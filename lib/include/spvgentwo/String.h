#pragma once

#include "Vector.h"
#include "FNV1aHasher.h"

namespace spvgentwo
{
	// includes string terminator
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

		// exclude string terminator
		constexpr sgt_size_t size() const { return m_elements == 0u ? 0u : m_elements - 1u; }
		constexpr auto end() const { return begin() + size(); }

		constexpr T& back() { return m_pData[m_elements - 2u]; }
		constexpr const T& back() const { return m_pData[m_elements - 2u]; }

		String substr(sgt_size_t _offset, sgt_size_t _length);

		String operator+(const String& _other) const;
		String operator+(const char* _pStr) const;

		String& operator+=(const String& _other);
		String& operator+=(const char* _pStr);

		String& append(const char* _pStr, sgt_size_t _length = 0u);

		template <sgt_size_t N>
		Iterator insert(sgt_size_t _pos, const char(&_array)[N]) { return Vector::insert(_pos, _array, N); }

		// don't insert the additional string terminator from _pCStr
		Iterator insert(sgt_size_t _pos, const char* _pCStr, sgt_size_t _length = 0u);

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