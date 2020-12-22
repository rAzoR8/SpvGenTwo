#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

#include "common/HeapAllocator.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"

#include <cstring>

using namespace spvgentwo;

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	const char* varName = nullptr; // variable to inspect

	bool printDescriptorSet = false;

	const int end = argc - 1;;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (i < end && strcmp(arg, "--var") == 0)
		{
			varName = argv[i + 1];
		}
		else if (strcmp(arg, "--dset") == 0)
		{
			printDescriptorSet = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	if (BinaryFileReader reader(spv); reader.isOpen())
	{
		Module module(&alloc, spv::Version, &logger);
		Grammar gram(&alloc);

		// parse the binary instructions & operands
		if (module.read(&reader, gram) == false)
		{
			return -1;
		}

		// turn <id> operands into instruction pointers
		if (module.resolveIDs() == false)
		{
			return -1;
		}

		//// creates type & constant infos for lookup (needed for codegen)
		//if (module.reconstructTypeAndConstantInfo() == false)
		//{
		//	return -1;
		//}

		// parses strings for lookup of named instructions, needed for printing
		if (module.reconstructNames() == false)
		{
			return -1;
		}
	}
	else
	{
		logger.logError("Failed to open %s", spv);
	}

	return 0;
}