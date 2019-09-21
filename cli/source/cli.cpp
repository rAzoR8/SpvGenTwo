#include "..\include\cli.h"
#include "cli.h"
#include <assert.h>
#include <stdio.h>

using namespace spvgentwo;

void* HeapAllocator::allocate(const size_t _bytes, const unsigned int _aligment) 
{
	(void)_aligment;
	m_Allocated += _bytes;
	return malloc(_bytes);
}
void HeapAllocator::deallocate(void* _ptr, const size_t _bytes)
{
	m_Deallocated += _bytes;
	free(_ptr);
}

spvgentwo::HeapAllocator::~HeapAllocator()
{
	assert(m_Allocated == m_Deallocated);
	printf("Allocated %zu bytes\n", m_Allocated);
}

int main(int argc, char* argv[])
{
	HeapAllocator alloc;

	Module module(&alloc);

	module.addCapability(spv::Capability::Shader);
	module.addExtensionInstructionImport("GLSL.std.450");
	module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

	Function& func = module.addFunction();
	BasicBlock& bb = func.addBasicBlock();

	auto c1 = module.newConstant();
	auto c2 = module.newConstant();

	auto const1 = module.addConstant(c1.make(1));
	auto const2 = module.addConstant(c2.make(2));

	Instruction* instr = bb.addInstruction()->opIAdd(const1->getType(), const1, const2);

	// void fun(float, float);
	func.createSignature().VoidM().FloatM().FloatM();
	func.finalize(spv::FunctionControlMask::Const);

	func.promoteToEntryPoint(spv::ExecutionModel::Vertex, "main");

	BinaryFileWriter writer("test.spv");

	module.write(&writer);

	return 0;
}