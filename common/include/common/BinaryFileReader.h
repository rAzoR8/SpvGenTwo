#pragma once

#include "spvgentwo/Reader.h"
#include "spvgentwo/Vector.h"

namespace spvgentwo
{
	class BinaryFileReader : public IReader
	{
	public:
		BinaryFileReader(IAllocator& _allocator, const char* _path = nullptr, sgt_size_t _offset = 0u, sgt_size_t _length = 0u);
		~BinaryFileReader() override = default;

		// get can only be called after read was successful
		bool get(unsigned int& _word) final;

		bool read(const char* _path, sgt_size_t _offset = 0u, sgt_size_t _length = 0u);
		operator bool() const { return m_buffer.empty() == false; }

	private:
		Vector<sgt_uint32_t> m_buffer;
		sgt_size_t m_pos = 0u;
	};
} //!spvgentwo
