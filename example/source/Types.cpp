#include "example/Types.h"

#include "common/TypeHelper.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

Module examples::types(IAllocator* _pAllocator, ILogger* _pLogger)
{
	Module module(_pAllocator, _pLogger);
	module.addCapability(spv::Capability::Shader);
	{
		Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, u8"main");
		BasicBlock& bb = *main;

		Type innerStruct = module.newType().RayQueryKHR().wrapStruct();

		//struct innerStruct
		//{
		   // ray_query_khr_t query;
		//};

		// add a name to the type
		module.addType(innerStruct, u8"innerStruct");

		Type myStruct = module.newType();

		//struct myStruct
		//{
		   // float x;
		   // int y;
		   // vec3 v;
		   // innerStruct i;
		//};

		myStruct.Struct();
		myStruct.FloatM(); // add 32 bit float as member
		myStruct.IntM(); // add signed int as member
		myStruct.Member().VectorElement(3).Float(); // add empty member to struct, make it a vector of 3 elements of type float
		myStruct.Member(&innerStruct);

		Instruction* type = module.addType(myStruct, u8"myStruct");
		
		String name(_pAllocator);
		TypeHelper::getTypeName(myStruct, name, type);
		_pLogger->logDebug("%s", name.c_str());

		type = module.addType(myStruct.wrapPointer(spv::StorageClass::Function));
		// add via addType, make a pointer for storage class 'function
		Instruction* var = bb->opVariable(type, spv::StorageClass::Function);

		// add C++ type via type<T>
		type = module.type<unsigned int*>(spv::StorageClass::Function, "uintptr");

		dyn_sampled_image_t img{ spv::Op::OpTypeFloat };

		// add complex dynamic C++ type
		type = module.type<dyn_sampled_image_t>(img);

		bb.returnValue();
	}

	{
		Function& f = module.addFunction<int, float, int, sampler_t, vector_t<float, 3>>("testFunc");
		
		String name(_pAllocator);
		TypeHelper::getTypeName(f.getFunctionType(), name, f.getFunction());
		_pLogger->logDebug("%s", name.c_str());

		BasicBlock& bb = *f;
		Instruction* var = f.variable<array_t<int, 6>>("myArray");
		var = bb->opLoad(var);

		name.clear();
		TypeHelper::getTypeName(*var->getType(), name, var);
		_pLogger->logDebug("%s", name.c_str());

		var = bb->opCompositeExtract(var, 3u);

		(*f).returnValue(var);
	}

	return module;
}
