#pragma once

namespace spvgentwo
{
	class IWriter
	{
	public:
		// append spv word to the output stream
		virtual void put(unsigned int word) = 0;
	};
} // !spvgentwo