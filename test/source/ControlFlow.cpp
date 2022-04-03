#include "example/ControlFlow.h"
#include "spvgentwo/Operators.h"
#include "common/ControlFlowGraph.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;
using namespace ops;

spvgentwo::Module examples::controlFlow(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
    // create a new spir-v module
    Module module(_pAllocator, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Shader);
    module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::Simple);

    // uniforms
    Instruction* uniOffset = module.uniform<int>(u8"u_Offset");

    Function& loopFunc = module.addFunction<float>(u8"loop", spv::FunctionControlMask::Const);
    {
        Instruction* one = module.constant(1);
        Instruction* loopCount = module.constant(10);
        Instruction* varI = loopFunc.variable<int>(0);
        Instruction* varSum = loopFunc.variable<float>(1.1f);

        BasicBlock& merge = (*loopFunc).Loop([&](BasicBlock& cond) -> Instruction*
        {
            auto i = cond->opLoad(varI);
            return cond < loopCount; // cond is translated to the last used instruction -> i < loopCount
        }, [&](BasicBlock& inc)
        {
            auto i = inc->opLoad(varI);
            i = inc.Add(i, one);
            inc->opStore(varI, i); // i++
        }, [&](BasicBlock& body)
        {
            auto s = body->opLoad(varSum);
            s = body.Mul(s, s);
            body->opStore(varSum, s); // sum += sum
        });

        auto s = merge->opLoad(varSum);

        merge.returnValue(s);

        ControlFlowGraph<> cfg(loopFunc);
    }

    // void entryPoint();
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

        BasicBlock& bb = *entry;

        Instruction* offset = bb->opLoad(uniOffset);
        Instruction* value = bb->opLoad(entry.variable(42, "value")); // function scope variable

        Instruction* cond = bb.Less(offset, value); // offset < 42

        Instruction* res1 = nullptr;
        Instruction* res2 = nullptr;

        BasicBlock& merge = bb.If(cond, [&](BasicBlock& trueBB)
        {
            res1 = trueBB.Add(value, offset) * value;
        }, [&](BasicBlock& falseBB)
        {
            res2 = falseBB.Sub(value, offset);
        });

        Instruction* res = merge->opPhi(res1, res2);

        merge->call(&loopFunc);
        merge->opReturn();
    }

    return module;
}
