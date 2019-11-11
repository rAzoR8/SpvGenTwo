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

spvgentwo::Instruction* spvgentwo::Function::variable(Instruction* _pPtrType, const spv::StorageClass _storageClass, Instruction* _pInitialzer)
{
	if (empty())
	{
		getModule()->logInfo("Implicitly added function entry basic block");
		addBasicBlock();
	}

	BasicBlock& funcEntry = **m_pBegin;

	// insert var instruction after first lable
	Instruction* pVar = funcEntry.insert_after(funcEntry.begin(), &funcEntry)->operator->();

	return pVar->opVariable(_pPtrType, _storageClass, _pInitialzer);
}