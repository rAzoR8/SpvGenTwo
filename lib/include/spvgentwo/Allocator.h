#pragma once
#include "stdreplacement.h"

namespace spvgentwo
{
	class IAllocator
	{
	public:
		virtual void* allocate(const sgt_size_t _bytes, const unsigned int _aligment = 1u) = 0;
		virtual void deallocate(void* _ptr, const sgt_size_t _bytes = 0u) = 0;

		template <class T, class ... Args>
		T* construct(Args&& ..._args) noexcept
		{
			T* pData = reinterpret_cast<T*>(allocate(sizeof(T), 1u)); // TODO: aligment
			if (pData != nullptr)
			{
				new(pData) T{ stdrep::forward<Args>(_args)... };
			}
			return pData;
		}

		template <class T>
		void destruct(T* _ptr)
		{
			_ptr->~T();
			deallocate(_ptr, sizeof(T));
		}
	};
} // spvgentwo