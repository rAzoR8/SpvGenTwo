#pragma once

#include "spvgentwo/Reader.h"

namespace spvgentwo
{
	class BinaryFileReader : public IReader
	{
	public:
		BinaryFileReader(const char* _path = nullptr);
		~BinaryFileReader();

		bool get(unsigned int& _word) final;

		bool open(const char* _path);
		bool isOpen() const { return m_pFile != nullptr; }
		operator bool() const { return m_pFile != nullptr; }

		void close();

	private:
		void* m_pFile = nullptr;
	};
} //!spvgentwo
