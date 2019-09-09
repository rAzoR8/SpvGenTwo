#include "Module.h"
#include "Function.h"

//using namespace spvgentwo;

spvgentwo::Module::Module(IAllocator* _pAllocator) :
	m_pAllocator(_pAllocator)
{
}

spvgentwo::Module::~Module()
{
	if (m_pFunctions == nullptr)
	{
		m_pFunctions->destroyList();
		m_pFunctions = nullptr;
	}
}

spvgentwo::TFunction* spvgentwo::Module::addFunction()
{
	if (m_pFunctions == nullptr)
	{
		m_pFunctions = TFunction::create(m_pAllocator, this);
		return m_pFunctions;
	}
	return m_pFunctions->emplace_back(m_pAllocator, this);
}
