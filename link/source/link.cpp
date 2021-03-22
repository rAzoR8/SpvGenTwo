#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Templates.h"

#include "common/BinaryFileReader.h"
#include "common/BinaryFileWriter.h"
#include "common/ConsoleLogger.h"
#include "common/HeapList.h"
#include "common/ModulePrinter.h"

#include <cstring> // strcmp
#include <cstdio> // printf, note windows console, and others too, don't print SPIR-V's UTF-8 strings properly
#include <cstdlib> // strtoul

using namespace spvgentwo;
using namespace ModulePrinter;

int main(int argc, char* argv[])
{
	const char* spv = nullptr;
	const char* out = nullptr;

	struct Target
	{
		Instruction* instr = nullptr;
		const char* name = nullptr;
		spv::LinkageType type = spv::LinkageType::Max;
	};
	
	HeapList<Target> targets;
	HeapAllocator alloc;
	ConsoleLogger logger;
	Module module(&alloc, spv::Version, &logger);
	Grammar gram(&alloc);

	const int end = argc - 1;;
	int i = 1u;

	auto addTarget = [&](spv::LinkageType type)
	{
		Instruction* instr = nullptr;
		if (auto id = strtoul(argv[++i], nullptr, 10); id != 0 && id != sgt_uint32_max)
		{
			instr = module.getInstructionById(spv::Id{ id });
		}
		else
		{
			instr = module.getInstructionByName(argv[i]);
		}

		if (const char* name = argv[++i]; instr != nullptr)
		{
			targets.emplace_back(instr, name, type);
		}
	};

	for (; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
			BinaryFileReader reader(spv);
			if (reader.isOpen() == false)
			{
				logger.logError("Failed to open %s", spv);
				return -1;
			}
			else if (module.readAndInit(&reader, gram) == false)
			{
				return -1;
			}
		}
		else if (i + 1 < end && strcmp(arg, "--out") == 0)
		{
			out = argv[++i];
		}
		else if (spv != nullptr && i + 1 < end && strcmp(arg, "--export") == 0)
		{
			addTarget(spv::LinkageType::Export);
		}
		else if (spv != nullptr && i + 1 < end && strcmp(arg, "--import") == 0)
		{
			addTarget(spv::LinkageType::Import);
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	auto printer = ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr); });

	if (targets.empty() == false)
	{
		module.checkAddCapability(spv::Capability::Linkage);
	}

	for (auto& t : targets)
	{
		Instruction* instr = module.addDecorationInstr();
		instr->opDecorate(t.instr, spv::Decoration::LinkageAttributes, t.name, t.type);
		printer << "Added "; printInstruction(*instr, gram, printer); printer << "\n";
	}
	
	BinaryFileWriter writer(out);
	if (writer.isOpen() == false) 
	{
		logger.logError("Failed to open %s", out);
		return -1;
	}

	module.write(&writer);

	return 0;
}