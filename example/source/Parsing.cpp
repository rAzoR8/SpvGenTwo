#include "Parsing.h"

using namespace spvgentwo;

spvgentwo::Module examples::parsing(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger, spvgentwo::IReader* _pReader)
{
	Module module(_pAllocator, spv::Version, _pLogger);

	// TODO: module.read(_pReader)

	return module;
}
