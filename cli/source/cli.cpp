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

	Function& funcAdd = module.addFunction();
	{
		BasicBlock& bb = funcAdd.addBasicBlock();

		Instruction* type = module.type<int>();
		Instruction* x = funcAdd.addParameter(type);
		Instruction* y = funcAdd.addParameter(type);

		Instruction* z = bb->opIAdd(module.type<int>(), x, y);
		bb.returnValue(z);

		funcAdd.finalize(type, spv::FunctionControlMask::Const);
	}

	Function& entry = module.addFunction();

	{
		BasicBlock& bb = entry.addBasicBlock();
		Instruction* c1 = module.constant(1);
		Instruction* c2 = module.constant(2);

		Instruction* ptrType = module.type<int*>(spv::StorageClass::Uniform);

		bb->call(&funcAdd, c1, c2);
		bb.returnValue();

		// void fun();	
		entry.finalize(module.type<void>(), spv::FunctionControlMask::Const);
	}

	entry.promoteToEntryPoint(spv::ExecutionModel::Vertex, "main");

	{
		BinaryFileWriter writer("test.spv");
		module.write(&writer);
	}

	system("spirv-dis test.spv");
	system("spirv-val test.spv");

	return 0;
}