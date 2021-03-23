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
	const char* out = nullptr;
	const char* patchspv = nullptr;

	// import/export target
	struct Target
	{
		Instruction* instr = nullptr;
		const char* name = nullptr;
		spv::LinkageType type = spv::LinkageType::Max;
	};
	
	HeapList<Target> targets;
	HeapList<Module> libs;

	HeapAllocator alloc;
	ConsoleLogger logger;
	Grammar gram(&alloc);

	Module patchModule(&alloc, spv::Version, &logger);

	int i = 1u;
	auto addTarget = [&](spv::LinkageType type)
	{
		Instruction* instr = nullptr;
		const char* target = argv[++i];
		if (auto id = strtoul(target, nullptr, 10); id != 0 && id != sgt_uint32_max)
		{
			instr = patchModule.getInstructionById(spv::Id{ id });
		}
		else
		{
			instr = patchModule.getInstructionByName(target);
		}

		if (instr == nullptr)
		{
			logger.logError("Could not find %s in %s", target, patchspv);
			return;
		}

		if (const char* name = argv[++i]; name != nullptr)
		{
			targets.emplace_back(instr, name, type);
		}
	};

	for (; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (i + 1 < argc && strcmp(arg, "--patchspv") == 0)
		{
			patchspv = argv[++i];
			BinaryFileReader reader(patchspv);
			if (reader.isOpen() == false)
			{
				logger.logError("Failed to open %s", patchspv);
				return -1;
			}
			else if (patchModule.readAndInit(&reader, gram) == false)
			{
				return -1;
			}
		}
		else if (i + 1 < argc && strcmp(arg, "--l") == 0)
		{
			const char* file = argv[++i];
			BinaryFileReader reader(file);
			if (reader.isOpen() == false)
			{
				logger.logError("Failed to open %s", file);
				return -1;
			}
			else if (libs.emplace_back(&alloc, spv::Version, &logger).readAndInit(&reader, gram) == false)
			{
				return -1;
			}
		}
		else if (i + 1 < argc && strcmp(arg, "--out") == 0)
		{
			out = argv[++i];
		}
		else if (i + 1 < argc && strcmp(arg, "--export") == 0)
		{
			addTarget(spv::LinkageType::Export);
		}
		else if (i + 1 < argc && strcmp(arg, "--import") == 0)
		{
			addTarget(spv::LinkageType::Import);
		}
	}

	auto printer = ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr); });

	if (targets.empty() == false)
	{
		patchModule.checkAddCapability(spv::Capability::Linkage);

		for (auto& t : targets)
		{
			Instruction* instr = patchModule.addDecorationInstr();
			instr->opDecorate(t.instr, spv::Decoration::LinkageAttributes, t.name, t.type);
			printer << "Added "; printInstruction(*instr, gram, printer); printer << "\n";
		}

		if (out == nullptr)
		{
			out = patchspv;
		}

		BinaryFileWriter writer(out);
		if (writer.isOpen() == false)
		{
			logger.logError("Failed to open %s", out);
			return -1;
		}

		patchModule.write(&writer);
	}

	return 0;
}