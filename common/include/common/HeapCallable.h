#pragma once

#include "Callable.h"
#include "HeapAllocator.h"

namespace spvgentwo
{
	template <typename T>
	class HeapCallable;

	template <typename Func>
	class HeapCallable : public Callable<Func>
	{
	public:
		using Callable<Func>::Callable;

		HeapCallable(const HeapCallable& _other) noexcept : Callable<Func>(_other){}

		HeapCallable(HeapCallable&& _other) noexcept : Callable<Func>(stdrep::move(_other)) {}

		template <typename ...Args>
		HeapCallable(Args&& ... _args) : Callable<Func>(HeapAllocator::instance(), stdrep::forward<Args>(_args)...) {}

		//template <typename Functor>
		//HeapCallable(const Functor& f) : Callable<Func>(HeapAllocator::instance(), f) {}

		//template <typename Obj, typename ReturnType, typename ... Args>
		//HeapCallable(Obj* _obj, ReturnType(Obj::* _func)(Args...)) : Callable<Func>(HeapAllocator::instance(), _func, _obj) {}

		//template <typename Functor>
		//HeapCallable(Functor&& f) : Callable<Func>(HeapAllocator::instance(), spvgentwo::stdrep::move(f)) {}

		virtual ~HeapCallable() override = default;

		HeapCallable& operator=(const HeapCallable& _other) { Callable<Func>::operator=(_other); return *this; }
		HeapCallable& operator=(HeapCallable&& _other) noexcept { Callable<Func>::operator=(stdrep::move(_other)); return *this; }
	};

	template <typename ReturnType, typename... Args>
	auto make_callable(ReturnType(*_func)(Args...))
	{
		return Callable<ReturnType(Args...)>(HeapAllocator::instance(), _func);
	}

	template <typename ReturnType, typename... Args>
	auto make_callable(ReturnType(*_func)(Args..., ...))
	{
		return Callable<ReturnType(Args..., ...)>(HeapAllocator::instance(), _func);
	}

	template <typename Obj, typename ReturnType, typename... Args>
	auto make_callable(Obj* _obj, ReturnType(Obj::*_func)(Args...))
	{
		return Callable<ReturnType(Args...)>(HeapAllocator::instance(), _obj, _func);
	}

	template <typename Obj, typename ReturnType, typename... Args>
	auto make_callable(Obj* _obj, ReturnType(Obj::*_func)(Args..., ...))
	{
		return Callable<ReturnType(Args..., ...)>(HeapAllocator::instance(), _obj, _func);
	}

	// fallback
	template <typename Func>
	auto make_callable(const Func& _func)
	{
		return HeapCallable<Func>(_func);
	}

	template <typename Obj, typename Func>
	auto make_callable(Obj* _pObj, const Func& _func)
	{
		return HeapCallable<Func>(_pObj, _func);
	}

} // !spvgentwo