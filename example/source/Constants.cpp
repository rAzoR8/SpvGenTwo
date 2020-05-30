#include "Constants.h"

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

		Instruction* inst = module.addConstant(myConst);

		myConst.reset();

		// make infers type, data and operation based on value passed
		myConst.make(1337.f);
		inst = module.addConstant(myConst);	
	}

	// use module constant()
	{
		// integer specialization constant with value 42
		Instruction* intconst = module.constant(42u, true);

		// create a vec3
		Instruction* vecconst = module.constant(make_vector(1.f, 2.f, 3.f));

		// create a literal sampler constant
		Instruction* samplerconst = module.constant(const_sampler_t{ spv::SamplerAddressingMode::ClampToEdge, ConstantSamplerCoordMode::UnNormalized, spv::SamplerFilterMode::Linear});

		// create a nullptr constant for unsigned int pointer
		Instruction* nullptrconst = module.constant(const_null_t<unsigned int*>{});
	}

	bb.returnValue();

	return module;
}
