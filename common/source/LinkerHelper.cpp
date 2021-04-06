#include "common/LinkerHelper.h"
#include "common/ReflectionHelper.h" // getDecorations
#include "common/ReflectionHelperTemplate.inl"
#include "common/FunctionCallGraph.h"
#include "common/ModulePrinter.h"

#include "spvgentwo/Module.h"
#include "spvgentwo/ModuleTemplate.inl"
#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/FunctionTemplate.inl"

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

spvgentwo::spv::LinkageType spvgentwo::LinkerHelper::getLinkageTypeFromDecoration(const Instruction* _pDecoration, Instruction** _ppOutSymbol, String* _pOutName)
{
	if (_pDecoration == nullptr || *_pDecoration != spv::Op::OpDecorate)
	{
		return spv::LinkageType::Max;	
	}

	if (auto it = _pDecoration->getFirstActualOperand(); it != nullptr && it->isInstruction())
	{
		if (_ppOutSymbol != nullptr)
		{
			*_ppOutSymbol = it->getInstruction();
		}

		if (it.next() != nullptr && static_cast<spv::Decoration>((++it)->getLiteral().value) == spv::Decoration::LinkageAttributes)
		{
			if (_pOutName != nullptr)
			{
				it = getLiteralString(*_pOutName, ++it, _pDecoration->end());			
			}
			else
			{
				it = skipLiteralString(++it);
			}
			
			if (it != nullptr)
			{
				return spv::LinkageType{ it->getLiteral().value };			
			}
		}
	}

	return spv::LinkageType::Max;
}

namespace spvgentwo 
{
	namespace LinkerHelper
	{
		void printInstruction(const LinkerOptions& _options, const spvgentwo::Instruction* _instr, const char* _end = "\n")
		{
			if(_options.printer != nullptr && _options.grammar != nullptr)
			{
				spvgentwo::ModulePrinter::printInstruction(*_instr, *_options.grammar, *_options.printer);
				*_options.printer << _end;
			}
		}

		bool transferInstruction(const Instruction* _pLibInstr, Instruction* _pTarget, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			Module* module = _pTarget->getModule();
			if (module == nullptr) { return false; }

			printInstruction(_options, _pLibInstr, " -> ");

			auto error = [&](auto&& ... args) {module->logError(args...); };

			// instruction parent must be be set before calling this function
			_pTarget->setOperation(_pLibInstr->getOperation());
	
			auto lookup = [&](const Instruction* lib) -> bool
			{
				Instruction* cInstr = nullptr;

				if (Instruction** ppTarget = _cache[lib]; ppTarget != nullptr)
				{
					cInstr = *ppTarget;
				}
				else if (lib->isSpecOrConstant() && (_options & LinkerOptionBits::ImportMissingConstants))
				{
					if (const Constant* c = lib->getConstant(); c != nullptr)
					{
						cInstr = module->addConstant(*c, lib->getName());
						_cache.emplaceUnique(lib, cInstr);
					}
				}
				else if (lib->isType() && (_options & LinkerOptionBits::ImportMissingTypes))
				{
					if (const Type* t = lib->getType(); t != nullptr)
					{
						cInstr = module->addType(*t, lib->getName());
						_cache.emplaceUnique(lib, cInstr);
					}
				}

				if (cInstr != nullptr)
				{
					if (_options & LinkerOptionBits::AssignResultIDs)
					{
						if (auto it = cInstr->getResultIdOperand(); it != nullptr && it->getId() == InvalidId)
						{
							*it = module->getNextId();
						}
					}

					_pTarget->addOperand(cInstr);
					return true;
				}
				
				error("Operand instruction not found");
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

			printInstruction(_options, _pTarget);

			_cache.emplaceUnique(_pLibInstr, _pTarget);
			return true;
		}

		bool importGlobalDependencies (Module& _consumer, const Instruction* _lInstr, const Instruction* _cInstr, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			if (_cache.find(_lInstr) != _cache.end())
			{
				return true; // already imported
			}

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

			// OpVariables
			if ((_options & LinkerOptionBits::ImportReferencedVariables))
			{
				// look for global variable operands
				for(auto it = _lInstr->getFirstActualOperand(); it != nullptr; ++it)
				{
					if (const Instruction* op = it->getInstruction(); op != nullptr && *op == spv::Op::OpVariable && op->getStorageClass() != spv::StorageClass::Function)
					{
						if (_cache.find(op) == _cache.end())
						{
							Instruction* cVar = _consumer.addGlobalVariableInstr(op->getName());
							success &= importGlobalDependencies(_consumer, op, cVar, _cache, _options);
							success &= transferInstruction(op, cVar, _cache, _options);						
						}
					}
				}
			}


			return success;
		};

		bool importSymbolImpl(Module& _consumer, const Instruction* _libSymbol, Instruction* _consumerSymbol, const String& _name, HashMap<const Instruction*, Instruction*>& _cache, LinkerOptions _options)
		{
			auto error = [&](auto&& ... args) {_consumer.logError(args...); };
			auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };

			info("Resolving import symbol [%llu] %s", hash(_name), _name.c_str());

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
				if (importGlobalDependencies(_consumer, _libSymbol, _consumerSymbol, _cache, _options) == false)
					return false;

				_cache.emplaceUnique(_libSymbol, _consumerSymbol);
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

bool spvgentwo::LinkerHelper::import(const Module& _lib, Module& _consumer, const LinkerOptions& _options)
{
	IAllocator* pAllocator = _options.allocator != nullptr ? _options.allocator : _consumer.getAllocator();

	auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };
	auto error = [&](auto&& ... args) {_consumer.logError(args...); };

	HashMap<String, const Instruction*> exportTable(pAllocator);

	// build export table
	for (const Instruction& deco : _lib.getDecorations())
	{
		Instruction* symbol = nullptr;
		String name(pAllocator);

		if (getLinkageTypeFromDecoration(&deco, &symbol, &name) == spv::LinkageType::Export)
		{
			info("Add export symbol [%llu] %s", hash(name), name.c_str());
			exportTable.emplace(stdrep::move(name), symbol);
		}
	}

	struct ImportSymbol
	{
		String name;
		const Instruction* lib = nullptr;
		Instruction* consume = nullptr;
		BasicBlock::Iterator decoIt = nullptr;
	};

	List<ImportSymbol> iVars(pAllocator);
	List<ImportSymbol> iFuncs(pAllocator);

	bool hasExports = false;

	// consume inputs
	for (auto it = _consumer.getDecorations().begin(), end = _consumer.getDecorations().end(); it != end; ++it)
	{
		Instruction* importSymbol = nullptr;
		String name(pAllocator);
		const spv::LinkageType type = getLinkageTypeFromDecoration(it.operator->(), &importSymbol, &name);

		if (type == spv::LinkageType::Import)
		{
			if (const Instruction** ppSymbol = exportTable[name]; ppSymbol != nullptr)
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
				info("Symbol %s not found in import module", name.c_str()); // just an info because it could be in a different import module
			}
		}
		else if (type == spv::LinkageType::Export)
		{
			hasExports = true;
		}
	}

	// lib -> consumer
	HashMap<const Instruction*, Instruction*> cache(pAllocator);

	if (_options & LinkerOptionBits::ImportReferencedFunctions)
	{
		// gather all functions called from all the iFuncs we want to import
		HashMap <Function*, Instruction*> calledFuncs(pAllocator, static_cast<unsigned int>(_lib.getFunctions().size())); // Func -> OpFunctionCall
		for (const ImportSymbol& func : iFuncs)
		{
			Function* target = func.lib->getFunction();
			FunctionCallGraph fcg(*target, pAllocator);

			for (auto& src : fcg)
			{
				for (auto& [node, call] : src.outputs())
				{
					Function* callee = node->data();
					if (callee != target) // not interested in the exported function
					{
						// check if callee is NOT marked for export
						bool exported = false;
						ReflectionHelper::getDecorationsFunc(callee->getFunction(), [&exported](const Instruction* pDeco) {
							if(exported == false && getLinkageTypeFromDecoration(pDeco) == spv::LinkageType::Export)
							{
								exported = true;
							}
						});

						if (exported == false)
						{
							calledFuncs.emplaceUnique(callee, call); // dont really care about the call						
						}
					}
				}
			}
		}

		// transfer functions from lib to consumer
		for (auto& [lFunc, call] : calledFuncs)
		{
			if (const char* name = lFunc->getName(); name != nullptr)
			{
				info("Auto importing referenced function '%s'", name);
			}
			else
			{
				info("Auto importing referenced function @%u", lFunc->getFunction()->getResultId());
			}

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
		_consumer.removeCapability(spv::Capability::Linkage);
	}

	const auto version = _lib.getSpvVersion() > _consumer.getSpvVersion() ? _lib.getSpvVersion() : _consumer.getSpvVersion();
	_consumer.setSpvVersion(version);

	if (_options.grammar != nullptr) // only add required capabilities
	{
		_consumer.addRequiredCapabilities(*_options.grammar);
	}
	else // import all capabilities
	{
		for (const auto& [cap, instr] : _lib.getCapabilities())
		{
			_consumer.addCapability(cap);
		}
	}

	// update global variable interface in case it changed and the user forgets to finalize the module
	_consumer.finalizeEntryPoints();

	return true;
}
