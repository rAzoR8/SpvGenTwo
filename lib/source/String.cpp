#include "spvgentwo/String.h"

spvgentwo::String& spvgentwo::String::operator=(const char* _pStr)
{
	const sgt_size_t length = stringLength(_pStr);

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

spvgentwo::String spvgentwo::String::substr(sgt_size_t _offset, sgt_size_t _length)
{
	const sgt_size_t available = m_elements - _offset;
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
		const sgt_size_t offset = m_elements > 0 && m_pData[m_elements - 1u] == '\0' ? m_elements - 1u : m_elements;
		for (sgt_size_t i = 0; i < _other.m_elements; ++i)
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

spvgentwo::String& spvgentwo::String::append(const char* _pStr, sgt_size_t _length)
{
	const sgt_size_t length = _length == 0u ? stringLength(_pStr) : _length;
	if (reserve(m_elements + length))
	{
		// we only want one string terminator, overwrite the old one an append
		const sgt_size_t offset = m_elements > 0 && m_pData[m_elements - 1u] == '\0' ? m_elements - 1u : m_elements;
		for (sgt_size_t i = 0u; i < length; ++i)
		{
			m_pData[offset + i] = _pStr[i];
		}
		m_elements = offset + length;
	}
	return *this;
}

bool spvgentwo::String::operator==(const String& _other) const
{
	if (m_elements == _other.m_elements)
	{
		for (sgt_size_t i = 0u; i < m_elements; ++i)
		{
			if (m_pData[i] != _other.m_pData[i])
				return false;
		}
		return true;
	}
	return false;
}

bool spvgentwo::String::operator==(const char* _pStr) const
{
	const sgt_size_t length = stringLength(_pStr);
	if (m_elements == length)
	{
		for (sgt_size_t i = 0; i < m_elements; ++i)
		{
			if (m_pData[i] != _pStr[i])
				return false;
		}
		return true;
	}
	return false;
}

spvgentwo::String::Iterator spvgentwo::String::insert(sgt_size_t _pos, const char* _pCStr, sgt_size_t _length)
{
	auto ret = Vector::insert(_pos, _pCStr, _length == 0u ? (stringLength(_pCStr) - 1u) : _length);

	if (m_elements != 0u && m_pData[m_elements - 1u] != '\0')
	{
		String::emplace_back('\0'); // append string terminator if necessar
	}
	return ret;
}