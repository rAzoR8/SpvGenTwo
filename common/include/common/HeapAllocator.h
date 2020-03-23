#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	class HeapAllocator : public IAllocator
	{
	public:
		void* allocate(const size_t _bytes, const unsigned int _aligment = 1u) final;
		void deallocate(void* _ptr, const size_t _bytes) final;
		~HeapAllocator();

		static HeapAllocator* instance();
	private:
		size_t m_Allocated = 0u;
		size_t m_Deallocated = 0u;
	};
} //! spvgentwo