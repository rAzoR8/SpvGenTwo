#pragma once

namespace spvgentwo
{
	class IReader
	{
	public:		
		virtual unsigned int get() = 0;
		virtual unsigned int getAt(const long _offset) = 0;

		// total size
		virtual long total() = 0;
	};
} // !spvgentwo