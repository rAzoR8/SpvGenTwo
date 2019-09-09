#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule)
{
}

spvgentwo::Function::~Function()
{
	if (m_pBasicBlocks != nullptr)
	{
		m_pBasicBlocks->destroyList();
		m_pBasicBlocks = nullptr;
	}
}

spvgentwo::TBasicBlock* spvgentwo::Function::addBasicBlock()
{
	if (m_pBasicBlocks == nullptr)
	{
		m_pBasicBlocks = TBasicBlock::create(m_pModule->getAllocator(), this);
		return m_pBasicBlocks;
	}

	return m_pBasicBlocks->emplace_back(m_pModule->getAllocator(), this);
}

spvgentwo::IAllocator* spvgentwo::Function::getAllocator()
{
	return m_pModule->getAllocator();
}
