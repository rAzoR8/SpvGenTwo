#include "spvgentwo/Allocator.h"

spvgentwo::Allocation::~Allocation()
{
	if (dealloc) 
	{
		allocator->deallocate(ptr, size);
		dealloc = false;
		allocator = nullptr;
	}
}
