#include "example/Constants.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module examples::constants(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	Module module(_pAllocator, spv::Version, _pLogger);
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::GenericPointer);
	module.addCapability(spv::Capability::LiteralSampler);

	Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, "main");
	BasicBlock& bb = *main;

	// using addConstant() manually:
	{
		Constant myConst = module.newConstant();

		// manual constant setup
		myConst.addData(123u);
		myConst.setType<unsigned int>();
		myConst.setOperation(spv::Op::OpConstant);

		// add constant to cache/map and retrieve generated OpConstantXXX instruction
		Instruction* inst = module.addConstant(myConst);

		myConst.reset(); // clear data and type for reuse

		// make infers type, data and operation based on value passed
		myConst.make(1337.f);
		inst = module.addConstant(myConst);	
	}

	// use module constant()
	{
		// create a vec3
		Instruction* vecconst = module.constant(make_vector(1.f, 2.f, 3.f));

		// create a literal sampler constant
		Instruction* samplerconst = module.constant(const_sampler_t{ spv::SamplerAddressingMode::ClampToEdge, ConstantSamplerCoordMode::UnNormalized, spv::SamplerFilterMode::Linear});

		// create a nullptr constant for unsigned int pointer
		Instruction* nullptrconst = module.constant(const_null_t<unsigned int*>{});
	}

	// specialization constatant
	{
		// integer specialization constant with value 42
		Instruction* intconst = module.constant(42u, true);

		//same as above, just a bit shorter
		Instruction* s2 = module.specConstant(3u);

		// add new constant without added a Constant descriptor, just the instruction
		// initialize the new instructions as UDiv operation
		// finally convert this UDiv operation to OpSpecConstantOp instruction
		Instruction* specOp = module.addConstantInstr()->opUDiv(intconst, s2)->toSpecOp();

		// same as above but with explicit opSpecConstantOp
		specOp = module.addConstantInstr()->opSpecConstantOp(module.type<unsigned int>(), spv::Op::OpIMul, s2, intconst);
	}

	bb.returnValue();

	return module;
}
