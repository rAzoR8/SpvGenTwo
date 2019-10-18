#include "Function.h"
#include "Module.h"

spvgentwo::Function::Function(Module* _pModule) :
	m_pModule(_pModule), List(_pModule->getAllocator()),
	m_Function(this),
	m_Parameters(_pModule->getAllocator()),
	m_EntryPoint(this),
	m_ExecutionModes(_pModule->getAllocator())
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

void spvgentwo::Function::promoteToEntryPoint(const spv::ExecutionModel _model, const char* _pEntryPointName)
{
	m_ExecutionModel = _model;
	m_pEntryPointName = _pEntryPointName;

	m_EntryPoint.reset();
	m_EntryPoint.opEntryPoint(_model, &m_Function, m_pEntryPointName);

	getGlobalVariableInterface(m_EntryPoint);
}

void spvgentwo::Function::getGlobalVariableInterface(List<Operand>& _outVarInstr) const
{
	struct VisitedBB
	{
		VisitedBB(BasicBlock* _pBB) : pBB(_pBB), visited(false) {}
		BasicBlock* pBB = nullptr;
		bool visited = false;
		bool operator==(const BasicBlock* _pBB) const { return pBB == _pBB; }
	};

	List<VisitedBB> BBs(m_pAllocator);

	// entry points own basic blocks
	for (BasicBlock& bb : *this)
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
						Instruction* pOpFunc = (instr.begin() + 2)->getInstruction();
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
	for(VisitedBB& bb : BBs)
	{
		for(Instruction& instr : *bb.pBB)
		{
			// go through operands that are Instructions which consume OpVariable
			for (Operand& operand : instr) 
			{
				// find valid OpVariable (resultType, resultId, Storage Class)
				Instruction* pArg = operand.getInstruction();
				if (pArg != nullptr && pArg->getOperation() == spv::Op::OpVariable && pArg->getStorageClass() != spv::StorageClass::Function)
				{
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