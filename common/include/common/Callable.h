#pragma once

#include "spvgentwo/Allocator.h"

namespace spvgentwo
{
	template <typename Obj, typename ReturnType, typename... Args>
	struct MemberFunc
	{
		using MemberFuncType = ReturnType(Obj::*)(Args...);
		Obj* pObj = nullptr;
		MemberFuncType pMemberFn = nullptr;

		ReturnType operator()(Args... _args) const { return (pObj->*pMemberFn)(_args...); }
	};

	template <typename Obj, typename ReturnType, typename... Args>
	auto make_memeber_func(Obj* _obj, ReturnType(Obj::* _func)(Args...))
	{
		return MemberFunc<Obj, ReturnType, Args...> {_obj, _func};
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
			virtual ICallable* copy(spvgentwo::IAllocator* _pAllocator) const = 0;
		};

		template <typename Functor>
		struct CallableImpl : public ICallable
		{
			CallableImpl(const Functor& t) : m_func(t) {}
			CallableImpl(Functor&& t) noexcept : m_func(stdrep::move(t)) {}
			CallableImpl(const CallableImpl& _other) : m_func(_other.m_func) {}
			CallableImpl(CallableImpl&& _other) noexcept : m_func(stdrep::move(_other.m_func)) {}

			template <typename ... ImplArgs>
			CallableImpl(ImplArgs&& ... _args) : m_func{ stdrep::forward<ImplArgs>(_args)... } {}

			virtual ~CallableImpl() override = default;

			ReturnType invoke(Args... args) final
			{
				return m_func(spvgentwo::stdrep::forward<Args>(args)...);
			}

			ICallable* copy(spvgentwo::IAllocator* _pAllocator) const final
			{
				return _pAllocator->construct<CallableImpl<Functor>>(m_func);
			}

		private:
			Functor m_func;
		};

	public:

		Callable(spvgentwo::IAllocator* _pAllocator = nullptr) : 
			m_pAllocator(_pAllocator)
		{}

		template <typename Functor>
		Callable(spvgentwo::IAllocator* _pAllocator, const Functor& f) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<Functor>>(f))
		{}

		template <typename Functor>
		Callable(spvgentwo::IAllocator* _pAllocator, Functor&& f) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<Functor>>(spvgentwo::stdrep::move(f)))
		{}

		template <typename Obj>
		Callable(spvgentwo::IAllocator* _pAllocator, Obj* _obj, ReturnType(Obj::* _func)(Args...)) :
			m_pAllocator(_pAllocator),
			m_pCallable(_pAllocator->construct<CallableImpl<MemberFunc<Obj, ReturnType, Args...>>>(_obj, _func))
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
			m_pCallable = m_pAllocator->construct<CallableImpl<Functor>>(spvgentwo::stdrep::move(f));
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
			return m_pCallable->invoke(spvgentwo::stdrep::forward<Args>(args)...);
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

	private:

		spvgentwo::IAllocator* m_pAllocator = nullptr;
		ICallable* m_pCallable = nullptr;
	};
} //! spvgentwo