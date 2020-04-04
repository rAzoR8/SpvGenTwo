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
		void put(unsigned int _word) final;

	private:
		FILE* m_pFile = nullptr;
	};
} //!spvgentwo
