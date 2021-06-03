#include "example/FragmentShader.h"
#include "spvgentwo/TypeAlias.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module examples::fragmentShader(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
    // create a new spir-v module
    Module module(_pAllocator, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Shader);

    // global variables
    Instruction* uniColor = module.uniform<glsl::vec4>(u8"u_color", module.constant(make_vector(0.f, 0.f, 0.f, 1.f))); // use initializer
    Instruction* uniTex = module.uniform(u8"u_baseColor", dyn_sampled_image_t{}); //default 2d float texture
    Instruction* inUV = module.input<glsl::vec2>(u8"v_inUV"); // varying input UVs

    // void main(); entry point
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        Instruction* mask = bb->opLoad(uniColor);
        Instruction* alphaMask = bb->opVectorExtractDynamic(mask, module.constant(3u)); // extract alpha channel

        Instruction* color = bb->opLoad(uniTex);
        Instruction* uv = bb->opLoad(inUV);

        Instruction* baseColor = bb->opImageSampleImplictLod(color, uv);
        Instruction* alpha = bb->opVectorExtractDynamic(baseColor, module.constant(3u)); // extract alpha channel

        Instruction* cond = bb->Less(alpha, alphaMask);
		BasicBlock& merge = bb.If(cond, [](BasicBlock& trueBB)
			{
                trueBB->opKill(); // discard pixel if baseColor.a < u_color.a
			});

        merge.returnValue();
    }

    return module;
}