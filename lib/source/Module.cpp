#include "spvgentwo/Module.h"
#include "spvgentwo/Writer.h"
#include "spvgentwo/Logger.h"

spvgentwo::Module::Module(IAllocator* _pAllocator, const unsigned int _spvVersion, ILogger* _pLogger, ITypeInferenceAndVailation* _pTypeInferenceAndVailation) :
	Module(_pAllocator, _spvVersion, spv::AddressingModel::Logical, spv::MemoryModel::Simple, _pLogger, _pTypeInferenceAndVailation) // use delegate constructor
{
}

spvgentwo::Module::Module(IAllocator* _pAllocator, const unsigned int _spvVersion, const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel, ILogger* _pLogger, ITypeInferenceAndVailation* _pTypeInferenceAndVailation) :
	m_pAllocator(_pAllocator),
	m_pLogger(_pLogger),
	m_pTypeInferenceAndVailation(_pTypeInferenceAndVailation),
	m_spvVersion(_spvVersion),
	m_Functions(_pAllocator),
	m_EntryPoints(_pAllocator),
	m_Capabilities(_pAllocator),
	m_Extensions(_pAllocator),
	m_ExtInstrImport(_pAllocator),
	m_MemoryModel(this),
	m_SourceStrings(_pAllocator),
	m_Names(_pAllocator),
	m_ModuleProccessed(_pAllocator),
	m_Decorations(_pAllocator),
	m_TypesAndConstants(_pAllocator),
	m_TypeToInstr(_pAllocator),
	m_InstrToType(_pAllocator),
	m_NameLookup(_pAllocator),
	m_ConstantBuilder(_pAllocator),
	m_GlobalVariables(_pAllocator),
	m_errorInstr(this)
{
	setMemoryModel(_addressModel, _memoryModel);
}

spvgentwo::Module::Module(Module&& _other) noexcept:
	m_pAllocator(_other.m_pAllocator),
	m_pLogger(_other.m_pLogger),
	m_pTypeInferenceAndVailation(_other.m_pTypeInferenceAndVailation),
	m_spvVersion(_other.m_spvVersion),
	m_Functions(stdrep::move(_other.m_Functions)),
	m_EntryPoints(stdrep::move(_other.m_EntryPoints)),
	m_Capabilities(stdrep::move(_other.m_Capabilities)),
	m_Extensions(stdrep::move(_other.m_Extensions)),
	m_ExtInstrImport(stdrep::move(_other.m_ExtInstrImport)),
	m_MemoryModel(this, stdrep::move(_other.m_MemoryModel)),
	m_SourceStrings(stdrep::move(_other.m_SourceStrings)),
	m_Names(stdrep::move(_other.m_Names)),
	m_ModuleProccessed(stdrep::move(_other.m_ModuleProccessed)),
	m_Decorations(stdrep::move(_other.m_Decorations)),
	m_TypesAndConstants(stdrep::move(_other.m_TypesAndConstants)),
	m_TypeToInstr(stdrep::move(_other.m_TypeToInstr)),
	m_InstrToType(stdrep::move(_other.m_InstrToType)),
	m_NameLookup(stdrep::move(_other.m_NameLookup)),
	m_ConstantBuilder(stdrep::move(_other.m_ConstantBuilder)),
	m_GlobalVariables(stdrep::move(_other.m_GlobalVariables)),
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
	m_Functions = stdrep::move(_other.m_Functions);
	m_EntryPoints = stdrep::move(_other.m_EntryPoints);
	m_Capabilities = stdrep::move(_other.m_Capabilities);
	m_Extensions = stdrep::move(_other.m_Extensions);
	m_ExtInstrImport = stdrep::move(_other.m_ExtInstrImport);
	m_MemoryModel = stdrep::move(m_MemoryModel);
	m_SourceStrings = stdrep::move(_other.m_SourceStrings);
	m_Names = stdrep::move(_other.m_Names);
	m_ModuleProccessed = stdrep::move(_other.m_ModuleProccessed);
	m_Decorations = stdrep::move(_other.m_Decorations);
	m_TypesAndConstants = stdrep::move(_other.m_TypesAndConstants);
	m_TypeToInstr = stdrep::move(_other.m_TypeToInstr);
	m_InstrToType = stdrep::move(_other.m_InstrToType);
	m_ConstantBuilder = stdrep::move(_other.m_ConstantBuilder);
	m_GlobalVariables = stdrep::move(_other.m_GlobalVariables);

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

	fixList(m_Capabilities);
	fixList(m_Extensions);

	for (auto& [ext, instr] : m_ExtInstrImport)
	{
		instr.m_parent.pModule = this;
	}

	fixList(m_SourceStrings);
	fixList(m_Names);
	fixList(m_ModuleProccessed);
	fixList(m_Decorations);
	fixList(m_TypesAndConstants);
	fixList(m_GlobalVariables);
}

spvgentwo::Module::~Module()
{
}

void spvgentwo::Module::reset()
{
	m_Functions.clear();
	m_EntryPoints.clear();

	m_Capabilities.clear();
	m_Extensions.clear();
	m_ExtInstrImport.clear();

	setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::Simple);

	m_SourceStrings.clear();
	m_Names.clear();
	m_ModuleProccessed.clear();
	m_Decorations.clear();

	m_TypesAndConstants.clear();

	m_TypeToInstr.clear();
	m_InstrToType.clear();
	m_NameLookup.clear();

	m_ConstantBuilder.clear();
	m_GlobalVariables.clear();
}

spvgentwo::Function& spvgentwo::Module::addFunction()
{
	return m_Functions.emplace_back(this);
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

void spvgentwo::Module::addCapability(const spv::Capability _capability)
{
	m_Capabilities.emplace_back(this).opCapability(_capability);
}

bool spvgentwo::Module::checkCapability(const spv::Capability _capability) const
{
	for (const Instruction& cap : m_Capabilities)
	{
		if (cap.front() == literal_t{ _capability })
		{
			return true;
		}
	}

	return false;
}

void spvgentwo::Module::checkAddCapability(const spv::Capability _capability)
{
	if (checkCapability(_capability) == false)
	{
		addCapability(_capability);

		logInfo("Implictly adding capablity");
	}
}

void spvgentwo::Module::addExtension(const char* _pExtName)
{
	m_Extensions.emplace_back(this).opExtension(_pExtName);
}

spvgentwo::Instruction* spvgentwo::Module::getExtensionInstructionImport(const char* _pExtName)
{
	Instruction& opExtInst = m_ExtInstrImport.emplaceUnique(_pExtName, this).kv.value;
	if (opExtInst.empty())
	{
		opExtInst.opExtInstImport(_pExtName);
	}

	return &opExtInst;
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
	m_NameLookup.emplaceUnique(_pTarget, m_pAllocator).kv.value = _pName;
}

void spvgentwo::Module::addMemberName(Instruction* _pMember, const char* _pMemberName, unsigned int _memberIndex)
{
	addNameInstr()->opMemberName(_pMember, _memberIndex, _pMemberName);
	m_NameLookup.emplaceUnique(_pMember, m_pAllocator).kv.value = _pMemberName;
}

const char* spvgentwo::Module::getName(const Instruction* _pTarget) const
{
	const String* pStr = m_NameLookup.get(_pTarget);
	return pStr != nullptr ? pStr->c_str() : "";
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
	auto& node = m_ConstantBuilder.emplaceUnique(_const, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	Instruction* pType = addType(_const.getType());

	auto entry = Entry<Instruction>::create(m_pAllocator, this);

	Instruction* pInstr = node.kv.value = entry->operator->();

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
		break; // nothing to do
	case spv::Op::OpTypeInt:
		pInstr->appendLiterals(_type.getIntWidth(), (unsigned int) _type.getIntSign());
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
		logFatal("Type not implemented");
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

const spvgentwo::Type* spvgentwo::Module::getTypeInfo(const Instruction* _pTypeInstr) const 
{
	if (_pTypeInstr->isType())
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
		m_ConstantBuilder.emplaceUnique(*_pConstant, instr);
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

spv::Id spvgentwo::Module::assignIDs()
{
	spv::Id maxId = 0;

	iterateInstructions([&maxId](Instruction& instr)
	{
		instr.resolveId(maxId);
	});

	return maxId;
}

void spvgentwo::Module::write(IWriter* _pWriter)
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

	const spv::Id maxId = assignIDs();

	// write header
	_pWriter->put(spv::MagicNumber);
	_pWriter->put(m_spvVersion);
	_pWriter->put(GeneratorId);
	_pWriter->put(maxId+1u); 
	_pWriter->put(0u); // schema

	auto writeInstr = [_pWriter](Instruction& instr)
	{
		instr.write(_pWriter);
	};

	iterateInstructions(writeInstr);
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