#pragma once

#include "spvgentwo/Vector.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	template <class U>
	class HeapVector : public Vector<U>
	{
	public:
		using T = typename stdrep::remove_cv_t<U>;

		using Vector<U>::Vector;

		HeapVector(const HeapVector& _other) : Vector<U>(_other) {}

		HeapVector(HeapVector&& _other) noexcept : Vector<U>(stdrep::move(_other)) {}

		HeapVector(sgt_size_t _size = 0u) : Vector<U>(HeapAllocator::instance(), _size) {}

		// copy from array
		HeapVector(const T* _pData, sgt_size_t _size = 0u) : Vector<U>(HeapAllocator::instance(), _pData, _size) {}

		template <sgt_size_t Size>
		HeapVector(const T(&_array)[Size]) : Vector<U>(HeapAllocator::instance(), _array) {}

		template <typename ...Args>
		HeapVector(const T& _first, Args&& ... _args) : Vector<U>(HeapAllocator::instance(), _first, stdrep::forward<Args>(_args)...) {}

		virtual ~HeapVector() override = default;

		HeapVector& operator=(const HeapVector& _other) { Vector<U>::operator=(_other); return *this; }
		HeapVector& operator=(HeapVector&& _other) noexcept { Vector<U>::operator=(stdrep::move(_other)); return *this; }
	};
} // !spvgentwo