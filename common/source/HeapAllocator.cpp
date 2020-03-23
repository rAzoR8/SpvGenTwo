#include "common/HeapAllocator.h"

#include <malloc.h>
#include <cassert>

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	#include <stdio.h>
#endif
void* spvgentwo::HeapAllocator::allocate(const size_t _bytes, const unsigned int _aligment)
{
	(void)_aligment;
	m_Allocated += _bytes;

	void* ptr = malloc(_bytes);

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	printf("%p size %llu\n", ptr, _bytes);
#endif

	return ptr;
}

void spvgentwo::HeapAllocator::deallocate(void* _ptr, const size_t _bytes)
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
#endif

	free(_ptr);
}

spvgentwo::HeapAllocator::~HeapAllocator()
{
#ifndef SPVGENTWO_DEBUG_HEAP_ALLOC
	assert(m_Allocated == m_Deallocated);
#endif
}

spvgentwo::HeapAllocator* spvgentwo::HeapAllocator::instance()
{
	static HeapAllocator alloc;
	return &alloc;
}
