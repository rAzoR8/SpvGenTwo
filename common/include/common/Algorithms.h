#pragma once

#include "spvgentwo/stdreplacement.h"

namespace spvgentwo::algo
{
	// transform a Container<Elem> to a Container<Func(Elem)>
	template <class Elem, template <typename T> class Container, class Func>
	auto transform(const Container<Elem>& _input, const Func& _func)
	{
		static_assert(traits::is_invocable_v<Func, const Elem&>, "Func not invocable with const Elem&");
		using Transformed = decltype(stdrep::declval<Func>()(stdrep::declval<const Elem&>()));
		Container<Transformed> output(_input.getAllocator());

		for(const Elem& elem : _input)
		{
			output.emplace_back(_func(elem));
		}

		return output;
	}

	template <class Elem, template <typename T> class Container, class Func>
	auto transform(Container<Elem>& _input, const Func& _func)
	{
		static_assert(traits::is_invocable_v<Func, Elem&>, "Func not invocable with Elem&");
		using Transformed = decltype(stdrep::declval<Func>()(stdrep::declval<Elem&>()));
		Container<Transformed> output(_input.getAllocator());

		for (Elem& elem : _input)
		{
			output.emplace_back(_func(elem));
		}

		return output;
	}

	template <class Elem, template <typename T> class Container, class Func>
	bool any(const Container<Elem>& _input, const Func& _func)
	{
		static_assert(traits::is_invocable_v<Func, const Elem&>, "Func not invocable with const Elem&");
	
		for (const Elem& elem : _input)
		{
			if (_func(elem))
				return true;
		}

		return false;
	}

	template <class Elem, template <typename T> class Container, class Func>
	bool all(const Container<Elem>& _input, const Func& _func)
	{
		static_assert(traits::is_invocable_v<Func, const Elem&>, "Func not invocable with const Elem&");

		for (const Elem& elem : _input)
		{
			if (_func(elem) == false)
				return false;
		}

		return true;
	}
} //!spvgentwo