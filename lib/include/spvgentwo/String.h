#pragma once

#include "Vector.h"
#include "FNV1aHasher.h"

namespace spvgentwo
{
	// includes terminator string
	inline constexpr sgt_size_t stringLength(const char* _pStr)
	{
		if (_pStr == nullptr) 
			return 0u;

		sgt_size_t i = 0u;
		for (; _pStr[i] != '\0'; ++i) {}
		return i+1u;
	}

	class String : public Vector<char>
	{
	public:
		using Vector<char>::Vector;

		virtual ~String() override = default;

		String(const String& _other) : Vector(_other) {}

		constexpr String(String&& _other) noexcept : Vector(stdrep::move(_other)) {}

		String(IAllocator* _pAllocator, const char* _pStr = nullptr, sgt_size_t _length = 0u) : Vector(_pAllocator, _pStr, _length == 0u ? stringLength(_pStr) : _length) {};

		String& operator=(const String& _other) { Vector::operator=(_other); return *this; }
		String& operator=(String&& _other) noexcept { Vector::operator=(stdrep::move(_other)); return *this; }

		String& operator=(const char* _pStr);
		
		constexpr const char* c_str() const { return data(); }
		constexpr operator const char* () const { return data(); }

		String substr(sgt_size_t _offset, sgt_size_t _length);

		String operator+(const String& _other) const;
		String operator+(const char* _pStr) const;

		String& operator+=(const String& _other);
		String& operator+=(const char* _pStr);

		String& append(const char* _pStr, sgt_size_t _length = 0u);

		template <sgt_size_t N>
		Iterator insert(sgt_size_t _pos, const char(&_array)[N]) { return Vector::insert(_pos, _array, N); }

		Iterator insert(sgt_size_t _pos, const char* _pCStr, sgt_size_t _length = 0u) { return Vector::insert(_pos, _pCStr, _length == 0u ? stringLength(_pCStr) : _length); }

		Iterator insert(sgt_size_t _pos, const String& _str) { return Vector::insert(_pos, _str.data(), _str.size()); }

		bool operator==(const String& _other) const;
		bool operator==(const char* _pStr) const;
	};

	template<>
	struct Hasher<String>
	{
		Hash64 operator()(const String& _str, Hash64 _seed = detail::Offset) const noexcept
		{
			FNV1aHasher h(_seed);
			h.add(_str.data(), _str.size());
			return h;
		}
	};
}