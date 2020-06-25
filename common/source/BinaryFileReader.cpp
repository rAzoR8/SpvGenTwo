#include "common/BinaryFileReader.h"

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
	return m_pFile != nullptr && fread(&_word, sizeof(unsigned int), 1u, m_pFile) == 1u;
}

bool spvgentwo::BinaryFileReader::open(const char* _path)
{
	if (m_pFile != nullptr || _path == nullptr)
	{
		return false;
	}

	m_pFile = fopen(_path, "r");

	return m_pFile != nullptr;
}

void spvgentwo::BinaryFileReader::close()
{
	if (m_pFile != nullptr)
	{
		fflush(m_pFile);
		fclose(m_pFile);
		m_pFile = nullptr;
	}
}