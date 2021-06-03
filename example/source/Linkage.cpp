#include "example/Linkage.h"
#include "common/LinkerHelper.h"
#include "spvgentwo/Templates.h"
#include "common/ModulePrinter.h"

#include "spvgentwo/GLSL450Instruction.h"

#include <stdio.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h> // OutputDebugStringA
#endif

using namespace spvgentwo;

spvgentwo::Module examples::linkageLibA(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::Simple, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::Linkage);

	Instruction* uniformVar = module.uniform<float>(u8"u_Time");
	//LinkerHelper::addLinkageDecoration(uniformVar, spv::LinkageType::Export, "@u_Time");

	// float addSq(float x, float y)
	Function& funcAdd = module.addFunction<float, float, float>(u8"addSq", spv::FunctionControlMask::Const);
	{
		BasicBlock& bb = *funcAdd; // get entry block to this function

		Instruction* x = funcAdd.getParameter(0);
		Instruction* y = funcAdd.getParameter(1);

		x = bb.Mul(x, x);
		y = bb.Mul(y, y);
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
		Instruction* scale = module.constant(1000.f);
		uTime = bb->Div(uTime, scale);
		Instruction* z = bb->call(&funcAdd, x, uTime); // call add(s, s)
		bb.returnValue(z);
	}

	// void main();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
		entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

		Instruction* someValue = module.constant(16.f);

		entry->call(&funcAddGlobalTime, someValue); // call add(s, s)
		entry->opReturn();
	}

	return module;
}

spvgentwo::Module examples::linkageLibB(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::Simple, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::Linkage);
	module.addCapability(spv::Capability::GenericPointer);
	
	Instruction* uniformCoefficients = module.uniform<array_t<float, 8>>(u8"u_Coefficients");
	LinkerHelper::addLinkageDecoration(uniformCoefficients, spv::LinkageType::Export, "@u_Coefficients");

	// float polynomial(float x);
	Function& funcPolynomial = module.addFunction<float, float>(u8"polynomial", spv::FunctionControlMask::Const);
	LinkerHelper::addLinkageDecoration(funcPolynomial.getFunction(), spv::LinkageType::Export, "@polynomial");
	{
		BasicBlock& bb = *funcPolynomial; // get entry block to this function
		Instruction* x = funcPolynomial.getParameter(0);
		module.addName(x, "x");

		Instruction* loopCount = module.constant(8u, "count");
		Instruction* varI = funcPolynomial.variable(0u, "i");
		Instruction* varSum = funcPolynomial.variable<float>(0.f, "s");
		Instruction* fltPtr = module.type<float*>("float*", spv::StorageClass::Uniform);

		Instruction* one = module.constant(1);

		BasicBlock& merge = bb.Loop([&](BasicBlock& cond) -> Instruction*
		{
			auto i = cond->opLoad(varI);
			return cond.Less(i, loopCount);
		}, [&](BasicBlock& inc)
		{
			auto i = inc->opLoad(varI);
			i = inc.Add(i, one);
			inc->opStore(varI, i); // i++
		}, [&](BasicBlock& body)
		{
			auto i = body->opLoad(varI);
			auto k = body->opConvertUToF(i);

			// x += x^k * coeff[i]
			Instruction* Xk = body.ext<ext::GLSL>()->opPow(x, k);
			Instruction* Ai = body->opAccessChain(fltPtr, uniformCoefficients, i);
			Ai = body->opLoad(Ai);
			Instruction* AkXk = body.Mul(Ai, Xk);

			auto s = body->opLoad(varSum);
			s = body.Add(s, AkXk);
			body->opStore(varSum, s);
		});
		
		auto s = merge->opLoad(varSum);
		merge.returnValue(s);
	}

	// void main();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
		entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

		Instruction* x = module.constant(4.f);

		entry->call(&funcPolynomial, x); // call polynomial(4.f)
		entry->opReturn();
	}

	return module;
}

spvgentwo::Module examples::linkageConsumer(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	// create a new spir-v module
	Module module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::Simple, _pLogger);

	// configure capabilities and extensions
	module.addCapability(spv::Capability::Shader);
	module.addCapability(spv::Capability::Linkage);

	// float addGlobalTime(float x);
	Function& funcAddGlobalTime = module.addFunction<float, float>(u8"addGlobalTime", spv::FunctionControlMask::Const, false);
	LinkerHelper::addLinkageDecoration(funcAddGlobalTime.getFunction(), spv::LinkageType::Import, "@addGlobalTime");

	Function& funcPolynomial = module.addFunction<float, float>(u8"polynomial", spv::FunctionControlMask::Const, false);
	LinkerHelper::addLinkageDecoration(funcPolynomial.getFunction(), spv::LinkageType::Import, "@polynomial");

	// void main();
	{
		EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Fragment, u8"main");
		entry.addExecutionMode(spv::ExecutionMode::OriginUpperLeft);

		Instruction* someValue = module.constant(16.f);

		Instruction* x = entry->call(&funcAddGlobalTime, someValue); // call funcAddGlobalTime(16.f)
		entry->call(&funcPolynomial, x); // call polynomial()

		entry->opReturn();
	}

	return module;
}

bool examples::linkageLinked(const spvgentwo::Module& _libA, const spvgentwo::Module& _libB, spvgentwo::Module& _consumer, spvgentwo::IAllocator* _pAllocator, const spvgentwo::Grammar* _pGrammar)
{
	auto printer = ModulePrinter::ModuleSimpleFuncPrinter([](const char* str) {
		printf("%s", str);

#ifdef _WIN32
		OutputDebugStringA(str);
#endif
	});

	LinkerHelper::LinkerOptions options{};
	options.flags = LinkerHelper::LinkerOptionBits::All;
	options.grammar = _pGrammar;
	options.printer = &printer;
	options.allocator = _pAllocator;

	bool linkA = LinkerHelper::import(_libA, _consumer, options);
	bool linkB = LinkerHelper::import(_libB, _consumer, options);

	return linkA && linkB;
}
