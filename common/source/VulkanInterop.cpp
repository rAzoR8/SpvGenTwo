#include "common/VulkanInterop.h"
#include "common/ReflectionHelper.h"
#include "common/ReflectionHelperTemplate.inl"
#include "common/HeapCallable.h"
#include "spvgentwo/Instruction.h"
#include "spvgentwo/Type.h"

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

spvgentwo::vk::DescriptorType spvgentwo::vk::getDescriptorTypeFromVariable(const Instruction& _variable)
{
	if (_variable.getModule() == nullptr || _variable != spv::Op::OpVariable)
	{
		return DescriptorType::VK_DESCRIPTOR_TYPE_MAX_ENUM;
	}

	const Type* ptr = _variable.getType();

	if (ptr == nullptr || *ptr != spv::Op::OpTypePointer || ptr->getSubTypes().empty())
	{
		return DescriptorType::VK_DESCRIPTOR_TYPE_MAX_ENUM;
	}

	const Type& type = ptr->front();

	const spv::StorageClass storage = _variable.getStorageClass();

	// https://www.khronos.org/registry/vulkan/specs/1.1-extensions/html/chap16.html#interfaces-resources-setandbinding
	// A noteworthy example of using multiple statically-used shader variables sharing the same descriptor set and binding values is a descriptor of type VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER
	// that has multiple corresponding shader variables in the UniformConstant storage class, where some could be OpTypeImage, some could be OpTypeSampler(Sampled = 1), and some could be OpTypeSampledImage.

	if (storage == spv::StorageClass::UniformConstant &&
		(	
			type.getType() == spv::Op::OpTypeSampler		||
			type.getType() == spv::Op::OpTypeSampledImage	||
			type.getType() == spv::Op::OpTypeImage)
		)
	{
		const unsigned int set = ReflectionHelper::getDecorationLiteralFromTarget(spv::Decoration::DescriptorSet, &_variable);
		const unsigned int binding = ReflectionHelper::getDecorationLiteralFromTarget(spv::Decoration::Binding, &_variable);

		if (set != sgt_uint32_max && binding != sgt_uint32_max)
		{
			bool foundCombinedImageSampler = false;
			auto check = [&](const Instruction* _pVar)
			{
				if (foundCombinedImageSampler) // skip rest
				{
					return;
				}

				// we found another variable in the same set
				if (const Type* otherType = _pVar->getType(); _pVar != &_variable && otherType != nullptr && _pVar->getStorageClass() == spv::StorageClass::UniformConstant)
				{
					// check for [sampler & image] or [image & sampler] variable combo
					if (((otherType->getType() == spv::Op::OpTypeSampler) && (type.getType() == spv::Op::OpTypeSampledImage || type.getType() == spv::Op::OpTypeImage)) ||
						((type.getType() == spv::Op::OpTypeSampler) && (otherType->getType() == spv::Op::OpTypeSampledImage || otherType->getType() == spv::Op::OpTypeImage)))
					{
						// we found a image or sampler on the same descriptor set & binding in UniformConstant storage class
						if (ReflectionHelper::getDecorationLiteralFromTarget(spv::Decoration::Binding, _pVar) == binding)
						{
							foundCombinedImageSampler = true;
						}
					}
				}
			};

			ReflectionHelper::getVariablesWithDecorationFunc(*_variable.getModule(), spv::Decoration::DescriptorSet, check, &set); // get variable in the same set

			if (foundCombinedImageSampler)
			{
				return DescriptorType::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			}
		}
	}

	switch (type.getType())
	{
	case spv::Op::OpTypeSampler:					return DescriptorType::VK_DESCRIPTOR_TYPE_SAMPLER;
	case spv::Op::OpTypeSampledImage:
		switch (type.front().getImageSamplerAccess())
		{
		case SamplerImageAccess::Sampled:			return DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;
		case SamplerImageAccess::Storage:			return DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;
		default:									return DescriptorType::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		}		
	case spv::Op::OpTypeImage:
	{
		switch (type.getImageDimension())
		{
		case spv::Dim::Buffer:		
			switch (type.getImageSamplerAccess())
			{
			case SamplerImageAccess::Sampled:		return DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;
			case SamplerImageAccess::Storage:		return DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;
			default: break;
			}
			break;
		case spv::Dim::SubpassData:					return DescriptorType::VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;
		default: // dim1/2/3
			switch (type.getImageSamplerAccess())
			{
			case SamplerImageAccess::Sampled:		return DescriptorType::VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
			case SamplerImageAccess::Storage:		return DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
			default: break;
			}
			break;
		}
		break;
	}
	case spv::Op::OpTypeAccelerationStructureKHR:	return DescriptorType::VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR;
	default: // assume this is a buffer
		switch (storage)
		{
		case spv::StorageClass::Uniform:			[[fallthrough]];
		case spv::StorageClass::UniformConstant:	return DescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		case spv::StorageClass::StorageBuffer:		return DescriptorType::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		default:
			break;
		}
		break;
	}

	return DescriptorType::VK_DESCRIPTOR_TYPE_MAX_ENUM;
}
