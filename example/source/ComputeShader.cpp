#include "example/ComputeShader.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module examples::computeShader(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::Kernel);

	// global variables

	//struct
	//{
	//	float x[];
	//};

	Type stArray = module.newType().Struct();
	// add runt-time float array
	stArray.Member().RuntimeArrayElement().Float();

	Instruction* uniRtArray = module.uniform(stArray, "u_RtArray");

	// void main(); entry point
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Kernel, "main");

		BasicBlock& bb = *entry; // get entry block to this function

		Instruction* arLength = bb->opArrayLength(uniRtArray, 0u);

		bb.returnValue();
	}

	return module;
}
