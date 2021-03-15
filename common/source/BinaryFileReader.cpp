#include "common/BinaryFileReader.h"
#include <cstdio>

spvgentwo::BinaryFileReader::BinaryFileReader(const char* _path)
{
	open(_path);
}

spvgentwo::BinaryFileReader::~BinaryFileReader()
{
	close();
}

bool spvgentwo::BinaryFileReader::get(unsigned int& _word)
{
	return m_pFile != nullptr && fread(&_word, sizeof(unsigned int), 1u, static_cast<FILE*>(m_pFile)) == 1u;
}

bool spvgentwo::BinaryFileReader::open(const char* _path)
{
	if (m_pFile != nullptr || _path == nullptr)
	{
		return false;
	}

#ifdef _CRT_INSECURE_DEPRECATE
	FILE* file = nullptr;
	if (fopen_s(&file, _path, "rb") == 0)
	{
		m_pFile = file;
	}
#else
	m_pFile = fopen(_path, "rb");
#endif

	return m_pFile != nullptr;
}

void spvgentwo::BinaryFileReader::close()
{
	if (m_pFile != nullptr)
	{
		fflush(static_cast<FILE*>(m_pFile));
		fclose(static_cast<FILE*>(m_pFile));
		m_pFile = nullptr;
	}
}