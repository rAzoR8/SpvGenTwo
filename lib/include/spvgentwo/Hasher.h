#pragma once

#include "FNV1aHasher.h"

namespace spvgentwo
{
	template<> struct Hasher<const char*> { Hash64 operator()(const char* ptr, Hash64 _seed = detail::Offset) const noexcept { FNV1aHasher h(_seed); h(ptr); return h; } };

	template<class T> struct Hasher<T*> { Hash64 operator()(T* ptr, Hash64 _seed = detail::Offset) const noexcept { FNV1aHasher h(_seed); h(ptr); return h; } };
	template<class T> struct Hasher<const T*> { Hash64 operator()(const T* ptr, Hash64 _seed = detail::Offset) const noexcept { FNV1aHasher h(_seed); h(ptr); return h; } };

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