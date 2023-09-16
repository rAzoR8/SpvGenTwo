#include "test/Modules.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module test::bitInstructionTest(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	Module module(_pAllocator, _pLogger);
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::BitInstructions);
	module.addExtension(spv::Extension::SPV_KHR_bit_instructions);

	Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, u8"main");
	BasicBlock& bb = *main;
	{
		Instruction* const base = module.constant(0b1111000011110000, false, "base");
		Instruction* const insert = module.constant(0b0000111100000000, false, "insert");
		Instruction* const offset = module.constant(4, false, "offset");
		Instruction* const count = module.constant(4u, false, "count");

		Instruction* const base3 = bb->opCompositeConstruct(module.type<vector_t<int, 3>>(), base, insert, offset);
		Instruction* const insert3 = bb->opCompositeConstruct(module.type<vector_t<int, 3>>(), insert, base, offset);

		bb->opBitFieldInsert(base, insert, offset, count);
		bb->opBitFieldSExtract(base, offset, count);
		bb->opBitFieldUExtract(base, offset, count);
		bb->opBitReverse(base);
		
		bb->opBitFieldInsert(base3, insert3, offset, count);
		bb->opBitFieldSExtract(base3, offset, count);
		bb->opBitFieldUExtract(base3, offset, count);
		bb->opBitReverse(base3);
	}

	bb.returnValue();

	return module;
}
