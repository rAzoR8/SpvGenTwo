#pragma once

namespace spvgentwo
{
	class IReader
	{
	public:
		// return value TRUE indicates success, FALSE fail or EOF
		virtual bool get(unsigned int& _word) = 0;
		virtual bool getAt(unsigned int& _word, const long _offset) = 0;

		// total size
		virtual long total() = 0;
	};
} // !spvgentwo