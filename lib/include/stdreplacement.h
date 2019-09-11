#pragma once

#include <stddef.h>

// replacement for some std functions and traits

#ifndef DONT_REPLACE_PLACEMENTNEW
inline void* operator new(size_t size, void* ptr) noexcept { (void)size; return ptr; }
#else
#include <new>
#endif

#ifdef DONT_REPLACE_TRAITS
#include <utility>
namespace spvgentwo
{
	using namespace std;
}
#else
namespace spvgentwo
{
	template <class>
	/*inline*/ constexpr bool is_lvalue_reference_v = false;

	template <class T>
	/*inline*/ constexpr bool is_lvalue_reference_v<T&> = true;

	template <class T>
	struct remove_reference { using type = T;};
	template <class T>
	struct remove_reference<T&> {using type = T;};
	template <class T>
	struct remove_reference<T&&> { using type = T;};

	template <class T>
	using remove_reference_t = typename remove_reference<T>::type;

	template <class T>
	/*[[nodiscard]]*/ constexpr T&& forward(remove_reference_t<T>& _Arg) noexcept {
		return static_cast<T&&>(_Arg);
	}

	template <class T>
	/*[[nodiscard]]*/ constexpr T&& forward(remove_reference_t<T>&& _Arg) noexcept { 
		static_assert(!is_lvalue_reference_v<T>, "forward of lvalue");
		return static_cast<T&&>(_Arg);
	}
} // !spvgentwo
#endif