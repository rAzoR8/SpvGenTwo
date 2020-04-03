#pragma once

#include "spvgentwo/Allocator.h"

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	#include <unordered_map>
	#include <unordered_set>
#endif

namespace spvgentwo
{
	class HeapAllocator : public IAllocator
	{
	public:
		void* allocate(const size_t _bytes, const unsigned int _aligment = 1u) final;
		void deallocate(void* _ptr, const size_t _bytes) final;
		~HeapAllocator();

		static HeapAllocator* instance();

		void setHeapAllocBreakpoint(unsigned int _id);
	private:
		size_t m_Allocated = 0u;
		size_t m_Deallocated = 0u;

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
		struct entry { unsigned int id; unsigned int size; operator size_t() const { return size_t(id) | size_t(size) << 32u; } };

		std::unordered_map<void*, entry> m_allocations;
		std::unordered_set<unsigned int> m_breakpoints;
#endif
	};

} //! spvgentwo