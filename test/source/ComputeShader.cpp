#include "test/Modules.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module test::computeShader(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::Kernel);
	module.addCapability(spv::Capability::Addresses);
	module.addCapability(spv::Capability::Int64);

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
		auto* zero = module.constant(1ull);
		bb->opCopyMemorySized(target, uniArray, zero);		

		bb->opSatConvertSToU(module.constant(13u));
		bb->opSatConvertUToS(module.constant(1337u));

		Instruction* intVec1 = module.constant(make_vector(0u, 3u, 4u));
		Instruction* intVec2 = module.constant(make_vector(3u, 0u, 4u));

		bb->opIAddCarry(intVec1, intVec2);
		bb->opISubBorrow(intVec2, intVec1);
		bb->opUMulExtended(intVec1, intVec1);

		bb.returnValue();
	}

	return module;
}
