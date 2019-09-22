#pragma once

#include "lib.h"
#include "Writer.h"
#include <malloc.h>
#include <cstdio>

namespace spvgentwo
{
	class HeapAllocator : public IAllocator
	{
	public:
		void* allocate(const size_t _bytes, const unsigned int _aligment = 1u) final;
		void deallocate(void* _ptr, const size_t _bytes) final;
		~HeapAllocator();
	private:
		size_t m_Allocated = 0u;
		size_t m_Deallocated = 0u;
	};

	class BinaryFileWriter : public IWriter
	{
	public:
		BinaryFileWriter(const char* _path)
		{
			m_pFile = fopen(_path, "wb");
		}

		~BinaryFileWriter()
		{
			if (m_pFile != nullptr)
			{
				fclose(m_pFile);
				m_pFile = nullptr;
			}
		}

		long put(unsigned int _word) final
		{
			if (m_pFile != nullptr)
			{
				fwrite(&_word, sizeof(unsigned int), 1u, m_pFile);
				return ftell(m_pFile);
			}

			return 0;
		}

		void putAt(unsigned int _word, const long _offset) final
		{
			if (m_pFile != nullptr && fseek(m_pFile, _offset, SEEK_SET) == 0)
			{
				fwrite(&_word, sizeof(unsigned int), 1u, m_pFile);
			}
		}

	private:
		FILE* m_pFile = nullptr;
	};
} //! spvgentwo