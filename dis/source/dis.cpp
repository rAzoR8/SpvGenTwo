#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ModuleToString.h"

#include <cstring>

#ifndef NDEBUG
#include <cstdlib> // system
#endif // !_NDEBUG

using namespace spvgentwo;

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	bool serialize = false; // for debugging
	bool reassignIDs = false;
	bool callSPIRVDis = false;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (strcmp(arg, "--serialize") == 0)
		{
			serialize = true;
		}
		else if (strcmp(arg, "--assignIDs") == 0 || strcmp(arg, "--assignids") == 0)
		{
			reassignIDs = true;
		}
		else if (strcmp(arg, "--calldis") == 0)
		{
			callSPIRVDis = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

#ifndef NDEBUG
	if (callSPIRVDis)
	{
		String cmd(&alloc, "spirv-dis ");
		cmd += spv;
		system(cmd.c_str());
	}
#endif

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

		// creates type & constant infos for lookup (needed for codegen)
		if (module.reconstructTypeAndConstantInfo() == false)
		{
			return -1;
		}

		// parses strings for lookup of named instructions, needed for printing
		if (module.reconstructNames() == false)
		{
			return -1;
		}

		if (reassignIDs)
		{
			module.assignIDs(); // compact ids
		}

		String buffer(&alloc, 2048u);
		ModuleStringPrinter printer(buffer, true);

		const bool success = moduleToString(module, gram, &alloc, &printer, true);

		printf("%s", buffer.c_str());

		if (success == false)
		{
			return -1;
		}

		if (serialize)
		{
			if (BinaryFileWriter writer("serialized.spv"); writer.isOpen())
			{
				module.write(&writer);
			}
		}
	}
	else
	{
		logger.logError("Failed to open %s", spv);
	}

	return 0;
}