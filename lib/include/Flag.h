#pragma once

namespace spvgentwo
{
	template <class Enum>
	struct Flag
	{
		Flag(Enum _enum) : enumeration(_enum) {}
		Flag(unsigned int _mask = 0u) : mask(_mask) {}

		union
		{
			unsigned int mask;
			Enum enumeration;
		};

		operator unsigned int() const { return mask; }
		operator Enum() const { return enumeration; }
	};

	template<class Enum>
	Flag<Enum> operator|(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask | r.mask); }
	template<class Enum>
	Flag<Enum> operator&(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask & r.mask); }
	template<class Enum>
	Flag<Enum> operator^(const Flag<Enum>& l, const Flag<Enum>& r) { return Flag<Enum>(l.mask ^ r.mask); }

	template<class Enum>
	Flag<Enum> operator|(const Flag<Enum>& l, const unsigned int& r) { return Flag<Enum>(l.mask | r); }
	template<class Enum>
	Flag<Enum> operator&(const Flag<Enum>& l, const unsigned int& r) { return Flag<Enum>(l.mask & r); }
	template<class Enum>
	Flag<Enum> operator^(const Flag<Enum>& l, const unsigned int& r) { return Flag<Enum>(l.mask ^ r); }
} // !spvgentwo