#include "..\include\cli.h"
#include "cli.h"
#include <assert.h>
#include <stdio.h>
#include <cstdlib>
#include "Operators.h"
#include "GLSL450Instruction.h"

using namespace spvgentwo;
using namespace ops;
using namespace ext;

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

void spvgentwo::ConsoleLogger::log(const LogLevel _level, const char* _pMsg)
{
	switch (_level)
	{
	case LogLevel::Debug:
		printf("Debug: "); break;
	case LogLevel::Info:
		printf("Info: "); break;
	case LogLevel::Warning:
		printf("Warning: "); break;
	case LogLevel::Error:
		printf("Error: "); break;
	case LogLevel::Fatal:
		printf("Fatal: "); break;
	default:
		break;
	}

	printf("%s", _pMsg);
	printf("\n");
}

int main(int argc, char* argv[])
{
	ConsoleLogger log;
	HeapAllocator alloc;

	Module module(spv::Version, &alloc, &log);

	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::VulkanMemoryModelKHR);
	module.addExtension("SPV_KHR_vulkan_memory_model");
	Instruction* ext = module.getExtensionInstructionImport("GLSL.std.450");
	module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

	Instruction* uniformVar = module.uniform<vector_t<float, 3>>("u_Position");

	dyn_sampled_image_t img{ spv::Op::OpTypeFloat };

	Instruction* uniNormal = module.uniform<dyn_sampled_image_t>("u_normalMap", img);

	// float add(float x, float y)
	Function& funcAdd = module.addFunction<float, float, float>("add", spv::FunctionControlMask::Const);
	{
		BasicBlock& bb = *funcAdd;

		Instruction* x = funcAdd.getParameter(0);
		Instruction* y = funcAdd.getParameter(1);

		Instruction* atan2 = bb.ext<GLSL>()->opAtan2(y, x);
		Instruction* pow = bb.ext<GLSL>()->opPow(atan2, y);

		Instruction* intvec = module.constant(const_vector_t<int, 3>{1, -3, 2});

		Instruction* signs = bb.ext<GLSL>()->opSSign(intvec);
		Instruction* abs = bb.ext<GLSL>()->opSAbs(signs);
		Instruction* smin = bb.ext<GLSL>()->opSMin(abs, signs);

		Instruction* z = bb.Add(x, y);
		z = bb.ext<GLSL>()->opRound(z);

		Instruction* uniVec = bb->opLoad(uniformVar);

		Instruction* cross = bb.ext<GLSL>()->opCross(uniVec, uniVec);
		bb->opDot(cross, uniVec);

		bb->opOuterProduct(uniVec, uniVec);

		Instruction* uniY = bb->opCompositeExtract(uniVec, 1u);
		
		Instruction* index = funcAdd.variable<int>(2, "index");
		index = bb->opLoad(index);

		Instruction* extracted = bb->opVectorExtractDynamic(cross, index);

		Instruction* insert = bb->opCompositeInsert(uniVec, z, 2u); // insert at z
		insert = bb->opCopyObject(insert);

		Instruction* mat = bb->opOuterProduct(insert, module.constant(const_vector_t<float, 4>{1.f, 2.f, 3.f, 4.f}));
		mat = bb->opTranspose(mat);

		Instruction* vecType = module.type<vector_t<float, 3>>();
		Instruction* newVec = bb->opCompositeConstruct(vecType, x, y, z);
		newVec = bb->opVectorInsertDynamic(newVec, extracted, index);

		Instruction* coord = module.constant(make_vector(0.5f, 0.5f));
		Instruction* normal = bb->opLoad(uniNormal);
		Instruction* lod = module.constant(0.5f);
		Instruction* normSample = bb->opImageSampleExplicitLodLevel(normal, coord, lod);
		normSample = bb->opImageSampleImplictLod(normal, coord);

		Instruction* uniformComp = bb->opAccessChain(uniformVar, 0u);
		Instruction* uniX = bb->opLoad(uniformComp);

		Instruction* cond = bb.Eq(uniX, uniY);

		Instruction* res1 = nullptr;
		Instruction* res2 = nullptr;

		BasicBlock& merge = bb.If(cond, [&](BasicBlock& trueBB)
		{
			res1 = trueBB.Add(z, x) * uniX;
		}, [&](BasicBlock& falseBB)
		{
			res2 = falseBB.Sub(z, x) * uniX;
		});		
		
		merge.returnValue(merge->opPhi(res1, res2));
	}

	Function& loopFunc = module.addFunction<void>("loop", spv::FunctionControlMask::Const);
	{
		Instruction* one = module.constant(1);
		Instruction* loopCount = module.constant(10);
		Instruction* varI = loopFunc.variable<int>(0);
		Instruction* varSum = loopFunc.variable<float>(1.1f);

		BasicBlock& loop = loopFunc.addBasicBlock();
		loopFunc->opBranch(&loop);

		BasicBlock& merge = loop.Loop([&](BasicBlock& cond)
		{
			auto i = cond->opLoad(varI);
			cond < loopCount;
		}, [&](BasicBlock& inc)
		{
			auto i = inc->opLoad(varI);
			i = inc.Add(i, one);
			inc->opStore(varI, i); // i++
		}, [&](BasicBlock& body)
		{
			auto s = body->opLoad(varSum);
			s = body.Mul(s, s);
			body->opStore(varSum, s); // sum += sum
		});

		auto s = merge->opLoad(varSum);

		merge->call(&funcAdd, s, s);
		merge.returnValue();
		//merge.returnValue(funcAdd.getFunction());
	}

	// void entryPoint();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
		entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);
		entry->call(&loopFunc);
		entry->opReturn();
	}

	// test types and constants
#if 0
	Instruction* vectype = module.type<array_t<float, 3>>();
	Instruction* mattype = module.type<matrix_t<float, 3, 3>>();
	Instruction* consvec = module.constant(const_vector_t<float, 3>({ 1.f, 2.f, 3.f }));
	const_matrix_t<float, 2, 2> mat{ 1.f, 2.f, 3.f, 4.f };
	Instruction* consvmat = module.constant(mat);
	auto v = make_vector(1.f, 2.f, 3.f);
	auto m = make_matrix(v, v, v);
	auto ar = make_array(m, m);
	module.constant(ar);
#endif

	{
		BinaryFileWriter writer("test.spv");
		module.write(&writer);
	}

	system("spirv-dis test.spv");
	system("spirv-val test.spv");

	return 0;
}