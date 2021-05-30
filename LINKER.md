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

Note that this is just pseudo SPIR-V code, it's valid but not meaningful. The generating code looks something like this:

```cpp
	// float polynomial(float x);
	Function& funcPolynomial = module.addFunction<float, float>(u8"polynomial", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcPolynomial.getFunction(), spv::LinkageType::Export, "@polynomial");
	{
		BasicBlock& bb = *funcPolynomial; // get entry block to this function
		Instruction* x = funcPolynomial.getParameter(0);
		module.addName(x, "x");

		Instruction* loopCount = module.constant(8u, "count");
		Instruction* varI = funcPolynomial.variable(0u, "i");
		Instruction* varSum = funcPolynomial.variable<float>(0.f, "s");
		Instruction* fltPtr = module.type<float*>("float*", spv::StorageClass::Uniform);

		Instruction* one = module.constant(1);

		BasicBlock& merge = bb.Loop([&](BasicBlock& cond) -> Instruction*
		{
			auto i = cond->opLoad(varI);
			return cond.Less(i, loopCount);
		}, [&](BasicBlock& inc)
		{
			auto i = inc->opLoad(varI);
			i = inc.Add(i, one);
			inc->opStore(varI, i); // i++
		}, [&](BasicBlock& body)
		{
			auto i = body->opLoad(varI);
			auto k = body->opConvertUToF(i);

			// x += x^k * coeff[i]
			Instruction* Xk = body.ext<ext::GLSL>()->opPow(x, k);
			Instruction* Ai = body->opAccessChain(fltPtr, uniformCoefficients, i);
			Ai = body->opLoad(Ai);
			Instruction* AkXk = body.Mul(Ai, Xk);

			auto s = body->opLoad(varSum);
			s = body.Add(s, AkXk);
			body->opStore(varSum, s);
		});
		
		auto s = merge->opLoad(varSum);
		merge.returnValue(s);
	}
```

We can import __exportA.spv__ and __exportB.spv__ into __import.spv__ and store the result in __linked.spv__ with these arguments:
```
SpvGenTwoLinker.exe -l exportA.spv -l exportB.spv -c import.spv -o linked.spv -types -constants -reffuncs -refvars -extsets -verbose
```

## linked.spv (result)
```cpp
; SPIR-V
; Version: 1.0
; Generator: Unknown(250); 0
; Bound: 64
; Schema: 0
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical Simple
               OpEntryPoint Fragment %main "main"
               OpExecutionMode %main OriginUpperLeft
               OpName %addGlobalTime "addGlobalTime"
               OpName %polynomial "polynomial"
               OpName %main "main"
               OpName %FunctionEntry "FunctionEntry"
               OpName %u_Time "u_Time"
               OpName %addSq "addSq"
               OpName %FunctionEntry_0 "FunctionEntry"
               OpName %FunctionEntry_1 "FunctionEntry"
               OpName %u_Coefficients "u_Coefficients"
               OpName %FunctionEntry_2 "FunctionEntry"
               OpName %x "x"
               OpName %i "i"
               OpName %s "s"
               OpName %LoopEntry "LoopEntry"
               OpName %LoopCondition "LoopCondition"
               OpName %LoopBody "LoopBody"
               OpName %LoopContinue "LoopContinue"
               OpName %LoopMerge "LoopMerge"
      %float = OpTypeFloat 32
          %3 = OpTypeFunction %float %float
       %void = OpTypeVoid
          %5 = OpTypeFunction %void
   %float_16 = OpConstant %float 16
          %7 = OpTypeFunction %float %float %float
%_ptr_Uniform_float = OpTypePointer Uniform %float
 %float_1000 = OpConstant %float 1000
%_ptr_Function_float = OpTypePointer Function %float
    %float_0 = OpConstant %float 0
       %uint = OpTypeInt 32 0
%_ptr_Function_uint = OpTypePointer Function %uint
     %uint_0 = OpConstant %uint 0
       %bool = OpTypeBool
         %16 = OpSpecConstant %uint 8
     %uint_8 = OpConstant %uint 8
%_arr_float_uint_8 = OpTypeArray %float %uint_8
%_ptr_Uniform__arr_float_uint_8 = OpTypePointer Uniform %_arr_float_uint_8
        %int = OpTypeInt 32 1
      %int_1 = OpConstant %int 1
     %u_Time = OpVariable %_ptr_Uniform_float Uniform
%u_Coefficients = OpVariable %_ptr_Uniform__arr_float_uint_8 Uniform
%addGlobalTime = OpFunction %float Const %3
         %25 = OpFunctionParameter %float
%FunctionEntry_1 = OpLabel
         %27 = OpLoad %float %u_Time None
         %28 = OpFDiv %float %27 %float_1000
         %29 = OpFunctionCall %float %addSq %25 %28
               OpReturnValue %29
               OpFunctionEnd
 %polynomial = OpFunction %float Const %3
          %x = OpFunctionParameter %float
%FunctionEntry_2 = OpLabel
          %s = OpVariable %_ptr_Function_float Function %float_0
          %i = OpVariable %_ptr_Function_uint Function %uint_0
               OpBranch %LoopEntry
  %LoopEntry = OpLabel
               OpLoopMerge %LoopMerge %LoopContinue None
               OpBranch %LoopCondition
%LoopCondition = OpLabel
         %37 = OpLoad %uint %i None
         %38 = OpULessThan %bool %37 %16
               OpBranchConditional %38 %LoopBody %LoopMerge
   %LoopBody = OpLabel
         %40 = OpLoad %uint %i None
         %41 = OpConvertUToF %float %40
         %42 = OpExtInst %float %1 Pow %x %41
         %43 = OpAccessChain %_ptr_Uniform_float %u_Coefficients %40
         %44 = OpLoad %float %43 None
         %45 = OpFMul %float %44 %42
         %46 = OpLoad %float %s None
         %47 = OpFAdd %float %46 %45
               OpStore %s %47 None
               OpBranch %LoopContinue
%LoopContinue = OpLabel
         %49 = OpLoad %uint %i None
         %50 = OpIAdd %uint %49 %int_1
               OpStore %i %50 None
               OpBranch %LoopEntry
  %LoopMerge = OpLabel
         %52 = OpLoad %float %s None
               OpReturnValue %52
               OpFunctionEnd
      %addSq = OpFunction %float Const %7
         %54 = OpFunctionParameter %float
         %55 = OpFunctionParameter %float
%FunctionEntry_0 = OpLabel
         %57 = OpFMul %float %54 %54
         %58 = OpFMul %float %55 %55
         %59 = OpFAdd %float %57 %58
               OpReturnValue %59
               OpFunctionEnd
       %main = OpFunction %void None %5
%FunctionEntry = OpLabel
         %62 = OpFunctionCall %float %addGlobalTime %float_16
         %63 = OpFunctionCall %float %polynomial %62
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

Instead of explicitly stating which parts should be imported, we can also just use `-auto` or `-AllOptions` the import everything needed, but this may come at a performance cost in return.
