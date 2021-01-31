#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	class ExternalMemoryAllocator : IAllocator
	{
	public:
		constexpr ExternalMemoryAllocator(void* _pBuffer = nullptr, sgt_size_t _capacity = 0u) : 
			IAllocator(),
			m_pBuffer(_pBuffer),
			m_pCurrent(_pBuffer),
			m_pEnd(static_cast<char*>(_pBuffer) + _capacity)
		{};

		template<class T, sgt_size_t N>
		constexpr ExternalMemoryAllocator(T(&_array)[N]) : IAllocator(), 
			m_pBuffer(_array),
			m_pCurrent(_array),
			m_pEnd(static_cast<char*>(_array) + sizeof(T[N]))
		{		
		}

		~ExternalMemoryAllocator() override = default;

		void* allocate(const sgt_size_t _bytes, const unsigned int _aligment = 1u) final;

		// can only deallocate last allocation, does not keep track of allocations
		void deallocate(void* _ptr, const sgt_size_t _bytes = 0u) final;

	private:
		void* m_pBuffer = nullptr;
		void* m_pCurrent = nullptr;
		const void* const m_pEnd = nullptr;
	};
} // !spvgentwo