#include "spvgentwo/Function.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Reader.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

spvgentwo::Function::Function(Module* _pModule) : 
	List(_pModule->getAllocator()),
	m_pModule(_pModule),
	m_Function(this, spv::Op::OpNop), // not finalized
	m_FunctionEnd(this, spv::Op::OpFunctionEnd),
	m_FunctionType(_pModule->getAllocator(), spv::Op::OpTypeFunction),
	m_Parameters(_pModule->getAllocator())
{
	m_FunctionType.VoidM(); // return type defaults to void
}

spvgentwo::Function::Function(Module* _pModule, Function&& _other) noexcept :
	List(stdrep::move(_other)),
	m_pModule(_pModule),
	m_Function(this, stdrep::move(_other.m_Function)),
	m_FunctionEnd(this, spv::Op::OpFunctionEnd), // no need to move
	m_FunctionType(stdrep::move(_other.m_FunctionType)),
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

	m_Function = stdrep::move(_other.m_Function);
	//m_FunctionEnd(this, spv::Op::OpFunctionEnd), // no need to move
	m_FunctionType = stdrep::move(_other.m_FunctionType);
	m_Parameters = stdrep::move(_other.m_Parameters);

	return *this;
}

void spvgentwo::Function::write(IWriter& _writer) const
{
	m_Function.write(_writer);

	for (const Instruction& instr : m_Parameters)
	{
		instr.write(_writer);
	}

	for (const BasicBlock& bb : *this)
	{
		bb.write(_writer);
	}

	m_FunctionEnd.write(_writer);
}

bool spvgentwo::Function::read(IReader& _reader, const Grammar& _grammar, Instruction&& _opFunc)
{
	// module already consumed OpFunction
	m_Function = stdrep::move(_opFunc);

	unsigned int word{ 0 };

	while (_reader.get(word))
	{
		const spv::Op op = getOperation(word);
		const unsigned int operands = getOperandCount(word) - 1u;

		switch (op)
		{
		case spv::Op::OpFunctionParameter:
			if (m_Parameters.emplace_back(this, spv::Op::OpNop).readOperands(_reader, _grammar, op, operands) == false) return false;
			break;
		case spv::Op::OpLabel:
			if (addBasicBlock().read(_reader, _grammar) == false) return false;
			break;
		case spv::Op::OpFunctionEnd:
			return true; // FunctionEnd has no operands
		default:
			m_pModule->logError("Unexpected op-code for function");
			return false; // unexpected op code
		}
	}

	m_pModule->logError("Unexpected module end for function");
	return false;
}

spvgentwo::Instruction* spvgentwo::Function::getReturnTypeInstr() const
{
	if (m_FunctionType.getSubTypes().empty() == false)
	{
		return m_pModule->addType(m_FunctionType.front());
	}
	return m_pModule->getErrorInstr();
}

spvgentwo::Instruction* spvgentwo::Function::getFunctionTypeInstr() const
{
	if (m_FunctionType.getSubTypes().empty() == false)
	{
		return m_pModule->addType(m_FunctionType);
	}
	return m_pModule->getErrorInstr();
}

const char* spvgentwo::Function::getName() const
{
	return m_pModule->getName(&m_Function);
}

spvgentwo::List<spvgentwo::Instruction*> spvgentwo::Function::remove(const BasicBlock* _pBB, BasicBlock* _pReplacement, IAllocator* _pAllocator)
{
	List<Instruction*> uses(_pAllocator != nullptr ? _pAllocator : getAllocator());

	if(_pBB == nullptr)
	{
		return uses;
	}

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
		m_pModule->logError("BasicBlock not found in function");
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

	m_pModule->iterateInstructions(gatherUse);

	return uses;
}

spvgentwo::Instruction* spvgentwo::Function::getParameter(unsigned int _index) const
{
	auto it = m_Parameters.begin() + _index;
	return it == nullptr ? nullptr : it.operator->();
}

spvgentwo::Instruction* spvgentwo::Function::variable(Instruction* _pPtrType, const char* _pName, Instruction* _pInitialzer)
{
	if (empty())
	{
		m_pModule->logInfo("Implicitly added function entry basic block");
		addBasicBlock("FunctionEntry");
	}

	BasicBlock& funcEntry = **m_pBegin;

	// insert var instruction after label
	Instruction* pVar = funcEntry.emplace_front(&funcEntry, spv::Op::OpNop).opVariable(_pPtrType, spv::StorageClass::Function, _pInitialzer);

	if (_pName != nullptr)
	{
		m_pModule->addName(pVar, _pName);
	}

	return pVar;
}

spvgentwo::Instruction* spvgentwo::Function::variable(const Type& _ptrType, const char* _pName, Instruction* _pInitialzer)
{
	Instruction* type = _ptrType.isPointer() ? m_pModule->addType(_ptrType) : m_pModule->addType(_ptrType.wrapPointer(spv::StorageClass::Function));

	return variable(type, _pName, _pInitialzer);
}

bool spvgentwo::Function::setReturnType(Instruction* _pReturnType)
{
	if (const Type* type = _pReturnType->getType(); type != nullptr)
	{
		return setReturnType(*type);
	}
	else
	{
		m_pModule->logInfo("_pReturnType has not type");
		return false;
	}
}

bool spvgentwo::Function::setReturnType(const Type& _returnType)
{
	auto& types = m_FunctionType.getSubTypes();
	if (types.empty())
	{
		m_pModule->logInfo("Result type of functions was not initialized");
		return false;
	}
	else
	{
		// Todo: check _returnType:
		// Return Type is the type of the return value of functions of this type. It must be a concrete or abstract type, or a pointer
		// to such a type.If the function has no return value, Return Type must be OpTypeVoid.

		types.front() = _returnType;
		return true;
	}
}

bool spvgentwo::Function::setFunctionType(Instruction* _pFunctionType)
{
	if (_pFunctionType->getOperation() != spv::Op::OpTypeFunction)
	{
		m_pModule->logError("_pFunctionType is not OpTypeFunction");
		return false;
	}

	if (const Type* type = _pFunctionType->getType(); type != nullptr)
	{
		return setFunctionType( *type );
	}
	else
	{
		m_pModule->logInfo("_pFunctionType has no type");
		return false;
	}
}

bool spvgentwo::Function::setFunctionType(const Type& _functionType)
{
	if (_functionType != spv::Op::OpTypeFunction)
	{
		m_pModule->logError("_functionType is not OpTypeFunction");
		return false;
	}
	m_FunctionType = _functionType;

	return true;
}

spvgentwo::Instruction* spvgentwo::Function::finalize(const Flag<spv::FunctionControlMask> _control, const char* _pName)
{
	if (m_FunctionType.getSubTypes().empty())
	{
		m_pModule->logError("Invalid ReturnType or FunctionType");
		return &m_Function;
	}

	Instruction* pFunc = m_Function.opFunction(_control, getReturnTypeInstr(), getFunctionTypeInstr());

	if (_pName != nullptr && pFunc->isErrorInstr() == false)
	{
		m_pModule->addName(pFunc, _pName);
	}

	return pFunc;
}

bool spvgentwo::Function::isFinalized() const
{
	return (m_FunctionType.getSubTypes().size() == m_Parameters.size() + 1u) && m_Function == spv::Op::OpFunction;
}

spvgentwo::Flag<spvgentwo::spv::FunctionControlMask> spvgentwo::Function::getFunctionControl() const
{
	if (auto it = m_Function.getFirstActualOperand(); it != nullptr && it->isLiteral())
	{
		return Flag<spv::FunctionControlMask>{ it->literal.value };
	}

	return Flag<spv::FunctionControlMask>();
}

void spvgentwo::collectReferencedVariables(const Function& _func, List<Operand>& _outVarInstr, const GlobalInterfaceVersion _version, IAllocator* _pAllocator)
{
	struct VisitedBB
	{
		explicit VisitedBB(BasicBlock* _pBB) : pBB(_pBB), visited(false) {}
		BasicBlock* pBB = nullptr;
		bool visited = false;
		bool operator==(const BasicBlock* _pBB) const { return pBB == _pBB; }
	};

	List<VisitedBB> BBs(_pAllocator);

	// entry points own basic blocks
	for (BasicBlock& bb : _func)
	{
		BBs.emplace_back(&bb);
	}

	// go through all basicblocks (including called functions)
	auto size = 0ull;
	do
	{
		size = BBs.size();

		for (VisitedBB& bb : BBs)
		{
			if (bb.visited == false)
			{
				bb.visited = true;

				// find calls to other functions and add those functions basic blocks
				for (Instruction& instr : *bb.pBB)
				{
					if (instr.getOperation() == spv::Op::OpFunctionCall)
					{
						// 3rd arg of opFunctionCall is OpFunction whos parent Function class holds the BBs were looking for
						Instruction* pOpFunc = (instr.begin() + 2u)->getInstruction();
						Function* pFunction = pOpFunc->getFunction();

						// add unvisited function BBs
						for (BasicBlock& funcBB : *pFunction)
						{
							if (BBs.contains(&funcBB) == false) // skip recursive calls
							{
								BBs.emplace_back(&funcBB);
							}
						}
					}
				}
			}
		}
	} while (size < BBs.size());

	// go through the instructions of the collected basic blocks and look for use of op variable operands
	for (VisitedBB& bb : BBs)
	{
		for (Instruction& instr : *bb.pBB)
		{
			// go through operands that are Instructions which consume OpVariable
			for (Operand& operand : instr)
			{
				// find valid OpVariable (resultType, resultId, Storage Class)
				Instruction* pArg = operand.getInstruction();
				if (pArg != nullptr && pArg->getOperation() == spv::Op::OpVariable)
				{
					const spv::StorageClass storage = pArg->getStorageClass();
					if (_version == GlobalInterfaceVersion::SpirV1_3 && storage != spv::StorageClass::Input && storage != spv::StorageClass::Output)
					{
						continue;
					}
					else if (_version == GlobalInterfaceVersion::SpirV14_x && storage == spv::StorageClass::Function)
					{
						continue;
					}

					// uniquely add the instruction to the interface list
					if (_outVarInstr.contains(pArg) == false)
					{
						_outVarInstr.emplace_back(pArg);
					}
					break;
				}
			}
		}
	}
}
