#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(Module* _pModule) : 
	List(_pModule->getAllocator()),
	m_pModule(_pModule),
	m_pReturnType(nullptr),
	m_Function(this),
	m_FunctionEnd(this, spv::Op::OpFunctionEnd),
	m_Parameters(_pModule->getAllocator())
{
}

spvgentwo::Function::Function(Module* _pModule, Function&& _other) noexcept :
	List(stdrep::move(_other)),
	m_pModule(_pModule),
	m_pReturnType(_other.m_pReturnType),
	m_Function(this, stdrep::move(_other.m_Function)),
	m_FunctionEnd(this, spv::Op::OpFunctionEnd), // no need to move
	m_Parameters(stdrep::move(_other.m_Parameters))
{
	for (BasicBlock& bb : *this)
	{
		bb.m_pFunction = this;
	}
}

spvgentwo::Function::~Function()
{
}

spvgentwo::Function& spvgentwo::Function::operator=(Function&& _other) noexcept
{
	if (this == &_other) return *this;

	List::operator=(stdrep::move(_other));

	for (BasicBlock& bb : *this)
	{
		bb.m_pFunction = this;
	}

	//m_pModule = _other.m_pModule;
	m_pReturnType = _other.m_pReturnType;
	m_Function = stdrep::move(_other.m_Function);
	//m_FunctionEnd(this, spv::Op::OpFunctionEnd), // no need to move
	m_Parameters = stdrep::move(_other.m_Parameters);

	return *this;
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

spvgentwo::Instruction* spvgentwo::Function::setReturnType(Instruction* _pReturnType)
{
	if (m_pFunctionType == nullptr)
	{
		m_pFunctionType = m_pModule->compositeType(spv::Op::OpTypeFunction, _pReturnType);
		m_pReturnType = _pReturnType;
	}

	return m_pFunctionType;
}

spvgentwo::Instruction* spvgentwo::Function::finalize(const Flag<spv::FunctionControlMask> _control, const char* _pName)
{
	if (m_pReturnType == nullptr || m_pFunctionType == nullptr)
	{
		return nullptr;
	}

	Instruction* pFunc = m_Function.opFunction(_control, m_pReturnType, m_pFunctionType);

	if (_pName != nullptr)
	{
		m_pModule->addName(pFunc, _pName);
	}

	return pFunc;
}