#pragma once

#include "Vector.h"

namespace spvgentwo
{
	inline constexpr size_t stringLength(const char* _pStr)
	{
		if (_pStr == nullptr) 
			return 0u;

		size_t i = 0u;
		for (; _pStr[i] != '\0'; ++i) {}
		return i;
	}

	class String : public Vector<char>
	{
	public:
		using Vector<char>::Vector;

		String(IAllocator* _pAllocator = nullptr, const char* _pStr = nullptr) : Vector(_pAllocator, _pStr, stringLength(_pStr)) {};

		String& operator=(const char* _pStr);

		auto c_str() const { return data(); }

		operator const char* () const { return data(); }

		// size excluding zero
		bool reserve(size_t _size);

		String substr(size_t _offset, size_t _length);

		String operator+(const String& _other) const;

		String& operator+=(const String & _other);
	private:
	};
}