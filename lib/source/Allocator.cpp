#include "spvgentwo/Allocator.h"

spvgentwo::ScopedAllocation::~ScopedAllocation()
{
	if (allocator != nullptr && ptr != nullptr)
	{
		allocator->deallocate(ptr, size);
	}
	allocator = nullptr;
}

spvgentwo::ScopedAllocation spvgentwo::IAllocator::allocateScoped(sgt_size_t _bytes, unsigned int _aligment)
{
	return ScopedAllocation(allocate(_bytes, _aligment), _bytes, this);
}
