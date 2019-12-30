#include "HeapAllocator.h"

#include <malloc.h>
#include <cassert>
#include <cstdio>

void* spvgentwo::HeapAllocator::allocate(const size_t _bytes, const unsigned int _aligment)
{
	(void)_aligment;
	m_Allocated += _bytes;
	return malloc(_bytes);
}

void spvgentwo::HeapAllocator::deallocate(void* _ptr, const size_t _bytes)
{
	m_Deallocated += _bytes;
	free(_ptr);
}

spvgentwo::HeapAllocator::~HeapAllocator()
{
	assert(m_Allocated == m_Deallocated);
	//printf("Allocated %zu bytes\n", m_Allocated);
}
