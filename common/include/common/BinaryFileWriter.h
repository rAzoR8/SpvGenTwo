#pragma once

#include "spvgentwo/Writer.h"
#include <cstdio>

namespace spvgentwo
{
	class BinaryFileWriter : public IWriter
	{
	public:
		BinaryFileWriter(const char* _path);
		~BinaryFileWriter();
		long put(unsigned int _word) final;
		void putAt(unsigned int _word, const long _offset) final;

	private:
		FILE* m_pFile = nullptr;
	};
} //!spvgentwo
