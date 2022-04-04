#pragma once

namespace spvgentwo
{
	namespace detail
	{
		template <class ... TEnum>
		constexpr unsigned int bit_or( TEnum ... _enum) 
		{
			return ( ... | static_cast<unsigned int>(_enum));
		}

		template <class ... TEnum>
		constexpr unsigned int bit_xor (TEnum ... _enum)
		{
			return (... ^ static_cast<unsigned int>(_enum));
		}

		template <class ... TEnum>
		constexpr unsigned int bit_and(TEnum ... _enum)
		{
			return (... & static_cast<unsigned int>(_enum));
		}
	} // !detail

	template <class Enum>
	struct Flag
	{
		static_assert(sizeof(Enum) <= sizeof(unsigned int), "Enum type does not fit into mask");

		// can not be explicit because otherwise aggregate init wont work
		constexpr Flag(unsigned int _mask = 0u) : mask{ _mask } {}

		// prohibit bad conversions
		template <class PtrT>
		Flag(const PtrT*) = delete;

		Flag(bool) = delete;

		template <class ... TEnum>
		constexpr Flag(Enum _first, TEnum ... _enums) : mask{ detail::bit_or(_first, _enums...) } { }

		template <class ... TEnum>
		static constexpr Flag OR(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_or(_first, _enums...)); }

		template <class ... TEnum>
		static constexpr Flag XOR(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_xor(_first, _enums...)); }

		template <class ... TEnum>
		static constexpr Flag AND(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_and(_first, _enums...)); }

		template <class ... TEnum>
		void set(Enum _first, TEnum ... _enums)
		{
			mask |= detail::bit_or(_first, _enums...);
		}

		constexpr operator bool() const { return mask != 0u; }
		constexpr operator unsigned int() const { return mask; }
		constexpr operator Enum() const { return static_cast<Enum>(mask); }
		constexpr bool empty() const { return mask == 0u; }

		template <class ... TEnum> // check if any of the enum flags is set
		constexpr bool any(Enum _first, TEnum ... _enums) const { return (mask & detail::bit_or(_first, _enums...)) != 0u; }
		template <class ... TEnum> // check if none of the enum flags is set
		constexpr bool none(Enum _first, TEnum ... _enums) const { return (mask & detail::bit_or(_first, _enums...)) == 0u; }
		template <class ... TEnum> // check if all of the enum flags is set
		constexpr bool all(Enum _first, TEnum ... _enums) const { return (mask & detail::bit_or(_first, _enums...)) == detail::bit_or(_first, _enums...); }

		Flag<Enum>& operator|=(const Flag<Enum>& r) { mask |= r.mask; return *this; }
		Flag<Enum>& operator&=(const Flag<Enum>& r) { mask &= r.mask; return *this; }
		Flag<Enum>& operator^=(const Flag<Enum>& r) { mask ^= r.mask; return *this; }

		Flag<Enum>& operator|=(const Enum& r) { mask |= static_cast<unsigned int>(r); return *this; }
		Flag<Enum>& operator&=(const Enum& r) { mask &= static_cast<unsigned int>(r); return *this; }
		Flag<Enum>& operator^=(const Enum& r) { mask ^= static_cast<unsigned int>(r); return *this; }

	protected:
		unsigned int mask;
	};

	template<class Enum>
	constexpr Flag<Enum> operator|(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::OR(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator&(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::AND(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator^(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::XOR(l, r); }

	template<class Enum>
	constexpr Flag<Enum> operator|(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::OR(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator&(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::AND(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator^(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::XOR(l, r); }

	template<class Enum>
	constexpr Flag<Enum> operator|( const Enum& l, const Flag<Enum>& r ) { return Flag<Enum>::OR( l, r ); }
	template<class Enum>
	constexpr Flag<Enum> operator&( const Enum& l, const Flag<Enum>& r ) { return Flag<Enum>::AND( l, r ); }
	template<class Enum>
	constexpr Flag<Enum> operator^( const Enum& l, const Flag<Enum>& r ) { return Flag<Enum>::XOR( l, r ); }
} // !spvgentwo