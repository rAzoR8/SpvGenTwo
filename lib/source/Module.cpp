#include "Module.h"
#include "Function.h"

spvgentwo::Module::Module(IAllocator* _pAllocator) :
	List(_pAllocator), m_Capabilities(_pAllocator)
{
}

spvgentwo::Module::~Module()
{
}

void spvgentwo::Module::addCapability(const spv::Capability _capability)
{
	// emplace free instruction (without parent BB)
	m_Capabilities.emplace_back(m_pAllocator).opCapability(_capability);
}
