#include "common/BinaryFileWriter.h"
#include <cstdio>

spvgentwo::BinaryFileWriter::BinaryFileWriter(IAllocator& _allocator, const char* _path, sgt_size_t _initialBufferSize) :
	m_buffer(&_allocator, _initialBufferSize)
{
	open(_path);
}

spvgentwo::BinaryFileWriter::~BinaryFileWriter()
{
	close();
}

bool spvgentwo::BinaryFileWriter::put(unsigned int _word)
{
	m_buffer.emplace_back(_word);
	return true;
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
		if (m_buffer.empty() == false)
		{
			fwrite(m_buffer.data(), sizeof(sgt_uint32_t), m_buffer.size(), static_cast<FILE*>(m_pFile));
		}

		fclose(static_cast<FILE*>(m_pFile));
		m_pFile = nullptr;
	}
	m_buffer.clear();
}