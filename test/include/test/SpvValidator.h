#pragma once

#include "spvgentwo/Module.h"

namespace test
{
	class SpvValidator
	{
	public:
		SpvValidator();

		bool validate( const spvgentwo::Module& _module );
	};
}