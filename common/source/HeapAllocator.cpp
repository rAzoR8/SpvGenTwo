#include "common/HeapAllocator.h"

#include <malloc.h>
#include <cassert>

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	#include <stdio.h>
#endif

void* spvgentwo::HeapAllocator::allocate(const sgt_size_t _bytes, const unsigned int _aligment)
{
	(void)_aligment;
	m_Allocated += _bytes;

	void* ptr = malloc(_bytes);

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	entry alloc{ (uint32_t)m_allocations.size(), (uint32_t)_bytes };
	m_allocations[ptr] = alloc;

	assert(m_breakpoints.count(alloc.id) == 0);

	printf("%p size %llu\n", ptr, _bytes);
#endif

	return ptr;
}

void spvgentwo::HeapAllocator::deallocate(void* _ptr, const sgt_size_t _bytes)
{
	m_Deallocated += _bytes;

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	printf("%p %llu \t", _ptr, _bytes);

	for (auto i = 0u; i < _bytes; ++i)
	{
		char c = ((const char*)_ptr)[i];
		if(c != '\n')
			putchar(c);
	}
	printf("\n");

	entry alloc = m_allocations[_ptr];

	if (alloc.size != _bytes)
	{
		printf("Size %llu difference for %p {%u}\n", alloc.size -  _bytes, _ptr, alloc.id);
	}

	m_allocations.erase(_ptr);
#endif

	free(_ptr);
}

spvgentwo::HeapAllocator::~HeapAllocator()
{
#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC

	for (const auto& [ptr, e] : m_allocations)
	{
		printf("Leak %p id %u\n", ptr, e.id);
	}

#endif

	m_Allocated = 0u;
	m_Deallocated = 0u;
}

spvgentwo::HeapAllocator* spvgentwo::HeapAllocator::instance()
{
	static HeapAllocator alloc;
	return &alloc;
}

void spvgentwo::HeapAllocator::setHeapAllocBreakpoint(unsigned int _id)
{
#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	m_breakpoints.insert(_id);
#endif
}
