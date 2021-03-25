#pragma once

namespace spvgentwo
{
	// forward decls
	class Function;

	namespace LinkerHelper
	{
		// turn function definition into a declaration by removing its basic blocks and instruction decorates/names from the module
		bool removeFunctionBody(Function& _func);
	} // !LinkerHelper
} // spvgentwo