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
	Function& func = module.addFunction();
	BasicBlock& bb = func.addBasicBlock();
	Instruction& instr = bb.addInstruction();
	instr.opCapability(spv::Capability::Shader);
	struct bl {
	char data[5]{ 'a', 'b', 'c', 'd', 'e' };
	}x;
	constexpr auto si = sizeof(bl);
	instr.appendLiterals(x);
	//Type& type = *instr.createType();
	//type.Int();

	return 0;
}