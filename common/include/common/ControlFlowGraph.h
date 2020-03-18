#pragma once

#include "Graph.h"
#include "spvgentwo/Function.h"

namespace spvgentwo
{
	// forward decl
	//class BasicBlock;

	template <class E = EmptyEdge>
	class ControlFlowGraph : public Graph<BasicBlock*, E>
	{
	public:
		using Graph<BasicBlock*, E>::Graph;
		using NodeType = typename Graph<BasicBlock*, E>::NodeType;

		ControlFlowGraph(const Function& _func);
	};

	template<class E>
	inline ControlFlowGraph<E>::ControlFlowGraph(const Function& _func) : Graph(_func.getAllocator())
	{
		auto addEdge = [&](NodeType* src, Instruction::Iterator target)
		{
			if (BasicBlock* bb = target->getBranchTarget(); bb != nullptr)
			{
				auto it = m_nodes.find_if([bb](NodeType& n) {return n.data() == bb; });
				NodeType* targetNode = it == m_nodes.end() ? emplace(bb) : it.operator->();
				src->connect(targetNode);
			}
		};

		for (BasicBlock& bb : _func)
		{
			auto it = m_nodes.find_if([&bb](NodeType& n) {return n.data() == &bb; });
			NodeType* node = it == m_nodes.end() ? emplace(&bb) : it.operator->();

			auto term = bb.getTerminator();

			if (term != nullptr)
			{
				for (auto it = term->getFirstActualOperand(); it != term->end(); ++it)
				{
					addEdge(node, it);
				}
			}
		}
	}
} // !spvgentwo