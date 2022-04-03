#include "common/HeapAllocator.h"

#ifdef SPVGENTWO_DEBUG_HEAP_ALLOC
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

#include <cstdlib>

void* spvgentwo::HeapAllocator::allocate(sgt_size_t _bytes, unsigned int _alignment)
{
	if (_alignment & (_alignment - 1)) // not a power of two
	{
		return nullptr;
	}

	m_Allocated += _bytes;

#if defined(_WIN32) || defined(__CYGWIN__)
	void* ptr = _aligned_malloc(_bytes, _alignment);
#else	
	void* ptr = aligned_alloc(_alignment < sizeof(void*) ? sizeof(void*) : _alignment, _bytes);
#endif

	return ptr;
}

void spvgentwo::HeapAllocator::deallocate(void* _ptr, sgt_size_t _bytes)
{
	m_Deallocated += _bytes;

#if defined(_WIN32) || defined(__CYGWIN__)
	 _aligned_free(_ptr);
#else	
	free(_ptr);
#endif
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
