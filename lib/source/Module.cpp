#include "Module.h"
#include "Function.h"
#include "Type.h"
#include "Writer.h"
#include "Logger.h"

spvgentwo::Module::Module(IAllocator* _pAllocator, ILogger* _pLogger) :
	m_pAllocator(_pAllocator),
	m_pLogger(_pLogger),
	m_Functions(_pAllocator),
	m_EntryPoints(_pAllocator),
	m_Capabilities(_pAllocator),
	m_MemoryModel(this),
	m_Extensions(_pAllocator),
	m_ExtInstrImport(_pAllocator),
	m_SourceStrings(_pAllocator),
	m_Names(_pAllocator),
	m_ModuleProccessed(_pAllocator),
	m_Decorations(_pAllocator),
	m_TypesAndConstants(_pAllocator),
	m_TypeToInstr(_pAllocator),
	m_InstrToType(_pAllocator),
	m_ConstantBuilder(_pAllocator),
	m_GlobalVariables(_pAllocator)
{
}

spvgentwo::Module::~Module()
{
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
	// emplace free instruction (without parent BB)
	m_Capabilities.emplace_back(this).opCapability(_capability);
}

void spvgentwo::Module::addExtension(const char* _pExtName)
{
	m_Extensions.emplace_back(this).opExtension(_pExtName);
}

spvgentwo::Instruction* spvgentwo::Module::addExtensionInstructionImport(const char* _pExtName)
{
	return m_ExtInstrImport.emplace_back(this).opExtInstImport(_pExtName);
}

spvgentwo::Instruction* spvgentwo::Module::addSourceStringInstr()
{
	return &m_SourceStrings.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addNameInstr()
{
	return &m_Names.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addModuleProccessedInstr()
{
	return &m_ModuleProccessed.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addDecorationInstr()
{
	return &m_Decorations.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::Module::addConstant(const Constant& _const)
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

	pInstr->makeOpEx(constantOp, pType, InvalidId);

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

		// TODO: remaining complex types
	case spv::Op::OpConstantSampler:
	case spv::Op::OpSpecConstantOp:
	default:
		break;
	}

	m_TypesAndConstants.append_entry(entry);

	return pInstr;
}

spvgentwo::Instruction* spvgentwo::Module::addType(const Type& _type)
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

	pInstr->makeOpEx(base);

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
		pInstr->appendLiterals(_type.getIntWidth(), unsigned int (_type.getIntSign()));
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
		pInstr->appendLiterals(_type.getImageFormat());
		if(_type.getAccessQualifier() != spv::AccessQualifier::Max)
		{
			pInstr->appendLiterals(_type.getAccessQualifier());
		}
		break;
	default:
		break; // unknown type
	}

	m_TypesAndConstants.append_entry(entry);

	return pInstr;
}

const spvgentwo::Type* spvgentwo::Module::getTypeInfo(const Instruction* _pTypeInstr) const 
{
	if (_pTypeInstr->isType())
	{
		//const Type* const* t = m_InstrToType.get(_pTypeInstr);
		const Type* const* t = m_InstrToType.get(hash(_pTypeInstr));

		if (t != nullptr)
		{
			return *t;
		}
	}
	return nullptr;
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

void spvgentwo::Module::write(IWriter* _pWriter)
{
	m_maxId = 0u;

	// write header
	_pWriter->put(spv::MagicNumber);
	_pWriter->put(spv::Version);
	_pWriter->put(GeneratorId);
	const long boundsPos = _pWriter->put(1024u); // bounds dummy
	_pWriter->put(0u); // schema

	// write preamble
	writeInstructions(_pWriter, m_Capabilities, m_maxId);
	writeInstructions(_pWriter, m_Extensions, m_maxId);
	writeInstructions(_pWriter, m_ExtInstrImport, m_maxId);
	m_MemoryModel.write(_pWriter, m_maxId);

	writeInstructions(_pWriter, m_SourceStrings, m_maxId);
	writeInstructions(_pWriter, m_Names, m_maxId);
	writeInstructions(_pWriter, m_ModuleProccessed, m_maxId);

	writeInstructions(_pWriter, m_Decorations, m_maxId);

	// write entry points declarations
	for (EntryPoint& ep : m_EntryPoints)
	{
		ep.finalize(); // fills out global variable interface
		ep.getEntryPoint()->write(_pWriter, m_maxId);
	}

	// write entrypoint executions modes
	for (EntryPoint& ep : m_EntryPoints)
	{
		for(Instruction& mode : ep.getExecutionModes())
		{
			mode.write(_pWriter, m_maxId);
		}
	}
	
	// write types and constants
	writeInstructions(_pWriter, m_TypesAndConstants, m_maxId);
	
	// all global variable declarations(all OpVariable instructions whose Storage Class is notFunction)
	writeInstructions(_pWriter, m_GlobalVariables, m_maxId); // TODO: check StorageClass

	//  All function declarations (function without body)
	for (Function& fun : m_Functions)
	{
		if (fun.empty())
		{
			fun.write(_pWriter, m_maxId);		
		}
	}

	// write functions with bodies
	for (Function& fun : m_Functions)
	{
		if (fun.empty() == false) 
		{
			fun.write(_pWriter, m_maxId);		
		}
	}
	for (EntryPoint& ep : m_EntryPoints)
	{
		if (ep.empty() == false) // can entry points be empty forward decls?
		{
			ep.write(_pWriter, m_maxId);
		}
	}

	_pWriter->putAt(m_maxId + 1u, boundsPos);
}

spvgentwo::Instruction* spvgentwo::Module::variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, Instruction* _pInitialzer)
{
	return m_GlobalVariables.emplace_back(this).opVariable(_pPtrType, _storageClass, _pInitialzer);
}