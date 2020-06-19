#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Reader.h"

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

void spvgentwo::Function::write(IWriter* _pWriter)
{
	m_Function.write(_pWriter);

	for (Instruction& instr : m_Parameters)
	{
		instr.write(_pWriter);
	}

	for (BasicBlock& bb : *this)
	{
		bb.write(_pWriter);
	}

	m_FunctionEnd.write(_pWriter);
}

bool spvgentwo::Function::read(IReader* _pReader, const Grammar& _grammar)
{
	// module already consumed first word of OpFunction, OpFunction has 4 Operands
	if (m_Function.readOperands(_pReader, _grammar, spv::Op::OpFunction, 4u) == false) return false;

	unsigned int word{ 0 };

	while (_pReader->get(word))
	{
		const spv::Op op = getOperation(word);
		const unsigned int operands = getOperandCount(word) - 1u;

		switch (op)
		{
		case spv::Op::OpFunctionParameter:
			if (m_Parameters.emplace_back(this).readOperands(_pReader, _grammar, op, operands) == false) return false;
			break;
		case spv::Op::OpLabel:
			if (addBasicBlock().read(_pReader, _grammar) == false) return false;
			break;
		case spv::Op::OpFunctionEnd:
			return true; // FunctionEnd as no operands
		default:
			return false; // unexpected op code
		}
	}

	return false;
}

const char* spvgentwo::Function::getName() const
{
	return m_pModule->getName(&m_Function);
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
		addBasicBlock("FunctionEntry");
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
		getModule()->logError("Invalid ReturnType or FunctionType");
		return &m_Function;
	}

	Instruction* pFunc = m_Function.opFunction(_control, m_pReturnType, m_pFunctionType);

	if (_pName != nullptr)
	{
		m_pModule->addName(pFunc, _pName);
	}

	return pFunc;
}