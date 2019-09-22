#pragma once
#include <cstddef>

namespace spvgentwo
{
	class IWriter
	{
	public:
		// returns the current offset after writing the word
		virtual long put(unsigned int word) = 0;

		virtual void putAt(unsigned int word, const long _offset) = 0;
	};
} // !spvgentwo