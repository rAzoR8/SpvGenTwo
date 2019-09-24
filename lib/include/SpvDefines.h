#pragma once

#define SPV_ENABLE_UTILITY_CODE
#include <vulkan/spirv.hpp11>

namespace spvgentwo
{
	// Sampled indicates whether or not this image will be accessed in combination with a sampler, and must be one of the following values:
	enum class SamplerImageAccess : unsigned int
	{
		Unknown = 0, // indicates this is only known at run time, not at compile time
		Sampled = 1, // indicates will be used with sampler
		Storage = 2  // indicates will be used without a sampler (a storage image)
	};

	constexpr unsigned int makeGeneratorId(unsigned short _gen, unsigned short _ver) { return _gen << 16 | _ver; }

	constexpr bool isType(const spv::Op _type)
	{		
		if ((_type >= spv::Op::OpTypeVoid && _type <= spv::Op::OpTypeForwardPointer) || // basic types
			(_type >= spv::Op::OpTypeVmeImageINTEL && _type <= spv::Op::OpTypeAvcSicResultINTEL) // intel ext
			)
		{
			return true;
		}

		// special cases and small extensions
		switch (_type)
		{
		case spv::Op::OpTypePipeStorage:
		case spv::Op::OpTypeNamedBarrier:
		case spv::Op::OpTypeAccelerationStructureNV:
		case spv::Op::OpTypeCooperativeMatrixNV:
			return true;
		default:
			return false;
		}
	}

	constexpr size_t wordCount(const size_t _byteCount)
	{
		return (_byteCount / sizeof(spv::Id)) + (_byteCount % sizeof(spv::Id) != 0u ? 1u : 0u);
	}

	inline bool hasResultId(const spv::Op _operation)
	{
		bool res = false, type = false;
		spv::HasResultAndType(_operation, &res, &type);
		return res;
	}

	inline bool hasResultTypeId(const spv::Op _operation)
	{
		bool res = false, type = false;
		spv::HasResultAndType(_operation, &res, &type);
		return type;
	}

	inline bool hasResultAndTypeId(const spv::Op _operation)
	{
		bool res = false, type = false;
		spv::HasResultAndType(_operation, &res, &type);
		return res && type;
	}

	// returns either spv::OpExecutionMode or spv::OpExecutionModeId based on input mode
	constexpr spv::Op getExecutionModeOp(const spv::ExecutionMode _mode)
	{
		switch (_mode)
		{
		case spv::ExecutionMode::SubgroupsPerWorkgroupId:
		case spv::ExecutionMode::LocalSizeId:
		case spv::ExecutionMode::LocalSizeHintId:
			return spv::Op::OpExecutionModeId;
		default:
			return spv::Op::OpExecutionMode;
		}
	}

	// spir-v specific traits
	namespace traits
	{
		template <class T> constexpr bool is_primitive_type_v = false;
		template <>	constexpr bool is_primitive_type_v<bool> = true;
		template <>	constexpr bool is_primitive_type_v<short> = true;
		template <>	constexpr bool is_primitive_type_v<unsigned short> = true;
		template <>	constexpr bool is_primitive_type_v<int> = true;
		template <>	constexpr bool is_primitive_type_v<unsigned int> = true;
		template <>	constexpr bool is_primitive_type_v<long> = true;
		template <>	constexpr bool is_primitive_type_v<unsigned long> = true;
		template <>	constexpr bool is_primitive_type_v<long long> = true;
		template <>	constexpr bool is_primitive_type_v<unsigned long long> = true;
		template <>	constexpr bool is_primitive_type_v<float> = true;
		template <>	constexpr bool is_primitive_type_v<double> = true;
	}
} //!spvgentwo