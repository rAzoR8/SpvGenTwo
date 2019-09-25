#include "Module.h"
#include "Function.h"
#include "Type.h"
#include "Writer.h"

spvgentwo::Module::Module(IAllocator* _pAllocator) :
	List(_pAllocator),
	m_Capabilities(_pAllocator),
	m_MemoryModel(_pAllocator),
	m_Extensions(_pAllocator),
	m_ExtInstrImport(_pAllocator),
	m_TypesAndConstants(_pAllocator),
	m_TypeBuilder(_pAllocator),
	m_ConstantBuilder(_pAllocator)
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
	m_Capabilities.emplace_back(m_pAllocator).opCapability(_capability);
}

void spvgentwo::Module::addExtension(const char* _pExtName)
{
	m_Extensions.emplace_back(m_pAllocator).opExtension(_pExtName);
}

spvgentwo::Instruction* spvgentwo::Module::addExtensionInstructionImport(const char* _pExtName)
{
	return m_ExtInstrImport.emplace_back(m_pAllocator).opExtInstrImport(_pExtName);
}

spvgentwo::Instruction* spvgentwo::Module::addConstant(const Constant& _const)
{
	auto& node = m_ConstantBuilder.emplaceUnique(_const, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	Instruction* pType = addType(_const.getType());

	Instruction* pInstr = node.kv.value = &m_TypesAndConstants.emplace_back(m_pAllocator);

	const spv::Op constantOp = _const.getOperation();

	pInstr->makeOp(constantOp, pType, InvalidId);

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

	return pInstr;
}

spvgentwo::Instruction* spvgentwo::Module::addType(const Type& _type)
{
	auto& node = m_TypeBuilder.emplaceUnique(_type, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	Instruction* pInstr = node.kv.value = &m_TypesAndConstants.emplace_back(m_pAllocator);

	const spv::Op base = _type.getBaseType();

	pInstr->makeOp(base);

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
		pInstr->addOperand(addConstant(newConstant().make(_type.getArrayLength()))); // length as constant
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

	return pInstr;
}

spvgentwo::Instruction* spvgentwo::Module::compositeType(const spv::Op _Type, const List<Instruction*>& _subTypes)
{
	// TODO: feed into TypeBuilder (use reverse Instruction* -> Type HashMap?)
	Instruction* pInstr = m_TypesAndConstants.emplace_back(m_pAllocator).makeOp(_Type, InvalidId);
	
	for (Instruction* pSubType : _subTypes)
	{
		pInstr->addOperand(pSubType);
	}

	return pInstr;
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

	// write entry points declarations
	for (Function& fun : *this)
	{
		if (fun.isEntryPoint())
		{
			fun.getEntryPoint()->write(_pWriter, m_maxId);
		}
	}

	// write entrypoint executions modes
	for (Function& fun : *this)
	{
		if (fun.isEntryPoint())
		{
			for(Instruction& mode : fun.getExecutionModes())
			{
				mode.write(_pWriter, m_maxId);
			}
		}
	}
	
	// TODO:
	//7. These debug instructions, which must be grouped in the following order :
	//	a. all OpString, OpSourceExtension, OpSource, and OpSourceContinued, without forward references.
	//	b. all OpNameand all OpMemberName
	//	c.all OpModuleProcessed instructions

	// TODO:
	// all decoration instructions (OpDecorate, OpMemberDecorate, OpGroupDecorate, OpGroupMemberDecorate, and OpDecorationGroup).

	// write types and constants
	writeInstructions(_pWriter, m_TypesAndConstants, m_maxId);
	
	// TODO:
	// all global variable declarations(all OpVariable instructions whose Storage Class is notFunction)

	//  All function declarations (function without body)
	for (Function& fun : *this)
	{
		if (fun.empty())
		{
			fun.write(_pWriter, m_maxId);		
		}
	}

	// write functions with bodies
	for (Function& fun : *this)
	{
		if (fun.empty() == false) 
		{
			fun.write(_pWriter, m_maxId);		
		}
	}

	_pWriter->putAt(m_maxId + 1u, boundsPos);
}
