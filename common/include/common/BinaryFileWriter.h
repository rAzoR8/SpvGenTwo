#pragma once

#include "spvgentwo/Writer.h"
#include "spvgentwo/Vector.h"

namespace spvgentwo
{
	class BinaryFileWriter : public IWriter
	{
	public:
		BinaryFileWriter(IAllocator& _allocator, const char* _path = nullptr, sgt_size_t _initialBufferSize = 2 * 1024u);
		~BinaryFileWriter();

		bool put(unsigned int _word) final;

		bool open(const char* _path);
		bool isOpen() const { return m_pFile != nullptr; }
		operator bool() const { return m_pFile != nullptr; }

		void close();

	private:
		Vector<sgt_uint32_t> m_buffer;
		void* m_pFile = nullptr;
	};
} //!spvgentwo
