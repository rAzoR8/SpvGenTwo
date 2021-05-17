#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	class ExternalMemoryAllocator : public IAllocator
	{
	public:
		constexpr ExternalMemoryAllocator(void* _pBuffer = nullptr, sgt_size_t _capacity = 0u) : 
			IAllocator(),
			m_pCurrent(_pBuffer),
			m_pEnd(static_cast<char*>(_pBuffer) + _capacity)
		{};

		template<class T, sgt_size_t N>
		constexpr ExternalMemoryAllocator(T(&_array)[N]) : IAllocator(), 
			m_pCurrent(_array),
			m_pEnd(reinterpret_cast<char*>(_array) + sizeof(T[N]))
		{		
		}

		~ExternalMemoryAllocator() override = default;

		void* allocate(const sgt_size_t _bytes, unsigned int _aligment) final;

		// can only deallocate last allocation, does not keep track of allocations
		void deallocate(void* _ptr, const sgt_size_t _bytes = 0u) final;

	private:
		void* m_pCurrent = nullptr;
		const void* const m_pEnd = nullptr;
	};

	template <sgt_size_t Capacity>
	class StackStorage 
	{
	public:
		char m_storage[Capacity]{};
	};

	template <sgt_size_t Capacity>
	class StackMemoryAllocator : protected StackStorage<Capacity>, public ExternalMemoryAllocator
	{
	public:
		constexpr StackMemoryAllocator() : ExternalMemoryAllocator(StackStorage<Capacity>::m_storage) {}
	};

	template <class Container, sgt_size_t Capacity>
	class StackContainer : StackMemoryAllocator<Capacity>, public Container
	{
	public:
		template <class ... ContainerArgs>
		StackContainer(ContainerArgs&& ... _args) : Container(this, stdrep::forward<ContainerArgs>(_args)...) {}
	};

	template <class Container, sgt_size_t Capacity, class ... ContainerArgs>
	auto make_stack_container(ContainerArgs&& ... _args)
	{
		return StackContainer<Container, Capacity>(stdrep::forward<ContainerArgs>(_args)...);
	}
} // !spvgentwo