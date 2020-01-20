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
