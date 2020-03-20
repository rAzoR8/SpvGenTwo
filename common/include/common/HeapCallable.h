#pragma once

#include "Callable.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	template <typename Func>
	class HeapCallable : public Callable<Func>
	{
	public:
		using Callable<Func>::Callable;

		HeapCallable(const HeapCallable& _other) noexcept : Callable<Func>(_other){}

		HeapCallable(HeapCallable&& _other) noexcept : Callable<Func>(stdrep::move(_other)) {}

		HeapCallable() : Callable<Func>(HeapAllocator::instance()) {}

		template <typename Functor>
		HeapCallable(const Functor& f) : Callable<Func>(HeapAllocator::instance(), f) {}

		template <typename Obj, typename ReturnType, typename ... Args>
		HeapCallable(Obj* _obj, ReturnType(Obj::* _func)(Args...)) : Callable<Func>(HeapAllocator::instance(), _obj, _func) {}

		template <typename Functor>
		HeapCallable(Functor&& f) : Callable<Func>(HeapAllocator::instance(), spvgentwo::stdrep::move(f)) {}

		virtual ~HeapCallable() override = default;

		HeapCallable& operator=(const HeapCallable& _other) { Callable<Func>::operator=(_other); return *this; }
		HeapCallable& operator=(HeapCallable&& _other) noexcept { Callable<Func>::operator=(stdrep::move(_other)); return *this; }
	};
} // !spvgentwo