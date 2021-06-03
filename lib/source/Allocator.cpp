#include "spvgentwo/Allocator.h"

spvgentwo::ScopedAllocation::~ScopedAllocation()
{
	if (allocator != nullptr && ptr != nullptr)
	{
		allocator->deallocate(ptr, size);
	}
	allocator = nullptr;
}

spvgentwo::ScopedAllocation spvgentwo::IAllocator::allocateScoped(const sgt_size_t _bytes, const unsigned int _aligment)
{
	return ScopedAllocation(allocate(_bytes, _aligment), _bytes, this);
}
