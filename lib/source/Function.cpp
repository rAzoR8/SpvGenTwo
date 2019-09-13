#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(IAllocator* _pAllocator) :
	m_pModule(nullptr), List(_pAllocator)
{
}

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule), List(_pModule->getAllocator())
{
}

spvgentwo::Function::~Function()
{
}

spvgentwo::IAllocator* spvgentwo::Function::getAllocator()
{
	return m_pModule->getAllocator();
}
