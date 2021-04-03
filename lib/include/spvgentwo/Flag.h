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

		template <class ... TEnum>
		constexpr Flag(Enum _first, TEnum ... _enums) : mask{ detail::bit_or(_first, _enums...) } { }

		template <class ... TEnum>
		static constexpr Flag flagOR(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_or(_first, _enums...)); }

		template <class ... TEnum>
		static constexpr Flag flagXOR(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_xor(_first, _enums...)); }

		template <class ... TEnum>
		static constexpr Flag flagAND(Enum _first, TEnum ... _enums) { return static_cast<Enum>(detail::bit_and(_first, _enums...)); }

		template <class ... TEnum>
		void set(Enum _first, TEnum ... _enums)
		{
			mask |= detail::bitor(_first, _enums);
		}

		constexpr operator bool() const { return mask != 0u; }
		constexpr operator unsigned int() const { return mask; }
		constexpr operator Enum() const { return static_cast<Enum>(mask); }

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
	constexpr Flag<Enum> operator|(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::flagOR(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator&(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::flagAND(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator^(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>::flagXOR(l, r); }

	template<class Enum>
	constexpr Flag<Enum> operator|(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::flagOR(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator&(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::flagAND(l, r); }
	template<class Enum>
	constexpr Flag<Enum> operator^(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>::flagXOR(l, r); }
} // !spvgentwo