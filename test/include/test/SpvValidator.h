#pragma once

#include "spvgentwo/Module.h"

namespace tests
{
	class SpvValidator
	{
	public:
		SpvValidator( spvgentwo::ILogger* _pLogger );

		bool validate( const spvgentwo::Module& _module );
	};
}