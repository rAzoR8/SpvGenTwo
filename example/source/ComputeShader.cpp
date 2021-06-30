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

	using complex = array_t<vector_t<float, 4>, 8>;

	Instruction* uniArray = module.uniform<complex>("u_Array");

	// void main(); entry point
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Kernel, "main");

		BasicBlock& bb = *entry; // get entry block to this function

		Instruction* arLength = bb->opArrayLength(uniRtArray, 0u);

		Instruction* f3 = entry.variable(make_vector(1.f, -3.f, 1.f / -0.01f));
		f3 = bb->opLoad(f3);

		Instruction* g3 = bb->Div(f3, module.constant(-0.0f));

		bb->opIsNan(g3);
		bb->opIsInf(f3);
		bb->opIsFinite(g3);
		bb->opIsNormal(f3);
		bb->opSignBitSet(g3);
		bb->opOrdered(f3, g3);
		bb->opUnordered(f3, g3);

		Instruction* target = entry.variable<complex>("func_Array");
		bb->opCopyMemory(target, uniArray);		

		bb.returnValue();
	}

	return module;
}
