#pragma once
#include "stdreplacement.h"

namespace spvgentwo
{
	class Allocation
	{
		friend class IAllocator;
		explicit constexpr Allocation(void* _ptr, sgt_size_t _size, IAllocator* _pAllocator, bool _dealloc = true) noexcept :
			ptr{_ptr}, size{_size}, allocator{_pAllocator},dealloc{_dealloc}
		{}

		bool dealloc;
		IAllocator* allocator;

	public:
		~Allocation();

		Allocation(const Allocation&) = delete;
		Allocation& operator=(const Allocation&) = delete;

		constexpr Allocation(Allocation&& _other) noexcept :
			ptr{_other.ptr}, size{_other.size}, allocator{_other.allocator}, dealloc{_other.dealloc}
		{
			_other.allocator = nullptr;
			_other.dealloc = false;
		}

		void* const ptr;
		const sgt_size_t size;
	};

	class IAllocator
	{
	public:
		virtual ~IAllocator() {}

		// alignment may only be a power of 2
		[[nodiscard]] virtual void* allocate(const sgt_size_t _bytes, const unsigned int _aligment = 1u) = 0;
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

		static inline void* alignPowerOf2(sgt_size_t _alignment, sgt_size_t _size, void*& _ptr, sgt_size_t _space) noexcept
		{
			static_assert(sizeof(sgt_size_t) == sizeof(void*), "System architecture not supported");

			sgt_size_t offset = static_cast<sgt_size_t>(reinterpret_cast<sgt_size_t>(_ptr) & (_alignment - 1));
			if (offset != 0)
			{
				offset = _alignment - offset;
			}

			if (_space < offset || _space - offset < _size)
			{
				return nullptr;
			}

			_ptr = static_cast<char*>(_ptr) + offset;
			return _ptr;
		}
	};
} // spvgentwo