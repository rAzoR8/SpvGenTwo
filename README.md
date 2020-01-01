# SpvGenTwo

SpvGenTwo is a [SPIR-V](https://www.khronos.org/registry/spir-v/) building library written in C++17 with only `stddef.h` and `spirv.hpp11` as dependencies, no STL or other 3rd-Party library needed.
I built this library as a slim backend for runtime material/shader-editors to avoid introducing enormous libraries like DXC (with the whole LLVM) to the codebase.

__SpvGenTwo__ is still under development, many parts are still missing, but all the building blocks are there. SpvGenTwo is designed to be extensible and customizable, it is fairly easy to implement new SPIR-V instructions and extensions, use custom allocators and define own type inference rules. It is still possible to generate invalid SPIR-V modules because not all inputs are checked yet, use the SPIR-V validator `spirv-val` from the SDK and have the [specification](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.pdf) at hand while using this library.

While developing, I mainly focused on Shader capabilities, so the Kernel and OpenCL side is a bit under-developed. Any community contributions in that regard are very welcome!

Okay, lets see a first example:

```cpp
ConsoleLogger log;
HeapAllocator alloc; // custom user allocator

// create a new spir-v module
Module module(spv::Version, &alloc, &log);

// configure capabilities and extensions
module.addCapability(spv::Capability::Shader);
module.addCapability(spv::Capability::VulkanMemoryModelKHR);
module.addExtension("SPV_KHR_vulkan_memory_model");
Instruction* ext = module.getExtensionInstructionImport("GLSL.std.450");
module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

// global variables
Instruction* uniformVar = module.uniform<vector_t<float, 3>>("u_Position");

// float add(float x, float y)
Function& funcAdd = module.addFunction<float, float, float>("add", spv::FunctionControlMask::Const);
{
    BasicBlock& bb = *funcAdd; // get entry block to this function

    Instruction* x = funcAdd.getParameter(0);
    Instruction* y = funcAdd.getParameter(1);

    Instruction* z = bb.Add(x, y);
    bb.returnValue(z);
}

// void entryPoint();
{
    EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
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
module.write(&writer);
```

The resulting SPIR-V binary when disassembled using `spirv-dis`:
```
; SPIR-V
; Version: 1.4
; Generator: Unknown(250); 0
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

# Building

Use the supplied CMakeLists.txt to generate project files for your build system. SpvGenTwo allows the user to use STL headers (<type_traits>, <new> etc) instead of my hand-made replacements (see `stdreplament.h`).

* SPIRV_INCLUDE_DIR need to point to a folder that contains the spirv.hpp11 header. If the vulkan SDK is present, VULKAN_INCLUDE_DIR/vulkan will be used as a default.
* SPVGENTWO_DONT_REPLACE_PLACEMENTNEW is set to FALSE by default. If TRUE, placement-new will be included from <new> header.
* SPVGENTWO_DONT_REPLACE_TRAITS is set to FALSE by default. If TRUE, <type_traits> and <utility> header will be included under spvgentwo::stdrep namespace.
* SPVGENTWO_NO_LOGGING is set to FALSE by default, calls to module.log() will have not effect if TRUE.