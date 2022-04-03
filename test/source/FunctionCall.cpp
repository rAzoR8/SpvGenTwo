#include "example/FunctionCall.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

Module examples::functionCall(IAllocator* _pAllocator, ILogger* _pLogger)
{
    // create a new spir-v module
    Module module(_pAllocator, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Shader);

    // global variables
    Instruction* uniformVar = module.uniform<vector_t<float, 3>>(u8"u_Position");

    // float add(float x, float y)
    Function& funcAdd = module.addFunction<float, float, float>(u8"add", spv::FunctionControlMask::Const);
    {
        BasicBlock& bb = *funcAdd; // get entry block to this function

        Instruction* x = funcAdd.getParameter(0);
        Instruction* y = funcAdd.getParameter(1);

        Instruction* z = bb.Add(x, y);
        bb.returnValue(z);
    }

    // void entryPoint();
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        Instruction* uniVec = bb->opLoad(uniformVar);        
        Instruction* s = bb->opDot(uniVec, uniVec);
        entry->call(&funcAdd, s, s); // call add(s, s)
        entry->opReturn();
    }

    return module;
}
