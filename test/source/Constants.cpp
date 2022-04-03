#include "example/Constants.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module examples::constants(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	Module module(_pAllocator, _pLogger);
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::GenericPointer);
	module.addCapability(spv::Capability::LiteralSampler);
	module.addCapability(spv::Capability::Float64);
	module.addCapability(spv::Capability::Int16);
	module.addCapability(spv::Capability::Int8);

	Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, u8"main");
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

		// extract constant data 1337.f
		const float* val = inst->getConstant()->getDataAs<float>();
	}

	// use module constant()
	{
		// create a vec3
		Instruction* vecconst = module.constant(make_vector(1.f, 2.f, 3.f));
		vecconst = module.constant(make_vector(-1.0, 32.0));

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

		// two short 'short' vectors
		Instruction* vecconst1 = module.constant(make_vector((short)8, (short)-16), true);
		Instruction* vecconst2 = module.constant(make_vector((short)-32, (short)64), true);
		specOp = module.addConstantInstr()->opIMul(vecconst1, vecconst2)->toSpecOp();

		// test 8-bit integers
		Instruction* const1 = module.constant((char)4, true);
		Instruction* const2 = module.constant((char)-3, true);
		specOp = module.addConstantInstr()->opIMul(const1, const2)->toSpecOp();
	}

	bb.returnValue();

	return module;
}
