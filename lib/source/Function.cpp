#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(IAllocator* _pAllocator) :
	m_pModule(nullptr), List(_pAllocator),
	m_Function(_pAllocator),
	m_Parameters(_pAllocator)
{
	//m_Function.opFunction()
}

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule), List(_pModule->getAllocator()),
	m_Function(_pModule->getAllocator()),
	m_Parameters(_pModule->getAllocator())
{
	//m_Function.opFunction()
}

spvgentwo::Function::~Function()
{
}

void spvgentwo::Function::write(IWriter* _pWriter) const
{
	m_Function.write(_pWriter);
	writeInstructions(_pWriter, m_Parameters);

	for (const BasicBlock& bb : *this)
	{
		bb.write(_pWriter);
	}

	Instruction end(m_pAllocator, spv::Op::OpFunctionEnd);
	end.write(_pWriter);
}