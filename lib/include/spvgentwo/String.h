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

	// _outBuffer must have space for at least 10 digits ( max length is log10(UINT_MAX) ~ 9.6 )
	inline constexpr void uintToString(unsigned int _value, char* _outBuffer, unsigned int _bufferLength, unsigned int _base = 10u)
	{
		constexpr char alpha[] = { '0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		_base = sizeof(alpha) < _base ? sizeof(alpha) : _base;

		unsigned int len = 0u; // count length of our string
		for (unsigned int val = _value; val != 0u; val /= _base, ++len) {}
		len = _value == 0u ? 1u : len;
		len = _bufferLength < len ? _bufferLength : len;

		do
		{
			_outBuffer[--len] = alpha[_value % _base];
			_value /= _base;
		} while (_value != 0 && len > 0u);
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
		
		constexpr char* c_str() const { return data(); }
		constexpr operator char* () const { return data(); }

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

		template <class Arg>
		T* emplace_back(Arg&& _arg);

		// emplace one element per argument
		template <class ...Args>
		void emplace_back_args(const T& _first, Args&& ..._tail);
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

	template<class Arg>
	inline String::T* String::emplace_back(Arg&& _arg)
	{
		if(m_elements == 0 || Vector::back() != '\0')
		{
			Vector::emplace_back(stdrep::forward<Arg>(_arg));
			Vector::emplace_back('\0');
			return &back();
		}
		else if (reserve(m_elements+1u))
		{
			m_pData[m_elements] = m_pData[m_elements - 1]; // move string terminator to last element
			m_pData[m_elements - 1] = stdrep::forward<Arg>(_arg); // new element is 2nd last
			++m_elements;
			return &back();
		}
		return nullptr;
	}

	template<class ...Args>
	inline void String::emplace_back_args(const T& _first, Args && ..._tail)
	{
		String::emplace_back(_first);

		if constexpr (sizeof...(_tail) > 0)
		{
			String::emplace_back_args(stdrep::forward<Args>(_tail)...);
		}
	}
}