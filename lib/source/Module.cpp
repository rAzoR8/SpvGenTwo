#include "Module.h"
#include "Function.h"

spvgentwo::Module::Module(IAllocator* _pAllocator) :
	List(_pAllocator),
	m_Capabilities(_pAllocator),
	m_MemoryModel(_pAllocator),
	m_Extensions(_pAllocator),
	m_ExtInstrImport(_pAllocator)
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
void spvgentwo::Module::addExtension(const char* _pExtName)
{
	m_Extensions.emplace_back(m_pAllocator).opExtension(_pExtName);
}
spvgentwo::Instruction* spvgentwo::Module::addExtensionInstructionImport(const char* _pExtName)
{
	return m_ExtInstrImport.emplace_back(m_pAllocator).opExtInstrImport(_pExtName);
}
void spvgentwo::Module::setMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	m_MemoryModel.opMemoryModel(_addressModel, _memoryModel);
}