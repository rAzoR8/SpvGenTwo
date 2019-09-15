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
	Instruction& instr = bb.addInstruction();

	//struct myStruct
	//{
	//	float x;
	//	float y;
	//	unsigned int z;
	//};
	Type myStruct(&alloc);
	myStruct.Struct().FloatM().FloatM().UIntM();

	Type freeType(&alloc);

	// void fun(float, float);
	freeType.Function().VoidM().FloatM().FloatM();

	Type x(freeType);

	Type y(&alloc);
	y = myStruct;

	assert(x == freeType && y == myStruct);

	const Instruction* pInstr = module.addType(myStruct);

	const Instruction* pInstr2 = module.addType(myStruct);

	assert(pInstr == pInstr2);

	return 0;
}