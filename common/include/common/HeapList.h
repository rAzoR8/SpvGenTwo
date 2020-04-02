#pragma once

#include "spvgentwo/List.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	template <class T>
	class HeapList : public List<T>
	{
	public:
		using List<T>::List;

		HeapList() : List<T>(HeapAllocator::instance()) {}

		HeapList(const HeapList& _other) : List<T>(_other) {}

		HeapList(HeapList&& _other) noexcept : List<T>(stdrep::move(_other)) {}

		template <class ...Args> // args must be of type T
		HeapList(T&& _first, Args&& ... _args) : List<T>(HeapAllocator::instance(), stdrep::forward<T>(_first), stdrep::forward<Args>(_args)...) {}

		HeapList& operator=(const HeapList<T>& _other) { List<T>::operator=(_other); return *this; }
		HeapList& operator=(HeapList<T>&& _other) noexcept { List<T>::operator=(stdrep::move(_other)); return *this; }

		virtual ~HeapList() override = default;
	};
} 