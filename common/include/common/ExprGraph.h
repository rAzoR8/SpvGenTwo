#pragma once

#include "Graph.h"
#include "Expression.h"
//#include "spvgentwo/HashMap.h"
#include "Algorithms.h"

namespace spvgentwo
{
	enum class ExprArgs
	{
		EdgeLists,
		FunctionPtrLists
	};

	template <class Func>
	class ExprGraph : public Graph<Expression<Func>>
	{
	public:
		using Graph<Expression<Func>>::Graph;

		using NodeType = typename Graph<Expression<Func>>::NodeType;

		template <ExprArgs args> // unfold => call expr with List<Func*> ins, List<Func*> outs, or if unfold == false => List<NodeType>& ins, List<NodeType>& outs
		static void evaluateRecursive(NodeType* _pExitNode);

		//void evaluate(NodeType* _pExitNode);
	};

	template<class Func>
	template <ExprArgs args>
	inline void ExprGraph<Func>::evaluateRecursive(NodeType* _pExitNode)
	{
		for (auto& edge : _pExitNode->inputs())
		{
			NodeType* in = edge.pTarget;
			auto& expr = in->data();
			if (!expr)
			{
				evaluateRecursive<args>(in);
			}
		}

		auto& expr = _pExitNode->data();

		if (!expr)
		{
			if constexpr (args == ExprArgs::FunctionPtrLists)
			{
				auto inputs = transform(_pExitNode->inputs(), [](auto& edge) -> Func* {return &edge.pTarget->data().get(); });
				auto outputs = transform(_pExitNode->outputs(), [](auto& edge) -> Func* {return &edge.pTarget->data().get(); });
				expr(inputs, outputs);
			}
			else
			{
				expr(_pExitNode->inputs(), _pExitNode->output());			
			}
		}
	}

	//template<class Func>
	//inline void ExprGraph<Func>::evaluate(NodeType* _pExitNode)
	//{
	//	int count = 0;
	//	HashMap<NodeType*, int> processedNodes(getAllocator());
	//	List<NodeType*> stack(getAllocator());

	//	auto parent = [&](NodeType* _pNode) -> bool
	//	{
	//		if (processedNodes.count(_pNode) == 0u)
	//		{
	//			processedNodes.emplaceUnique(_pNode, count++);
	//			return true;
	//		}
	//		return false;
	//	};

	//	stack.emplace_back(_pExitNode);

	//	while (stack.empty() == false)
	//	{
	//		NodeType* node = stack.pop_front();

	//		if (parent(node))
	//		{
	//			for (auto& in : node->inputs())
	//			{
	//				if (parent(in.pTarget))
	//				{
	//					stack.emplace_back(in.pTarget);
	//				}
	//			}
	//		}
	//	}

	//	while (count > 0)
	//	{
	//		for (auto& [node, id] : processedNodes)
	//		{
	//			if (id == count-1)
	//			{
	//				node->data()(*node);
	//				--count;
	//				break; // todo: remove from processed to speed up					
	//			}
	//		}
	//	}
	//}
} // !spvgentwo