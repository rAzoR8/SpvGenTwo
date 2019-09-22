#include "..\include\cli.h"
#include "cli.h"
#include <assert.h>
#include <stdio.h>
#include <cstdlib>

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

BinaryFileWriter::BinaryFileWriter(const char* _path)
{
	m_pFile = fopen(_path, "wb");
}

BinaryFileWriter::~BinaryFileWriter()
{
	if (m_pFile != nullptr)
	{
		fflush(m_pFile);
		fclose(m_pFile);
		m_pFile = nullptr;
	}
}

long BinaryFileWriter::put(unsigned int _word)
{
	if (m_pFile != nullptr)
	{
		fwrite(&_word, sizeof(unsigned int), 1u, m_pFile);
		auto pos = ftell(m_pFile);
		printf("%llu:\t0x%X\t\t%u\n", pos - sizeof(unsigned int), _word, _word);
		return pos;
	}

	return 0;
}

void BinaryFileWriter::putAt(unsigned int _word, const long _offset)
{
	if (m_pFile != nullptr && fseek(m_pFile, _offset, SEEK_SET) == 0)
	{
		put(_word);
	}
}

int main(int argc, char* argv[])
{
	HeapAllocator alloc;

	Module module(&alloc);

	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::VulkanMemoryModelKHR);
	module.addExtension("SPV_KHR_vulkan_memory_model");
	module.addExtensionInstructionImport("GLSL.std.450");
	module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

	Function& func = module.addFunction();
	BasicBlock& bb = func.addBasicBlock();

	auto c1 = module.newConstant();
	auto c2 = module.newConstant();

	auto const1 = module.addConstant(c1.make(1));
	auto const2 = module.addConstant(c2.make(2));

	Instruction* instr = bb.addInstruction()->opIAdd(const1->getType(), const1, const2);
	bb.returnValue(/*instr*/);

	// int fun(float, float);
	func.createSignature().VoidM();// .FloatM().FloatM();
	func.finalize(spv::FunctionControlMask::Const);

	func.promoteToEntryPoint(spv::ExecutionModel::Vertex, "main");

	{
		BinaryFileWriter writer("test.spv");
		module.write(&writer);
	}

	system("spirv-dis test.spv");
	system("spirv-val test.spv");

	return 0;
}