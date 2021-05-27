# SpvGenTwo - Linker

![SpvGenTwoLinker](/misc/linker.PNG)

SpvGenTwoLinker source can be found at [refl/source/link.cpp](refl/source/link.cpp)

CLI: SpvGenTwoLinker ```<option> <option> ...```

## Options

* `-o outputPath` path to the resulting output module
    * `-out outputPath` same as `-o`
* `-l libPath` path to a input module to import symbols from (e.g. `-l toneMapping.spv`)
    * `-lib libPath` same as `-l`
* `-c consumerPath` path to a target module to consume symbols from import modules (e.g. `-c targetShader.spv`)
    * `-c targetPath` same as `-c`
    * if `outputPath` (below) is undefined, _targetPath_ will be used to write the output .spv

* `-verbose` enable printing of instructions being imported to the consuming module (debug feature)
    * `-PrintInstructions` same as `-verbose`

Currently, GLSL shader compilers do no support SPIR-V import/export attributes so SpvGenTwoLinker exposes functionality to patch existing SPIR-V modules to add linkage attributes and remove function bodies to turn .spv shaders into libs for import.

* `-p shaderPath` path to .spv module that should be prepared for use as import or export module.
    * `-patchspv shaderPath` same as `-p`
    * if _outputPath_ is undefined _shaderPath_ will be used. (Overwrites the original file)
* `-e target name -vars` export a symbol (OpVariable or OpFunction) with _target_ ID or string name (if the symbol was decorated with OpName) from the _patchspv_ module by adding `OpDecorate` with LinkageType::Export and export _name_. `-vars` can be used on OpFunction exports to automatically export global variables referenced in the function. Those global variables will be exported with the name taken form OpName (i.e. they can't be exported without OpName).
    `-export target name -vars` same as `-e`. `-vars` is optional
* `-i target name` import a _target_ symbol (by ID or OpName) with _name_ and LinkageType::Import decoration. `-vars` is only applicable for `-e`.
    * `-import target name` same as `-i`

## Flags:
    -ImportMissingTypes or -types
    -ImportMissingConstants or -constants
    -ImportMissingExtensionSets or -extsets
    -ImportReferencedDecorations or -refdecos
    -ImportReferencedNames or -refnames
    -ImportReferencedFunctions or -reffuncs
    -ImportReferencedVariables or -refvars
    -RemoveLinkageCapability or -rmcap
    -AutoAddRequiredCapabilitiesAndExtensions or -addcaps
    -UpdateEntryPointGlobalVarInterface or -variface
    -CopyOpSourceStringInstructions or -srcstrings
    -CopyOpLineInstructions or -lines
    -CopyOpModuleProcessedInstructions or -processed
    -AllOptions or -auto (all of the above)

## Example
Example code for generating the SPIR-V modules listed below can be found in the [Linkage Example](example/source/Linkage.cpp)

### import.spv
```cpp
; SPIR-V
; Version: 1.0
; Generator: Unknown(250); 0
; Bound: 14
; Schema: 0
               OpCapability Linkage
               OpCapability Shader
               OpMemoryModel Logical Simple
               OpEntryPoint Fragment %main "main"
               OpExecutionMode %main OriginUpperLeft
               OpName %addGlobalTime "addGlobalTime"
               OpName %polynomial "polynomial"
               OpName %main "main"
               OpName %FunctionEntry "FunctionEntry"
               OpDecorate %addGlobalTime LinkageAttributes "@addGlobalTime" Import
               OpDecorate %polynomial LinkageAttributes "@polynomial" Import
      %float = OpTypeFloat 32
          %2 = OpTypeFunction %float %float
       %void = OpTypeVoid
          %4 = OpTypeFunction %void
   %float_16 = OpConstant %float 16
%addGlobalTime = OpFunction %float Const %2
          %7 = OpFunctionParameter %float
               OpFunctionEnd
 %polynomial = OpFunction %float Const %2
          %9 = OpFunctionParameter %float
               OpFunctionEnd
       %main = OpFunction %void None %4
%FunctionEntry = OpLabel
         %12 = OpFunctionCall %float %addGlobalTime %float_16
         %13 = OpFunctionCall %float %polynomial %12
               OpReturn
               OpFunctionEnd
```
__import.spv__ requires external symbols to be runnable:
* `float addGlobalTime(float x)` from __exportA.spv__
* `float polynomial(float x)` from __exportB.spv__

### exportA.spv
```cpp
; SPIR-V
; Version: 1.0
; Generator: Unknown(250); 0
; Bound: 26
; Schema: 0
               OpCapability Linkage
               OpCapability Shader
               OpMemoryModel Logical Simple
               OpEntryPoint Fragment %main "main"
               OpExecutionMode %main OriginUpperLeft
               OpName %u_Time "u_Time"
               OpName %addSq "addSq"
               OpName %FunctionEntry "FunctionEntry"
               OpName %addGlobalTime "addGlobalTime"
               OpName %FunctionEntry_0 "FunctionEntry"
               OpName %main "main"
               OpName %FunctionEntry_1 "FunctionEntry"
               OpDecorate %addGlobalTime LinkageAttributes "@addGlobalTime" Export
      %float = OpTypeFloat 32
%_ptr_Uniform_float = OpTypePointer Uniform %float
          %3 = OpTypeFunction %float %float %float
          %4 = OpTypeFunction %float %float
 %float_1000 = OpConstant %float 1000
       %void = OpTypeVoid
          %7 = OpTypeFunction %void
   %float_16 = OpConstant %float 16
     %u_Time = OpVariable %_ptr_Uniform_float Uniform
      %addSq = OpFunction %float Const %3
         %11 = OpFunctionParameter %float
         %12 = OpFunctionParameter %float
%FunctionEntry = OpLabel
         %14 = OpFMul %float %11 %11
         %15 = OpFMul %float %12 %12
         %16 = OpFAdd %float %14 %15
               OpReturnValue %16
               OpFunctionEnd
%addGlobalTime = OpFunction %float Const %4
         %18 = OpFunctionParameter %float
%FunctionEntry_0 = OpLabel
         %20 = OpLoad %float %u_Time None
         %21 = OpFDiv %float %20 %float_1000
         %22 = OpFunctionCall %float %addSq %18 %21
               OpReturnValue %22
               OpFunctionEnd
       %main = OpFunction %void None %7
%FunctionEntry_1 = OpLabel
         %25 = OpFunctionCall %float %addGlobalTime %float_16
               OpReturn
               OpFunctionEnd
```

### exportB.spv
```cpp
; SPIR-V
; Version: 1.0
; Generator: Unknown(250); 0
; Bound: 57
; Schema: 0
               OpCapability Linkage
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical Simple
               OpEntryPoint Fragment %main "main"
               OpExecutionMode %main OriginUpperLeft
               OpName %u_Coefficients "u_Coefficients"
               OpName %polynomial "polynomial"
               OpName %FunctionEntry "FunctionEntry"
               OpName %main "main"
               OpName %FunctionEntry_0 "FunctionEntry"
               OpDecorate %u_Coefficients LinkageAttributes "@u_Coefficients" Export
               OpDecorate %polynomial LinkageAttributes "@polynomial" Export
      %float = OpTypeFloat 32
       %uint = OpTypeInt 32 0
     %uint_8 = OpConstant %uint 8
%_arr_float_uint_8 = OpTypeArray %float %uint_8
%_ptr_Uniform__arr_float_uint_8 = OpTypePointer Uniform %_arr_float_uint_8
          %7 = OpTypeFunction %float %float
    %float_0 = OpConstant %float 0
    %float_1 = OpConstant %float 1
    %float_2 = OpConstant %float 2
    %float_3 = OpConstant %float 3
    %float_4 = OpConstant %float 4
    %float_5 = OpConstant %float 5
    %float_6 = OpConstant %float 6
    %float_7 = OpConstant %float 7
       %void = OpTypeVoid
         %17 = OpTypeFunction %void
%u_Coefficients = OpVariable %_ptr_Uniform__arr_float_uint_8 Uniform
 %polynomial = OpFunction %float Const %7
         %20 = OpFunctionParameter %float
%FunctionEntry = OpLabel
         %22 = OpLoad %_arr_float_uint_8 %u_Coefficients None
         %23 = OpExtInst %float %1 Pow %20 %float_0
         %24 = OpCompositeExtract %float %22 0
         %25 = OpFMul %float %24 %23
         %26 = OpExtInst %float %1 Pow %20 %float_1
         %27 = OpCompositeExtract %float %22 1
         %28 = OpFMul %float %27 %26
         %29 = OpFAdd %float %25 %28
         %30 = OpExtInst %float %1 Pow %20 %float_2
         %31 = OpCompositeExtract %float %22 2
         %32 = OpFMul %float %31 %30
         %33 = OpFAdd %float %29 %32
         %34 = OpExtInst %float %1 Pow %20 %float_3
         %35 = OpCompositeExtract %float %22 3
         %36 = OpFMul %float %35 %34
         %37 = OpFAdd %float %33 %36
         %38 = OpExtInst %float %1 Pow %20 %float_4
         %39 = OpCompositeExtract %float %22 4
         %40 = OpFMul %float %39 %38
         %41 = OpFAdd %float %37 %40
         %42 = OpExtInst %float %1 Pow %20 %float_5
         %43 = OpCompositeExtract %float %22 5
         %44 = OpFMul %float %43 %42
         %45 = OpFAdd %float %41 %44
         %46 = OpExtInst %float %1 Pow %20 %float_6
         %47 = OpCompositeExtract %float %22 6
         %48 = OpFMul %float %47 %46
         %49 = OpFAdd %float %45 %48
         %50 = OpExtInst %float %1 Pow %20 %float_7
         %51 = OpCompositeExtract %float %22 7
         %52 = OpFMul %float %51 %50
         %53 = OpFAdd %float %49 %52
               OpReturnValue %53
               OpFunctionEnd
       %main = OpFunction %void None %17
%FunctionEntry_0 = OpLabel
         %56 = OpFunctionCall %float %polynomial %float_4
               OpReturn
               OpFunctionEnd
```

Note that this is just pseudo SPIR-V code, it's valid but not meaningful. The recurring computation above is the result of meta-programing & unrolling polynomial evaluation loop:

```cpp
BasicBlock& bb = *funcPolynomial; // get entry block to this function
Instruction* x = funcPolynomial.getParameter(0);

Instruction* uCoefs = bb->opLoad(uniformCoefficients);
		
auto eval = [&](unsigned int i) -> Instruction*
{
	Instruction* k = module.constant((float)i);
	Instruction* Xk = bb.ext<ext::GLSL>()->opPow(x, k);

	Instruction* Ai = bb->opCompositeExtract(uCoefs, i);

	Instruction* AkXk = bb.Mul(Ai, Xk);
	return AkXk;
};

Instruction* sum = eval(0);

// unroll
for (auto i = 1u; i < 8u; ++i)
{
	auto val = eval(i);
	sum = bb.Add(sum, val);
}

bb.returnValue(sum);
```

We can import them using:
```
SpvGenTwoLinker.exe -l exportA.spv -l exportB.spv -c import.spv -o linked.spv -types -constants -reffuncs -refvars -extsets -verbose
```

## linked.spv (result)
```cpp
; SPIR-V
; Version: 1.0
; Generator: Unknown(250); 0
; Bound: 76
; Schema: 0
               OpCapability Linkage
               OpCapability Shader
         %34 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical Simple
               OpEntryPoint Fragment %main "main"
               OpExecutionMode %main OriginUpperLeft
               OpName %addGlobalTime "addGlobalTime"
               OpName %polynomial "polynomial"
               OpName %main "main"
               OpName %FunctionEntry "FunctionEntry"
               OpName %addSq "addSq"
               OpName %FunctionEntry_0 "FunctionEntry"
               OpName %FunctionEntry_1 "FunctionEntry"
               OpName %u_Time "u_Time"
               OpName %FunctionEntry_2 "FunctionEntry"
               OpName %u_Coefficients "u_Coefficients"
      %float = OpTypeFloat 32
          %2 = OpTypeFunction %float %float
       %void = OpTypeVoid
          %4 = OpTypeFunction %void
   %float_16 = OpConstant %float 16
         %16 = OpTypeFunction %float %float %float
%_ptr_Uniform_float = OpTypePointer Uniform %float
 %float_1000 = OpConstant %float 1000
       %uint = OpTypeInt 32 0
     %uint_8 = OpConstant %uint 8
%_arr_float_uint_8 = OpTypeArray %float %uint_8
%_ptr_Uniform__arr_float_uint_8 = OpTypePointer Uniform %_arr_float_uint_8
    %float_0 = OpConstant %float 0
    %float_1 = OpConstant %float 1
    %float_2 = OpConstant %float 2
    %float_3 = OpConstant %float 3
    %float_4 = OpConstant %float 4
    %float_5 = OpConstant %float 5
    %float_6 = OpConstant %float 6
    %float_7 = OpConstant %float 7
     %u_Time = OpVariable %_ptr_Uniform_float Uniform
%u_Coefficients = OpVariable %_ptr_Uniform__arr_float_uint_8 Uniform
%addGlobalTime = OpFunction %float Const %2
          %7 = OpFunctionParameter %float
%FunctionEntry_1 = OpLabel
         %25 = OpLoad %float %u_Time None
         %26 = OpFDiv %float %25 %float_1000
         %28 = OpFunctionCall %float %addSq %7 %26
               OpReturnValue %28
               OpFunctionEnd
 %polynomial = OpFunction %float Const %2
          %9 = OpFunctionParameter %float
%FunctionEntry_2 = OpLabel
         %33 = OpLoad %_arr_float_uint_8 %u_Coefficients None
         %35 = OpExtInst %float %34 Pow %9 %float_0
         %37 = OpCompositeExtract %float %33 0
         %38 = OpFMul %float %37 %35
         %39 = OpExtInst %float %34 Pow %9 %float_1
         %41 = OpCompositeExtract %float %33 1
         %42 = OpFMul %float %41 %39
         %43 = OpFAdd %float %38 %42
         %44 = OpExtInst %float %34 Pow %9 %float_2
         %46 = OpCompositeExtract %float %33 2
         %47 = OpFMul %float %46 %44
         %48 = OpFAdd %float %43 %47
         %49 = OpExtInst %float %34 Pow %9 %float_3
         %51 = OpCompositeExtract %float %33 3
         %52 = OpFMul %float %51 %49
         %53 = OpFAdd %float %48 %52
         %54 = OpExtInst %float %34 Pow %9 %float_4
         %56 = OpCompositeExtract %float %33 4
         %57 = OpFMul %float %56 %54
         %58 = OpFAdd %float %53 %57
         %59 = OpExtInst %float %34 Pow %9 %float_5
         %61 = OpCompositeExtract %float %33 5
         %62 = OpFMul %float %61 %59
         %63 = OpFAdd %float %58 %62
         %64 = OpExtInst %float %34 Pow %9 %float_6
         %66 = OpCompositeExtract %float %33 6
         %67 = OpFMul %float %66 %64
         %68 = OpFAdd %float %63 %67
         %69 = OpExtInst %float %34 Pow %9 %float_7
         %71 = OpCompositeExtract %float %33 7
         %72 = OpFMul %float %71 %69
         %73 = OpFAdd %float %68 %72
               OpReturnValue %73
               OpFunctionEnd
      %addSq = OpFunction %float Const %16
         %14 = OpFunctionParameter %float
         %15 = OpFunctionParameter %float
%FunctionEntry_0 = OpLabel
         %19 = OpFMul %float %14 %14
         %20 = OpFMul %float %15 %15
         %21 = OpFAdd %float %19 %20
               OpReturnValue %21
               OpFunctionEnd
       %main = OpFunction %void None %4
%FunctionEntry = OpLabel
         %12 = OpFunctionCall %float %addGlobalTime %float_16
         %13 = OpFunctionCall %float %polynomial %12
               OpReturn
               OpFunctionEnd
```

`-types` and `-constants` will import newly introduced OpType and OpConstant instructions. Without we will run into these errors (pointer type missing):

```cpp
%u_Time         OpVariable %2 Uniform -> Error: [u_Time] OpType operand instruction not found! use 'ImportMissingTypes'
%2              OpTypePointer Uniform float
...
%21             OpFDiv float %20 1000.000000 -> Error: [UNNAMED-SYMBOL] OpConstant/OpSpecConstant operand instruction not found! use 'ImportMissingConstants'
%5              OpConstant float 1000.000000
```

`-reffuncs` and `-refvars` will import implicitly referenced functions and variables used in `float addGlobalTime(float x)` and `float polynomial(float x)`. Without those we will run in the following errors:

```cpp
Error: Call to unresolved OpFunction addSq
%22             OpFunctionCall float %addSq %18 %21 -> Error: [UNNAMED-SYMBOL] OpFunction operand instruction not found!
%addSq          OpFunction float Const %3
                OpReturnValue %22 -> Error: [UNNAMED-SYMBOL] OpFunctionCall operand instruction not found!
%22             OpFunctionCall float %addSq %18 %21

%20             OpLoad float %u_Time None -> Error: [UNNAMED-SYMBOL] OpVariable operand instruction not found!
%u_Time         OpVariable %2 Uniform
%21             OpFDiv float %20 1000.000000 -> Error: [UNNAMED-SYMBOL] OpLoad operand instruction not found!
%20             OpLoad float %u_Time None
%22             OpFunctionCall float %addSq %18 %21 -> Error: [UNNAMED-SYMBOL] OpFDiv operand instruction not found!
%21             OpFDiv float %20 1000.000000
```

`-extsets` will import OpExtInstImport instructions referenced by OpExtInst in any of the newly imported functions. Without this option we can not use functions with extension set instructions:

```cpp
%23             OpExtInst float %1 Pow %20 0.000000 -> Error: [UNNAMED-SYMBOL] OpExtInstImport operand instruction not found!
%1              OpExtInstImport "GLSL.std.450"
%24             OpCompositeExtract float %22 0 -> %35           OpCompositeExtract float %33 0
%25             OpFMul float %24 %23 -> Error: [UNNAMED-SYMBOL] OpExtInst operand instruction not found!
%23             OpExtInst float %1 Pow %20 0.000000
```
