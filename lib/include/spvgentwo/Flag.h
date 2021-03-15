#pragma once

namespace spvgentwo
{
	template <class Enum>
	struct Flag
	{
		Flag(Enum _enum) : enumeration(_enum) {}
		Flag(unsigned int _mask = 0u) : mask(_mask) {}

		template <class ... TEnum>
		void set(Enum _first, TEnum ... _enum)
		{
			mask |= static_cast<unsigned int>(_first);

			if constexpr (sizeof...(_enum) > 0)
			{
				set(_enum...);
			}
		}

		template <class ... TEnum>
		Flag(TEnum ... _enum) { set(_enum...); }

		union
		{
			unsigned int mask;
			Enum enumeration;
		};

		operator bool() const { return mask != 0u; }
		operator unsigned int() const { return mask; }
		operator Enum() const { return enumeration; }

		Flag<Enum>& operator|=(const Flag<Enum>& r) { mask |= r.mask; return *this; }
		Flag<Enum>& operator&=(const Flag<Enum>& r) { mask &= r.mask; return *this; }
		Flag<Enum>& operator^=(const Flag<Enum>& r) { mask ^= r.mask; return *this; }

		Flag<Enum>& operator|=(const Enum& r) { mask |= static_cast<unsigned int>(r); return *this; }
		Flag<Enum>& operator&=(const Enum& r) { mask &= static_cast<unsigned int>(r); return *this; }
		Flag<Enum>& operator^=(const Enum& r) { mask ^= static_cast<unsigned int>(r); return *this; }
	};

	template<class Enum>
	Flag<Enum> operator|(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask | r.mask); }
	template<class Enum>
	Flag<Enum> operator&(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask & r.mask); }
	template<class Enum>
	Flag<Enum> operator^(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask ^ r.mask); }

	template<class Enum>
	Flag<Enum> operator|(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>(l.mask | static_cast<unsigned int>(r)); }
	template<class Enum>
	Flag<Enum> operator&(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>(l.mask & static_cast<unsigned int>(r)); }
	template<class Enum>
	Flag<Enum> operator^(const Flag<Enum>& l, const Enum& r) { return Flag<Enum>(l.mask ^ static_cast<unsigned int>(r)); }
} // !spvgentwo