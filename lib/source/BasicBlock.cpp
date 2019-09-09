#include "BasicBlock.h"
#include "Function.h"
#include "Module.h"

spvgentwo::BasicBlock::BasicBlock(Function* _pFunction) :
	m_pFunction(_pFunction), List(_pFunction->getAllocator())
{
}

spvgentwo::BasicBlock::~BasicBlock()
{
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
	return Iterator(m_pLast);
}