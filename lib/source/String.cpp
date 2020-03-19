#include "spvgentwo/String.h"

spvgentwo::String& spvgentwo::String::operator=(const char* _pStr)
{
	const size_t length = stringLength(_pStr);

	if (reserve(length))
	{
		for (size_t i = 0; i < length; ++i)
		{
			m_pData[i] = _pStr[i];
		}

		m_elements = length;
	}

	return *this;
}

spvgentwo::String spvgentwo::String::substr(size_t _offset, size_t _length)
{
	const size_t available = m_elements - _offset;
	return String(m_pAllocator, m_pData+_offset, _length > available ? available : _length);
}

spvgentwo::String spvgentwo::String::operator+(const String& _other) const
{
	String both(m_pAllocator);
	if (both.reserve(m_elements + _other.m_elements))
	{
		both = *this; // assign first half
		for (size_t i = 0; i < _other.m_elements; ++i)
		{
			both[m_elements + i] = _other[i];
		}
		both.m_elements = m_elements + _other.m_elements;
	}
	return both;
}

spvgentwo::String spvgentwo::String::operator+(const char* _pStr) const
{
	String both(m_pAllocator);
	const size_t length = stringLength(_pStr);
	if (both.reserve(m_elements + length))
	{
		both = *this; // assign first half
		for (size_t i = 0; i < length; ++i)
		{
			both[m_elements + i] = _pStr[i];
		}
		both.m_elements = m_elements + length;
	}
	return both;
}

spvgentwo::String& spvgentwo::String::operator+=(const String& _other)
{
	if (reserve(m_elements + _other.m_elements))
	{
		for (size_t i = 0; i < _other.m_elements; ++i)
		{
			m_pData[m_elements + i] = _other[i];
		}
		m_elements = m_elements + _other.m_elements;
	}
	return *this;
}

spvgentwo::String& spvgentwo::String::operator+=(const char* _pStr)
{
	const size_t length = stringLength(_pStr);
	if (reserve(m_elements + length))
	{
		for (size_t i = 0; i < length; ++i)
		{
			m_pData[m_elements + i] = _pStr[i];
		}
		m_elements = m_elements + length;
	}
	return *this;
}
