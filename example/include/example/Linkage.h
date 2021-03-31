#pragma once

#include "spvgentwo/Module.h"

namespace examples
{
	spvgentwo::Module linkageLib(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);

	spvgentwo::Module linkageConsumer(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);

	spvgentwo::Module linkageLinked(const spvgentwo::Module& _lib, spvgentwo::Module& _consumer, spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);
} // !examples
