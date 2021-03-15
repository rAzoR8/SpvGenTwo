#pragma once

#include "spvgentwo/Spv.h"

namespace spvgentwo
{
    // forward decls
    class Instruction;

	namespace vk
	{
        // identical to VkShaderStageFlagBits
        enum class ShaderStageFlagBits : unsigned int
        {
            VK_SHADER_STAGE_VERTEX_BIT = 0x00000001,
            VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT = 0x00000002,
            VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT = 0x00000004,
            VK_SHADER_STAGE_GEOMETRY_BIT = 0x00000008,
            VK_SHADER_STAGE_FRAGMENT_BIT = 0x00000010,
            VK_SHADER_STAGE_COMPUTE_BIT = 0x00000020,
            VK_SHADER_STAGE_ALL_GRAPHICS = 0x0000001F,
            VK_SHADER_STAGE_ALL = 0x7FFFFFFF,
            VK_SHADER_STAGE_RAYGEN_BIT_KHR = 0x00000100,
            VK_SHADER_STAGE_ANY_HIT_BIT_KHR = 0x00000200,
            VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR = 0x00000400,
            VK_SHADER_STAGE_MISS_BIT_KHR = 0x00000800,
            VK_SHADER_STAGE_INTERSECTION_BIT_KHR = 0x00001000,
            VK_SHADER_STAGE_CALLABLE_BIT_KHR = 0x00002000,
            VK_SHADER_STAGE_TASK_BIT_NV = 0x00000040,
            VK_SHADER_STAGE_MESH_BIT_NV = 0x00000080,
            VK_SHADER_STAGE_RAYGEN_BIT_NV = VK_SHADER_STAGE_RAYGEN_BIT_KHR,
            VK_SHADER_STAGE_ANY_HIT_BIT_NV = VK_SHADER_STAGE_ANY_HIT_BIT_KHR,
            VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV = VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR,
            VK_SHADER_STAGE_MISS_BIT_NV = VK_SHADER_STAGE_MISS_BIT_KHR,
            VK_SHADER_STAGE_INTERSECTION_BIT_NV = VK_SHADER_STAGE_INTERSECTION_BIT_KHR,
            VK_SHADER_STAGE_CALLABLE_BIT_NV = VK_SHADER_STAGE_CALLABLE_BIT_KHR,
            VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
        };

        // returns VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM if incompatible (OpenCL, unknown extension)
        ShaderStageFlagBits getShaderStageFromExecutionModel(spv::ExecutionModel _model);

        // identical to VkDescriptorType
        enum class DescriptorType
        {
            VK_DESCRIPTOR_TYPE_SAMPLER = 0,
            VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 1,
            VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE = 2,
            VK_DESCRIPTOR_TYPE_STORAGE_IMAGE = 3,
            VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER = 4,
            VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER = 5,
            VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER = 6,
            VK_DESCRIPTOR_TYPE_STORAGE_BUFFER = 7,
            VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC = 8,
            VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC = 9,
            VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT = 10,
            VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT = 1000138000,
            VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR = 1000150000,
            VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV = 1000165000,
            VK_DESCRIPTOR_TYPE_MAX_ENUM = 0x7FFFFFFF
        };

        // _pVariable needs to have a valid type (Module::reconstructTypeAndConstantInfo() has to be called before)
        // returns VK_DESCRIPTOR_TYPE_MAX_ENUM if input variable is incompatible. This is not an accureate translation for all VK usecases (can't infer if buffer is 'dynamic')
        DescriptorType getDescriptorTypeFromVariable(const Instruction& _variable);
	}
} //spvgentwo