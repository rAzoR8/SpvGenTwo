#include "Function.h"
#include "Module.h"

spvgentwo::Function::~Function()
{
}

void spvgentwo::Function::write(IWriter* _pWriter, spv::Id& _resultId)
{
	m_Function.write(_pWriter, _resultId);
	writeInstructions(_pWriter, m_Parameters, _resultId);

	for (BasicBlock& bb : *this)
	{
		bb.write(_pWriter, _resultId);
	}

	Instruction end(m_pModule, spv::Op::OpFunctionEnd);
	end.write(_pWriter, _resultId);
}

spvgentwo::Instruction* spvgentwo::Function::getParameter(unsigned int _index)
{
	auto it = m_Parameters.begin() + _index;
	return it == nullptr ? nullptr : it.operator->();
}