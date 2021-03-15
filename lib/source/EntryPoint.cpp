#include "spvgentwo/EntryPoint.h"

#include "spvgentwo/InstructionTemplate.inl"

spvgentwo::EntryPoint::EntryPoint(Module* _pModule) :
	Function(_pModule),
	m_EntryPoint(this),
	m_nameStorage(_pModule->getAllocator())
{
}

spvgentwo::EntryPoint::~EntryPoint()
{
}

const char* spvgentwo::EntryPoint::getName() const
{
	return m_nameStorage.c_str();
}

void spvgentwo::EntryPoint::finalizeGlobalInterface(const GlobalInterfaceVersion _version)
{
	if (m_finalized == false)
	{
		collectReferencedVariables(*this, m_EntryPoint, _version, m_pAllocator);
		
		m_finalized = true;
	}
}

spvgentwo::String& spvgentwo::EntryPoint::getNameStorage()
{
	return m_nameStorage;
}

spvgentwo::Instruction* spvgentwo::EntryPoint::finalize(const spv::ExecutionModel _model, const Flag<spv::FunctionControlMask> _control, const char* _pEntryPointName)
{
	Instruction* pFunc = Function::finalize(_control, _pEntryPointName);

	if (pFunc != nullptr && pFunc->isErrorInstr() == false)
	{
		m_EntryPoint.opEntryPoint(_model, &m_Function, _pEntryPointName);
		m_nameStorage = _pEntryPointName;
	}

	return pFunc;
}

spvgentwo::Range<spvgentwo::Instruction::Iterator> spvgentwo::EntryPoint::getInterfaceVariables() const
{
	auto it = skipLiteralString(m_EntryPoint.getFirstActualOperand() + 2u); // skip execution model & entry function id first, then skip over name string

	return { it, m_EntryPoint.end() };
}
