#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	template <typename ReturnType, typename... Args>
	struct Func
	{
		using FuncType = ReturnType(*)(Args...);
		FuncType pFn = nullptr;

		operator bool() const { return pFn != nullptr; }

		template <typename ... OtherArgs>
		ReturnType operator()(OtherArgs... _args) const { return (*pFn)(_args...); }
	};

	template <typename ReturnType, typename... Args>
	auto maker_func(ReturnType(*_func)(Args...))
	{
		return Func<ReturnType, Args...> {_func};
	}

	template <typename Obj, typename ReturnType, typename... Args>
	struct MemberFunc
	{
		using FuncType = ReturnType(Obj::*)(Args...);
		FuncType pFn = nullptr;
		Obj* pObj = nullptr;

		operator bool() const { return pFn != nullptr; }

		ReturnType operator()(Args... _args) const { return (pObj->*pFn)(_args...); }
	};

	template <typename Obj, typename ReturnType, typename... Args>
	auto make_memeber_func(Obj* _obj, ReturnType(Obj::* _func)(Args...))
	{
		return MemberFunc<Obj, ReturnType, Args...> {_obj, _func};
	}

	template <typename ReturnType, typename... Args>
	struct VariadicFunc
	{
		using FuncType = ReturnType(*)(Args..., ...);
		FuncType pFn = nullptr;

		operator bool() const { return pFn != nullptr; }

		template <typename ... OtherArgs>
		ReturnType operator()(OtherArgs... _args) const { return (*pFn)(_args...); }
	};

	template <typename ReturnType, typename... Args>
	auto maker_variadic_func(ReturnType(*_func)(Args..., ...))
	{
		return VariadicFunc<ReturnType, Args...> {_func};
	}

	template <typename Obj, typename ReturnType, typename... Args>
	struct VariadicMemberFunc
	{
		using FuncType = ReturnType(Obj::*)(Args..., ...);
		FuncType pFn = nullptr;
		Obj* pObj = nullptr;

		operator bool() const { return pFn != nullptr; }

		template <typename ... OtherArgs>
		ReturnType operator()(OtherArgs... _args) const { return (pObj->*pFn)(_args...); }
	};

	template <typename Obj, typename ReturnType, typename... Args>
	auto make_variadic_memeber_func(Obj* _obj, ReturnType(Obj::* _func)(Args..., ...))
	{
		return VariadicMemberFunc<Obj, ReturnType, Args...> {_obj, _func};
	}

	template <typename T>
	class Callable;

	template <typename ReturnType, typename... Args>
	class Callable<ReturnType(Args...)>
	{
		struct ICallable
		{
			virtual ~ICallable() = default;
			virtual ReturnType invoke(Args...) = 0;
			virtual ICallable* copy(IAllocator* _pAllocator) const = 0;
		};

		template <typename Functor>
		struct CallableImpl : public ICallable
		{
			// consume anything that constructs the functor
			template <typename ... ImplArgs>
			CallableImpl(ImplArgs&& ... _args) noexcept: m_func{ stdrep::forward<ImplArgs>(_args)... } {}

			virtual ~CallableImpl() override = default;

			ReturnType invoke(Args... args) final
			{
				return m_func(stdrep::forward<Args>(args)...);
			}

			ICallable* copy(IAllocator* _pAllocator) const final
			{
				return _pAllocator->construct<CallableImpl<Functor>>(m_func);
			}

		private:
			Functor m_func;
		};

	private:

		IAllocator* m_pAllocator = nullptr;
		ICallable* m_pCallable = nullptr;

	public:

		using FuncType = ReturnType(Args...);

		Callable(IAllocator* _pAllocator = nullptr) : 
			m_pAllocator(_pAllocator)
		{}

		template <typename Functor>
		Callable(IAllocator* _pAllocator, const Functor& f) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<Functor>>(f))
		{}

		template <typename Functor>
		Callable(IAllocator* _pAllocator, Functor&& f) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<Functor>>(spvgentwo::stdrep::move(f)))
		{}

		Callable(IAllocator* _pAllocator, ReturnType(*_func)(Args...)) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<Func<ReturnType, Args...>>>(_func))
		{
		}

		template <typename Obj>
		Callable(IAllocator* _pAllocator, Obj* _obj, ReturnType(Obj::* _func)(Args...)) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<MemberFunc<Obj, ReturnType, Args...>>>(_func, _obj))
		{
		}

		Callable(const Callable& _other) :
			m_pAllocator(_other.m_pAllocator)
		{
			if (_other.m_pCallable != nullptr && m_pAllocator != nullptr)
			{
				m_pCallable = _other.m_pCallable->copy(_other.m_pAllocator);
			}
		}

		Callable(Callable&& _other) noexcept:
			m_pAllocator(_other.m_pAllocator),
			m_pCallable(_other.m_pCallable)
		{	
			_other.m_pAllocator = nullptr;
			_other.m_pCallable = nullptr;
		}

		template <typename Functor>
		Callable& operator=(const Functor& f)
		{
			reset();
			m_pCallable = m_pAllocator->construct<CallableImpl<Functor>>(f);
			return *this;
		}

		template <typename Functor>
		Callable& operator=(Functor&& f) noexcept
		{
			reset();
			m_pCallable = m_pAllocator->construct<CallableImpl<Functor>>(stdrep::move(f));
			return *this;
		}

		Callable& operator=(const Callable& _other)
		{
			reset();
			m_pAllocator = _other.m_pAllocator;
			m_pCallable = _other.m_pCallable->copy(m_pAllocator);
			return *this;
		}

		Callable& operator=(Callable&& _other)
		{
			reset();
			m_pAllocator = _other.m_pAllocator;
			m_pCallable = _other.m_pCallable;
			_other.m_pAllocator = nullptr;
			_other.m_pCallable = nullptr;
			return *this;
		}

		ReturnType operator()(Args... args) const
		{
			return m_pCallable->invoke(stdrep::forward<Args>(args)...);
		}

		operator bool() const { return m_pCallable != nullptr; }

		void reset()
		{
			if (m_pAllocator != nullptr && m_pCallable != nullptr)
			{
				m_pAllocator->destruct(m_pCallable);
				m_pCallable = nullptr;
			}
		}

		virtual ~Callable()
		{
			reset();
		}
	};

	// member functions maps to regular callable
	template <typename ReturnType, typename Obj, typename... Args>
	class Callable<ReturnType(Obj::*)(Args...)> : public Callable<ReturnType(Args...)>
	{
		using Callable<ReturnType(Args...)>::Callable;
		virtual ~Callable() { Callable::reset(); }
	};

	// variadic variant
	template <typename ReturnType, typename... Args>
	class Callable<ReturnType(Args..., ...)>
	{
		VariadicFunc<ReturnType, Args...> m_func{};

	public:
		using FuncType = ReturnType(Args..., ...);

		Callable(const Callable& _other) : m_func{ _other.m_func } {}
		Callable(Callable&& _other) : m_func{ stdrep::move(_other.m_func) } {}
		Callable(ReturnType(*_func)(Args..., ...)) : m_func{ _func }{}

		// consume alloctor without using it
		Callable(spvgentwo::IAllocator* _pAllocator, ReturnType(*_func)(Args..., ...)) : m_func{ _func }	{}

		virtual ~Callable() {}

		template <typename ...OtherArgs>
		ReturnType operator()(OtherArgs... _args){	return m_func(_args...); }

		Callable& operator=(const Callable& _other) { m_func = _other.m_func; return *this; }
		Callable& operator=(Callable&& _other) { m_func = stdrep::move(_other.m_func); return *this; }
		Callable& operator=(ReturnType(*_func)(Args..., ...)) { m_func.pFn = _func; return *this; }
	};

	// free function
	template <typename ReturnType, typename... Args>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, ReturnType(*_func)(Args...))
	{
		return Callable<ReturnType(Args...)>(_pAllocator, _func);
	}

	// free variadic function
	template <typename ReturnType, typename... Args>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, ReturnType(*_func)(Args..., ...))
	{
		return Callable<ReturnType(Args..., ...)>(_pAllocator, _func);
	}

	// member function
	template <typename Obj, typename ReturnType, typename... Args>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, Obj* _obj, ReturnType(Obj::*_func)(Args...))
	{
		return Callable<ReturnType(Args...)>(_pAllocator, _func, _obj);
	}

	// variadic member function
	template <typename Obj, typename ReturnType, typename... Args>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, Obj* _obj, ReturnType(Obj::* _func)(Args..., ...))
	{
		return Callable<ReturnType(Args..., ...)>(_pAllocator, _func, _obj);
	}

	// fallback
	template <typename Func>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, const Func& _func)
	{
		return Callable<Func>(_pAllocator, _func);
	}

	// member fallback
	template <typename Obj, typename Func>
	auto make_callable(spvgentwo::IAllocator* _pAllocator, Obj* _pObj, const Func& _func)
	{
		return Callable<Func>(_pAllocator, _pObj, _func);
	}
} //! spvgentwo