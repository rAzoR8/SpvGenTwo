#pragma once
#include "stdreplacement.h"

namespace spvgentwo
{
	class IAllocator
	{
	public:
		virtual void* allocate(const size_t _bytes, const unsigned int _aligment) = 0;
		virtual void deallocate(void* _ptr) = 0;

		template <class T, class ... Args>
		T* construct(Args&& ..._args) 
		{
			T* pData = reinterpret_cast<T*>(allocate(sizeof(T), 1u)); // TODO: aligment
			if (pData != nullptr)
			{
				new(pData) T(forward<Args>(_args)...); // forward
			}
			return pData;
		}

		template <class T>
		void destruct(T* _ptr)
		{
			_ptr->~T();
			deallocate(_ptr);
		}
	};
} // spvgentwo