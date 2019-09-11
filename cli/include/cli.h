#pragma once

#include "lib.h"
#include <malloc.h>

namespace spvgentwo
{
	class HeapAllocator : public IAllocator
	{
	public:
		void* allocate(const size_t _bytes, const unsigned int _aligment) final;
		void deallocate(void* _ptr) final;
	};
} //! spvgentwo