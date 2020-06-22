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
//
//bool spvgentwo::BinaryFileReader::getAt(unsigned int& _word, const long _offset)
//{
//	return m_pFile != nullptr && fseek(m_pFile, _offset, SEEK_SET) == 0 && get(_word);
//}

//bool spvgentwo::BinaryFileReader::unGet(const unsigned int _count)
//{
//	if (m_pFile != nullptr)
//	{
//		const long offset = ftell(m_pFile) - static_cast<long>(_count * sizeof(unsigned int));		
//		return fseek(m_pFile, offset, SEEK_SET) == 0;
//	}
//
//	return false;
//}

//unsigned int spvgentwo::BinaryFileReader::total()
//{
//	unsigned int l{};
//
//	if (m_pFile != nullptr)
//	{
//		fseek(m_pFile, 0, SEEK_END);
//		l = static_cast<unsigned int>(ftell(m_pFile) * sizeof(unsigned int));
//		fseek(m_pFile, 0, SEEK_SET);
//	}
//	return l;
//}

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