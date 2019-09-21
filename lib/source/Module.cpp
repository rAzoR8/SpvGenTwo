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
const spvgentwo::Instruction* spvgentwo::Module::addConstant(const Constant& _const)
{
	const Instruction* pType = addType(_const.getType());

	auto& node = m_ConstantBuilder.emplaceUnique(_const, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

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

const spvgentwo::Instruction* spvgentwo::Module::addType(const Type& _type)
{
	auto& node = m_TypeBuilder.emplaceUnique(_type, nullptr);
	if (node.kv.value != nullptr)
	{
		return node.kv.value;
	}

	Instruction* pInstr = node.kv.value = &m_TypesAndConstants.emplace_back(m_pAllocator);

	const spv::Op base = _type.getBaseType();

	pInstr->makeOp(base, InvalidId);

	switch (base)
	{
	case spv::Op::OpTypeVoid:
	case spv::Op::OpTypeBool:
	case spv::Op::OpTypeSampler:
		break; // nothing to do
	case spv::Op::OpTypeInt:
		pInstr->appendLiterals(_type.getDimension(), unsigned int (_type.getSign()));
		break;
	case spv::Op::OpTypeFloat:
		pInstr->appendLiterals(_type.getDimension());
		break;
	case spv::Op::OpTypeVector:
	case spv::Op::OpTypeMatrix:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // element / row type
		pInstr->appendLiterals(_type.getDimension()); // element / row count
		break;
	case spv::Op::OpTypeStruct:
		for (const Type& member : _type.getSubTypes())
		{
			pInstr->addOperand(addType(member)); // member type
		}
		break;
	case spv::Op::OpTypeArray:
		pInstr->addOperand(addType(_type.getSubTypes().front())); // element type
		pInstr->addOperand(addConstant(newConstant().make(_type.getDimension()))); // length as constant
		break;
	default:
		break; // unknown type
	}

	return pInstr;
}
void spvgentwo::Module::setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	m_MemoryModel.opMemoryModel(_addressModel, _memoryModel);
}

void spvgentwo::Module::write(IWriter* _pWriter) const
{
	// TODO: resolve step (maybe outside of this function)

	// write header
	_pWriter->put(spv::MagicNumber);
	_pWriter->put(spv::Version);
	_pWriter->put(GeneratorId);
	_pWriter->put(m_maxId + 1u); // bounds
	_pWriter->put(0u); // schema

	// write preamble
	writeInstructions(_pWriter, m_Capabilities);
	writeInstructions(_pWriter, m_Extensions);
	writeInstructions(_pWriter, m_ExtInstrImport);
	m_MemoryModel.write(_pWriter);

	// write entry points
	for (const Function& fun : *this)
	{
		if (fun.isEntryPoint())
		{
			fun.getEntryPoint()->write(_pWriter);
		}
	}

	// write entrypoint executions modes
	for (const Function& fun : *this)
	{
		if (fun.isEntryPoint())
		{
			for(const Instruction& mode : fun.getExecutionModes())
			{
				mode.write(_pWriter);
			}
		}
	}

	//All execution - mode declarations, using OpExecutionMode or OpExecutionModeId.
	
	//7. These debug instructions, which must be grouped in the following order :
	//	a. all OpString, OpSourceExtension, OpSource, and OpSourceContinued, without forward references.
	//	b. all OpNameand all OpMemberName
	//	c.all OpModuleProcessed instructions

	// all decoration instructions (OpDecorate, OpMemberDecorate, OpGroupDecorate, OpGroupMemberDecorate, and OpDecorationGroup).

	//  All function declarations (function without body)

	// write functions
	for (const Function& fun : *this)
	{
		fun.write(_pWriter);
	}
}