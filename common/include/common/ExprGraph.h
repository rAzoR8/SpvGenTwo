#pragma once

#include "Graph.h"
#include "SimpleExpr.h"
#include "spvgentwo/HashMap.h"

namespace spvgentwo
{
	template <class Expr>
	class ExprGraph : public Graph<SimpleExpr<Expr>>
	{
	public:
		using Graph<SimpleExpr<Expr>>::Graph;

		using NodeType = typename Graph<SimpleExpr<Expr>>::NodeType;

		void evaluate(NodeType* _pExitNode);
	};

	template<class Expr>
	inline void ExprGraph<Expr>::evaluate(NodeType* _pExitNode)
	{
		HashMap<NodeType*, bool> processed;

		// todo: find exit node
		if (empty() == false)
		{
			//auto& node = back();
			_pExitNode->data()(*_pExitNode);
		}
	}
} // !spvgentwo