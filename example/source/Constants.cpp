#include "Constants.h"

using namespace spvgentwo;

spvgentwo::Module examples::constants(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	Module module(_pAllocator, spv::Version, _pLogger);
	module.addCapability(spv::Capability::Shader);
	Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, "main");
	BasicBlock& bb = *main;

	Constant myConst = module.newConstant();

	myConst.addData(123);
	myConst.setType<int>();
	myConst.setOperation(spv::Op::OpConstant);

	Instruction* inst = module.addConstant(myConst);

	bb.returnValue();

	return module;
}
