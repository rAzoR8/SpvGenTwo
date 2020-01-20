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
	}

	return *this;
}

bool spvgentwo::String::reserve(size_t _size)
{
	bool ret = true;
	if (_size > m_capacity)
	{
		ret = Vector::reserve(_size + 1u);
		m_pData[_size] = '\0';
	}
	return ret;
}
