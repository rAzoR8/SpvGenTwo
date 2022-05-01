#include "test/Modules.h"

#include "common/HeapAllocator.h"
#include "common/ConsoleLogger.h"
#include "spvgentwo/Operators.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;
using namespace ops;

Module test::physicalStorageTest(IAllocator* _pAllocator, ILogger* _pLogger)
{
	Module module(_pAllocator, _pLogger);

	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::VulkanMemoryModelKHR);
	module.addCapability(spv::Capability::Int64);
	module.addCapability(spv::Capability::PhysicalStorageBufferAddresses);
	module.setSpvVersion(1, 4);

	module.addExtension(spv::Extension::SPV_KHR_physical_storage_buffer);
	module.addExtension(spv::Extension::SPV_KHR_storage_buffer_storage_class);
	module.addExtension(spv::Extension::SPV_KHR_vulkan_memory_model);

	module.setMemoryModel(spv::AddressingModel::Physical64, spv::MemoryModel::VulkanKHR);
	
	Type storageBufferType = module.newType();
	//	struct 
	//	{ 
	//		uint64_t ptr; // to convert to a physical pointer
	//	};
	storageBufferType.Struct().Member().UInt(64);
	Instruction* storageBufferTypeIns = module.addType(storageBufferType);
	Instruction* storageBufferPtr = module.storageBuffer(storageBufferType, "testStorageBuffer");
	module.addDecorationInstr()->opDecorate(storageBufferTypeIns, spv::Decoration::Block);
	module.addDecorationInstr()->opDecorate(storageBufferPtr, spv::Decoration::DescriptorSet, 0);
	module.addDecorationInstr()->opDecorate(storageBufferPtr, spv::Decoration::Binding, 0);
	module.addDecorationInstr()->opMemberDecorate(storageBufferTypeIns, 0, spv::Decoration::Offset, literal_t{ 0 });

	Type physicalStorageBufferType = module.newType();
	//	struct
	//	{ 
	//		float data;
	//	};
	Type innerType = module.newType();
	innerType.Struct().Member().Float(32);
	physicalStorageBufferType.Pointer(spv::StorageClass::PhysicalStorageBuffer, &innerType);

	// void entryPoint();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::GLCompute, u8"main");

		BasicBlock& bb = *entry;

		Instruction* uintPtr = bb->opAccessChain(storageBufferPtr, 0u);
		Instruction* pUint = bb->opLoad(uintPtr);

		Instruction* ptrType = module.addType(physicalStorageBufferType);
		Instruction* bufferPtr = bb->opConvertUToPtr(ptrType, pUint);
		Instruction* floatPtr = bb->opAccessChain(bufferPtr, 0u);
		Instruction* pFloat = bb->opLoad(floatPtr, spvgentwo::spv::MemoryAccessMask::Aligned, literal_t{4});

		Instruction* ptrEqualRes = bb->opPtrEqual(storageBufferPtr, storageBufferPtr);
		Instruction* ptrNotEqualRes = bb->opPtrNotEqual(uintPtr, uintPtr);


		Instruction* cond = module.constant<bool>(false);
		BasicBlock& merge = bb.If(cond, [&](BasicBlock& trueBB)
			{
				// this branch is unreachable for the cond is always false
				trueBB->opUnreachable();
			});

		merge.returnValue();
	}

	return module;
}