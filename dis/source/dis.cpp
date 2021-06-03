#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "common/HeapAllocator.h"
#include "common/BinaryFileWriter.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ModulePrinter.h"

#include <cstring>
#include <cstdio>

using namespace spvgentwo;
using namespace ModulePrinter;

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	logger.logInfo("SpvGenTwoDisassembler by Fabian Wahlster - https://github.com/rAzoR8/SpvGenTwo");

	const char* spv = nullptr;
	const char* tabs = "\t\t";
	bool serialize = false; // for debugging
	bool reassignIDs = false;
	bool colors = false;

	PrintOptions options{ PrintOptionsBits::All };

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (strcmp(arg, "-serialize") == 0)
		{
			serialize = true;
		}
		else if (strcmp(arg, "-assignIDs") == 0 || strcmp(arg, "-assignids") == 0)
		{
			reassignIDs = true;
		}
		else if (strcmp(arg, "-noinstrnames") == 0)
		{
			options ^= PrintOptionsBits::InstructionName;
		}
		else if (strcmp(arg, "-noopnames") == 0)
		{
			options ^= PrintOptionsBits::OperandName;
		}
		else if (strcmp(arg, "-nopreamble") == 0)
		{
			options ^= PrintOptionsBits::Preamble;
		}
		else if (strcmp(arg, "-colors") == 0)
		{
			colors = true;
		}
		else if (i+1 < argc && strcmp(arg, "-tabs") == 0)
		{
			tabs = argv[++i];
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	if (BinaryFileReader reader(alloc, spv); reader)
	{
		Module module(&alloc, &logger);
		Grammar gram(&alloc);

		// parse the binary instructions & operands
		if (module.readAndInit(reader, gram) == false)
		{
			return -1;
		}

		if (reassignIDs)
		{
			module.assignIDs(); // compact ids
		}

		auto printer = ModulePrinter::ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr);	}, colors);
		const bool success = ModulePrinter::printModule(module, gram, printer, options, tabs);

		if (success == false)
		{
			return -1;
		}

		if (serialize)
		{
			if (BinaryFileWriter writer(alloc, "serialized.spv"); writer.isOpen())
			{
				module.finalizeAndWrite(writer);
			}
		}
	}
	else
	{
		logger.logError("Failed to open %s", spv);
	}

	return 0;
}