#include "spvgentwo/Logger.h"
#include "spvgentwo/Module.h"
#include "spvgentwo/Grammar.h"

#include "common/HeapAllocator.h"
#include "common/BinaryFileReader.h"
#include "common/ConsoleLogger.h"
#include "common/ReflectionHelper.h"
#include "common/GrammarHelper.h"
#include "common/HeapList.h"
#include "common/HeapString.h"
#include "common/HeapHashMap.h"
#include "common/ModuleToString.h"
#include "common/VulkanInterop.h"
#include "common/ExternalMemoryAllocator.h"

#include <cstring> // strcmp
#include <cstdio> // printf, note windows console, and others too, don't print SPIR-V's UTF-8 strings properly
#include <cstdlib> // strtoul

using namespace spvgentwo;

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

auto g_instrPrinter = ModuleSimpleFuncPrinter([](const char* _pStr) { printf("%s", _pStr); });

template <class Pred, class Func>
void map(const List<const Instruction*>& instructions, Pred pred, Func func)
{
	for (const Instruction* instr : instructions)
	{
		if (pred(instr))
		{
			func(instr);
		}
	}
}

template <template <class> class Container>
void getList(const Container<Instruction>& _container, List<const Instruction*>& _instructions)
{
	for (const Instruction& instr : _container)
	{
		_instructions.emplace_back(&instr);
	}
}

void printFunctions(const Module& _module, const Grammar& gram)
{
	for (const EntryPoint& ep : _module.getEntryPoints())
	{
		if (const char** shaderType = ExecutionModelNames[ep.getExecutionModel()]; shaderType != nullptr)
		{
			printf("%s [EP %s]\n", ep.getName(), *shaderType);		
		}

		for (const Operand& op : ep.getInterfaceVariables())
		{
			if (const Instruction* var = op.getInstruction(); var != nullptr)
			{
				if (const char* name = var->getName(); name != nullptr)
				{
					printf("\t%s\t", name);
				}

				printInstruction(*var, gram, g_instrPrinter, false);
				printf("\n");
			}
		}
	}

	for (const Function& fun : _module.getFunctions())
	{
		printf("%s\n", fun.getName());
	}
}

void printDecorations(const List<Instruction>& _targets, const Grammar& _gram, bool _printDescriptorType)
{
	HeapList<const Instruction*> decorations;

	for (const Instruction& target : _targets)
	{
		decorations.clear();
		ReflectionHelper::getDecorations(&target, decorations);

		if (const char* name = target.getName(); name != nullptr)
		{
			printf("%s:\n", name);		
		}
		else
		{
			printf("[UNNAMED]:\n");
		}

		printf("\t");
		printInstruction(target, _gram, g_instrPrinter, false);
		printf("\n");

		if (target == spv::Op::OpVariable && _printDescriptorType)
		{
			if (auto it = DescriptorTypeNames.find(vk::getDescriptorTypeFromVariable(target)); it != DescriptorTypeNames.end())
			{
				printf("\t%s\n", it->value);
			}
		}
		
		for (const Instruction* deco : decorations)
		{
			spv::Decoration spvDeco{};
			unsigned int value = sgt_uint32_max;
			if (ReflectionHelper::getSpvDecorationAndLiteralFromDecoration(deco, spvDeco, value))
			{
				if (auto it = DecorationNames.find(spvDeco); it != DecorationNames.end())				
				{
					if (value != sgt_uint32_max)
					{
						printf("\t%s \t%u\n", it->value, value);					
					}
					else // no literal value for this decoration
					{
						printf("\t%s\n", it->value);
					}
				}
			}
		}
	}
}

int main(int argc, char* argv[])
{
	ConsoleLogger logger;

	const char* spv = nullptr;
	const char* varName = nullptr; // variable to inspect

	HeapList<spv::Decoration> decorationsToPrint;

	bool listFunctions = false;
	bool listVariables = false;
	bool listTypeAndConstants = false;
	bool printVKDescriptorType = false;
	spv::Id idToPrint = InvalidId;

	const int end = argc - 1;;

	for (int i = 1u; i < argc; ++i)
	{
		const char* arg = argv[i];
		if (spv == nullptr)
		{
			spv = arg;
		}
		else if (i < end && strcmp(arg, "--id") == 0)
		{
			idToPrint = strtoul(argv[++i], nullptr, 10);
		}
		else if (i < end && strcmp(arg, "--var") == 0)
		{
			varName = argv[++i];
		}
		else if (i < end && strcmp(arg, "--deco") == 0)
		{
			const char* input = argv[++i];

			for (const auto& [deco, str] : DecorationNames)
			{
				if (strcmp(str, input) == 0)
				{
					decorationsToPrint.emplace_back(deco);
				}
			}
		}
		else if (strcmp(arg, "--funcs") == 0)
		{
			listFunctions = true;
		}
		else if (strcmp(arg, "--vars") == 0)
		{
			listVariables = true;
		}
		else if (strcmp(arg, "--types") == 0)
		{
			listTypeAndConstants = true;
		}
		else if (strcmp(arg, "--desc") == 0)
		{
			printVKDescriptorType = true;
		}
	}

	if (spv == nullptr)
	{
		return -1;
	}

	HeapAllocator alloc;

	BinaryFileReader reader(spv);
	if (reader.isOpen() == false)
	{
		logger.logError("Failed to open %s", spv);
		return -1;
	}

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

	// parses strings for lookup of named instructions, needed for printing
	if (module.reconstructNames() == false)
	{
		return -1;
	}

	// get type info for vulkan descriptor lookup help
	if (module.reconstructTypeAndConstantInfo() == false)
	{
		return -1;
	}

	if (idToPrint != InvalidId)
	{
		if (const Instruction* instr = module.getInstructionById(idToPrint); instr != nullptr)
		{
			printInstruction(*instr, gram, g_instrPrinter);
			printf("\n");
		}
		else
		{
			logger.logWarning("Instruction with Id %u not found in module", idToPrint);
		}
	}

	if (listFunctions)
	{
		printf("Functions:\n");
		printFunctions(module, gram);
	}

	if (listVariables)
	{
		printf("Global Variables:\n");
		printDecorations(module.getGlobalVariables(), gram, printVKDescriptorType);
	}

	if (listTypeAndConstants)
	{
		printf("Types and Constants:\n");
		printDecorations(module.getTypesAndConstants(), gram, false);
	}

	List<const Instruction*> decorations(&alloc);

	if (varName != nullptr)
	{
		const Instruction* instr = module.getInstructionByName(varName);

		if (instr == nullptr)
		{
			logger.logWarning("Instruction with OpName %s not found in module", varName);
			return -1;
		}

		if (printVKDescriptorType)
		{
			if (auto it = DescriptorTypeNames.find(vk::getDescriptorTypeFromVariable(*instr)); it != DescriptorTypeNames.end())
			{
				printf("%s\n", it->value);
			}
		}

		ReflectionHelper::getDecorations(instr, decorations);
	}
	else
	{
		getList(module.getDecorations(), decorations);
	}

	if (decorations.empty() == false)
	{
		printf("Decorations:\n");
	}

	for (const Instruction* inst : decorations)
	{
		for (spv::Decoration deco : decorationsToPrint)
		{
			if (auto value = ReflectionHelper::getLiteralFromDecoration(deco, inst); value != sgt_uint32_max)
			{
				printf("%u\n", value);
			}
		}
	}
	
	return 0;
}