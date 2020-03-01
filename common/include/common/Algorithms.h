#pragma once

#include "spvgentwo/stdreplacement.h"

namespace spvgentwo
{
	// transform a Container<Elem> to a Container<Func(Elem)>
	template <class Elem, template <typename T> class Container, class Func>
	auto transform(const Container<Elem>& _input, const Func& _func)
	{
		using Transformed = decltype(stdrep::declval<Func>()(stdrep::declval<const Elem&>));
		Container<Transformed> output(_input.getAllocator());

		for(const Elem& elem : _input)
		{
			output.emplace_back(_func(elem));
		}

		return output;
	}
} //!spvgentwo