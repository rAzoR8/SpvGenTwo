#include "BasicBlock.h"
#include "Function.h"
#include "Module.h"

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction) :
	m_pFunction(_pFunction)
{
}

spvgentwo::BasicBlock::~BasicBlock()
{
	if (m_pInstructions != nullptr) 
	{
		m_pInstructions->destroyList();
		m_pInstructions = nullptr;
	}
}

spvgentwo::Module* spvgentwo::BasicBlock::getModule()
{
	return m_pFunction->getModule();
}

spvgentwo::IAllocator* spvgentwo::BasicBlock::getAllocator()
{
	return getModule()->getAllocator();;
}

spvgentwo::BasicBlock::Iterator spvgentwo::BasicBlock::getTerminator()
{
	return Iterator(m_pInstructions == nullptr ? nullptr : m_pInstructions->last());
}

spvgentwo::TInstruction* spvgentwo::BasicBlock::addInstruction()
{
	if (m_pInstructions == nullptr)
	{
		m_pInstructions = TInstruction::create(getAllocator(), this);
		return m_pInstructions;
	}
	return m_pInstructions->emplace_back(getAllocator(), this);
}
