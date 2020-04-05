#pragma once

#include "spvgentwo/Writer.h"
#include <cstdio>

namespace spvgentwo
{
	class BinaryFileWriter : public IWriter
	{
	public:
		BinaryFileWriter(const char* _path = nullptr);
		~BinaryFileWriter();

		void put(unsigned int _word) final;

		bool open(const char* _path);
		bool isOpen() const { return m_pFile != nullptr; }
		operator bool() const { return m_pFile != nullptr; }

		void close();

	private:
		FILE* m_pFile = nullptr;
	};
} //!spvgentwo
