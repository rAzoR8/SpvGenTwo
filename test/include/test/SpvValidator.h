#pragma once

#include "spvgentwo/Module.h"

namespace test
{
	class SpvValidator
	{
	public:
		SpvValidator(const spvgentwo::Grammar& _gram);

		bool validate( const spvgentwo::Module& _module );
	private:
		const spvgentwo::Grammar& m_gram;
	};
}