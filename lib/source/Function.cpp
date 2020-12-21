#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Reader.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

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

bool spvgentwo::Function::read(IReader* _pReader, const Grammar& _grammar, Instruction&& _opFunc)
{
	// module already consumed OpFunction
	m_Function = stdrep::move(_opFunc);

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

spvgentwo::List<spvgentwo::Instruction*> spvgentwo::Function::remove(const BasicBlock* _pBB, BasicBlock* _pReplacement)
{
	List<Instruction*> uses(getAllocator());

	if(_pBB == nullptr)
	{
		return uses;
	}

	Module* module = getModule();

	const Instruction* opLabel = _pBB->getLabel();

	bool found = false;
	for (auto it = begin(); it != end(); ++it) 
	{
		if (it.operator->() == _pBB)
		{
			erase(it);
			found = true;
			break;
		}
	}

	if (found == false)
	{
		module->logError("BasicBlock not found in function");
		return uses;
	}

	auto gatherUse = [opLabel, _pBB, _pReplacement, &uses](Instruction& instr)
	{
		for (auto it = instr.getFirstActualOperand(), end = instr.end(); it != end; ++it)
		{
			if (*it == _pBB || *it == opLabel)
			{
				uses.emplace_back(&instr);
				*it = _pReplacement;
			}
		}
	};

	module->iterateInstructions(gatherUse);

	return uses;
}

spvgentwo::Instruction* spvgentwo::Function::getParameter(unsigned int _index)
{
	auto it = m_Parameters.begin() + _index;
	return it == nullptr ? nullptr : it.operator->();
}

spvgentwo::Instruction* spvgentwo::Function::variable(Instruction* _pPtrType, const char* _pName, Instruction* _pInitialzer)
{
	if (empty())
	{
		getModule()->logInfo("Implicitly added function entry basic block");
		addBasicBlock("FunctionEntry");
	}

	BasicBlock& funcEntry = **m_pBegin;

	// insert var instruction after label
	Instruction* pVar = funcEntry.emplace_front(&funcEntry).opVariable(_pPtrType, spv::StorageClass::Function, _pInitialzer);

	if (_pName != nullptr)
	{
		getModule()->addName(pVar, _pName);
	}

	return pVar;
}

spvgentwo::Instruction* spvgentwo::Function::variable(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer)
{
	Instruction* type = _ptrType.isPointer() ? getModule()->addType(_ptrType) : getModule()->addType(_ptrType.wrapPointer(spv::StorageClass::Function));

	return variable(type, _pName, _pInitialzer);
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