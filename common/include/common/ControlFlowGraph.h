#pragma once

#include "Graph.h"
#include "spvgentwo/Function.h"

namespace spvgentwo
{
	template <class E = EmptyEdge>
	class ControlFlowGraph : public Graph<BasicBlock*, E>
	{
	public:
		using Graph<BasicBlock*, E>::Graph;
		using NodeType = typename Graph<BasicBlock*, E>::NodeType;

		ControlFlowGraph(const Function& _func, IAllocator*_pAllocator = nullptr);
	};

	template<class E>
	inline ControlFlowGraph<E>::ControlFlowGraph(const Function& _func, IAllocator* _pAllocator) :
		Graph<BasicBlock*, E>(_pAllocator != nullptr ? _pAllocator : _func.getAllocator())
	{
		auto addEdge = [&](NodeType* src, Instruction::Iterator target)
		{
			BasicBlock* bb = target->getBranchTarget();
			if (Instruction* label = target->getInstruction(); bb == nullptr && label != nullptr && *label == spv::Op::OpLabel)
			{
				bb = label->getBasicBlock();
			}

			if (bb != nullptr)
			{
				auto it = this->m_nodes.find_if([bb](NodeType& n) {return n.data() == bb; });
				NodeType* targetNode = it == this->m_nodes.end() ? this->emplace(bb) : it.operator->();
				src->connect(targetNode);
			}
		};

		for (BasicBlock& bb : _func)
		{
			auto it = this->m_nodes.find_if([&bb](NodeType& n) {return n.data() == &bb; });
			NodeType* node = it == this->m_nodes.end() ? this->emplace(&bb) : it.operator->();

			auto term = bb.getTerminator();

			if (term != nullptr)
			{
				for (auto term_it = term->getFirstActualOperand(); term_it != term->end(); ++term_it)
				{
					addEdge(node, term_it);
				}
			}
		}
	}
} // !spvgentwo