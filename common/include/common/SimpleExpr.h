#pragma once

#include "Node.h"

namespace spvgentwo
{	
	template <class Func>
	class SimpleExpr
	{
		Func m_func;
	public:
		SimpleExpr(const Func& _func) : m_func(_func) {}

		//template <class ...Args>
		//SimpleExpr(Args&& ... _args) : m_func{ stdrep::forward<Args>(_args)... } {}

		template <class ...Args>
		auto operator()(Args&& ... _args)
		{ 
			return m_func(stdrep::forward<Args>(_args)...);
		}
	};

	template <class ...Args>
	auto make_expr(Args&& ... _args) { return SimpleExpr(stdrep::forward<Args>(_args)...); }

	template <class ...Args>
	using expr_type = decltype(make_expr(stdrep::declval<Args>()...));
} // !spvgentwo