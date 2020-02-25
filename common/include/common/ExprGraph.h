#pragma once

#include "Graph.h"
#include "SimpleExpr.h"

namespace spvgentwo
{
	template <class Expr>
	class ExprGraph : public Graph<SimpleExpr<Expr>>
	{
		using Graph<SimpleExpr<Expr>>::Graph;
	public:

		void evaluate();
	};

	template<class Expr>
	inline void ExprGraph<Expr>::evaluate()
	{
		// todo: find exit node
		if (empty() == false)
		{
			back().data()(3);
		}
	}
} // !spvgentwo