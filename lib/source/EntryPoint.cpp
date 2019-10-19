#include "EntryPoint.h"
#include "Module.h"

spvgentwo::EntryPoint::EntryPoint(Module* _pModule, const spv::ExecutionModel _model, const char* _pEntryPointName) : Function(_pModule),
	m_EntryPoint(this),
	m_ExecutionModes(_pModule->getAllocator()),
	m_ExecutionModel(_model),
	m_pEntryPointName(_pEntryPointName)
{
	m_EntryPoint.opEntryPoint(_model, getFunction(), m_pEntryPointName);
}

spvgentwo::EntryPoint::~EntryPoint()
{
}

void spvgentwo::EntryPoint::getGlobalVariableInterface(List<Operand>& _outVarInstr) const
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
	for (VisitedBB& bb : BBs)
	{
		for (Instruction& instr : *bb.pBB)
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

bool spvgentwo::EntryPoint::finalizeEP(Instruction* _pReturnType, const Flag<spv::FunctionControlMask> _control)
{
	if (m_finalized == false)
	{
		getGlobalVariableInterface(m_EntryPoint);

		Function::finalize(_pReturnType, _control);
		
		m_finalized = true;
	}

	return m_finalized;
}
