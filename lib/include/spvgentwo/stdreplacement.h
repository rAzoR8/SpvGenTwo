#pragma once

// replacement header for some std functions and traits

#include <cstddef>

#ifdef SPVGENTWO_REPLACE_PLACEMENTNEW
#pragma warning(disable: 4291)
template <class T>
inline void* operator new(size_t size, T* ptr) noexcept { (void)size; return ptr; }
#else
#include <new>
#endif

#ifndef SPVGENTWO_REPLACE_TRAITS
#include <type_traits>
#include <utility>
namespace spvgentwo::stdrep
{
	using namespace ::std;
}
#else
namespace spvgentwo::stdrep
{
	template <class... _Types>
	using void_t = void;

	template <class T, T Val>
	struct integral_constant
	{
		static constexpr T value = Val;

		using value_type = T;
		using type = integral_constant;

		constexpr operator value_type() const noexcept {
			return value;
		}

		[[nodiscard]] constexpr value_type operator()() const noexcept {
			return value;
		}
	};

	template <bool Val>
	using bool_constant = integral_constant<bool, Val>;

	using true_type = bool_constant<true>;
	using false_type = bool_constant<false>;

	template <bool cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { using type = T; };

	template <bool cond, class T = void>
	using enable_if_t = typename enable_if<cond, T>::type;

	template <class>
	inline constexpr bool is_pointer_v = false;

	template <class T>
	inline constexpr bool is_pointer_v<T*> = true;

	template <class T>
	struct remove_pointer { using type = T; };
	template <class T>
	struct remove_pointer<T*> { using type = T; };
	template <class T>
	struct remove_pointer<T**> { using type = T; };

	template <class T>
	using remove_pointer_t = typename remove_pointer<T>::type;

	template <class>
	inline constexpr bool is_lvalue_reference_v = false;

	template <class T>
	inline constexpr bool is_lvalue_reference_v<T&> = true;

	template <class T>
	struct remove_reference { using type = T; };
	template <class T>
	struct remove_reference<T&> { using type = T; };
	template <class T>
	struct remove_reference<T&&> { using type = T; };

	template <class T>
	using remove_reference_t = typename remove_reference<T>::type;

	template <class T>
	[[nodiscard]] constexpr T&& forward(remove_reference_t<T>& _Arg) noexcept
	{
		return static_cast<T&&>(_Arg);
	}

	template <class T>
	[[nodiscard]] constexpr T&& forward(remove_reference_t<T>&& _Arg) noexcept
	{
		static_assert(!is_lvalue_reference_v<T>, "forward of lvalue");
		return static_cast<T&&>(_Arg);
	}

	template <class T>
	[[nodiscard]] constexpr remove_reference_t<T>&& move(T&& _Arg) noexcept
	{
		return static_cast<remove_reference_t<T>&&>(_Arg);
	}

	template <class, class>
	inline constexpr bool is_same_v = false;
	template <class T>
	inline constexpr bool is_same_v<T, T> = true;

	template <class T>
	struct remove_const { using type = T; };

	template <class T>
	struct remove_const<const T> { using type = T; };

	template <class T>
	using remove_const_t = typename remove_const<T>::type;

	template <class T>
	struct remove_volatile { using type = T; };

	template <class T>
	struct remove_volatile<volatile T> { using type = T; };

	template <class T>
	using remove_volatile_t = typename remove_volatile<T>::type;

	template <class T>
	struct remove_cv { using type = T; };
	template <class T>
	struct remove_cv<const T> { using type = T; };
	template <class T>
	struct remove_cv<volatile T> { using type = T; };
	template <class T>
	struct remove_cv<const volatile T> { using type = T; };
	template <class T>
	using remove_cv_t = typename remove_cv<T>::type;

	template <class>
	inline constexpr bool is_const_v = false;

	template <class T>
	inline constexpr bool is_const_v<const T> = true;

	namespace detail {

		template <class T>
		struct type_identity { using type = T; };

		template <class T>
		auto try_add_lvalue_reference(int)->type_identity<T&>;
		template <class T>
		auto try_add_lvalue_reference(...)->type_identity<T>;

		template <class T>
		auto try_add_rvalue_reference(int)->type_identity<T&&>;
		template <class T>
		auto try_add_rvalue_reference(...)->type_identity<T>;

	} // namespace detail

	template <class T>
	struct add_lvalue_reference : decltype(detail::try_add_lvalue_reference<T>(0)) {};

	template <class T>
	struct add_rvalue_reference : decltype(detail::try_add_rvalue_reference<T>(0)) {};

	template <class T>
	using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

	template <class T>
	using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

	template<class T>
	typename add_rvalue_reference<T>::type declval() noexcept;

	namespace detail
	{
		template <class, class T, class... Args>
		struct is_constructible_impl : false_type {};

		template <class T, class... Args>
		struct is_constructible_impl<void_t<decltype(T(declval<Args>()...))>, T, Args...> : true_type {};
	}

	template <class T, class... Args>
	using is_constructible = detail::is_constructible_impl<void_t<>, T, Args...>;

	template <class T, class... Args>
	inline constexpr bool is_constructible_v = is_constructible<T, Args...>::value;
} // !spvgentwo::stdrep
#endif

// custom traits
namespace spvgentwo::traits
{
	template <class T> inline constexpr bool is_primitive_type_v = false;
	template <>	inline constexpr bool is_primitive_type_v<bool> = true;
	template <>	inline constexpr bool is_primitive_type_v<short> = true;
	template <>	inline constexpr bool is_primitive_type_v<unsigned short> = true;
	template <>	inline constexpr bool is_primitive_type_v<int> = true;
	template <>	inline constexpr bool is_primitive_type_v<unsigned int> = true;
	template <>	inline constexpr bool is_primitive_type_v<long> = true;
	template <>	inline constexpr bool is_primitive_type_v<unsigned long> = true;
	template <>	inline constexpr bool is_primitive_type_v<long long> = true;
	template <>	inline constexpr bool is_primitive_type_v<unsigned long long> = true;
	template <>	inline constexpr bool is_primitive_type_v<float> = true;
	template <>	inline constexpr bool is_primitive_type_v<double> = true;

	// cpp20
	template <class T>
	using remove_cvref_t = stdrep::remove_cv_t<stdrep::remove_reference_t<T>>;
	template <class T>
	struct remove_cvref { using type = remove_cvref_t<T>; };

	//custom
	template <class T>
	using remove_cvref_ptr_t = stdrep::remove_cv_t<stdrep::remove_reference_t<stdrep::remove_pointer_t<T>>>;
	template <class T>
	struct remove_cvref_ptr { using type = remove_cvref_ptr_t<T>; };

	template <class T, class BASE>
	inline constexpr bool is_same_base_type_v = stdrep::is_same_v<remove_cvref_t<T>, BASE>;

	template <class F, class... Args>
	struct is_invocable
	{
		template <class U>
		static auto test(U* p) -> decltype((*p)(stdrep::declval<Args>()...), void(), stdrep::true_type());
		template <class U>
		static auto test(...) -> decltype(stdrep::false_type());

		static constexpr bool value = decltype(test<F>(0))::value;
	};

	template <class F, class... Args>
	inline constexpr bool is_invocable_v = is_invocable<F, Args...>::value;

	template <class T>
	const T* selectTypeFromArgs() { return nullptr; }

	template <class T, class First, class... Args>
	const T* selectTypeFromArgs(First& _first, Args&... _tail)
	{
		if constexpr (is_same_base_type_v<First, T>)
		{
			return &_first; // todo: implement addressof
		}
		else if constexpr (sizeof...(_tail) > 0)
		{
			return selectTypeFromArgs<T>(_tail...);
		}
		else
		{
			return nullptr;
		}
	}

	template <class T>
	T& to_ref(T& _ref) { return _ref; }

	template <class T>
	T& to_ref(T* _ptr) { return *_ptr; }

	template <int N, int I, class Element, class... Args>
	auto selectNthElement(Element&& elem, Args&& ... args)
	{
		if constexpr (I == N)
		{
			return elem;
		}
		else if constexpr (sizeof...(args) > 0)
		{
			return selectNthElement<N, I + 1>(stdrep::forward<Args>(args)...);
		}
	}

	template<class T, class ...Args>
	T* constructWithArgs(T* _ptr, Args&& ..._args)
	{
		if constexpr (stdrep::is_constructible_v<T, Args...>)
		{
			return new(_ptr) T(stdrep::forward<Args>(_args)...);
		}
		else
		{
			return new(_ptr) T{ stdrep::forward<Args>(_args)... };
		}
	}
} // !spvgentw