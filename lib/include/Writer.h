#pragma once

namespace spvgentwo
{
	class IWriter
	{
	public:
		virtual void put(unsigned int word) = 0;
	};
} // !spvgentwo