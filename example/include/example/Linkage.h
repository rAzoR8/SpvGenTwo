#pragma once

#include "spvgentwo/Module.h"

namespace examples
{
	spvgentwo::Module linkageLibA(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);

	spvgentwo::Module linkageLibB(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);

	spvgentwo::Module linkageConsumer(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);

	bool linkageLinked(const spvgentwo::Module& _libA, const spvgentwo::Module& _libB, spvgentwo::Module& _consumer, spvgentwo::IAllocator* _pAllocator, const spvgentwo::Grammar* _pGrammar);
} // !examples
