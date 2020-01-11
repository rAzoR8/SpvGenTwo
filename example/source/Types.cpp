#include "Types.h"

using namespace spvgentwo;

Module examples::types(IAllocator* _pAllocator, ILogger* _pLogger)
{
	 Module module(_pAllocator, spv::Version, _pLogger);
	 module.addCapability(spv::Capability::Shader);
	 Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, "main");
	 BasicBlock& bb = *main;

	 Type myStruct = module.newType();

	 //struct myStruct
	 //{
		// float x;
		// int y;
		// vec3 v;
	 //};

	 myStruct.Struct();
	 myStruct.FloatM(); // add 32 bit float as member
	 myStruct.IntM(); // add signed int as member
	 myStruct.Member().VectorElement(3).Float(); // add empty member to struct, make it a vector of 3 elements of type float

	 // add via addType, make a pointer for storage class 'function
	 Instruction* type = module.addType(myStruct.wrapPointer(spv::StorageClass::Function));
	 //Instruction* var = bb->opVariable(type, spv::StorageClass::Function);

	 // add C++ type via type<T>
	 //type = module.type<sampler_t>();

	 bb.returnValue();

	 return module;
}
