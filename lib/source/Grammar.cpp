// Auto generated - do not modify
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Glsl.h"
#include "spvgentwo/OpenCl.h"
using namespace spvgentwo;

Grammar::Grammar(IAllocator* _pAllocator) : m_instructions(_pAllocator, 796)
{
	m_instructions.emplaceUnique(0ull << 32u |0u, Instruction{"OpNop", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |1u, Instruction{"OpUndef", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |2u, Instruction{"OpSourceContinued", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Continued Source'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |3u, Instruction{"OpSource", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::SourceLanguage, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Version'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Source'",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4u, Instruction{"OpSourceExtension", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Extension'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5u, Instruction{"OpName", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6u, Instruction{"OpMemberName", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |7u, Instruction{"OpString", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'String'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |8u, Instruction{"OpLine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Line'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |10u, Instruction{"OpExtension", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |11u, Instruction{"OpExtInstImport", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |12u, Instruction{"OpExtInst", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Set'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralExtInstInteger, OperandCategory::Literal, "'Instruction'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1', +'Operand 2', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |14u, Instruction{"OpMemoryModel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::AddressingModel, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryModel, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |15u, Instruction{"OpEntryPoint", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::ExecutionModel, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Interface'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |16u, Instruction{"OpExecutionMode", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |17u, Instruction{"OpCapability", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::Capability, OperandCategory::ValueEnum, "'Capability'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |19u, Instruction{"OpTypeVoid", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |20u, Instruction{"OpTypeBool", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |21u, Instruction{"OpTypeInt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Signedness'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |22u, Instruction{"OpTypeFloat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |23u, Instruction{"OpTypeVector", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Component Count'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |24u, Instruction{"OpTypeMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |25u, Instruction{"OpTypeImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Dim, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Depth'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Arrayed'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'MS'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Sampled'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageFormat, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::AccessQualifier, OperandCategory::ValueEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |26u, Instruction{"OpTypeSampler", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |27u, Instruction{"OpTypeSampledImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |28u, Instruction{"OpTypeArray", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Length'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |29u, Instruction{"OpTypeRuntimeArray", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |30u, Instruction{"OpTypeStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Member 0 type', +'member 1 type', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |31u, Instruction{"OpTypeOpaque", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "The name of the opaque type.",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |32u, Instruction{"OpTypePointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |33u, Instruction{"OpTypeFunction", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Return Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Parameter 0 Type', +'Parameter 1 Type', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |34u, Instruction{"OpTypeEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |35u, Instruction{"OpTypeDeviceEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |36u, Instruction{"OpTypeReserveId", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |37u, Instruction{"OpTypeQueue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |38u, Instruction{"OpTypePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::AccessQualifier, OperandCategory::ValueEnum, "'Qualifier'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |39u, Instruction{"OpTypeForwardPointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |41u, Instruction{"OpConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |42u, Instruction{"OpConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |43u, Instruction{"OpConstant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |44u, Instruction{"OpConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |45u, Instruction{"OpConstantSampler", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerAddressingMode, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerFilterMode, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::LiteralSampler);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |46u, Instruction{"OpConstantNull", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |48u, Instruction{"OpSpecConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |49u, Instruction{"OpSpecConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |50u, Instruction{"OpSpecConstant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |51u, Instruction{"OpSpecConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |52u, Instruction{"OpSpecConstantOp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralSpecConstantOpInteger, OperandCategory::Literal, "'Opcode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |54u, Instruction{"OpFunction", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FunctionControl, OperandCategory::BitEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |55u, Instruction{"OpFunctionParameter", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	m_instructions.emplaceUnique(0ull << 32u |56u, Instruction{"OpFunctionEnd", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |57u, Instruction{"OpFunctionCall", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Argument 0', +'Argument 1', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |59u, Instruction{"OpVariable", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Initializer'",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |60u, Instruction{"OpImageTexelPointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sample'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |61u, Instruction{"OpLoad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |62u, Instruction{"OpStore", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |63u, Instruction{"OpCopyMemory", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |64u, Instruction{"OpCopyMemorySized", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |65u, Instruction{"OpAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |66u, Instruction{"OpInBoundsAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |67u, Instruction{"OpPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::VariablePointers);
		instr.capabilities.emplace_back(spv::Capability::VariablePointersStorageBuffer);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |68u, Instruction{"OpArrayLength", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Array member'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |69u, Instruction{"OpGenericPtrMemSemantics", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |70u, Instruction{"OpInBoundsPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |71u, Instruction{"OpDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |72u, Instruction{"OpMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |73u, Instruction{"OpDecorationGroup", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |74u, Instruction{"OpGroupDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Targets'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |75u, Instruction{"OpGroupMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefLiteralInteger, OperandCategory::Composite, "'Targets'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |77u, Instruction{"OpVectorExtractDynamic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |78u, Instruction{"OpVectorInsertDynamic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |79u, Instruction{"OpVectorShuffle", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Components'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |80u, Instruction{"OpCompositeConstruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |81u, Instruction{"OpCompositeExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |82u, Instruction{"OpCompositeInsert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |83u, Instruction{"OpCopyObject", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |84u, Instruction{"OpTranspose", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |86u, Instruction{"OpSampledImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |87u, Instruction{"OpImageSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |88u, Instruction{"OpImageSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |89u, Instruction{"OpImageSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |90u, Instruction{"OpImageSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |91u, Instruction{"OpImageSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |92u, Instruction{"OpImageSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |93u, Instruction{"OpImageSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |94u, Instruction{"OpImageSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |95u, Instruction{"OpImageFetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |96u, Instruction{"OpImageGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |97u, Instruction{"OpImageDrefGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |98u, Instruction{"OpImageRead", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |99u, Instruction{"OpImageWrite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Texel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |100u, Instruction{"OpImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |101u, Instruction{"OpImageQueryFormat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |102u, Instruction{"OpImageQueryOrder", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |103u, Instruction{"OpImageQuerySizeLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Level of Detail'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |104u, Instruction{"OpImageQuerySize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |105u, Instruction{"OpImageQueryLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |106u, Instruction{"OpImageQueryLevels", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |107u, Instruction{"OpImageQuerySamples", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |109u, Instruction{"OpConvertFToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |110u, Instruction{"OpConvertFToS", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |111u, Instruction{"OpConvertSToF", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |112u, Instruction{"OpConvertUToF", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |113u, Instruction{"OpUConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |114u, Instruction{"OpSConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |115u, Instruction{"OpFConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |116u, Instruction{"OpQuantizeToF16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |117u, Instruction{"OpConvertPtrToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |118u, Instruction{"OpSatConvertSToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |119u, Instruction{"OpSatConvertUToS", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |120u, Instruction{"OpConvertUToPtr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Integer Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |121u, Instruction{"OpPtrCastToGeneric", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |122u, Instruction{"OpGenericCastToPtr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |123u, Instruction{"OpGenericCastToPtrExplicit", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "'Storage'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |124u, Instruction{"OpBitcast", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |126u, Instruction{"OpSNegate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |127u, Instruction{"OpFNegate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |128u, Instruction{"OpIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |129u, Instruction{"OpFAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |130u, Instruction{"OpISub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |131u, Instruction{"OpFSub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |132u, Instruction{"OpIMul", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |133u, Instruction{"OpFMul", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |134u, Instruction{"OpUDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |135u, Instruction{"OpSDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |136u, Instruction{"OpFDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |137u, Instruction{"OpUMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |138u, Instruction{"OpSRem", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |139u, Instruction{"OpSMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |140u, Instruction{"OpFRem", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |141u, Instruction{"OpFMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |142u, Instruction{"OpVectorTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |143u, Instruction{"OpMatrixTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |144u, Instruction{"OpVectorTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |145u, Instruction{"OpMatrixTimesVector", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |146u, Instruction{"OpMatrixTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LeftMatrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RightMatrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |147u, Instruction{"OpOuterProduct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |148u, Instruction{"OpDot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |149u, Instruction{"OpIAddCarry", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |150u, Instruction{"OpISubBorrow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |151u, Instruction{"OpUMulExtended", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |152u, Instruction{"OpSMulExtended", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |154u, Instruction{"OpAny", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |155u, Instruction{"OpAll", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |156u, Instruction{"OpIsNan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |157u, Instruction{"OpIsInf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |158u, Instruction{"OpIsFinite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |159u, Instruction{"OpIsNormal", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |160u, Instruction{"OpSignBitSet", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |161u, Instruction{"OpLessOrGreater", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |162u, Instruction{"OpOrdered", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |163u, Instruction{"OpUnordered", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |164u, Instruction{"OpLogicalEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |165u, Instruction{"OpLogicalNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |166u, Instruction{"OpLogicalOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |167u, Instruction{"OpLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |168u, Instruction{"OpLogicalNot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |169u, Instruction{"OpSelect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |170u, Instruction{"OpIEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |171u, Instruction{"OpINotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |172u, Instruction{"OpUGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |173u, Instruction{"OpSGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |174u, Instruction{"OpUGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |175u, Instruction{"OpSGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |176u, Instruction{"OpULessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |177u, Instruction{"OpSLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |178u, Instruction{"OpULessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |179u, Instruction{"OpSLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |180u, Instruction{"OpFOrdEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |181u, Instruction{"OpFUnordEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |182u, Instruction{"OpFOrdNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |183u, Instruction{"OpFUnordNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |184u, Instruction{"OpFOrdLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |185u, Instruction{"OpFUnordLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |186u, Instruction{"OpFOrdGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |187u, Instruction{"OpFUnordGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |188u, Instruction{"OpFOrdLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |189u, Instruction{"OpFUnordLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |190u, Instruction{"OpFOrdGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |191u, Instruction{"OpFUnordGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |194u, Instruction{"OpShiftRightLogical", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |195u, Instruction{"OpShiftRightArithmetic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |196u, Instruction{"OpShiftLeftLogical", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |197u, Instruction{"OpBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |198u, Instruction{"OpBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |199u, Instruction{"OpBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |200u, Instruction{"OpNot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |201u, Instruction{"OpBitFieldInsert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Insert'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |202u, Instruction{"OpBitFieldSExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |203u, Instruction{"OpBitFieldUExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |204u, Instruction{"OpBitReverse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |205u, Instruction{"OpBitCount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |207u, Instruction{"OpDPdx", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |208u, Instruction{"OpDPdy", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |209u, Instruction{"OpFwidth", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |210u, Instruction{"OpDPdxFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |211u, Instruction{"OpDPdyFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |212u, Instruction{"OpFwidthFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |213u, Instruction{"OpDPdxCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |214u, Instruction{"OpDPdyCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |215u, Instruction{"OpFwidthCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |218u, Instruction{"OpEmitVertex", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |219u, Instruction{"OpEndPrimitive", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |220u, Instruction{"OpEmitStreamVertex", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |221u, Instruction{"OpEndStreamPrimitive", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |224u, Instruction{"OpControlBarrier", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |225u, Instruction{"OpMemoryBarrier", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |227u, Instruction{"OpAtomicLoad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |228u, Instruction{"OpAtomicStore", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |229u, Instruction{"OpAtomicExchange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |230u, Instruction{"OpAtomicCompareExchange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Equal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Unequal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Comparator'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |231u, Instruction{"OpAtomicCompareExchangeWeak", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Equal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Unequal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Comparator'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |232u, Instruction{"OpAtomicIIncrement", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |233u, Instruction{"OpAtomicIDecrement", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |234u, Instruction{"OpAtomicIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |235u, Instruction{"OpAtomicISub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |236u, Instruction{"OpAtomicSMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |237u, Instruction{"OpAtomicUMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |238u, Instruction{"OpAtomicSMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |239u, Instruction{"OpAtomicUMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |240u, Instruction{"OpAtomicAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |241u, Instruction{"OpAtomicOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |242u, Instruction{"OpAtomicXor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |245u, Instruction{"OpPhi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefIdRef, OperandCategory::Composite, "'Variable, Parent, ...'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |246u, Instruction{"OpLoopMerge", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Continue Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LoopControl, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |247u, Instruction{"OpSelectionMerge", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SelectionControl, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |248u, Instruction{"OpLabel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |249u, Instruction{"OpBranch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target Label'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |250u, Instruction{"OpBranchConditional", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'True Label'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'False Label'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Branch weights'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |251u, Instruction{"OpSwitch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Selector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Default'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairLiteralIntegerIdRef, OperandCategory::Composite, "'Target'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |252u, Instruction{"OpKill", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	m_instructions.emplaceUnique(0ull << 32u |253u, Instruction{"OpReturn", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |254u, Instruction{"OpReturnValue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	m_instructions.emplaceUnique(0ull << 32u |255u, Instruction{"OpUnreachable", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |256u, Instruction{"OpLifetimeStart", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |257u, Instruction{"OpLifetimeStop", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |259u, Instruction{"OpGroupAsyncCopy", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Destination'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Elements'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |260u, Instruction{"OpGroupWaitEvents", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Events List'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |261u, Instruction{"OpGroupAll", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |262u, Instruction{"OpGroupAny", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |263u, Instruction{"OpGroupBroadcast", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |264u, Instruction{"OpGroupIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |265u, Instruction{"OpGroupFAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |266u, Instruction{"OpGroupFMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |267u, Instruction{"OpGroupUMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |268u, Instruction{"OpGroupSMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |269u, Instruction{"OpGroupFMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |270u, Instruction{"OpGroupUMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |271u, Instruction{"OpGroupSMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |274u, Instruction{"OpReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |275u, Instruction{"OpWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |276u, Instruction{"OpReservedReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |277u, Instruction{"OpReservedWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |278u, Instruction{"OpReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |279u, Instruction{"OpReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |280u, Instruction{"OpCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |281u, Instruction{"OpCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |282u, Instruction{"OpIsValidReserveId", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |283u, Instruction{"OpGetNumPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |284u, Instruction{"OpGetMaxPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |285u, Instruction{"OpGroupReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |286u, Instruction{"OpGroupReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |287u, Instruction{"OpGroupCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |288u, Instruction{"OpGroupCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |291u, Instruction{"OpEnqueueMarker", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Queue'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Wait Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ret Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |292u, Instruction{"OpEnqueueKernel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Queue'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Flags'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Wait Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ret Event'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Local Size'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |293u, Instruction{"OpGetKernelNDrangeSubGroupCount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |294u, Instruction{"OpGetKernelNDrangeMaxSubGroupSize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ND Range'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |295u, Instruction{"OpGetKernelWorkGroupSize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |296u, Instruction{"OpGetKernelPreferredWorkGroupSizeMultiple", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |297u, Instruction{"OpRetainEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |298u, Instruction{"OpReleaseEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |299u, Instruction{"OpCreateUserEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |300u, Instruction{"OpIsValidEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |301u, Instruction{"OpSetUserEventStatus", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Status'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |302u, Instruction{"OpCaptureEventProfilingInfo", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Profiling Info'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |303u, Instruction{"OpGetDefaultQueue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |304u, Instruction{"OpBuildNDRange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkSize'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalWorkSize'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkOffset'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |305u, Instruction{"OpImageSparseSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |306u, Instruction{"OpImageSparseSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |307u, Instruction{"OpImageSparseSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |308u, Instruction{"OpImageSparseSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |309u, Instruction{"OpImageSparseSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |310u, Instruction{"OpImageSparseSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |311u, Instruction{"OpImageSparseSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |312u, Instruction{"OpImageSparseSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |313u, Instruction{"OpImageSparseFetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |314u, Instruction{"OpImageSparseGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |315u, Instruction{"OpImageSparseDrefGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |316u, Instruction{"OpImageSparseTexelsResident", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Resident Code'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	m_instructions.emplaceUnique(0ull << 32u |317u, Instruction{"OpNoLine", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |318u, Instruction{"OpAtomicFlagTestAndSet", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |319u, Instruction{"OpAtomicFlagClear", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |320u, Instruction{"OpImageSparseRead", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |321u, Instruction{"OpSizeOf", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |322u, Instruction{"OpTypePipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |323u, Instruction{"OpConstantPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Alignment'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Capacity'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |324u, Instruction{"OpCreatePipeFromPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe Storage'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |325u, Instruction{"OpGetKernelLocalSizeForSubgroupCount", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroup Count'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupDispatch);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |326u, Instruction{"OpGetKernelMaxNumSubgroups", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupDispatch);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |327u, Instruction{"OpTypeNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |328u, Instruction{"OpNamedBarrierInitialize", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroup Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |329u, Instruction{"OpMemoryNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Named Barrier'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |330u, Instruction{"OpModuleProcessed", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Process'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |331u, Instruction{"OpExecutionModeId", _pAllocator, _pAllocator, _pAllocator, 66048}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |332u, Instruction{"OpDecorateId", _pAllocator, _pAllocator, _pAllocator, 66048}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |333u, Instruction{"OpGroupNonUniformElect", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniform);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |334u, Instruction{"OpGroupNonUniformAll", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |335u, Instruction{"OpGroupNonUniformAny", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |336u, Instruction{"OpGroupNonUniformAllEqual", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |337u, Instruction{"OpGroupNonUniformBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |338u, Instruction{"OpGroupNonUniformBroadcastFirst", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |339u, Instruction{"OpGroupNonUniformBallot", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |340u, Instruction{"OpGroupNonUniformInverseBallot", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |341u, Instruction{"OpGroupNonUniformBallotBitExtract", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |342u, Instruction{"OpGroupNonUniformBallotBitCount", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |343u, Instruction{"OpGroupNonUniformBallotFindLSB", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |344u, Instruction{"OpGroupNonUniformBallotFindMSB", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |345u, Instruction{"OpGroupNonUniformShuffle", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |346u, Instruction{"OpGroupNonUniformShuffleXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Mask'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |347u, Instruction{"OpGroupNonUniformShuffleUp", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |348u, Instruction{"OpGroupNonUniformShuffleDown", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |349u, Instruction{"OpGroupNonUniformIAdd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |350u, Instruction{"OpGroupNonUniformFAdd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |351u, Instruction{"OpGroupNonUniformIMul", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |352u, Instruction{"OpGroupNonUniformFMul", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |353u, Instruction{"OpGroupNonUniformSMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |354u, Instruction{"OpGroupNonUniformUMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |355u, Instruction{"OpGroupNonUniformFMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |356u, Instruction{"OpGroupNonUniformSMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |357u, Instruction{"OpGroupNonUniformUMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |358u, Instruction{"OpGroupNonUniformFMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |359u, Instruction{"OpGroupNonUniformBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |360u, Instruction{"OpGroupNonUniformBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |361u, Instruction{"OpGroupNonUniformBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |362u, Instruction{"OpGroupNonUniformLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |363u, Instruction{"OpGroupNonUniformLogicalOr", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |364u, Instruction{"OpGroupNonUniformLogicalXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ClusterSize'",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformArithmetic);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformClustered);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |365u, Instruction{"OpGroupNonUniformQuadBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |366u, Instruction{"OpGroupNonUniformQuadSwap", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |400u, Instruction{"OpCopyLogical", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |401u, Instruction{"OpPtrEqual", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |402u, Instruction{"OpPtrNotEqual", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |403u, Instruction{"OpPtrDiff", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::VariablePointers);
		instr.capabilities.emplace_back(spv::Capability::VariablePointersStorageBuffer);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4421u, Instruction{"OpSubgroupBallotKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4422u, Instruction{"OpSubgroupFirstInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4428u, Instruction{"OpSubgroupAllKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4429u, Instruction{"OpSubgroupAnyKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4430u, Instruction{"OpSubgroupAllEqualKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4432u, Instruction{"OpSubgroupReadInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4472u, Instruction{"OpTypeRayQueryProvisionalKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4473u, Instruction{"OpRayQueryInitializeKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayFlags'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'CullMask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayOrigin'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayTMin'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayDirection'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayTMax'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4474u, Instruction{"OpRayQueryTerminateKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4475u, Instruction{"OpRayQueryGenerateIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'HitT'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4476u, Instruction{"OpRayQueryConfirmIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4477u, Instruction{"OpRayQueryProceedKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |4479u, Instruction{"OpRayQueryGetIntersectionTypeKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5000u, Instruction{"OpGroupIAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5001u, Instruction{"OpGroupFAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5002u, Instruction{"OpGroupFMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5003u, Instruction{"OpGroupUMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5004u, Instruction{"OpGroupSMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5005u, Instruction{"OpGroupFMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5006u, Instruction{"OpGroupUMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5007u, Instruction{"OpGroupSMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5011u, Instruction{"OpFragmentMaskFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5012u, Instruction{"OpFragmentFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fragment Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5056u, Instruction{"OpReadClockKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ShaderClockKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_clock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5283u, Instruction{"OpImageSampleFootprintNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Granularity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coarse'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::ImageFootprintNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_shader_image_footprint);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5296u, Instruction{"OpGroupNonUniformPartitionNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_shader_subgroup_partitioned);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5299u, Instruction{"OpWritePackedPrimitiveIndices4x8NV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Indices'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::MeshShadingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_mesh_shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5334u, Instruction{"OpReportIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Hit'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'HitKind'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5335u, Instruction{"OpIgnoreIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5336u, Instruction{"OpTerminateRayKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5337u, Instruction{"OpTraceRayKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Accel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Flags'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cull Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Stride'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Miss Index'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Origin'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmin'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Direction'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ray Tmax'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'PayloadId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5341u, Instruction{"OpTypeAccelerationStructureKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5344u, Instruction{"OpExecuteCallableKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Index'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Callable DataId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5358u, Instruction{"OpTypeCooperativeMatrixNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Rows'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Columns'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5359u, Instruction{"OpCooperativeMatrixLoadNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Major'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5360u, Instruction{"OpCooperativeMatrixStoreNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Major'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5361u, Instruction{"OpCooperativeMatrixMulAddNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'A'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'B'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'C'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5362u, Instruction{"OpCooperativeMatrixLengthNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5364u, Instruction{"OpBeginInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5365u, Instruction{"OpEndInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5380u, Instruction{"OpDemoteToHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5381u, Instruction{"OpIsHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5571u, Instruction{"OpSubgroupShuffleINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'InvocationId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5572u, Instruction{"OpSubgroupShuffleDownINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Next'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5573u, Instruction{"OpSubgroupShuffleUpINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Previous'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5574u, Instruction{"OpSubgroupShuffleXorINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5575u, Instruction{"OpSubgroupBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5576u, Instruction{"OpSubgroupBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5577u, Instruction{"OpSubgroupImageBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5578u, Instruction{"OpSubgroupImageBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5580u, Instruction{"OpSubgroupImageMediaBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5581u, Instruction{"OpSubgroupImageMediaBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5585u, Instruction{"OpUCountLeadingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5586u, Instruction{"OpUCountTrailingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5587u, Instruction{"OpAbsISubINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5588u, Instruction{"OpAbsUSubINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5589u, Instruction{"OpIAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5590u, Instruction{"OpUAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5591u, Instruction{"OpIAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5592u, Instruction{"OpUAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5593u, Instruction{"OpIAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5594u, Instruction{"OpUAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5595u, Instruction{"OpISubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5596u, Instruction{"OpUSubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5597u, Instruction{"OpIMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5598u, Instruction{"OpUMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5600u, Instruction{"OpFunctionPointerINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5601u, Instruction{"OpFunctionPointerCallINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5632u, Instruction{"OpDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5633u, Instruction{"OpMemberDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Struct Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5699u, Instruction{"OpVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5700u, Instruction{"OpTypeVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5701u, Instruction{"OpTypeAvcImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5702u, Instruction{"OpTypeAvcRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5703u, Instruction{"OpTypeAvcSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5704u, Instruction{"OpTypeAvcMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5705u, Instruction{"OpTypeAvcMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5706u, Instruction{"OpTypeAvcImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5707u, Instruction{"OpTypeAvcImeResultSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5708u, Instruction{"OpTypeAvcImeResultDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5709u, Instruction{"OpTypeAvcImeSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5710u, Instruction{"OpTypeAvcImeDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5711u, Instruction{"OpTypeAvcRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5712u, Instruction{"OpTypeAvcSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5713u, Instruction{"OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5714u, Instruction{"OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Base Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5715u, Instruction{"OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5716u, Instruction{"OpSubgroupAvcMceSetInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5717u, Instruction{"OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5718u, Instruction{"OpSubgroupAvcMceSetInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction Cost'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5719u, Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5720u, Instruction{"OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5721u, Instruction{"OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5722u, Instruction{"OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5723u, Instruction{"OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5724u, Instruction{"OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Center Delta'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Table'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cost Precision'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5725u, Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5726u, Instruction{"OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5727u, Instruction{"OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5728u, Instruction{"OpSubgroupAvcMceSetAcOnlyHaarINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5729u, Instruction{"OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5730u, Instruction{"OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5731u, Instruction{"OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Forward Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Backward Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5732u, Instruction{"OpSubgroupAvcMceConvertToImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5733u, Instruction{"OpSubgroupAvcMceConvertToImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5734u, Instruction{"OpSubgroupAvcMceConvertToRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5735u, Instruction{"OpSubgroupAvcMceConvertToRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5736u, Instruction{"OpSubgroupAvcMceConvertToSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5737u, Instruction{"OpSubgroupAvcMceConvertToSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5738u, Instruction{"OpSubgroupAvcMceGetMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5739u, Instruction{"OpSubgroupAvcMceGetInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5740u, Instruction{"OpSubgroupAvcMceGetBestInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5741u, Instruction{"OpSubgroupAvcMceGetInterMajorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5742u, Instruction{"OpSubgroupAvcMceGetInterMinorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5743u, Instruction{"OpSubgroupAvcMceGetInterDirectionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5744u, Instruction{"OpSubgroupAvcMceGetInterMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5745u, Instruction{"OpSubgroupAvcMceGetInterReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5746u, Instruction{"OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Parameter Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5747u, Instruction{"OpSubgroupAvcImeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Partition Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SAD Adjustment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5748u, Instruction{"OpSubgroupAvcImeSetSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5749u, Instruction{"OpSubgroupAvcImeSetDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'id> Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5750u, Instruction{"OpSubgroupAvcImeRefWindowSizeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Dual Ref'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5751u, Instruction{"OpSubgroupAvcImeAdjustRefOffsetINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Window Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5752u, Instruction{"OpSubgroupAvcImeConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5753u, Instruction{"OpSubgroupAvcImeSetMaxMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Max Motion Vector Count'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5754u, Instruction{"OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5755u, Instruction{"OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Threshold'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5756u, Instruction{"OpSubgroupAvcImeSetWeightedSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Weights'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5757u, Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5758u, Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5759u, Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5760u, Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5761u, Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5762u, Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5763u, Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5764u, Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5765u, Instruction{"OpSubgroupAvcImeConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5766u, Instruction{"OpSubgroupAvcImeGetSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5767u, Instruction{"OpSubgroupAvcImeGetDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5768u, Instruction{"OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5769u, Instruction{"OpSubgroupAvcImeStripDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5770u, Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5771u, Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5772u, Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5773u, Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5774u, Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5775u, Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5776u, Instruction{"OpSubgroupAvcImeGetBorderReachedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Select'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5777u, Instruction{"OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5778u, Instruction{"OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5779u, Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5780u, Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5781u, Instruction{"OpSubgroupAvcFmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shapes'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Minor Shapes'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pixel Resolution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5782u, Instruction{"OpSubgroupAvcBmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shapes'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Minor Shapes'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pixel Resolution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bidirectional Weight'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5783u, Instruction{"OpSubgroupAvcRefConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5784u, Instruction{"OpSubgroupAvcRefSetBidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5785u, Instruction{"OpSubgroupAvcRefSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5786u, Instruction{"OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5787u, Instruction{"OpSubgroupAvcRefEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5788u, Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5789u, Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5790u, Instruction{"OpSubgroupAvcRefConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5791u, Instruction{"OpSubgroupAvcSicInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5792u, Instruction{"OpSubgroupAvcSicConfigureSkcINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Block Partition Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Motion Vector Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Motion Vectors'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bidirectional Weight'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5793u, Instruction{"OpSubgroupAvcSicConfigureIpeLumaINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Intra Partition Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intra Neighbour Availabilty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Luma Pixel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Right Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5794u, Instruction{"OpSubgroupAvcSicConfigureIpeLumaChromaINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Intra Partition Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intra Neighbour Availabilty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Luma Pixel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Right Edge Luma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Left Edge Chroma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Left Corner Chroma Pixel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Upper Edge Chroma Pixels'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sad Adjustment'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5795u, Instruction{"OpSubgroupAvcSicGetMotionVectorMaskINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Block Partition Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5796u, Instruction{"OpSubgroupAvcSicConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5797u, Instruction{"OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5798u, Instruction{"OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Mode Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Packed Neighbor Modes'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Luma Packed Non Dc Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5799u, Instruction{"OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Chroma Mode Base Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5800u, Instruction{"OpSubgroupAvcSicSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5801u, Instruction{"OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Coefficients'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5802u, Instruction{"OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Block Based Skip Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5803u, Instruction{"OpSubgroupAvcSicEvaluateIpeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5804u, Instruction{"OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5805u, Instruction{"OpSubgroupAvcSicEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5806u, Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5807u, Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5808u, Instruction{"OpSubgroupAvcSicConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5809u, Instruction{"OpSubgroupAvcSicGetIpeLumaShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5810u, Instruction{"OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5811u, Instruction{"OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5812u, Instruction{"OpSubgroupAvcSicGetPackedIpeLumaModesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5813u, Instruction{"OpSubgroupAvcSicGetIpeChromaModeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5814u, Instruction{"OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5815u, Instruction{"OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5816u, Instruction{"OpSubgroupAvcSicGetInterRawSadsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5887u, Instruction{"OpLoopControlINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Loop Control Parameters'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::UnstructuredLoopControlsINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_unstructured_loop_controls);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5946u, Instruction{"OpReadPipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5947u, Instruction{"OpWritePipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |5949u, Instruction{"OpFPGARegINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Result'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Input'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FPGARegINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_fpga_reg);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6016u, Instruction{"OpRayQueryGetRayTMinKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6017u, Instruction{"OpRayQueryGetRayFlagsKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6018u, Instruction{"OpRayQueryGetIntersectionTKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6019u, Instruction{"OpRayQueryGetIntersectionInstanceCustomIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6020u, Instruction{"OpRayQueryGetIntersectionInstanceIdKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6021u, Instruction{"OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6022u, Instruction{"OpRayQueryGetIntersectionGeometryIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6023u, Instruction{"OpRayQueryGetIntersectionPrimitiveIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6024u, Instruction{"OpRayQueryGetIntersectionBarycentricsKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6025u, Instruction{"OpRayQueryGetIntersectionFrontFaceKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6026u, Instruction{"OpRayQueryGetIntersectionCandidateAABBOpaqueKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6027u, Instruction{"OpRayQueryGetIntersectionObjectRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6028u, Instruction{"OpRayQueryGetIntersectionObjectRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6029u, Instruction{"OpRayQueryGetWorldRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6030u, Instruction{"OpRayQueryGetWorldRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6031u, Instruction{"OpRayQueryGetIntersectionObjectToWorldKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(0ull << 32u |6032u, Instruction{"OpRayQueryGetIntersectionWorldToObjectKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |1u, Instruction{"Round", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |2u, Instruction{"RoundEven", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |3u, Instruction{"Trunc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |4u, Instruction{"FAbs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |5u, Instruction{"SAbs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |6u, Instruction{"FSign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |7u, Instruction{"SSign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |8u, Instruction{"Floor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |9u, Instruction{"Ceil", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |10u, Instruction{"Fract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |11u, Instruction{"Radians", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |12u, Instruction{"Degrees", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |13u, Instruction{"Sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |14u, Instruction{"Cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |15u, Instruction{"Tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |16u, Instruction{"Asin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |17u, Instruction{"Acos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |18u, Instruction{"Atan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y_over_x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |19u, Instruction{"Sinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |20u, Instruction{"Cosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |21u, Instruction{"Tanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |22u, Instruction{"Asinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |23u, Instruction{"Acosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |24u, Instruction{"Atanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |25u, Instruction{"Atan2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |26u, Instruction{"Pow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |27u, Instruction{"Exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |28u, Instruction{"Log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |29u, Instruction{"Exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |30u, Instruction{"Log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |31u, Instruction{"Sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |32u, Instruction{"InverseSqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |33u, Instruction{"Determinant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |34u, Instruction{"MatrixInverse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |35u, Instruction{"Modf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |36u, Instruction{"ModfStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |37u, Instruction{"FMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |38u, Instruction{"UMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |39u, Instruction{"SMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |40u, Instruction{"FMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |41u, Instruction{"UMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |42u, Instruction{"SMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |43u, Instruction{"FClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |44u, Instruction{"UClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |45u, Instruction{"SClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |46u, Instruction{"FMix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |47u, Instruction{"IMix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |48u, Instruction{"Step", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |49u, Instruction{"SmoothStep", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |50u, Instruction{"Fma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |51u, Instruction{"Frexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |52u, Instruction{"FrexpStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |53u, Instruction{"Ldexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |54u, Instruction{"PackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |55u, Instruction{"PackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |56u, Instruction{"PackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |57u, Instruction{"PackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |58u, Instruction{"PackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |59u, Instruction{"PackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |60u, Instruction{"UnpackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |61u, Instruction{"UnpackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |62u, Instruction{"UnpackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |63u, Instruction{"UnpackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |64u, Instruction{"UnpackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |65u, Instruction{"UnpackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |66u, Instruction{"Length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |67u, Instruction{"Distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |68u, Instruction{"Cross", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |69u, Instruction{"Normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |70u, Instruction{"FaceForward", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Nref'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |71u, Instruction{"Reflect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |72u, Instruction{"Refract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'eta'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |73u, Instruction{"FindILsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |74u, Instruction{"FindSMsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |75u, Instruction{"FindUMsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |76u, Instruction{"InterpolateAtCentroid", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |77u, Instruction{"InterpolateAtSample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'sample'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |78u, Instruction{"InterpolateAtOffset", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |79u, Instruction{"NMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |80u, Instruction{"NMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(1ull << 32u |81u, Instruction{"NClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |0u, Instruction{"acos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |1u, Instruction{"acosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |2u, Instruction{"acospi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |3u, Instruction{"asin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |4u, Instruction{"asinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |5u, Instruction{"asinpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |6u, Instruction{"atan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |7u, Instruction{"atan2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |8u, Instruction{"atanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |9u, Instruction{"atanpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |10u, Instruction{"atan2pi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |11u, Instruction{"cbrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |12u, Instruction{"ceil", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |13u, Instruction{"copysign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |14u, Instruction{"cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |15u, Instruction{"cosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |16u, Instruction{"cospi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |17u, Instruction{"erfc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |18u, Instruction{"erf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |19u, Instruction{"exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |20u, Instruction{"exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |21u, Instruction{"exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |22u, Instruction{"expm1", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |23u, Instruction{"fabs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |24u, Instruction{"fdim", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |25u, Instruction{"floor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |26u, Instruction{"fma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |27u, Instruction{"fmax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |28u, Instruction{"fmin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |29u, Instruction{"fmod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |30u, Instruction{"fract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |31u, Instruction{"frexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |32u, Instruction{"hypot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |33u, Instruction{"ilogb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |34u, Instruction{"ldexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'k'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |35u, Instruction{"lgamma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |36u, Instruction{"lgamma_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'signp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |37u, Instruction{"log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |38u, Instruction{"log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |39u, Instruction{"log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |40u, Instruction{"log1p", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |41u, Instruction{"logb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |42u, Instruction{"mad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |43u, Instruction{"maxmag", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |44u, Instruction{"minmag", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |45u, Instruction{"modf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'iptr'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |46u, Instruction{"nan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'nancode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |47u, Instruction{"nextafter", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |48u, Instruction{"pow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |49u, Instruction{"pown", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |50u, Instruction{"powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |51u, Instruction{"remainder", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |52u, Instruction{"remquo", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'quo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |53u, Instruction{"rint", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |54u, Instruction{"rootn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |55u, Instruction{"round", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |56u, Instruction{"rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |57u, Instruction{"sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |58u, Instruction{"sincos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'cosval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |59u, Instruction{"sinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |60u, Instruction{"sinpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |61u, Instruction{"sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |62u, Instruction{"tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |63u, Instruction{"tanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |64u, Instruction{"tanpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |65u, Instruction{"tgamma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |66u, Instruction{"trunc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |67u, Instruction{"half_cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |68u, Instruction{"half_divide", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |69u, Instruction{"half_exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |70u, Instruction{"half_exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |71u, Instruction{"half_exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |72u, Instruction{"half_log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |73u, Instruction{"half_log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |74u, Instruction{"half_log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |75u, Instruction{"half_powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |76u, Instruction{"half_recip", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |77u, Instruction{"half_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |78u, Instruction{"half_sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |79u, Instruction{"half_sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |80u, Instruction{"half_tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |81u, Instruction{"native_cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |82u, Instruction{"native_divide", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |83u, Instruction{"native_exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |84u, Instruction{"native_exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |85u, Instruction{"native_exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |86u, Instruction{"native_log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |87u, Instruction{"native_log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |88u, Instruction{"native_log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |89u, Instruction{"native_powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |90u, Instruction{"native_recip", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |91u, Instruction{"native_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |92u, Instruction{"native_sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |93u, Instruction{"native_sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |94u, Instruction{"native_tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |141u, Instruction{"s_abs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |142u, Instruction{"s_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |143u, Instruction{"s_add_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |144u, Instruction{"u_add_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |145u, Instruction{"s_hadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |146u, Instruction{"u_hadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |147u, Instruction{"s_rhadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |148u, Instruction{"u_rhadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |149u, Instruction{"s_clamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |150u, Instruction{"u_clamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |151u, Instruction{"clz", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |152u, Instruction{"ctz", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |153u, Instruction{"s_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |154u, Instruction{"u_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |155u, Instruction{"s_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |156u, Instruction{"s_max", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |157u, Instruction{"u_max", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |158u, Instruction{"s_min", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |159u, Instruction{"u_min", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |160u, Instruction{"s_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |161u, Instruction{"rotate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |162u, Instruction{"s_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |163u, Instruction{"u_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |164u, Instruction{"u_upsample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |165u, Instruction{"s_upsample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |166u, Instruction{"popcount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |167u, Instruction{"s_mad24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |168u, Instruction{"u_mad24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |169u, Instruction{"s_mul24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |170u, Instruction{"u_mul24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |201u, Instruction{"u_abs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |202u, Instruction{"u_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |203u, Instruction{"u_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |204u, Instruction{"u_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |95u, Instruction{"fclamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |96u, Instruction{"degrees", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |97u, Instruction{"fmax_common", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |98u, Instruction{"fmin_common", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |99u, Instruction{"mix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |100u, Instruction{"radians", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |101u, Instruction{"step", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |102u, Instruction{"smoothstep", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |103u, Instruction{"sign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |104u, Instruction{"cross", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |105u, Instruction{"distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |106u, Instruction{"length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |107u, Instruction{"normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |108u, Instruction{"fast_distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |109u, Instruction{"fast_length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |110u, Instruction{"fast_normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |186u, Instruction{"bitselect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |187u, Instruction{"select", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |171u, Instruction{"vloadn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |172u, Instruction{"vstoren", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |173u, Instruction{"vload_half", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |174u, Instruction{"vload_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |175u, Instruction{"vstore_half", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |176u, Instruction{"vstore_half_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |177u, Instruction{"vstore_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |178u, Instruction{"vstore_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |179u, Instruction{"vloada_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |180u, Instruction{"vstorea_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |181u, Instruction{"vstorea_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |182u, Instruction{"shuffle", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |183u, Instruction{"shuffle2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |184u, Instruction{"printf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'format'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'additional arguments'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(2ull << 32u |185u, Instruction{"prefetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'num elements'",Quantifier::One);
	}
};
const Grammar::Instruction* Grammar::getInfo(unsigned int _opcode, Extension _extension) const
{
	Hash64 hash = static_cast<Hash64>(_extension) << 32u | _opcode;
	return m_instructions.get(hash);
};
