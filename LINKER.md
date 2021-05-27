# SpvGenTwo - Linker

![SpvGenTwoLinker](/misc/linker.PNG)

SpvGenTwoLinker source can be found at [refl/source/link.cpp](refl/source/link.cpp)

CLI: SpvGenTwoLinker ```<option> <option> ...```

### Options

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

#### Flags:
    -ImportMissingTypes or -types
    -ImportMissingConstants or -constants
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