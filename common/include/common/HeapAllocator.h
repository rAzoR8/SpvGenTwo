#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	class HeapAllocator : public IAllocator
	{
	public:
		HeapAllocator();

		void* allocate(sgt_size_t _bytes, unsigned int _alignment) final;
		void deallocate(void* _ptr, sgt_size_t _bytes) final;

		static HeapAllocator* instance();

		static void setBreakAlloc( long alloc );

	private:
		sgt_size_t m_Allocated = 0u;
		sgt_size_t m_Deallocated = 0u;
	};

	template <class Container>
	class HeapContainer : public Container
	{
	public:
		template <class ... ContainerArgs>
		HeapContainer(ContainerArgs&& ... _args) : Container(HeapAllocator::instance(), stdrep::forward<ContainerArgs>(_args)...) {}
	};

	template <class Container, class ... ContainerArgs>
	auto make_heap_container(ContainerArgs&& ... _args)
	{
		return HeapContainer<Container>(stdrep::forward<ContainerArgs>(_args)...);
	}
} //! spvgentwo
