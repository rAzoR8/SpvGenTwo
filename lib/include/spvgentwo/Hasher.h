#pragma once

#include "FNV1aHasher.h"

namespace spvgentwo
{
	template<class T> struct Hasher<T*> { Hash64 operator()(T* ptr) const noexcept { return reinterpret_cast<Hash64>(ptr); } };

	template <class T>
	inline const Hash64 hash(const T& data) { return Hasher<T>()(data); }

	template <class T, class ...Tail>
	inline Hash64 hash(const T& _data, const Tail&... _tail)
	{
		FNV1aHasher func;
		func(_data, _tail...);
		return func;
	}
} // !spvgentwo