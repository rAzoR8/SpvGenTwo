#include "Function.h"
#include "Module.h"

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
