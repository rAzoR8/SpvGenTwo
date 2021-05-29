#include "common/LinkerHelper.h"
#include "common/ReflectionHelper.h" // getDecorations
#include "common/ReflectionHelperTemplate.inl"
#include "common/FunctionCallGraph.h"
#include "common/ModulePrinter.h"
#include "common/TypeHelper.h"

#include "spvgentwo/Grammar.h"
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

namespace
{
	using InstrLookup = spvgentwo::HashMap<const spvgentwo::Instruction*, spvgentwo::Instruction*>;

	inline void printInstruction(const spvgentwo::LinkerHelper::LinkerOptions& _options, const spvgentwo::Instruction* _instr1, const char* _separator = "\n", const spvgentwo::Instruction* _instr2 = nullptr, const char* _end = "\n")
	{
		if (_options.printer != nullptr && _options.grammar != nullptr)
		{
			spvgentwo::ModulePrinter::printInstruction(*_instr1, *_options.grammar, *_options.printer);
			*_options.printer << _separator;

			if (_instr2 != nullptr)
			{
				spvgentwo::ModulePrinter::printInstruction(*_instr2, *_options.grammar, *_options.printer);
				*_options.printer << _end;
			}
		}
	}

	inline bool transferInstruction(const spvgentwo::Instruction* _pLibInstr, spvgentwo::Instruction* _pTarget, InstrLookup& _cache, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		using namespace spvgentwo;
		using namespace LinkerHelper;

		if (_cache.find(_pLibInstr) != _cache.end())
		{
			return true;
		}

		Module* module = _pTarget->getModule();
		if (module == nullptr) { return false; }

		auto instrName = [&_options](const Instruction* instr) -> const char*
		{
			if (_options.grammar == nullptr) return "";

			if (auto* info = _options.grammar->getInfo(static_cast<unsigned int>(instr->getOperation())); info != nullptr)
			{
				return info->name;
			}

			return "";
		};

		auto libSymbolName = [_pLibInstr, &instrName]() -> const char*
		{
			const char* name = _pLibInstr->getName();
			if (name == nullptr)
			{
				name = instrName(_pLibInstr);
			}
			return name != nullptr ? name : "UNNAMED-SYMBOL";
		};

		printInstruction(_options, _pLibInstr, " -> ");

		auto error = [module](auto&& ... args) {module->logError(args...); };

		// instruction parent must be be set before calling this function
		_pTarget->setOperation(_pLibInstr->getOperation());

		auto lookupOperand = [&](const Instruction* lib) -> bool
		{
			Instruction* cInstr = nullptr;

			bool reported = false;

			if (Instruction** ppTarget = _cache[lib]; ppTarget != nullptr)
			{
				cInstr = *ppTarget;
			}
			else if (lib->isSpecOrConstant())
			{
				if (const Constant* c = lib->getConstant(); c != nullptr && (_options & LinkerOptionBits::ImportMissingConstants))
				{
					cInstr = module->addConstant(*c);
				}
				else
				{
					error("[%s] OpConstant/OpSpecConstant operand instruction not found! use \'ImportMissingConstants\'", libSymbolName());
					reported = true;
				}
			}
			else if (lib->isType())
			{
				if (const Type* t = lib->getType(); t != nullptr && (_options & LinkerOptionBits::ImportMissingTypes))
				{
					cInstr = module->addType(*t);
				}
				else
				{
					error("[%s] OpType operand instruction not found! use \'ImportMissingTypes\'", libSymbolName());
					reported = true;
				}
			}

			if (cInstr != nullptr)
			{
				_cache.emplaceUnique(lib, cInstr);

				if (_options & LinkerOptionBits::AssignResultIDs)
				{
					cInstr->assignResultId(false);
				}

				_pTarget->addOperand(cInstr);
				return true;
			}

			if (reported == false)
			{
				error("[%s] operand %s not found!", libSymbolName(), instrName(lib));
			}

			printInstruction(_options, lib);

			return false;
		};

		if (_pTarget->hasResultType())
		{
			if (lookupOperand(_pLibInstr->getResultTypeInstr()) == false) return false;
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
				if (lookupOperand(it->getInstruction()) == false) return false;
			}
			else if (it->isBranchTarget())
			{
				if (lookupOperand(it->getBranchTarget()->getLabel()) == false) return false;
			}
			else
			{
				error("[%s] Instruction has unresolved ID operand, module needs to be resolved by resolveIDs() before importing a using it as import library.", libSymbolName());
				return false;
			}
		}

		printInstruction(_options, _pTarget);

		_cache.emplaceUnique(_pLibInstr, _pTarget);

		return true;
	}

	inline bool importGlobalDependencies(spvgentwo::Module& _consumer, const spvgentwo::Instruction* _lInstr, InstrLookup& _cache, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		using namespace spvgentwo;
		using namespace LinkerHelper;

		if (_cache.find(_lInstr) != _cache.end())
		{
			return true; // already imported
		}

		bool success = true;

		// OpVariables
		if (_options & LinkerOptionBits::ImportReferencedVariables)
		{
			// look for global variable operands
			for (auto it = _lInstr->getFirstActualOperand(); it != nullptr; ++it)
			{
				if (const Instruction* op = it->getInstruction(); op != nullptr && *op == spv::Op::OpVariable && op->getStorageClass() != spv::StorageClass::Function)
				{
					if (_cache.find(op) == _cache.end())
					{
						Instruction* cVar = _consumer.addGlobalVariableInstr();
						success &= importGlobalDependencies(_consumer, op, _cache, _options);
						success &= transferInstruction(op, cVar, _cache, _options);
					}
				}
			}
		}

		// TODO: move to post with OpNames
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

		//OpExtInst
		if ((_options & LinkerOptionBits::ImportMissingExtensionSets) && *_lInstr == spv::Op::OpExtInst)
		{
			if (auto it = _lInstr->getFirstActualOperand(); it != nullptr && it->getInstruction() != nullptr) 
			{
				Instruction* lSet = it->instruction;
				if (*lSet == spv::Op::OpExtInstImport)
				{
					for (const auto& [name, instr] : _lInstr->getModule()->getExtInstrImports())
					{
						if(&instr == lSet && _consumer.getExtensionInstructionImport(name.c_str()) == nullptr)
						{
							Instruction* cSet = _consumer.addExtensionInstructionImport(name.c_str());
							_cache.emplaceUnique(lSet, cSet);
							if (_options & LinkerOptionBits::AssignResultIDs)
							{
								cSet->assignResultId(false);
							}
							printInstruction(_options, lSet, "->", cSet);
							break;
						}
					}
				}
			}
		}

		return success;
	}

	inline spvgentwo::Instruction* assignId(spvgentwo::Instruction* instr, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		if (_options & spvgentwo::LinkerHelper::LinkerOptionBits::AssignResultIDs)
		{
			instr->assignResultId(false);
		}
		return instr;
	};

	inline bool transferBasicBlock(const spvgentwo::BasicBlock& _lBB, spvgentwo::BasicBlock& _cBB, InstrLookup& _cache, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		bool success = true;

		printInstruction(_options, _lBB.getLabel(), " -> ", _cBB.getLabel());

		for (const spvgentwo::Instruction& lInstr : _lBB)
		{
			success &= importGlobalDependencies(*_cBB.getModule(), &lInstr, _cache, _options);
			success &= transferInstruction(&lInstr, _cBB.addInstruction(), _cache, _options);
		}

		return success;
	}

	inline bool transferFunction(const spvgentwo::Function& _lFunc, spvgentwo::Function& _cFunc, InstrLookup& _cache, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		using namespace spvgentwo;

		bool success = true;
		Module& consumer = *_cFunc.getModule();

		// we dont need to call assignID for OpTypes because we iterate over all types and assign them later

		// create function signature
		if (_cFunc.isFinalized() == false) // Function return type
		{
			Instruction* cRetType = consumer.addType(_lFunc.getReturnType());
			_cache.emplaceUnique(_lFunc.getReturnTypeInstr(), cRetType);
			_cFunc.setReturnType(_lFunc.getReturnType());
		}

		if(_cFunc.getParameters().empty()) // parameters
		{
			for (const Instruction& lParam : _lFunc.getParameters())
			{
				Instruction* cType = consumer.addType(*lParam.getType());
				_cache.emplaceUnique(lParam.getResultTypeInstr(), cType);
				_cFunc.addParameters(cType); // OpFunctionParameter
			}
		}
		else if(_cFunc.getParameters().size() != _lFunc.getParameters().size())
		{
			consumer.logError("Number of function parameters does not match for");
			return false;
		}

		if(_cFunc.isFinalized() == false) // create OpFunction
		{
			_cFunc.finalize(_lFunc.getFunctionControl());		
		}

		_cFunc.getFunctionTypeInstr(), _options; // OpTypeFunction
		_cache.emplaceUnique(_lFunc.getFunction(), assignId(_cFunc.getFunction(), _options)); // OpFunction

		printInstruction(_options, _lFunc.getFunction(), " -> ", _cFunc.getFunction()); // OpFunction
		for (auto i = 0u; i < _cFunc.getParameters().size(); ++i)
		{
			Instruction* lParam = _lFunc.getParameter(i);
			Instruction* cParam = assignId(_cFunc.getParameter(i), _options);
			Instruction* cType = cParam->getResultTypeInstr();

			_cache.emplaceUnique(lParam->getResultTypeInstr(), cType);
			_cache.emplaceUnique(lParam, cParam);

			printInstruction(_options, lParam, " -> ", cParam); // OpFunctionParameter
		}

		// cache labels first, they can be referenced from other basic blocks, not yet added
		for(const spvgentwo::BasicBlock& lBB : _lFunc)
		{
			auto& cBB = _cFunc.addBasicBlock();
			_cache.emplaceUnique(lBB.getLabel(), assignId(cBB.getLabel(), _options));
		}

		for(auto lit = _lFunc.begin(), cit = _cFunc.begin(); lit != _lFunc.end(); ++lit, ++cit)
		{
			success &= transferBasicBlock(*lit, *cit, _cache, _options);
		}

		printInstruction(_options, _lFunc.getFunctionEnd(), " -> ", _cFunc.getFunctionEnd());

		return success;
	}

	inline bool importSymbolImpl(spvgentwo::Module& _consumer, const spvgentwo::Instruction* _libSymbol, spvgentwo::Instruction* _consumerSymbol, const spvgentwo::String& _name, InstrLookup& _cache, spvgentwo::LinkerHelper::LinkerOptions _options)
	{
		bool success = true;

		using namespace spvgentwo;
		using namespace LinkerHelper;

		auto error = [&](auto&& ... args) {_consumer.logError(args...); };
		auto info = [&](auto&& ... args) {_consumer.logInfo(args...); };

		IAllocator* pAllocator = _options.allocator != nullptr ? _options.allocator : _consumer.getAllocator();

		info("Resolving import symbol %s [%llu]", _name.c_str(), hash(_name));

		if (_libSymbol->getOperation() != _consumerSymbol->getOperation())
		{
			error("Lib symbol Op kind does not match consumer kind, both must be either OpFunction or OpVariable [Op: lib %u consumer %u]", _libSymbol->getOperation(), _consumerSymbol->getOperation());
			return false;
		}

		const Type* libType = _libSymbol->getType();
		const Type* consumerType = _consumerSymbol->getType();

		if (libType == nullptr || consumerType == nullptr) 
			return false;

		String lTypeName(pAllocator);
		TypeHelper::getTypeName(*libType, lTypeName, _libSymbol);

		if (*libType != *consumerType)
		{
			String cTypeName(pAllocator);
			TypeHelper::getTypeName(*consumerType, cTypeName, _consumerSymbol);

			error("Type mismatch for symbol %s: \n[export] %s\n[import] %s", _name.c_str(), lTypeName.c_str(), cTypeName.c_str());
			return false;
		}

		info("Symbol type: \'%s\'", lTypeName.c_str());

		if (*_libSymbol == spv::Op::OpVariable)
		{
			success &= importGlobalDependencies(_consumer, _libSymbol, _cache, _options);

			printInstruction(_options, _libSymbol, " -> ", _consumerSymbol);
			_cache.emplaceUnique(_libSymbol, _consumerSymbol);
		}
		else if (*_libSymbol == spv::Op::OpFunction && _libSymbol->getFunction() != nullptr && _consumerSymbol->getFunction() != nullptr)
		{
			const Function& libFunc = *_libSymbol->getFunction();
			Function& cosumerFunc = *_consumerSymbol->getFunction();

			success &= transferFunction(libFunc, cosumerFunc, _cache, _options);
		}
		else
		{
			error("Symbol %s must be OpVariable or OpFunction", _name.c_str());
			return false;
		}

		return success;
	}
} // anon namespace

bool spvgentwo::LinkerHelper::import(const Module& _lib, Module& _consumer, const LinkerOptions& _options)
{
	bool success = true;
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
			info("Found export symbol %s [%llu]", name.c_str(), hash(name));
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

	// gather symbols to import
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
					error("Symbol %s must be OpVariable or OpFunction", name.c_str());
					success = false;
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
	InstrLookup cache(pAllocator);

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
			{
				String sig(pAllocator);
				TypeHelper::getTypeName(lFunc->getFunctionType(), sig, lFunc->getFunction());
				info("Auto importing referenced function \'%s\'", sig.c_str());
			}

			success &= transferFunction(*lFunc, _consumer.addFunction(), cache, _options);
		}
	}

	bool allImportsResolved = true;
	// import variables first in case they are used in the imported function
	for (const ImportSymbol& var : iVars)
	{
		if (success &= importSymbolImpl(_consumer, var.lib, var.consume, var.name, cache, _options); success)
		{
			_consumer.getDecorations().erase(var.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	for (const ImportSymbol& func : iFuncs)
	{
		if (success &= importSymbolImpl(_consumer, func.lib, func.consume, func.name, cache, _options); success)
		{
			_consumer.getDecorations().erase(func.decoIt); // remove if successful
		}
		else { allImportsResolved = false; }
	}

	if (hasExports == false && allImportsResolved && (_options & LinkerOptionBits::RemoveLinkageCapability)) 
	{
		info("Removing Capability::Linkage from consumer module");
		_consumer.removeCapability(spv::Capability::Linkage);
	}

	const auto version = _lib.getSpvVersion() > _consumer.getSpvVersion() ? _lib.getSpvVersion() : _consumer.getSpvVersion();
	_consumer.setSpvVersion(version);
	info("Merged SPIR-V version: %u.%u [%u->%u]", getMajorVersion(version), getMinorVersion(version), _consumer.getSpvVersion(), version);

	// only add required capabilities & extensions
	if (_options.grammar != nullptr && (_options & LinkerOptionBits::AutoAddRequiredCapabilitiesAndExtensions))
	{
		_consumer.addRequiredCapabilities(*_options.grammar);
		_consumer.addRequiredExtensions(*_options.grammar);
	}
	else // import all capabilities
	{
		for (const auto& [cap, instr] : _lib.getCapabilities())
		{
			_consumer.addCapability(cap);
		}

		for (const auto& [name, instr] : _lib.getExtensions())
		{
			_consumer.addExtension(name.c_str());
		}
	}

	// OpTypeArray might have implictly added a integer OpConstant & OpType
	if (_options & LinkerOptionBits::AssignResultIDs)
	{
		for (Instruction& ct : _consumer.getTypesAndConstants())
		{
			ct.assignResultId(false);
		}
	}

	if(_options & LinkerOptionBits::ImportReferencedNames)
	{
		for(const Instruction& name : _lib.getNames())
		{
			const Instruction* lTarget = name.getFirstActualOperand()->getInstruction();
			if(Instruction** ppCTarget = cache[lTarget]; ppCTarget != nullptr)
			{
				Instruction* cTarget = *ppCTarget;

				auto cRange = _consumer.getNameLookupMap().getRange(static_cast<const Instruction*>(cTarget));

				// check if we already added (member) names for this instructions
				if (cRange.empty())
				{
					for (const auto& n : _lib.getNameLookupMap().getRange(lTarget))
					{
						if (*lTarget == spv::Op::OpTypeStruct)
						{
							_consumer.addMemberName(cTarget, n.kv.value.name.c_str(), n.kv.value.member);
						}
						else
						{
							_consumer.addName(cTarget, n.kv.value.name.c_str());
						}
					}
				}
			}
		}
	}

	auto copy = [&](const List<Instruction>& _in, auto addFunc) -> bool
	{
		for (const Instruction& src : _in)
		{
			Instruction* cSrc = addFunc();
			if (transferInstruction(&src, cSrc, cache, _options) == false)
				return false;

			printInstruction(_options, &src, " -> ", cSrc);
		}
		return true;
	};

	if (_options & LinkerOptionBits::CopyOpSourceStringInstructions)
	{
		success &= copy(_lib.getSourceStrings(), [&]() -> Instruction* { return _consumer.addSourceStringInstr(); });
	}

	if (_options & LinkerOptionBits::CopyOpLineInstructions)
	{
		success &= copy(_lib.getLines(), [&]() -> Instruction* { return _consumer.addLineInstr(); });
	}

	if (_options & LinkerOptionBits::CopyOpModuleProcessedInstructions)
	{
		success &= copy(_lib.getModulesProcessed(), [&]() -> Instruction* { return _consumer.addLineInstr(); });
	}

	if (_options & LinkerOptionBits::UpdateEntryPointGlobalVarInterface)
	{
		// update global variable interface in case it changed and the user forgets to finalize the module
		_consumer.finalizeEntryPoints();	
	}

	return success;
}
