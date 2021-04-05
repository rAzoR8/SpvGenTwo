#include "common/LinkerHelper.h"
#include "common/ReflectionHelper.h" // getDecorations
#include "common/ReflectionHelperTemplate.inl"
#include "common/FunctionCallGraph.h"

#include "spvgentwo/Module.h"
#include "spvgentwo/ModuleTemplate.inl"
#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/FunctionTemplate.inl"

#define SPVGENTWO_DEBUG_LINKER
#if defined(SPVGENTWO_DEBUG_LINKER) && defined (_DEBUG) && defined(_WIN32)
// for debugging
#include "common/HeapAllocator.h"
#include "common/ModulePrinter.h"
#include "spvgentwo/Grammar.h"

#define WIN32_MEAN_AND_LEAN
#include <Windows.h>

namespace dbg
{
	auto g_printer = spvgentwo::ModulePrinter::ModuleSimpleFuncPrinter([](const char* str) { OutputDebugStringA(str); });
	const spvgentwo::Grammar g_gram(spvgentwo::HeapAllocator::instance());
	void printInstruction(const spvgentwo::Instruction* instr, const char* end = "\n")
	{
		spvgentwo::ModulePrinter::printInstruction(*instr, g_gram, g_printer);
		OutputDebugStringA(end);
	}
}
#else
namespace dbg { void printInstruction(const spvgentwo::Instruction* instr, const char* end = nullptr) {} }
#endif

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
	namespace LinkerHelper
	{
		bool transferInstruction(const Instruction* _pLibInstr, Instruction* _pTarget, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			Module* module = _pTarget->getModule();
			if (module == nullptr) { return false; }

			dbg::printInstruction(_pLibInstr, " -> ");

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
				else if (lib->isSpecOrConstant()) // TODO: check for auto import
				{
					if (const Constant* c = lib->getConstant(); c != nullptr)
					{
						Instruction* cInstr = module->addConstant(*c, lib->getName());
						_cache.emplaceUnique(lib, cInstr);
						_pTarget->addOperand(cInstr);
						return true;
					}
				}
				else if (lib->isType())
				{
					if (const Type* t = lib->getType(); t != nullptr)
					{
						Instruction* cInstr = module->addType(*t, lib->getName());
						_cache.emplaceUnique(lib, cInstr);
						_pTarget->addOperand(cInstr);
						return true;
					}
				}
				
				error("Operand instruction not found for");
				return false;
			};

			if (_pTarget->hasResultType())
			{
				lookup(_pLibInstr->getResultTypeInstr());
			}
			if (_pTarget->hasResult())
			{
				_pTarget->addOperand((_options & LinkerOptionBits::AssignResultIDs) ? module->getNextId() : InvalidId);
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

			dbg::printInstruction(_pTarget);

			_cache.emplaceUnique(_pLibInstr, _pTarget);
			return true;
		}

		bool importGlobalDependencies (Module& _consumer, const Instruction* _lInstr, const Instruction* _cInstr, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			// for Names, Decorates etc referencing _libInstr:
			// transferInstruction(instr, new _consumerInstr, cache);
			bool success = true;

			// decorates except linkage
			if (_options & LinkerOptionBits::ImportReferencedDecorations)
			{
				ReflectionHelper::getDecorationsFunc(_lInstr, [&](const Instruction* deco) {
					if (ReflectionHelper::getSpvDecorationKindFromDecoration(deco) != spv::Decoration::LinkageAttributes)
					{
						success &= transferInstruction(deco, _consumer.addDecorationInstr(), _cache, _options);
					}
					});
			}

			// OpNames
			if (_options & LinkerOptionBits::ImportReferencedNames && (_cInstr == nullptr || _cInstr->getName() == nullptr)) // check if a name is already present
			{
				ReflectionHelper::getNamesFunc(_lInstr, [&](const Instruction* name) {
					success &= transferInstruction(name, _consumer.addNameInstr(), _cache, _options);
					});
			}

			return success;
		};

		bool importSymbolImpl(Module& _consumer, const Instruction* _libSymbol, Instruction* _consumerSymbol, const String& _name, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			auto error = [&](auto&& ... args) {_consumer.logError(args...); };
			auto warning = [&](auto&& ... args) {_consumer.logWarning(args...); };
			auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };
			auto debug = [&](auto&& ... args) {_consumer.logDebug(args...); };

			debug("Resolving import symbol [%llu] %s", hash(_name), _name.c_str());

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

			if (*_libSymbol == spv::Op::OpVariable) // && _options.importDecorationsAndNames
			{
				_cache.emplaceUnique(_libSymbol, _consumerSymbol);
				return importGlobalDependencies(_consumer, _libSymbol, _consumerSymbol, _cache, _options);
			}
			else if (*_libSymbol == spv::Op::OpFunction && _libSymbol->getFunction() != nullptr && _consumerSymbol->getFunction() != nullptr)
			{
				const Function& libFunc = *_libSymbol->getFunction();
				Function& cosumerFunc = *_consumerSymbol->getFunction();

				// add function signature to cache
				{
					_cache.emplaceUnique(_libSymbol, _consumerSymbol); // cache OpFunction

					const auto& libParams = libFunc.getParameters();
					const auto& consumerParams = cosumerFunc.getParameters();

					if (libParams.size() != consumerParams.size())
					{
						error("Number of function parameters does not match for %s", _name.c_str());
						return false;
					}

					// cache OpFunctionParameter
					for (auto lit = libParams.begin(), lend = libParams.end(), cit = consumerParams.begin(); lit != lend; ++lit, ++cit)
					{
						if ((lit->getType() == nullptr || cit->getType() == nullptr) || *lit->getType() != *cit->getType())
						{
							error("Type of function parameter does not match for %s", _name.c_str());
							return false;
						}

						_cache.emplaceUnique(lit.operator->(), cit.operator->()); 
					}
				}
				
				// When resolving imported functions, the Function Control and all Function Parameter Attributes are taken from the function
				// definition, and not from the function declaration.

				for (const BasicBlock& bbLib : *_libSymbol->getFunction())
				{
					BasicBlock& bbConsumer = cosumerFunc.addBasicBlock(bbLib.getName());
					for (const Instruction& iLib : bbLib)
					{
						if (iLib == spv::Op::OpFunctionCall)
						{
							// TODO: check if function was imported
						}

						if (importGlobalDependencies(_consumer, &iLib, nullptr, _cache, _options) == false)
							return false;

						if (transferInstruction(&iLib, bbConsumer.addInstruction(), _cache, _options) == false) 
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
				String name(_pAllocator);
				it = getLiteralString(name, ++it, deco.end());
				if ( it != nullptr && spv::LinkageType{ (it)->getLiteral().value } == spv::LinkageType::Export) 
				{
					debug("Add export symbol [%llu] %s", hash(name), name.c_str());
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

	if (_options & LinkerOptionBits::ImportReferencedFunctions)
	{
		// gather all functions called from all the iFuncs we want to import
		HashMap <Function*, Instruction*> calledFuncs(_pAllocator, static_cast<unsigned int>(_lib.getFunctions().size())); // Func -> OpFunctionCall
		for (const ImportSymbol& func : iFuncs)
		{
			Function* target = func.lib->getFunction();
			FunctionCallGraph fcg(*target, _pAllocator);

			for (auto& src : fcg)
			{
				for (auto& [node, call] : src.outputs())
				{
					if (node->data() != target) // not interested in the exported function
					{
						// TODO: check if callee is NOT marked for export
						calledFuncs.emplaceUnique(node->data(), call); // dont really care about the call
					}
				}
			}
		}

		// transfer functions from lib to consumer
		for (auto& [lFunc, call] : calledFuncs)
		{
			Function& cFunc = _consumer.addFunction();
			cache.emplaceUnique(lFunc->getFunction(), cFunc.getFunction()); // OpFunction

			cFunc.setReturnType(_consumer.addType(lFunc->getReturnType()));

			for (const Instruction& lParam : lFunc->getParameters()) // OpFunctionCall
			{
				Instruction* cType = _consumer.addType(*lParam.getType());
				cache.emplaceUnique(lParam.getResultTypeInstr(), cType);
				
				Instruction* cParam = cFunc.addParameters(cType);
				cache.emplaceUnique(&lParam, cParam);
			}

			for (const BasicBlock& lBB : *lFunc) 
			{
				BasicBlock& cBB = cFunc.addBasicBlock(lBB.getName());

				for (const Instruction& lInstr : lBB)
				{
					Instruction* cInstr = cBB.addInstruction(lInstr.getName());

					if (importGlobalDependencies(_consumer, &lInstr, cInstr, cache, _options) == false)
						return false;

					if (transferInstruction(&lInstr, cInstr, cache, _options) == false)
						return false;
				}
			}

			cFunc.finalize(lFunc->getFunctionControl(), lFunc->getName());
		}
	}

	bool allImportsResolved = true;
	// import variables first in case they are used in the imported function
	for (const ImportSymbol& var : iVars)
	{
		if (importSymbolImpl(_consumer, var.lib, var.consume, var.name, cache, _options))
		{
			_consumer.getDecorations().erase(var.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	for (const ImportSymbol& func : iFuncs)
	{
		if (importSymbolImpl(_consumer, func.lib, func.consume, func.name, cache, _options))
		{
			_consumer.getDecorations().erase(func.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	if (hasExports && allImportsResolved && (_options & LinkerOptionBits::RemoveLinkageCapability)) 
	{
		// TODO: remove Linkage capabilities from _consumer if it does not export any symbols itself
	}

	// update global variable interface in case it changed and the user forgets to finalize the module
	_consumer.finalizeEntryPoints();

	return true;
}
