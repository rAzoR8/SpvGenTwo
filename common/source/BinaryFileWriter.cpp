#include "common/BinaryFileWriter.h"

spvgentwo::BinaryFileWriter::BinaryFileWriter(const char* _path)
{
	open(_path);
}

spvgentwo::BinaryFileWriter::~BinaryFileWriter()
{
	close();
}

void spvgentwo::BinaryFileWriter::put(unsigned int _word)
{
	if (m_pFile != nullptr)
	{
		fwrite(&_word, sizeof(unsigned int), 1u, m_pFile);
	}
}

bool spvgentwo::BinaryFileWriter::open(const char* _path)
{
	if (m_pFile != nullptr || _path == nullptr)
	{
		return false;
	}

	m_pFile = fopen(_path, "wb");

	return m_pFile != nullptr;
}

void spvgentwo::BinaryFileWriter::close()
{
	if (m_pFile != nullptr)
	{
		fflush(m_pFile);
		fclose(m_pFile);
		m_pFile = nullptr;
	}
}