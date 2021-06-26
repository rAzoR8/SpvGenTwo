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
    module.addCapability(spv::Capability::StorageImageExtendedFormats);
    module.addCapability(spv::Capability::Float16);
    module.addCapability(spv::Capability::Int8);
    module.addCapability(spv::Capability::Kernel);

    // global variables
    Instruction* const uniColor = module.uniform<glsl::vec4>(u8"u_color", module.constant(make_vector(0.f, 0.f, 0.f, 1.f))); // use initializer
    Instruction* const uniTex = module.uniform(u8"u_baseColor", dyn_sampled_image_t{}); //default 2d float texture
    Instruction* const inUV = module.input<glsl::vec2>(u8"v_inUV"); // varying input UVs

    dyn_image_t imgDesc{ dyn_scalar_t{spv::Op::OpTypeFloat, 16u} };
    imgDesc.format = spv::ImageFormat::Rg16;
    Instruction* const uniImgRawRG16 = module.uniform(u8"u_imgRG16", imgDesc);

    imgDesc.format = spv::ImageFormat::Unknown;
    Instruction* const uniImageUnknownFmt = module.uniform(u8"u_imgUnknownFmt", dyn_sampled_image_t{ imgDesc });

    imgDesc.format = spv::ImageFormat::Rg32f;
    imgDesc.sampledType.bits = 32u;
    imgDesc.accessQualifier = spv::AccessQualifier::WriteOnly;
    imgDesc.samplerAccess = SamplerImageAccess::Unknown;
    Instruction* const uniImgRawStorageRG32 = module.uniform(u8"u_imgStorageRG32", imgDesc);

    // 3d volume tex
    imgDesc.dimension = spv::Dim::Dim3D;
    imgDesc.sampledType = { spv::Op::OpTypeInt, 8u };
    imgDesc.format = spv::ImageFormat::Rgba8ui;
    Instruction* const uni3DImgRawRGBA8 = module.uniform(u8"u_img3DRGABA8", imgDesc);

    Instruction* const constCoord2D = module.constant(make_vector(0u, 1u));
    Instruction* const constCoord3D = module.constant(make_vector(0u, 1u, 2u));
    
    // void main(); entry point
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        Instruction* mask = bb->opLoad(uniColor);
        Instruction* alphaMask = bb->opVectorExtractDynamic(mask, module.constant(3u)); // extract alpha channel

        Instruction* unknownSampledImg = bb->opLoad(uniImageUnknownFmt);
        Instruction* unknownImg = bb->opImage(unknownSampledImg);
        Instruction* format = bb->opImageQueryFormat(unknownImg);
        Instruction* channelOrder = bb->opImageQueryOrder(unknownImg);

        Instruction* color = bb->opLoad(uniTex);
        Instruction* uv = bb->opLoad(inUV);
        Instruction* baseColor = bb->opImageSampleImplictLod(color, uv);
        Instruction* alpha = bb->opVectorExtractDynamic(baseColor, module.constant(3u)); // extract alpha channel

        Instruction* cond = bb->Less(alpha, alphaMask);
		BasicBlock& merge = bb.If(cond, [](BasicBlock& trueBB)
			{
                trueBB->opKill(); // discard pixel if baseColor.a < u_color.a
			});

        Instruction* rawImgRg16 = merge->opLoad(uniImgRawRG16);
        Instruction* rawTexelRG16 = merge->opImageRead(rawImgRg16, constCoord2D);

        Instruction* rawImgRgba8 = merge->opLoad(uni3DImgRawRGBA8);
        Instruction* rawTexelRGBA7 = merge->opImageRead(rawImgRgba8, constCoord3D);

        Instruction* offsetCoord = merge->Add(constCoord2D, module.constant(make_vector(8u, 16u)));
        Instruction* rg32 = merge->opFConvert(rawTexelRG16, 32u);
        rg32 = merge->Mul(rg32, module.constant(0.5f));

        Instruction* rawStorageImgRG32 = merge->opLoad(uniImgRawStorageRG32);
        merge->opImageWrite(rawStorageImgRG32, offsetCoord, rg32);

        merge.returnValue();
    }

    return module;
}