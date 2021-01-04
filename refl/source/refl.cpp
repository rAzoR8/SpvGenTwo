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

#include <cstring> // strcmp
#include <cstdio> // printf, note windows console, and others too, don't print SPIR-V's UTF-8 strings properly

using namespace spvgentwo;

const HeapHashMap<spv::Decoration, const char*> DecorationNames(
	spv::Decoration::RelaxedPrecision, "RelaxedPrecision",
	spv::Decoration::SpecId, "SpecId",
	spv::Decoration::Block, "Block",
	spv::Decoration::BufferBlock, "BufferBlock",
	spv::Decoration::RowMajor, "RowMajor",
	spv::Decoration::ColMajor, "ColMajor",
	spv::Decoration::ArrayStride, "ArrayStride",
	spv::Decoration::MatrixStride, "MatrixStride",
	spv::Decoration::GLSLShared, "GLSLShared",
	spv::Decoration::GLSLPacked, "GLSLPacked",
	spv::Decoration::CPacked, "CPacked",
	spv::Decoration::BuiltIn, "BuiltIn",
	spv::Decoration::NoPerspective, "NoPerspective",
	spv::Decoration::Flat, "Flat",
	spv::Decoration::Patch, "Patch",
	spv::Decoration::Centroid, "Centroid",
	spv::Decoration::Sample, "Sample",
	spv::Decoration::Invariant, "Invariant",
	spv::Decoration::Restrict, "Restrict`",
	spv::Decoration::Aliased, "Aliased",
	spv::Decoration::Volatile, "Volatile",
	spv::Decoration::Constant, "Constant",
	spv::Decoration::NonWritable, "NonWritable",
	spv::Decoration::NonReadable, "NonReadable",
	spv::Decoration::Uniform, "Uniform",
	spv::Decoration::UniformId, "UniformId",
	spv::Decoration::SaturatedConversion, "SaturatedConversion",
	spv::Decoration::Stream, "Stream",
	spv::Decoration::Location, "Location",
	spv::Decoration::Component, "Component",
	spv::Decoration::Index, "Index",
	spv::Decoration::Binding, "Binding",
	spv::Decoration::DescriptorSet, "DescriptorSet",
	spv::Decoration::Offset, "Offset",
	spv::Decoration::XfbBuffer, "XfbBuffer",
	spv::Decoration::XfbStride, "XfbStride",
	spv::Decoration::FuncParamAttr, "FuncParamAttr",
	spv::Decoration::FPRoundingMode, "FPRoundingMode",
	spv::Decoration::FPFastMathMode, "FPFastMathMode",
	spv::Decoration::LinkageAttributes, "LinkageAttributes",
	spv::Decoration::NoContraction, "NoContraction",
	spv::Decoration::InputAttachmentIndex, "InputAttachmentIndex",
	spv::Decoration::Alignment, "Alignment",
	spv::Decoration::MaxByteOffset, "MaxByteOffset",
	spv::Decoration::AlignmentId, "AlignmentId",
	spv::Decoration::MaxByteOffsetId, "MaxByteOffsetId"
);

const HeapHashMap<spv::ExecutionModel, const char*> ExecutionModelNames(
	spv::ExecutionModel::Vertex, "Vertex",
	spv::ExecutionModel::TessellationControl, "TessellationControl",
	spv::ExecutionModel::TessellationEvaluation, "TessellationEvaluation",
	spv::ExecutionModel::Geometry, "Geometry",
	spv::ExecutionModel::Fragment, "Fragment",
	spv::ExecutionModel::GLCompute, "GLCompute",
	spv::ExecutionModel::Kernel, "Kernel",
	spv::ExecutionModel::TaskNV, "TaskNV",
	spv::ExecutionModel::MeshNV, "MeshNV",
	spv::ExecutionModel::RayGenerationKHR, "RayGenerationKHR",
	spv::ExecutionModel::IntersectionKHR, "IntersectionKHR",
	spv::ExecutionModel::AnyHitKHR, "AnyHitKHR",
	spv::ExecutionModel::ClosestHitKHR, "ClosestHitKHR",
	spv::ExecutionModel::MissKHR, "MissKHR",
	spv::ExecutionModel::CallableKHR, "CallableKHR"
);

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

void printFunctions(const Module& _module)
{
	for (const EntryPoint& ep : _module.getEntryPoints())
	{
		if (const char** shaderType = ExecutionModelNames[ep.getExecutionModel()]; shaderType != nullptr)
		{
			printf("%s [EP %s]\n", ep.getName(), *shaderType);		
		}
	}

	for (const Function& fun : _module.getFunctions())
	{
		printf("%s\n", fun.getName());
	}
}

void printDecorations(const List<Instruction>& _targets)
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
		else if(decorations.empty() == false)
		{
			printf("[UNNAMED]:\n");
		}
		
		for (const Instruction* deco : decorations)
		{
			spv::Decoration spvDeco{};
			unsigned int value = ~0u;
			if (ReflectionHelper::getSpvDecorationAndLiteralFromDecoration(deco, spvDeco, value))
			{
				if (auto it = DecorationNames.find(spvDeco); it != DecorationNames.end())				
				{
					if (value != ~0u)
					{
						printf("\t%s \t %u\n", it->value, value);					
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

	if (listFunctions)
	{
		printFunctions(module);
	}

	if (listVariables)
	{
		printDecorations(module.getGlobalVariables());
	}

	if (listTypeAndConstants)
	{
		printDecorations(module.getTypesAndConstants());
	}

	List<const Instruction*> decorations(&alloc);

	if (varName != nullptr)
	{
		Instruction* inst = module.getInstructionByName(varName);

		if (inst == nullptr)
		{
			logger.logWarning("Instruction with OpName %s not found in module", varName);
			return -1;
		}

		ReflectionHelper::getDecorations(inst, decorations);
	}
	else
	{
		getList(module.getDecorations(), decorations);
	}

	for (const Instruction* inst : decorations)
	{
		for (spv::Decoration deco : decorationsToPrint)
		{
			if (auto value = ReflectionHelper::getLiteralFromDecoration(deco, inst); value != ~0u) 
			{
				printf("%u\n", value);
			}
		}
	}
	
	return 0;
}