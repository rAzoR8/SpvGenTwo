#include "Extensions.h"

#include "spvgentwo/GLSL450Instruction.h"

using namespace spvgentwo;
using namespace ext;

spvgentwo::Module examples::extensions(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::Version, spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR, _pLogger);
   
    module.addCapability(spv::Capability::Shader);

    module.addCapability(spv::Capability::VulkanMemoryModelKHR);
    module.addExtension("SPV_KHR_vulkan_memory_model");
    Instruction* ext = module.getExtensionInstructionImport("GLSL.std.450");

    // void entryPoint();
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        Instruction* vec3 = module.constant(make_vector(1.f, 2.f, 3.f));

        Instruction* cross = bb.ext<GLSL>()->opCross(vec3, vec3); // use GLSL.std.450 extension
       
        entry->opReturn();
    }

	return module;
}
