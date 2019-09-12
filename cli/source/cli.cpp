#include "cli.h"

using namespace spvgentwo;

void* HeapAllocator::allocate(const size_t _bytes, const unsigned int _aligment) 
{
	(void)_aligment;
	return malloc(_bytes);
}
void HeapAllocator::deallocate(void* _ptr)
{
	free(_ptr);
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