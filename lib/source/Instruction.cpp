#include "Instruction.h"
#include "BasicBlock.h"

spvgentwo::Instruction::Instruction(BasicBlock* _pBasicBlock) :
	m_pBasicBlock(_pBasicBlock)
{
}

spvgentwo::Instruction::~Instruction()
{
	if (m_pOperands != nullptr) 
	{
		m_pOperands->destroyList();
		m_pOperands = nullptr;
	}
}

spvgentwo::TOperand* spvgentwo::Instruction::addOperand(const Operand& _operand)
{
	if (m_pOperands == nullptr)
	{
		m_pOperands = TOperand::create(m_pBasicBlock->getAllocator(), _operand);
		return m_pOperands;
	}

	return m_pOperands->emplace_back(m_pBasicBlock->getAllocator(), _operand);
}
