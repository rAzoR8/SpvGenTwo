#include "common/BinaryFileReader.h"
#include <cstdio>

spvgentwo::BinaryFileReader::BinaryFileReader(IAllocator& _allocator, const char* _path, sgt_size_t _offset, sgt_size_t _length) :
	m_buffer(&_allocator)
{
	read(_path, _offset, _length);
}

bool spvgentwo::BinaryFileReader::get(unsigned int& _word)
{
	if (m_pos < m_buffer.size())
	{
		_word = m_buffer[m_pos++];
		return true;
	}

	return false;
}

bool spvgentwo::BinaryFileReader::read(const char* _path, sgt_size_t _offset, sgt_size_t _length)
{
	if (_path == nullptr)
	{
		return false;
	}

	struct rai
	{
		FILE* file = nullptr;
		~rai()
		{
			if (file != nullptr)
			{
				fclose(file);
				file = nullptr;
			}
		}
	};

	FILE* file = nullptr;
#ifdef _CRT_INSECURE_DEPRECATE
	if (fopen_s(&file, _path, "rb") != 0)
	{
		return false;
	}
#else
	file = fopen(_path, "rb");
#endif

	const rai closer{ file };

	if (file != nullptr)
	{
		if (fseek(file, static_cast<long>(_offset), SEEK_END) != 0) 
		{
			return false;
		}

		auto remaining = static_cast<sgt_size_t>(ftell(file));
		if (fseek(file, static_cast<long>(_offset), SEEK_SET) != 0u)
		{
			return false;
		}

		if (_length <= remaining)
		{
			_length = _length == 0 ? remaining : _length;

			if (_length % sizeof(sgt_uint32_t) != 0u)
			{
				return false;
			}

			auto count = _length / sizeof(sgt_uint32_t);
			if (m_buffer.resize(count) == false)
			{
				return false;
			}

			return fread(m_buffer.data(), sizeof(sgt_uint32_t), count, file) == count;
		}
	}

	return false;
}