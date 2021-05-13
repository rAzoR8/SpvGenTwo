#include "spvgentwo/Module.h"
#include "spvgentwo/Writer.h"
#include "spvgentwo/Reader.h"
#include "spvgentwo/Logger.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

#include "spvgentwo/Grammar.h"

spvgentwo::Module::Module(IAllocator* _pAllocator, ILogger* _pLogger, ITypeInferenceAndVailation* _pTypeInferenceAndVailation) :
	Module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::Simple, _pLogger, _pTypeInferenceAndVailation) // use delegate constructor
{
}

spvgentwo::Module::Module(IAllocator* _pAllocator, const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel, ILogger* _pLogger, ITypeInferenceAndVailation* _pTypeInferenceAndVailation) :
	m_pAllocator(_pAllocator),
	m_pLogger(_pLogger),
	m_pTypeInferenceAndVailation(_pTypeInferenceAndVailation),
	m_spvVersion(makeVersion(1u, 0u)),
	m_spvBound(0u),
	m_spvSchema(0u),
	m_Functions(_pAllocator),
	m_EntryPoints(_pAllocator),
	m_Capabilities(_pAllocator),
	m_Extensions(_pAllocator),
	m_ExtInstrImport(_pAllocator),
	m_MemoryModel(this, spv::Op::OpMemoryModel),
	m_ExecutionModes(_pAllocator),
	m_SourceStrings(_pAllocator),
	m_Names(_pAllocator),
	m_ModuleProccessed(_pAllocator),
	m_Decorations(_pAllocator),
	m_TypesAndConstants(_pAllocator),
	m_TypeToInstr(_pAllocator),
	m_InstrToType(_pAllocator),
	m_ConstantToInstr(_pAllocator),
	m_InstrToConstant(_pAllocator),
	m_NameLookup(_pAllocator),
	m_GlobalVariables(_pAllocator),
	m_Undefs(_pAllocator),
	m_Lines(_pAllocator),
	m_errorInstr(this)
{
	if (_pAllocator != nullptr)
	{
		setMemoryModel(_addressModel, _memoryModel);	
	}
}

spvgentwo::Module::Module(Module&& _other) noexcept:
	m_pAllocator(_other.m_pAllocator),
	m_pLogger(_other.m_pLogger),
	m_pTypeInferenceAndVailation(_other.m_pTypeInferenceAndVailation),
	m_spvVersion(_other.m_spvVersion),
	m_spvBound(_other.m_spvBound),
	m_spvSchema(_other.m_spvSchema),
	m_Functions(stdrep::move(_other.m_Functions)),
	m_EntryPoints(stdrep::move(_other.m_EntryPoints)),
	m_Capabilities(stdrep::move(_other.m_Capabilities)),
	m_Extensions(stdrep::move(_other.m_Extensions)),
	m_ExtInstrImport(stdrep::move(_other.m_ExtInstrImport)),
	m_MemoryModel(this, stdrep::move(_other.m_MemoryModel)),
	m_ExecutionModes(stdrep::move(_other.m_ExecutionModes)),
	m_SourceStrings(stdrep::move(_other.m_SourceStrings)),
	m_Names(stdrep::move(_other.m_Names)),
	m_ModuleProccessed(stdrep::move(_other.m_ModuleProccessed)),
	m_Decorations(stdrep::move(_other.m_Decorations)),
	m_TypesAndConstants(stdrep::move(_other.m_TypesAndConstants)),
	m_TypeToInstr(stdrep::move(_other.m_TypeToInstr)),
	m_InstrToType(stdrep::move(_other.m_InstrToType)),
	m_ConstantToInstr(stdrep::move(_other.m_ConstantToInstr)),
	m_InstrToConstant(stdrep::move(_other.m_InstrToConstant)),
	m_NameLookup(stdrep::move(_other.m_NameLookup)),
	m_GlobalVariables(stdrep::move(_other.m_GlobalVariables)),
	m_Undefs(stdrep::move(_other.m_Undefs)),
	m_Lines(stdrep::move(_other.m_Lines)),
	m_errorInstr(this, stdrep::move(_other.m_errorInstr))
{
	updateParentPointers();
}

spvgentwo::Module& spvgentwo::Module::operator=(Module&& _other) noexcept
{
	if (this == &_other) return *this;

	m_pAllocator = _other.m_pAllocator;
	m_pLogger = _other.m_pLogger;
	m_pTypeInferenceAndVailation = _other.m_pTypeInferenceAndVailation;
	m_spvVersion = _other.m_spvVersion;
	m_spvBound = _other.m_spvBound;
	m_spvSchema = _other.m_spvSchema;
	m_Functions = stdrep::move(_other.m_Functions);
	m_EntryPoints = stdrep::move(_other.m_EntryPoints);
	m_Capabilities = stdrep::move(_other.m_Capabilities);
	m_Extensions = stdrep::move(_other.m_Extensions);
	m_ExtInstrImport = stdrep::move(_other.m_ExtInstrImport);
	m_MemoryModel = stdrep::move(_other.m_MemoryModel);
	m_ExecutionModes = stdrep::move(_other.m_ExecutionModes);
	m_SourceStrings = stdrep::move(_other.m_SourceStrings);
	m_Names = stdrep::move(_other.m_Names);
	m_ModuleProccessed = stdrep::move(_other.m_ModuleProccessed);
	m_Decorations = stdrep::move(_other.m_Decorations);
	m_TypesAndConstants = stdrep::move(_other.m_TypesAndConstants);
	m_TypeToInstr = stdrep::move(_other.m_TypeToInstr);
	m_InstrToType = stdrep::move(_other.m_InstrToType);
	m_ConstantToInstr = stdrep::move(_other.m_ConstantToInstr);
	m_InstrToConstant= stdrep::move(_other.m_InstrToConstant);
	m_NameLookup = stdrep::move(_other.m_NameLookup);
	m_GlobalVariables = stdrep::move(_other.m_GlobalVariables);
	m_Undefs = stdrep::move(_other.m_Undefs);
	m_Lines = stdrep::move(_other.m_Lines);

	updateParentPointers();

	return *this;
}

void spvgentwo::Module::updateParentPointers()
{
	for (Function& func : m_Functions)
	{
		func.m_pModule = this;
	}

	for (Function& func : m_EntryPoints)
	{
		func.m_pModule = this;
	}

	auto fixList = [&](List<Instruction>& list)
	{
		for (Instruction& instr : list)
		{
			instr.m_parent.pModule = this;
		}
	};

	auto fixMap = [&](auto& map)
	{
		for (auto& [key, instr] : map)
		{
			instr.m_parent.pModule = this;
		}
	};

	fixMap(m_Capabilities);
	fixMap(m_Extensions);
	fixMap(m_ExtInstrImport);

	fixList(m_ExecutionModes);
	fixList(m_SourceStrings);
	fixList(m_Names);
	fixList(m_ModuleProccessed);
	fixList(m_Decorations);
	fixList(m_TypesAndConstants);
	fixList(m_GlobalVariables);
	fixList(m_Undefs);
	fixList(m_Lines);
}

spvgentwo::Module::~Module()
{
}

void spvgentwo::Module::reset()
{
	m_spvVersion = spv::Version;
	m_spvGenerator = GeneratorId;
	m_spvBound = 0u;
	m_spvSchema = 0u;

	m_Functions.clear();
	m_EntryPoints.clear();

	m_Capabilities.clear();
	m_Extensions.clear();
	m_ExtInstrImport.clear();

	setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::Simple);

	m_ExecutionModes.clear();
	m_SourceStrings.clear();
	m_Names.clear();
	m_ModuleProccessed.clear();
	m_Decorations.clear();

	m_TypesAndConstants.clear();

	m_TypeToInstr.clear();
	m_InstrToType.clear();
	m_ConstantToInstr.clear();
	m_InstrToConstant.clear();

	m_NameLookup.clear();

	m_GlobalVariables.clear();
	m_Undefs.clear();
	m_Lines.clear();
}

spvgentwo::Function& spvgentwo::Module::addFunction()
{
	return m_Functions.emplace_back(this);
}

spvgentwo::List<spvgentwo::Instruction*> spvgentwo::Module::remove(const Function* _pFunction, Function* _pReplacementToCall, IAllocator* _pAllocator)
{
	List<Instruction*> uses(_pAllocator == nullptr ? getAllocator() : _pAllocator);

	if (_pFunction == nullptr)
	{
		return uses;
	}

	const Instruction* opFunction = _pFunction->getFunction();
	Instruction* opFunctionReplacement = _pReplacementToCall != nullptr ? _pReplacementToCall->getFunction() : nullptr;

	// remove from functions if its not an entry point
	bool found = false;
	for (auto it = m_Functions.begin(), end = m_Functions.end(); it != end; ++it)
	{
		if (it.operator->() == _pFunction)
		{
			m_Functions.erase(it);
			found = true;
			break;
		}
	}

	// function seems to be an entry point
	if (found == false)
	{
		for (auto it = m_EntryPoints.begin(), end = m_EntryPoints.end(); it != end; ++it)
		{
			if (it.operator->() == _pFunction)
			{
				m_EntryPoints.erase(it);
				found = true;
				break;
			}
		}
	}

	if (found)
	{
		auto gatherUse = [opFunction, opFunctionReplacement, &uses](Instruction& instr)
		{
			for (auto it = instr.getFirstActualOperand(), end = instr.end(); it != end; ++it)
			{
				if (*it == opFunction) // need to check use of OpFunctionparameter?
				{
					*it = opFunctionReplacement;
					uses.emplace_back(&instr);
					break;
				}
			}
		};

		iterateInstructions(gatherUse);
	}
	else
	{
		logError("Could not remove function, not found in module");
	}

	return uses;
}

spvgentwo::EntryPoint& spvgentwo::Module::addEntryPoint()
{
	return m_EntryPoints.emplace_back(this);
}

spvgentwo::Type spvgentwo::Module::newType()
{
	return Type(m_pAllocator);
}

spvgentwo::Constant spvgentwo::Module::newConstant()
{
	return Constant(m_pAllocator);
}

spvgentwo::Instruction* spvgentwo::Module::addGlobalVariableInstr(const char* _pName)
{
	Instruction* pVar = &m_GlobalVariables.emplace_back(this);
	pVar->setOperation(spv::Op::OpVariable);

	if (_pName != nullptr)
	{
		addName(pVar, _pName);
	}

	return pVar;
}

void spvgentwo::Module::addCapability(spv::Capability _capability, bool _addDependentCapablity)
{
	if (_addDependentCapablity)
	{
		const BaseCapability cap = getBaseCapability(_capability);
		if (cap.primary != spv::Capability::Max)
		{
			addCapability(cap.primary, true);
		}
		if (cap.secondary != spv::Capability::Max)
		{
			addCapability(cap.primary, true);
		}
	}

	m_Capabilities.emplaceUnique(_capability, Instruction(this, spv::Op::OpCapability, _capability));
}

bool spvgentwo::Module::checkCapability(spv::Capability _capability) const
{
	return m_Capabilities.find(_capability) != m_Capabilities.end();
}

bool spvgentwo::Module::removeCapability(spv::Capability _capability)
{
	if (auto it = m_Capabilities.find(_capability); it != m_Capabilities.end())
	{
		m_Capabilities.erase(it);
		return true;
	}
	return false;
}

void spvgentwo::Module::addExtension(const char* _pExtName)
{
	Instruction& instr = m_Extensions.emplaceUnique(String(m_pAllocator, _pExtName), this).kv.value;
	if (instr.empty()) 
	{
		instr.opExtension(_pExtName);	
	}
}

spvgentwo::Instruction* spvgentwo::Module::getExtensionInstructionImport(const char* _pExtName)
{
	Instruction& instr = m_ExtInstrImport.emplaceUnique(String(m_pAllocator, _pExtName), this).kv.value;
	if (instr.empty())
	{
		instr.opExtInstImport(_pExtName);
	}

	return &instr;
}

spvgentwo::Instruction* spvgentwo::Module::addSourceStringInstr()
{
	return &m_SourceStrings.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addNameInstr()
{
	return &m_Names.emplace_back(this);
}

void spvgentwo::Module::addName(Instruction* _pTarget, const char* _pName)
{
	addNameInstr()->opName(_pTarget, _pName);
	m_NameLookup.emplace(_pTarget, MemberName{ String(m_pAllocator, _pName), ~0u });
}

void spvgentwo::Module::addMemberName(Instruction* _pTargetBase, const char* _pMemberName, unsigned int _memberIndex)
{
	addNameInstr()->opMemberName(_pTargetBase, _memberIndex, _pMemberName);
	m_NameLookup.emplace(_pTargetBase, MemberName{ String(m_pAllocator, _pMemberName), _memberIndex });
}

const char* spvgentwo::Module::getName(const Instruction* _pTarget, const unsigned int _memberIndex) const
{
	for (auto& name : m_NameLookup.getRange(_pTarget))
	{
		if (name.kv.value.member == _memberIndex)
		{
			return name.kv.value.name.c_str();
		}
	}

	return nullptr;
}

spvgentwo::List<spvgentwo::Module::MemberNameCStr> spvgentwo::Module::getNames(const Instruction* _pTarget, IAllocator* _pAllocator) const
{
	List<MemberNameCStr> names(_pAllocator == nullptr ? getAllocator() : _pAllocator);

	for (auto& name : m_NameLookup.getRange(_pTarget))
	{
		if (name.kv.key == _pTarget) 
		{		
			names.emplace_back(name.kv.value.name.c_str(), name.kv.value.member);
		}
	}

	return names;
}

spvgentwo::Instruction* spvgentwo::Module::addModuleProccessedInstr()
{
	return &m_ModuleProccessed.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addDecorationInstr()
{
	return &m_Decorations.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addConstant(const Constant& _const, const char* _pName)
{
	auto& node = m_ConstantToInstr.emplaceUnique(_const, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	Instruction* pType = addType(_const.getType());

	auto entry = Entry<Instruction>::create(m_pAllocator, this);

	Instruction* pInstr = node.kv.value = entry->operator->();

	m_InstrToConstant.emplaceUnique(pInstr, &node.kv.key);

	const spv::Op constantOp = _const.getOperation();
	pInstr->setOperation(constantOp);

	pInstr->addOperand(pType);
	pInstr->addOperand(InvalidId);

	switch (constantOp)
	{
	case spv::Op::OpConstantTrue:
	case spv::Op::OpConstantFalse:
	case spv::Op::OpConstantNull:
	case spv::Op::OpSpecConstantTrue:
	case spv::Op::OpSpecConstantFalse:
		// nothing to do
		break;
	case spv::Op::OpConstant:
	case spv::Op::OpSpecConstant:
	case spv::Op::OpConstantSampler:
		for(const unsigned int& val : _const.getData())
		{
			pInstr->addOperand(literal_t{ val });
		}
		break;
	case spv::Op::OpConstantComposite:
	case spv::Op::OpSpecConstantComposite:
		for(const Constant& component : _const.getComponents())
		{
			pInstr->addOperand(addConstant(component));		
		}
		break;
	case spv::Op::OpSpecConstantOp:
		logFatal("OpSpecConstantOp not supported by Module::constant() or addConstant(), use Instruction::toSpecOp or opSpecConstantOp()");
		break;
	default:

		logFatal("Constant not implemented");
		break;
	}

	pInstr->validateOperands();

	m_TypesAndConstants.append_entry(entry);

	if (_pName != nullptr)
	{
		addName(pInstr, _pName);
	}

	return pInstr;
}

const spvgentwo::Constant* spvgentwo::Module::getConstantInfo(const Instruction* _pConstantInstr)
{
	if (_pConstantInstr != nullptr && _pConstantInstr->isSpecOrConstant())
	{
		const Constant* const* c = m_InstrToConstant.get(_pConstantInstr);

		if (c != nullptr)
		{
			return *c;
		}
	}
	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Module::addType(const Type& _type, const char* _pName)
{
	auto& node = m_TypeToInstr.emplaceUnique(_type, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	auto entry = Entry<Instruction>::create(m_pAllocator, this);

	Instruction* pInstr = node.kv.value = entry->operator->();

	m_InstrToType.emplaceUnique(pInstr, &node.kv.key);

	const spv::Op base = _type.getType();

	pInstr->setOperation(base);

	if (base != spv::Op::OpTypeForwardPointer)
	{
		pInstr->addOperand(InvalidId);
	}

	switch (base)
	{
	case spv::Op::OpTypeVoid:
	case spv::Op::OpTypeBool:
	case spv::Op::OpTypeSampler:
	case spv::Op::OpTypeEvent:
	case spv::Op::OpTypeDeviceEvent:
	case spv::Op::OpTypeReserveId:
	case spv::Op::OpTypeQueue:
	case spv::Op::OpTypePipeStorage:
	case spv::Op::OpTypeNamedBarrier:

	case spv::Op::OpTypeRayQueryKHR:
	case spv::Op::OpTypeAccelerationStructureKHR:

	case spv::Op::OpTypeAvcMcePayloadINTEL:
	case spv::Op::OpTypeAvcImePayloadINTEL:
	case spv::Op::OpTypeAvcRefPayloadINTEL:
	case spv::Op::OpTypeAvcSicPayloadINTEL:
	case spv::Op::OpTypeAvcMceResultINTEL:
	case spv::Op::OpTypeAvcImeResultINTEL:
	case spv::Op::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
	case spv::Op::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
	case spv::Op::OpTypeAvcImeSingleReferenceStreaminINTEL:
	case spv::Op::OpTypeAvcImeDualReferenceStreaminINTEL:
	case spv::Op::OpTypeAvcRefResultINTEL:
	case spv::Op::OpTypeAvcSicResultINTEL:

		break; // nothing to do
	case spv::Op::OpTypeInt:
		pInstr->appendLiterals(_type.getIntWidth(), static_cast<unsigned int>(_type.getIntSign()));
		break;
	case spv::Op::OpTypeFloat:
		pInstr->appendLiterals(_type.getFloatWidth());
		break;
	case spv::Op::OpTypeVector:
	case spv::Op::OpTypeMatrix:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // column type
		pInstr->appendLiterals(_type.getMatrixColumnCount());
		break;
	case spv::Op::OpTypePointer:
		pInstr->appendLiterals(_type.getStorageClass());
		pInstr->addOperand(addType(_type.getSubTypes().front())); // base type
		break;
	case spv::Op::OpTypeForwardPointer:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // base type
		pInstr->appendLiterals(_type.getStorageClass());
		break;
	case spv::Op::OpTypeStruct:
	case spv::Op::OpTypeFunction:
		for (const Type& member : _type.getSubTypes())
		{
			pInstr->addOperand(addType(member)); // member type
		}
		break;
	case spv::Op::OpTypeRuntimeArray:
	case spv::Op::OpTypeSampledImage:
	case spv::Op::OpTypeVmeImageINTEL:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // element type
		break;
	case spv::Op::OpTypeArray:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // element type
		pInstr->addOperand(constant(_type.getArrayLength())); // length as constant
		break;
	case spv::Op::OpTypeImage:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // sampled type
		pInstr->appendLiterals(_type.getImageDimension());
		pInstr->appendLiterals(_type.getImageDepth());
		pInstr->appendLiterals(_type.getImageArray());
		pInstr->appendLiterals(_type.getImageMultiSampled());
		pInstr->appendLiterals(_type.getImageSamplerAccess());
		pInstr->appendLiterals(_type.getImageFormat());
		if(_type.getAccessQualifier() != spv::AccessQualifier::Max)
		{
			pInstr->appendLiterals(_type.getAccessQualifier());
		}
		break;
	default:
		logFatal("Type [%u] not implemented", base);
		break; // unknown type
	}

	pInstr->validateOperands();

	m_TypesAndConstants.append_entry(entry);

	if (_pName != nullptr) 
	{
		addName(pInstr, _pName);
	}

	return pInstr;
}

spvgentwo::Instruction* spvgentwo::Module::getTypeInstr(const Type& _type) const
{
	if(Instruction** instr = m_TypeToInstr.get(_type); instr != nullptr)
	{
		return *instr;
	}
	return nullptr;
}

const spvgentwo::Type* spvgentwo::Module::getTypeInfo(const Instruction* _pTypeInstr) const 
{
	if (_pTypeInstr != nullptr && _pTypeInstr->isType())
	{
		const Type* const* t = m_InstrToType.get(_pTypeInstr);

		if (t != nullptr)
		{
			return *t;
		}
	}
	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Module::addTypeInstr(const Type* _pType)
{
	Instruction* instr = &m_TypesAndConstants.emplace_back(this);

	if (_pType != nullptr)
	{
		m_TypeToInstr.emplaceUnique(*_pType, instr);
		m_InstrToType.emplaceUnique(instr, _pType);
	}

	return instr;
}

spvgentwo::Instruction* spvgentwo::Module::addConstantInstr(const Constant* _pConstant)
{
	Instruction* instr = &m_TypesAndConstants.emplace_back(this);

	if (_pConstant != nullptr)
	{
		m_ConstantToInstr.emplaceUnique(*_pConstant, instr);
		m_InstrToConstant.emplaceUnique(instr, _pConstant);
	}

	return instr;
}

spvgentwo::Instruction* spvgentwo::Module::compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes)
{
	Type t(m_pAllocator);
	t.setType(_Type);
	
	for (Instruction* pSubType : _subTypes)
	{
		const Type* info = getTypeInfo(pSubType);
		if (info != nullptr)
		{
			t.getSubTypes().emplace_back(*info);
		}
	}

	return addType(t);
}

void spvgentwo::Module::setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	m_MemoryModel.opMemoryModel(_addressModel, _memoryModel);
}

spvgentwo::spv::Id spvgentwo::Module::assignIDs(const Grammar* _pGrammar)
{
	unsigned int maxId = 0u;
	unsigned int maxVersion = makeVersion(1u, 0u);

	iterateInstructions([&maxId, &maxVersion, _pGrammar, this](Instruction& instr)
	{
		if (_pGrammar != nullptr) // add missing capabilities, extensions and required version
		{
			if (auto* info = _pGrammar->getInfo(static_cast<unsigned int>(instr.getOperation())); info != nullptr)
			{
				for (const spv::Capability& c : info->capabilities)
				{
					addCapability(c);
				}
				for (const spv::Extension& e : info->extensions)
				{
					addExtension(e);
				}
				if (info->version > maxVersion)
				{
					maxVersion = info->version;
				}
			}
		}

		// assign IDs
		if (auto it = instr.getResultIdOperand(); it != nullptr)
		{
			*it = spv::Id{ ++maxId };
		}
	});

	m_spvVersion = maxVersion;
	m_spvBound = maxId + 1u;

	return spv::Id{ maxId };
}

bool spvgentwo::Module::resolveIDs(IAllocator* _pAllocator)
{
	bool success = true;

	HashMap<spv::Id, Instruction*> idToPtr(_pAllocator != nullptr ? _pAllocator : m_pAllocator);

	auto populate = [&idToPtr, &success, this](Instruction& _instr) -> bool
	{
		// this instruction generates a new Id
		if (auto it = _instr.getResultIdOperand(); it != nullptr)
		{
			if (it->isId() == false) // this is just to check if a previous transformation changed the type of operand in error 
			{
				logError("Result <id> operand is not a ID operand");
				success = false;
				return true; // stop iterating
			}

			idToPtr.emplaceUnique(it->id, &_instr);
		}
		return false;
	};

	iterateInstructions(populate);

	if (success == false)
	{
		return false;
	}

	auto lookUp = [&idToPtr, &success, this](Instruction& _instr) -> bool
	{
		for (auto it = _instr.begin(), end = _instr.end(); it != end; ++it)
		{
			if (_instr.hasResult() && it == _instr.getResultIdOperand()) // dont replace the dummy resultID operand
			{
				continue;
			}

			if (spv::Id id = it->getId(); id != InvalidId)
			{
				if (Instruction** ppInstr = idToPtr.get(id); ppInstr != nullptr) // lookup pointer for operand
				{
					Instruction* op = *ppInstr;

					// operand is a branch target
					if (op->getOperation() == spv::Op::OpLabel &&
						(_instr.getOperation() == spv::Op::OpBranch ||
						 _instr.getOperation() == spv::Op::OpBranchConditional ||
						 _instr.getOperation() == spv::Op::OpSwitch))
					{
						*it = op->getBasicBlock();
					}
					else
					{
						*it = op;
					}	
				}
				else
				{
					logError("Instruction not found for Id %u", id);
					success = false;
					return true; // abort
				}
			}
		}
		return false; // continue iterating
	};

	iterateInstructions(lookUp);

	return success;
}

bool spvgentwo::Module::reconstructTypeAndConstantInfo(IAllocator* _pAllocator)
{
	m_InstrToType.clear();
	m_TypeToInstr.clear();
	m_InstrToConstant.clear();
	m_ConstantToInstr.clear();

	bool success = true;

	for (Instruction& instr : m_TypesAndConstants)
	{
		auto it = instr.getFirstActualOperand(); // TODO: validate number of available operands with Grammar in read() (for now just assume the .spv is valid)

		if (instr.isType())
		{
			Type t(_pAllocator != nullptr ? _pAllocator: m_pAllocator);
			t.setType(instr.getOperation());

			switch (instr.getOperation())
			{
			case spv::Op::OpTypeVoid:
			case spv::Op::OpTypeBool:
			case spv::Op::OpTypeSampler:
			case spv::Op::OpTypeEvent:
			case spv::Op::OpTypeDeviceEvent:
			case spv::Op::OpTypeReserveId:
			case spv::Op::OpTypeQueue:
			case spv::Op::OpTypePipeStorage:
			case spv::Op::OpTypeNamedBarrier:

			case spv::Op::OpTypeRayQueryKHR:
			case spv::Op::OpTypeAccelerationStructureKHR:

			case spv::Op::OpTypeAvcMcePayloadINTEL:
			case spv::Op::OpTypeAvcImePayloadINTEL:
			case spv::Op::OpTypeAvcRefPayloadINTEL:
			case spv::Op::OpTypeAvcSicPayloadINTEL:
			case spv::Op::OpTypeAvcMceResultINTEL:
			case spv::Op::OpTypeAvcImeResultINTEL:
			case spv::Op::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
			case spv::Op::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
			case spv::Op::OpTypeAvcImeSingleReferenceStreaminINTEL:
			case spv::Op::OpTypeAvcImeDualReferenceStreaminINTEL:
			case spv::Op::OpTypeAvcRefResultINTEL:
			case spv::Op::OpTypeAvcSicResultINTEL:

				break; // nothing to do
			case spv::Op::OpTypeInt:
				t.setIntWidth(it->getLiteral());
				t.setIntSign((++it)->getLiteral() == 1u);
				break;
			case spv::Op::OpTypeFloat:
				t.setFloatWidth(it->getLiteral());
				break;
			case spv::Op::OpTypeVector:
			case spv::Op::OpTypeMatrix:
			{
				const Type* sub = getTypeInfo(it->getInstruction());
				if (sub == nullptr)
				{
					logError("Component or Column sub type not found");
					success = false;
				}

				t.Member(sub); // component / column type
				t.setVectorComponentCount((++it)->getLiteral()); // or MatrixColumnCount
			}
			break;
			case spv::Op::OpTypePointer:
				t.setStorageClass(static_cast<spv::StorageClass>(it->getLiteral().value));
				{
					const Type* sub = getTypeInfo((++it)->getInstruction());
					if (sub == nullptr)
					{
						logError("Pointer base type not found");
						success = false;
					}
					t.Member(sub);
				}
				break;
			case spv::Op::OpTypeForwardPointer:
			{
				const Type* sub = getTypeInfo(it->getInstruction());
				if (sub == nullptr)
				{
					logError("Pointer type not found");
					success = false;
				}
				t.Member(sub);
				t.setStorageClass(static_cast<spv::StorageClass>((++it)->getLiteral().value));
			}
			break;
			case spv::Op::OpTypeStruct:
			case spv::Op::OpTypeFunction:
				for (auto end = instr.end(); it != end; ++it)
				{
					const Type* sub = getTypeInfo(it->getInstruction());
					if (sub == nullptr)
					{
						logError("Member or Parameter sub type not found");
						success = false;
					}
					t.Member(sub); // member or parameter type
				}
				break;
			case spv::Op::OpTypeRuntimeArray:
			case spv::Op::OpTypeSampledImage:
			case spv::Op::OpTypeVmeImageINTEL:
			{
				const Type* sub = getTypeInfo(it->getInstruction());
				if (sub == nullptr)
				{
					logError("Element or image type not found");
					success = false;
				}
				t.Member(sub); // element or image type
			}
			break;
			case spv::Op::OpTypeArray:
			{
				const Type* sub = getTypeInfo(it->getInstruction());
				if (sub == nullptr)
				{
					logError("Element type not found");
					success = false;
				}
				t.Member(sub); // element type

				const Constant* c = getConstantInfo((++it)->getInstruction());
				if (c == nullptr)
				{
					logError("Array length constant not found");
					success = false;
					break; // don't deref c
				}

				if (c->getType().isInt() && c->getData().empty() == false)
				{
					t.setArrayLength(c->getData().front()); // array length
				}
				else
				{
					logError("Invalid constant data");
					success = false;
				}
			}
			break;
			case spv::Op::OpTypeImage:
			{
				const Type* sub = getTypeInfo(it->getInstruction());
				if (sub == nullptr)
				{
					logError("Sampled type not found");
					success = false;
				}
				t.Member(sub); // sampled type

				t.setImageDimension(static_cast<spv::Dim>((++it)->getLiteral().value));
				t.setImageDepth((++it)->getLiteral());
				t.setImageArray((++it)->getLiteral() == 1u);
				t.setImageMultiSampled((++it)->getLiteral() == 1u);
				t.setImageSamplerAccess(static_cast<spvgentwo::SamplerImageAccess>((++it)->getLiteral().value));
				t.setImageFormat(static_cast<spv::ImageFormat>((++it)->getLiteral().value));

				if (++it != nullptr)
				{
					t.setAccessQualifier(static_cast<spv::AccessQualifier>((++it)->getLiteral().value));
				}
			}
			break;
			default:
				logError("Type [%u] not implemented", instr.getOperation());
				success = false;
			}

			auto& node = m_TypeToInstr.emplaceUnique(stdrep::move(t), &instr);
			m_InstrToType.emplaceUnique(&instr, &node.kv.key);
		}
		else if (instr.isSpecOrConstant())
		{
			Constant c(_pAllocator != nullptr ? _pAllocator : m_pAllocator);

			c.setOperation(instr.getOperation());

			if (const Type* t = getTypeInfo(instr.getResultTypeInstr()); t != nullptr)
			{
				c.getType() = *t;
			}
			else
			{
				logError("Constant type not found");
				success = false;
			}

			switch (instr.getOperation())
			{
			case spv::Op::OpConstantNull:
			case spv::Op::OpConstantTrue:
			case spv::Op::OpSpecConstantTrue:
			case spv::Op::OpConstantFalse:
			case spv::Op::OpSpecConstantFalse:
				break; // nothing to do
			case spv::Op::OpConstant:
			case spv::Op::OpSpecConstant:
			case spv::Op::OpConstantSampler:
				for (auto end = instr.end(); it != end; ++it)
				{
					c.getData().emplace_back(it->getLiteral());
				}
				break;
			case spv::Op::OpConstantComposite:
			case spv::Op::OpSpecConstantComposite:
				for (auto end = instr.end(); it != end; ++it)
				{					
					if (const Constant* sub = getConstantInfo(it->getInstruction()); sub != nullptr)
					{
						c.Component() = *sub;
					}
					else
					{
						logError("Constituent constant not found");
						success = false;					
					}
				}
				break;
			case spv::Op::OpSpecConstantOp:
				continue; // continue the loop, dont add to lookup
				//break;
			default:
				logError("Constant [%u] not implemented", instr.getOperation());
				success = false;
			}

			auto& node = m_ConstantToInstr.emplaceUnique(stdrep::move(c), &instr);
			m_InstrToConstant.emplaceUnique(&instr, &node.kv.key);
		}
	}

	auto updateFunctionTypes = [](Function& _fun) -> bool
	{
		if (auto it = _fun.getFunction()->last(); it != nullptr && it->isInstruction() && it->instruction->isType()) // last operand is OpTypeFunction
		{
			return _fun.setFunctionType(it->instruction);
		}
		return false;
	};

	for (Function& f : m_Functions)
	{
		if (updateFunctionTypes(f) == false)
			success = false;
	}

	for (EntryPoint& f : m_EntryPoints)
	{
		if (updateFunctionTypes(f) == false)
			success = false;
	}

	return success;
}

bool spvgentwo::Module::reconstructNames(IAllocator* _pAllocator)
{
	m_NameLookup.clear();

	bool success = true;

	for (const Instruction& instr : m_Names)
	{
		auto it = instr.getFirstActualOperand();
		const Instruction* target = it != nullptr ? it->getInstruction() : nullptr;

		if (target == nullptr)
		{
			logError("Invalid OpName / OpMemberName target");
			success = false;
			continue;
		}

		unsigned int memberIndex = ~0u;

		if (instr.getOperation() == spv::Op::OpMemberName)
		{
			if (++it == nullptr || it->isLiteral() == false)
			{
				logError("Invalid member index operand for OpMemberName");
				success = false;
				continue;
			}
			memberIndex = it->literal.value;
		}
		else if (instr.getOperation() != spv::Op::OpName)
		{
			logError("Invalid name instructions");
			success = false;
			continue;
		}

		String& name = m_NameLookup.emplace(target, MemberName{ _pAllocator != nullptr ? _pAllocator : m_pAllocator, memberIndex }).kv.value.name;

		getLiteralString(name, it.next(), instr.end());

		if (name.empty())
		{
			logWarning("Empty OpName literal string");
		}
	}

	return success;
}

bool spvgentwo::Module::write(IWriter& _writer) const
{
	// write header
	if (_writer.put(spv::MagicNumber) == false) return false;
	if (_writer.put(m_spvVersion) == false) return false;
	if (_writer.put(GeneratorId) == false) return false;
	if (_writer.put(m_spvBound) == false) return false;
	if (_writer.put(m_spvSchema) == false) return false;

	auto writeInstr = [&_writer](const Instruction& instr) -> bool
	{
		return instr.write(_writer) == false;
	};

	// iterateModuleInstructions returns TRUE if not all instructions were enumarated because _func returned TRUE
	return !iterateInstructions(writeInstr);
}

bool spvgentwo::Module::finalizeAndWrite(IWriter& _writer, const Grammar* _pGrammar)
{
	finalizeEntryPoints();

	assignIDs(_pGrammar); // overwrites m_spvBound

	return write(_writer);
}

void spvgentwo::Module::finalizeEntryPoints()
{
	// finalize entry points interfaces
	for (EntryPoint& ep : m_EntryPoints)
	{
		if (m_spvVersion < makeVersion(1u, 4u))
		{
			ep.finalizeGlobalInterface(GlobalInterfaceVersion::SpirV1_3);
		}
		else
		{
			ep.finalizeGlobalInterface(GlobalInterfaceVersion::SpirV14_x);
		}
	}
}

bool spvgentwo::Module::read(IReader& _reader, const Grammar& _grammar)
{
	unsigned int word{ 0 };

	if (_reader.get(word) == false || word != spv::MagicNumber)
	{
		logError("Failed to parse magic number");
		return false;
	}

	if (logError(_reader.get(m_spvVersion), "Failed to parse version") == false) return false;
	if (logError(_reader.get(m_spvGenerator), "Failed to parse generator") == false) return false;
	if (logError(_reader.get(m_spvBound), "Failed to parse bounds") == false) return false;
	if (logError(_reader.get(m_spvSchema), "Failed to parse schema") == false) return false;

	HashMap<spv::Id, EntryPoint*> entryPoints(m_pAllocator);

	while (_reader.get(word))
	{
		const spv::Op op = getOperation(word);
		const unsigned int operands = getOperandCount(word) - 1u;

		if (spv::IsTypeOp(op) || isSpecOrConstantOp(op))
		{
			if (m_TypesAndConstants.emplace_back(this).readOperands(_reader, _grammar, op, operands) == false) return false;
			continue;
		}

		switch (op)
		{
		case spv::Op::OpCapability:
		{
			Instruction opCap(this, spv::Op::OpCapability);
			if (opCap.readOperands(_reader, _grammar, op, operands) == false)
			{
				return false;
			}
			const spv::Capability cap{ opCap.front().getLiteral().value };
			m_Capabilities.emplaceUnique(cap, stdrep::move(opCap));
			break;
		}
		case spv::Op::OpExtension:
		{
			Instruction opExtension(this, spv::Op::OpExtension);
			if (opExtension.readOperands(_reader, _grammar, op, operands) == false)
			{
				return false;
			}

			String name(m_pAllocator);
			getLiteralString(name, opExtension.begin(), opExtension.end());

			if (name.empty())
			{
				logError("Invalid OpExtension name operand");
				return false;
			}

			m_Extensions.emplaceUnique(stdrep::move(name), stdrep::move(opExtension));
			break;
		}
		case spv::Op::OpExtInstImport:
		{
			Instruction opExtInstrImport(this, spv::Op::OpExtension);
			if (opExtInstrImport.readOperands(_reader, _grammar, op, operands) == false)
			{
				return false;
			}

			String name(m_pAllocator);
			getLiteralString(name, opExtInstrImport.begin().next(), opExtInstrImport.end());

			if (name.empty())
			{
				logError("Invalid OpExtInstImport name operand");
				return false;
			}

			m_ExtInstrImport.emplaceUnique(stdrep::move(name), stdrep::move(opExtInstrImport));
			break;
		}
		case spv::Op::OpMemoryModel:
			if (m_MemoryModel.readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpEntryPoint:
		{
			EntryPoint* ep = &m_EntryPoints.emplace_back(this);
			if (ep->getEntryPoint()->readOperands(_reader, _grammar, op, operands) == false)
			{
				return false;
			}

			auto it = ep->getEntryPoint()->getFirstActualOperand(); // get execution model
			if (it == nullptr || it->isLiteral() == false)
			{
				logError("Failed to get execution model operand of EP");
				return false;
			}
			
			ep->setExecutionModel(static_cast<spv::ExecutionModel>(it->literal.value));

			++it; // EntryPoint <id> is second operand of OpEntryPoint
			if (it == nullptr || it->isId() == false)
			{
				logError("Failed to get function ID operand of EP");
				return false;
			}

			const spv::Id id = it->id; // function result id

			// copy name form LiteralString of OpEntryPoint to name storage for getName query
			ep->getNameStorage().clear();
			getLiteralString(ep->getNameStorage(), ++it, ep->getEntryPoint()->end());

			if (ep->getNameStorage().empty())
			{
				logError("Invalid OpEntryPoint name operand");
				return false;
			}

			entryPoints.emplaceUnique(id, ep);
		}
			break;
		case spv::Op::OpExecutionMode:
		case spv::Op::OpExecutionModeId:
			if (addExtensionModeInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpString:
		case spv::Op::OpSourceExtension:
		case spv::Op::OpSource:
		case spv::Op::OpSourceContinued:
			if (addSourceStringInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpName:
		case spv::Op::OpMemberName:
			if (addNameInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpModuleProcessed:
			if (addModuleProccessedInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpDecorate:
		case spv::Op::OpMemberDecorate:
		case spv::Op::OpDecorationGroup:
		case spv::Op::OpGroupDecorate:
		case spv::Op::OpGroupMemberDecorate:
		case spv::Op::OpDecorateId:
		case spv::Op::OpDecorateString:
		case spv::Op::OpMemberDecorateString:
			if (addDecorationInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpVariable:
			if (addGlobalVariableInstr()->readOperands(_reader, _grammar, op, operands) == false) return false;
			
			// check if storage type != function
			if (m_GlobalVariables.last()->getStorageClass() == spv::StorageClass::Function)
			{
				logError("Found OpVariable with StorageClass 'Function in global scope");
				return false;
			}

			break;
		case spv::Op::OpUndef:
			if(addUndefInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpLine:
		case spv::Op::OpNoLine:
			if (addLineInstr()->readOperands(_reader, _grammar, op, operands) == false) return false; break;
		case spv::Op::OpFunction:
		{
			Instruction opFunc(this);
			if (opFunc.readOperands(_reader, _grammar, op, operands) == false)
			{
				return false;
			}

			const spv::Id id = opFunc.getResultId();
			if (id == InvalidId || id >= spv::Id{ m_spvBound })
			{
				logError("Invalid result ID for OpFunction");
				return false;
			}

			// check if this function is an existing entrypoint, otherwise create new function
			Function* func = nullptr;
			if (EntryPoint** epp = entryPoints.get(id); epp != nullptr)
			{
				func = *epp;
			}
			else
			{
				func = &m_Functions.emplace_back(this);
			}

			if (func->read(_reader, _grammar, stdrep::move(opFunc)) == false)
			{
				return false;
			}
		}
			break;
		default:
			logError("Failed to parse operation %u", op);
			return false;
		}
	}

	return true;
}

bool spvgentwo::Module::readAndInit(IReader& _reader, const Grammar& _grammar)
{
	return read(_reader, _grammar) && resolveIDs() && reconstructNames() && reconstructTypeAndConstantInfo();
}

spvgentwo::Instruction* spvgentwo::Module::addExtensionModeInstr()
{
	return &m_ExecutionModes.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, const char* _pName, Instruction* _pInitialzer)
{
	Instruction* pVar = m_GlobalVariables.emplace_back(this).opVariable(_pPtrType, _storageClass, _pInitialzer);

	if (_pName != nullptr)
	{
		addName(pVar, _pName);
	}

	return pVar;
}

spvgentwo::Instruction* spvgentwo::Module::variable(const Type& _ptrType, const spv::StorageClass _storageClass, const char* _pName, Instruction* _pInitialzer)
{
	Instruction* type = _ptrType.isPointer() ? addType(_ptrType) : addType(_ptrType.wrapPointer(_storageClass));

	return variable(type, _storageClass, _pName, _pInitialzer);
}

spvgentwo::Instruction* spvgentwo::Module::addUndefInstr()
{
	return &m_Undefs.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addLineInstr()
{
	return &m_Lines.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::getInstructionById(const spv::Id _resultId)
{
	Instruction* instr = nullptr;

	auto pred = [&instr, _resultId](Instruction& _instr) -> bool
	{
		if (_instr.getResultId() == _resultId)
		{
			instr = &_instr;
			return true; // break
		}
		return false;
	};

	iterateInstructions(pred);

	return instr;
}

void spvgentwo::Module::gatherUses(const Instruction* _pInstr, List<Instruction*>& _outUses, Instruction* _pReplacement)
{
	auto gather = [_pInstr, _pReplacement, &_outUses](Instruction& _instr)
	{
		for (auto it = _instr.getFirstActualOperand(), end = _instr.end(); it != end; ++it)
		{
			if (*it == _pInstr)
			{
				_outUses.emplace_back(&_instr);
				if (_pReplacement != nullptr)
				{
					*it = _pReplacement;				
				}
			}
		}
	};

	iterateInstructions(gather);
}

void spvgentwo::Module::replaceUses(const Instruction* _pInstr, Instruction* _pReplacement)
{
	if (_pInstr == nullptr) 
	{
		return;
	}

	auto replace = [_pInstr, _pReplacement](Instruction& _instr)
	{
		for (auto it = _instr.getFirstActualOperand(), end = _instr.end(); it != end; ++it)
		{
			if (*it == _pInstr)
			{
				*it = _pReplacement;
			}
		}
	};

	iterateInstructions(replace);
}

void spvgentwo::Module::removeFromLookupMaps(const Instruction* _pInstr)
{
	if (auto itt = m_InstrToType.find(_pInstr); itt != m_InstrToType.end())
	{
		if(auto tti = m_TypeToInstr.find(*itt->value); tti != m_TypeToInstr.end())
		{
			m_TypeToInstr.erase(tti);
		}
		m_InstrToType.erase(itt);
	}

	if (auto itc = m_InstrToConstant.find(_pInstr); itc != m_InstrToConstant.end())
	{
		if (auto cti = m_ConstantToInstr.find(*itc->value); cti != m_ConstantToInstr.end())
		{
			m_ConstantToInstr.erase(cti);
		}
		m_InstrToConstant.erase(itc);
	}

	m_NameLookup.eraseRange(_pInstr);
}

bool spvgentwo::Module::remove(const Instruction* _pInstr)
{
	if (_pInstr == nullptr || _pInstr->getModule() != this)
	{
		return false;
	}

	auto erase = [_pInstr](List<Instruction>& container) -> bool
	{
		auto it = container.find_if([_pInstr](const Instruction& _instr) {return &_instr == _pInstr; });
		if (it != container.end())
		{
			container.erase(it);
			return true;
		}
		return false;
	};

	if(_pInstr->getParentType() == Instruction::ParentType::Module)
	{
		for (const auto& [key, value] : m_Capabilities)
		{
			if (&value == _pInstr)
			{
				m_Capabilities.erase(m_Capabilities.find(key));
				return true;
			}
		}

		for (const auto& [key, value] : m_Extensions)
		{
			if (&value == _pInstr)
			{
				m_Extensions.erase(m_Extensions.find(key));
				return true;
			}
		}

		for (const auto& [key, value] : m_ExtInstrImport)
		{
			if (&value == _pInstr) 
			{
				m_ExtInstrImport.erase(m_ExtInstrImport.find(key));
				return true;
			}
		}

		if (&m_MemoryModel == _pInstr)
		{
			logError("OpMemoryModel can't be removed");
			return false;
		}

		if (erase(m_ExecutionModes)) return true;
		if (erase(m_SourceStrings)) return true;
		if (erase(m_Names)) return true;
		if (erase(m_ModuleProccessed)) return true;
		if (erase(m_Decorations)) return true;
		if (erase(m_TypesAndConstants)) return true;
		if (erase(m_GlobalVariables)) return true;
		if (erase(m_Undefs)) return true;
		if (erase(m_Lines)) return true;

		logError("Failed to remove instruction from module");
		return false;
	}
	else if (_pInstr->getParentType() == Instruction::ParentType::Function && _pInstr->getFunction() != nullptr)
	{
		if (*_pInstr != spv::Op::OpFunctionParameter)
		{
			logError("OpFunction and OpFunctionEnd can't be removed");
			return false;
		}

		// opFunction and opFunctionEnd cant be removed, only opFunctionParameters
		return erase(_pInstr->getFunction()->getParameters());
	}
	else if (_pInstr->getParentType() == Instruction::ParentType::BasicBlock && _pInstr->getBasicBlock() != nullptr)
	{
		if (*_pInstr == spv::Op::OpLabel) 
		{
			logError("OpLabel can't be removed");
			return false;
		}

		return _pInstr->getBasicBlock()->remove(_pInstr);
	}

	logError("Invalid instruction parent");

	return false;
}

void spvgentwo::Module::addRequiredCapabilities(const Grammar& _grammar)
{
	auto check = [&](const Instruction& _instr)
	{
		if (auto* info = _grammar.getInfo(static_cast<unsigned int>(_instr.getOperation())); info != nullptr)
		{
			for (const spv::Capability& c : info->capabilities)
			{
				addCapability(c);
			}
		}
	};

	iterateInstructions(check);
}

void spvgentwo::Module::addRequiredExtensions(const Grammar& _grammar)
{
	auto check = [&](const Instruction& _instr)
	{
		if (auto* info = _grammar.getInfo(static_cast<unsigned int>(_instr.getOperation())); info != nullptr)
		{
			for (const spv::Extension& e : info->extensions)
			{
				addExtension(e);
			}
		}
	};

	iterateInstructions(check);
}

unsigned int spvgentwo::Module::getRequiredVersion(const Grammar& _grammar) const
{
	auto ver = makeVersion(1u, 0u);

	auto check = [&ver, &_grammar](const Instruction& _instr)
	{
		if (auto* info = _grammar.getInfo(static_cast<unsigned int>(_instr.getOperation())); info != nullptr)
		{
			if (info->version > ver) 
			{
				ver = info->version;
			}
		}
	};

	iterateInstructions(check);

	return ver;
}

unsigned int spvgentwo::Module::setRequiredVersion(const Grammar& _grammar)
{
	m_spvVersion = getRequiredVersion(_grammar);
	return m_spvVersion;
}

spvgentwo::Instruction* spvgentwo::Module::getInstructionByName(const char* _pName) const
{
	for (Instruction& instr : m_Names) 
	{
		auto it = instr.getFirstActualOperand();

		if (Instruction* target = it->getInstruction(); target != nullptr)
		{
			if (compareLiteralString(_pName, it.next(), instr.end()))
			{
				return target;
			} 
		}
	}
	return nullptr;
}