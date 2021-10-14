#pragma once

// replacement header for some std functions and traits

namespace spvgentwo 
{
	using sgt_size_t = decltype(sizeof(int));
	using sgt_nullptr_t = decltype(nullptr);

	constexpr sgt_size_t sgt_size_max = ~(sgt_size_t)0u;
	constexpr auto sgt_uint32_max = ~0u;
	constexpr auto sgt_uint64_max = ~0ull;

	using sgt_uint32_t = decltype(0u);
	using sgt_uint64_t = decltype(0ull);

	using sgt_int32_t = decltype(0);
	using sgt_int64_t = decltype(0ll);

	static_assert(sizeof(sgt_uint32_t) == 4, "32bit integer type size mismatch");
	static_assert(sizeof(sgt_uint64_t) == 8, "64bit integer type size mismatch");
}

#ifdef SPVGENTWO_REPLACE_PLACEMENTNEW

#if _MSC_VER && !__INTEL_COMPILER
#pragma warning(disable: 4291)
#endif

template <class T>
inline void* operator new(spvgentwo::sgt_size_t size, T* ptr) noexcept { (void)size; return ptr; }
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

	template<bool B, class T, class F>
	struct conditional { using type = T; };

	template<class T, class F>
	struct conditional<false, T, F> { using type = F; };

	template< bool B, class T, class F >
	using conditional_t = typename conditional<B, T, F>::type;

	template<class...> struct conjunction : true_type { };
	template<class B1> struct conjunction<B1> : B1 { };
	template<class B1, class... Bn> struct conjunction<B1, Bn...> : conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

	template<class... B>
	inline constexpr bool conjunction_v = conjunction<B...>::value;

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

	template<class T, class U>
	struct is_same : false_type {};

	template<class T>
	struct is_same<T, T> : true_type {};

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

	template <class>
	inline constexpr bool is_reference_v = false;

	template <class T>
	inline constexpr bool is_reference_v<T&> = true;

	template <class T>
	inline constexpr bool is_reference_v<T&&> = true;

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

		template <class T>
		auto try_add_pointer(int)->type_identity<typename remove_reference<T>::type*>;
		template <class T>
		auto try_add_pointer(...)->type_identity<T>;

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

	template <class T>
	struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};

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

	template <class T>
	using is_copy_constructible = is_constructible<T, add_lvalue_reference_t<T>>;

	template <class T>
	inline constexpr bool is_copy_constructible_v = is_copy_constructible<T>::value;

	template <class T>
	using is_move_constructible = is_constructible<T, add_rvalue_reference_t<T>>;

	template <class T>
	inline constexpr bool is_move_constructible_v = is_move_constructible<T>::value;

	template <typename T, typename U, typename = void>
	struct is_assignable : false_type {};

	template <typename T, typename U>
	struct is_assignable<T, U, decltype(declval<add_lvalue_reference_t<T>>() = declval<U>(), void())> : true_type {};

	template <typename T, typename U>
	inline constexpr bool is_assignable_v = is_assignable<T, U>::value;

	template <class T, class U = T>
	struct is_move_assignable : is_assignable< T, add_rvalue_reference_t<U>> {};

	template<typename T, typename U = T>
	inline constexpr bool is_move_assignable_v = is_move_assignable<T, U>::value;

	template<class T>
	struct is_function : integral_constant<bool, !is_const_v<const T> && !is_reference_v<T>> {};

	template<class T>
	inline constexpr bool is_function_v = is_function<T>::value;

	template<class T>
	struct remove_extent { typedef T type; };

	template<class T>
	struct remove_extent<T[]> { typedef T type; };

	template<class T, sgt_size_t N>
	struct remove_extent<T[N]> { typedef T type; };

	template <class>
	inline constexpr bool is_array_v = false;

	template <class T>
	inline constexpr bool is_array_v<T[]> = true;

	template< class T >
	struct decay
	{
	private:
		typedef typename remove_reference<T>::type U;
	public:
		typedef typename conditional<
			is_array_v<U>,
			typename remove_extent<U>::type*,
			typename conditional<
			is_function_v<U>,
			typename add_pointer<U>::type,
			typename remove_cv<U>::type
			>::type
		>::type type;
	};

	template< class T >
	using decay_t = typename decay<T>::type;
} // !spvgentwo::stdrep
#endif

// custom traits
namespace spvgentwo::traits
{
	template <class T> inline constexpr bool is_primitive_type_v = false;
	template <>	inline constexpr bool is_primitive_type_v<bool> = true;
	template <>	inline constexpr bool is_primitive_type_v<char> = true;
	template <>	inline constexpr bool is_primitive_type_v<unsigned char> = true;
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
	constexpr const T* selectTypeFromArgs() { return nullptr; }

	template <class T, class First, class... Args>
	constexpr const T* selectTypeFromArgs([[maybe_unused]] First& _first, [[maybe_unused]] Args&... _tail)
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
	constexpr T& to_ref(T& _ref) { return _ref; }

	template <class T>
	constexpr T& to_ref(T* _ptr) { return *_ptr; }

	template <int N, int I, class Element, class... Args>
	constexpr auto selectNthElement(Element&& elem, Args&& ... args)
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
	constexpr T* constructWithArgs(T* _ptr, Args&& ..._args)
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

	namespace detail
	{
		template <class T, sgt_uint64_t = sizeof(T)> // sizeof can only be applied to complete types
		constexpr stdrep::true_type is_complete_type(T*);
		constexpr stdrep::false_type is_complete_type(...);
	}

	template <class T>
	using is_complete_t = decltype(detail::is_complete_type(stdrep::declval<T*>()));

	template <class T>
	constexpr bool is_complete_v = is_complete_t<T>::value;

} // !spvgentwo::traits