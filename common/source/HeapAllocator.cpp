#include "common/HeapAllocator.h"

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

void* spvgentwo::HeapAllocator::allocate(sgt_size_t _bytes, [[maybe_unused]] unsigned int _alignment)
{
	m_Allocated += _bytes;
	return new char[_bytes];
}

void spvgentwo::HeapAllocator::deallocate(void* _ptr, sgt_size_t _bytes)
{
	m_Deallocated += _bytes;

	delete[] (char*) _ptr;
}

spvgentwo::HeapAllocator::HeapAllocator()
{
#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	static bool heapDbgInitialized = false;
	if( heapDbgInitialized == false )
	{
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
		heapDbgInitialized = true;
	}
#endif
}

spvgentwo::HeapAllocator* spvgentwo::HeapAllocator::instance()
{
	static HeapAllocator alloc;
	return &alloc;
}

void spvgentwo::HeapAllocator::setBreakAlloc( [[maybe_unused]] long alloc )
{
#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	_CrtSetBreakAlloc(alloc);
#endif
}
