#include "FunctionCall.h"
#include "GLSL450Instruction.h"

using namespace spvgentwo;
using namespace ext;

Module examples::functionCall(IAllocator* _pAllocator, ILogger* _pLogger)
{
    // create a new spir-v module
    Module module(spv::Version, _pAllocator, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Shader);
    module.addCapability(spv::Capability::VulkanMemoryModelKHR);
    module.addExtension("SPV_KHR_vulkan_memory_model");
    Instruction* ext = module.getExtensionInstructionImport("GLSL.std.450");
    module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

    // global variables
    Instruction* uniformVar = module.uniform<vector_t<float, 3>>("u_Position");

    // float add(float x, float y)
    Function& funcAdd = module.addFunction<float, float, float>("add", spv::FunctionControlMask::Const);
    {
        BasicBlock& bb = *funcAdd; // get entry block to this function

        Instruction* x = funcAdd.getParameter(0);
        Instruction* y = funcAdd.getParameter(1);

        Instruction* z = bb.Add(x, y);
        bb.returnValue(z);
    }

    // void entryPoint();
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        Instruction* uniVec = bb->opLoad(uniformVar);
        Instruction* cross = bb.ext<GLSL>()->opCross(uniVec, uniVec); // use GLSL.std.450 extension
        Instruction* s = bb->opDot(cross, uniVec);
        entry->call(&funcAdd, s, s); // call add(s, s)
        entry->opReturn();
    }

    return module;
}
