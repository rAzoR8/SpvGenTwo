// Auto generated - do not modify
// Copyright (c) 2014-2020 The Khronos Group Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and/or associated documentation files (the "Materials"),
// to deal in the Materials without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Materials, and to permit persons to whom the
// Materials are furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Materials.
// 
// MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS KHRONOS
// STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS SPECIFICATIONS AND
// HEADER INFORMATION ARE LOCATED AT https://www.khronos.org/registry/ 
// 
// THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM,OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE USE OR OTHER DEALINGS
// IN THE MATERIALS.
#pragma once

namespace spvgentwo::spv
{
	enum class Id : unsigned int;
	static constexpr unsigned int MagicNumber = 0x07230203;
	static constexpr unsigned int Version = 67072;
	static constexpr unsigned int Revision = 1;
	static constexpr unsigned int OpCodeMask = 0xffff;
	static constexpr unsigned int WordCountShift = 16;
	enum class ImageOperandsMask : unsigned
	{
		MaskNone = 0x0000,
		Bias = 0x0001,
		Lod = 0x0002,
		Grad = 0x0004,
		ConstOffset = 0x0008,
		Offset = 0x0010,
		ConstOffsets = 0x0020,
		Sample = 0x0040,
		MinLod = 0x0080,
		MakeTexelAvailable = 0x0100,
		MakeTexelAvailableKHR = 0x0100,
		MakeTexelVisible = 0x0200,
		MakeTexelVisibleKHR = 0x0200,
		NonPrivateTexel = 0x0400,
		NonPrivateTexelKHR = 0x0400,
		VolatileTexel = 0x0800,
		VolatileTexelKHR = 0x0800,
		SignExtend = 0x1000,
		ZeroExtend = 0x2000,
		Nontemporal = 0x4000,
		Offsets = 0x10000,
	};
	enum class ImageOperandsShift : unsigned
	{
		None = 0,
		Bias = 1,
		Lod = 2,
		Grad = 3,
		ConstOffset = 4,
		Offset = 5,
		ConstOffsets = 6,
		Sample = 7,
		MinLod = 8,
		MakeTexelAvailable = 9,
		MakeTexelAvailableKHR = 10,
		MakeTexelVisible = 11,
		MakeTexelVisibleKHR = 12,
		NonPrivateTexel = 13,
		NonPrivateTexelKHR = 14,
		VolatileTexel = 15,
		VolatileTexelKHR = 16,
		SignExtend = 17,
		ZeroExtend = 18,
		Nontemporal = 19,
		Offsets = 20,
		Max = 0x7fffffff
	};
	enum class FPFastMathModeMask : unsigned
	{
		MaskNone = 0x0000,
		NotNaN = 0x0001,
		NotInf = 0x0002,
		NSZ = 0x0004,
		AllowRecip = 0x0008,
		Fast = 0x0010,
		AllowContractFastINTEL = 0x10000,
		AllowReassocINTEL = 0x20000,
	};
	enum class FPFastMathModeShift : unsigned
	{
		None = 0,
		NotNaN = 1,
		NotInf = 2,
		NSZ = 3,
		AllowRecip = 4,
		Fast = 5,
		AllowContractFastINTEL = 6,
		AllowReassocINTEL = 7,
		Max = 0x7fffffff
	};
	enum class SelectionControlMask : unsigned
	{
		MaskNone = 0x0000,
		Flatten = 0x0001,
		DontFlatten = 0x0002,
	};
	enum class SelectionControlShift : unsigned
	{
		None = 0,
		Flatten = 1,
		DontFlatten = 2,
		Max = 0x7fffffff
	};
	enum class LoopControlMask : unsigned
	{
		MaskNone = 0x0000,
		Unroll = 0x0001,
		DontUnroll = 0x0002,
		DependencyInfinite = 0x0004,
		DependencyLength = 0x0008,
		MinIterations = 0x0010,
		MaxIterations = 0x0020,
		IterationMultiple = 0x0040,
		PeelCount = 0x0080,
		PartialCount = 0x0100,
		InitiationIntervalINTEL = 0x10000,
		MaxConcurrencyINTEL = 0x20000,
		DependencyArrayINTEL = 0x40000,
		PipelineEnableINTEL = 0x80000,
		LoopCoalesceINTEL = 0x100000,
		MaxInterleavingINTEL = 0x200000,
		SpeculatedIterationsINTEL = 0x400000,
		NoFusionINTEL = 0x800000,
	};
	enum class LoopControlShift : unsigned
	{
		None = 0,
		Unroll = 1,
		DontUnroll = 2,
		DependencyInfinite = 3,
		DependencyLength = 4,
		MinIterations = 5,
		MaxIterations = 6,
		IterationMultiple = 7,
		PeelCount = 8,
		PartialCount = 9,
		InitiationIntervalINTEL = 10,
		MaxConcurrencyINTEL = 11,
		DependencyArrayINTEL = 12,
		PipelineEnableINTEL = 13,
		LoopCoalesceINTEL = 14,
		MaxInterleavingINTEL = 15,
		SpeculatedIterationsINTEL = 16,
		NoFusionINTEL = 17,
		Max = 0x7fffffff
	};
	enum class FunctionControlMask : unsigned
	{
		MaskNone = 0x0000,
		Inline = 0x0001,
		DontInline = 0x0002,
		Pure = 0x0004,
		Const = 0x0008,
		OptNoneINTEL = 0x10000,
	};
	enum class FunctionControlShift : unsigned
	{
		None = 0,
		Inline = 1,
		DontInline = 2,
		Pure = 3,
		Const = 4,
		OptNoneINTEL = 5,
		Max = 0x7fffffff
	};
	enum class MemorySemanticsMask : unsigned
	{
		Relaxed = 0x0000,
		MaskNone = 0x0000,
		Acquire = 0x0002,
		Release = 0x0004,
		AcquireRelease = 0x0008,
		SequentiallyConsistent = 0x0010,
		UniformMemory = 0x0040,
		SubgroupMemory = 0x0080,
		WorkgroupMemory = 0x0100,
		CrossWorkgroupMemory = 0x0200,
		AtomicCounterMemory = 0x0400,
		ImageMemory = 0x0800,
		OutputMemory = 0x1000,
		OutputMemoryKHR = 0x1000,
		MakeAvailable = 0x2000,
		MakeAvailableKHR = 0x2000,
		MakeVisible = 0x4000,
		MakeVisibleKHR = 0x4000,
		Volatile = 0x8000,
	};
	enum class MemorySemanticsShift : unsigned
	{
		Relaxed = 0,
		None = 1,
		Acquire = 2,
		Release = 3,
		AcquireRelease = 4,
		SequentiallyConsistent = 5,
		UniformMemory = 6,
		SubgroupMemory = 7,
		WorkgroupMemory = 8,
		CrossWorkgroupMemory = 9,
		AtomicCounterMemory = 10,
		ImageMemory = 11,
		OutputMemory = 12,
		OutputMemoryKHR = 13,
		MakeAvailable = 14,
		MakeAvailableKHR = 15,
		MakeVisible = 16,
		MakeVisibleKHR = 17,
		Volatile = 18,
		Max = 0x7fffffff
	};
	enum class MemoryAccessMask : unsigned
	{
		MaskNone = 0x0000,
		Volatile = 0x0001,
		Aligned = 0x0002,
		Nontemporal = 0x0004,
		MakePointerAvailable = 0x0008,
		MakePointerAvailableKHR = 0x0008,
		MakePointerVisible = 0x0010,
		MakePointerVisibleKHR = 0x0010,
		NonPrivatePointer = 0x0020,
		NonPrivatePointerKHR = 0x0020,
		AliasScopeINTELMask = 0x10000,
		NoAliasINTELMask = 0x20000,
	};
	enum class MemoryAccessShift : unsigned
	{
		None = 0,
		Volatile = 1,
		Aligned = 2,
		Nontemporal = 3,
		MakePointerAvailable = 4,
		MakePointerAvailableKHR = 5,
		MakePointerVisible = 6,
		MakePointerVisibleKHR = 7,
		NonPrivatePointer = 8,
		NonPrivatePointerKHR = 9,
		AliasScopeINTELMask = 10,
		NoAliasINTELMask = 11,
		Max = 0x7fffffff
	};
	enum class KernelProfilingInfoMask : unsigned
	{
		MaskNone = 0x0000,
		CmdExecTime = 0x0001,
	};
	enum class KernelProfilingInfoShift : unsigned
	{
		None = 0,
		CmdExecTime = 1,
		Max = 0x7fffffff
	};
	enum class RayFlagsMask : unsigned
	{
		NoneKHR = 0x0000,
		OpaqueKHR = 0x0001,
		NoOpaqueKHR = 0x0002,
		TerminateOnFirstHitKHR = 0x0004,
		SkipClosestHitShaderKHR = 0x0008,
		CullBackFacingTrianglesKHR = 0x0010,
		CullFrontFacingTrianglesKHR = 0x0020,
		CullOpaqueKHR = 0x0040,
		CullNoOpaqueKHR = 0x0080,
		SkipTrianglesKHR = 0x0100,
		SkipAABBsKHR = 0x0200,
	};
	enum class RayFlagsShift : unsigned
	{
		NoneKHR = 0,
		OpaqueKHR = 1,
		NoOpaqueKHR = 2,
		TerminateOnFirstHitKHR = 3,
		SkipClosestHitShaderKHR = 4,
		CullBackFacingTrianglesKHR = 5,
		CullFrontFacingTrianglesKHR = 6,
		CullOpaqueKHR = 7,
		CullNoOpaqueKHR = 8,
		SkipTrianglesKHR = 9,
		SkipAABBsKHR = 10,
		Max = 0x7fffffff
	};
	enum class FragmentShadingRateMask : unsigned
	{
		Vertical2Pixels = 0x0001,
		Vertical4Pixels = 0x0002,
		Horizontal2Pixels = 0x0004,
		Horizontal4Pixels = 0x0008,
	};
	enum class FragmentShadingRateShift : unsigned
	{
		Vertical2Pixels = 0,
		Vertical4Pixels = 1,
		Horizontal2Pixels = 2,
		Horizontal4Pixels = 3,
		Max = 0x7fffffff
	};
	enum class SourceLanguage : unsigned
	{
		Unknown = 0,
		ESSL = 1,
		GLSL = 2,
		OpenCL_C = 3,
		OpenCL_CPP = 4,
		HLSL = 5,
		CPP_for_OpenCL = 6,
		SYCL = 7,
		Max = 0x7fffffff
	};
	enum class ExecutionModel : unsigned
	{
		Vertex = 0,
		TessellationControl = 1,
		TessellationEvaluation = 2,
		Geometry = 3,
		Fragment = 4,
		GLCompute = 5,
		Kernel = 6,
		TaskNV = 5267,
		MeshNV = 5268,
		RayGenerationNV = 5313,
		RayGenerationKHR = 5313,
		IntersectionNV = 5314,
		IntersectionKHR = 5314,
		AnyHitNV = 5315,
		AnyHitKHR = 5315,
		ClosestHitNV = 5316,
		ClosestHitKHR = 5316,
		MissNV = 5317,
		MissKHR = 5317,
		CallableNV = 5318,
		CallableKHR = 5318,
		Max = 0x7fffffff
	};
	enum class AddressingModel : unsigned
	{
		Logical = 0,
		Physical32 = 1,
		Physical64 = 2,
		PhysicalStorageBuffer64 = 5348,
		PhysicalStorageBuffer64EXT = 5348,
		Max = 0x7fffffff
	};
	enum class MemoryModel : unsigned
	{
		Simple = 0,
		GLSL450 = 1,
		OpenCL = 2,
		Vulkan = 3,
		VulkanKHR = 3,
		Max = 0x7fffffff
	};
	enum class ExecutionMode : unsigned
	{
		Invocations = 0,
		SpacingEqual = 1,
		SpacingFractionalEven = 2,
		SpacingFractionalOdd = 3,
		VertexOrderCw = 4,
		VertexOrderCcw = 5,
		PixelCenterInteger = 6,
		OriginUpperLeft = 7,
		OriginLowerLeft = 8,
		EarlyFragmentTests = 9,
		PointMode = 10,
		Xfb = 11,
		DepthReplacing = 12,
		DepthGreater = 14,
		DepthLess = 15,
		DepthUnchanged = 16,
		LocalSize = 17,
		LocalSizeHint = 18,
		InputPoints = 19,
		InputLines = 20,
		InputLinesAdjacency = 21,
		Triangles = 22,
		InputTrianglesAdjacency = 23,
		Quads = 24,
		Isolines = 25,
		OutputVertices = 26,
		OutputPoints = 27,
		OutputLineStrip = 28,
		OutputTriangleStrip = 29,
		VecTypeHint = 30,
		ContractionOff = 31,
		Initializer = 33,
		Finalizer = 34,
		SubgroupSize = 35,
		SubgroupsPerWorkgroup = 36,
		SubgroupsPerWorkgroupId = 37,
		LocalSizeId = 38,
		LocalSizeHintId = 39,
		SubgroupUniformControlFlowKHR = 4421,
		PostDepthCoverage = 4446,
		DenormPreserve = 4459,
		DenormFlushToZero = 4460,
		SignedZeroInfNanPreserve = 4461,
		RoundingModeRTE = 4462,
		RoundingModeRTZ = 4463,
		StencilRefReplacingEXT = 5027,
		OutputLinesNV = 5269,
		OutputPrimitivesNV = 5270,
		DerivativeGroupQuadsNV = 5289,
		DerivativeGroupLinearNV = 5290,
		OutputTrianglesNV = 5298,
		PixelInterlockOrderedEXT = 5366,
		PixelInterlockUnorderedEXT = 5367,
		SampleInterlockOrderedEXT = 5368,
		SampleInterlockUnorderedEXT = 5369,
		ShadingRateInterlockOrderedEXT = 5370,
		ShadingRateInterlockUnorderedEXT = 5371,
		SharedLocalMemorySizeINTEL = 5618,
		RoundingModeRTPINTEL = 5620,
		RoundingModeRTNINTEL = 5621,
		FloatingPointModeALTINTEL = 5622,
		FloatingPointModeIEEEINTEL = 5623,
		MaxWorkgroupSizeINTEL = 5893,
		MaxWorkDimINTEL = 5894,
		NoGlobalOffsetINTEL = 5895,
		NumSIMDWorkitemsINTEL = 5896,
		SchedulerTargetFmaxMhzINTEL = 5903,
		NamedBarrierCountINTEL = 6417,
		Max = 0x7fffffff
	};
	enum class StorageClass : unsigned
	{
		UniformConstant = 0,
		Input = 1,
		Uniform = 2,
		Output = 3,
		Workgroup = 4,
		CrossWorkgroup = 5,
		Private = 6,
		Function = 7,
		Generic = 8,
		PushConstant = 9,
		AtomicCounter = 10,
		Image = 11,
		StorageBuffer = 12,
		CallableDataNV = 5328,
		CallableDataKHR = 5328,
		IncomingCallableDataNV = 5329,
		IncomingCallableDataKHR = 5329,
		RayPayloadNV = 5338,
		RayPayloadKHR = 5338,
		HitAttributeNV = 5339,
		HitAttributeKHR = 5339,
		IncomingRayPayloadNV = 5342,
		IncomingRayPayloadKHR = 5342,
		ShaderRecordBufferNV = 5343,
		ShaderRecordBufferKHR = 5343,
		PhysicalStorageBuffer = 5349,
		PhysicalStorageBufferEXT = 5349,
		CodeSectionINTEL = 5605,
		DeviceOnlyINTEL = 5936,
		HostOnlyINTEL = 5937,
		Max = 0x7fffffff
	};
	enum class Dim : unsigned
	{
		Dim1D = 0,
		Dim2D = 1,
		Dim3D = 2,
		Cube = 3,
		Rect = 4,
		Buffer = 5,
		SubpassData = 6,
		Max = 0x7fffffff
	};
	enum class SamplerAddressingMode : unsigned
	{
		None = 0,
		ClampToEdge = 1,
		Clamp = 2,
		Repeat = 3,
		RepeatMirrored = 4,
		Max = 0x7fffffff
	};
	enum class SamplerFilterMode : unsigned
	{
		Nearest = 0,
		Linear = 1,
		Max = 0x7fffffff
	};
	enum class ImageFormat : unsigned
	{
		Unknown = 0,
		Rgba32f = 1,
		Rgba16f = 2,
		R32f = 3,
		Rgba8 = 4,
		Rgba8Snorm = 5,
		Rg32f = 6,
		Rg16f = 7,
		R11fG11fB10f = 8,
		R16f = 9,
		Rgba16 = 10,
		Rgb10A2 = 11,
		Rg16 = 12,
		Rg8 = 13,
		R16 = 14,
		R8 = 15,
		Rgba16Snorm = 16,
		Rg16Snorm = 17,
		Rg8Snorm = 18,
		R16Snorm = 19,
		R8Snorm = 20,
		Rgba32i = 21,
		Rgba16i = 22,
		Rgba8i = 23,
		R32i = 24,
		Rg32i = 25,
		Rg16i = 26,
		Rg8i = 27,
		R16i = 28,
		R8i = 29,
		Rgba32ui = 30,
		Rgba16ui = 31,
		Rgba8ui = 32,
		R32ui = 33,
		Rgb10a2ui = 34,
		Rg32ui = 35,
		Rg16ui = 36,
		Rg8ui = 37,
		R16ui = 38,
		R8ui = 39,
		R64ui = 40,
		R64i = 41,
		Max = 0x7fffffff
	};
	enum class ImageChannelOrder : unsigned
	{
		R = 0,
		A = 1,
		RG = 2,
		RA = 3,
		RGB = 4,
		RGBA = 5,
		BGRA = 6,
		ARGB = 7,
		Intensity = 8,
		Luminance = 9,
		Rx = 10,
		RGx = 11,
		RGBx = 12,
		Depth = 13,
		DepthStencil = 14,
		sRGB = 15,
		sRGBx = 16,
		sRGBA = 17,
		sBGRA = 18,
		ABGR = 19,
		Max = 0x7fffffff
	};
	enum class ImageChannelDataType : unsigned
	{
		SnormInt8 = 0,
		SnormInt16 = 1,
		UnormInt8 = 2,
		UnormInt16 = 3,
		UnormShort565 = 4,
		UnormShort555 = 5,
		UnormInt101010 = 6,
		SignedInt8 = 7,
		SignedInt16 = 8,
		SignedInt32 = 9,
		UnsignedInt8 = 10,
		UnsignedInt16 = 11,
		UnsignedInt32 = 12,
		HalfFloat = 13,
		Float = 14,
		UnormInt24 = 15,
		UnormInt101010_2 = 16,
		Max = 0x7fffffff
	};
	enum class FPRoundingMode : unsigned
	{
		RTE = 0,
		RTZ = 1,
		RTP = 2,
		RTN = 3,
		Max = 0x7fffffff
	};
	enum class FPDenormMode : unsigned
	{
		Preserve = 0,
		FlushToZero = 1,
		Max = 0x7fffffff
	};
	enum class QuantizationModes : unsigned
	{
		TRN = 0,
		TRN_ZERO = 1,
		RND = 2,
		RND_ZERO = 3,
		RND_INF = 4,
		RND_MIN_INF = 5,
		RND_CONV = 6,
		RND_CONV_ODD = 7,
		Max = 0x7fffffff
	};
	enum class FPOperationMode : unsigned
	{
		IEEE = 0,
		ALT = 1,
		Max = 0x7fffffff
	};
	enum class OverflowModes : unsigned
	{
		WRAP = 0,
		SAT = 1,
		SAT_ZERO = 2,
		SAT_SYM = 3,
		Max = 0x7fffffff
	};
	enum class LinkageType : unsigned
	{
		Export = 0,
		Import = 1,
		LinkOnceODR = 2,
		Max = 0x7fffffff
	};
	enum class AccessQualifier : unsigned
	{
		ReadOnly = 0,
		WriteOnly = 1,
		ReadWrite = 2,
		Max = 0x7fffffff
	};
	enum class FunctionParameterAttribute : unsigned
	{
		Zext = 0,
		Sext = 1,
		ByVal = 2,
		Sret = 3,
		NoAlias = 4,
		NoCapture = 5,
		NoWrite = 6,
		NoReadWrite = 7,
		Max = 0x7fffffff
	};
	enum class Decoration : unsigned
	{
		RelaxedPrecision = 0,
		SpecId = 1,
		Block = 2,
		BufferBlock = 3,
		RowMajor = 4,
		ColMajor = 5,
		ArrayStride = 6,
		MatrixStride = 7,
		GLSLShared = 8,
		GLSLPacked = 9,
		CPacked = 10,
		BuiltIn = 11,
		NoPerspective = 13,
		Flat = 14,
		Patch = 15,
		Centroid = 16,
		Sample = 17,
		Invariant = 18,
		Restrict = 19,
		Aliased = 20,
		Volatile = 21,
		Constant = 22,
		Coherent = 23,
		NonWritable = 24,
		NonReadable = 25,
		Uniform = 26,
		UniformId = 27,
		SaturatedConversion = 28,
		Stream = 29,
		Location = 30,
		Component = 31,
		Index = 32,
		Binding = 33,
		DescriptorSet = 34,
		Offset = 35,
		XfbBuffer = 36,
		XfbStride = 37,
		FuncParamAttr = 38,
		FPRoundingMode = 39,
		FPFastMathMode = 40,
		LinkageAttributes = 41,
		NoContraction = 42,
		InputAttachmentIndex = 43,
		Alignment = 44,
		MaxByteOffset = 45,
		AlignmentId = 46,
		MaxByteOffsetId = 47,
		NoSignedWrap = 4469,
		NoUnsignedWrap = 4470,
		ExplicitInterpAMD = 4999,
		OverrideCoverageNV = 5248,
		PassthroughNV = 5250,
		ViewportRelativeNV = 5252,
		SecondaryViewportRelativeNV = 5256,
		PerPrimitiveNV = 5271,
		PerViewNV = 5272,
		PerTaskNV = 5273,
		PerVertexKHR = 5285,
		PerVertexNV = 5285,
		NonUniform = 5300,
		NonUniformEXT = 5300,
		RestrictPointer = 5355,
		RestrictPointerEXT = 5355,
		AliasedPointer = 5356,
		AliasedPointerEXT = 5356,
		BindlessSamplerNV = 5398,
		BindlessImageNV = 5399,
		BoundSamplerNV = 5400,
		BoundImageNV = 5401,
		SIMTCallINTEL = 5599,
		ReferencedIndirectlyINTEL = 5602,
		ClobberINTEL = 5607,
		SideEffectsINTEL = 5608,
		VectorComputeVariableINTEL = 5624,
		FuncParamIOKindINTEL = 5625,
		VectorComputeFunctionINTEL = 5626,
		StackCallINTEL = 5627,
		GlobalVariableOffsetINTEL = 5628,
		CounterBuffer = 5634,
		HlslCounterBufferGOOGLE = 5634,
		UserSemantic = 5635,
		HlslSemanticGOOGLE = 5635,
		UserTypeGOOGLE = 5636,
		FunctionRoundingModeINTEL = 5822,
		FunctionDenormModeINTEL = 5823,
		RegisterINTEL = 5825,
		MemoryINTEL = 5826,
		NumbanksINTEL = 5827,
		BankwidthINTEL = 5828,
		MaxPrivateCopiesINTEL = 5829,
		SinglepumpINTEL = 5830,
		DoublepumpINTEL = 5831,
		MaxReplicatesINTEL = 5832,
		SimpleDualPortINTEL = 5833,
		MergeINTEL = 5834,
		BankBitsINTEL = 5835,
		ForcePow2DepthINTEL = 5836,
		BurstCoalesceINTEL = 5899,
		CacheSizeINTEL = 5900,
		DontStaticallyCoalesceINTEL = 5901,
		PrefetchINTEL = 5902,
		StallEnableINTEL = 5905,
		FuseLoopsInFunctionINTEL = 5907,
		AliasScopeINTEL = 5914,
		NoAliasINTEL = 5915,
		BufferLocationINTEL = 5921,
		IOPipeStorageINTEL = 5944,
		FunctionFloatingPointModeINTEL = 6080,
		SingleElementVectorINTEL = 6085,
		VectorComputeCallableFunctionINTEL = 6087,
		MediaBlockIOINTEL = 6140,
		Max = 0x7fffffff
	};
	enum class BuiltIn : unsigned
	{
		Position = 0,
		PointSize = 1,
		ClipDistance = 3,
		CullDistance = 4,
		VertexId = 5,
		InstanceId = 6,
		PrimitiveId = 7,
		InvocationId = 8,
		Layer = 9,
		ViewportIndex = 10,
		TessLevelOuter = 11,
		TessLevelInner = 12,
		TessCoord = 13,
		PatchVertices = 14,
		FragCoord = 15,
		PointCoord = 16,
		FrontFacing = 17,
		SampleId = 18,
		SamplePosition = 19,
		SampleMask = 20,
		FragDepth = 22,
		HelperInvocation = 23,
		NumWorkgroups = 24,
		WorkgroupSize = 25,
		WorkgroupId = 26,
		LocalInvocationId = 27,
		GlobalInvocationId = 28,
		LocalInvocationIndex = 29,
		WorkDim = 30,
		GlobalSize = 31,
		EnqueuedWorkgroupSize = 32,
		GlobalOffset = 33,
		GlobalLinearId = 34,
		SubgroupSize = 36,
		SubgroupMaxSize = 37,
		NumSubgroups = 38,
		NumEnqueuedSubgroups = 39,
		SubgroupId = 40,
		SubgroupLocalInvocationId = 41,
		VertexIndex = 42,
		InstanceIndex = 43,
		SubgroupEqMask = 4416,
		SubgroupEqMaskKHR = 4416,
		SubgroupGeMask = 4417,
		SubgroupGeMaskKHR = 4417,
		SubgroupGtMask = 4418,
		SubgroupGtMaskKHR = 4418,
		SubgroupLeMask = 4419,
		SubgroupLeMaskKHR = 4419,
		SubgroupLtMask = 4420,
		SubgroupLtMaskKHR = 4420,
		BaseVertex = 4424,
		BaseInstance = 4425,
		DrawIndex = 4426,
		PrimitiveShadingRateKHR = 4432,
		DeviceIndex = 4438,
		ViewIndex = 4440,
		ShadingRateKHR = 4444,
		BaryCoordNoPerspAMD = 4992,
		BaryCoordNoPerspCentroidAMD = 4993,
		BaryCoordNoPerspSampleAMD = 4994,
		BaryCoordSmoothAMD = 4995,
		BaryCoordSmoothCentroidAMD = 4996,
		BaryCoordSmoothSampleAMD = 4997,
		BaryCoordPullModelAMD = 4998,
		FragStencilRefEXT = 5014,
		ViewportMaskNV = 5253,
		SecondaryPositionNV = 5257,
		SecondaryViewportMaskNV = 5258,
		PositionPerViewNV = 5261,
		ViewportMaskPerViewNV = 5262,
		FullyCoveredEXT = 5264,
		TaskCountNV = 5274,
		PrimitiveCountNV = 5275,
		PrimitiveIndicesNV = 5276,
		ClipDistancePerViewNV = 5277,
		CullDistancePerViewNV = 5278,
		LayerPerViewNV = 5279,
		MeshViewCountNV = 5280,
		MeshViewIndicesNV = 5281,
		BaryCoordKHR = 5286,
		BaryCoordNV = 5286,
		BaryCoordNoPerspKHR = 5287,
		BaryCoordNoPerspNV = 5287,
		FragSizeEXT = 5292,
		FragmentSizeNV = 5292,
		FragInvocationCountEXT = 5293,
		InvocationsPerPixelNV = 5293,
		LaunchIdNV = 5319,
		LaunchIdKHR = 5319,
		LaunchSizeNV = 5320,
		LaunchSizeKHR = 5320,
		WorldRayOriginNV = 5321,
		WorldRayOriginKHR = 5321,
		WorldRayDirectionNV = 5322,
		WorldRayDirectionKHR = 5322,
		ObjectRayOriginNV = 5323,
		ObjectRayOriginKHR = 5323,
		ObjectRayDirectionNV = 5324,
		ObjectRayDirectionKHR = 5324,
		RayTminNV = 5325,
		RayTminKHR = 5325,
		RayTmaxNV = 5326,
		RayTmaxKHR = 5326,
		InstanceCustomIndexNV = 5327,
		InstanceCustomIndexKHR = 5327,
		ObjectToWorldNV = 5330,
		ObjectToWorldKHR = 5330,
		WorldToObjectNV = 5331,
		WorldToObjectKHR = 5331,
		HitTNV = 5332,
		HitKindNV = 5333,
		HitKindKHR = 5333,
		CurrentRayTimeNV = 5334,
		IncomingRayFlagsNV = 5351,
		IncomingRayFlagsKHR = 5351,
		RayGeometryIndexKHR = 5352,
		WarpsPerSMNV = 5374,
		SMCountNV = 5375,
		WarpIDNV = 5376,
		SMIDNV = 5377,
		Max = 0x7fffffff
	};
	enum class Scope : unsigned
	{
		CrossDevice = 0,
		Device = 1,
		Workgroup = 2,
		Subgroup = 3,
		Invocation = 4,
		QueueFamily = 5,
		QueueFamilyKHR = 5,
		ShaderCallKHR = 6,
		Max = 0x7fffffff
	};
	enum class GroupOperation : unsigned
	{
		Reduce = 0,
		InclusiveScan = 1,
		ExclusiveScan = 2,
		ClusteredReduce = 3,
		PartitionedReduceNV = 6,
		PartitionedInclusiveScanNV = 7,
		PartitionedExclusiveScanNV = 8,
		Max = 0x7fffffff
	};
	enum class KernelEnqueueFlags : unsigned
	{
		NoWait = 0,
		WaitKernel = 1,
		WaitWorkGroup = 2,
		Max = 0x7fffffff
	};
	enum class Capability : unsigned
	{
		Matrix = 0,
		Shader = 1,
		Geometry = 2,
		Tessellation = 3,
		Addresses = 4,
		Linkage = 5,
		Kernel = 6,
		Vector16 = 7,
		Float16Buffer = 8,
		Float16 = 9,
		Float64 = 10,
		Int64 = 11,
		Int64Atomics = 12,
		ImageBasic = 13,
		ImageReadWrite = 14,
		ImageMipmap = 15,
		Pipes = 17,
		Groups = 18,
		DeviceEnqueue = 19,
		LiteralSampler = 20,
		AtomicStorage = 21,
		Int16 = 22,
		TessellationPointSize = 23,
		GeometryPointSize = 24,
		ImageGatherExtended = 25,
		StorageImageMultisample = 27,
		UniformBufferArrayDynamicIndexing = 28,
		SampledImageArrayDynamicIndexing = 29,
		StorageBufferArrayDynamicIndexing = 30,
		StorageImageArrayDynamicIndexing = 31,
		ClipDistance = 32,
		CullDistance = 33,
		ImageCubeArray = 34,
		SampleRateShading = 35,
		ImageRect = 36,
		SampledRect = 37,
		GenericPointer = 38,
		Int8 = 39,
		InputAttachment = 40,
		SparseResidency = 41,
		MinLod = 42,
		Sampled1D = 43,
		Image1D = 44,
		SampledCubeArray = 45,
		SampledBuffer = 46,
		ImageBuffer = 47,
		ImageMSArray = 48,
		StorageImageExtendedFormats = 49,
		ImageQuery = 50,
		DerivativeControl = 51,
		InterpolationFunction = 52,
		TransformFeedback = 53,
		GeometryStreams = 54,
		StorageImageReadWithoutFormat = 55,
		StorageImageWriteWithoutFormat = 56,
		MultiViewport = 57,
		SubgroupDispatch = 58,
		NamedBarrier = 59,
		PipeStorage = 60,
		GroupNonUniform = 61,
		GroupNonUniformVote = 62,
		GroupNonUniformArithmetic = 63,
		GroupNonUniformBallot = 64,
		GroupNonUniformShuffle = 65,
		GroupNonUniformShuffleRelative = 66,
		GroupNonUniformClustered = 67,
		GroupNonUniformQuad = 68,
		ShaderLayer = 69,
		ShaderViewportIndex = 70,
		UniformDecoration = 71,
		FragmentShadingRateKHR = 4422,
		SubgroupBallotKHR = 4423,
		DrawParameters = 4427,
		WorkgroupMemoryExplicitLayoutKHR = 4428,
		WorkgroupMemoryExplicitLayout8BitAccessKHR = 4429,
		WorkgroupMemoryExplicitLayout16BitAccessKHR = 4430,
		SubgroupVoteKHR = 4431,
		StorageBuffer16BitAccess = 4433,
		StorageUniformBufferBlock16 = 4433,
		UniformAndStorageBuffer16BitAccess = 4434,
		StorageUniform16 = 4434,
		StoragePushConstant16 = 4435,
		StorageInputOutput16 = 4436,
		DeviceGroup = 4437,
		MultiView = 4439,
		VariablePointersStorageBuffer = 4441,
		VariablePointers = 4442,
		AtomicStorageOps = 4445,
		SampleMaskPostDepthCoverage = 4447,
		StorageBuffer8BitAccess = 4448,
		UniformAndStorageBuffer8BitAccess = 4449,
		StoragePushConstant8 = 4450,
		DenormPreserve = 4464,
		DenormFlushToZero = 4465,
		SignedZeroInfNanPreserve = 4466,
		RoundingModeRTE = 4467,
		RoundingModeRTZ = 4468,
		RayQueryProvisionalKHR = 4471,
		RayQueryKHR = 4472,
		RayTraversalPrimitiveCullingKHR = 4478,
		RayTracingKHR = 4479,
		Float16ImageAMD = 5008,
		ImageGatherBiasLodAMD = 5009,
		FragmentMaskAMD = 5010,
		StencilExportEXT = 5013,
		ImageReadWriteLodAMD = 5015,
		Int64ImageEXT = 5016,
		ShaderClockKHR = 5055,
		SampleMaskOverrideCoverageNV = 5249,
		GeometryShaderPassthroughNV = 5251,
		ShaderViewportIndexLayerEXT = 5254,
		ShaderViewportIndexLayerNV = 5254,
		ShaderViewportMaskNV = 5255,
		ShaderStereoViewNV = 5259,
		PerViewAttributesNV = 5260,
		FragmentFullyCoveredEXT = 5265,
		MeshShadingNV = 5266,
		ImageFootprintNV = 5282,
		FragmentBarycentricKHR = 5284,
		FragmentBarycentricNV = 5284,
		ComputeDerivativeGroupQuadsNV = 5288,
		FragmentDensityEXT = 5291,
		ShadingRateNV = 5291,
		GroupNonUniformPartitionedNV = 5297,
		ShaderNonUniform = 5301,
		ShaderNonUniformEXT = 5301,
		RuntimeDescriptorArray = 5302,
		RuntimeDescriptorArrayEXT = 5302,
		InputAttachmentArrayDynamicIndexing = 5303,
		InputAttachmentArrayDynamicIndexingEXT = 5303,
		UniformTexelBufferArrayDynamicIndexing = 5304,
		UniformTexelBufferArrayDynamicIndexingEXT = 5304,
		StorageTexelBufferArrayDynamicIndexing = 5305,
		StorageTexelBufferArrayDynamicIndexingEXT = 5305,
		UniformBufferArrayNonUniformIndexing = 5306,
		UniformBufferArrayNonUniformIndexingEXT = 5306,
		SampledImageArrayNonUniformIndexing = 5307,
		SampledImageArrayNonUniformIndexingEXT = 5307,
		StorageBufferArrayNonUniformIndexing = 5308,
		StorageBufferArrayNonUniformIndexingEXT = 5308,
		StorageImageArrayNonUniformIndexing = 5309,
		StorageImageArrayNonUniformIndexingEXT = 5309,
		InputAttachmentArrayNonUniformIndexing = 5310,
		InputAttachmentArrayNonUniformIndexingEXT = 5310,
		UniformTexelBufferArrayNonUniformIndexing = 5311,
		UniformTexelBufferArrayNonUniformIndexingEXT = 5311,
		StorageTexelBufferArrayNonUniformIndexing = 5312,
		StorageTexelBufferArrayNonUniformIndexingEXT = 5312,
		RayTracingNV = 5340,
		RayTracingMotionBlurNV = 5341,
		VulkanMemoryModel = 5345,
		VulkanMemoryModelKHR = 5345,
		VulkanMemoryModelDeviceScope = 5346,
		VulkanMemoryModelDeviceScopeKHR = 5346,
		PhysicalStorageBufferAddresses = 5347,
		PhysicalStorageBufferAddressesEXT = 5347,
		ComputeDerivativeGroupLinearNV = 5350,
		RayTracingProvisionalKHR = 5353,
		CooperativeMatrixNV = 5357,
		FragmentShaderSampleInterlockEXT = 5363,
		FragmentShaderShadingRateInterlockEXT = 5372,
		ShaderSMBuiltinsNV = 5373,
		FragmentShaderPixelInterlockEXT = 5378,
		DemoteToHelperInvocation = 5379,
		DemoteToHelperInvocationEXT = 5379,
		BindlessTextureNV = 5390,
		SubgroupShuffleINTEL = 5568,
		SubgroupBufferBlockIOINTEL = 5569,
		SubgroupImageBlockIOINTEL = 5570,
		SubgroupImageMediaBlockIOINTEL = 5579,
		RoundToInfinityINTEL = 5582,
		FloatingPointModeINTEL = 5583,
		IntegerFunctions2INTEL = 5584,
		FunctionPointersINTEL = 5603,
		IndirectReferencesINTEL = 5604,
		AsmINTEL = 5606,
		AtomicFloat32MinMaxEXT = 5612,
		AtomicFloat64MinMaxEXT = 5613,
		AtomicFloat16MinMaxEXT = 5616,
		VectorComputeINTEL = 5617,
		VectorAnyINTEL = 5619,
		ExpectAssumeKHR = 5629,
		SubgroupAvcMotionEstimationINTEL = 5696,
		SubgroupAvcMotionEstimationIntraINTEL = 5697,
		SubgroupAvcMotionEstimationChromaINTEL = 5698,
		VariableLengthArrayINTEL = 5817,
		FunctionFloatControlINTEL = 5821,
		FPGAMemoryAttributesINTEL = 5824,
		FPFastMathModeINTEL = 5837,
		ArbitraryPrecisionIntegersINTEL = 5844,
		ArbitraryPrecisionFloatingPointINTEL = 5845,
		UnstructuredLoopControlsINTEL = 5886,
		FPGALoopControlsINTEL = 5888,
		KernelAttributesINTEL = 5892,
		FPGAKernelAttributesINTEL = 5897,
		FPGAMemoryAccessesINTEL = 5898,
		FPGAClusterAttributesINTEL = 5904,
		LoopFuseINTEL = 5906,
		MemoryAccessAliasingINTEL = 5910,
		FPGABufferLocationINTEL = 5920,
		ArbitraryPrecisionFixedPointINTEL = 5922,
		USMStorageClassesINTEL = 5935,
		IOPipesINTEL = 5943,
		BlockingPipesINTEL = 5945,
		FPGARegINTEL = 5948,
		DotProductInputAll = 6016,
		DotProductInputAllKHR = 6016,
		DotProductInput4x8Bit = 6017,
		DotProductInput4x8BitKHR = 6017,
		DotProductInput4x8BitPacked = 6018,
		DotProductInput4x8BitPackedKHR = 6018,
		DotProduct = 6019,
		DotProductKHR = 6019,
		BitInstructions = 6025,
		AtomicFloat32AddEXT = 6033,
		AtomicFloat64AddEXT = 6034,
		LongConstantCompositeINTEL = 6089,
		OptNoneINTEL = 6094,
		AtomicFloat16AddEXT = 6095,
		DebugInfoModuleINTEL = 6114,
		SplitBarrierINTEL = 6141,
		GroupUniformArithmeticKHR = 6400,
		Max = 0x7fffffff
	};
	enum class RayQueryIntersection : unsigned
	{
		RayQueryCandidateIntersectionKHR = 0,
		RayQueryCommittedIntersectionKHR = 1,
		Max = 0x7fffffff
	};
	enum class RayQueryCommittedIntersectionType : unsigned
	{
		RayQueryCommittedIntersectionNoneKHR = 0,
		RayQueryCommittedIntersectionTriangleKHR = 1,
		RayQueryCommittedIntersectionGeneratedKHR = 2,
		Max = 0x7fffffff
	};
	enum class RayQueryCandidateIntersectionType : unsigned
	{
		RayQueryCandidateIntersectionTriangleKHR = 0,
		RayQueryCandidateIntersectionAABBKHR = 1,
		Max = 0x7fffffff
	};
	enum class PackedVectorFormat : unsigned
	{
		PackedVectorFormat4x8Bit = 0,
		PackedVectorFormat4x8BitKHR = 0,
		Max = 0x7fffffff
	};
	enum class Op : unsigned
	{
		OpNop = 0,
		OpUndef = 1,
		OpSourceContinued = 2,
		OpSource = 3,
		OpSourceExtension = 4,
		OpName = 5,
		OpMemberName = 6,
		OpString = 7,
		OpLine = 8,
		OpExtension = 10,
		OpExtInstImport = 11,
		OpExtInst = 12,
		OpMemoryModel = 14,
		OpEntryPoint = 15,
		OpExecutionMode = 16,
		OpCapability = 17,
		OpTypeVoid = 19,
		OpTypeBool = 20,
		OpTypeInt = 21,
		OpTypeFloat = 22,
		OpTypeVector = 23,
		OpTypeMatrix = 24,
		OpTypeImage = 25,
		OpTypeSampler = 26,
		OpTypeSampledImage = 27,
		OpTypeArray = 28,
		OpTypeRuntimeArray = 29,
		OpTypeStruct = 30,
		OpTypeOpaque = 31,
		OpTypePointer = 32,
		OpTypeFunction = 33,
		OpTypeEvent = 34,
		OpTypeDeviceEvent = 35,
		OpTypeReserveId = 36,
		OpTypeQueue = 37,
		OpTypePipe = 38,
		OpTypeForwardPointer = 39,
		OpConstantTrue = 41,
		OpConstantFalse = 42,
		OpConstant = 43,
		OpConstantComposite = 44,
		OpConstantSampler = 45,
		OpConstantNull = 46,
		OpSpecConstantTrue = 48,
		OpSpecConstantFalse = 49,
		OpSpecConstant = 50,
		OpSpecConstantComposite = 51,
		OpSpecConstantOp = 52,
		OpFunction = 54,
		OpFunctionParameter = 55,
		OpFunctionEnd = 56,
		OpFunctionCall = 57,
		OpVariable = 59,
		OpImageTexelPointer = 60,
		OpLoad = 61,
		OpStore = 62,
		OpCopyMemory = 63,
		OpCopyMemorySized = 64,
		OpAccessChain = 65,
		OpInBoundsAccessChain = 66,
		OpPtrAccessChain = 67,
		OpArrayLength = 68,
		OpGenericPtrMemSemantics = 69,
		OpInBoundsPtrAccessChain = 70,
		OpDecorate = 71,
		OpMemberDecorate = 72,
		OpDecorationGroup = 73,
		OpGroupDecorate = 74,
		OpGroupMemberDecorate = 75,
		OpVectorExtractDynamic = 77,
		OpVectorInsertDynamic = 78,
		OpVectorShuffle = 79,
		OpCompositeConstruct = 80,
		OpCompositeExtract = 81,
		OpCompositeInsert = 82,
		OpCopyObject = 83,
		OpTranspose = 84,
		OpSampledImage = 86,
		OpImageSampleImplicitLod = 87,
		OpImageSampleExplicitLod = 88,
		OpImageSampleDrefImplicitLod = 89,
		OpImageSampleDrefExplicitLod = 90,
		OpImageSampleProjImplicitLod = 91,
		OpImageSampleProjExplicitLod = 92,
		OpImageSampleProjDrefImplicitLod = 93,
		OpImageSampleProjDrefExplicitLod = 94,
		OpImageFetch = 95,
		OpImageGather = 96,
		OpImageDrefGather = 97,
		OpImageRead = 98,
		OpImageWrite = 99,
		OpImage = 100,
		OpImageQueryFormat = 101,
		OpImageQueryOrder = 102,
		OpImageQuerySizeLod = 103,
		OpImageQuerySize = 104,
		OpImageQueryLod = 105,
		OpImageQueryLevels = 106,
		OpImageQuerySamples = 107,
		OpConvertFToU = 109,
		OpConvertFToS = 110,
		OpConvertSToF = 111,
		OpConvertUToF = 112,
		OpUConvert = 113,
		OpSConvert = 114,
		OpFConvert = 115,
		OpQuantizeToF16 = 116,
		OpConvertPtrToU = 117,
		OpSatConvertSToU = 118,
		OpSatConvertUToS = 119,
		OpConvertUToPtr = 120,
		OpPtrCastToGeneric = 121,
		OpGenericCastToPtr = 122,
		OpGenericCastToPtrExplicit = 123,
		OpBitcast = 124,
		OpSNegate = 126,
		OpFNegate = 127,
		OpIAdd = 128,
		OpFAdd = 129,
		OpISub = 130,
		OpFSub = 131,
		OpIMul = 132,
		OpFMul = 133,
		OpUDiv = 134,
		OpSDiv = 135,
		OpFDiv = 136,
		OpUMod = 137,
		OpSRem = 138,
		OpSMod = 139,
		OpFRem = 140,
		OpFMod = 141,
		OpVectorTimesScalar = 142,
		OpMatrixTimesScalar = 143,
		OpVectorTimesMatrix = 144,
		OpMatrixTimesVector = 145,
		OpMatrixTimesMatrix = 146,
		OpOuterProduct = 147,
		OpDot = 148,
		OpIAddCarry = 149,
		OpISubBorrow = 150,
		OpUMulExtended = 151,
		OpSMulExtended = 152,
		OpAny = 154,
		OpAll = 155,
		OpIsNan = 156,
		OpIsInf = 157,
		OpIsFinite = 158,
		OpIsNormal = 159,
		OpSignBitSet = 160,
		OpLessOrGreater = 161,
		OpOrdered = 162,
		OpUnordered = 163,
		OpLogicalEqual = 164,
		OpLogicalNotEqual = 165,
		OpLogicalOr = 166,
		OpLogicalAnd = 167,
		OpLogicalNot = 168,
		OpSelect = 169,
		OpIEqual = 170,
		OpINotEqual = 171,
		OpUGreaterThan = 172,
		OpSGreaterThan = 173,
		OpUGreaterThanEqual = 174,
		OpSGreaterThanEqual = 175,
		OpULessThan = 176,
		OpSLessThan = 177,
		OpULessThanEqual = 178,
		OpSLessThanEqual = 179,
		OpFOrdEqual = 180,
		OpFUnordEqual = 181,
		OpFOrdNotEqual = 182,
		OpFUnordNotEqual = 183,
		OpFOrdLessThan = 184,
		OpFUnordLessThan = 185,
		OpFOrdGreaterThan = 186,
		OpFUnordGreaterThan = 187,
		OpFOrdLessThanEqual = 188,
		OpFUnordLessThanEqual = 189,
		OpFOrdGreaterThanEqual = 190,
		OpFUnordGreaterThanEqual = 191,
		OpShiftRightLogical = 194,
		OpShiftRightArithmetic = 195,
		OpShiftLeftLogical = 196,
		OpBitwiseOr = 197,
		OpBitwiseXor = 198,
		OpBitwiseAnd = 199,
		OpNot = 200,
		OpBitFieldInsert = 201,
		OpBitFieldSExtract = 202,
		OpBitFieldUExtract = 203,
		OpBitReverse = 204,
		OpBitCount = 205,
		OpDPdx = 207,
		OpDPdy = 208,
		OpFwidth = 209,
		OpDPdxFine = 210,
		OpDPdyFine = 211,
		OpFwidthFine = 212,
		OpDPdxCoarse = 213,
		OpDPdyCoarse = 214,
		OpFwidthCoarse = 215,
		OpEmitVertex = 218,
		OpEndPrimitive = 219,
		OpEmitStreamVertex = 220,
		OpEndStreamPrimitive = 221,
		OpControlBarrier = 224,
		OpMemoryBarrier = 225,
		OpAtomicLoad = 227,
		OpAtomicStore = 228,
		OpAtomicExchange = 229,
		OpAtomicCompareExchange = 230,
		OpAtomicCompareExchangeWeak = 231,
		OpAtomicIIncrement = 232,
		OpAtomicIDecrement = 233,
		OpAtomicIAdd = 234,
		OpAtomicISub = 235,
		OpAtomicSMin = 236,
		OpAtomicUMin = 237,
		OpAtomicSMax = 238,
		OpAtomicUMax = 239,
		OpAtomicAnd = 240,
		OpAtomicOr = 241,
		OpAtomicXor = 242,
		OpPhi = 245,
		OpLoopMerge = 246,
		OpSelectionMerge = 247,
		OpLabel = 248,
		OpBranch = 249,
		OpBranchConditional = 250,
		OpSwitch = 251,
		OpKill = 252,
		OpReturn = 253,
		OpReturnValue = 254,
		OpUnreachable = 255,
		OpLifetimeStart = 256,
		OpLifetimeStop = 257,
		OpGroupAsyncCopy = 259,
		OpGroupWaitEvents = 260,
		OpGroupAll = 261,
		OpGroupAny = 262,
		OpGroupBroadcast = 263,
		OpGroupIAdd = 264,
		OpGroupFAdd = 265,
		OpGroupFMin = 266,
		OpGroupUMin = 267,
		OpGroupSMin = 268,
		OpGroupFMax = 269,
		OpGroupUMax = 270,
		OpGroupSMax = 271,
		OpReadPipe = 274,
		OpWritePipe = 275,
		OpReservedReadPipe = 276,
		OpReservedWritePipe = 277,
		OpReserveReadPipePackets = 278,
		OpReserveWritePipePackets = 279,
		OpCommitReadPipe = 280,
		OpCommitWritePipe = 281,
		OpIsValidReserveId = 282,
		OpGetNumPipePackets = 283,
		OpGetMaxPipePackets = 284,
		OpGroupReserveReadPipePackets = 285,
		OpGroupReserveWritePipePackets = 286,
		OpGroupCommitReadPipe = 287,
		OpGroupCommitWritePipe = 288,
		OpEnqueueMarker = 291,
		OpEnqueueKernel = 292,
		OpGetKernelNDrangeSubGroupCount = 293,
		OpGetKernelNDrangeMaxSubGroupSize = 294,
		OpGetKernelWorkGroupSize = 295,
		OpGetKernelPreferredWorkGroupSizeMultiple = 296,
		OpRetainEvent = 297,
		OpReleaseEvent = 298,
		OpCreateUserEvent = 299,
		OpIsValidEvent = 300,
		OpSetUserEventStatus = 301,
		OpCaptureEventProfilingInfo = 302,
		OpGetDefaultQueue = 303,
		OpBuildNDRange = 304,
		OpImageSparseSampleImplicitLod = 305,
		OpImageSparseSampleExplicitLod = 306,
		OpImageSparseSampleDrefImplicitLod = 307,
		OpImageSparseSampleDrefExplicitLod = 308,
		OpImageSparseSampleProjImplicitLod = 309,
		OpImageSparseSampleProjExplicitLod = 310,
		OpImageSparseSampleProjDrefImplicitLod = 311,
		OpImageSparseSampleProjDrefExplicitLod = 312,
		OpImageSparseFetch = 313,
		OpImageSparseGather = 314,
		OpImageSparseDrefGather = 315,
		OpImageSparseTexelsResident = 316,
		OpNoLine = 317,
		OpAtomicFlagTestAndSet = 318,
		OpAtomicFlagClear = 319,
		OpImageSparseRead = 320,
		OpSizeOf = 321,
		OpTypePipeStorage = 322,
		OpConstantPipeStorage = 323,
		OpCreatePipeFromPipeStorage = 324,
		OpGetKernelLocalSizeForSubgroupCount = 325,
		OpGetKernelMaxNumSubgroups = 326,
		OpTypeNamedBarrier = 327,
		OpNamedBarrierInitialize = 328,
		OpMemoryNamedBarrier = 329,
		OpModuleProcessed = 330,
		OpExecutionModeId = 331,
		OpDecorateId = 332,
		OpGroupNonUniformElect = 333,
		OpGroupNonUniformAll = 334,
		OpGroupNonUniformAny = 335,
		OpGroupNonUniformAllEqual = 336,
		OpGroupNonUniformBroadcast = 337,
		OpGroupNonUniformBroadcastFirst = 338,
		OpGroupNonUniformBallot = 339,
		OpGroupNonUniformInverseBallot = 340,
		OpGroupNonUniformBallotBitExtract = 341,
		OpGroupNonUniformBallotBitCount = 342,
		OpGroupNonUniformBallotFindLSB = 343,
		OpGroupNonUniformBallotFindMSB = 344,
		OpGroupNonUniformShuffle = 345,
		OpGroupNonUniformShuffleXor = 346,
		OpGroupNonUniformShuffleUp = 347,
		OpGroupNonUniformShuffleDown = 348,
		OpGroupNonUniformIAdd = 349,
		OpGroupNonUniformFAdd = 350,
		OpGroupNonUniformIMul = 351,
		OpGroupNonUniformFMul = 352,
		OpGroupNonUniformSMin = 353,
		OpGroupNonUniformUMin = 354,
		OpGroupNonUniformFMin = 355,
		OpGroupNonUniformSMax = 356,
		OpGroupNonUniformUMax = 357,
		OpGroupNonUniformFMax = 358,
		OpGroupNonUniformBitwiseAnd = 359,
		OpGroupNonUniformBitwiseOr = 360,
		OpGroupNonUniformBitwiseXor = 361,
		OpGroupNonUniformLogicalAnd = 362,
		OpGroupNonUniformLogicalOr = 363,
		OpGroupNonUniformLogicalXor = 364,
		OpGroupNonUniformQuadBroadcast = 365,
		OpGroupNonUniformQuadSwap = 366,
		OpCopyLogical = 400,
		OpPtrEqual = 401,
		OpPtrNotEqual = 402,
		OpPtrDiff = 403,
		OpTerminateInvocation = 4416,
		OpSubgroupBallotKHR = 4421,
		OpSubgroupFirstInvocationKHR = 4422,
		OpSubgroupAllKHR = 4428,
		OpSubgroupAnyKHR = 4429,
		OpSubgroupAllEqualKHR = 4430,
		OpSubgroupReadInvocationKHR = 4432,
		OpTraceRayKHR = 4445,
		OpExecuteCallableKHR = 4446,
		OpConvertUToAccelerationStructureKHR = 4447,
		OpIgnoreIntersectionKHR = 4448,
		OpTerminateRayKHR = 4449,
		OpSDot = 4450,
		OpSDotKHR = 4450,
		OpUDot = 4451,
		OpUDotKHR = 4451,
		OpSUDot = 4452,
		OpSUDotKHR = 4452,
		OpSDotAccSat = 4453,
		OpSDotAccSatKHR = 4453,
		OpUDotAccSat = 4454,
		OpUDotAccSatKHR = 4454,
		OpSUDotAccSat = 4455,
		OpSUDotAccSatKHR = 4455,
		OpTypeRayQueryKHR = 4472,
		OpRayQueryInitializeKHR = 4473,
		OpRayQueryTerminateKHR = 4474,
		OpRayQueryGenerateIntersectionKHR = 4475,
		OpRayQueryConfirmIntersectionKHR = 4476,
		OpRayQueryProceedKHR = 4477,
		OpRayQueryGetIntersectionTypeKHR = 4479,
		OpGroupIAddNonUniformAMD = 5000,
		OpGroupFAddNonUniformAMD = 5001,
		OpGroupFMinNonUniformAMD = 5002,
		OpGroupUMinNonUniformAMD = 5003,
		OpGroupSMinNonUniformAMD = 5004,
		OpGroupFMaxNonUniformAMD = 5005,
		OpGroupUMaxNonUniformAMD = 5006,
		OpGroupSMaxNonUniformAMD = 5007,
		OpFragmentMaskFetchAMD = 5011,
		OpFragmentFetchAMD = 5012,
		OpReadClockKHR = 5056,
		OpImageSampleFootprintNV = 5283,
		OpGroupNonUniformPartitionNV = 5296,
		OpWritePackedPrimitiveIndices4x8NV = 5299,
		OpReportIntersectionNV = 5334,
		OpReportIntersectionKHR = 5334,
		OpIgnoreIntersectionNV = 5335,
		OpTerminateRayNV = 5336,
		OpTraceNV = 5337,
		OpTraceMotionNV = 5338,
		OpTraceRayMotionNV = 5339,
		OpTypeAccelerationStructureNV = 5341,
		OpTypeAccelerationStructureKHR = 5341,
		OpExecuteCallableNV = 5344,
		OpTypeCooperativeMatrixNV = 5358,
		OpCooperativeMatrixLoadNV = 5359,
		OpCooperativeMatrixStoreNV = 5360,
		OpCooperativeMatrixMulAddNV = 5361,
		OpCooperativeMatrixLengthNV = 5362,
		OpBeginInvocationInterlockEXT = 5364,
		OpEndInvocationInterlockEXT = 5365,
		OpDemoteToHelperInvocation = 5380,
		OpDemoteToHelperInvocationEXT = 5380,
		OpIsHelperInvocationEXT = 5381,
		OpConvertUToImageNV = 5391,
		OpConvertUToSamplerNV = 5392,
		OpConvertImageToUNV = 5393,
		OpConvertSamplerToUNV = 5394,
		OpConvertUToSampledImageNV = 5395,
		OpConvertSampledImageToUNV = 5396,
		OpSamplerImageAddressingModeNV = 5397,
		OpSubgroupShuffleINTEL = 5571,
		OpSubgroupShuffleDownINTEL = 5572,
		OpSubgroupShuffleUpINTEL = 5573,
		OpSubgroupShuffleXorINTEL = 5574,
		OpSubgroupBlockReadINTEL = 5575,
		OpSubgroupBlockWriteINTEL = 5576,
		OpSubgroupImageBlockReadINTEL = 5577,
		OpSubgroupImageBlockWriteINTEL = 5578,
		OpSubgroupImageMediaBlockReadINTEL = 5580,
		OpSubgroupImageMediaBlockWriteINTEL = 5581,
		OpUCountLeadingZerosINTEL = 5585,
		OpUCountTrailingZerosINTEL = 5586,
		OpAbsISubINTEL = 5587,
		OpAbsUSubINTEL = 5588,
		OpIAddSatINTEL = 5589,
		OpUAddSatINTEL = 5590,
		OpIAverageINTEL = 5591,
		OpUAverageINTEL = 5592,
		OpIAverageRoundedINTEL = 5593,
		OpUAverageRoundedINTEL = 5594,
		OpISubSatINTEL = 5595,
		OpUSubSatINTEL = 5596,
		OpIMul32x16INTEL = 5597,
		OpUMul32x16INTEL = 5598,
		OpConstantFunctionPointerINTEL = 5600,
		OpFunctionPointerCallINTEL = 5601,
		OpAsmTargetINTEL = 5609,
		OpAsmINTEL = 5610,
		OpAsmCallINTEL = 5611,
		OpAtomicFMinEXT = 5614,
		OpAtomicFMaxEXT = 5615,
		OpAssumeTrueKHR = 5630,
		OpExpectKHR = 5631,
		OpDecorateString = 5632,
		OpDecorateStringGOOGLE = 5632,
		OpMemberDecorateString = 5633,
		OpMemberDecorateStringGOOGLE = 5633,
		OpVmeImageINTEL = 5699,
		OpTypeVmeImageINTEL = 5700,
		OpTypeAvcImePayloadINTEL = 5701,
		OpTypeAvcRefPayloadINTEL = 5702,
		OpTypeAvcSicPayloadINTEL = 5703,
		OpTypeAvcMcePayloadINTEL = 5704,
		OpTypeAvcMceResultINTEL = 5705,
		OpTypeAvcImeResultINTEL = 5706,
		OpTypeAvcImeResultSingleReferenceStreamoutINTEL = 5707,
		OpTypeAvcImeResultDualReferenceStreamoutINTEL = 5708,
		OpTypeAvcImeSingleReferenceStreaminINTEL = 5709,
		OpTypeAvcImeDualReferenceStreaminINTEL = 5710,
		OpTypeAvcRefResultINTEL = 5711,
		OpTypeAvcSicResultINTEL = 5712,
		OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL = 5713,
		OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL = 5714,
		OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL = 5715,
		OpSubgroupAvcMceSetInterShapePenaltyINTEL = 5716,
		OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL = 5717,
		OpSubgroupAvcMceSetInterDirectionPenaltyINTEL = 5718,
		OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL = 5719,
		OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL = 5720,
		OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL = 5721,
		OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL = 5722,
		OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL = 5723,
		OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL = 5724,
		OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL = 5725,
		OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL = 5726,
		OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL = 5727,
		OpSubgroupAvcMceSetAcOnlyHaarINTEL = 5728,
		OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL = 5729,
		OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL = 5730,
		OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL = 5731,
		OpSubgroupAvcMceConvertToImePayloadINTEL = 5732,
		OpSubgroupAvcMceConvertToImeResultINTEL = 5733,
		OpSubgroupAvcMceConvertToRefPayloadINTEL = 5734,
		OpSubgroupAvcMceConvertToRefResultINTEL = 5735,
		OpSubgroupAvcMceConvertToSicPayloadINTEL = 5736,
		OpSubgroupAvcMceConvertToSicResultINTEL = 5737,
		OpSubgroupAvcMceGetMotionVectorsINTEL = 5738,
		OpSubgroupAvcMceGetInterDistortionsINTEL = 5739,
		OpSubgroupAvcMceGetBestInterDistortionsINTEL = 5740,
		OpSubgroupAvcMceGetInterMajorShapeINTEL = 5741,
		OpSubgroupAvcMceGetInterMinorShapeINTEL = 5742,
		OpSubgroupAvcMceGetInterDirectionsINTEL = 5743,
		OpSubgroupAvcMceGetInterMotionVectorCountINTEL = 5744,
		OpSubgroupAvcMceGetInterReferenceIdsINTEL = 5745,
		OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL = 5746,
		OpSubgroupAvcImeInitializeINTEL = 5747,
		OpSubgroupAvcImeSetSingleReferenceINTEL = 5748,
		OpSubgroupAvcImeSetDualReferenceINTEL = 5749,
		OpSubgroupAvcImeRefWindowSizeINTEL = 5750,
		OpSubgroupAvcImeAdjustRefOffsetINTEL = 5751,
		OpSubgroupAvcImeConvertToMcePayloadINTEL = 5752,
		OpSubgroupAvcImeSetMaxMotionVectorCountINTEL = 5753,
		OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL = 5754,
		OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL = 5755,
		OpSubgroupAvcImeSetWeightedSadINTEL = 5756,
		OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL = 5757,
		OpSubgroupAvcImeEvaluateWithDualReferenceINTEL = 5758,
		OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL = 5759,
		OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL = 5760,
		OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL = 5761,
		OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL = 5762,
		OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL = 5763,
		OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL = 5764,
		OpSubgroupAvcImeConvertToMceResultINTEL = 5765,
		OpSubgroupAvcImeGetSingleReferenceStreaminINTEL = 5766,
		OpSubgroupAvcImeGetDualReferenceStreaminINTEL = 5767,
		OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL = 5768,
		OpSubgroupAvcImeStripDualReferenceStreamoutINTEL = 5769,
		OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL = 5770,
		OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL = 5771,
		OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL = 5772,
		OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL = 5773,
		OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL = 5774,
		OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL = 5775,
		OpSubgroupAvcImeGetBorderReachedINTEL = 5776,
		OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL = 5777,
		OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL = 5778,
		OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL = 5779,
		OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL = 5780,
		OpSubgroupAvcFmeInitializeINTEL = 5781,
		OpSubgroupAvcBmeInitializeINTEL = 5782,
		OpSubgroupAvcRefConvertToMcePayloadINTEL = 5783,
		OpSubgroupAvcRefSetBidirectionalMixDisableINTEL = 5784,
		OpSubgroupAvcRefSetBilinearFilterEnableINTEL = 5785,
		OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL = 5786,
		OpSubgroupAvcRefEvaluateWithDualReferenceINTEL = 5787,
		OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL = 5788,
		OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL = 5789,
		OpSubgroupAvcRefConvertToMceResultINTEL = 5790,
		OpSubgroupAvcSicInitializeINTEL = 5791,
		OpSubgroupAvcSicConfigureSkcINTEL = 5792,
		OpSubgroupAvcSicConfigureIpeLumaINTEL = 5793,
		OpSubgroupAvcSicConfigureIpeLumaChromaINTEL = 5794,
		OpSubgroupAvcSicGetMotionVectorMaskINTEL = 5795,
		OpSubgroupAvcSicConvertToMcePayloadINTEL = 5796,
		OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL = 5797,
		OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL = 5798,
		OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL = 5799,
		OpSubgroupAvcSicSetBilinearFilterEnableINTEL = 5800,
		OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL = 5801,
		OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL = 5802,
		OpSubgroupAvcSicEvaluateIpeINTEL = 5803,
		OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL = 5804,
		OpSubgroupAvcSicEvaluateWithDualReferenceINTEL = 5805,
		OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL = 5806,
		OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL = 5807,
		OpSubgroupAvcSicConvertToMceResultINTEL = 5808,
		OpSubgroupAvcSicGetIpeLumaShapeINTEL = 5809,
		OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL = 5810,
		OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL = 5811,
		OpSubgroupAvcSicGetPackedIpeLumaModesINTEL = 5812,
		OpSubgroupAvcSicGetIpeChromaModeINTEL = 5813,
		OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL = 5814,
		OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL = 5815,
		OpSubgroupAvcSicGetInterRawSadsINTEL = 5816,
		OpVariableLengthArrayINTEL = 5818,
		OpSaveMemoryINTEL = 5819,
		OpRestoreMemoryINTEL = 5820,
		OpArbitraryFloatSinCosPiINTEL = 5840,
		OpArbitraryFloatCastINTEL = 5841,
		OpArbitraryFloatCastFromIntINTEL = 5842,
		OpArbitraryFloatCastToIntINTEL = 5843,
		OpArbitraryFloatAddINTEL = 5846,
		OpArbitraryFloatSubINTEL = 5847,
		OpArbitraryFloatMulINTEL = 5848,
		OpArbitraryFloatDivINTEL = 5849,
		OpArbitraryFloatGTINTEL = 5850,
		OpArbitraryFloatGEINTEL = 5851,
		OpArbitraryFloatLTINTEL = 5852,
		OpArbitraryFloatLEINTEL = 5853,
		OpArbitraryFloatEQINTEL = 5854,
		OpArbitraryFloatRecipINTEL = 5855,
		OpArbitraryFloatRSqrtINTEL = 5856,
		OpArbitraryFloatCbrtINTEL = 5857,
		OpArbitraryFloatHypotINTEL = 5858,
		OpArbitraryFloatSqrtINTEL = 5859,
		OpArbitraryFloatLogINTEL = 5860,
		OpArbitraryFloatLog2INTEL = 5861,
		OpArbitraryFloatLog10INTEL = 5862,
		OpArbitraryFloatLog1pINTEL = 5863,
		OpArbitraryFloatExpINTEL = 5864,
		OpArbitraryFloatExp2INTEL = 5865,
		OpArbitraryFloatExp10INTEL = 5866,
		OpArbitraryFloatExpm1INTEL = 5867,
		OpArbitraryFloatSinINTEL = 5868,
		OpArbitraryFloatCosINTEL = 5869,
		OpArbitraryFloatSinCosINTEL = 5870,
		OpArbitraryFloatSinPiINTEL = 5871,
		OpArbitraryFloatCosPiINTEL = 5872,
		OpArbitraryFloatASinINTEL = 5873,
		OpArbitraryFloatASinPiINTEL = 5874,
		OpArbitraryFloatACosINTEL = 5875,
		OpArbitraryFloatACosPiINTEL = 5876,
		OpArbitraryFloatATanINTEL = 5877,
		OpArbitraryFloatATanPiINTEL = 5878,
		OpArbitraryFloatATan2INTEL = 5879,
		OpArbitraryFloatPowINTEL = 5880,
		OpArbitraryFloatPowRINTEL = 5881,
		OpArbitraryFloatPowNINTEL = 5882,
		OpLoopControlINTEL = 5887,
		OpAliasDomainDeclINTEL = 5911,
		OpAliasScopeDeclINTEL = 5912,
		OpAliasScopeListDeclINTEL = 5913,
		OpFixedSqrtINTEL = 5923,
		OpFixedRecipINTEL = 5924,
		OpFixedRsqrtINTEL = 5925,
		OpFixedSinINTEL = 5926,
		OpFixedCosINTEL = 5927,
		OpFixedSinCosINTEL = 5928,
		OpFixedSinPiINTEL = 5929,
		OpFixedCosPiINTEL = 5930,
		OpFixedSinCosPiINTEL = 5931,
		OpFixedLogINTEL = 5932,
		OpFixedExpINTEL = 5933,
		OpPtrCastToCrossWorkgroupINTEL = 5934,
		OpCrossWorkgroupCastToPtrINTEL = 5938,
		OpReadPipeBlockingINTEL = 5946,
		OpWritePipeBlockingINTEL = 5947,
		OpFPGARegINTEL = 5949,
		OpRayQueryGetRayTMinKHR = 6016,
		OpRayQueryGetRayFlagsKHR = 6017,
		OpRayQueryGetIntersectionTKHR = 6018,
		OpRayQueryGetIntersectionInstanceCustomIndexKHR = 6019,
		OpRayQueryGetIntersectionInstanceIdKHR = 6020,
		OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR = 6021,
		OpRayQueryGetIntersectionGeometryIndexKHR = 6022,
		OpRayQueryGetIntersectionPrimitiveIndexKHR = 6023,
		OpRayQueryGetIntersectionBarycentricsKHR = 6024,
		OpRayQueryGetIntersectionFrontFaceKHR = 6025,
		OpRayQueryGetIntersectionCandidateAABBOpaqueKHR = 6026,
		OpRayQueryGetIntersectionObjectRayDirectionKHR = 6027,
		OpRayQueryGetIntersectionObjectRayOriginKHR = 6028,
		OpRayQueryGetWorldRayDirectionKHR = 6029,
		OpRayQueryGetWorldRayOriginKHR = 6030,
		OpRayQueryGetIntersectionObjectToWorldKHR = 6031,
		OpRayQueryGetIntersectionWorldToObjectKHR = 6032,
		OpAtomicFAddEXT = 6035,
		OpTypeBufferSurfaceINTEL = 6086,
		OpTypeStructContinuedINTEL = 6090,
		OpConstantCompositeContinuedINTEL = 6091,
		OpSpecConstantCompositeContinuedINTEL = 6092,
		OpControlBarrierArriveINTEL = 6142,
		OpControlBarrierWaitINTEL = 6143,
		OpGroupIMulKHR = 6401,
		OpGroupFMulKHR = 6402,
		OpGroupBitwiseAndKHR = 6403,
		OpGroupBitwiseOrKHR = 6404,
		OpGroupBitwiseXorKHR = 6405,
		OpGroupLogicalAndKHR = 6406,
		OpGroupLogicalOrKHR = 6407,
		OpGroupLogicalXorKHR = 6408,
		Max = 0x7fffffff
	};
	enum class Extension : unsigned
	{
		SPV_AMD_gpu_shader_half_float_fetch = 0,
		SPV_AMD_shader_ballot = 1,
		SPV_AMD_shader_explicit_vertex_parameter = 2,
		SPV_AMD_shader_fragment_mask = 3,
		SPV_AMD_shader_image_load_store_lod = 4,
		SPV_AMD_texture_gather_bias_lod = 5,
		SPV_EXT_demote_to_helper_invocation = 6,
		SPV_EXT_descriptor_indexing = 7,
		SPV_EXT_fragment_fully_covered = 8,
		SPV_EXT_fragment_invocation_density = 9,
		SPV_EXT_fragment_shader_interlock = 10,
		SPV_EXT_physical_storage_buffer = 11,
		SPV_EXT_shader_atomic_float16_add = 12,
		SPV_EXT_shader_atomic_float_add = 13,
		SPV_EXT_shader_atomic_float_min_max = 14,
		SPV_EXT_shader_image_int64 = 15,
		SPV_EXT_shader_stencil_export = 16,
		SPV_EXT_shader_viewport_index_layer = 17,
		SPV_GOOGLE_decorate_string = 18,
		SPV_GOOGLE_hlsl_functionality1 = 19,
		SPV_GOOGLE_user_type = 20,
		SPV_INTEL_arbitrary_precision_fixed_point = 21,
		SPV_INTEL_arbitrary_precision_floating_point = 22,
		SPV_INTEL_arbitrary_precision_integers = 23,
		SPV_INTEL_blocking_pipes = 24,
		SPV_INTEL_debug_module = 25,
		SPV_INTEL_device_side_avc_motion_estimation = 26,
		SPV_INTEL_float_controls2 = 27,
		SPV_INTEL_fp_fast_math_mode = 28,
		SPV_INTEL_fpga_buffer_location = 29,
		SPV_INTEL_fpga_cluster_attributes = 30,
		SPV_INTEL_fpga_loop_controls = 31,
		SPV_INTEL_fpga_memory_accesses = 32,
		SPV_INTEL_fpga_memory_attributes = 33,
		SPV_INTEL_fpga_reg = 34,
		SPV_INTEL_function_pointers = 35,
		SPV_INTEL_inline_assembly = 36,
		SPV_INTEL_io_pipes = 37,
		SPV_INTEL_kernel_attributes = 38,
		SPV_INTEL_long_constant_composite = 39,
		SPV_INTEL_loop_fuse = 40,
		SPV_INTEL_media_block_io = 41,
		SPV_INTEL_memory_access_aliasing = 42,
		SPV_INTEL_optnone = 43,
		SPV_INTEL_shader_integer_functions2 = 44,
		SPV_INTEL_split_barrier = 45,
		SPV_INTEL_subgroups = 46,
		SPV_INTEL_unstructured_loop_controls = 47,
		SPV_INTEL_usm_storage_classes = 48,
		SPV_INTEL_variable_length_array = 49,
		SPV_INTEL_vector_compute = 50,
		SPV_KHR_16bit_storage = 51,
		SPV_KHR_8bit_storage = 52,
		SPV_KHR_bit_instructions = 53,
		SPV_KHR_device_group = 54,
		SPV_KHR_expect_assume = 55,
		SPV_KHR_float_controls = 56,
		SPV_KHR_fragment_shader_barycentric = 57,
		SPV_KHR_fragment_shading_rate = 58,
		SPV_KHR_integer_dot_product = 59,
		SPV_KHR_linkonce_odr = 60,
		SPV_KHR_multiview = 61,
		SPV_KHR_no_integer_wrap_decoration = 62,
		SPV_KHR_physical_storage_buffer = 63,
		SPV_KHR_post_depth_coverage = 64,
		SPV_KHR_ray_query = 65,
		SPV_KHR_ray_tracing = 66,
		SPV_KHR_shader_atomic_counter_ops = 67,
		SPV_KHR_shader_ballot = 68,
		SPV_KHR_shader_clock = 69,
		SPV_KHR_shader_draw_parameters = 70,
		SPV_KHR_storage_buffer_storage_class = 71,
		SPV_KHR_subgroup_uniform_control_flow = 72,
		SPV_KHR_subgroup_vote = 73,
		SPV_KHR_terminate_invocation = 74,
		SPV_KHR_uniform_group_instructions = 75,
		SPV_KHR_variable_pointers = 76,
		SPV_KHR_vulkan_memory_model = 77,
		SPV_KHR_workgroup_memory_explicit_layout = 78,
		SPV_NVX_multiview_per_view_attributes = 79,
		SPV_NV_bindless_texture = 80,
		SPV_NV_compute_shader_derivatives = 81,
		SPV_NV_cooperative_matrix = 82,
		SPV_NV_fragment_shader_barycentric = 83,
		SPV_NV_geometry_shader_passthrough = 84,
		SPV_NV_mesh_shader = 85,
		SPV_NV_ray_tracing = 86,
		SPV_NV_ray_tracing_motion_blur = 87,
		SPV_NV_sample_mask_override_coverage = 88,
		SPV_NV_shader_image_footprint = 89,
		SPV_NV_shader_sm_builtins = 90,
		SPV_NV_shader_subgroup_partitioned = 91,
		SPV_NV_shading_rate = 92,
		SPV_NV_stereo_view_rendering = 93,
		SPV_NV_viewport_array2 = 94,
		Max = 0x7fffffff
	};
	static constexpr const char* ExtensionNames[] =
	{
		"SPV_AMD_gpu_shader_half_float_fetch",
		"SPV_AMD_shader_ballot",
		"SPV_AMD_shader_explicit_vertex_parameter",
		"SPV_AMD_shader_fragment_mask",
		"SPV_AMD_shader_image_load_store_lod",
		"SPV_AMD_texture_gather_bias_lod",
		"SPV_EXT_demote_to_helper_invocation",
		"SPV_EXT_descriptor_indexing",
		"SPV_EXT_fragment_fully_covered",
		"SPV_EXT_fragment_invocation_density",
		"SPV_EXT_fragment_shader_interlock",
		"SPV_EXT_physical_storage_buffer",
		"SPV_EXT_shader_atomic_float16_add",
		"SPV_EXT_shader_atomic_float_add",
		"SPV_EXT_shader_atomic_float_min_max",
		"SPV_EXT_shader_image_int64",
		"SPV_EXT_shader_stencil_export",
		"SPV_EXT_shader_viewport_index_layer",
		"SPV_GOOGLE_decorate_string",
		"SPV_GOOGLE_hlsl_functionality1",
		"SPV_GOOGLE_user_type",
		"SPV_INTEL_arbitrary_precision_fixed_point",
		"SPV_INTEL_arbitrary_precision_floating_point",
		"SPV_INTEL_arbitrary_precision_integers",
		"SPV_INTEL_blocking_pipes",
		"SPV_INTEL_debug_module",
		"SPV_INTEL_device_side_avc_motion_estimation",
		"SPV_INTEL_float_controls2",
		"SPV_INTEL_fp_fast_math_mode",
		"SPV_INTEL_fpga_buffer_location",
		"SPV_INTEL_fpga_cluster_attributes",
		"SPV_INTEL_fpga_loop_controls",
		"SPV_INTEL_fpga_memory_accesses",
		"SPV_INTEL_fpga_memory_attributes",
		"SPV_INTEL_fpga_reg",
		"SPV_INTEL_function_pointers",
		"SPV_INTEL_inline_assembly",
		"SPV_INTEL_io_pipes",
		"SPV_INTEL_kernel_attributes",
		"SPV_INTEL_long_constant_composite",
		"SPV_INTEL_loop_fuse",
		"SPV_INTEL_media_block_io",
		"SPV_INTEL_memory_access_aliasing",
		"SPV_INTEL_optnone",
		"SPV_INTEL_shader_integer_functions2",
		"SPV_INTEL_split_barrier",
		"SPV_INTEL_subgroups",
		"SPV_INTEL_unstructured_loop_controls",
		"SPV_INTEL_usm_storage_classes",
		"SPV_INTEL_variable_length_array",
		"SPV_INTEL_vector_compute",
		"SPV_KHR_16bit_storage",
		"SPV_KHR_8bit_storage",
		"SPV_KHR_bit_instructions",
		"SPV_KHR_device_group",
		"SPV_KHR_expect_assume",
		"SPV_KHR_float_controls",
		"SPV_KHR_fragment_shader_barycentric",
		"SPV_KHR_fragment_shading_rate",
		"SPV_KHR_integer_dot_product",
		"SPV_KHR_linkonce_odr",
		"SPV_KHR_multiview",
		"SPV_KHR_no_integer_wrap_decoration",
		"SPV_KHR_physical_storage_buffer",
		"SPV_KHR_post_depth_coverage",
		"SPV_KHR_ray_query",
		"SPV_KHR_ray_tracing",
		"SPV_KHR_shader_atomic_counter_ops",
		"SPV_KHR_shader_ballot",
		"SPV_KHR_shader_clock",
		"SPV_KHR_shader_draw_parameters",
		"SPV_KHR_storage_buffer_storage_class",
		"SPV_KHR_subgroup_uniform_control_flow",
		"SPV_KHR_subgroup_vote",
		"SPV_KHR_terminate_invocation",
		"SPV_KHR_uniform_group_instructions",
		"SPV_KHR_variable_pointers",
		"SPV_KHR_vulkan_memory_model",
		"SPV_KHR_workgroup_memory_explicit_layout",
		"SPV_NVX_multiview_per_view_attributes",
		"SPV_NV_bindless_texture",
		"SPV_NV_compute_shader_derivatives",
		"SPV_NV_cooperative_matrix",
		"SPV_NV_fragment_shader_barycentric",
		"SPV_NV_geometry_shader_passthrough",
		"SPV_NV_mesh_shader",
		"SPV_NV_ray_tracing",
		"SPV_NV_ray_tracing_motion_blur",
		"SPV_NV_sample_mask_override_coverage",
		"SPV_NV_shader_image_footprint",
		"SPV_NV_shader_sm_builtins",
		"SPV_NV_shader_subgroup_partitioned",
		"SPV_NV_shading_rate",
		"SPV_NV_stereo_view_rendering",
		"SPV_NV_viewport_array2",
	};
	inline void HasResultAndType(Op opcode, bool *hasResult, bool *hasResultType) {
		*hasResult = *hasResultType = false;
		switch (opcode) {
		default: /* unknown opcode */ break;
		case Op::OpUndef: *hasResult = true; *hasResultType = true; break;
		case Op::OpString: *hasResult = true; *hasResultType = false; break;
		case Op::OpExtInstImport: *hasResult = true; *hasResultType = false; break;
		case Op::OpExtInst: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeVoid: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeBool: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeInt: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeFloat: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeVector: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeMatrix: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeImage: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeSampler: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeSampledImage: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeArray: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeRuntimeArray: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeStruct: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeOpaque: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypePointer: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeFunction: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeEvent: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeDeviceEvent: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeReserveId: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeQueue: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypePipe: *hasResult = true; *hasResultType = false; break;
		case Op::OpConstantTrue: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstantFalse: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstant: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstantComposite: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstantSampler: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstantNull: *hasResult = true; *hasResultType = true; break;
		case Op::OpSpecConstantTrue: *hasResult = true; *hasResultType = true; break;
		case Op::OpSpecConstantFalse: *hasResult = true; *hasResultType = true; break;
		case Op::OpSpecConstant: *hasResult = true; *hasResultType = true; break;
		case Op::OpSpecConstantComposite: *hasResult = true; *hasResultType = true; break;
		case Op::OpSpecConstantOp: *hasResult = true; *hasResultType = true; break;
		case Op::OpFunction: *hasResult = true; *hasResultType = true; break;
		case Op::OpFunctionParameter: *hasResult = true; *hasResultType = true; break;
		case Op::OpFunctionCall: *hasResult = true; *hasResultType = true; break;
		case Op::OpVariable: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageTexelPointer: *hasResult = true; *hasResultType = true; break;
		case Op::OpLoad: *hasResult = true; *hasResultType = true; break;
		case Op::OpAccessChain: *hasResult = true; *hasResultType = true; break;
		case Op::OpInBoundsAccessChain: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrAccessChain: *hasResult = true; *hasResultType = true; break;
		case Op::OpArrayLength: *hasResult = true; *hasResultType = true; break;
		case Op::OpGenericPtrMemSemantics: *hasResult = true; *hasResultType = true; break;
		case Op::OpInBoundsPtrAccessChain: *hasResult = true; *hasResultType = true; break;
		case Op::OpDecorationGroup: *hasResult = true; *hasResultType = false; break;
		case Op::OpVectorExtractDynamic: *hasResult = true; *hasResultType = true; break;
		case Op::OpVectorInsertDynamic: *hasResult = true; *hasResultType = true; break;
		case Op::OpVectorShuffle: *hasResult = true; *hasResultType = true; break;
		case Op::OpCompositeConstruct: *hasResult = true; *hasResultType = true; break;
		case Op::OpCompositeExtract: *hasResult = true; *hasResultType = true; break;
		case Op::OpCompositeInsert: *hasResult = true; *hasResultType = true; break;
		case Op::OpCopyObject: *hasResult = true; *hasResultType = true; break;
		case Op::OpTranspose: *hasResult = true; *hasResultType = true; break;
		case Op::OpSampledImage: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleDrefImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleDrefExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleProjImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleProjExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleProjDrefImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleProjDrefExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageFetch: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageGather: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageDrefGather: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageRead: *hasResult = true; *hasResultType = true; break;
		case Op::OpImage: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQueryFormat: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQueryOrder: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQuerySizeLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQuerySize: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQueryLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQueryLevels: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageQuerySamples: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertFToU: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertFToS: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertSToF: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToF: *hasResult = true; *hasResultType = true; break;
		case Op::OpUConvert: *hasResult = true; *hasResultType = true; break;
		case Op::OpSConvert: *hasResult = true; *hasResultType = true; break;
		case Op::OpFConvert: *hasResult = true; *hasResultType = true; break;
		case Op::OpQuantizeToF16: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertPtrToU: *hasResult = true; *hasResultType = true; break;
		case Op::OpSatConvertSToU: *hasResult = true; *hasResultType = true; break;
		case Op::OpSatConvertUToS: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToPtr: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrCastToGeneric: *hasResult = true; *hasResultType = true; break;
		case Op::OpGenericCastToPtr: *hasResult = true; *hasResultType = true; break;
		case Op::OpGenericCastToPtrExplicit: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitcast: *hasResult = true; *hasResultType = true; break;
		case Op::OpSNegate: *hasResult = true; *hasResultType = true; break;
		case Op::OpFNegate: *hasResult = true; *hasResultType = true; break;
		case Op::OpIAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpFAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpISub: *hasResult = true; *hasResultType = true; break;
		case Op::OpFSub: *hasResult = true; *hasResultType = true; break;
		case Op::OpIMul: *hasResult = true; *hasResultType = true; break;
		case Op::OpFMul: *hasResult = true; *hasResultType = true; break;
		case Op::OpUDiv: *hasResult = true; *hasResultType = true; break;
		case Op::OpSDiv: *hasResult = true; *hasResultType = true; break;
		case Op::OpFDiv: *hasResult = true; *hasResultType = true; break;
		case Op::OpUMod: *hasResult = true; *hasResultType = true; break;
		case Op::OpSRem: *hasResult = true; *hasResultType = true; break;
		case Op::OpSMod: *hasResult = true; *hasResultType = true; break;
		case Op::OpFRem: *hasResult = true; *hasResultType = true; break;
		case Op::OpFMod: *hasResult = true; *hasResultType = true; break;
		case Op::OpVectorTimesScalar: *hasResult = true; *hasResultType = true; break;
		case Op::OpMatrixTimesScalar: *hasResult = true; *hasResultType = true; break;
		case Op::OpVectorTimesMatrix: *hasResult = true; *hasResultType = true; break;
		case Op::OpMatrixTimesVector: *hasResult = true; *hasResultType = true; break;
		case Op::OpMatrixTimesMatrix: *hasResult = true; *hasResultType = true; break;
		case Op::OpOuterProduct: *hasResult = true; *hasResultType = true; break;
		case Op::OpDot: *hasResult = true; *hasResultType = true; break;
		case Op::OpIAddCarry: *hasResult = true; *hasResultType = true; break;
		case Op::OpISubBorrow: *hasResult = true; *hasResultType = true; break;
		case Op::OpUMulExtended: *hasResult = true; *hasResultType = true; break;
		case Op::OpSMulExtended: *hasResult = true; *hasResultType = true; break;
		case Op::OpAny: *hasResult = true; *hasResultType = true; break;
		case Op::OpAll: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsNan: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsInf: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsFinite: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsNormal: *hasResult = true; *hasResultType = true; break;
		case Op::OpSignBitSet: *hasResult = true; *hasResultType = true; break;
		case Op::OpLessOrGreater: *hasResult = true; *hasResultType = true; break;
		case Op::OpOrdered: *hasResult = true; *hasResultType = true; break;
		case Op::OpUnordered: *hasResult = true; *hasResultType = true; break;
		case Op::OpLogicalEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpLogicalNotEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpLogicalOr: *hasResult = true; *hasResultType = true; break;
		case Op::OpLogicalAnd: *hasResult = true; *hasResultType = true; break;
		case Op::OpLogicalNot: *hasResult = true; *hasResultType = true; break;
		case Op::OpSelect: *hasResult = true; *hasResultType = true; break;
		case Op::OpIEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpINotEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpUGreaterThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpSGreaterThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpUGreaterThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpSGreaterThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpULessThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpSLessThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpULessThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpSLessThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdNotEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordNotEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdLessThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordLessThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdGreaterThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordGreaterThan: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdLessThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordLessThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFOrdGreaterThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpFUnordGreaterThanEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpShiftRightLogical: *hasResult = true; *hasResultType = true; break;
		case Op::OpShiftRightArithmetic: *hasResult = true; *hasResultType = true; break;
		case Op::OpShiftLeftLogical: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitwiseOr: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitwiseXor: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitwiseAnd: *hasResult = true; *hasResultType = true; break;
		case Op::OpNot: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitFieldInsert: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitFieldSExtract: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitFieldUExtract: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitReverse: *hasResult = true; *hasResultType = true; break;
		case Op::OpBitCount: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdx: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdy: *hasResult = true; *hasResultType = true; break;
		case Op::OpFwidth: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdxFine: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdyFine: *hasResult = true; *hasResultType = true; break;
		case Op::OpFwidthFine: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdxCoarse: *hasResult = true; *hasResultType = true; break;
		case Op::OpDPdyCoarse: *hasResult = true; *hasResultType = true; break;
		case Op::OpFwidthCoarse: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicLoad: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicExchange: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicCompareExchange: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicCompareExchangeWeak: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicIIncrement: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicIDecrement: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicIAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicISub: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicSMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicUMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicSMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicUMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicAnd: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicOr: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicXor: *hasResult = true; *hasResultType = true; break;
		case Op::OpPhi: *hasResult = true; *hasResultType = true; break;
		case Op::OpLabel: *hasResult = true; *hasResultType = false; break;
		case Op::OpGroupAsyncCopy: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupAll: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupAny: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupBroadcast: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupIAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupUMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupSMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupUMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupSMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpReadPipe: *hasResult = true; *hasResultType = true; break;
		case Op::OpWritePipe: *hasResult = true; *hasResultType = true; break;
		case Op::OpReservedReadPipe: *hasResult = true; *hasResultType = true; break;
		case Op::OpReservedWritePipe: *hasResult = true; *hasResultType = true; break;
		case Op::OpReserveReadPipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpReserveWritePipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsValidReserveId: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetNumPipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetMaxPipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupReserveReadPipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupReserveWritePipePackets: *hasResult = true; *hasResultType = true; break;
		case Op::OpEnqueueMarker: *hasResult = true; *hasResultType = true; break;
		case Op::OpEnqueueKernel: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelNDrangeSubGroupCount: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelNDrangeMaxSubGroupSize: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelWorkGroupSize: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelPreferredWorkGroupSizeMultiple: *hasResult = true; *hasResultType = true; break;
		case Op::OpCreateUserEvent: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsValidEvent: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetDefaultQueue: *hasResult = true; *hasResultType = true; break;
		case Op::OpBuildNDRange: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleDrefImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleDrefExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleProjImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleProjExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleProjDrefImplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseSampleProjDrefExplicitLod: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseFetch: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseGather: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseDrefGather: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseTexelsResident: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicFlagTestAndSet: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSparseRead: *hasResult = true; *hasResultType = true; break;
		case Op::OpSizeOf: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypePipeStorage: *hasResult = true; *hasResultType = false; break;
		case Op::OpConstantPipeStorage: *hasResult = true; *hasResultType = true; break;
		case Op::OpCreatePipeFromPipeStorage: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelLocalSizeForSubgroupCount: *hasResult = true; *hasResultType = true; break;
		case Op::OpGetKernelMaxNumSubgroups: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeNamedBarrier: *hasResult = true; *hasResultType = false; break;
		case Op::OpNamedBarrierInitialize: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformElect: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformAll: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformAny: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformAllEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBroadcast: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBroadcastFirst: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBallot: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformInverseBallot: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBallotBitExtract: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBallotBitCount: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBallotFindLSB: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBallotFindMSB: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformShuffle: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformShuffleXor: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformShuffleUp: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformShuffleDown: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformIAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformFAdd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformIMul: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformFMul: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformSMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformUMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformFMin: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformSMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformUMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformFMax: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBitwiseAnd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBitwiseOr: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformBitwiseXor: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformLogicalAnd: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformLogicalOr: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformLogicalXor: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformQuadBroadcast: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformQuadSwap: *hasResult = true; *hasResultType = true; break;
		case Op::OpCopyLogical: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrNotEqual: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrDiff: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupBallotKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupFirstInvocationKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAllKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAnyKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAllEqualKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupReadInvocationKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToAccelerationStructureKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpSDot: *hasResult = true; *hasResultType = true; break;
		case Op::OpUDot: *hasResult = true; *hasResultType = true; break;
		case Op::OpSUDot: *hasResult = true; *hasResultType = true; break;
		case Op::OpSDotAccSat: *hasResult = true; *hasResultType = true; break;
		case Op::OpUDotAccSat: *hasResult = true; *hasResultType = true; break;
		case Op::OpSUDotAccSat: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeRayQueryKHR: *hasResult = true; *hasResultType = false; break;
		case Op::OpRayQueryProceedKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionTypeKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupIAddNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFAddNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFMinNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupUMinNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupSMinNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFMaxNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupUMaxNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupSMaxNonUniformAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpFragmentMaskFetchAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpFragmentFetchAMD: *hasResult = true; *hasResultType = true; break;
		case Op::OpReadClockKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpImageSampleFootprintNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupNonUniformPartitionNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpReportIntersectionNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeAccelerationStructureNV: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeCooperativeMatrixNV: *hasResult = true; *hasResultType = false; break;
		case Op::OpCooperativeMatrixLoadNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpCooperativeMatrixMulAddNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpCooperativeMatrixLengthNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpIsHelperInvocationEXT: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToImageNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToSamplerNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertImageToUNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertSamplerToUNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertUToSampledImageNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpConvertSampledImageToUNV: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupShuffleINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupShuffleDownINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupShuffleUpINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupShuffleXorINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupBlockReadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupImageBlockReadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupImageMediaBlockReadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUCountLeadingZerosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUCountTrailingZerosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAbsISubINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAbsUSubINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpIAddSatINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUAddSatINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpIAverageINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUAverageINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpIAverageRoundedINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUAverageRoundedINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpISubSatINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUSubSatINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpIMul32x16INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpUMul32x16INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpConstantFunctionPointerINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFunctionPointerCallINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAsmTargetINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAsmINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAsmCallINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicFMinEXT: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicFMaxEXT: *hasResult = true; *hasResultType = true; break;
		case Op::OpExpectKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpVmeImageINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeVmeImageINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImePayloadINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcRefPayloadINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcSicPayloadINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcMcePayloadINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcMceResultINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImeResultINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImeResultSingleReferenceStreamoutINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImeResultDualReferenceStreamoutINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImeSingleReferenceStreaminINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcImeDualReferenceStreaminINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcRefResultINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpTypeAvcSicResultINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetInterShapePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetInterDirectionPenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetAcOnlyHaarINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToImePayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToImeResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToRefPayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToRefResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToSicPayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceConvertToSicResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetMotionVectorsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterDistortionsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetBestInterDistortionsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterMajorShapeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterMinorShapeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterDirectionsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterMotionVectorCountINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterReferenceIdsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeInitializeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetSingleReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetDualReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeRefWindowSizeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeAdjustRefOffsetINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeConvertToMcePayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetMaxMotionVectorCountINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeSetWeightedSadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithDualReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeConvertToMceResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetSingleReferenceStreaminINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetDualReferenceStreaminINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeStripDualReferenceStreamoutINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetBorderReachedINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcFmeInitializeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcBmeInitializeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefConvertToMcePayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefSetBidirectionalMixDisableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefSetBilinearFilterEnableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefEvaluateWithDualReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcRefConvertToMceResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicInitializeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicConfigureSkcINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicConfigureIpeLumaINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicConfigureIpeLumaChromaINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetMotionVectorMaskINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicConvertToMcePayloadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetBilinearFilterEnableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicEvaluateIpeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicEvaluateWithDualReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicConvertToMceResultINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetIpeLumaShapeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetPackedIpeLumaModesINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetIpeChromaModeINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSubgroupAvcSicGetInterRawSadsINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpVariableLengthArrayINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpSaveMemoryINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSinCosPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCastINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCastFromIntINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCastToIntINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatAddINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSubINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatMulINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatDivINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatGTINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatGEINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLTINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLEINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatEQINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatRecipINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatRSqrtINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCbrtINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatHypotINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSqrtINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLogINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLog2INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLog10INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatLog1pINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatExpINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatExp2INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatExp10INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatExpm1INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSinINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSinCosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatSinPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatCosPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatASinINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatASinPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatACosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatACosPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatATanINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatATanPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatATan2INTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatPowINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatPowRINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpArbitraryFloatPowNINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpAliasDomainDeclINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpAliasScopeDeclINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpAliasScopeListDeclINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpFixedSqrtINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedRecipINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedRsqrtINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedSinINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedCosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedSinCosINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedSinPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedCosPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedSinCosPiINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedLogINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFixedExpINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpPtrCastToCrossWorkgroupINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpCrossWorkgroupCastToPtrINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpReadPipeBlockingINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpWritePipeBlockingINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpFPGARegINTEL: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetRayTMinKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetRayFlagsKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionTKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionInstanceCustomIndexKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionInstanceIdKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionGeometryIndexKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionPrimitiveIndexKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionBarycentricsKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionFrontFaceKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionCandidateAABBOpaqueKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionObjectRayDirectionKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionObjectRayOriginKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetWorldRayDirectionKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetWorldRayOriginKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionObjectToWorldKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpRayQueryGetIntersectionWorldToObjectKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpAtomicFAddEXT: *hasResult = true; *hasResultType = true; break;
		case Op::OpTypeBufferSurfaceINTEL: *hasResult = true; *hasResultType = false; break;
		case Op::OpGroupIMulKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupFMulKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupBitwiseAndKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupBitwiseOrKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupBitwiseXorKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupLogicalAndKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupLogicalOrKHR: *hasResult = true; *hasResultType = true; break;
		case Op::OpGroupLogicalXorKHR: *hasResult = true; *hasResultType = true; break;
		}
	}
	inline constexpr bool HasResult(Op opcode) {
		switch (opcode) {
		default: return true; // majority of instructions has a result
		case Op::OpNop: return false;
		case Op::OpSourceContinued: return false;
		case Op::OpSource: return false;
		case Op::OpSourceExtension: return false;
		case Op::OpName: return false;
		case Op::OpMemberName: return false;
		case Op::OpLine: return false;
		case Op::OpExtension: return false;
		case Op::OpMemoryModel: return false;
		case Op::OpEntryPoint: return false;
		case Op::OpExecutionMode: return false;
		case Op::OpCapability: return false;
		case Op::OpTypeForwardPointer: return false;
		case Op::OpFunctionEnd: return false;
		case Op::OpStore: return false;
		case Op::OpCopyMemory: return false;
		case Op::OpCopyMemorySized: return false;
		case Op::OpDecorate: return false;
		case Op::OpMemberDecorate: return false;
		case Op::OpGroupDecorate: return false;
		case Op::OpGroupMemberDecorate: return false;
		case Op::OpImageWrite: return false;
		case Op::OpEmitVertex: return false;
		case Op::OpEndPrimitive: return false;
		case Op::OpEmitStreamVertex: return false;
		case Op::OpEndStreamPrimitive: return false;
		case Op::OpControlBarrier: return false;
		case Op::OpMemoryBarrier: return false;
		case Op::OpAtomicStore: return false;
		case Op::OpLoopMerge: return false;
		case Op::OpSelectionMerge: return false;
		case Op::OpBranch: return false;
		case Op::OpBranchConditional: return false;
		case Op::OpSwitch: return false;
		case Op::OpKill: return false;
		case Op::OpReturn: return false;
		case Op::OpReturnValue: return false;
		case Op::OpUnreachable: return false;
		case Op::OpLifetimeStart: return false;
		case Op::OpLifetimeStop: return false;
		case Op::OpGroupWaitEvents: return false;
		case Op::OpCommitReadPipe: return false;
		case Op::OpCommitWritePipe: return false;
		case Op::OpGroupCommitReadPipe: return false;
		case Op::OpGroupCommitWritePipe: return false;
		case Op::OpRetainEvent: return false;
		case Op::OpReleaseEvent: return false;
		case Op::OpSetUserEventStatus: return false;
		case Op::OpCaptureEventProfilingInfo: return false;
		case Op::OpNoLine: return false;
		case Op::OpAtomicFlagClear: return false;
		case Op::OpMemoryNamedBarrier: return false;
		case Op::OpModuleProcessed: return false;
		case Op::OpExecutionModeId: return false;
		case Op::OpDecorateId: return false;
		case Op::OpTerminateInvocation: return false;
		case Op::OpTraceRayKHR: return false;
		case Op::OpExecuteCallableKHR: return false;
		case Op::OpIgnoreIntersectionKHR: return false;
		case Op::OpTerminateRayKHR: return false;
		case Op::OpRayQueryInitializeKHR: return false;
		case Op::OpRayQueryTerminateKHR: return false;
		case Op::OpRayQueryGenerateIntersectionKHR: return false;
		case Op::OpRayQueryConfirmIntersectionKHR: return false;
		case Op::OpWritePackedPrimitiveIndices4x8NV: return false;
		case Op::OpIgnoreIntersectionNV: return false;
		case Op::OpTerminateRayNV: return false;
		case Op::OpTraceNV: return false;
		case Op::OpTraceMotionNV: return false;
		case Op::OpTraceRayMotionNV: return false;
		case Op::OpExecuteCallableNV: return false;
		case Op::OpCooperativeMatrixStoreNV: return false;
		case Op::OpBeginInvocationInterlockEXT: return false;
		case Op::OpEndInvocationInterlockEXT: return false;
		case Op::OpDemoteToHelperInvocation: return false;
		case Op::OpSamplerImageAddressingModeNV: return false;
		case Op::OpSubgroupBlockWriteINTEL: return false;
		case Op::OpSubgroupImageBlockWriteINTEL: return false;
		case Op::OpSubgroupImageMediaBlockWriteINTEL: return false;
		case Op::OpAssumeTrueKHR: return false;
		case Op::OpDecorateString: return false;
		case Op::OpMemberDecorateString: return false;
		case Op::OpRestoreMemoryINTEL: return false;
		case Op::OpLoopControlINTEL: return false;
		case Op::OpTypeStructContinuedINTEL: return false;
		case Op::OpConstantCompositeContinuedINTEL: return false;
		case Op::OpSpecConstantCompositeContinuedINTEL: return false;
		case Op::OpControlBarrierArriveINTEL: return false;
		case Op::OpControlBarrierWaitINTEL: return false;
		}
	}
	inline constexpr bool HasResultType(Op opcode) {
		switch (opcode) {
		default: return true; // majority of instructions has a result type
		case Op::OpNop: return false;
		case Op::OpSourceContinued: return false;
		case Op::OpSource: return false;
		case Op::OpSourceExtension: return false;
		case Op::OpName: return false;
		case Op::OpMemberName: return false;
		case Op::OpString: return false;
		case Op::OpLine: return false;
		case Op::OpExtension: return false;
		case Op::OpExtInstImport: return false;
		case Op::OpMemoryModel: return false;
		case Op::OpEntryPoint: return false;
		case Op::OpExecutionMode: return false;
		case Op::OpCapability: return false;
		case Op::OpTypeVoid: return false;
		case Op::OpTypeBool: return false;
		case Op::OpTypeInt: return false;
		case Op::OpTypeFloat: return false;
		case Op::OpTypeVector: return false;
		case Op::OpTypeMatrix: return false;
		case Op::OpTypeImage: return false;
		case Op::OpTypeSampler: return false;
		case Op::OpTypeSampledImage: return false;
		case Op::OpTypeArray: return false;
		case Op::OpTypeRuntimeArray: return false;
		case Op::OpTypeStruct: return false;
		case Op::OpTypeOpaque: return false;
		case Op::OpTypePointer: return false;
		case Op::OpTypeFunction: return false;
		case Op::OpTypeEvent: return false;
		case Op::OpTypeDeviceEvent: return false;
		case Op::OpTypeReserveId: return false;
		case Op::OpTypeQueue: return false;
		case Op::OpTypePipe: return false;
		case Op::OpTypeForwardPointer: return false;
		case Op::OpFunctionEnd: return false;
		case Op::OpStore: return false;
		case Op::OpCopyMemory: return false;
		case Op::OpCopyMemorySized: return false;
		case Op::OpDecorate: return false;
		case Op::OpMemberDecorate: return false;
		case Op::OpDecorationGroup: return false;
		case Op::OpGroupDecorate: return false;
		case Op::OpGroupMemberDecorate: return false;
		case Op::OpImageWrite: return false;
		case Op::OpEmitVertex: return false;
		case Op::OpEndPrimitive: return false;
		case Op::OpEmitStreamVertex: return false;
		case Op::OpEndStreamPrimitive: return false;
		case Op::OpControlBarrier: return false;
		case Op::OpMemoryBarrier: return false;
		case Op::OpAtomicStore: return false;
		case Op::OpLoopMerge: return false;
		case Op::OpSelectionMerge: return false;
		case Op::OpLabel: return false;
		case Op::OpBranch: return false;
		case Op::OpBranchConditional: return false;
		case Op::OpSwitch: return false;
		case Op::OpKill: return false;
		case Op::OpReturn: return false;
		case Op::OpReturnValue: return false;
		case Op::OpUnreachable: return false;
		case Op::OpLifetimeStart: return false;
		case Op::OpLifetimeStop: return false;
		case Op::OpGroupWaitEvents: return false;
		case Op::OpCommitReadPipe: return false;
		case Op::OpCommitWritePipe: return false;
		case Op::OpGroupCommitReadPipe: return false;
		case Op::OpGroupCommitWritePipe: return false;
		case Op::OpRetainEvent: return false;
		case Op::OpReleaseEvent: return false;
		case Op::OpSetUserEventStatus: return false;
		case Op::OpCaptureEventProfilingInfo: return false;
		case Op::OpNoLine: return false;
		case Op::OpAtomicFlagClear: return false;
		case Op::OpTypePipeStorage: return false;
		case Op::OpTypeNamedBarrier: return false;
		case Op::OpMemoryNamedBarrier: return false;
		case Op::OpModuleProcessed: return false;
		case Op::OpExecutionModeId: return false;
		case Op::OpDecorateId: return false;
		case Op::OpTerminateInvocation: return false;
		case Op::OpTraceRayKHR: return false;
		case Op::OpExecuteCallableKHR: return false;
		case Op::OpIgnoreIntersectionKHR: return false;
		case Op::OpTerminateRayKHR: return false;
		case Op::OpTypeRayQueryKHR: return false;
		case Op::OpRayQueryInitializeKHR: return false;
		case Op::OpRayQueryTerminateKHR: return false;
		case Op::OpRayQueryGenerateIntersectionKHR: return false;
		case Op::OpRayQueryConfirmIntersectionKHR: return false;
		case Op::OpWritePackedPrimitiveIndices4x8NV: return false;
		case Op::OpIgnoreIntersectionNV: return false;
		case Op::OpTerminateRayNV: return false;
		case Op::OpTraceNV: return false;
		case Op::OpTraceMotionNV: return false;
		case Op::OpTraceRayMotionNV: return false;
		case Op::OpTypeAccelerationStructureNV: return false;
		case Op::OpExecuteCallableNV: return false;
		case Op::OpTypeCooperativeMatrixNV: return false;
		case Op::OpCooperativeMatrixStoreNV: return false;
		case Op::OpBeginInvocationInterlockEXT: return false;
		case Op::OpEndInvocationInterlockEXT: return false;
		case Op::OpDemoteToHelperInvocation: return false;
		case Op::OpSamplerImageAddressingModeNV: return false;
		case Op::OpSubgroupBlockWriteINTEL: return false;
		case Op::OpSubgroupImageBlockWriteINTEL: return false;
		case Op::OpSubgroupImageMediaBlockWriteINTEL: return false;
		case Op::OpAssumeTrueKHR: return false;
		case Op::OpDecorateString: return false;
		case Op::OpMemberDecorateString: return false;
		case Op::OpTypeVmeImageINTEL: return false;
		case Op::OpTypeAvcImePayloadINTEL: return false;
		case Op::OpTypeAvcRefPayloadINTEL: return false;
		case Op::OpTypeAvcSicPayloadINTEL: return false;
		case Op::OpTypeAvcMcePayloadINTEL: return false;
		case Op::OpTypeAvcMceResultINTEL: return false;
		case Op::OpTypeAvcImeResultINTEL: return false;
		case Op::OpTypeAvcImeResultSingleReferenceStreamoutINTEL: return false;
		case Op::OpTypeAvcImeResultDualReferenceStreamoutINTEL: return false;
		case Op::OpTypeAvcImeSingleReferenceStreaminINTEL: return false;
		case Op::OpTypeAvcImeDualReferenceStreaminINTEL: return false;
		case Op::OpTypeAvcRefResultINTEL: return false;
		case Op::OpTypeAvcSicResultINTEL: return false;
		case Op::OpRestoreMemoryINTEL: return false;
		case Op::OpLoopControlINTEL: return false;
		case Op::OpAliasDomainDeclINTEL: return false;
		case Op::OpAliasScopeDeclINTEL: return false;
		case Op::OpAliasScopeListDeclINTEL: return false;
		case Op::OpTypeBufferSurfaceINTEL: return false;
		case Op::OpTypeStructContinuedINTEL: return false;
		case Op::OpConstantCompositeContinuedINTEL: return false;
		case Op::OpSpecConstantCompositeContinuedINTEL: return false;
		case Op::OpControlBarrierArriveINTEL: return false;
		case Op::OpControlBarrierWaitINTEL: return false;
		}
	}
	inline constexpr bool IsTypeOp(Op opcode) {
		switch (opcode) {
		default: return false; // majority of instructions are not types
		case Op::OpTypeVoid: return true;
		case Op::OpTypeBool: return true;
		case Op::OpTypeInt: return true;
		case Op::OpTypeFloat: return true;
		case Op::OpTypeVector: return true;
		case Op::OpTypeMatrix: return true;
		case Op::OpTypeImage: return true;
		case Op::OpTypeSampler: return true;
		case Op::OpTypeSampledImage: return true;
		case Op::OpTypeArray: return true;
		case Op::OpTypeRuntimeArray: return true;
		case Op::OpTypeStruct: return true;
		case Op::OpTypeOpaque: return true;
		case Op::OpTypePointer: return true;
		case Op::OpTypeFunction: return true;
		case Op::OpTypeEvent: return true;
		case Op::OpTypeDeviceEvent: return true;
		case Op::OpTypeReserveId: return true;
		case Op::OpTypeQueue: return true;
		case Op::OpTypePipe: return true;
		case Op::OpTypeForwardPointer: return true;
		case Op::OpTypePipeStorage: return true;
		case Op::OpTypeNamedBarrier: return true;
		case Op::OpTypeRayQueryKHR: return true;
		case Op::OpTypeAccelerationStructureNV: return true;
		case Op::OpTypeCooperativeMatrixNV: return true;
		case Op::OpTypeVmeImageINTEL: return true;
		case Op::OpTypeAvcImePayloadINTEL: return true;
		case Op::OpTypeAvcRefPayloadINTEL: return true;
		case Op::OpTypeAvcSicPayloadINTEL: return true;
		case Op::OpTypeAvcMcePayloadINTEL: return true;
		case Op::OpTypeAvcMceResultINTEL: return true;
		case Op::OpTypeAvcImeResultINTEL: return true;
		case Op::OpTypeAvcImeResultSingleReferenceStreamoutINTEL: return true;
		case Op::OpTypeAvcImeResultDualReferenceStreamoutINTEL: return true;
		case Op::OpTypeAvcImeSingleReferenceStreaminINTEL: return true;
		case Op::OpTypeAvcImeDualReferenceStreaminINTEL: return true;
		case Op::OpTypeAvcRefResultINTEL: return true;
		case Op::OpTypeAvcSicResultINTEL: return true;
		case Op::OpTypeBufferSurfaceINTEL: return true;
		case Op::OpTypeStructContinuedINTEL: return true;
		}
	}
	inline constexpr bool IsConstantOp(Op opcode) {
		switch (opcode) {
		default: return false; // majority of instructions are not constants
		case Op::OpConstantTrue: return true;
		case Op::OpConstantFalse: return true;
		case Op::OpConstant: return true;
		case Op::OpConstantComposite: return true;
		case Op::OpConstantSampler: return true;
		case Op::OpConstantNull: return true;
		case Op::OpConstantPipeStorage: return true;
		case Op::OpConstantFunctionPointerINTEL: return true;
		case Op::OpConstantCompositeContinuedINTEL: return true;
		}
	}
	inline constexpr bool IsSpecConstantOp(Op opcode) {
		switch (opcode) {
		default: return false; // majority of instructions are not spec constants
		case Op::OpSpecConstantTrue: return true;
		case Op::OpSpecConstantFalse: return true;
		case Op::OpSpecConstant: return true;
		case Op::OpSpecConstantComposite: return true;
		case Op::OpSpecConstantOp: return true;
		case Op::OpSpecConstantCompositeContinuedINTEL: return true;
		}
	}
} // spvgentwo::spv
