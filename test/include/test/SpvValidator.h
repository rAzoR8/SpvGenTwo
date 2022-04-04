#pragma once

#include "spvgentwo/Module.h"

namespace test
{
	class SpvValidator
	{
	public:
		SpvValidator( spvgentwo::ILogger* _pLogger );

		bool validate( const spvgentwo::Module& _module );
	private:
		spvgentwo::ILogger* m_pLogger;
	};
}