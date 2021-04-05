#pragma once

#include "FNV1aHasher.h"

namespace spvgentwo
{
	template <class T, class ...Tail>
	inline constexpr Hash64 hash(const T& _data, const Tail&... _tail)
	{
		FNV1aHasher h{};
		return h(_data, _tail...);
	}
} // !spvgentwo