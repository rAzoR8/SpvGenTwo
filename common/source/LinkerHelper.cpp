#include "common/LinkerHelper.h"
#include "common/ReflectionHelper.h" // getDecorations
#include "common/ReflectionHelperTemplate.inl"

#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/ModuleTemplate.inl"
#include "spvgentwo/InstructionTemplate.inl"

#include "spvgentwo/HashMap.h"

bool spvgentwo::LinkerHelper::removeFunctionBody(Function& _func)
{
	Module* module = _func.getModule();

	if (module == nullptr)
	{
		return false;
	}

	auto erase = [&_func](List<Instruction>& _container)
	{
		// look for instructions which reference/consume instructions originating from the function _func we want to clear
		for (auto it = _container.begin(), end = _container.end(); it != end;)
		{
			bool removed = false;
			for (const Operand& op : *it)
			{
				// if the instruction is coming from one of _funcs basic blocks, we remove it 
				// (OpFunction, OpFunctionParameter and OpFunctionEnd are fine, they will not be removed as they are part to the declaration)
				if (const Instruction* param = op.getInstruction(); param != nullptr && (param->getFunction() == &_func && param->getBasicBlock() != nullptr))
				{
					it = _container.erase(it);
					removed = true;
					break;
				}
			}

			if (removed == false)
			{
				++it;			
			}
		}
	};

	erase(module->getNames());
	erase(module->getDecorations());
	erase(module->getUndefs());

	_func.clear();

	return true;
}

spvgentwo::Instruction* spvgentwo::LinkerHelper::addLinkageDecoration(Instruction* _varOrFunc, spv::LinkageType _linkage, const char* name)
{
	if (_varOrFunc == nullptr)
		return nullptr;

	Module* module = _varOrFunc->getModule();

	if (module == nullptr || _linkage == spv::LinkageType::Max)
	{
		return nullptr;
	}

	if (*_varOrFunc == spv::Op::OpFunction || *_varOrFunc == spv::Op::OpVariable)
	{
		Instruction* deco = module->addDecorationInstr();
		deco->opDecorate(_varOrFunc, spv::Decoration::LinkageAttributes, name, _linkage);
		return deco;
	}

	return nullptr;
}

bool spvgentwo::LinkerHelper::addLinkageDecorateForUsedGlobalVariables(const Function& _func, spv::LinkageType _linkage, IAllocator* _pAllocator)
{
	Module* module = _func.getModule();

	if (module == nullptr || _linkage == spv::LinkageType::Max)
	{
		return false;
	}

	List<Operand> vars(_pAllocator  != nullptr ? _pAllocator : module->getAllocator());
	collectReferencedVariables(_func, vars, GlobalInterfaceVersion::SpirV14_x, vars.getAllocator());

	bool result = true;

	for (const Operand& op : vars)
	{
		if (Instruction* var = op.getInstruction(); var != nullptr)
		{
			if (const char* name = var->getName(); name != nullptr)
			{
				module->addDecorationInstr()->opDecorate(var, spv::Decoration::LinkageAttributes, name, _linkage);
				module->logInfo("%s variable %s", _linkage == spv::LinkageType::Export ? "Exporting" : "Importing", name);
			}
			else
			{
				module->logError("OpVariable Id %u has no OpName for exporting", var->getResultId());
				result =  false;
			}
		}
	}

	return result;
}

namespace spvgentwo 
{
	template<> struct Hasher<String> { Hash64 operator()(const String& _str, Hash64 _seed = detail::Offset) const noexcept { FNV1aHasher h(_seed); h(_str.data(), _str.size()); return h; } };

	namespace LinkerHelper
	{
		bool transferInstruction(const Instruction* _pLibInstr, Instruction* _pTarget, HashMap<const Instruction*, Instruction*>& _cache)
		{
			Module* module = _pTarget->getModule();
			if (module == nullptr) { return false; }

			auto error = [&](auto&& ... args) {module->logError(args...); };

			// instruction parent must be be set before calling this function
			_pTarget->setOperation(_pLibInstr->getOperation());
	
			auto lookup = [&](const Instruction* lib) -> bool
			{
				if (Instruction** ppTarget = _cache[lib]; ppTarget != nullptr)
				{
					_pTarget->addOperand(*ppTarget);
					return true;
				}
				else
				{
					error("Operand instruction not found");
					return false;
				}
			};

			if (_pTarget->hasResultType())
			{
				lookup(_pLibInstr->getResultTypeInstr());
			}
			if (_pTarget->hasResult())
			{
				_pTarget->addOperand(InvalidId);
			}

			for (auto it = _pLibInstr->getFirstActualOperand(), end = _pLibInstr->end(); it != end; ++it)
			{
				if (it->isLiteral())
				{
					_pTarget->addOperand(*it);
				}
				else if (it->isInstruction())
				{
					if (lookup(it->getInstruction()) == false) return false;
				}
				else if (it->isBranchTarget())
				{
					if (lookup(it->getBranchTarget()->getLabel()) == false) return false;
				}
				else
				{
					error("Instruction has unresolved ID operand, module needs to be resolved by resolveIDs() before importing a using it as import library.");
					return false;
				}
			}

			_cache.emplaceUnique(_pLibInstr, _pTarget);
			return true;
		}

		bool importSymbolImpl(const Module& _lib, Module& _consumer, const Instruction* _libSymbol, Instruction* _consumerSymbol, const String& _name, HashMap<const Instruction*, Instruction*>& _cache)
		{
			auto error = [&](auto&& ... args) {_consumer.logError(args...); };
			auto warning = [&](auto&& ... args) {_consumer.logWarning(args...); };
			auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };
			auto debug = [&](auto&& ... args) {_consumer.logDebug(args...); };

			if (_libSymbol->getOperation() != _consumerSymbol->getOperation())
			{
				return false;
			}

			const Type* libType = _libSymbol->getType();
			const Type* consumerType = _consumerSymbol->getType();

			if (libType == nullptr || consumerType == nullptr) return false;

			if (*libType != *consumerType)
			{
				error("Type mismatch for symbol %s", _name.c_str());
				return false;
			}

			// TODO: auto import decorations, names etc
			auto importGlobalDependencies = [&](const Instruction* _libInstr) -> bool
			{
				// for Names, Decorates etc referencing _libInstr:
				// transferInstruction(instr, new _consumerInstr, cache);
				bool success = true;

				ReflectionHelper::getDecorationsFunc(_libSymbol, [&](const Instruction* deco) {
					if (transferInstruction(deco, _consumer.addDecorationInstr(), _cache) == false)
					{
						success = false;
					}
				});

				ReflectionHelper::getNamesFunc(_libSymbol, [&](const Instruction* name) {
					if (transferInstruction(name, _consumer.addNameInstr(), _cache) == false)
					{
						success = false;
					}
				});

				return success;
			};

			if (*_libSymbol == spv::Op::OpVariable) // && _options.importDecorationsAndNames
			{
				return importGlobalDependencies(_libSymbol);
			}
			else if (*_libSymbol == spv::Op::OpFunction && _libSymbol->getFunction() != nullptr && _consumerSymbol->getFunction() != nullptr)
			{
				// When resolving imported functions, the Function Control and all Function Parameter Attributes are taken from the function
				// definition, and not from the function declaration.

				Function& cosumerFunc = *_consumerSymbol->getFunction();
				for (const BasicBlock& bbLib : *_libSymbol->getFunction())
				{
					BasicBlock& bbConsumer = cosumerFunc.addBasicBlock(bbLib.getName());
					for (const Instruction& iLib : bbLib)
					{
						if (iLib == spv::Op::OpFunctionCall)
						{
							// TODO: check if function was imported
						}

						if (importGlobalDependencies(&iLib) == false)
							return false;

						if (transferInstruction(&iLib, bbConsumer.addInstruction(), _cache) == false) 
							return false;
					}
				}
			}
			else
			{
				error("%s symbol must be OpVariable or OpFunction", _name.c_str());
				return false;
			}

			return true;
		}
	} // !LinkerHelper
} // !spvgentwo

bool spvgentwo::LinkerHelper::import(const Module& _lib, Module& _consumer, const LinkerOptions& _options, IAllocator* _pAllocator)
{
	if(_pAllocator == nullptr)
	{
		_pAllocator = _consumer.getAllocator();
	}

	auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };
	auto debug = [&](auto&& ... args) {_consumer.logDebug(args...); };
	auto error = [&](auto&& ... args) {_consumer.logError(args...); };

	const auto version = _lib.getSpvVersion() > _consumer.getSpvVersion() ? _lib.getSpvVersion() : _consumer.getSpvVersion();
	_consumer.setSpvVersion(version);

	HashMap<String, const Instruction*> exportTable(_pAllocator);

	// build export table
	for (const Instruction& deco : _lib.getDecorations())
	{
		if (auto it = deco.getFirstActualOperand(); it != nullptr && deco == spv::Op::OpDecorate && it->isInstruction())
		{
			const Instruction* symbol{ it->getInstruction() };
			if (static_cast<spv::Decoration>((++it)->getLiteral().value) == spv::Decoration::LinkageAttributes)
			{
				it = skipLiteralString(it);
				if ( it != nullptr && spv::LinkageType{ (it)->getLiteral().value } == spv::LinkageType::Export) 
				{
					String name(_pAllocator);
					getLiteralString(name, ++it, deco.end());
					debug("Add export symbol %s [%llu]", name.c_str(), hash(name));
					exportTable.emplace(stdrep::move(name), symbol);
				}
			}			
		}
	}

	struct ImportSymbol
	{
		String name;
		const Instruction* lib = nullptr;
		Instruction* consume = nullptr;
		BasicBlock::Iterator decoIt = nullptr;
	};

	List<ImportSymbol> iVars(_pAllocator);
	List<ImportSymbol> iFuncs(_pAllocator);

	bool hasExports = true;
	// consume inputs
	for (auto it = _consumer.getDecorations().begin(), end = _consumer.getDecorations().end(); it != end; ++it)
	{
		if (auto op = it->getFirstActualOperand(); *it == spv::Op::OpDecorate && op != nullptr && op->isInstruction())
		{
			Instruction* importSymbol{ op->getInstruction() };
			if (static_cast<spv::Decoration>((++op)->getLiteral().value) == spv::Decoration::LinkageAttributes)
			{
				String name(_pAllocator);
				op = getLiteralString(name, ++op, it->end());
				debug("Trying to resolve import symbol %s [%llu]", name.c_str(), hash(name));

				if (op != nullptr && spv::LinkageType{ (op)->getLiteral().value } == spv::LinkageType::Import)
				{
					if (auto ppSymbol = exportTable[name]; ppSymbol != nullptr)
					{
						const Instruction* exportSymbol = *ppSymbol;

						if (*exportSymbol == spv::Op::OpVariable)
						{
							iVars.emplace_back(stdrep::move(name), exportSymbol, importSymbol, it);
						}
						else if (*exportSymbol == spv::Op::OpFunction)
						{
							iFuncs.emplace_back(stdrep::move(name), exportSymbol, importSymbol, it);
						}
						else
						{
							error("%s symbol must be OpVariable or OpFunction", name.c_str());
							return false;
						}
					}
					else
					{
						info("Symbol %s not found in import module", name.c_str());
					}
				}
				else // module has exports on its own, so we need to preserve linkage capabilities
				{
					hasExports = false;
				}
			}
		}
	}

	// lib -> consumer
	HashMap<const Instruction*, Instruction*> cache(_pAllocator);

	bool allImportsResolved = true;
	// import variables first in case they are used in the imported function
	for (const ImportSymbol& var : iVars)
	{
		if (importSymbolImpl(_lib, _consumer, var.lib, var.consume, var.name, cache))
		{
			_consumer.getDecorations().erase(var.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	for (const ImportSymbol& func : iFuncs)
	{
		if (importSymbolImpl(_lib, _consumer, func.lib, func.consume, func.name, cache))
		{
			_consumer.getDecorations().erase(func.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	if (hasExports && allImportsResolved) 
	{
		// TODO: remove Linkage capabilities from _consumer if it does not export any symbols itself
	}

	return false;
}
