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
	String both(m_pAllocator, m_elements + _other.m_elements);
	both = *this; // assign first half
	both += _other; // assign new part
	return both;
}

spvgentwo::String spvgentwo::String::operator+(const char* _pStr) const
{
	String both(m_pAllocator);
	both = *this; // assign first half
	both.append(_pStr); // assign new part
	return both;
}

spvgentwo::String& spvgentwo::String::operator+=(const String& _other)
{
	if (reserve(m_elements + _other.m_elements))
	{
		const size_t offset = m_elements > 0 && m_pData[m_elements - 1u] == '\0' ? m_elements - 1u : m_elements;
		for (size_t i = 0; i < _other.m_elements; ++i)
		{
			m_pData[offset + i] = _other[i];
		}
		m_elements = offset + _other.m_elements;
	}
	return *this;
}

spvgentwo::String& spvgentwo::String::operator+=(const char* _pStr)
{
	return append(_pStr);
}

spvgentwo::String& spvgentwo::String::append(const char* _pStr, size_t _length)
{
	const size_t length = _length == 0u ? stringLength(_pStr) : _length;
	if (reserve(m_elements + length))
	{
		// we only want one string terminator, overwrite the old one an append
		const size_t offset = m_elements > 0 && m_pData[m_elements - 1u] == '\0' ? m_elements - 1u : m_elements;
		for (size_t i = 0; i < length; ++i)
		{
			m_pData[offset + i] = _pStr[i];
		}
		m_elements = offset + length;
	}
	return *this;
}
