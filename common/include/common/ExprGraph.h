#pragma once

#include "Graph.h"
#include "Expression.h"
#include "spvgentwo/HashMap.h"

namespace spvgentwo
{
	template <class Func>
	class ExprGraph : public Graph<Expression<Func>>
	{
	public:
		using Graph<Expression<Func>>::Graph;

		using NodeType = typename Graph<Expression<Func>>::NodeType;

		void evaluate(NodeType* _pExitNode);
	};

	template<class Func>
	inline void ExprGraph<Func>::evaluate(NodeType* _pExitNode)
	{
		int count = 0;
		HashMap<NodeType*, int> processedNodes(getAllocator());
		List<NodeType*> stack(getAllocator());

		auto parent = [&](NodeType* _pNode) -> bool
		{
			if (processedNodes.count(_pNode) == 0u)
			{
				processedNodes.emplaceUnique(_pNode, count++);
				return true;
			}
			return false;
		};

		stack.emplace_back(_pExitNode);

		while (stack.empty() == false)
		{
			NodeType* node = stack.pop_back();

			if (parent(node))
			{
				for (auto& in : node->inputs())
				{
					if (parent(in.pTarget))
					{
						stack.emplace_back(in.pTarget);
					}
				}
			}
		}

		while (count > 0)
		{
			for (auto& [node, id] : processedNodes)
			{
				if (id == count-1)
				{
					node->data()(*node);
					--count;
					break; // todo: remove from processed to speed up					
				}
			}
		}
	}
} // !spvgentwo