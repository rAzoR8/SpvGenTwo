# SpvGenTwo

SpvGenTwo is a [SPIR-V](https://www.khronos.org/registry/spir-v/) building and parsing library written in C++17, no other dependencies! No STL or other 3rd-Party library needed. The library comes with its own set of SPIR-V definitions generated from the [machine readable grammar](https://github.com/KhronosGroup/SPIRV-Headers/blob/master/include/spirv/unified1/spirv.core.grammar.json) and therefore does not require any `vulkan` or `spirv-headers` includes. The generator can be found here: [rustspvgen](https://github.com/rAzoR8/rustspvgen).

I built this library as a 'slim' **backend** for runtime material/shader-editors (like [Proto](https://twitter.com/SiNGUL4RiTY/status/1246492443811422208)) to avoid introducing enormous libraries like [DXC](https://github.com/microsoft/DirectXShaderCompiler) (including LLVM and Frontend) or [SPIRV-Tools](https://github.com/KhronosGroup/SPIRV-Tools) to the codebase.

__SpvGenTwo__ is still under development, many parts are still missing, but all the building blocks are there. SpvGenTwo is designed to be extensible and customizable, it is fairly easy to implement new SPIR-V instructions and extensions, use custom allocators and define own type inference rules. Note that it is still possible to generate invalid SPIR-V modules because not all inputs are checked yet. Use the SPIR-V validator [spirv-val](https://github.com/KhronosGroup/SPIRV-Tools#validator-tool) from the SDK and have the [specification](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.pdf) at hand while using this library.

I mainly focused on Shader capabilities, so the Kernel and OpenCL side is a bit under-developed. Any community contributions in that regard are very welcome!

**Overview:**
* [Examples](#Examples)
    * [Example Project](#Example-Project)
* [Building](#Building)
* [Tools](#Tools)
    * [Disassembler](#Disassembler)
    * [Reflector](#Reflector)
    * [Linker](#Linker)
* [Documentation](#Documentation)
* [Contributing](#Contributing)
* [Copyright and Licensing](#Copyright-and-Licensing)
* [Roadmap](#Roadmap)
* [Gallery](#Gallery)
* [Coverage](#Coverage)
    * [Core](#Core)
    * [GLSL.std.450](#GLSL.std.450)
    * [OpenCl.std.100](#OpenCl.std.100)

# Examples

```cpp
ConsoleLogger log;
HeapAllocator alloc; // custom user allocator

// create a new spir-v module
Module module(&alloc, &log);

// configure capabilities and extensions
module.addCapability(spv::Capability::Shader);
module.addCapability(spv::Capability::VulkanMemoryModelKHR);
module.addExtension(spv::Extension::SPV_KHR_vulkan_memory_model);
Instruction* ext = module.getExtensionInstructionImport(u8"GLSL.std.450");
module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

// global variables
Instruction* uniformVar = module.uniform<vector_t<float, 3>>(u8"u_Position");

// float add(float x, float y)
Function& funcAdd = module.addFunction<float, float, float>(u8"add", spv::FunctionControlMask::Const);
{
    BasicBlock& bb = *funcAdd; // get entry block to this function

    Instruction* x = funcAdd.getParameter(0);
    Instruction* y = funcAdd.getParameter(1);

    Instruction* z = bb.Add(x, y);
    bb.returnValue(z);
}

// void entryPoint();
{
    EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
    entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
    BasicBlock& bb = *entry; // get entry block to this function

    Instruction* uniVec = bb->opLoad(uniformVar);
    Instruction* cross = bb.ext<GLSL>()->opCross(uniVec, uniVec); // use GLSL.std.450 extension
    Instruction* s = bb->opDot(cross, uniVec);
    entry->call(&funcAdd, s, s); // call add(s, s)
    entry->opReturn();
}

// custom spir-v binary serializer:
BinaryFileWriter writer("test.spv");
module.finalizeAndWrite(writer);
```

The resulting SPIR-V binary when disassembled using `spirv-dis`:
```cpp
; SPIR-V
; Version: 1.0
; Generator: SpvGenTwo SPIR-V IR Tools(30); 0
; Bound: 20
; Schema: 0
               OpCapability Shader
               OpCapability VulkanMemoryModelKHR
               OpExtension "SPV_KHR_vulkan_memory_model"
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical VulkanKHR
               OpEntryPoint Fragment %main "main" %u_Position
               OpExecutionMode %main OriginUpperLeft
               OpName %u_Position "u_Position"
               OpName %add "add"
               OpName %main "main"
      %float = OpTypeFloat 32
    %v3float = OpTypeVector %float 3
%_ptr_Uniform_v3float = OpTypePointer Uniform %v3float
          %9 = OpTypeFunction %float %float %float
       %void = OpTypeVoid
          %3 = OpTypeFunction %void
 %u_Position = OpVariable %_ptr_Uniform_v3float Uniform
        %add = OpFunction %float Const %9
         %11 = OpFunctionParameter %float
         %12 = OpFunctionParameter %float
         %13 = OpLabel
         %14 = OpFAdd %float %11 %12
               OpReturnValue %14
               OpFunctionEnd
       %main = OpFunction %void None %3
         %15 = OpLabel
         %16 = OpLoad %v3float %u_Position None
         %17 = OpExtInst %v3float %1 Cross %16 %16
         %18 = OpDot %float %17 %16
         %19 = OpFunctionCall %float %add %18 %18
               OpReturn
               OpFunctionEnd
```

## Example Project

Set CMake option SPVGENTWO_BUILD_EXAMPLES to TRUE to build included examples:

* [FunctionCall Example](example/source/FunctionCall.cpp)
* [ControlFlow Example](example/source/ControlFlow.cpp)
* [FunctionCall Example](example/source/FunctionCall.cpp)
* [Extensions Example](example/source/Extensions.cpp)
* [Constants Example](example/source/Constants.cpp)
* [Types Example](example/source/Types.cpp)
* [ExpressionGraph Example](example/source/ExpressionGraph.cpp)
* [Linkage Example](example/source/Linkage.cpp)

# Project Structure

SpvGenTwo is split into 5 folders:

* `lib` contains the foundation to generate SPIR-V code. SpvGenTwo makes excessive use of its allocator interface, no memory is allocated from the heap. SpvGenTwo comes with its on set of container classes: List, Vector, String and HashMap. Those are not built for performance, but they shouldn't be much worse than standard implementations (okay maybe my HashMap is not as fast as unordered_map, build times are quite nice though :). Everything within this folders is pure C++17, no other dependencies (given that SPVGENTWO_REPLACE_PLACEMENTNEW and SPVGENTWO_REPLACE_TRAITS are used).
* `common` contains some convenience implementations of abstract interfaces: HeapAllocator uses C malloc and free, BindaryFileWriter uses fopen, ConsoleLogger uses vprintf, ModulePrinter uses snprintf. It also has some additional classes like Callable (std::function replacement), Graph, ControlFlowGraph, Expression and ExprGraph, they follow the same design principles and might sooner or later be moved to `lib` if needed.
* `example` contains small, self-contained code snippets that each generate a SPIR-V module to show some of the fundamental mechanics and APIs of SpvGenTwo.
* `dis` is a [spirv-dis](https://github.com/KhronosGroup/SPIRV-Tools#disassembler-tool)-like tool to print assembly language text.
* `refl` is a [SPIRV-Reflect](https://github.com/KhronosGroup/SPIRV-Reflect)-like tool to extract descriptor bindings and other relevant info from SPIR-V binary modules.
* `link` is a [spirv-link](https://github.com/KhronosGroup/SPIRV-Tools#linker-tool)-like tool to for merging symbols of modules into a new output module.

# Building

Use the supplied CMakeLists.txt to generate project files for your build system. SpvGenTwo allows the user to use STL headers (`<type_traits>`, `<new>` etc) instead of my hand-made replacements (see `stdreplament.h`).

* `SPVGENTWO_BUILD_EXAMPLES` is set to FALSE by default. If TRUE, an executable with sources from the 'example' folder will be built.
    * Note that the SpvGenTwoExample executable project requires the Vulkan SDK to be installed as it calls spirv-val and spriv-dis.
* `SPVGENTWO_BUILD_DISASSEMBLER` is set to FALSE by default. If TRUE, an executable with sources from the 'dis' folder will be built.
* `SPVGENTWO_BUILD_REFLECT` is set to FALSE by default. If TRUE, an executable with sources from the 'refl' folder will be built.
* `SPVGENTWO_BUILD_LINKER` is set to FALSE by default. If TRUE, an executable with sources from the 'link' folder will be built.
* `SPVGENTWO_REPLACE_PLACEMENTNEW` is set to TRUE by default. If FALSE, placement-new will be included from `<new>` header.
* `SPVGENTWO_REPLACE_TRAITS` is set to TRUE by default. If FALSE, `<type_traits>` and `<utility>` header will be included under `spvgentwo::stdrep` namespace.
* `SPVGENTWO_LOGGING` is set to TRUE by default, calls to module.log() will have not effect if FALSE.

Note that I mainly develop on windows using clang and MSVC but I'll also try to support GCC/linux.

# Tools

SpvGenTwo includes a couple of CLI tools to explore and test the libraries capabilities.

## Disassembler

![SpvGenTwoDisassembler](/misc/dis.PNG)

SpvGenTwoDisassembler source can be found at [dis/source/dis.cpp](dis/source/dis.cpp), it is just a single source file demonstrating the basic parsing and IR walking capabilities of SpvGenTwo.

CLI: ```SpvGenTwoDisassembler [file] <option> <option> ...```

### Options
* `-assignids` re-assigns instruction result IDs starting from 1. Some SPIR-V compilers emit IDs in a very high range, making it hard to read and trace data flow in assembly language text, `assignIDs` helps with that.
* `-serialize` writes the parsed SPIR-V program to a `serialized.spv` file in the working directory (this is a debug feature).
* `-noinstrnames` don't replace result IDs with OpNames
* `-noopnames` don't replace operand IDs with OpNames
* `-nopreamble` don't print SPIR-V preamble
* `-colors` use [ANSI](https://en.wikipedia.org/wiki/ANSI_escape_code) color codes
* `-tabs "    "` example: use 4 spaces instead of 2 tabs

## Reflector

![SpvGenTwoReflect](/misc/refl.PNG)

SpvGenTwoReflect source can be found at [refl/source/refl.cpp](refl/source/refl.cpp)

CLI: SpvGenTwoReflect ```[file] <option> <option> ...```

### Options
* `-var name` select variable by name (if OpVariable was annotated by OpName) for DescriptorType & Decoration printing (`name` has to be a UTF-8 string)
    * `-var MyBuffer`
* `-deco decoration` select [decoration](https://github.com/KhronosGroup/SPIRV-Headers/blob/75b30a659c8a4979104986652c54cc421fc51129/include/spirv/unified1/spirv.core.grammar.json#L9486) to query for in the module
    * `-deco` print all decorations in the module
    * `-deco DescriptorSet` to print only DescriptorSets
    * `-deco DescriptorSet -deco Binding` to print only DescriptorSets & Bindings
* `-funcs` list functions names in the module
* `-vars` list global variables in the module (StorageClass != Function)
* `-types` list types and constatns in the module
* `-id Id` print SPIR-V assembly text for the instruction with result Id
    * `-id 24`
* `-colors` use [ANSI](https://en.wikipedia.org/wiki/ANSI_escape_code) color codes

## Linker

![SpvGenTwoLinker](/misc/linker.PNG)

See [SpvGenTwoLinker](LINKER.md) for detailed description. Source can be found at [refl/source/link.cpp](refl/source/link.cpp).

# Documentation

Please read the [documentation](DOCUMENTATION.md) for more detailed information on how to use SpvGenTwo and some reasoning about my design choices.

# Contributing

Please follow the "fork-and-pull" Git workflow:

* Fork the repo on GitHub
* Clone the project to your own machine
* Commit changes to your own branch
* Push your work back up to your fork
* Submit a Pull request so that we can review your changes

Make sure to merge the latest from "upstream" before making a pull request.

# Copyright and Licensing

The SpvGenTwo open source project is licensed under [MIT license](LICENSE).
Any contribution you make to this original repository shall be licensed under same license. You are still free to distribute your contributions (in your own fork) under the license you desire.

# Roadmap

A list of short and long term goals for this library:

* Implement more Instructions, at least 90% of Shader capabilities
* Improve validation / logging / error reporting
* Write unit tests
* Implement [SPIRV-Tools](https://github.com/KhronosGroup/SPIRV-Tools) like helper tools
* Implement some front-end or DSL like [SPEAR](https://github.com/rAzoR8/SPEAR)

# Gallery

SpvGenTwo is used in:

* [Proto](https://github.com/rAzoR8/Proto)
![Proto](https://raw.githubusercontent.com/rAzoR8/Proto/master/proto.png)

* [SHADERed](https://github.com/dfranx/SHADERed)
![SHADERed](https://raw.githubusercontent.com/dfranx/SHADERed/master/Misc/Screenshots/IMG2.png)

* [TanTien-Engine](https://github.com/TanTien-Engine/tantien) [(shadertrans)](https://github.com/xzrunner/shadertrans)
![TanTien-Engine](https://media.githubusercontent.com/media/TanTien-Engine/tantien/main/doc/pbrgraph/screenshots/ibl.jpg)

Leave PR with your software if you want it to be added here :)

# Coverage

SPIR-V IR generation progress, parsing is independent and auto generated. This table indicates whether the operation is already implemented in the `Instruction` class or can be generated by other facilities. This is not a complete list, if an entry is missing, assume it has not been implemented yet. You can file an Issue to request its implementation or just use `Instruction::makeOp(...)` directly.

## Core

| Instruction | Implemented  |
|---|---|
| OpNop | &#10004;  |
| OpUndef | &#10004; |
| OpSourceContinued | &#10004; |
| OpSource | &#10004; |
| OpSourceExtension | &#10004; |
| OpName | &#10004; |
| OpMemberName | &#10004; |
| OpString | &#10004; |
| OpLine | &#10004; |
| OpExtension | &#10004; |
| OpExtInstImport | &#10004; |
| OpExtInst | &#10004; |
| OpMemoryModel | &#10004; |
| OpEntryPoint | &#10004; |
| opExecutionMode | &#10004; |
| OpCapability | &#10004; |
| OpExecutionModeId | &#10004; |
| OpTypeXXX | via `Module::addType()` |
| OpConstantXXX | via `Module::addConstant()` |
| OpSpecConstantXXX | via `Module::addConstant()` |
| OpSpecConstantOp | &#10004; |
| OpFunction | &#10004; |
| OpFunctionParameter | &#10004; |
| OpFunctionEnd | &#10004; |
| OpFunctionCall | &#10004; |
| OpVariable | &#10004; |
| OpImageTexelPointer | &#9744; |
| OpLoad | &#10004; |
| OpStore | &#10004; |
| OpCopyMemory | &#9744; |
| OpCopyMemorySized | &#9744; |
| OpAccessChain | &#10004; |
| OpInBoundsAccessChain | &#10004; |
| OpPtrAccessChain | &#9744; |
| OpArrayLength | &#9744; |
| OpGenericPtrMemSemantics | &#9744; |
| OpInBoundsPtrAccessChain | &#9744; |
| OpDecorate | &#10004; |
| OpMemberDecorate | &#10004; |
| OpDecorationGroup | &#9744; |
| OpGroupDecorate | &#9744; |
| OpGroupMemberDecorate | &#9744; |
| OpVectorExtractDynamic | &#10004; |
| OpVectorInsertDynamic | &#10004; |
| OpVectorShuffle | &#10004; |
| OpCompositeConstruct | &#10004; |
| OpCompositeExtract | &#10004; |
| OpCompositeInsert | &#10004; |
| OpCopyObject | &#10004; |
| OpTranspose | &#10004; |
| OpSampledImage | &#10004; |
| OpImageSampleImplicitLod | &#10004; |
| OpImageSampleExplicitLod | &#10004; |
| OpImageSampleDrefImplicitLod | &#10004; |
| OpImageSampleDrefExplicitLod | &#10004; |
| OpImageSampleProjImplicitLod | &#10004; |
| OpImageSampleProjExplicitLod | &#10004; |
| OpImageSampleProjDrefImplicitLod | &#10004; |
| OpImageSampleProjDrefExplicitLod | &#10004; |
| OpImageFetch | via generic `opImageSample` |
| OpImageGather | via generic `opImageSample` |
| OpImageDrefGather | via generic `opImageSample` |
| OpImageRead | &#9744; |
| OpImageWrite | &#9744; |
| OpImage | &#9744; |
| OpImageQueryFormat | &#9744; |
| OpImageQueryOrder | &#9744; |
| OpImageQuerySizeLod | &#9744; |
| OpImageQuerySize | &#9744; |
| OpImageQueryLod | &#9744; |
| OpImageQueryLevels | &#9744; |
| OpImageQuerySamples | &#9744; |
| OpConvertFToU | &#10004; |
| OpConvertFToS | &#10004; |
| OpConvertSToF | &#10004; |
| OpConvertUToF | &#10004; |
| OpUConvert | &#10004; |
| OpSConvert | &#10004; |
| OpFConvert | &#10004; |
| OpQuantizeToF16 | &#10004; |
| OpConvertPtrToU | &#10004; |
| OpSatConvertSToU | &#9744; |
| OpSatConvertUToS | &#9744; |
| OpConvertUToPtr | &#9744; |
| OpPtrCastToGeneric | &#9744; |
| OpGenericCastToPtr | &#9744; |
| OpGenericCastToPtrExplicit | &#9744; |
| OpBitcast | &#10004; |
| OpSNegate | &#10004; |
| OpFNegate | &#10004; |
| OpIAdd | &#10004; |
| OpFAdd | &#10004; |
| OpISub | &#10004; |
| OpFSub | &#10004; |
| OpIMul | &#10004; |
| OpFMul | &#10004; |
| OpUDiv | &#10004; |
| OpSDiv | &#10004; |
| OpFDiv | &#10004; |
| OpUMod | &#10004; |
| OpSRem | &#10004; |
| OpSMod | &#10004; |
| OpFRem | &#10004; |
| OpFMod | &#10004; |
| OpVectorTimesScalar | &#10004; |
| OpMatrixTimesScalar | &#10004; |
| OpVectorTimesMatrix | &#10004; |
| OpMatrixTimesVector | &#10004; |
| OpMatrixTimesMatrix | &#10004; |
| OpOuterProduct | &#10004; |
| OpDot | &#10004; |
| OpIAddCarry | &#9744; |
| OpISubBorrow | &#9744; |
| OpUMulExtended | &#9744; |
| OpSMulExtended | &#9744; |
| OpAny | &#10004; |
| OpAll | &#10004; |
| OpIsNan | &#9744; |
| OpIsInf | &#9744; |
| OpIsFinite | &#9744; |
| OpIsNormal | &#9744; |
| OpSignBitSet | &#9744; |
| OpLessOrGreater | &#9744; |
| OpOrdered | &#9744; |
| OpUnordered | &#9744; |
| OpLogicalEqual | &#10004; |
| OpLogicalNotEqual | &#10004; |
| OpLogicalOr | &#10004; |
| OpLogicalAnd | &#10004; |
| OpLogicalNot | &#10004; |
| OpSelect | &#10004; |
| OpIEqual | &#10004; |
| OpINotEqual | &#10004; |
| OpUGreaterThan | &#10004; |
| OpSGreaterThan | &#10004; |
| OpUGreaterThanEqual | &#10004; |
| OpSGreaterThanEqual | &#10004; |
| OpULessThan | &#10004; |
| OpSLessThan | &#10004; |
| OpULessThanEqual | &#10004; |
| OpSLessThanEqual | &#10004; |
| OpFOrdEqual | &#10004; |
| OpFUnordEqual | &#10004; |
| OpFOrdNotEqual | &#10004; |
| OpFUnordNotEqual | &#10004; |
| OpFOrdLessThan | &#10004; |
| OpFUnordLessThan | &#10004; |
| OpFOrdGreaterThan | &#10004; |
| OpFUnordGreaterThan | &#10004; |
| OpFOrdLessThanEqual | &#10004; |
| OpFUnordLessThanEqual | &#10004; |
| OpFOrdGreaterThanEqual | &#10004; |
| OpFUnordGreaterThanEqual | &#10004; |
| OpShiftRightLogical | &#10004; |
| OpShiftRightArithmetic | &#10004; |
| OpShiftLeftLogical | &#10004; |
| OpBitwiseOr | &#10004; |
| OpBitwiseXor | &#10004; |
| OpBitwiseAnd | &#10004; |
| OpNot | &#10004; |
| OpBitFieldInsert | &#9744; |
| OpBitFieldSExtract | &#9744; |
| OpBitFieldUExtract | &#9744; |
| OpBitReverse | &#9744; |
| OpBitCount | &#9744; |
| OpDPdx | &#10004; |
| OpDPdy | &#10004; |
| OpFwidth | &#10004; |
| OpDPdxFine | &#10004; |
| OpDPdyFine | &#10004; |
| OpFwidthFine | &#10004; |
| OpDPdxCoarse | &#10004; |
| OpDPdyCoarse | &#10004; |
| OpFwidthCoarse | &#10004; |
| OpEmitVertex | &#10004; |
| OpEndPrimitive | &#10004; |
| OpEmitStreamVertex | &#10004; |
| OpEndStreamPrimitive | &#10004; |
| OpControlBarrier | &#9744; |
| OpMemoryBarrier | &#9744; |
| OpAtomicLoad | &#9744; |
| OpAtomicStore | &#9744; |
| OpAtomicExchange | &#9744; |
| OpAtomicCompareExchange | &#9744; |
| OpAtomicCompareExchangeWeak | &#9744; |
| OpAtomicIIncrement | &#9744; |
| OpAtomicIDecrement | &#9744; |
| OpAtomicIAdd | &#9744; |
| OpAtomicISub | &#9744; |
| OpAtomicSMin | &#9744; |
| OpAtomicUMin | &#9744; |
| OpAtomicSMax | &#9744; |
| OpAtomicUMax | &#9744; |
| OpAtomicAnd | &#9744; |
| OpAtomicOr | &#9744; |
| OpAtomicXor | &#9744; |
| OpPhi | &#10004; |
| OpLoopMerge | &#10004; |
| OpSelectionMerge | &#10004; |
| OpLabel | &#10004; |
| OpBranch | &#10004; |
| OpBranchConditional | &#10004; |
| OpSwitch | &#9744; |
| OpKill | &#10004; |
| OpReturn | &#10004; |
| OpReturnValue | &#10004; |
| OpUnreachable | &#9744; |
| OpNoLine | &#10004; |
| OpAtomicFlagTestAndSet | &#9744; |
| OpAtomicFlagClear | &#9744; |
| OpImageSparseRead | &#9744; |
| OpSizeOf | &#10004; |
| OpTypePipeStorage | via `Module::addType()` |
| OpConstantPipeStorage | via `Module::addConstant()` |
| OpCreatePipeFromPipeStorage | &#9744; |
| OpGetKernelLocalSizeForSubgroupCount | &#9744; |
| OpGetKernelMaxNumSubgroups | &#9744; |
| OpTypeNamedBarrier | via `Module::addType()` |
| OpNamedBarrierInitialize | &#9744; |
| OpModuleProcessed | &#9744; |
| OpExecutionModeId | &#9744; |
| OpDecorateId | &#10004; |
| ... | ... |

## GLSL.std.450

| Instruction | Implemented  |
|---|---|
| Round | &#10004; |
| RoundEven | &#10004; |
| Trunc | &#10004; |
| FAbs | &#10004; |
| SAbs | &#10004; |
| FSign | &#10004; |
| SSign | &#10004; |
| Floor | &#10004; |
| Ceil | &#10004; |
| Fract | &#10004; |
| Radians | &#10004; |
| Degrees | &#10004; |
| Sin | &#10004; |
| Cos | &#10004; |
| Tan | &#10004; |
| Asin | &#10004; |
| Acos | &#10004; |
| Atan | &#10004; |
| Sinh | &#10004; |
| Cosh | &#10004; |
| Tanh | &#10004; |
| Asinh | &#10004; |
| Acosh | &#10004; |
| Atanh | &#10004; |
| Atan2 | &#10004; |
| Pow | &#10004; |
| Exp | &#10004; |
| Log | &#10004; |
| Exp2 | &#10004; |
| Log2 | &#10004; |
| Sqrt | &#10004; |
| InverseSqrt | &#10004; |
| Determinant | &#10004; |
| MatrixInverse | &#10004; |
| Modf | &#9744; |
| ModfStruct | &#9744; |
| FMin | &#10004; |
| UMin | &#10004; |
| SMin | &#10004; |
| FMax | &#10004; |
| UMax | &#10004; |
| SMax | &#10004; |
| FClamp | &#10004; |
| UClamp | &#10004; |
| SClamp | &#10004; |
| FMix | &#10004; |
| IMix | &#9744; |
| Step | &#10004; |
| SmoothStep | &#10004; |
| Fma | &#10004; |
| Frexp | &#9744; |
| FrexpStruct | &#9744; |
| Ldexp | &#9744; |
| PackSnorm4x8 | &#9744; |
| PackUnorm4x8 | &#9744; |
| PackSnorm2x16 | &#9744; |
| PackUnorm2x16 | &#9744; |
| PackHalf2x16 | &#9744; |
| PackDouble2x32 | &#9744; |
| UnpackSnorm2x16 | &#9744; |
| UnpackUnorm2x16 | &#9744; |
| UnpackHalf2x16 | &#9744; |
| UnpackSnorm4x8 | &#9744; |
| UnpackUnorm4x8 | &#9744; |
| UnpackDouble2x32 | &#9744; |
| Length | &#10004; |
| Distance | &#10004; |
| Cross | &#10004; |
| Normalize | &#10004; |
| FaceForward | &#10004; |
| Reflect | &#10004; |
| Refract | &#10004; |
| FindILsb | &#9744; |
| FindSMsb | &#9744; |
| FindUMsb | &#9744; |
| InterpolateAtCentroid | &#9744; |
| InterpolateAtSample | &#9744; |
| InterpolateAtOffset | &#9744; |
| NMin | &#9744; |
| NMax | &#9744; |
| NClamp | &#9744; |

## OpenCl.std.100

Not implemented yet