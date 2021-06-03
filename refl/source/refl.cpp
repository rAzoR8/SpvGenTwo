#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

#include "common/HeapAllocator.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ReflectionHelper.h"
#include "common/HeapList.h"
#include "common/HeapHashMap.h"
#include "common/ModulePrinter.h"
#include "common/VulkanInterop.h"

#include <cstring> // strcmp
#include <cstdio> // printf, note windows console, and others too, don't print SPIR-V's UTF-8 strings properly
#include <cstdlib> // strtoul

using namespace spvgentwo;
using namespace ModulePrinter;

const HeapHashMap<spv::Decoration, const char*> DecorationNames(
	spv::Decoration::RelaxedPrecision, (const char*)"RelaxedPrecision",
	spv::Decoration::SpecId, (const char*)"SpecId",
	spv::Decoration::Block, (const char*)"Block",
	spv::Decoration::BufferBlock, (const char*)"BufferBlock",
	spv::Decoration::RowMajor, (const char*)"RowMajor",
	spv::Decoration::ColMajor, (const char*)"ColMajor",
	spv::Decoration::ArrayStride, (const char*)"ArrayStride",
	spv::Decoration::MatrixStride, (const char*)"MatrixStride",
	spv::Decoration::GLSLShared, (const char*)"GLSLShared",
	spv::Decoration::GLSLPacked, (const char*)"GLSLPacked",
	spv::Decoration::CPacked, (const char*)"CPacked",
	spv::Decoration::BuiltIn, (const char*)"BuiltIn",
	spv::Decoration::NoPerspective, (const char*)"NoPerspective",
	spv::Decoration::Flat, (const char*)"Flat",
	spv::Decoration::Patch, (const char*)"Patch",
	spv::Decoration::Centroid, (const char*)"Centroid",
	spv::Decoration::Sample, (const char*)"Sample",
	spv::Decoration::Invariant, (const char*)"Invariant",
	spv::Decoration::Restrict, (const char*)"Restrict`",
	spv::Decoration::Aliased, (const char*)"Aliased",
	spv::Decoration::Volatile, (const char*)"Volatile",
	spv::Decoration::Constant, (const char*)"Constant",
	spv::Decoration::NonWritable, (const char*)"NonWritable",
	spv::Decoration::NonReadable, (const char*)"NonReadable",
	spv::Decoration::Uniform, (const char*)"Uniform",
	spv::Decoration::UniformId, (const char*)"UniformId",
	spv::Decoration::SaturatedConversion, (const char*)"SaturatedConversion",
	spv::Decoration::Stream, (const char*)"Stream",
	spv::Decoration::Location, (const char*)"Location",
	spv::Decoration::Component, (const char*)"Component",
	spv::Decoration::Index, (const char*)"Index",
	spv::Decoration::Binding, (const char*)"Binding",
	spv::Decoration::DescriptorSet, (const char*)"DescriptorSet",
	spv::Decoration::Offset, (const char*)"Offset",
	spv::Decoration::XfbBuffer, (const char*)"XfbBuffer",
	spv::Decoration::XfbStride, (const char*)"XfbStride",
	spv::Decoration::FuncParamAttr, (const char*)"FuncParamAttr",
	spv::Decoration::FPRoundingMode, (const char*)"FPRoundingMode",
	spv::Decoration::FPFastMathMode, (const char*)"FPFastMathMode",
	spv::Decoration::LinkageAttributes, (const char*)"LinkageAttributes",
	spv::Decoration::NoContraction, (const char*)"NoContraction",
	spv::Decoration::InputAttachmentIndex, (const char*)"InputAttachmentIndex",
	spv::Decoration::Alignment, (const char*)"Alignment",
	spv::Decoration::MaxByteOffset, (const char*)"MaxByteOffset",
	spv::Decoration::AlignmentId, (const char*)"AlignmentId",
	spv::Decoration::MaxByteOffsetId, (const char*)"MaxByteOffsetId"
);

const HeapHashMap<spv::ExecutionModel, const char*> ExecutionModelNames(
	spv::ExecutionModel::Vertex, (const char*)"Vertex",
	spv::ExecutionModel::TessellationControl, (const char*)"TessellationControl",
	spv::ExecutionModel::TessellationEvaluation, (const char*)"TessellationEvaluation",
	spv::ExecutionModel::Geometry, (const char*)"Geometry",
	spv::ExecutionModel::Fragment, (const char*)"Fragment",
	spv::ExecutionModel::GLCompute, (const char*)"GLCompute",
	spv::ExecutionModel::Kernel, (const char*)"Kernel",
	spv::ExecutionModel::TaskNV, (const char*)"TaskNV",
	spv::ExecutionModel::MeshNV, (const char*)"MeshNV",
	spv::ExecutionModel::RayGenerationKHR, (const char*)"RayGenerationKHR",
	spv::ExecutionModel::IntersectionKHR, (const char*)"IntersectionKHR",
	spv::ExecutionModel::AnyHitKHR, (const char*)"AnyHitKHR",
	spv::ExecutionModel::ClosestHitKHR, (const char*)"ClosestHitKHR",
	spv::ExecutionModel::MissKHR, (const char*)"MissKHR",
	spv::ExecutionModel::CallableKHR, (const char*)"CallableKHR"
);

const HeapHashMap<vk::DescriptorType, const char*> DescriptorTypeNames(
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_SAMPLER, (const char*)"VK_DESCRIPTOR_TYPE_SAMPLER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, (const char*)"VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, (const char*)"VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, (const char*)"VK_DESCRIPTOR_TYPE_STORAGE_IMAGE",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, (const char*)"VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, (const char*)"VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, (const char*)"VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, (const char*)"VK_DESCRIPTOR_TYPE_STORAGE_BUFFER",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, (const char*)"VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, (const char*)"VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, (const char*)"VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT, (const char*)"VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR, (const char*)"VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR",
	vk::DescriptorType::VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV, (const char*)"VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV"
);

template <template <class> class Container, class Instr>
void getList(const Container<Instruction>& _container, List<Instr*>& _instructions)
{
	for (auto& instr : _container)
	{
		_instructions.emplace_back(&instr);
	}
}

void printFunctions(IModulePrinter& _printer, const Module& _module, const Grammar& _gram)
{
	auto printFnType = [&](const Function& _func)
	{
		if (const Instruction* instr = _func.getFunction(); instr != nullptr)
		{
			printInstruction(*instr, _gram, _printer, PrintOptions(PrintOptionsBits::OperationName, PrintOptionsBits::ResultId));
		}

		printf("\n"); // OpTypeFunction
		if (const Instruction* type = _func.getFunctionTypeInstr(); type != nullptr)
		{
			printInstruction(*type, _gram, _printer, PrintOptionsBits::All);
			printf("\n");

			for (auto it = type->getFirstActualOperand(); it != type->end(); ++it)
			{
				if (const Instruction* instr = it->getInstruction(); instr != nullptr)
				{
					printInstruction(*instr, _gram, _printer, PrintOptionsBits::All);
					printf("\n");
				}
			}
		}
		printf("\n");
	};

	for (const EntryPoint& ep : _module.getEntryPoints())
	{
		if (const char** shaderType = ExecutionModelNames[ep.getExecutionModel()]; shaderType != nullptr)
		{
			printf("%s [EP %s]\n", ep.getName(), *shaderType);		
		}
		if (const Instruction* instr = ep.getEntryPoint(); instr != nullptr)
		{
			printInstruction(*instr, _gram, _printer, PrintOptions(PrintOptionsBits::OperationName, PrintOptionsBits::ResultId));
		}
		printf("\n");

		printFnType(ep);

		for (const Operand& op : ep.getInterfaceVariables())
		{
			if (const Instruction* var = op.getInstruction(); var != nullptr)
			{
				printInstruction(*var, _gram, _printer, PrintOptions(PrintOptionsBits::OperationName, PrintOptionsBits::ResultId));
				if (const char* name = var->getName(); name != nullptr)
				{
					printf("\t[%s]", name);
				}
				printf("\n");
			}
		}
	}

	for (const Function& fun : _module.getFunctions())
	{
		printf("%s\n", fun.getName());

		printFnType(fun);
	}

	printf("\n");
}

void printVariable(IModulePrinter& _printer, const Instruction& _instr, const Grammar& _gram)
{
	if (const char* name = _instr.getName(); name != nullptr)
	{
		if (strcmp(name, "") != 0)
		{
			printf("%s:\t", name);
		}
		else
		{
			printf("[EMPTY]:\t");
		}
	}
	else
	{
		printf("[UNNAMED]:\t");
	}

	printInstruction(_instr, _gram, _printer, PrintOptions(PrintOptionsBits::OperationName, PrintOptionsBits::ResultId), "\t");

	if (_instr == spv::Op::OpVariable)
	{
		if (auto it = DescriptorTypeNames.find(vk::getDescriptorTypeFromVariable(_instr)); it != DescriptorTypeNames.end())
		{
			printf("\t[%s]", it->value);
		}
	}
}

void printDecorationsForTargets(IModulePrinter& _printer, const List<Instruction>& _targets, const Grammar& _gram)
{
	HeapList<Instruction*> decorations;

	for (const Instruction& target : _targets)
	{
		decorations.clear();
		ReflectionHelper::getDecorations(&target, decorations);

		printVariable(_printer, target, _gram);
		printf("\n");

		for (const Instruction* deco : decorations)
		{
			printInstruction(*deco, _gram, _printer, PrintOptions(PrintOptionsBits::OperationName, PrintOptionsBits::ResultId), "\t\t\t");
			printf("\n");
		}
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	logger.logInfo("SpvGenTwoReflector by Fabian Wahlster - https://github.com/rAzoR8/SpvGenTwo");

	const char* spv = nullptr;
	const char* varName = nullptr; // variable to inspect

	HeapList<spv::Decoration> decorationsToPrint;

	bool listFunctions = false;
	bool listVariables = false;
	bool listTypeAndConstants = false;
	bool listDecorations = false;
	bool printLocalSize = false;
	spv::Id idToPrint = InvalidId;
	bool colors = false;

	const int end = argc - 1;;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (i < end && strcmp(arg, "-id") == 0)
		{
			idToPrint = spv::Id{ static_cast<unsigned int>(strtoul(argv[++i], nullptr, 10)) };
		}
		else if (i < end && strcmp(arg, "-var") == 0)
		{
			varName = argv[++i];
		}
		else if (strcmp(arg, "-deco") == 0)
		{
			listDecorations = true;

			if (i < end)
			{
				const char* input = argv[i+1];

				bool validDeco = false;
				for (const auto& [deco, str] : DecorationNames)
				{
					if (strcmp(str, input) == 0)
					{
						decorationsToPrint.emplace_back(deco);
						validDeco = true;
						break;
					}
				}

				if (validDeco) // 2nd argument part was valid
				{
					++i;
				}
			}
		}
		else if (strcmp(arg, "-funcs") == 0)
		{
			listFunctions = true;
		}
		else if (strcmp(arg, "-vars") == 0)
		{
			listVariables = true;
		}
		else if (strcmp(arg, "-types") == 0)
		{
			listTypeAndConstants = true;
		}
		else if (strcmp(arg, "-localsize") == 0)
		{
			printLocalSize = true;
		}
		else if (strcmp(arg, "-colors") == 0)
		{
			colors = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	BinaryFileReader reader(alloc, spv);
	if (reader == false)
	{
		logger.logError("Failed to open %s", spv);
		return -1;
	}

	Module module(&alloc, &logger);
	Grammar gram(&alloc);

	// parse the binary instructions & operands
	if (module.readAndInit(reader, gram) == false)
	{
		return -1;
	}

	if (printLocalSize)
	{
		unsigned int x, y, z;
		if (ReflectionHelper::getLocalSize(module, x, y, z))
		{
			printf("LocalSize: x %u y %u z %u\n", x, y, z);
		}
		else
		{
			logger.logWarning("OpExecutionMode with LocalSize/LocalSizeHint not found in module");
		}
	}

	auto printer = ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr); }, colors);

	if (listFunctions)
	{
		printf("Functions:\n");
		printFunctions(printer, module, gram);
	}

	if (listVariables)
	{
		printf("Global Variables:\n");
		printDecorationsForTargets(printer, module.getGlobalVariables(), gram);
	}

	if (listTypeAndConstants)
	{
		printf("Types and Constants:\n");
		printDecorationsForTargets(printer, module.getTypesAndConstants(), gram);
	}

	const Instruction* instr = nullptr;

	if (varName != nullptr)
	{
		printf("%s:\n", varName);

		instr = module.getInstructionByName(varName);

		if (instr == nullptr)
		{
			logger.logWarning("Instruction with OpName %s not found in module", varName);
			return -1;
		}
	}
	else if (idToPrint != InvalidId)
	{
		instr = module.getInstructionById(idToPrint);

		if (instr == nullptr)
		{
			logger.logWarning("Instruction with Id %u not found in module", idToPrint);
			return -1;
		}
	}

	auto printDecorations = [&decorationsToPrint, &gram, &printer](const List<Instruction*>& _decorations)
	{
		for (const Instruction* decoInstr : _decorations)
		{
			if (decorationsToPrint.empty())
			{
				printInstruction(*decoInstr, gram, printer); printf("\n");
			}

			for (spv::Decoration decoToPrint : decorationsToPrint)
			{
				spv::Decoration outDeco{};
				unsigned int value = sgt_uint32_max;
				if (ReflectionHelper::getSpvDecorationAndLiteralFromDecoration(decoInstr, outDeco, value) && outDeco == decoToPrint)
				{
					printInstruction(*decoInstr, gram, printer); printf("\n");
				}
			}
		}
	};

	List<Instruction*> decorations(&alloc);

	if (listDecorations)
	{
		getList(module.getDecorations(), decorations);

		printf("Decorations:\n");

		printDecorations(decorations);

		printf("\n");
	}

	if (instr != nullptr)
	{
		printVariable(printer, *instr, gram);
		printf("\n");

		if (instr->hasResultType())
		{
			if (const Instruction* type = instr->getResultTypeInstr(); type != nullptr && type->isErrorInstr() == false)
			{
				printInstruction(*type, gram, printer); printf("\n");
			}
		}

		decorations.clear();
		ReflectionHelper::getDecorations(instr, decorations);

		printDecorations(decorations);
	}
	
	return 0;
}