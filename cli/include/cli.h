#pragma once

#include "lib.h"
#include "Writer.h"
#include "Logger.h"
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
		BinaryFileWriter(const char* _path);
		~BinaryFileWriter();
		long put(unsigned int _word);
		void putAt(unsigned int _word, const long _offset);

	private:
		FILE* m_pFile = nullptr;
	};

	class ConsoleLogger : public ILogger
	{
	public:
		void log(const LogLevel _level, const char* _pMsg) final;
	};
} //! spvgentwo