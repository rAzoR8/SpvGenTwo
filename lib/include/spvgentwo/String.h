#pragma once

#include "Vector.h"

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

		String(String&& _other) noexcept : Vector(stdrep::move(_other)) {}

		String(IAllocator* _pAllocator = nullptr, const char* _pStr = nullptr, sgt_size_t _length = 0u) : Vector(_pAllocator, _pStr, _length == 0u ? stringLength(_pStr) : _length) {};

		template <sgt_size_t N>
		String(IAllocator* _pAllocator, const char(&_pStr)[N]) : Vector(_pAllocator, _pStr) {};

		String& operator=(const String& _other) { Vector::operator=(_other); return *this; }
		String& operator=(String&& _other) noexcept { Vector::operator=(stdrep::move(_other)); return *this; }

		String& operator=(const char* _pStr);
		
		template <sgt_size_t N>
		String& operator=(const char(&_pStr)[N]);

		auto c_str() const { return data(); }

		operator const char* () const { return data(); }

		String substr(sgt_size_t _offset, sgt_size_t _length);

		String operator+(const String& _other) const;
		String operator+(const char* _pStr) const;

		String& operator+=(const String& _other);
		String& operator+=(const char* _pStr);

		String& append(const char* _pStr, sgt_size_t _length = 0u);

		bool operator==(const String& _other) const;
		bool operator==(const char* _pStr) const;
	};

	template<sgt_size_t length>
	inline String& String::operator=(const char(&_pStr)[length])
	{
		if (reserve(length))
		{
			for (sgt_size_t i = 0; i < length; ++i)
			{
				m_pData[i] = _pStr[i];
			}

			m_elements = length;
		}

		return *this;
	}
}