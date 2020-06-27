#include "spvgentwo/EntryPoint.h"

spvgentwo::EntryPoint::EntryPoint(Module* _pModule) :
	Function(_pModule),
	m_EntryPoint(this),
	m_ExecutionModes(m_pAllocator) // use allocator initialized by parent class
{
}

spvgentwo::EntryPoint::~EntryPoint()
{
}

void spvgentwo::EntryPoint::getGlobalVariableInterface(List<Operand>& _outVarInstr, const GlobalInterfaceVersion _version) const
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

void spvgentwo::EntryPoint::finalizeGlobalInterface(const GlobalInterfaceVersion _version)
{
	if (m_finalized == false)
	{
		getGlobalVariableInterface(m_EntryPoint, _version);
		
		m_finalized = true;
	}
}

spvgentwo::Instruction* spvgentwo::EntryPoint::addExecutionModeInstr()
{
	return &m_ExecutionModes.emplace_back(this);
}

spvgentwo::Instruction* spvgentwo::EntryPoint::finalize(const spv::ExecutionModel _model, const Flag<spv::FunctionControlMask> _control, const char* _pEntryPointName)
{
	Instruction* pFunc = Function::finalize(_control, _pEntryPointName);

	if (pFunc != nullptr)
	{
		m_EntryPoint.opEntryPoint(_model, &m_Function, _pEntryPointName);
	}

	return pFunc;
}