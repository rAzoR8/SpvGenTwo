#pragma once

#include "Graph.h"
#include "Expression.h"
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

		template <ExprArgs args> // every node in _nodeOrder must be unique
		static bool evaluateExplicit(const List<NodeType*>& _nodeOrder);

		// resets nodes 'evaluated' state to false
		void resetEvaluationState();
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

	template<class Func>
	template<ExprArgs args>
	inline bool ExprGraph<Func>::evaluateExplicit(const List<NodeType*>& _nodeOrder)
	{
		for (NodeType* node : _nodeOrder)
		{
			auto& expr = node->data();

			if (expr.evaluated()) // node was already evaluated (non unique)
			{
				return false;
			}

			if constexpr (args == ExprArgs::FunctionPtrLists)
			{
				auto inputs = transform(node->inputs(), [](auto& edge) -> Func* {return &edge.pTarget->data().get(); });
				auto outputs = transform(node->outputs(), [](auto& edge) -> Func* {return &edge.pTarget->data().get(); });
				expr(inputs, outputs);
			}
			else
			{
				expr(node->inputs(), node->output());
			}
		}

		return true;
	}

	template<class Func>
	inline void ExprGraph<Func>::resetEvaluationState()
	{
		for (NodeType& node : Graph<Expression<Func>>::m_nodes)
		{
			node.data().reset();
		}
	}
} // !spvgentwo