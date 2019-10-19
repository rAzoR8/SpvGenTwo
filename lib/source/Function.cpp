#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule), List(_pModule->getAllocator()),
	m_Function(this),
	m_Parameters(_pModule->getAllocator())
{
}

spvgentwo::Function::~Function()
{
}

spvgentwo::Instruction* spvgentwo::Function::getReturnType()
{
	if (m_pFunctionType != nullptr)
	{
		auto it = ++m_pFunctionType->begin();
		if (it != nullptr)
		{
			return it->getInstruction();
		}
	}
	return nullptr;
}

void spvgentwo::Function::write(IWriter* _pWriter, spv::Id& _resultId)
{
	m_Function.write(_pWriter, _resultId);
	writeInstructions(_pWriter, m_Parameters, _resultId);

	for (BasicBlock& bb : *this)
	{
		bb.write(_pWriter, _resultId);
	}

	Instruction end(getModule(), spv::Op::OpFunctionEnd);
	end.write(_pWriter, _resultId);
}

spvgentwo::Instruction* spvgentwo::Function::addParameter(Instruction* _pType)
{
	return m_Parameters.emplace_back(this).opFunctionParameter(_pType);
}

bool spvgentwo::Function::finalize(Instruction* _pReturnType, const Flag<spv::FunctionControlMask> _control)
{
	if (m_pModule == nullptr || m_pFunctionType != nullptr)
	{
		return false;
	}

	// function signature type
	m_pFunctionType = m_pModule->compositeType(spv::Op::OpTypeFunction, _pReturnType);

	for (Instruction& param : m_Parameters)
	{
		m_pFunctionType->addOperand(param.getTypeInst());
	}

	m_Function.opFunction(_control, _pReturnType, m_pFunctionType);

	return true;
}