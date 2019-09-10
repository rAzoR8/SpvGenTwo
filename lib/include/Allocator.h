#pragma once
#include <stdint.h>
//#include <utility> // std::forward
#include <new>

namespace spvgentwo
{
	class IAllocator
	{
	public:
		virtual void* allocate(const size_t _bytes, const uint32_t _aligment) = 0;
		virtual void deallocate(const void* _ptr) = 0;

		template <class T, class ... Args>
		T* construct(Args&& ..._args) 
		{
			T* pData = reinterpret_cast<T*>(allocate(sizeof(T), 1u)); // TODO: aligment
			if (pData != nullptr)
			{
				new(pData) T(static_cast<Args&&>(_args)...); // forward
			}
			return pData;
		}
	};
} // spvgentwo