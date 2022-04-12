#pragma once
#include "stdreplacement.h"

namespace spvgentwo
{
	// forward decl
	class IAllocator;

	class ScopedAllocation
	{
		friend class IAllocator;
		explicit constexpr ScopedAllocation(void* _ptr, sgt_size_t _size, IAllocator* _pAllocator) noexcept :
			allocator{_pAllocator},
			ptr{_ptr}, 
			size{_size}
		{}

		IAllocator* allocator;

	public:
		~ScopedAllocation();

		ScopedAllocation(const ScopedAllocation&) = delete;
		ScopedAllocation& operator=(const ScopedAllocation&) = delete;

		constexpr ScopedAllocation(ScopedAllocation&& _other) noexcept :
			allocator{_other.allocator},
			ptr{_other.ptr},
			size{_other.size}
		{
			_other.allocator = nullptr;
		}

		constexpr operator bool() const { return ptr != nullptr && allocator != nullptr; }

		void* const ptr;
		const sgt_size_t size;
	};

	class IAllocator
	{
	public:
		virtual ~IAllocator() = default;

		// alignment may only be a power of 2
		// the library has no alignment requirement so implementations are free to use the hint or return unaligned pointers
		[[nodiscard]] virtual void* allocate(sgt_size_t _bytes, unsigned int _alignmentHint) = 0;
		virtual void deallocate(void* _ptr, sgt_size_t _bytes = 0u) = 0;

		[[nodiscard]] ScopedAllocation allocateScoped(sgt_size_t _bytes, unsigned int _alignment);

		template <class T, class ... Args>
		T* construct(Args&& ..._args) noexcept
		{
			T* pData = reinterpret_cast<T*>(allocate(sizeof(T), alignof(T)));
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
