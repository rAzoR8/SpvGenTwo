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

	//Instruction end(m_pModule, spv::Op::OpFunctionEnd);
	m_FunctionEnd.write(_pWriter, _resultId);
}

spvgentwo::Instruction* spvgentwo::Function::getParameter(unsigned int _index)
{
	auto it = m_Parameters.begin() + _index;
	return it == nullptr ? nullptr : it.operator->();
}

spvgentwo::Instruction* spvgentwo::Function::variable(Instruction* _pPtrType, Instruction* _pInitialzer, const char* _pName)
{
	if (empty())
	{
		getModule()->logInfo("Implicitly added function entry basic block");
		addBasicBlock();
	}

	BasicBlock& funcEntry = **m_pBegin;

	// insert var instruction after first lable
	Instruction* pVar = funcEntry.insert_after(funcEntry.begin(), &funcEntry)->operator->();

	pVar->opVariable(_pPtrType, spv::StorageClass::Function, _pInitialzer);

	if (_pName != nullptr)
	{
		getModule()->addName(pVar, _pName);
	}

	return pVar;
}