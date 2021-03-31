#include "example/Linkage.h"
#include "common/LinkerHelper.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

spvgentwo::Module examples::linkageLib(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::Version, spv::AddressingModel::Logical, spv::MemoryModel::GLSL450, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Linkage);

	Instruction* uniformVar = module.uniform<float>(u8"u_Time");
	LinkerHelper::addLinkageDecoration(uniformVar, spv::LinkageType::Export, "@u_Time");

	// float add(float x, float y)
	Function& funcAdd = module.addFunction<float, float, float>(u8"add", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcAdd.getFunction(), spv::LinkageType::Export, "@add");
	{
		BasicBlock& bb = *funcAdd; // get entry block to this function

		Instruction* x = funcAdd.getParameter(0);
		Instruction* y = funcAdd.getParameter(1);

		Instruction* z = bb.Add(x, y);
		bb.returnValue(z);
	}

	// float addGlobalTime(float x);
	Function& funcAddGlobalTime = module.addFunction<float, float>(u8"addGlobalTime", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcAddGlobalTime.getFunction(), spv::LinkageType::Export, "@addGlobalTime");
	{
		BasicBlock& bb = *funcAddGlobalTime; // get entry block to this function
		Instruction* x = funcAddGlobalTime.getParameter(0);

		Instruction* uTime = bb->opLoad(uniformVar);
		Instruction* z = bb->call(&funcAdd, x, uTime); // call add(s, s)
		bb.returnValue(z);
	}

	// void main();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");

		Instruction* someValue = module.constant(16.f);

		entry->call(&funcAddGlobalTime, someValue ); // call add(s, s)
		entry->opReturn();
	}

	return module;
}

spvgentwo::Module examples::linkageConsumer(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::Version, spv::AddressingModel::Logical, spv::MemoryModel::GLSL450, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Linkage);

	Instruction* uniformVar = module.uniform<float>(u8"u_Time");
	LinkerHelper::addLinkageDecoration(uniformVar, spv::LinkageType::Import, "@u_Time");

	// float add(float x, float y)
	Function& funcAdd = module.addFunction<float, float, float>(u8"add", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcAdd.getFunction(), spv::LinkageType::Import, "@add");

	// float addGlobalTime(float x);
	Function& funcAddGlobalTime = module.addFunction<float, float>(u8"addGlobalTime", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcAddGlobalTime.getFunction(), spv::LinkageType::Import, "@addGlobalTime");

	// void main();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
		BasicBlock& bb = *entry; // get entry block to this function

		Instruction* someValue = module.constant(16.f);

		entry->call(&funcAddGlobalTime, someValue); // call add(s, s)
		entry->opReturn();
	}

	return module;
}

spvgentwo::Module examples::linkageLinked(const spvgentwo::Module& _lib, spvgentwo::Module& _consumer, spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	return spvgentwo::Module();
}
