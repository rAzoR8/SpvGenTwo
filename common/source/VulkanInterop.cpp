#include "common/VulkanInterop.h"

spvgentwo::vk::ShaderStageFlagBits spvgentwo::vk::getShaderStageFromExecutionModel(spv::ExecutionModel _model)
{
	switch (_model)
	{
	case spv::ExecutionModel::Vertex:
		return ShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT;
	case spv::ExecutionModel::TessellationControl:
		return ShaderStageFlagBits::VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case spv::ExecutionModel::TessellationEvaluation:
		return ShaderStageFlagBits::VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case spv::ExecutionModel::Geometry:
		return ShaderStageFlagBits::VK_SHADER_STAGE_GEOMETRY_BIT;
	case spv::ExecutionModel::Fragment:
		return ShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT;
	case spv::ExecutionModel::GLCompute:
		return ShaderStageFlagBits::VK_SHADER_STAGE_COMPUTE_BIT;
	//case spv::ExecutionModel::Kernel: OpenCL
	case spv::ExecutionModel::TaskNV:
		return ShaderStageFlagBits::VK_SHADER_STAGE_TASK_BIT_NV;
	case spv::ExecutionModel::MeshNV:
		return ShaderStageFlagBits::VK_SHADER_STAGE_MESH_BIT_NV;
	case spv::ExecutionModel::RayGenerationKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_RAYGEN_BIT_KHR;
	case spv::ExecutionModel::IntersectionKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_INTERSECTION_BIT_KHR;
	case spv::ExecutionModel::AnyHitKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_ANY_HIT_BIT_KHR;
	case spv::ExecutionModel::ClosestHitKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR;
	case spv::ExecutionModel::MissKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_MISS_BIT_KHR;
	case spv::ExecutionModel::CallableKHR:
		return ShaderStageFlagBits::VK_SHADER_STAGE_CALLABLE_BIT_KHR;
	case spv::ExecutionModel::Max:
		return ShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT;
	default:
		break;
	}
    return ShaderStageFlagBits::VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM;
}
