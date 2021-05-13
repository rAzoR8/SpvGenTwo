#pragma once

namespace spvgentwo
{
	class IReader
	{
	public:
		// return value TRUE indicates success, FALSE fail or EOF
		virtual bool get(unsigned int& _word) = 0;
		virtual ~IReader() = default;
	};
} // !spvgentwo