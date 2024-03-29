#include "test/Modules.h"

#include "spvgentwo/GLSL450Instruction.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;
using namespace ext;

spvgentwo::Module test::extensions(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR, _pLogger);
   
    module.addCapability(spv::Capability::Shader);
    module.addCapability(spv::Capability::Float64);
    module.addCapability(spv::Capability::InterpolationFunction);

    // use Vulkan Memory Model
    module.addCapability(spv::Capability::VulkanMemoryModelKHR);
    module.addExtension(u8"SPV_KHR_vulkan_memory_model"); // add extension by string

    // Instruction* extId = module.getExtensionInstructionImport("GLSL.std.450");

    // void entryPoint();
    {
        EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
        entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
        BasicBlock& bb = *entry; // get entry block to this function

        // SPV_AMD_gcn_shader example: https://htmlpreview.github.io/?https://github.com/KhronosGroup/SPIRV-Registry/blob/master/extensions/AMD/SPV_AMD_gcn_shader.html
        {
            module.addExtension(u8"SPV_AMD_gcn_shader"); // adds an OpExtension instruction to the module

            // opcodes taken from extension spec:
            const unsigned int CubeFaceCoordAMD = 2;
            const unsigned int CubeFaceIndexAMD = 1;
            const unsigned int TimeAMD = 3;

            // getExtensionInstructionImport adds extension to the module
            // return value ext can be used with Instruction.opExtInst(resultType, extId, opCode, ...);
            Instruction* extId = module.addExtensionInstructionImport(u8"SPV_AMD_gcn_shader");

            /// CubeFaceCoordAMD example:

            // Result Type must be a 2-component 32-bit floating-point vector.
            Instruction* vec2 = module.type<vector_t<float, 2>>();

            // The operand <P> must be a pointer to a 3-component 32-bit floating-point vector.
            Instruction* P = entry.variable<vector_t<float, 3>>();

            // use extId generated by getExtensionInstructionImport (which adds OpExtInstImport)
            Instruction* faceCoord = bb->opExtInst(vec2, extId, CubeFaceCoordAMD, P);

            /// TimeAMD example:

            //Use of this instruction requires declaration of the Int64 capability.
            //Result Type must be a 64 - bit unsigned integer scalar.
            Instruction* uint64 = module.type<unsigned long int>();

            // The second variant of opExtInst can direclty add the extension to the module by supplying the extension name "GLSL.std.450"
            Instruction* time = bb->opExtInst(uint64, u8"SPV_AMD_gcn_shader", TimeAMD);
        }

        // SpvGenTwo comes with GLSL extension instructions (GLSL450Intruction derives from Instruction>
        Instruction* const vec3 = module.constant(make_vector(1.f, 2.f, 3.f));

        // BasicBlock template function ext<T> adds a new Instruction and casts it to type T
        // this works as long as T does not add any data members and just functionally extends the Instruction class
        Instruction* const cross = bb.ext<GLSL450Intruction>()->opCross(vec3, vec3); // use GLSL.std.450 extension
       
        // ext<T> is usefull for extension instruction derivates that are foreign to spvgentwo
        // For GLSL 4.5 we have the glsl() and ext<GLSL>() shortcuts:
        Instruction* const norm = bb.glsl()->opNormalize(cross);

        Instruction* const ff = bb.ext<GLSL>()->opFaceForward(vec3, norm, cross);

        Instruction* const refl = bb.glsl()->opReflect(vec3, norm);

        Instruction* const eta = bb->opDot(refl, ff);

        Instruction* const refr = bb.glsl()->opRefract(refl, ff, eta);

        Instruction* const len = bb.glsl()->opLength(refr);

        Instruction* const dist = bb.glsl()->opDistance(refl, refr);

        Instruction* const modf = bb.glsl()->opModfStruct(refl);

        Instruction* const frexp = bb.glsl()->opFrexpStruct(refr);

        Instruction* const expInt = bb->opCompositeExtract(frexp, 1u); // extract the exponent

        Instruction* const ldexp = bb.glsl()->opLdexp(ff, expInt);

        Instruction* const vec4 = module.constant(make_vector(1.f, 2.f, 3.f, 4.f));

        Instruction* const vec2 = module.constant(make_vector(1.f, 2.f));

        Instruction* const ivec2 = module.constant(make_vector(1, 2));

        Instruction* pack = bb.glsl()->opPackSnorm4x8(vec4);
        bb.glsl()->opUnpackSnorm4x8(pack);

        pack = bb.glsl()->opPackUnorm4x8(vec4);
        bb.glsl()->opUnpackUnorm4x8(pack);

        pack = bb.glsl()->opPackSnorm2x16(vec2);
        bb.glsl()->opUnpackSnorm2x16(pack);

        pack = bb.glsl()->opPackUnorm2x16(vec2);
        bb.glsl()->opUnpackUnorm2x16(pack);

        pack = bb.glsl()->opPackHalf2x16(vec2);
        bb.glsl()->opUnpackHalf2x16(pack);

        pack = bb.glsl()->opPackDouble2x32(ivec2);
        bb.glsl()->opUnpackDouble2x32(pack);

        Instruction* const ilsb = bb.glsl()->opFindILsb(ivec2);
        Instruction* const smsb = bb.glsl()->opFindSMsb(ivec2);
        Instruction* const umsm = bb.glsl()->opFindUMsb(ivec2);

        Instruction* const inputVar = module.input<vector_t<float, 4>>("interpolant");
        Instruction* const interpolant = bb->opAccessChain(inputVar, 0u);

        Instruction* const ipolC = bb.glsl()->opInterpolateAtCentroid(interpolant);
        Instruction* const ipolS = bb.glsl()->opInterpolateAtSample(interpolant, module.constant(2));
        Instruction* const ipolO = bb.glsl()->opInterpolateAtOffset(interpolant, vec2);

        bb.glsl()->opNMin(ipolC, ipolO);
        bb.glsl()->opNMax(ipolS, ipolO);
        bb.glsl()->opNClamp(ipolC, ipolO, ipolS);

        entry->opReturn();
    }

	return module;
}
