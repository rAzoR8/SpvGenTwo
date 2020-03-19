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

		HeapCallable() : Callable<Func>(HeapAllocator::instance()) {}

		template <typename Functor>
		HeapCallable(const Functor& f) : Callable<Func>(HeapAllocator::instance(), f) {}

		template <typename Functor>
		HeapCallable(Functor&& f) : Callable<Func>(HeapAllocator::instance(), spvgentwo::stdrep::move(f)) {}

		virtual ~HeapCallable() override = default;
	};
} // !spvgentwo