#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Writer.h"

spvgentwo::Instruction::Instruction(IAllocator* _pAllocator) :
	m_pBasicBlock(nullptr), List(_pAllocator)
{
}

spvgentwo::Instruction::Instruction(BasicBlock* _pBasicBlock) :
	m_pBasicBlock(_pBasicBlock), List(_pBasicBlock->getAllocator())
{
}

spvgentwo::Instruction::~Instruction()
{
	if (m_pType != nullptr && m_bSharedType == false)
	{
		m_pAllocator->destruct(m_pType);
		m_pType = nullptr;
	}
}

void spvgentwo::Instruction::setSharedType(Type* _pType)
{
	if (m_pType == nullptr)
	{
		m_pType = _pType;
		m_bSharedType = true;
	}
}

spvgentwo::Type* spvgentwo::Instruction::createType()
{
	if (m_pType == nullptr)
	{
		m_pType = m_pAllocator->construct<Type>(m_pAllocator);
		m_bSharedType = false;
		return m_pType;
	}

	// only return a valid type owned by this instance
	return nullptr;
}

unsigned int spvgentwo::Instruction::getWordCount() const
{
	// TODO: check with spv::HasResultAndType if m_pType and m_ResultId have been set correctly
	return 1u + (m_pType != nullptr ? 1u : 0) + (m_ResultId != InvalidId ? 1u : 0u) + static_cast<unsigned int>(m_Elements); // (m_elements is number of operands)
}

unsigned int spvgentwo::Instruction::getOpCode() const
{
	return (unsigned int (m_Operation) & spv::OpCodeMask) | (getWordCount() << spv::WordCountShift);
}

void spvgentwo::Instruction::write(IWriter* _pWriter) const
{
	_pWriter->put(getOpCode());

	if (m_pType != nullptr)
	{
		// TODO: put result id
	}

	if (m_ResultId != InvalidId)
	{
		_pWriter->put(m_ResultId);
	}
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
}

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOp(spv::Op::OpCapability, _capability);
}

void spvgentwo::Instruction::opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	makeOp(spv::Op::OpMemoryModel, _addressModel, _memoryModel);
}

void spvgentwo::Instruction::opExtension(const char* _pExtName)
{
	makeOp(spv::Op::OpExtension, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstrImport(const char* _pExtName)
{
	makeOp(spv::Op::OpExtInstImport, _pExtName);
	return this;
}