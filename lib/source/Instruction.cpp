#include "Instruction.h"
#include "BasicBlock.h"

spvgentwo::Instruction::Instruction(BasicBlock* _pBasicBlock) :
	m_pBasicBlock(_pBasicBlock), List(_pBasicBlock->getAllocator())
{
}

spvgentwo::Instruction::~Instruction()
{
}