#include "Parsing.h"
#include "spvgentwo/Grammar.h"

using namespace spvgentwo;

spvgentwo::Module examples::parsing(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger, spvgentwo::IReader* _pReader)
{
	Module module(_pAllocator, spv::Version, _pLogger);

	Grammar gram(_pAllocator);
	module.read(_pReader, gram);

	return module;
}
