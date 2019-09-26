#pragma once

// replacement header for some std functions and traits

#include <cstddef>

#ifndef DONT_REPLACE_PLACEMENTNEW
inline void* operator new(size_t size, void* ptr) noexcept { (void)size; return ptr; }
#else
#include <new>
#endif

//#include <type_traits>

#ifdef DONT_REPLACE_TRAITS
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
	struct enable_if<true, T> {	using type = T;	};

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
	struct remove_reference { using type = T;};
	template <class T>
	struct remove_reference<T&> {using type = T;};
	template <class T>
	struct remove_reference<T&&> { using type = T;};

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
	struct remove_cv { using type = T; };
	template <class T>
	struct remove_cv<const T> { using type = T; };
	template <class T>
	struct remove_cv<volatile T> { using type = T; };
	template <class T>
	struct remove_cv<const volatile T> { using type = T; };
	template <class T>
	using remove_cv_t = typename remove_cv<T>::type;
} // !spvgentwo::stdrep
#endif

// custom traits
namespace spvgentwo
{
	// cpp20
	template <class T>
	using remove_cvref_t = stdrep::remove_cv_t<stdrep::remove_reference_t<T>>;
	template <class T>
	struct remove_cvref { using type = remove_cvref_t<T>; };

	template <class T, class BASE>
	inline constexpr bool is_same_base_type_v = stdrep::is_same_v<remove_cvref_t<T>, BASE>;
} // !spvgentwo