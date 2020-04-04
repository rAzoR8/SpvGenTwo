#include "common/BinaryFileWriter.h"

spvgentwo::BinaryFileWriter::BinaryFileWriter(const char* _path)
{
	m_pFile = fopen(_path, "wb");
}

spvgentwo::BinaryFileWriter::~BinaryFileWriter()
{
	if (m_pFile != nullptr)
	{
		fflush(m_pFile);
		fclose(m_pFile);
		m_pFile = nullptr;
	}
}

void spvgentwo::BinaryFileWriter::put(unsigned int _word)
{
	if (m_pFile != nullptr)
	{
		fwrite(&_word, sizeof(unsigned int), 1u, m_pFile);
		//auto pos = ftell(m_pFile);
		//printf("%llu:\t0x%X\t\t%u\n", pos - sizeof(unsigned int), _word, _word);
	}
}