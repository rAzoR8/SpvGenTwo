#pragma once

#include "Spv.h"

namespace spvgentwo
{
	constexpr unsigned int makeGeneratorId(unsigned short _gen, unsigned short _ver) { return _gen << 16 | _ver; }
	constexpr unsigned int getGeneratorId(unsigned int _gen) { return (_gen >> 16) & 0xFFFF; }
	constexpr unsigned int getGeneratorVersion(unsigned int _gen) { return _gen & 0xFFFF; }

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

	constexpr auto wordCount(decltype(sizeof(spv::Id)) _byteCount)
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

	inline bool hasResultAndTypeId(spv::Op _operation)
	{
		bool res = false, type = false;
		spv::HasResultAndType(_operation, &res, &type);
		return res && type;
	}

	// returns either spv::OpExecutionMode or spv::OpExecutionModeId based on input mode
	constexpr spv::Op getExecutionModeOp(spv::ExecutionMode _mode)
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

	constexpr bool isTerminatorOp(spv::Op _instr)
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
	constexpr bool isSpecOrConstantOp(spv::Op _instr)
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
	constexpr spv::Op getTypeFromOp(spv::Op _op, Sign& _sign)
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
		case spv::Op::OpIAddSatINTEL:
		case spv::Op::OpIAverageINTEL:
		case spv::Op::OpIAverageRoundedINTEL:
		case spv::Op::OpIEqual:
		case spv::Op::OpINotEqual:
		case spv::Op::OpIMul:
		case spv::Op::OpIMul32x16INTEL:
		case spv::Op::OpISub:
		case spv::Op::OpISubSatINTEL:
		case spv::Op::OpNot:
		case spv::Op::OpShiftRightLogical:
		case spv::Op::OpShiftRightArithmetic:
		case spv::Op::OpShiftLeftLogical:
		case spv::Op::OpBitwiseOr:
		case spv::Op::OpBitwiseXor:
		case spv::Op::OpBitwiseAnd:
		case spv::Op::OpSatConvertUToS:
		case spv::Op::OpSatConvertSToU:
		case spv::Op::OpBitFieldInsert:
		case spv::Op::OpBitReverse:

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
		case spv::Op::OpConvertUToPtr:

			// The member type must be a scalar or vector of integer type, whose Signedness operand is 0
			// Operand 1 and Operand 2 must have the same type as the members of Result Type. => unsigned int
		case spv::Op::OpIAddCarry:
		case spv::Op::OpISubBorrow:

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

	constexpr spv::Op getTypeFromOp(spv::Op _op) { Sign sign = Sign::Any; return getTypeFromOp(_op, sign); }

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
		case spv::Capability::Pipes: return spv::Capability::Kernel;
		//case spv::Capability::Groups:
		case spv::Capability::DeviceEnqueue: return spv::Capability::Kernel;
		case spv::Capability::LiteralSampler: return spv::Capability::Kernel;
		case spv::Capability::AtomicStorage: return spv::Capability::Shader;
		//case spv::Capability::Int16:
		case spv::Capability::TessellationPointSize: return spv::Capability::Tessellation;
		case spv::Capability::GeometryPointSize: return spv::Capability::Geometry;
		case spv::Capability::ImageGatherExtended: return spv::Capability::Shader;
		case spv::Capability::StorageImageMultisample: return spv::Capability::Shader;
		case spv::Capability::UniformBufferArrayDynamicIndexing: return spv::Capability::Shader;
		case spv::Capability::SampledImageArrayDynamicIndexing: return spv::Capability::Shader;
		case spv::Capability::StorageBufferArrayDynamicIndexing: return spv::Capability::Shader;
		case spv::Capability::StorageImageArrayDynamicIndexing: return spv::Capability::Shader;
		case spv::Capability::ClipDistance: return spv::Capability::Shader;
		case spv::Capability::CullDistance: return spv::Capability::Shader;
		case spv::Capability::ImageCubeArray: return spv::Capability::SampledCubeArray;
		case spv::Capability::SampleRateShading: return spv::Capability::Shader;
		case spv::Capability::ImageRect: return spv::Capability::SampledRect;
		case spv::Capability::SampledRect: return spv::Capability::Shader;
		case spv::Capability::GenericPointer: return spv::Capability::Addresses;
		//case spv::Capability::Int8:
		case spv::Capability::InputAttachment: return spv::Capability::Shader;
		case spv::Capability::SparseResidency: return spv::Capability::Shader;
		case spv::Capability::MinLod: return spv::Capability::Shader;
		//case spv::Capability::Sampled1D:
		case spv::Capability::Image1D: return spv::Capability::Sampled1D;
		case spv::Capability::SampledCubeArray: return spv::Capability::Shader;
		//case spv::Capability::SampledBuffer:
		case spv::Capability::ImageBuffer: return spv::Capability::SampledBuffer;
		case spv::Capability::ImageMSArray: return spv::Capability::Shader;
		case spv::Capability::StorageImageExtendedFormats: return spv::Capability::Shader;
		case spv::Capability::ImageQuery: return spv::Capability::Shader;
		case spv::Capability::DerivativeControl: return spv::Capability::Shader;
		case spv::Capability::InterpolationFunction: return spv::Capability::Shader;
		case spv::Capability::TransformFeedback: return spv::Capability::Shader;
		case spv::Capability::GeometryStreams: return spv::Capability::Geometry;
		case spv::Capability::StorageImageReadWithoutFormat: return spv::Capability::Shader;
		case spv::Capability::StorageImageWriteWithoutFormat: return spv::Capability::Shader;
		case spv::Capability::MultiViewport: return spv::Capability::Geometry;
		case spv::Capability::SubgroupDispatch: return spv::Capability::DeviceEnqueue;
		case spv::Capability::NamedBarrier: return spv::Capability::Kernel;
		case spv::Capability::PipeStorage: return spv::Capability::Pipes;
		//case spv::Capability::GroupNonUniform:
		case spv::Capability::GroupNonUniformVote: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformArithmetic: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformBallot: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformShuffle: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformShuffleRelative: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformClustered: return spv::Capability::GroupNonUniform;
		case spv::Capability::GroupNonUniformQuad: return spv::Capability::GroupNonUniform;
		//case spv::Capability::ShaderLayer:
		//case spv::Capability::ShaderViewportIndex:
		case spv::Capability::FragmentShadingRateKHR: return spv::Capability::Shader;
		//case spv::Capability::SubgroupBallotKHR:
		case spv::Capability::DrawParameters: return spv::Capability::Shader;
		//case spv::Capability::WorkgroupMemoryExplicitLayoutKHR: unkown
		//case spv::Capability::WorkgroupMemoryExplicitLayout8BitAccessKHR: unkonwn
		//case spv::Capability::WorkgroupMemoryExplicitLayout16BitAccessKHR: unkown
		//case spv::Capability::SubgroupVoteKHR:
		//case spv::Capability::StorageBuffer16BitAccess: // same as StorageUniformBufferBlock16
		case spv::Capability::UniformAndStorageBuffer16BitAccess: return spv::Capability::StorageBuffer16BitAccess; // same as StorageUniform16
		//case spv::Capability::StoragePushConstant16:
		//case spv::Capability::StorageInputOutput16:
		//case spv::Capability::DeviceGroup:
		case spv::Capability::MultiView: return spv::Capability::Shader;
		case spv::Capability::VariablePointersStorageBuffer: return spv::Capability::Shader;
		case spv::Capability::VariablePointers: return spv::Capability::VariablePointersStorageBuffer;
		//case spv::Capability::AtomicStorageOps:
		//case spv::Capability::SampleMaskPostDepthCoverage:
		//case spv::Capability::StorageBuffer8BitAccess:
		case spv::Capability::UniformAndStorageBuffer8BitAccess: return spv::Capability::StorageBuffer8BitAccess;
		//case spv::Capability::StoragePushConstant8:
		//case spv::Capability::DenormPreserve:
		//case spv::Capability::DenormFlushToZero:
		//case spv::Capability::SignedZeroInfNanPreserve:
		//case spv::Capability::RoundingModeRTE:
		//case spv::Capability::RoundingModeRTZ:
		case spv::Capability::RayQueryProvisionalKHR: return spv::Capability::Shader;
		case spv::Capability::RayQueryKHR: return spv::Capability::Shader;
		case spv::Capability::RayTraversalPrimitiveCullingKHR: return { spv::Capability::RayQueryKHR, spv::Capability::RayTracingKHR };
		case spv::Capability::RayTracingKHR:return spv::Capability::Shader;
		case spv::Capability::Float16ImageAMD:return spv::Capability::Shader;
		case spv::Capability::ImageGatherBiasLodAMD: return spv::Capability::Shader;
		case spv::Capability::FragmentMaskAMD: return spv::Capability::Shader;
		case spv::Capability::StencilExportEXT: return spv::Capability::Shader;
		case spv::Capability::ImageReadWriteLodAMD: return spv::Capability::Shader;
		case spv::Capability::Int64ImageEXT: return spv::Capability::Shader;
		case spv::Capability::ShaderClockKHR: return spv::Capability::Shader;
		case spv::Capability::SampleMaskOverrideCoverageNV: return spv::Capability::SampleRateShading;
		case spv::Capability::GeometryShaderPassthroughNV: return spv::Capability::Geometry;
		case spv::Capability::ShaderViewportIndexLayerEXT: return spv::Capability::MultiViewport;
		case spv::Capability::ShaderViewportMaskNV: return spv::Capability::ShaderViewportIndexLayerEXT;
		case spv::Capability::ShaderStereoViewNV: return spv::Capability::ShaderViewportMaskNV;
		case spv::Capability::PerViewAttributesNV: return spv::Capability::MultiView;
		case spv::Capability::FragmentFullyCoveredEXT:  return spv::Capability::Shader;
		case spv::Capability::MeshShadingNV: return spv::Capability::Shader;
		//case spv::Capability::ImageFootprintNV:
		//case spv::Capability::FragmentBarycentricNV:
		//case spv::Capability::ComputeDerivativeGroupQuadsNV:
		case spv::Capability::FragmentDensityEXT: return spv::Capability::Shader;
		//case spv::Capability::GroupNonUniformPartitionedNV: unkown
		case spv::Capability::ShaderNonUniform: return spv::Capability::Shader;
		case spv::Capability::RuntimeDescriptorArray: return spv::Capability::Shader;
		case spv::Capability::InputAttachmentArrayDynamicIndexing:  return spv::Capability::InputAttachment;
		case spv::Capability::UniformTexelBufferArrayDynamicIndexing: return spv::Capability::SampledBuffer;
		case spv::Capability::StorageTexelBufferArrayDynamicIndexing: return spv::Capability::ImageBuffer;
		case spv::Capability::UniformBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::SampledImageArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::StorageBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::StorageImageArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::InputAttachmentArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::UniformTexelBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::StorageTexelBufferArrayNonUniformIndexing: return spv::Capability::ShaderNonUniform;
		case spv::Capability::RayTracingNV: return spv::Capability::Shader;
		//case spv::Capability::VulkanMemoryModel:
		//case spv::Capability::VulkanMemoryModelDeviceScope:
		case spv::Capability::PhysicalStorageBufferAddresses: return spv::Capability::Shader;
		//case spv::Capability::ComputeDerivativeGroupLinearNV:
		case spv::Capability::RayTracingProvisionalKHR: return spv::Capability::Shader;
		case spv::Capability::CooperativeMatrixNV: return spv::Capability::Shader;
		case spv::Capability::FragmentShaderSampleInterlockEXT: return spv::Capability::Shader;
		case spv::Capability::FragmentShaderShadingRateInterlockEXT: return spv::Capability::Shader;
		case spv::Capability::ShaderSMBuiltinsNV: return spv::Capability::Shader;
		case spv::Capability::FragmentShaderPixelInterlockEXT: return spv::Capability::Shader;
		case spv::Capability::DemoteToHelperInvocationEXT: return spv::Capability::Shader;
		//case spv::Capability::SubgroupShuffleINTEL:
		//case spv::Capability::SubgroupBufferBlockIOINTEL:
		//case spv::Capability::SubgroupImageBlockIOINTEL:
		//case spv::Capability::SubgroupImageMediaBlockIOINTEL:
		//case spv::Capability::RoundToInfinityINTEL: unknown
		//case spv::Capability::FloatingPointModeINTEL: unknown
		case spv::Capability::IntegerFunctions2INTEL: return spv::Capability::Shader;
		//case spv::Capability::FunctionPointersINTEL:
		//case spv::Capability::IndirectReferencesINTEL: unknown
		//case spv::Capability::AsmINTEL: unknown
		//case spv::Capability::AtomicFloat32MinMaxEXT: unknown
		//case spv::Capability::AtomicFloat64MinMaxEXT: unknown
		//case spv::Capability::AtomicFloat16MinMaxEXT: unknown
		//case spv::Capability::VectorComputeINTEL: unknown
		//case spv::Capability::VectorAnyINTEL: unknown
		//case spv::Capability::SubgroupAvcMotionEstimationINTEL:
		//case spv::Capability::SubgroupAvcMotionEstimationIntraINTEL:
		//case spv::Capability::SubgroupAvcMotionEstimationChromaINTEL:
		//case spv::Capability::VariableLengthArrayINTEL: unknown
		//case spv::Capability::FunctionFloatControlINTEL: unknown
		//case spv::Capability::FPGAMemoryAttributesINTEL: unknown
		//case spv::Capability::FPFastMathModeINTEL: unknown
		//case spv::Capability::ArbitraryPrecisionIntegersINTEL: unknown
		//case spv::Capability::UnstructuredLoopControlsINTEL:
		//case spv::Capability::FPGALoopControlsINTEL:
		//case spv::Capability::KernelAttributesINTEL:
		//case spv::Capability::FPGAKernelAttributesINTEL:
		//case spv::Capability::FPGAMemoryAccessesINTEL: unknown
		//case spv::Capability::FPGAClusterAttributesINTEL: unknown
		//case spv::Capability::LoopFuseINTEL: unknown
		//case spv::Capability::FPGABufferLocationINTEL: unknown
		//case spv::Capability::USMStorageClassesINTEL: unknown
		//case spv::Capability::IOPipesINTEL: unknown
		//case spv::Capability::BlockingPipesINTEL:
		//case spv::Capability::FPGARegINTEL:
		case spv::Capability::AtomicFloat32AddEXT: return spv::Capability::Shader;
		case spv::Capability::AtomicFloat64AddEXT: return spv::Capability::Shader;
		//case spv::Capability::LongConstantCompositeINTEL: unknown
		default:
			return spv::Capability::Max;
		}
	}

	// returns number of dimensions of an image (surface/layer) for spv::Dim, or 0u if input is unimplemented
	constexpr unsigned int getImageDimension(spv::Dim _dim)
	{
		switch (_dim)
		{
		case spv::Dim::Dim1D:
		case spv::Dim::Buffer:
			return 1u;
		case spv::Dim::Dim2D:
		case spv::Dim::Cube:
		case spv::Dim::Rect:
		case spv::Dim::SubpassData:
			return 2u;
		case spv::Dim::Dim3D:
			return 3u;
		default:
			return 0u;
		}
	}

	// returns number of channels/components for spv::ImageFormat, or 0u if unknown or max
	constexpr unsigned int getImageChannelCount(spv::ImageFormat _format)
	{
		switch (_format)
		{
		case spvgentwo::spv::ImageFormat::R8:
		case spvgentwo::spv::ImageFormat::R8Snorm:
		case spvgentwo::spv::ImageFormat::R8i:
		case spvgentwo::spv::ImageFormat::R8ui:
		case spvgentwo::spv::ImageFormat::R16:
		case spvgentwo::spv::ImageFormat::R16f:
		case spvgentwo::spv::ImageFormat::R16Snorm:
		case spvgentwo::spv::ImageFormat::R16i:
		case spvgentwo::spv::ImageFormat::R16ui:
		case spvgentwo::spv::ImageFormat::R32f:
		case spvgentwo::spv::ImageFormat::R32i:
		case spvgentwo::spv::ImageFormat::R32ui:
		case spvgentwo::spv::ImageFormat::R64i:
		case spvgentwo::spv::ImageFormat::R64ui:
			return 1u;
		case spvgentwo::spv::ImageFormat::Rg8:
		case spvgentwo::spv::ImageFormat::Rg8Snorm:
		case spvgentwo::spv::ImageFormat::Rg8i:
		case spvgentwo::spv::ImageFormat::Rg8ui:
		case spvgentwo::spv::ImageFormat::Rg16:
		case spvgentwo::spv::ImageFormat::Rg16f:
		case spvgentwo::spv::ImageFormat::Rg16Snorm:
		case spvgentwo::spv::ImageFormat::Rg16i:
		case spvgentwo::spv::ImageFormat::Rg16ui:
		case spvgentwo::spv::ImageFormat::Rg32f:
		case spvgentwo::spv::ImageFormat::Rg32i:
		case spvgentwo::spv::ImageFormat::Rg32ui:
			return 2u;
		case spvgentwo::spv::ImageFormat::R11fG11fB10f:
			return 3u;
		case spvgentwo::spv::ImageFormat::Rgba8:
		case spvgentwo::spv::ImageFormat::Rgba8Snorm:
		case spvgentwo::spv::ImageFormat::Rgba8i:
		case spvgentwo::spv::ImageFormat::Rgba8ui:
		case spvgentwo::spv::ImageFormat::Rgb10A2:
		case spvgentwo::spv::ImageFormat::Rgb10a2ui:
		case spvgentwo::spv::ImageFormat::Rgba16:
		case spvgentwo::spv::ImageFormat::Rgba16Snorm:
		case spvgentwo::spv::ImageFormat::Rgba16f:
		case spvgentwo::spv::ImageFormat::Rgba16i:
		case spvgentwo::spv::ImageFormat::Rgba16ui:
		case spvgentwo::spv::ImageFormat::Rgba32f:
		case spvgentwo::spv::ImageFormat::Rgba32i:
		case spvgentwo::spv::ImageFormat::Rgba32ui:
			return 4u;
		default:
			return 0u;
		}
	}
} //!spvgentwo