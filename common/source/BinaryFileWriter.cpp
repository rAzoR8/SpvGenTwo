#include "common/BinaryFileWriter.h"
#include <cstdio>

spvgentwo::BinaryFileWriter::BinaryFileWriter(const char* _path)
{
	open(_path);
}

spvgentwo::BinaryFileWriter::~BinaryFileWriter()
{
	close();
}

bool spvgentwo::BinaryFileWriter::put(unsigned int _word)
{
	return m_pFile != nullptr && fwrite(&_word, sizeof(unsigned int), 1u, static_cast<FILE*>(m_pFile)) == 1u;
}

bool spvgentwo::BinaryFileWriter::open(const char* _path)
{
	if (m_pFile != nullptr || _path == nullptr)
	{
		return false;
	}

#ifdef _CRT_INSECURE_DEPRECATE
	FILE* file = nullptr;
	if (fopen_s(&file, _path, "wb") == 0)
	{
		m_pFile = file;
	}
#else
	m_pFile = fopen(_path, "wb");
#endif

	return m_pFile != nullptr;
}

void spvgentwo::BinaryFileWriter::close()
{
	if (m_pFile != nullptr)
	{
		fflush(static_cast<FILE*>(m_pFile));
		fclose(static_cast<FILE*>(m_pFile));
		m_pFile = nullptr;
	}
}