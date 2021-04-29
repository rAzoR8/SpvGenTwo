#pragma once

#include "Spv.h"

namespace spvgentwo
{
	constexpr unsigned int makeGeneratorId(unsigned short _gen, unsigned short _ver) { return _gen << 16 | _ver; }
	constexpr unsigned int makeVersion(unsigned char _major, unsigned char _minor) { return _major << 16 | (_minor << 8); }
	constexpr unsigned char getMajorVersion(unsigned int _version) { return static_cast<unsigned char>( (_version & 0x00FF0000) >> 16 ); }
	constexpr unsigned char getMinorVersion(unsigned int _version) { return static_cast<unsigned char>( (_version & 0x0000FF00) >> 8 ); }

	// Sampled indicates whether or not this image will be accessed in combination with a sampler, and must be one of the following values:
	enum class SamplerImageAccess : unsigned int
	{
		Unknown = 0, // indicates this is only known at run time, not at compile time
		Sampled = 1, // indicates will be used with sampler
		Storage = 2  // indicates will be used without a sampler (a storage image)
	};

	enum class ConstantSamplerCoordMode : unsigned int
	{
		UnNormalized = 0,
		Normalized = 1
	};

	constexpr auto wordCount(const decltype(sizeof(spv::Id)) _byteCount)
	{
		if (_byteCount <= sizeof(spv::Id)) return decltype(sizeof(spv::Id)){ 1u };
		return (_byteCount / sizeof(spv::Id)) + (_byteCount % sizeof(spv::Id) != 0u ? 1u : 0u);
	}

	template <class T>
	constexpr auto wordCount() { return wordCount(sizeof(T)); }

	constexpr spv::Op getOperation(unsigned int _instrWord)
	{
		return static_cast<spv::Op>(_instrWord & spv::OpCodeMask);
	}

	constexpr unsigned int getOperandCount(unsigned int _instrWord)
	{
		return _instrWord >> spv::WordCountShift;
	}

	constexpr unsigned int makeOpCode(spv::Op _op, unsigned int _operandCount)
	{
		return (static_cast<unsigned int>(_op) & spv::OpCodeMask) | (_operandCount << spv::WordCountShift);
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

	constexpr bool isTerminatorOp(const spv::Op _instr)
	{
		switch (_instr)
		{
		case spv::Op::OpBranch:
		case spv::Op::OpBranchConditional:
		case spv::Op::OpSwitch:
		case spv::Op::OpReturn:
		case spv::Op::OpReturnValue:
		case spv::Op::OpKill:
		case spv::Op::OpUnreachable:
			return true;
		default:
			return false;
		}
	}

	// Instructions that start "OpConstant" or "OpSpec"
	constexpr bool isSpecOrConstantOp(const spv::Op _instr)
	{
		return IsConstantOp(_instr) || IsSpecConstantOp(_instr);
	}

	enum class Sign
	{
		Signed = 1 << 0,
		Unsigned = 1 << 1,
		Any = Signed | Unsigned,
	};

	// get spv::Op::OpTypeFloat from spv::Op::OpFAdd etc (argument type), returns spv::Op::OpNop
	constexpr spv::Op getTypeFromOp(const spv::Op _op, Sign& _sign)
	{
		// this is not a complete match for all instructions, but for most that have variants for several types
		switch (_op)
		{
		case spv::Op::OpTypeFloat:
		case spv::Op::OpFAdd:
		case spv::Op::OpFConvert:
		case spv::Op::OpFDiv:
		case spv::Op::OpFMod:
		case spv::Op::OpFMul:
		case spv::Op::OpFNegate:
		case spv::Op::OpFOrdEqual:
		case spv::Op::OpFOrdGreaterThan:
		case spv::Op::OpFOrdGreaterThanEqual:
		case spv::Op::OpFOrdLessThan:
		case spv::Op::OpFOrdLessThanEqual:
		case spv::Op::OpFOrdNotEqual:
		case spv::Op::OpFRem:
		case spv::Op::OpFSub:
		case spv::Op::OpFUnordEqual:
		case spv::Op::OpFUnordGreaterThan:
		case spv::Op::OpFUnordGreaterThanEqual:
		case spv::Op::OpFUnordLessThan:
		case spv::Op::OpFUnordLessThanEqual:
		case spv::Op::OpFUnordNotEqual:
		case spv::Op::OpFwidth:
		case spv::Op::OpFwidthCoarse:
		case spv::Op::OpFwidthFine:
		case spv::Op::OpDPdx:
		case spv::Op::OpDPdy:
		case spv::Op::OpDPdxFine:
		case spv::Op::OpDPdyFine:
		case spv::Op::OpDPdxCoarse:
		case spv::Op::OpDPdyCoarse:

		case spv::Op::OpIsNan:
		case spv::Op::OpIsInf:
		case spv::Op::OpIsFinite:
		case spv::Op::OpIsNormal:
		case spv::Op::OpSignBitSet:
		case spv::Op::OpLessOrGreater:
		case spv::Op::OpOrdered:
		case spv::Op::OpUnordered:
		case spv::Op::OpConvertFToS:
		case spv::Op::OpConvertFToU:

			_sign = Sign::Any;
			return spv::Op::OpTypeFloat;

		case spv::Op::OpSConvert:
		case spv::Op::OpSDiv:
		case spv::Op::OpSGreaterThan:
		case spv::Op::OpSGreaterThanEqual:
		case spv::Op::OpSLessThan:
		case spv::Op::OpSLessThanEqual:
		case spv::Op::OpSMod:
		case spv::Op::OpSMulExtended:
		case spv::Op::OpSNegate:
		case spv::Op::OpSRem:
		case spv::Op::OpConvertSToF:
			_sign = Sign::Signed;
			return spv::Op::OpTypeInt;

		case spv::Op::OpTypeInt:
		case spv::Op::OpIAdd:
		case spv::Op::OpIAddCarry:
		case spv::Op::OpIAddSatINTEL:
		case spv::Op::OpIAverageINTEL:
		case spv::Op::OpIAverageRoundedINTEL:
		case spv::Op::OpIEqual:
		case spv::Op::OpINotEqual:
		case spv::Op::OpIMul:
		case spv::Op::OpIMul32x16INTEL:
		case spv::Op::OpISub:
		case spv::Op::OpISubBorrow:
		case spv::Op::OpISubSatINTEL:
		case spv::Op::OpNot:
		case spv::Op::OpShiftRightLogical:
		case spv::Op::OpShiftRightArithmetic:
		case spv::Op::OpShiftLeftLogical:
		case spv::Op::OpBitwiseOr:
		case spv::Op::OpBitwiseXor:
		case spv::Op::OpBitwiseAnd:
			_sign = Sign::Any;
			return spv::Op::OpTypeInt;

		case spv::Op::OpUAddSatINTEL:
		case spv::Op::OpUAverageINTEL:
		case spv::Op::OpUAverageRoundedINTEL:
		case spv::Op::OpUConvert:
		case spv::Op::OpUCountLeadingZerosINTEL:
		case spv::Op::OpUCountTrailingZerosINTEL:
		case spv::Op::OpUDiv:
		case spv::Op::OpUGreaterThan:
		case spv::Op::OpUGreaterThanEqual:
		case spv::Op::OpULessThan:
		case spv::Op::OpULessThanEqual:
		case spv::Op::OpUMod:
		case spv::Op::OpUMul32x16INTEL:
		case spv::Op::OpUMulExtended:
		case spv::Op::OpUSubSatINTEL:
		case spv::Op::OpConvertUToF:
			_sign = Sign::Unsigned;
			return spv::Op::OpTypeInt;

		case spv::Op::OpTypeBool:
		case spv::Op::OpLogicalEqual:
		case spv::Op::OpLogicalNotEqual:
		case spv::Op::OpLogicalOr:
		case spv::Op::OpLogicalAnd:
		case spv::Op::OpLogicalNot:
		case spv::Op::OpAny:
		case spv::Op::OpAll:

			_sign = Sign::Any;
			return spv::Op::OpTypeBool;

		default:
			_sign = Sign::Any;
			return spv::Op::OpNop;
		}
	}

	constexpr spv::Op getTypeFromOp(const spv::Op _op) { Sign sign = Sign::Any; return getTypeFromOp(_op, sign); }

	constexpr bool hasStringTerminator(unsigned int _word)
	{
		return (_word & 0x000000FFu) == 0u || (_word & 0x0000FF00) == 0u || (_word & 0x00FF0000) == 0u || (_word & 0xFF000000) == 0u;
	}
	
	struct BaseCapability
	{
		constexpr BaseCapability(spv::Capability _primary = spv::Capability::Max, spv::Capability _secondary = spv::Capability::Max) :
			primary{ _primary }, secondary{ _secondary }
		{}

		spv::Capability primary;
		spv::Capability secondary;

		constexpr operator spv::Capability() const { return primary; }
	};

	// returns 'parent' capability required for _cap, or Max if unspecified
	constexpr BaseCapability getBaseCapability(spv::Capability _cap)
	{
		// commented means no implicit base capability -> Max is returned
		switch (_cap)
		{
		//case spv::Capability::Matrix:
		case spv::Capability::Shader: return spv::Capability::Matrix;
		case spv::Capability::Geometry: return spv::Capability::Shader;
		case spv::Capability::Tessellation: return spv::Capability::Shader;
		//case spv::Capability::Addresses:
		//case spv::Capability::Linkage:
		//case spv::Capability::Kernel:
		case spv::Capability::Vector16: return spv::Capability::Kernel;
		case spv::Capability::Float16Buffer: return spv::Capability::Kernel;
		//case spv::Capability::Float16:
		//case spv::Capability::Float64:
		//case spv::Capability::Int64:
		case spv::Capability::Int64Atomics: return spv::Capability::Int64;
		case spv::Capability::ImageBasic: return spv::Capability::Kernel;
		case spv::Capability::ImageReadWrite: return spv::Capability::ImageBasic;
		case spv::Capability::ImageMipmap: return spv::Capability::ImageBasic;
			break;
		case spv::Capability::Pipes: return spv::Capability::Kernel;
			break;
		//case spv::Capability::Groups:
			break;
		case spv::Capability::DeviceEnqueue: return spv::Capability::Kernel;
			break;
		case spv::Capability::LiteralSampler: return spv::Capability::Kernel;
			break;
		case spv::Capability::AtomicStorage: return spv::Capability::Shader;
			break;
		//case spv::Capability::Int16:
			break;
		case spv::Capability::TessellationPointSize: return spv::Capability::Tessellation;
			break;
		case spv::Capability::GeometryPointSize: return spv::Capability::Geometry;
			break;
		case spv::Capability::ImageGatherExtended: return spv::Capability::Shader;
			break;
		case spv::Capability::StorageImageMultisample: return spv::Capability::Shader;
			break;
		case spv::Capability::UniformBufferArrayDynamicIndexing: return spv::Capability::Shader;
			break;
		case spv::Capability::SampledImageArrayDynamicIndexing: return spv::Capability::Shader;
			break;
		case spv::Capability::StorageBufferArrayDynamicIndexing: return spv::Capability::Shader;
			break;
		case spv::Capability::StorageImageArrayDynamicIndexing: return spv::Capability::Shader;
			break;
		case spv::Capability::ClipDistance: return spv::Capability::Shader;
			break;
		case spv::Capability::CullDistance: return spv::Capability::Shader;
			break;
		case spv::Capability::ImageCubeArray: return spv::Capability::SampledCubeArray;
			break;
		case spv::Capability::SampleRateShading: return spv::Capability::Shader;
			break;
		case spv::Capability::ImageRect: return spv::Capability::SampledRect;
			break;
		case spv::Capability::SampledRect: return spv::Capability::Shader;
			break;
		case spv::Capability::GenericPointer: return spv::Capability::Addresses;
			break;
		//case spv::Capability::Int8:
			break;
		case spv::Capability::InputAttachment: return spv::Capability::Shader;
			break;
		case spv::Capability::SparseResidency: return spv::Capability::Shader;
			break;
		case spv::Capability::MinLod: return spv::Capability::Shader;
			break;
		//case spv::Capability::Sampled1D:
			break;
		case spv::Capability::Image1D: return spv::Capability::Sampled1D;
			break;
		case spv::Capability::SampledCubeArray: return spv::Capability::Shader;
			break;
		//case spv::Capability::SampledBuffer:
			break;
		case spv::Capability::ImageBuffer: return spv::Capability::SampledBuffer;
			break;
		case spv::Capability::ImageMSArray: return spv::Capability::Shader;
			break;
		case spv::Capability::StorageImageExtendedFormats: return spv::Capability::Shader;
			break;
		case spv::Capability::ImageQuery: return spv::Capability::Shader;
			break;
		case spv::Capability::DerivativeControl: return spv::Capability::Shader;
			break;
		case spv::Capability::InterpolationFunction: return spv::Capability::Shader;
			break;
		case spv::Capability::TransformFeedback: return spv::Capability::Shader;
			break;
		case spv::Capability::GeometryStreams: return spv::Capability::Geometry;
			break;
		case spv::Capability::StorageImageReadWithoutFormat: return spv::Capability::Shader;
			break;
		case spv::Capability::StorageImageWriteWithoutFormat: return spv::Capability::Shader;
			break;
		case spv::Capability::MultiViewport: return spv::Capability::Geometry;
			break;
		case spv::Capability::SubgroupDispatch: return spv::Capability::DeviceEnqueue;
			break;
		case spv::Capability::NamedBarrier: return spv::Capability::Kernel;
			break;
		case spv::Capability::PipeStorage: return spv::Capability::Pipes;
			break;
		//case spv::Capability::GroupNonUniform:
			break;
		case spv::Capability::GroupNonUniformVote: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformArithmetic: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformBallot: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformShuffle: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformShuffleRelative: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformClustered: return spv::Capability::GroupNonUniform;
			break;
		case spv::Capability::GroupNonUniformQuad: return spv::Capability::GroupNonUniform;
			break;
		//case spv::Capability::ShaderLayer:
			break;
		//case spv::Capability::ShaderViewportIndex:
			break;
		case spv::Capability::FragmentShadingRateKHR: return spv::Capability::Shader;
			break;
		//case spv::Capability::SubgroupBallotKHR:
			break;
		case spv::Capability::DrawParameters: return spv::Capability::Shader;
			break;
		//case spv::Capability::WorkgroupMemoryExplicitLayoutKHR: unkown
			break;
		//case spv::Capability::WorkgroupMemoryExplicitLayout8BitAccessKHR: unkonwn
			break;
		//case spv::Capability::WorkgroupMemoryExplicitLayout16BitAccessKHR: unkown
			break;
		//case spv::Capability::SubgroupVoteKHR:
			break;
		//case spv::Capability::StorageBuffer16BitAccess: // same as StorageUniformBufferBlock16
			break;
		case spv::Capability::UniformAndStorageBuffer16BitAccess: return spv::Capability::StorageBuffer16BitAccess; // same as StorageUniform16
			break;
		//case spv::Capability::StoragePushConstant16:
			break;
		//case spv::Capability::StorageInputOutput16:
			break;
		//case spv::Capability::DeviceGroup:
			break;
		case spv::Capability::MultiView: return spv::Capability::Shader;
			break;
		case spv::Capability::VariablePointersStorageBuffer: return spv::Capability::Shader;
			break;
		case spv::Capability::VariablePointers: return spv::Capability::VariablePointersStorageBuffer;
			break;
		//case spv::Capability::AtomicStorageOps:
			break;
		//case spv::Capability::SampleMaskPostDepthCoverage:
			break;
		//case spv::Capability::StorageBuffer8BitAccess:
			break;
		case spv::Capability::UniformAndStorageBuffer8BitAccess: return spv::Capability::StorageBuffer8BitAccess;
			break;
		//case spv::Capability::StoragePushConstant8:
			break;
		//case spv::Capability::DenormPreserve:
			break;
		//case spv::Capability::DenormFlushToZero:
			break;
		//case spv::Capability::SignedZeroInfNanPreserve:
			break;
		//case spv::Capability::RoundingModeRTE:
			break;
		//case spv::Capability::RoundingModeRTZ:
			break;
		case spv::Capability::RayQueryProvisionalKHR: return spv::Capability::Shader;
			break;
		case spv::Capability::RayQueryKHR: return spv::Capability::Shader;
			break;
		case spv::Capability::RayTraversalPrimitiveCullingKHR: return { spv::Capability::RayQueryKHR, spv::Capability::RayTracingKHR };
			break;
		case spv::Capability::RayTracingKHR:return spv::Capability::Shader;
			break;
		case spv::Capability::Float16ImageAMD:return spv::Capability::Shader;
			break;
		case spv::Capability::ImageGatherBiasLodAMD: return spv::Capability::Shader;
			break;
		case spv::Capability::FragmentMaskAMD: return spv::Capability::Shader;
			break;
		case spv::Capability::StencilExportEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::ImageReadWriteLodAMD: return spv::Capability::Shader;
			break;
		case spv::Capability::Int64ImageEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::ShaderClockKHR: return spv::Capability::Shader;
			break;
		case spv::Capability::SampleMaskOverrideCoverageNV: return spv::Capability::SampleRateShading;
			break;
		case spv::Capability::GeometryShaderPassthroughNV: return spv::Capability::Geometry;
			break;
		case spv::Capability::ShaderViewportIndexLayerEXT: return spv::Capability::MultiViewport;
			break;
		case spv::Capability::ShaderViewportMaskNV: return spv::Capability::ShaderViewportIndexLayerEXT;
			break;
		case spv::Capability::ShaderStereoViewNV: return spv::Capability::ShaderViewportMaskNV;
			break;
		case spv::Capability::PerViewAttributesNV: return spv::Capability::MultiView;
			break;
		case spv::Capability::FragmentFullyCoveredEXT:  return spv::Capability::Shader;
			break;
		case spv::Capability::MeshShadingNV: return spv::Capability::Shader;
			break;
		//case spv::Capability::ImageFootprintNV:
			break;
		//case spv::Capability::FragmentBarycentricNV:
			break;
		//case spv::Capability::ComputeDerivativeGroupQuadsNV:
			break;
		case spv::Capability::FragmentDensityEXT: return spv::Capability::Shader;
			break;
		//case spv::Capability::GroupNonUniformPartitionedNV: unkown
			break;
		case spv::Capability::ShaderNonUniform: return spv::Capability::Shader;
			break;
		case spv::Capability::RuntimeDescriptorArray: return spv::Capability::Shader;
			break;
		case spv::Capability::InputAttachmentArrayDynamicIndexing:  return spv::Capability::InputAttachment;
			break;
		case spv::Capability::UniformTexelBufferArrayDynamicIndexing: return spv::Capability::SampledBuffer;
			break;
		case spv::Capability::StorageTexelBufferArrayDynamicIndexing: return spv::Capability::ImageBuffer;
			break;
		case spv::Capability::UniformBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::SampledImageArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::StorageBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::StorageImageArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::InputAttachmentArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::UniformTexelBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::StorageTexelBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
			break;
		case spv::Capability::RayTracingNV: return spv::Capability::Shader;
			break;
		//case spv::Capability::VulkanMemoryModel:
			break;
		//case spv::Capability::VulkanMemoryModelDeviceScope:
			break;
		case spv::Capability::PhysicalStorageBufferAddresses: return spv::Capability::Shader;
			break;
		//case spv::Capability::ComputeDerivativeGroupLinearNV:
			break;
		case spv::Capability::RayTracingProvisionalKHR: return spv::Capability::Shader;
			break;
		case spv::Capability::CooperativeMatrixNV: return spv::Capability::Shader;
			break;
		case spv::Capability::FragmentShaderSampleInterlockEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::FragmentShaderShadingRateInterlockEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::ShaderSMBuiltinsNV: return spv::Capability::Shader;
			break;
		case spv::Capability::FragmentShaderPixelInterlockEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::DemoteToHelperInvocationEXT: return spv::Capability::Shader;
			break;
		//case spv::Capability::SubgroupShuffleINTEL:
			break;
		//case spv::Capability::SubgroupBufferBlockIOINTEL:
			break;
		//case spv::Capability::SubgroupImageBlockIOINTEL:
			break;
		//case spv::Capability::SubgroupImageMediaBlockIOINTEL:
			break;
		//case spv::Capability::RoundToInfinityINTEL: unknown
			break;
		//case spv::Capability::FloatingPointModeINTEL: unknown
			break;
		case spv::Capability::IntegerFunctions2INTEL: return spv::Capability::Shader;
			break;
		//case spv::Capability::FunctionPointersINTEL:
			break;
		//case spv::Capability::IndirectReferencesINTEL: unknown
			break;
		//case spv::Capability::AsmINTEL: unknown
			break;
		//case spv::Capability::AtomicFloat32MinMaxEXT: unknown
			break;
		//case spv::Capability::AtomicFloat64MinMaxEXT: unknown
			break;
		//case spv::Capability::AtomicFloat16MinMaxEXT: unknown
			break;
		//case spv::Capability::VectorComputeINTEL: unknown
			break;
		//case spv::Capability::VectorAnyINTEL: unknown
			break;
		//case spv::Capability::SubgroupAvcMotionEstimationINTEL:
			break;
		//case spv::Capability::SubgroupAvcMotionEstimationIntraINTEL:
			break;
		//case spv::Capability::SubgroupAvcMotionEstimationChromaINTEL:
			break;
		//case spv::Capability::VariableLengthArrayINTEL: unknown
			break;
		//case spv::Capability::FunctionFloatControlINTEL: unknown
			break;
		//case spv::Capability::FPGAMemoryAttributesINTEL: unknown
			break;
		//case spv::Capability::FPFastMathModeINTEL: unknown
			break;
		//case spv::Capability::ArbitraryPrecisionIntegersINTEL: unknown
			break;
		//case spv::Capability::UnstructuredLoopControlsINTEL:
			break;
		//case spv::Capability::FPGALoopControlsINTEL:
			break;
		//case spv::Capability::KernelAttributesINTEL:
			break;
		//case spv::Capability::FPGAKernelAttributesINTEL:
			break;
		//case spv::Capability::FPGAMemoryAccessesINTEL: unknown
			break;
		//case spv::Capability::FPGAClusterAttributesINTEL: unknown
			break;
		//case spv::Capability::LoopFuseINTEL: unknown
			break;
		//case spv::Capability::FPGABufferLocationINTEL: unknown
			break;
		//case spv::Capability::USMStorageClassesINTEL: unknown
			break;
		//case spv::Capability::IOPipesINTEL: unknown
			break;
		//case spv::Capability::BlockingPipesINTEL:
			break;
		//case spv::Capability::FPGARegINTEL:
			break;
		case spv::Capability::AtomicFloat32AddEXT: return spv::Capability::Shader;
			break;
		case spv::Capability::AtomicFloat64AddEXT: return spv::Capability::Shader;
			break;
		//case spv::Capability::LongConstantCompositeINTEL: unknown
			break;
		default:
			return spv::Capability::Max;
		}
	}
} //!spvgentwo