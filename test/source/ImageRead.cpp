#include "test/Modules.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module test::imageRead( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger )
{
	Module module(_pAllocator, _pLogger);

    module.addCapability(spvgentwo::spv::Capability::Shader);
    module.setSpvVersion(1, 5);

    //glsl:
    //  layout(set = 0, binding = 0, rgba8) uniform image2D myImg;
    dyn_image_t imgDesc;
    imgDesc.sampledType = dyn_scalar_t{ spvgentwo::spv::Op::OpTypeFloat, 32u };
    imgDesc.dimension = spvgentwo::spv::Dim::Dim2D;
    imgDesc.format = spvgentwo::spv::ImageFormat::Rgba8;
    imgDesc.samplerAccess = SamplerImageAccess::Storage;

    Instruction* const pImageRGBA8 = module.uniformConstant("myImg", imgDesc);

    module.addDecorationInstr()->opDecorate(
        pImageRGBA8, spvgentwo::spv::Decoration::DescriptorSet, 0);
    module.addDecorationInstr()->opDecorate(pImageRGBA8, spvgentwo::spv::Decoration::Binding, 0);

    // void main(); entry point
    {
        EntryPoint& entry =
            module.addEntryPoint(spvgentwo::spv::ExecutionModel::GLCompute, "main");
        entry.addExecutionMode(spvgentwo::spv::ExecutionMode::LocalSize, 256, 1, 1);
        BasicBlock& bb = *entry;  // get entry block to this function
        auto        imageRGBA8 = bb->opLoad(pImageRGBA8);
        auto        pUV = entry.variable<vector_t<int, 2>>();
        auto        uv = bb->opLoad(pUV);
        bb->opImageRead(imageRGBA8, uv);
        bb.returnValue();
    }

    return module;
}
