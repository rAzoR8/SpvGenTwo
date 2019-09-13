#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"

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

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOp(spv::Op::OpCapability, _capability);
}