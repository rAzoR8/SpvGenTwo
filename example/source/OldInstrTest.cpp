#include "OldInstrTest.h"

#include <cstdio>

#include "common/HeapAllocator.h"
#include "common/ConsoleLogger.h"
#include "spvgentwo/Operators.h"
#include "spvgentwo/GLSL450Instruction.h"

using namespace spvgentwo;
using namespace ops;
using namespace ext;

Module examples::oldInstrTest(IAllocator* _pAllocator, ILogger* _pLogger)
{
	Module module(_pAllocator, spv::Version, _pLogger);

	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::VulkanMemoryModelKHR);
	module.addExtension("SPV_KHR_vulkan_memory_model");
	Instruction* ext = module.getExtensionInstructionImport("GLSL.std.450");
	module.setMemoryModel(spv::AddressingModel::Logical, spv::MemoryModel::VulkanKHR);

	Instruction* uniformVar = module.uniform<vector_t<float, 3>>("u_Position");

	dyn_sampled_image_t img{ spv::Op::OpTypeFloat };

	Instruction* uniNormal = module.uniform<dyn_sampled_image_t>("u_normalMap", img);

	img.imageType.samplerAccess = SamplerImageAccess::Sampled;

	Instruction* uniImage = module.uniform<dyn_image_t>("u_someImage", img.imageType);

	// void entryPoint();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, "main");
		entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

		BasicBlock& bb = *entry;

		Instruction* x = module.constant(1.f);
		Instruction* y = module.constant(3.14f);

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

		Instruction* index = entry.variable<int>(2, "index");
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
		normSample = bb->opImageDrefGather(normal, coord, lod); // use lod as dref

		Instruction* intCoord = module.constant(make_vector(512, 512));
		Instruction* image = bb->opLoad(uniImage);
		Instruction* fetch = bb->opImageFetch(image, intCoord);

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

		merge.returnValue(/*merge->opPhi(res1, res2)*/);
	}

	return module;
}