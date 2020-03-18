#pragma once

#include "Callable.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	//template <typename T>
	//class HeapCallable : public Callable<T> {};

	template <typename ReturnValue, typename... Args>
	//class HeapCallable : public CallableT<ReturnValue, Args...>
	class HeapCallable : public Callable<ReturnValue(Args...)>
	{
	public:
		using Callable<ReturnValue(Args...)>::Callable;

		HeapCallable() : Callable<ReturnValue(Args...)>(HeapAllocator::instance()) {}

		template <typename Functor>
		HeapCallable(const Functor& f) : Callable<ReturnValue(Args...)>(HeapAllocator::instance(), f)	{}

		template <typename Functor>
		HeapCallable(Functor&& f) : Callable<ReturnValue(Args...)>(HeapAllocator::instance(), spvgentwo::stdrep::move(f)) {}
	};
} // !spvgentwo