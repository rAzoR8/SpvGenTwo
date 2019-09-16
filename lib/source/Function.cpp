#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(IAllocator* _pAllocator) :
	m_pModule(nullptr), List(_pAllocator),
	m_Function(_pAllocator),
	m_Parameters(_pAllocator),
	m_Type(_pAllocator)
{
}

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule), List(_pModule->getAllocator()),
	m_Function(_pModule->getAllocator()),
	m_Parameters(_pModule->getAllocator()),
	m_Type(_pModule->getAllocator())
{
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

spvgentwo::Type& spvgentwo::Function::createSignature()
{
	return m_Type.Function();
}

bool spvgentwo::Function::finalize(const Flag<spv::FunctionControlMask> _control)
{
	if (m_pModule == nullptr || m_pFunctionType != nullptr)
	{
		return false;
	}

	m_Type.Function();

	// first type is the return type
	const Instruction* pResultType = m_pModule->addType(m_Type.front());

	// function parameters
	for (auto it = ++m_Type.begin(), end = m_Type.end(); it != end; ++it) 
	{
		m_Parameters.emplace_back(m_pAllocator).opFunctionParameter(m_pModule->addType(*it));
	}

	// function signature type
	m_pFunctionType = m_pModule->addType(m_Type);

	m_Function.opFunction(_control, pResultType, m_pFunctionType);

	return true;
}