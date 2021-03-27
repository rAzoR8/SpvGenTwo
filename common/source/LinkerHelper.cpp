#include "common/LinkerHelper.h"

#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/ModuleTemplate.inl"

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
		bool importSymbolImpl(const Module& _lib, Module& _consumer, const Instruction* _libSymbol, Instruction* _consumerSymbol, const String& _name)
		{
			auto error = [&](auto&& ... args) {_consumer.logError(args...); };
			auto warning = [&](auto&& ... args) {_consumer.logWarning(args...); };
			auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };
			auto debug = [&](auto&& ... args) {_consumer.logDebug(args...); };

			if (_libSymbol->getOperation() != _consumerSymbol->getOperation())
			{
				return false;
			}

			// TODO: copy types, decorates (bindings etc), names

			if (*_libSymbol == spv::Op::OpVariable)
			{
			
			}
			else if (*_libSymbol == spv::Op::OpFunction)
			{
			
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

	const auto version = _lib.getSpvVersion() > _consumer.getSpvVersion() ? _lib.getSpvVersion() : _consumer.getSpvVersion();
	_consumer.setSpvVersion(version);

	HashMap<String, const Instruction*> exportTable(_pAllocator);

	// build import table
	for (const Instruction& deco : _lib.getDecorations())
	{
		if (auto it = deco.getFirstActualOperand(); it != nullptr && deco == spv::Op::OpDecorate && it->isInstruction())
		{
			const Instruction* symbol{ it->getInstruction() };
			if (static_cast<spv::Decoration>((++it)->getLiteral().value) == spv::Decoration::LinkageAttributes)
			{
				if (spv::LinkageType{ (++it)->getLiteral().value } == spv::LinkageType::Export) 
				{
					String name(_pAllocator);
					getLiteralString(name, ++it, deco.end());
					debug("Add export symbol %s [%llu]", name.c_str(), hash(name));
					exportTable.emplace(stdrep::move(name), symbol);
				}
			}			
		}
	}

	bool removedAllLinkageDecorates = true;
	// consume inputs
	for (auto it = _consumer.getDecorations().begin(), end = _consumer.getDecorations().end(); it != end;)
	{
		if (auto op = it->getFirstActualOperand(); *it == spv::Op::OpDecorate && op != nullptr && op->isInstruction())
		{
			Instruction* importSymbol{ op->getInstruction() };
			if (static_cast<spv::Decoration>((++op)->getLiteral().value) == spv::Decoration::LinkageAttributes)
			{
				const spv::LinkageType type{ (++op)->getLiteral().value };
				if (type == spv::LinkageType::Import)
				{
					String name(_pAllocator);
					getLiteralString(name, ++op, it->end());
					debug("Trying to resolve import symbol %s [%llu]", name.c_str(), hash(name));

					if (auto ppSymbol = exportTable[name]; ppSymbol != nullptr)
					{
						const Instruction* exportSymbol = *ppSymbol;

						if (importSymbolImpl(_lib, _consumer, exportSymbol, importSymbol, name))
						{
							// remove if successful
							it = _consumer.getDecorations().erase(it);
							continue;
						}
					}
					else
					{
						info("Symbol %s not found in import module", name.c_str());
						removedAllLinkageDecorates = false;
					}
				}
				else // module has exports on its own, so we need to preserve linkage capabilities
				{
					removedAllLinkageDecorates = false;
				}
			}
		}
		++it;
	}

	if (removedAllLinkageDecorates) 
	{
		// TODO: remove Linkage capabilities from _consumer if it does not export any symbols itself
	}

	return false;
}
