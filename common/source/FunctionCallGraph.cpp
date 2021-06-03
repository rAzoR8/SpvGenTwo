#include "common/FunctionCallGraph.h"

#include "spvgentwo/Function.h"

spvgentwo::FunctionCallGraph::FunctionCallGraph(const Function& _func, IAllocator* _pAllocator)	:
	Graph<Function*, Instruction*>(_pAllocator != nullptr ? _pAllocator : _func.getAllocator())
{
	add(_func);
}

void spvgentwo::FunctionCallGraph::add(const Function& _func)
{
	Function* srcFunc = _func.getFunction()->getFunction(); // use OpFunction to get non-const Function
	auto srcIt = this->m_nodes.find_if([&srcFunc](NodeType& n) { return n.data() == srcFunc; });
	NodeType* src = srcIt == this->m_nodes.end() ? this->emplace(srcFunc) : srcIt.operator->();

	for (BasicBlock& bb : _func)
	{
		for (Instruction& instr : bb)
		{
			if (instr == spv::Op::OpFunctionCall)
			{
				if (auto it = instr.getFirstActualOperand(); it != nullptr && it->isInstruction())
				{
					Function* dstFunc = it->getInstruction()->getFunction();
					auto dstIt = this->m_nodes.find_if([&dstFunc](NodeType& n) { return n.data() == dstFunc; });

					NodeType* dst = nullptr;
					if (dstIt == this->m_nodes.end())
					{
						dst = this->emplace(dstFunc);
						add(*dstFunc);
					}
					else
					{
						dst = srcIt.operator->();
					}

					src->connect(dst, &instr);
				}
			}
		}
	}
}
