// Auto generated - do not modify
#include "spvgentwo/Grammar.h"
#include "spvgentwo/Glsl.h"
#include "spvgentwo/OpenCl.h"
using namespace spvgentwo;

Grammar::Grammar(IAllocator* _pAllocator) : m_instructions(_pAllocator, 796), m_operandNames(_pAllocator, 720)
{
	m_instructions.emplaceUnique(Hash64(0u, 0u), Instruction{"OpNop", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 0u), Instruction{"OpUndef", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 0u), Instruction{"OpSourceContinued", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Continued Source'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 0u), Instruction{"OpSource", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::SourceLanguage, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Version'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Source'",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 0u), Instruction{"OpSourceExtension", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Extension'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 0u), Instruction{"OpName", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 0u), Instruction{"OpMemberName", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 0u), Instruction{"OpString", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'String'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 0u), Instruction{"OpLine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'File'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Line'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 0u), Instruction{"OpExtension", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 0u), Instruction{"OpExtInstImport", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 0u), Instruction{"OpExtInst", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Set'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralExtInstInteger, OperandCategory::Literal, "'Instruction'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1', +'Operand 2', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 0u), Instruction{"OpMemoryModel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::AddressingModel, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryModel, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 0u), Instruction{"OpEntryPoint", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::ExecutionModel, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Name'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Interface'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 0u), Instruction{"OpExecutionMode", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 0u), Instruction{"OpCapability", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::Capability, OperandCategory::ValueEnum, "'Capability'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 0u), Instruction{"OpTypeVoid", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 0u), Instruction{"OpTypeBool", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 0u), Instruction{"OpTypeInt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Signedness'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 0u), Instruction{"OpTypeFloat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Width'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 0u), Instruction{"OpTypeVector", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Component Count'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 0u), Instruction{"OpTypeMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Column Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 0u), Instruction{"OpTypeImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 0u), Instruction{"OpTypeSampler", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 0u), Instruction{"OpTypeSampledImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 0u), Instruction{"OpTypeArray", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Length'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 0u), Instruction{"OpTypeRuntimeArray", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 0u), Instruction{"OpTypeStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Member 0 type', +'member 1 type', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 0u), Instruction{"OpTypeOpaque", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "The name of the opaque type.",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 0u), Instruction{"OpTypePointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 0u), Instruction{"OpTypeFunction", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Return Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Parameter 0 Type', +'Parameter 1 Type', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 0u), Instruction{"OpTypeEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 0u), Instruction{"OpTypeDeviceEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 0u), Instruction{"OpTypeReserveId", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 0u), Instruction{"OpTypeQueue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 0u), Instruction{"OpTypePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::AccessQualifier, OperandCategory::ValueEnum, "'Qualifier'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 0u), Instruction{"OpTypeForwardPointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 0u), Instruction{"OpConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 0u), Instruction{"OpConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 0u), Instruction{"OpConstant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 0u), Instruction{"OpConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 0u), Instruction{"OpConstantSampler", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerAddressingMode, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SamplerFilterMode, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::LiteralSampler);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 0u), Instruction{"OpConstantNull", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 0u), Instruction{"OpSpecConstantTrue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 0u), Instruction{"OpSpecConstantFalse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 0u), Instruction{"OpSpecConstant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralContextDependentNumber, OperandCategory::Literal, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 0u), Instruction{"OpSpecConstantComposite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 0u), Instruction{"OpSpecConstantOp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralSpecConstantOpInteger, OperandCategory::Literal, "'Opcode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 0u), Instruction{"OpFunction", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FunctionControl, OperandCategory::BitEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function Type'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 0u), Instruction{"OpFunctionParameter", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	m_instructions.emplaceUnique(Hash64(56u, 0u), Instruction{"OpFunctionEnd", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 0u), Instruction{"OpFunctionCall", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Argument 0', +'Argument 1', +...",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 0u), Instruction{"OpVariable", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Initializer'",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 0u), Instruction{"OpImageTexelPointer", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sample'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 0u), Instruction{"OpLoad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 0u), Instruction{"OpStore", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 0u), Instruction{"OpCopyMemory", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 0u), Instruction{"OpCopyMemorySized", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 0u), Instruction{"OpAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 0u), Instruction{"OpInBoundsAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 0u), Instruction{"OpPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 0u), Instruction{"OpArrayLength", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Array member'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 0u), Instruction{"OpGenericPtrMemSemantics", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 0u), Instruction{"OpInBoundsPtrAccessChain", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Element'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Indexes'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 0u), Instruction{"OpDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 0u), Instruction{"OpMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Structure Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 0u), Instruction{"OpDecorationGroup", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 0u), Instruction{"OpGroupDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Targets'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 0u), Instruction{"OpGroupMemberDecorate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Decoration Group'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefLiteralInteger, OperandCategory::Composite, "'Targets'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 0u), Instruction{"OpVectorExtractDynamic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 0u), Instruction{"OpVectorInsertDynamic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 0u), Instruction{"OpVectorShuffle", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Components'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 0u), Instruction{"OpCompositeConstruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Constituents'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 0u), Instruction{"OpCompositeExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(82u, 0u), Instruction{"OpCompositeInsert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Composite'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Indexes'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(83u, 0u), Instruction{"OpCopyObject", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(84u, 0u), Instruction{"OpTranspose", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(86u, 0u), Instruction{"OpSampledImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(87u, 0u), Instruction{"OpImageSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(88u, 0u), Instruction{"OpImageSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(89u, 0u), Instruction{"OpImageSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(90u, 0u), Instruction{"OpImageSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(91u, 0u), Instruction{"OpImageSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(92u, 0u), Instruction{"OpImageSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(93u, 0u), Instruction{"OpImageSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(94u, 0u), Instruction{"OpImageSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(95u, 0u), Instruction{"OpImageFetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(96u, 0u), Instruction{"OpImageGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(97u, 0u), Instruction{"OpImageDrefGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(98u, 0u), Instruction{"OpImageRead", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(99u, 0u), Instruction{"OpImageWrite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Texel'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(100u, 0u), Instruction{"OpImage", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(101u, 0u), Instruction{"OpImageQueryFormat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(102u, 0u), Instruction{"OpImageQueryOrder", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(103u, 0u), Instruction{"OpImageQuerySizeLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Level of Detail'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(104u, 0u), Instruction{"OpImageQuerySize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(105u, 0u), Instruction{"OpImageQueryLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(106u, 0u), Instruction{"OpImageQueryLevels", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(107u, 0u), Instruction{"OpImageQuerySamples", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
		instr.capabilities.emplace_back(spv::Capability::ImageQuery);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(109u, 0u), Instruction{"OpConvertFToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(110u, 0u), Instruction{"OpConvertFToS", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(111u, 0u), Instruction{"OpConvertSToF", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(112u, 0u), Instruction{"OpConvertUToF", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(113u, 0u), Instruction{"OpUConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(114u, 0u), Instruction{"OpSConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(115u, 0u), Instruction{"OpFConvert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Float Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(116u, 0u), Instruction{"OpQuantizeToF16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(117u, 0u), Instruction{"OpConvertPtrToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(118u, 0u), Instruction{"OpSatConvertSToU", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Signed Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(119u, 0u), Instruction{"OpSatConvertUToS", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Unsigned Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(120u, 0u), Instruction{"OpConvertUToPtr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Integer Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::PhysicalStorageBufferAddresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(121u, 0u), Instruction{"OpPtrCastToGeneric", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(122u, 0u), Instruction{"OpGenericCastToPtr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(123u, 0u), Instruction{"OpGenericCastToPtrExplicit", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::StorageClass, OperandCategory::ValueEnum, "'Storage'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(124u, 0u), Instruction{"OpBitcast", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(126u, 0u), Instruction{"OpSNegate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(127u, 0u), Instruction{"OpFNegate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(128u, 0u), Instruction{"OpIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(129u, 0u), Instruction{"OpFAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(130u, 0u), Instruction{"OpISub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(131u, 0u), Instruction{"OpFSub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(132u, 0u), Instruction{"OpIMul", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(133u, 0u), Instruction{"OpFMul", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(134u, 0u), Instruction{"OpUDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(135u, 0u), Instruction{"OpSDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(136u, 0u), Instruction{"OpFDiv", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(137u, 0u), Instruction{"OpUMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(138u, 0u), Instruction{"OpSRem", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(139u, 0u), Instruction{"OpSMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(140u, 0u), Instruction{"OpFRem", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(141u, 0u), Instruction{"OpFMod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(142u, 0u), Instruction{"OpVectorTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(143u, 0u), Instruction{"OpMatrixTimesScalar", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Scalar'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(144u, 0u), Instruction{"OpVectorTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(145u, 0u), Instruction{"OpMatrixTimesVector", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Matrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(146u, 0u), Instruction{"OpMatrixTimesMatrix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LeftMatrix'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RightMatrix'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(147u, 0u), Instruction{"OpOuterProduct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(148u, 0u), Instruction{"OpDot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(149u, 0u), Instruction{"OpIAddCarry", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(150u, 0u), Instruction{"OpISubBorrow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(151u, 0u), Instruction{"OpUMulExtended", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(152u, 0u), Instruction{"OpSMulExtended", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(154u, 0u), Instruction{"OpAny", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(155u, 0u), Instruction{"OpAll", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Vector'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(156u, 0u), Instruction{"OpIsNan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(157u, 0u), Instruction{"OpIsInf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(158u, 0u), Instruction{"OpIsFinite", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(159u, 0u), Instruction{"OpIsNormal", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(160u, 0u), Instruction{"OpSignBitSet", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(161u, 0u), Instruction{"OpLessOrGreater", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(162u, 0u), Instruction{"OpOrdered", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(163u, 0u), Instruction{"OpUnordered", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(164u, 0u), Instruction{"OpLogicalEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(165u, 0u), Instruction{"OpLogicalNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(166u, 0u), Instruction{"OpLogicalOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(167u, 0u), Instruction{"OpLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(168u, 0u), Instruction{"OpLogicalNot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(169u, 0u), Instruction{"OpSelect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(170u, 0u), Instruction{"OpIEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(171u, 0u), Instruction{"OpINotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(172u, 0u), Instruction{"OpUGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(173u, 0u), Instruction{"OpSGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(174u, 0u), Instruction{"OpUGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(175u, 0u), Instruction{"OpSGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(176u, 0u), Instruction{"OpULessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(177u, 0u), Instruction{"OpSLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(178u, 0u), Instruction{"OpULessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(179u, 0u), Instruction{"OpSLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(180u, 0u), Instruction{"OpFOrdEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(181u, 0u), Instruction{"OpFUnordEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(182u, 0u), Instruction{"OpFOrdNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(183u, 0u), Instruction{"OpFUnordNotEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(184u, 0u), Instruction{"OpFOrdLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(185u, 0u), Instruction{"OpFUnordLessThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(186u, 0u), Instruction{"OpFOrdGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(187u, 0u), Instruction{"OpFUnordGreaterThan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(188u, 0u), Instruction{"OpFOrdLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(189u, 0u), Instruction{"OpFUnordLessThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(190u, 0u), Instruction{"OpFOrdGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(191u, 0u), Instruction{"OpFUnordGreaterThanEqual", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(194u, 0u), Instruction{"OpShiftRightLogical", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(195u, 0u), Instruction{"OpShiftRightArithmetic", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(196u, 0u), Instruction{"OpShiftLeftLogical", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Shift'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(197u, 0u), Instruction{"OpBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(198u, 0u), Instruction{"OpBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(199u, 0u), Instruction{"OpBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(200u, 0u), Instruction{"OpNot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(201u, 0u), Instruction{"OpBitFieldInsert", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Insert'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(202u, 0u), Instruction{"OpBitFieldSExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(203u, 0u), Instruction{"OpBitFieldUExtract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(204u, 0u), Instruction{"OpBitReverse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(205u, 0u), Instruction{"OpBitCount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Base'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(207u, 0u), Instruction{"OpDPdx", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(208u, 0u), Instruction{"OpDPdy", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(209u, 0u), Instruction{"OpFwidth", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(210u, 0u), Instruction{"OpDPdxFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(211u, 0u), Instruction{"OpDPdyFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(212u, 0u), Instruction{"OpFwidthFine", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(213u, 0u), Instruction{"OpDPdxCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(214u, 0u), Instruction{"OpDPdyCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(215u, 0u), Instruction{"OpFwidthCoarse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'P'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DerivativeControl);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(218u, 0u), Instruction{"OpEmitVertex", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(219u, 0u), Instruction{"OpEndPrimitive", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Geometry);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(220u, 0u), Instruction{"OpEmitStreamVertex", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(221u, 0u), Instruction{"OpEndStreamPrimitive", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stream'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GeometryStreams);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(224u, 0u), Instruction{"OpControlBarrier", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(225u, 0u), Instruction{"OpMemoryBarrier", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(227u, 0u), Instruction{"OpAtomicLoad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(228u, 0u), Instruction{"OpAtomicStore", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(229u, 0u), Instruction{"OpAtomicExchange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(230u, 0u), Instruction{"OpAtomicCompareExchange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(231u, 0u), Instruction{"OpAtomicCompareExchangeWeak", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(232u, 0u), Instruction{"OpAtomicIIncrement", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(233u, 0u), Instruction{"OpAtomicIDecrement", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(234u, 0u), Instruction{"OpAtomicIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(235u, 0u), Instruction{"OpAtomicISub", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(236u, 0u), Instruction{"OpAtomicSMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(237u, 0u), Instruction{"OpAtomicUMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(238u, 0u), Instruction{"OpAtomicSMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(239u, 0u), Instruction{"OpAtomicUMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(240u, 0u), Instruction{"OpAtomicAnd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(241u, 0u), Instruction{"OpAtomicOr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(242u, 0u), Instruction{"OpAtomicXor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(245u, 0u), Instruction{"OpPhi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairIdRefIdRef, OperandCategory::Composite, "'Variable, Parent, ...'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(246u, 0u), Instruction{"OpLoopMerge", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Continue Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LoopControl, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(247u, 0u), Instruction{"OpSelectionMerge", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Merge Block'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::SelectionControl, OperandCategory::BitEnum, "",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(248u, 0u), Instruction{"OpLabel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(249u, 0u), Instruction{"OpBranch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target Label'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(250u, 0u), Instruction{"OpBranchConditional", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Condition'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'True Label'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'False Label'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Branch weights'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(251u, 0u), Instruction{"OpSwitch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Selector'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Default'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::PairLiteralIntegerIdRef, OperandCategory::Composite, "'Target'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(252u, 0u), Instruction{"OpKill", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::Shader);
	}
	m_instructions.emplaceUnique(Hash64(253u, 0u), Instruction{"OpReturn", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(254u, 0u), Instruction{"OpReturnValue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	m_instructions.emplaceUnique(Hash64(255u, 0u), Instruction{"OpUnreachable", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(256u, 0u), Instruction{"OpLifetimeStart", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(257u, 0u), Instruction{"OpLifetimeStop", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(259u, 0u), Instruction{"OpGroupAsyncCopy", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(260u, 0u), Instruction{"OpGroupWaitEvents", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Events List'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(261u, 0u), Instruction{"OpGroupAll", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(262u, 0u), Instruction{"OpGroupAny", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(263u, 0u), Instruction{"OpGroupBroadcast", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(264u, 0u), Instruction{"OpGroupIAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(265u, 0u), Instruction{"OpGroupFAdd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(266u, 0u), Instruction{"OpGroupFMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(267u, 0u), Instruction{"OpGroupUMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(268u, 0u), Instruction{"OpGroupSMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(269u, 0u), Instruction{"OpGroupFMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(270u, 0u), Instruction{"OpGroupUMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(271u, 0u), Instruction{"OpGroupSMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(274u, 0u), Instruction{"OpReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(275u, 0u), Instruction{"OpWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(276u, 0u), Instruction{"OpReservedReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(277u, 0u), Instruction{"OpReservedWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(278u, 0u), Instruction{"OpReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(279u, 0u), Instruction{"OpReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Packets'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(280u, 0u), Instruction{"OpCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(281u, 0u), Instruction{"OpCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(282u, 0u), Instruction{"OpIsValidReserveId", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(283u, 0u), Instruction{"OpGetNumPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(284u, 0u), Instruction{"OpGetMaxPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(285u, 0u), Instruction{"OpGroupReserveReadPipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(286u, 0u), Instruction{"OpGroupReserveWritePipePackets", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(287u, 0u), Instruction{"OpGroupCommitReadPipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(288u, 0u), Instruction{"OpGroupCommitWritePipe", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reserve Id'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(291u, 0u), Instruction{"OpEnqueueMarker", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Queue'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Num Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Wait Events'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ret Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(292u, 0u), Instruction{"OpEnqueueKernel", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(293u, 0u), Instruction{"OpGetKernelNDrangeSubGroupCount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(294u, 0u), Instruction{"OpGetKernelNDrangeMaxSubGroupSize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(295u, 0u), Instruction{"OpGetKernelWorkGroupSize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(296u, 0u), Instruction{"OpGetKernelPreferredWorkGroupSizeMultiple", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(297u, 0u), Instruction{"OpRetainEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(298u, 0u), Instruction{"OpReleaseEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(299u, 0u), Instruction{"OpCreateUserEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(300u, 0u), Instruction{"OpIsValidEvent", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(301u, 0u), Instruction{"OpSetUserEventStatus", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Status'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(302u, 0u), Instruction{"OpCaptureEventProfilingInfo", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Event'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Profiling Info'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(303u, 0u), Instruction{"OpGetDefaultQueue", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(304u, 0u), Instruction{"OpBuildNDRange", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkSize'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'LocalWorkSize'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'GlobalWorkOffset'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DeviceEnqueue);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(305u, 0u), Instruction{"OpImageSparseSampleImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(306u, 0u), Instruction{"OpImageSparseSampleExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(307u, 0u), Instruction{"OpImageSparseSampleDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(308u, 0u), Instruction{"OpImageSparseSampleDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(309u, 0u), Instruction{"OpImageSparseSampleProjImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(310u, 0u), Instruction{"OpImageSparseSampleProjExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(311u, 0u), Instruction{"OpImageSparseSampleProjDrefImplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(312u, 0u), Instruction{"OpImageSparseSampleProjDrefExplicitLod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(313u, 0u), Instruction{"OpImageSparseFetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(314u, 0u), Instruction{"OpImageSparseGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(315u, 0u), Instruction{"OpImageSparseDrefGather", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampled Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'D~ref~'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(316u, 0u), Instruction{"OpImageSparseTexelsResident", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Resident Code'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	m_instructions.emplaceUnique(Hash64(317u, 0u), Instruction{"OpNoLine", _pAllocator, _pAllocator, _pAllocator, 0});
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(318u, 0u), Instruction{"OpAtomicFlagTestAndSet", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(319u, 0u), Instruction{"OpAtomicFlagClear", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Kernel);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(320u, 0u), Instruction{"OpImageSparseRead", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ImageOperands, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::SparseResidency);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(321u, 0u), Instruction{"OpSizeOf", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(322u, 0u), Instruction{"OpTypePipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(323u, 0u), Instruction{"OpConstantPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Packet Alignment'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Capacity'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(324u, 0u), Instruction{"OpCreatePipeFromPipeStorage", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pipe Storage'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::PipeStorage);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(325u, 0u), Instruction{"OpGetKernelLocalSizeForSubgroupCount", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(326u, 0u), Instruction{"OpGetKernelMaxNumSubgroups", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Invoke'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Param Align'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupDispatch);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(327u, 0u), Instruction{"OpTypeNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(328u, 0u), Instruction{"OpNamedBarrierInitialize", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Subgroup Count'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(329u, 0u), Instruction{"OpMemoryNamedBarrier", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Named Barrier'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Memory'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdMemorySemantics, OperandCategory::Id, "'Semantics'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::NamedBarrier);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(330u, 0u), Instruction{"OpModuleProcessed", _pAllocator, _pAllocator, _pAllocator, 65792}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralString, OperandCategory::Literal, "'Process'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(331u, 0u), Instruction{"OpExecutionModeId", _pAllocator, _pAllocator, _pAllocator, 66048}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Entry Point'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::ExecutionMode, OperandCategory::ValueEnum, "'Mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(332u, 0u), Instruction{"OpDecorateId", _pAllocator, _pAllocator, _pAllocator, 66048}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(333u, 0u), Instruction{"OpGroupNonUniformElect", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniform);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(334u, 0u), Instruction{"OpGroupNonUniformAll", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(335u, 0u), Instruction{"OpGroupNonUniformAny", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(336u, 0u), Instruction{"OpGroupNonUniformAllEqual", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformVote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(337u, 0u), Instruction{"OpGroupNonUniformBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(338u, 0u), Instruction{"OpGroupNonUniformBroadcastFirst", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(339u, 0u), Instruction{"OpGroupNonUniformBallot", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(340u, 0u), Instruction{"OpGroupNonUniformInverseBallot", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(341u, 0u), Instruction{"OpGroupNonUniformBallotBitExtract", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(342u, 0u), Instruction{"OpGroupNonUniformBallotBitCount", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(343u, 0u), Instruction{"OpGroupNonUniformBallotFindLSB", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(344u, 0u), Instruction{"OpGroupNonUniformBallotFindMSB", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformBallot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(345u, 0u), Instruction{"OpGroupNonUniformShuffle", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Id'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(346u, 0u), Instruction{"OpGroupNonUniformShuffleXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Mask'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffle);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(347u, 0u), Instruction{"OpGroupNonUniformShuffleUp", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(348u, 0u), Instruction{"OpGroupNonUniformShuffleDown", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformShuffleRelative);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(349u, 0u), Instruction{"OpGroupNonUniformIAdd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(350u, 0u), Instruction{"OpGroupNonUniformFAdd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(351u, 0u), Instruction{"OpGroupNonUniformIMul", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(352u, 0u), Instruction{"OpGroupNonUniformFMul", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(353u, 0u), Instruction{"OpGroupNonUniformSMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(354u, 0u), Instruction{"OpGroupNonUniformUMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(355u, 0u), Instruction{"OpGroupNonUniformFMin", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(356u, 0u), Instruction{"OpGroupNonUniformSMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(357u, 0u), Instruction{"OpGroupNonUniformUMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(358u, 0u), Instruction{"OpGroupNonUniformFMax", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(359u, 0u), Instruction{"OpGroupNonUniformBitwiseAnd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(360u, 0u), Instruction{"OpGroupNonUniformBitwiseOr", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(361u, 0u), Instruction{"OpGroupNonUniformBitwiseXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(362u, 0u), Instruction{"OpGroupNonUniformLogicalAnd", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(363u, 0u), Instruction{"OpGroupNonUniformLogicalOr", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(364u, 0u), Instruction{"OpGroupNonUniformLogicalXor", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(365u, 0u), Instruction{"OpGroupNonUniformQuadBroadcast", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(366u, 0u), Instruction{"OpGroupNonUniformQuadSwap", _pAllocator, _pAllocator, _pAllocator, 66304}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformQuad);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(400u, 0u), Instruction{"OpCopyLogical", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(401u, 0u), Instruction{"OpPtrEqual", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(402u, 0u), Instruction{"OpPtrNotEqual", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(403u, 0u), Instruction{"OpPtrDiff", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Addresses);
		instr.capabilities.emplace_back(spv::Capability::VariablePointers);
		instr.capabilities.emplace_back(spv::Capability::VariablePointersStorageBuffer);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4421u, 0u), Instruction{"OpSubgroupBallotKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4422u, 0u), Instruction{"OpSubgroupFirstInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4428u, 0u), Instruction{"OpSubgroupAllKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4429u, 0u), Instruction{"OpSubgroupAnyKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4430u, 0u), Instruction{"OpSubgroupAllEqualKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Predicate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupVoteKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_subgroup_vote);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4432u, 0u), Instruction{"OpSubgroupReadInvocationKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBallotKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4472u, 0u), Instruction{"OpTypeRayQueryProvisionalKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4473u, 0u), Instruction{"OpRayQueryInitializeKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(4474u, 0u), Instruction{"OpRayQueryTerminateKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4475u, 0u), Instruction{"OpRayQueryGenerateIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'HitT'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4476u, 0u), Instruction{"OpRayQueryConfirmIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4477u, 0u), Instruction{"OpRayQueryProceedKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4479u, 0u), Instruction{"OpRayQueryGetIntersectionTypeKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5000u, 0u), Instruction{"OpGroupIAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5001u, 0u), Instruction{"OpGroupFAddNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5002u, 0u), Instruction{"OpGroupFMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5003u, 0u), Instruction{"OpGroupUMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5004u, 0u), Instruction{"OpGroupSMinNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5005u, 0u), Instruction{"OpGroupFMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5006u, 0u), Instruction{"OpGroupUMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5007u, 0u), Instruction{"OpGroupSMaxNonUniformAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::GroupOperation, OperandCategory::ValueEnum, "'Operation'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'X'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Groups);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_ballot);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5011u, 0u), Instruction{"OpFragmentMaskFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5012u, 0u), Instruction{"OpFragmentFetchAMD", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fragment Index'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FragmentMaskAMD);
		instr.extensions.emplace_back(spv::Extension::SPV_AMD_shader_fragment_mask);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5056u, 0u), Instruction{"OpReadClockKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::ShaderClockKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_shader_clock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5283u, 0u), Instruction{"OpImageSampleFootprintNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5296u, 0u), Instruction{"OpGroupNonUniformPartitionNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::GroupNonUniformPartitionedNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_shader_subgroup_partitioned);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5299u, 0u), Instruction{"OpWritePackedPrimitiveIndices4x8NV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Index Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Indices'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::MeshShadingNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_mesh_shader);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5334u, 0u), Instruction{"OpReportIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5335u, 0u), Instruction{"OpIgnoreIntersectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5336u, 0u), Instruction{"OpTerminateRayKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5337u, 0u), Instruction{"OpTraceRayKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5341u, 0u), Instruction{"OpTypeAccelerationStructureKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5344u, 0u), Instruction{"OpExecuteCallableKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SBT Index'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Callable DataId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayTracingNV);
		instr.capabilities.emplace_back(spv::Capability::RayTracingProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_ray_tracing);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_tracing);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5358u, 0u), Instruction{"OpTypeCooperativeMatrixNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Component Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdScope, OperandCategory::Id, "'Execution'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Rows'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Columns'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5359u, 0u), Instruction{"OpCooperativeMatrixLoadNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5360u, 0u), Instruction{"OpCooperativeMatrixStoreNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Pointer'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Object'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Stride'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Column Major'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::MemoryAccess, OperandCategory::BitEnum, "",Quantifier::ZeroOrOne);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5361u, 0u), Instruction{"OpCooperativeMatrixMulAddNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'A'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'B'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'C'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5362u, 0u), Instruction{"OpCooperativeMatrixLengthNV", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::CooperativeMatrixNV);
		instr.extensions.emplace_back(spv::Extension::SPV_NV_cooperative_matrix);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5364u, 0u), Instruction{"OpBeginInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5365u, 0u), Instruction{"OpEndInvocationInterlockEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderSampleInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderPixelInterlockEXT);
		instr.capabilities.emplace_back(spv::Capability::FragmentShaderShadingRateInterlockEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_fragment_shader_interlock);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5380u, 0u), Instruction{"OpDemoteToHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5381u, 0u), Instruction{"OpIsHelperInvocationEXT", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::DemoteToHelperInvocationEXT);
		instr.extensions.emplace_back(spv::Extension::SPV_EXT_demote_to_helper_invocation);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5571u, 0u), Instruction{"OpSubgroupShuffleINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'InvocationId'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5572u, 0u), Instruction{"OpSubgroupShuffleDownINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Next'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5573u, 0u), Instruction{"OpSubgroupShuffleUpINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Previous'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Current'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Delta'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5574u, 0u), Instruction{"OpSubgroupShuffleXorINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupShuffleINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5575u, 0u), Instruction{"OpSubgroupBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5576u, 0u), Instruction{"OpSubgroupBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ptr'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupBufferBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5577u, 0u), Instruction{"OpSubgroupImageBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5578u, 0u), Instruction{"OpSubgroupImageBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5580u, 0u), Instruction{"OpSubgroupImageMediaBlockReadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5581u, 0u), Instruction{"OpSubgroupImageMediaBlockWriteINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Coordinate'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Width'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Height'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Data'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupImageMediaBlockIOINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5585u, 0u), Instruction{"OpUCountLeadingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5586u, 0u), Instruction{"OpUCountTrailingZerosINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5587u, 0u), Instruction{"OpAbsISubINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5588u, 0u), Instruction{"OpAbsUSubINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5589u, 0u), Instruction{"OpIAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5590u, 0u), Instruction{"OpUAddSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5591u, 0u), Instruction{"OpIAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5592u, 0u), Instruction{"OpUAverageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5593u, 0u), Instruction{"OpIAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5594u, 0u), Instruction{"OpUAverageRoundedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5595u, 0u), Instruction{"OpISubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5596u, 0u), Instruction{"OpUSubSatINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5597u, 0u), Instruction{"OpIMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5598u, 0u), Instruction{"OpUMul32x16INTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 2'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::IntegerFunctions2INTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5600u, 0u), Instruction{"OpFunctionPointerINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Function'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5601u, 0u), Instruction{"OpFunctionPointerCallINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Operand 1'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::FunctionPointersINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_function_pointers);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5632u, 0u), Instruction{"OpDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Target'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5633u, 0u), Instruction{"OpMemberDecorateString", _pAllocator, _pAllocator, _pAllocator, 66560}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Struct Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Member'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::Decoration, OperandCategory::ValueEnum, "",Quantifier::One);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_decorate_string);
		instr.extensions.emplace_back(spv::Extension::SPV_GOOGLE_hlsl_functionality1);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5699u, 0u), Instruction{"OpVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Sampler'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5700u, 0u), Instruction{"OpTypeVmeImageINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Type'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5701u, 0u), Instruction{"OpTypeAvcImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5702u, 0u), Instruction{"OpTypeAvcRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5703u, 0u), Instruction{"OpTypeAvcSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5704u, 0u), Instruction{"OpTypeAvcMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5705u, 0u), Instruction{"OpTypeAvcMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5706u, 0u), Instruction{"OpTypeAvcImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5707u, 0u), Instruction{"OpTypeAvcImeResultSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5708u, 0u), Instruction{"OpTypeAvcImeResultDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5709u, 0u), Instruction{"OpTypeAvcImeSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5710u, 0u), Instruction{"OpTypeAvcImeDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5711u, 0u), Instruction{"OpTypeAvcRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5712u, 0u), Instruction{"OpTypeAvcSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5713u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5714u, 0u), Instruction{"OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Base Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5715u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5716u, 0u), Instruction{"OpSubgroupAvcMceSetInterShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5717u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5718u, 0u), Instruction{"OpSubgroupAvcMceSetInterDirectionPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction Cost'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5719u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5720u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5721u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5722u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5723u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5724u, 0u), Instruction{"OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Center Delta'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Cost Table'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Cost Precision'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5725u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Slice Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Qp'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5726u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5727u, 0u), Instruction{"OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5728u, 0u), Instruction{"OpSubgroupAvcMceSetAcOnlyHaarINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5729u, 0u), Instruction{"OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Source Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5730u, 0u), Instruction{"OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5731u, 0u), Instruction{"OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Forward Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Backward Reference Field Polarity'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5732u, 0u), Instruction{"OpSubgroupAvcMceConvertToImePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5733u, 0u), Instruction{"OpSubgroupAvcMceConvertToImeResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5734u, 0u), Instruction{"OpSubgroupAvcMceConvertToRefPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5735u, 0u), Instruction{"OpSubgroupAvcMceConvertToRefResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5736u, 0u), Instruction{"OpSubgroupAvcMceConvertToSicPayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5737u, 0u), Instruction{"OpSubgroupAvcMceConvertToSicResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5738u, 0u), Instruction{"OpSubgroupAvcMceGetMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5739u, 0u), Instruction{"OpSubgroupAvcMceGetInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5740u, 0u), Instruction{"OpSubgroupAvcMceGetBestInterDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5741u, 0u), Instruction{"OpSubgroupAvcMceGetInterMajorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5742u, 0u), Instruction{"OpSubgroupAvcMceGetInterMinorShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5743u, 0u), Instruction{"OpSubgroupAvcMceGetInterDirectionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5744u, 0u), Instruction{"OpSubgroupAvcMceGetInterMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5745u, 0u), Instruction{"OpSubgroupAvcMceGetInterReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5746u, 0u), Instruction{"OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Parameter Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5747u, 0u), Instruction{"OpSubgroupAvcImeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Partition Mask'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'SAD Adjustment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5748u, 0u), Instruction{"OpSubgroupAvcImeSetSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5749u, 0u), Instruction{"OpSubgroupAvcImeSetDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'id> Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5750u, 0u), Instruction{"OpSubgroupAvcImeRefWindowSizeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Search Window Config'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Dual Ref'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5751u, 0u), Instruction{"OpSubgroupAvcImeAdjustRefOffsetINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Window Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Size'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5752u, 0u), Instruction{"OpSubgroupAvcImeConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5753u, 0u), Instruction{"OpSubgroupAvcImeSetMaxMotionVectorCountINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Max Motion Vector Count'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5754u, 0u), Instruction{"OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5755u, 0u), Instruction{"OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Threshold'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5756u, 0u), Instruction{"OpSubgroupAvcImeSetWeightedSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Weights'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5757u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5758u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5759u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5760u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5761u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5762u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5763u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Streamin Components'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5764u, 0u), Instruction{"OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5765u, 0u), Instruction{"OpSubgroupAvcImeConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5766u, 0u), Instruction{"OpSubgroupAvcImeGetSingleReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5767u, 0u), Instruction{"OpSubgroupAvcImeGetDualReferenceStreaminINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5768u, 0u), Instruction{"OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5769u, 0u), Instruction{"OpSubgroupAvcImeStripDualReferenceStreamoutINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5770u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5771u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5772u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5773u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5774u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5775u, 0u), Instruction{"OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Major Shape'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5776u, 0u), Instruction{"OpSubgroupAvcImeGetBorderReachedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Image Select'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5777u, 0u), Instruction{"OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5778u, 0u), Instruction{"OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5779u, 0u), Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5780u, 0u), Instruction{"OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5781u, 0u), Instruction{"OpSubgroupAvcFmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5782u, 0u), Instruction{"OpSubgroupAvcBmeInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5783u, 0u), Instruction{"OpSubgroupAvcRefConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5784u, 0u), Instruction{"OpSubgroupAvcRefSetBidirectionalMixDisableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5785u, 0u), Instruction{"OpSubgroupAvcRefSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5786u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5787u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5788u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5789u, 0u), Instruction{"OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5790u, 0u), Instruction{"OpSubgroupAvcRefConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5791u, 0u), Instruction{"OpSubgroupAvcSicInitializeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Coord'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5792u, 0u), Instruction{"OpSubgroupAvcSicConfigureSkcINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5793u, 0u), Instruction{"OpSubgroupAvcSicConfigureIpeLumaINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5794u, 0u), Instruction{"OpSubgroupAvcSicConfigureIpeLumaChromaINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5795u, 0u), Instruction{"OpSubgroupAvcSicGetMotionVectorMaskINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Skip Block Partition Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Direction'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5796u, 0u), Instruction{"OpSubgroupAvcSicConvertToMcePayloadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5797u, 0u), Instruction{"OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Shape Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5798u, 0u), Instruction{"OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
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
		auto& instr = m_instructions.emplaceUnique(Hash64(5799u, 0u), Instruction{"OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Chroma Mode Base Penalty'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5800u, 0u), Instruction{"OpSubgroupAvcSicSetBilinearFilterEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5801u, 0u), Instruction{"OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Sad Coefficients'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5802u, 0u), Instruction{"OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Block Based Skip Type'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5803u, 0u), Instruction{"OpSubgroupAvcSicEvaluateIpeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5804u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5805u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithDualReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Fwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Bwd Ref Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5806u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5807u, 0u), Instruction{"OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Src Image'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Ids'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packed Reference Field Polarities'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5808u, 0u), Instruction{"OpSubgroupAvcSicConvertToMceResultINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5809u, 0u), Instruction{"OpSubgroupAvcSicGetIpeLumaShapeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5810u, 0u), Instruction{"OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5811u, 0u), Instruction{"OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5812u, 0u), Instruction{"OpSubgroupAvcSicGetPackedIpeLumaModesINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5813u, 0u), Instruction{"OpSubgroupAvcSicGetIpeChromaModeINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationChromaINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5814u, 0u), Instruction{"OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5815u, 0u), Instruction{"OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationIntraINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5816u, 0u), Instruction{"OpSubgroupAvcSicGetInterRawSadsINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Payload'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::SubgroupAvcMotionEstimationINTEL);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5887u, 0u), Instruction{"OpLoopControlINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'Loop Control Parameters'",Quantifier::ZeroOrAny);
		instr.capabilities.emplace_back(spv::Capability::UnstructuredLoopControlsINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_unstructured_loop_controls);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5946u, 0u), Instruction{"OpReadPipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5947u, 0u), Instruction{"OpWritePipeBlockingINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Size'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Packet Alignment'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::BlockingPipesINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_blocking_pipes);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5949u, 0u), Instruction{"OpFPGARegINTEL", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Result'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Input'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::FPGARegINTEL);
		instr.extensions.emplace_back(spv::Extension::SPV_INTEL_fpga_reg);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6016u, 0u), Instruction{"OpRayQueryGetRayTMinKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6017u, 0u), Instruction{"OpRayQueryGetRayFlagsKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6018u, 0u), Instruction{"OpRayQueryGetIntersectionTKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6019u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceCustomIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6020u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceIdKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6021u, 0u), Instruction{"OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6022u, 0u), Instruction{"OpRayQueryGetIntersectionGeometryIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6023u, 0u), Instruction{"OpRayQueryGetIntersectionPrimitiveIndexKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6024u, 0u), Instruction{"OpRayQueryGetIntersectionBarycentricsKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6025u, 0u), Instruction{"OpRayQueryGetIntersectionFrontFaceKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6026u, 0u), Instruction{"OpRayQueryGetIntersectionCandidateAABBOpaqueKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6027u, 0u), Instruction{"OpRayQueryGetIntersectionObjectRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6028u, 0u), Instruction{"OpRayQueryGetIntersectionObjectRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6029u, 0u), Instruction{"OpRayQueryGetWorldRayDirectionKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6030u, 0u), Instruction{"OpRayQueryGetWorldRayOriginKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6031u, 0u), Instruction{"OpRayQueryGetIntersectionObjectToWorldKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6032u, 0u), Instruction{"OpRayQueryGetIntersectionWorldToObjectKHR", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdResultType, OperandCategory::Id, "ResultType",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdResult, OperandCategory::Id, "Result",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'RayQuery'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Intersection'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::RayQueryProvisionalKHR);
		instr.extensions.emplace_back(spv::Extension::SPV_KHR_ray_query);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 1u), Instruction{"Round", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 1u), Instruction{"RoundEven", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 1u), Instruction{"Trunc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 1u), Instruction{"FAbs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 1u), Instruction{"SAbs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 1u), Instruction{"FSign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 1u), Instruction{"SSign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 1u), Instruction{"Floor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(9u, 1u), Instruction{"Ceil", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 1u), Instruction{"Fract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 1u), Instruction{"Radians", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 1u), Instruction{"Degrees", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(13u, 1u), Instruction{"Sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 1u), Instruction{"Cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 1u), Instruction{"Tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 1u), Instruction{"Asin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 1u), Instruction{"Acos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(18u, 1u), Instruction{"Atan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y_over_x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 1u), Instruction{"Sinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 1u), Instruction{"Cosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 1u), Instruction{"Tanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 1u), Instruction{"Asinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 1u), Instruction{"Acosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 1u), Instruction{"Atanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 1u), Instruction{"Atan2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 1u), Instruction{"Pow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 1u), Instruction{"Exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 1u), Instruction{"Log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 1u), Instruction{"Exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 1u), Instruction{"Log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 1u), Instruction{"Sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 1u), Instruction{"InverseSqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 1u), Instruction{"Determinant", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 1u), Instruction{"MatrixInverse", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 1u), Instruction{"Modf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 1u), Instruction{"ModfStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 1u), Instruction{"FMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 1u), Instruction{"UMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 1u), Instruction{"SMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(40u, 1u), Instruction{"FMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 1u), Instruction{"UMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 1u), Instruction{"SMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 1u), Instruction{"FClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 1u), Instruction{"UClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 1u), Instruction{"SClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 1u), Instruction{"FMix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(47u, 1u), Instruction{"IMix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 1u), Instruction{"Step", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 1u), Instruction{"SmoothStep", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 1u), Instruction{"Fma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 1u), Instruction{"Frexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 1u), Instruction{"FrexpStruct", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(53u, 1u), Instruction{"Ldexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 1u), Instruction{"PackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 1u), Instruction{"PackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(56u, 1u), Instruction{"PackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 1u), Instruction{"PackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(58u, 1u), Instruction{"PackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 1u), Instruction{"PackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 1u), Instruction{"UnpackSnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 1u), Instruction{"UnpackUnorm2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 1u), Instruction{"UnpackHalf2x16", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 1u), Instruction{"UnpackSnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 1u), Instruction{"UnpackUnorm4x8", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 1u), Instruction{"UnpackDouble2x32", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::Float64);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 1u), Instruction{"Length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 1u), Instruction{"Distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 1u), Instruction{"Cross", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 1u), Instruction{"Normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 1u), Instruction{"FaceForward", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Nref'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 1u), Instruction{"Reflect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 1u), Instruction{"Refract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'I'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'N'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'eta'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 1u), Instruction{"FindILsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 1u), Instruction{"FindSMsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 1u), Instruction{"FindUMsb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'Value'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(76u, 1u), Instruction{"InterpolateAtCentroid", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 1u), Instruction{"InterpolateAtSample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'sample'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 1u), Instruction{"InterpolateAtOffset", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'interpolant'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.capabilities.emplace_back(spv::Capability::InterpolationFunction);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 1u), Instruction{"NMin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 1u), Instruction{"NMax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 1u), Instruction{"NClamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minVal'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxVal'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(0u, 2u), Instruction{"acos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(1u, 2u), Instruction{"acosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(2u, 2u), Instruction{"acospi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(3u, 2u), Instruction{"asin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(4u, 2u), Instruction{"asinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(5u, 2u), Instruction{"asinpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(6u, 2u), Instruction{"atan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(7u, 2u), Instruction{"atan2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(8u, 2u), Instruction{"atanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(9u, 2u), Instruction{"atanpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(10u, 2u), Instruction{"atan2pi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(11u, 2u), Instruction{"cbrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(12u, 2u), Instruction{"ceil", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(13u, 2u), Instruction{"copysign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(14u, 2u), Instruction{"cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(15u, 2u), Instruction{"cosh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(16u, 2u), Instruction{"cospi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(17u, 2u), Instruction{"erfc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(18u, 2u), Instruction{"erf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(19u, 2u), Instruction{"exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(20u, 2u), Instruction{"exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(21u, 2u), Instruction{"exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(22u, 2u), Instruction{"expm1", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(23u, 2u), Instruction{"fabs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(24u, 2u), Instruction{"fdim", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(25u, 2u), Instruction{"floor", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(26u, 2u), Instruction{"fma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(27u, 2u), Instruction{"fmax", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(28u, 2u), Instruction{"fmin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(29u, 2u), Instruction{"fmod", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(30u, 2u), Instruction{"fract", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(31u, 2u), Instruction{"frexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'exp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(32u, 2u), Instruction{"hypot", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(33u, 2u), Instruction{"ilogb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(34u, 2u), Instruction{"ldexp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'k'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(35u, 2u), Instruction{"lgamma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(36u, 2u), Instruction{"lgamma_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'signp'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(37u, 2u), Instruction{"log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(38u, 2u), Instruction{"log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(39u, 2u), Instruction{"log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(40u, 2u), Instruction{"log1p", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(41u, 2u), Instruction{"logb", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(42u, 2u), Instruction{"mad", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(43u, 2u), Instruction{"maxmag", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(44u, 2u), Instruction{"minmag", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(45u, 2u), Instruction{"modf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'iptr'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(46u, 2u), Instruction{"nan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'nancode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(47u, 2u), Instruction{"nextafter", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(48u, 2u), Instruction{"pow", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(49u, 2u), Instruction{"pown", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(50u, 2u), Instruction{"powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(51u, 2u), Instruction{"remainder", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(52u, 2u), Instruction{"remquo", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'quo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(53u, 2u), Instruction{"rint", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(54u, 2u), Instruction{"rootn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(55u, 2u), Instruction{"round", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(56u, 2u), Instruction{"rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(57u, 2u), Instruction{"sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(58u, 2u), Instruction{"sincos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'cosval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(59u, 2u), Instruction{"sinh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(60u, 2u), Instruction{"sinpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(61u, 2u), Instruction{"sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(62u, 2u), Instruction{"tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(63u, 2u), Instruction{"tanh", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(64u, 2u), Instruction{"tanpi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(65u, 2u), Instruction{"tgamma", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(66u, 2u), Instruction{"trunc", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(67u, 2u), Instruction{"half_cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(68u, 2u), Instruction{"half_divide", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(69u, 2u), Instruction{"half_exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(70u, 2u), Instruction{"half_exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(71u, 2u), Instruction{"half_exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(72u, 2u), Instruction{"half_log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(73u, 2u), Instruction{"half_log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(74u, 2u), Instruction{"half_log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(75u, 2u), Instruction{"half_powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(76u, 2u), Instruction{"half_recip", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(77u, 2u), Instruction{"half_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(78u, 2u), Instruction{"half_sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(79u, 2u), Instruction{"half_sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(80u, 2u), Instruction{"half_tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(81u, 2u), Instruction{"native_cos", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(82u, 2u), Instruction{"native_divide", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(83u, 2u), Instruction{"native_exp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(84u, 2u), Instruction{"native_exp2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(85u, 2u), Instruction{"native_exp10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(86u, 2u), Instruction{"native_log", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(87u, 2u), Instruction{"native_log2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(88u, 2u), Instruction{"native_log10", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(89u, 2u), Instruction{"native_powr", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(90u, 2u), Instruction{"native_recip", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(91u, 2u), Instruction{"native_rsqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(92u, 2u), Instruction{"native_sin", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(93u, 2u), Instruction{"native_sqrt", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(94u, 2u), Instruction{"native_tan", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(141u, 2u), Instruction{"s_abs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(142u, 2u), Instruction{"s_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(143u, 2u), Instruction{"s_add_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(144u, 2u), Instruction{"u_add_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(145u, 2u), Instruction{"s_hadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(146u, 2u), Instruction{"u_hadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(147u, 2u), Instruction{"s_rhadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(148u, 2u), Instruction{"u_rhadd", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(149u, 2u), Instruction{"s_clamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(150u, 2u), Instruction{"u_clamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(151u, 2u), Instruction{"clz", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(152u, 2u), Instruction{"ctz", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(153u, 2u), Instruction{"s_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(154u, 2u), Instruction{"u_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(155u, 2u), Instruction{"s_mad_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(156u, 2u), Instruction{"s_max", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(157u, 2u), Instruction{"u_max", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(158u, 2u), Instruction{"s_min", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(159u, 2u), Instruction{"u_min", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(160u, 2u), Instruction{"s_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(161u, 2u), Instruction{"rotate", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'v'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'i'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(162u, 2u), Instruction{"s_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(163u, 2u), Instruction{"u_sub_sat", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(164u, 2u), Instruction{"u_upsample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(165u, 2u), Instruction{"s_upsample", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'hi'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'lo'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(166u, 2u), Instruction{"popcount", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(167u, 2u), Instruction{"s_mad24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(168u, 2u), Instruction{"u_mad24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'z'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(169u, 2u), Instruction{"s_mul24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(170u, 2u), Instruction{"u_mul24", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(201u, 2u), Instruction{"u_abs", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(202u, 2u), Instruction{"u_abs_diff", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(203u, 2u), Instruction{"u_mul_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(204u, 2u), Instruction{"u_mad_hi", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(95u, 2u), Instruction{"fclamp", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'minval'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'maxval'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(96u, 2u), Instruction{"degrees", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'radians'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(97u, 2u), Instruction{"fmax_common", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(98u, 2u), Instruction{"fmin_common", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(99u, 2u), Instruction{"mix", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(100u, 2u), Instruction{"radians", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'degrees'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(101u, 2u), Instruction{"step", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(102u, 2u), Instruction{"smoothstep", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'edge1'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(103u, 2u), Instruction{"sign", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(104u, 2u), Instruction{"cross", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(105u, 2u), Instruction{"distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(106u, 2u), Instruction{"length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(107u, 2u), Instruction{"normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(108u, 2u), Instruction{"fast_distance", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p0'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p1'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(109u, 2u), Instruction{"fast_length", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(110u, 2u), Instruction{"fast_normalize", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(186u, 2u), Instruction{"bitselect", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(187u, 2u), Instruction{"select", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'a'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'b'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'c'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(171u, 2u), Instruction{"vloadn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(172u, 2u), Instruction{"vstoren", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(173u, 2u), Instruction{"vload_half", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(174u, 2u), Instruction{"vload_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(175u, 2u), Instruction{"vstore_half", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(176u, 2u), Instruction{"vstore_half_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(177u, 2u), Instruction{"vstore_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(178u, 2u), Instruction{"vstore_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(179u, 2u), Instruction{"vloada_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::LiteralInteger, OperandCategory::Literal, "'n'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(180u, 2u), Instruction{"vstorea_halfn", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(181u, 2u), Instruction{"vstorea_halfn_r", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'data'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'offset'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'p'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::FPRoundingMode, OperandCategory::ValueEnum, "'mode'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(182u, 2u), Instruction{"shuffle", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(183u, 2u), Instruction{"shuffle2", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'x'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'y'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'shuffle mask'",Quantifier::One);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(184u, 2u), Instruction{"printf", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'format'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'additional arguments'",Quantifier::ZeroOrAny);
	}
	{
		auto& instr = m_instructions.emplaceUnique(Hash64(185u, 2u), Instruction{"prefetch", _pAllocator, _pAllocator, _pAllocator, 0}).kv.value;
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'ptr'",Quantifier::One);
		instr.operands.emplace_back(OperandKind::IdRef, OperandCategory::Id, "'num elements'",Quantifier::One);
	}
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::ImageOperands)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::ImageOperands)),"Bias");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::ImageOperands)),"Lod");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::ImageOperands)),"Grad");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::ImageOperands)),"ConstOffset");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::ImageOperands)),"Offset");
	m_operandNames.emplaceUnique(Hash64(0x0020u, static_cast<unsigned int>(OperandKind::ImageOperands)),"ConstOffsets");
	m_operandNames.emplaceUnique(Hash64(0x0040u, static_cast<unsigned int>(OperandKind::ImageOperands)),"Sample");
	m_operandNames.emplaceUnique(Hash64(0x0080u, static_cast<unsigned int>(OperandKind::ImageOperands)),"MinLod");
	m_operandNames.emplaceUnique(Hash64(0x0100u, static_cast<unsigned int>(OperandKind::ImageOperands)),"MakeTexelAvailable");
	m_operandNames.emplaceUnique(Hash64(0x0100u, static_cast<unsigned int>(OperandKind::ImageOperands)),"MakeTexelAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(0x0200u, static_cast<unsigned int>(OperandKind::ImageOperands)),"MakeTexelVisible");
	m_operandNames.emplaceUnique(Hash64(0x0200u, static_cast<unsigned int>(OperandKind::ImageOperands)),"MakeTexelVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(0x0400u, static_cast<unsigned int>(OperandKind::ImageOperands)),"NonPrivateTexel");
	m_operandNames.emplaceUnique(Hash64(0x0400u, static_cast<unsigned int>(OperandKind::ImageOperands)),"NonPrivateTexelKHR");
	m_operandNames.emplaceUnique(Hash64(0x0800u, static_cast<unsigned int>(OperandKind::ImageOperands)),"VolatileTexel");
	m_operandNames.emplaceUnique(Hash64(0x0800u, static_cast<unsigned int>(OperandKind::ImageOperands)),"VolatileTexelKHR");
	m_operandNames.emplaceUnique(Hash64(0x1000u, static_cast<unsigned int>(OperandKind::ImageOperands)),"SignExtend");
	m_operandNames.emplaceUnique(Hash64(0x2000u, static_cast<unsigned int>(OperandKind::ImageOperands)),"ZeroExtend");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"NotNaN");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"NotInf");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"NSZ");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"AllowRecip");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::FPFastMathMode)),"Fast");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::SelectionControl)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::SelectionControl)),"Flatten");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::SelectionControl)),"DontFlatten");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::LoopControl)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::LoopControl)),"Unroll");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::LoopControl)),"DontUnroll");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::LoopControl)),"DependencyInfinite");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::LoopControl)),"DependencyLength");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::LoopControl)),"MinIterations");
	m_operandNames.emplaceUnique(Hash64(0x0020u, static_cast<unsigned int>(OperandKind::LoopControl)),"MaxIterations");
	m_operandNames.emplaceUnique(Hash64(0x0040u, static_cast<unsigned int>(OperandKind::LoopControl)),"IterationMultiple");
	m_operandNames.emplaceUnique(Hash64(0x0080u, static_cast<unsigned int>(OperandKind::LoopControl)),"PeelCount");
	m_operandNames.emplaceUnique(Hash64(0x0100u, static_cast<unsigned int>(OperandKind::LoopControl)),"PartialCount");
	m_operandNames.emplaceUnique(Hash64(0x10000u, static_cast<unsigned int>(OperandKind::LoopControl)),"InitiationIntervalINTEL");
	m_operandNames.emplaceUnique(Hash64(0x20000u, static_cast<unsigned int>(OperandKind::LoopControl)),"MaxConcurrencyINTEL");
	m_operandNames.emplaceUnique(Hash64(0x40000u, static_cast<unsigned int>(OperandKind::LoopControl)),"DependencyArrayINTEL");
	m_operandNames.emplaceUnique(Hash64(0x80000u, static_cast<unsigned int>(OperandKind::LoopControl)),"PipelineEnableINTEL");
	m_operandNames.emplaceUnique(Hash64(0x100000u, static_cast<unsigned int>(OperandKind::LoopControl)),"LoopCoalesceINTEL");
	m_operandNames.emplaceUnique(Hash64(0x200000u, static_cast<unsigned int>(OperandKind::LoopControl)),"MaxInterleavingINTEL");
	m_operandNames.emplaceUnique(Hash64(0x400000u, static_cast<unsigned int>(OperandKind::LoopControl)),"SpeculatedIterationsINTEL");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::FunctionControl)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::FunctionControl)),"Inline");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::FunctionControl)),"DontInline");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::FunctionControl)),"Pure");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::FunctionControl)),"Const");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"Relaxed");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"Acquire");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"Release");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"AcquireRelease");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"SequentiallyConsistent");
	m_operandNames.emplaceUnique(Hash64(0x0040u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"UniformMemory");
	m_operandNames.emplaceUnique(Hash64(0x0080u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"SubgroupMemory");
	m_operandNames.emplaceUnique(Hash64(0x0100u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"WorkgroupMemory");
	m_operandNames.emplaceUnique(Hash64(0x0200u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"CrossWorkgroupMemory");
	m_operandNames.emplaceUnique(Hash64(0x0400u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"AtomicCounterMemory");
	m_operandNames.emplaceUnique(Hash64(0x0800u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"ImageMemory");
	m_operandNames.emplaceUnique(Hash64(0x1000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"OutputMemory");
	m_operandNames.emplaceUnique(Hash64(0x1000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"OutputMemoryKHR");
	m_operandNames.emplaceUnique(Hash64(0x2000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"MakeAvailable");
	m_operandNames.emplaceUnique(Hash64(0x2000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"MakeAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(0x4000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"MakeVisible");
	m_operandNames.emplaceUnique(Hash64(0x4000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"MakeVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(0x8000u, static_cast<unsigned int>(OperandKind::MemorySemantics)),"Volatile");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"Volatile");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"Aligned");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"Nontemporal");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"MakePointerAvailable");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"MakePointerAvailableKHR");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"MakePointerVisible");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"MakePointerVisibleKHR");
	m_operandNames.emplaceUnique(Hash64(0x0020u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"NonPrivatePointer");
	m_operandNames.emplaceUnique(Hash64(0x0020u, static_cast<unsigned int>(OperandKind::MemoryAccess)),"NonPrivatePointerKHR");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::KernelProfilingInfo)),"None");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::KernelProfilingInfo)),"CmdExecTime");
	m_operandNames.emplaceUnique(Hash64(0x0000u, static_cast<unsigned int>(OperandKind::RayFlags)),"NoneKHR");
	m_operandNames.emplaceUnique(Hash64(0x0001u, static_cast<unsigned int>(OperandKind::RayFlags)),"OpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(0x0002u, static_cast<unsigned int>(OperandKind::RayFlags)),"NoOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(0x0004u, static_cast<unsigned int>(OperandKind::RayFlags)),"TerminateOnFirstHitKHR");
	m_operandNames.emplaceUnique(Hash64(0x0008u, static_cast<unsigned int>(OperandKind::RayFlags)),"SkipClosestHitShaderKHR");
	m_operandNames.emplaceUnique(Hash64(0x0010u, static_cast<unsigned int>(OperandKind::RayFlags)),"CullBackFacingTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(0x0020u, static_cast<unsigned int>(OperandKind::RayFlags)),"CullFrontFacingTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(0x0040u, static_cast<unsigned int>(OperandKind::RayFlags)),"CullOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(0x0080u, static_cast<unsigned int>(OperandKind::RayFlags)),"CullNoOpaqueKHR");
	m_operandNames.emplaceUnique(Hash64(0x0100u, static_cast<unsigned int>(OperandKind::RayFlags)),"SkipTrianglesKHR");
	m_operandNames.emplaceUnique(Hash64(0x0200u, static_cast<unsigned int>(OperandKind::RayFlags)),"SkipAABBsKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"Unknown");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"ESSL");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"GLSL");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"OpenCL_C");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"OpenCL_CPP");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::SourceLanguage)),"HLSL");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"Vertex");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"TessellationControl");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"TessellationEvaluation");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"Geometry");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"Fragment");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"GLCompute");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"Kernel");
	m_operandNames.emplaceUnique(Hash64(5267u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"TaskNV");
	m_operandNames.emplaceUnique(Hash64(5268u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"MeshNV");
	m_operandNames.emplaceUnique(Hash64(5313u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"RayGenerationNV");
	m_operandNames.emplaceUnique(Hash64(5313u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"RayGenerationKHR");
	m_operandNames.emplaceUnique(Hash64(5314u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"IntersectionNV");
	m_operandNames.emplaceUnique(Hash64(5314u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"IntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(5315u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"AnyHitNV");
	m_operandNames.emplaceUnique(Hash64(5315u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"AnyHitKHR");
	m_operandNames.emplaceUnique(Hash64(5316u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"ClosestHitNV");
	m_operandNames.emplaceUnique(Hash64(5316u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"ClosestHitKHR");
	m_operandNames.emplaceUnique(Hash64(5317u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"MissNV");
	m_operandNames.emplaceUnique(Hash64(5317u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"MissKHR");
	m_operandNames.emplaceUnique(Hash64(5318u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"CallableNV");
	m_operandNames.emplaceUnique(Hash64(5318u, static_cast<unsigned int>(OperandKind::ExecutionModel)),"CallableKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::AddressingModel)),"Logical");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::AddressingModel)),"Physical32");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::AddressingModel)),"Physical64");
	m_operandNames.emplaceUnique(Hash64(5348u, static_cast<unsigned int>(OperandKind::AddressingModel)),"PhysicalStorageBuffer64");
	m_operandNames.emplaceUnique(Hash64(5348u, static_cast<unsigned int>(OperandKind::AddressingModel)),"PhysicalStorageBuffer64EXT");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::MemoryModel)),"Simple");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::MemoryModel)),"GLSL450");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::MemoryModel)),"OpenCL");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::MemoryModel)),"Vulkan");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::MemoryModel)),"VulkanKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Invocations");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SpacingEqual");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SpacingFractionalEven");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SpacingFractionalOdd");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"VertexOrderCw");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"VertexOrderCcw");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"PixelCenterInteger");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OriginUpperLeft");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OriginLowerLeft");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"EarlyFragmentTests");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"PointMode");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Xfb");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DepthReplacing");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DepthGreater");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DepthLess");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DepthUnchanged");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"LocalSize");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"LocalSizeHint");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"InputPoints");
	m_operandNames.emplaceUnique(Hash64(20u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"InputLines");
	m_operandNames.emplaceUnique(Hash64(21u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"InputLinesAdjacency");
	m_operandNames.emplaceUnique(Hash64(22u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Triangles");
	m_operandNames.emplaceUnique(Hash64(23u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"InputTrianglesAdjacency");
	m_operandNames.emplaceUnique(Hash64(24u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Quads");
	m_operandNames.emplaceUnique(Hash64(25u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Isolines");
	m_operandNames.emplaceUnique(Hash64(26u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputVertices");
	m_operandNames.emplaceUnique(Hash64(27u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputPoints");
	m_operandNames.emplaceUnique(Hash64(28u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputLineStrip");
	m_operandNames.emplaceUnique(Hash64(29u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputTriangleStrip");
	m_operandNames.emplaceUnique(Hash64(30u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"VecTypeHint");
	m_operandNames.emplaceUnique(Hash64(31u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"ContractionOff");
	m_operandNames.emplaceUnique(Hash64(33u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Initializer");
	m_operandNames.emplaceUnique(Hash64(34u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"Finalizer");
	m_operandNames.emplaceUnique(Hash64(35u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SubgroupSize");
	m_operandNames.emplaceUnique(Hash64(36u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SubgroupsPerWorkgroup");
	m_operandNames.emplaceUnique(Hash64(37u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SubgroupsPerWorkgroupId");
	m_operandNames.emplaceUnique(Hash64(38u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"LocalSizeId");
	m_operandNames.emplaceUnique(Hash64(39u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"LocalSizeHintId");
	m_operandNames.emplaceUnique(Hash64(4446u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"PostDepthCoverage");
	m_operandNames.emplaceUnique(Hash64(4459u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DenormPreserve");
	m_operandNames.emplaceUnique(Hash64(4460u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DenormFlushToZero");
	m_operandNames.emplaceUnique(Hash64(4461u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SignedZeroInfNanPreserve");
	m_operandNames.emplaceUnique(Hash64(4462u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"RoundingModeRTE");
	m_operandNames.emplaceUnique(Hash64(4463u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"RoundingModeRTZ");
	m_operandNames.emplaceUnique(Hash64(5027u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"StencilRefReplacingEXT");
	m_operandNames.emplaceUnique(Hash64(5269u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputLinesNV");
	m_operandNames.emplaceUnique(Hash64(5270u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputPrimitivesNV");
	m_operandNames.emplaceUnique(Hash64(5289u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DerivativeGroupQuadsNV");
	m_operandNames.emplaceUnique(Hash64(5290u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"DerivativeGroupLinearNV");
	m_operandNames.emplaceUnique(Hash64(5298u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"OutputTrianglesNV");
	m_operandNames.emplaceUnique(Hash64(5366u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"PixelInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(5367u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"PixelInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(5368u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SampleInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(5369u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"SampleInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(5370u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"ShadingRateInterlockOrderedEXT");
	m_operandNames.emplaceUnique(Hash64(5371u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"ShadingRateInterlockUnorderedEXT");
	m_operandNames.emplaceUnique(Hash64(5893u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"MaxWorkgroupSizeINTEL");
	m_operandNames.emplaceUnique(Hash64(5894u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"MaxWorkDimINTEL");
	m_operandNames.emplaceUnique(Hash64(5895u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"NoGlobalOffsetINTEL");
	m_operandNames.emplaceUnique(Hash64(5896u, static_cast<unsigned int>(OperandKind::ExecutionMode)),"NumSIMDWorkitemsINTEL");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::StorageClass)),"UniformConstant");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::StorageClass)),"Input");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::StorageClass)),"Uniform");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::StorageClass)),"Output");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::StorageClass)),"Workgroup");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::StorageClass)),"CrossWorkgroup");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::StorageClass)),"Private");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::StorageClass)),"Function");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::StorageClass)),"Generic");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::StorageClass)),"PushConstant");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::StorageClass)),"AtomicCounter");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::StorageClass)),"Image");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::StorageClass)),"StorageBuffer");
	m_operandNames.emplaceUnique(Hash64(5328u, static_cast<unsigned int>(OperandKind::StorageClass)),"CallableDataNV");
	m_operandNames.emplaceUnique(Hash64(5328u, static_cast<unsigned int>(OperandKind::StorageClass)),"CallableDataKHR");
	m_operandNames.emplaceUnique(Hash64(5329u, static_cast<unsigned int>(OperandKind::StorageClass)),"IncomingCallableDataNV");
	m_operandNames.emplaceUnique(Hash64(5329u, static_cast<unsigned int>(OperandKind::StorageClass)),"IncomingCallableDataKHR");
	m_operandNames.emplaceUnique(Hash64(5338u, static_cast<unsigned int>(OperandKind::StorageClass)),"RayPayloadNV");
	m_operandNames.emplaceUnique(Hash64(5338u, static_cast<unsigned int>(OperandKind::StorageClass)),"RayPayloadKHR");
	m_operandNames.emplaceUnique(Hash64(5339u, static_cast<unsigned int>(OperandKind::StorageClass)),"HitAttributeNV");
	m_operandNames.emplaceUnique(Hash64(5339u, static_cast<unsigned int>(OperandKind::StorageClass)),"HitAttributeKHR");
	m_operandNames.emplaceUnique(Hash64(5342u, static_cast<unsigned int>(OperandKind::StorageClass)),"IncomingRayPayloadNV");
	m_operandNames.emplaceUnique(Hash64(5342u, static_cast<unsigned int>(OperandKind::StorageClass)),"IncomingRayPayloadKHR");
	m_operandNames.emplaceUnique(Hash64(5343u, static_cast<unsigned int>(OperandKind::StorageClass)),"ShaderRecordBufferNV");
	m_operandNames.emplaceUnique(Hash64(5343u, static_cast<unsigned int>(OperandKind::StorageClass)),"ShaderRecordBufferKHR");
	m_operandNames.emplaceUnique(Hash64(5349u, static_cast<unsigned int>(OperandKind::StorageClass)),"PhysicalStorageBuffer");
	m_operandNames.emplaceUnique(Hash64(5349u, static_cast<unsigned int>(OperandKind::StorageClass)),"PhysicalStorageBufferEXT");
	m_operandNames.emplaceUnique(Hash64(5605u, static_cast<unsigned int>(OperandKind::StorageClass)),"CodeSectionINTEL");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::Dim)),"Dim1D");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::Dim)),"Dim2D");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::Dim)),"Dim3D");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::Dim)),"Cube");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::Dim)),"Rect");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::Dim)),"Buffer");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::Dim)),"SubpassData");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::SamplerAddressingMode)),"None");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::SamplerAddressingMode)),"ClampToEdge");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::SamplerAddressingMode)),"Clamp");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::SamplerAddressingMode)),"Repeat");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::SamplerAddressingMode)),"RepeatMirrored");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::SamplerFilterMode)),"Nearest");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::SamplerFilterMode)),"Linear");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Unknown");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba32f");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba16f");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R32f");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba8");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba8Snorm");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg32f");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg16f");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R11fG11fB10f");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R16f");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba16");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgb10A2");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg16");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg8");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R16");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R8");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba16Snorm");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg16Snorm");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg8Snorm");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R16Snorm");
	m_operandNames.emplaceUnique(Hash64(20u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R8Snorm");
	m_operandNames.emplaceUnique(Hash64(21u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba32i");
	m_operandNames.emplaceUnique(Hash64(22u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba16i");
	m_operandNames.emplaceUnique(Hash64(23u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba8i");
	m_operandNames.emplaceUnique(Hash64(24u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R32i");
	m_operandNames.emplaceUnique(Hash64(25u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg32i");
	m_operandNames.emplaceUnique(Hash64(26u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg16i");
	m_operandNames.emplaceUnique(Hash64(27u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg8i");
	m_operandNames.emplaceUnique(Hash64(28u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R16i");
	m_operandNames.emplaceUnique(Hash64(29u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R8i");
	m_operandNames.emplaceUnique(Hash64(30u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba32ui");
	m_operandNames.emplaceUnique(Hash64(31u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba16ui");
	m_operandNames.emplaceUnique(Hash64(32u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgba8ui");
	m_operandNames.emplaceUnique(Hash64(33u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R32ui");
	m_operandNames.emplaceUnique(Hash64(34u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rgb10a2ui");
	m_operandNames.emplaceUnique(Hash64(35u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg32ui");
	m_operandNames.emplaceUnique(Hash64(36u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg16ui");
	m_operandNames.emplaceUnique(Hash64(37u, static_cast<unsigned int>(OperandKind::ImageFormat)),"Rg8ui");
	m_operandNames.emplaceUnique(Hash64(38u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R16ui");
	m_operandNames.emplaceUnique(Hash64(39u, static_cast<unsigned int>(OperandKind::ImageFormat)),"R8ui");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"R");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"A");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RG");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RA");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RGB");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RGBA");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"BGRA");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"ARGB");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"Intensity");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"Luminance");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"Rx");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RGx");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"RGBx");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"Depth");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"DepthStencil");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"sRGB");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"sRGBx");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"sRGBA");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"sBGRA");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::ImageChannelOrder)),"ABGR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"SnormInt8");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"SnormInt16");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormInt8");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormInt16");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormShort565");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormShort555");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormInt101010");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"SignedInt8");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"SignedInt16");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"SignedInt32");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnsignedInt8");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnsignedInt16");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnsignedInt32");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"HalfFloat");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"Float");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormInt24");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::ImageChannelDataType)),"UnormInt101010_2");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::FPRoundingMode)),"RTE");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::FPRoundingMode)),"RTZ");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::FPRoundingMode)),"RTP");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::FPRoundingMode)),"RTN");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::LinkageType)),"Export");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::LinkageType)),"Import");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::AccessQualifier)),"ReadOnly");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::AccessQualifier)),"WriteOnly");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::AccessQualifier)),"ReadWrite");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"Zext");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"Sext");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"ByVal");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"Sret");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"NoAlias");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"NoCapture");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"NoWrite");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::FunctionParameterAttribute)),"NoReadWrite");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::Decoration)),"RelaxedPrecision");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::Decoration)),"SpecId");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::Decoration)),"Block");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::Decoration)),"BufferBlock");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::Decoration)),"RowMajor");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::Decoration)),"ColMajor");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::Decoration)),"ArrayStride");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::Decoration)),"MatrixStride");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::Decoration)),"GLSLShared");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::Decoration)),"GLSLPacked");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::Decoration)),"CPacked");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::Decoration)),"BuiltIn");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::Decoration)),"NoPerspective");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::Decoration)),"Flat");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::Decoration)),"Patch");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::Decoration)),"Centroid");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::Decoration)),"Sample");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::Decoration)),"Invariant");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::Decoration)),"Restrict");
	m_operandNames.emplaceUnique(Hash64(20u, static_cast<unsigned int>(OperandKind::Decoration)),"Aliased");
	m_operandNames.emplaceUnique(Hash64(21u, static_cast<unsigned int>(OperandKind::Decoration)),"Volatile");
	m_operandNames.emplaceUnique(Hash64(22u, static_cast<unsigned int>(OperandKind::Decoration)),"Constant");
	m_operandNames.emplaceUnique(Hash64(23u, static_cast<unsigned int>(OperandKind::Decoration)),"Coherent");
	m_operandNames.emplaceUnique(Hash64(24u, static_cast<unsigned int>(OperandKind::Decoration)),"NonWritable");
	m_operandNames.emplaceUnique(Hash64(25u, static_cast<unsigned int>(OperandKind::Decoration)),"NonReadable");
	m_operandNames.emplaceUnique(Hash64(26u, static_cast<unsigned int>(OperandKind::Decoration)),"Uniform");
	m_operandNames.emplaceUnique(Hash64(27u, static_cast<unsigned int>(OperandKind::Decoration)),"UniformId");
	m_operandNames.emplaceUnique(Hash64(28u, static_cast<unsigned int>(OperandKind::Decoration)),"SaturatedConversion");
	m_operandNames.emplaceUnique(Hash64(29u, static_cast<unsigned int>(OperandKind::Decoration)),"Stream");
	m_operandNames.emplaceUnique(Hash64(30u, static_cast<unsigned int>(OperandKind::Decoration)),"Location");
	m_operandNames.emplaceUnique(Hash64(31u, static_cast<unsigned int>(OperandKind::Decoration)),"Component");
	m_operandNames.emplaceUnique(Hash64(32u, static_cast<unsigned int>(OperandKind::Decoration)),"Index");
	m_operandNames.emplaceUnique(Hash64(33u, static_cast<unsigned int>(OperandKind::Decoration)),"Binding");
	m_operandNames.emplaceUnique(Hash64(34u, static_cast<unsigned int>(OperandKind::Decoration)),"DescriptorSet");
	m_operandNames.emplaceUnique(Hash64(35u, static_cast<unsigned int>(OperandKind::Decoration)),"Offset");
	m_operandNames.emplaceUnique(Hash64(36u, static_cast<unsigned int>(OperandKind::Decoration)),"XfbBuffer");
	m_operandNames.emplaceUnique(Hash64(37u, static_cast<unsigned int>(OperandKind::Decoration)),"XfbStride");
	m_operandNames.emplaceUnique(Hash64(38u, static_cast<unsigned int>(OperandKind::Decoration)),"FuncParamAttr");
	m_operandNames.emplaceUnique(Hash64(39u, static_cast<unsigned int>(OperandKind::Decoration)),"FPRoundingMode");
	m_operandNames.emplaceUnique(Hash64(40u, static_cast<unsigned int>(OperandKind::Decoration)),"FPFastMathMode");
	m_operandNames.emplaceUnique(Hash64(41u, static_cast<unsigned int>(OperandKind::Decoration)),"LinkageAttributes");
	m_operandNames.emplaceUnique(Hash64(42u, static_cast<unsigned int>(OperandKind::Decoration)),"NoContraction");
	m_operandNames.emplaceUnique(Hash64(43u, static_cast<unsigned int>(OperandKind::Decoration)),"InputAttachmentIndex");
	m_operandNames.emplaceUnique(Hash64(44u, static_cast<unsigned int>(OperandKind::Decoration)),"Alignment");
	m_operandNames.emplaceUnique(Hash64(45u, static_cast<unsigned int>(OperandKind::Decoration)),"MaxByteOffset");
	m_operandNames.emplaceUnique(Hash64(46u, static_cast<unsigned int>(OperandKind::Decoration)),"AlignmentId");
	m_operandNames.emplaceUnique(Hash64(47u, static_cast<unsigned int>(OperandKind::Decoration)),"MaxByteOffsetId");
	m_operandNames.emplaceUnique(Hash64(4469u, static_cast<unsigned int>(OperandKind::Decoration)),"NoSignedWrap");
	m_operandNames.emplaceUnique(Hash64(4470u, static_cast<unsigned int>(OperandKind::Decoration)),"NoUnsignedWrap");
	m_operandNames.emplaceUnique(Hash64(4999u, static_cast<unsigned int>(OperandKind::Decoration)),"ExplicitInterpAMD");
	m_operandNames.emplaceUnique(Hash64(5248u, static_cast<unsigned int>(OperandKind::Decoration)),"OverrideCoverageNV");
	m_operandNames.emplaceUnique(Hash64(5250u, static_cast<unsigned int>(OperandKind::Decoration)),"PassthroughNV");
	m_operandNames.emplaceUnique(Hash64(5252u, static_cast<unsigned int>(OperandKind::Decoration)),"ViewportRelativeNV");
	m_operandNames.emplaceUnique(Hash64(5256u, static_cast<unsigned int>(OperandKind::Decoration)),"SecondaryViewportRelativeNV");
	m_operandNames.emplaceUnique(Hash64(5271u, static_cast<unsigned int>(OperandKind::Decoration)),"PerPrimitiveNV");
	m_operandNames.emplaceUnique(Hash64(5272u, static_cast<unsigned int>(OperandKind::Decoration)),"PerViewNV");
	m_operandNames.emplaceUnique(Hash64(5273u, static_cast<unsigned int>(OperandKind::Decoration)),"PerTaskNV");
	m_operandNames.emplaceUnique(Hash64(5285u, static_cast<unsigned int>(OperandKind::Decoration)),"PerVertexNV");
	m_operandNames.emplaceUnique(Hash64(5300u, static_cast<unsigned int>(OperandKind::Decoration)),"NonUniform");
	m_operandNames.emplaceUnique(Hash64(5300u, static_cast<unsigned int>(OperandKind::Decoration)),"NonUniformEXT");
	m_operandNames.emplaceUnique(Hash64(5355u, static_cast<unsigned int>(OperandKind::Decoration)),"RestrictPointer");
	m_operandNames.emplaceUnique(Hash64(5355u, static_cast<unsigned int>(OperandKind::Decoration)),"RestrictPointerEXT");
	m_operandNames.emplaceUnique(Hash64(5356u, static_cast<unsigned int>(OperandKind::Decoration)),"AliasedPointer");
	m_operandNames.emplaceUnique(Hash64(5356u, static_cast<unsigned int>(OperandKind::Decoration)),"AliasedPointerEXT");
	m_operandNames.emplaceUnique(Hash64(5602u, static_cast<unsigned int>(OperandKind::Decoration)),"ReferencedIndirectlyINTEL");
	m_operandNames.emplaceUnique(Hash64(5634u, static_cast<unsigned int>(OperandKind::Decoration)),"CounterBuffer");
	m_operandNames.emplaceUnique(Hash64(5634u, static_cast<unsigned int>(OperandKind::Decoration)),"HlslCounterBufferGOOGLE");
	m_operandNames.emplaceUnique(Hash64(5635u, static_cast<unsigned int>(OperandKind::Decoration)),"UserSemantic");
	m_operandNames.emplaceUnique(Hash64(5635u, static_cast<unsigned int>(OperandKind::Decoration)),"HlslSemanticGOOGLE");
	m_operandNames.emplaceUnique(Hash64(5636u, static_cast<unsigned int>(OperandKind::Decoration)),"UserTypeGOOGLE");
	m_operandNames.emplaceUnique(Hash64(5825u, static_cast<unsigned int>(OperandKind::Decoration)),"RegisterINTEL");
	m_operandNames.emplaceUnique(Hash64(5826u, static_cast<unsigned int>(OperandKind::Decoration)),"MemoryINTEL");
	m_operandNames.emplaceUnique(Hash64(5827u, static_cast<unsigned int>(OperandKind::Decoration)),"NumbanksINTEL");
	m_operandNames.emplaceUnique(Hash64(5828u, static_cast<unsigned int>(OperandKind::Decoration)),"BankwidthINTEL");
	m_operandNames.emplaceUnique(Hash64(5829u, static_cast<unsigned int>(OperandKind::Decoration)),"MaxPrivateCopiesINTEL");
	m_operandNames.emplaceUnique(Hash64(5830u, static_cast<unsigned int>(OperandKind::Decoration)),"SinglepumpINTEL");
	m_operandNames.emplaceUnique(Hash64(5831u, static_cast<unsigned int>(OperandKind::Decoration)),"DoublepumpINTEL");
	m_operandNames.emplaceUnique(Hash64(5832u, static_cast<unsigned int>(OperandKind::Decoration)),"MaxReplicatesINTEL");
	m_operandNames.emplaceUnique(Hash64(5833u, static_cast<unsigned int>(OperandKind::Decoration)),"SimpleDualPortINTEL");
	m_operandNames.emplaceUnique(Hash64(5834u, static_cast<unsigned int>(OperandKind::Decoration)),"MergeINTEL");
	m_operandNames.emplaceUnique(Hash64(5835u, static_cast<unsigned int>(OperandKind::Decoration)),"BankBitsINTEL");
	m_operandNames.emplaceUnique(Hash64(5836u, static_cast<unsigned int>(OperandKind::Decoration)),"ForcePow2DepthINTEL");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::BuiltIn)),"Position");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PointSize");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ClipDistance");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::BuiltIn)),"CullDistance");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::BuiltIn)),"VertexId");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InstanceId");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PrimitiveId");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InvocationId");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::BuiltIn)),"Layer");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ViewportIndex");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::BuiltIn)),"TessLevelOuter");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::BuiltIn)),"TessLevelInner");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::BuiltIn)),"TessCoord");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PatchVertices");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragCoord");
	m_operandNames.emplaceUnique(Hash64(16u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PointCoord");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FrontFacing");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SampleId");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SamplePosition");
	m_operandNames.emplaceUnique(Hash64(20u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SampleMask");
	m_operandNames.emplaceUnique(Hash64(22u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragDepth");
	m_operandNames.emplaceUnique(Hash64(23u, static_cast<unsigned int>(OperandKind::BuiltIn)),"HelperInvocation");
	m_operandNames.emplaceUnique(Hash64(24u, static_cast<unsigned int>(OperandKind::BuiltIn)),"NumWorkgroups");
	m_operandNames.emplaceUnique(Hash64(25u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorkgroupSize");
	m_operandNames.emplaceUnique(Hash64(26u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorkgroupId");
	m_operandNames.emplaceUnique(Hash64(27u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LocalInvocationId");
	m_operandNames.emplaceUnique(Hash64(28u, static_cast<unsigned int>(OperandKind::BuiltIn)),"GlobalInvocationId");
	m_operandNames.emplaceUnique(Hash64(29u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LocalInvocationIndex");
	m_operandNames.emplaceUnique(Hash64(30u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorkDim");
	m_operandNames.emplaceUnique(Hash64(31u, static_cast<unsigned int>(OperandKind::BuiltIn)),"GlobalSize");
	m_operandNames.emplaceUnique(Hash64(32u, static_cast<unsigned int>(OperandKind::BuiltIn)),"EnqueuedWorkgroupSize");
	m_operandNames.emplaceUnique(Hash64(33u, static_cast<unsigned int>(OperandKind::BuiltIn)),"GlobalOffset");
	m_operandNames.emplaceUnique(Hash64(34u, static_cast<unsigned int>(OperandKind::BuiltIn)),"GlobalLinearId");
	m_operandNames.emplaceUnique(Hash64(36u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupSize");
	m_operandNames.emplaceUnique(Hash64(37u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupMaxSize");
	m_operandNames.emplaceUnique(Hash64(38u, static_cast<unsigned int>(OperandKind::BuiltIn)),"NumSubgroups");
	m_operandNames.emplaceUnique(Hash64(39u, static_cast<unsigned int>(OperandKind::BuiltIn)),"NumEnqueuedSubgroups");
	m_operandNames.emplaceUnique(Hash64(40u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupId");
	m_operandNames.emplaceUnique(Hash64(41u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupLocalInvocationId");
	m_operandNames.emplaceUnique(Hash64(42u, static_cast<unsigned int>(OperandKind::BuiltIn)),"VertexIndex");
	m_operandNames.emplaceUnique(Hash64(43u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InstanceIndex");
	m_operandNames.emplaceUnique(Hash64(4416u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupEqMask");
	m_operandNames.emplaceUnique(Hash64(4417u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupGeMask");
	m_operandNames.emplaceUnique(Hash64(4418u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupGtMask");
	m_operandNames.emplaceUnique(Hash64(4419u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupLeMask");
	m_operandNames.emplaceUnique(Hash64(4420u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupLtMask");
	m_operandNames.emplaceUnique(Hash64(4416u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupEqMaskKHR");
	m_operandNames.emplaceUnique(Hash64(4417u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupGeMaskKHR");
	m_operandNames.emplaceUnique(Hash64(4418u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupGtMaskKHR");
	m_operandNames.emplaceUnique(Hash64(4419u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupLeMaskKHR");
	m_operandNames.emplaceUnique(Hash64(4420u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SubgroupLtMaskKHR");
	m_operandNames.emplaceUnique(Hash64(4424u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaseVertex");
	m_operandNames.emplaceUnique(Hash64(4425u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaseInstance");
	m_operandNames.emplaceUnique(Hash64(4426u, static_cast<unsigned int>(OperandKind::BuiltIn)),"DrawIndex");
	m_operandNames.emplaceUnique(Hash64(4438u, static_cast<unsigned int>(OperandKind::BuiltIn)),"DeviceIndex");
	m_operandNames.emplaceUnique(Hash64(4440u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ViewIndex");
	m_operandNames.emplaceUnique(Hash64(4992u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordNoPerspAMD");
	m_operandNames.emplaceUnique(Hash64(4993u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordNoPerspCentroidAMD");
	m_operandNames.emplaceUnique(Hash64(4994u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordNoPerspSampleAMD");
	m_operandNames.emplaceUnique(Hash64(4995u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordSmoothAMD");
	m_operandNames.emplaceUnique(Hash64(4996u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordSmoothCentroidAMD");
	m_operandNames.emplaceUnique(Hash64(4997u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordSmoothSampleAMD");
	m_operandNames.emplaceUnique(Hash64(4998u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordPullModelAMD");
	m_operandNames.emplaceUnique(Hash64(5014u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragStencilRefEXT");
	m_operandNames.emplaceUnique(Hash64(5253u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(5257u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SecondaryPositionNV");
	m_operandNames.emplaceUnique(Hash64(5258u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SecondaryViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(5261u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PositionPerViewNV");
	m_operandNames.emplaceUnique(Hash64(5262u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ViewportMaskPerViewNV");
	m_operandNames.emplaceUnique(Hash64(5264u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FullyCoveredEXT");
	m_operandNames.emplaceUnique(Hash64(5274u, static_cast<unsigned int>(OperandKind::BuiltIn)),"TaskCountNV");
	m_operandNames.emplaceUnique(Hash64(5275u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PrimitiveCountNV");
	m_operandNames.emplaceUnique(Hash64(5276u, static_cast<unsigned int>(OperandKind::BuiltIn)),"PrimitiveIndicesNV");
	m_operandNames.emplaceUnique(Hash64(5277u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ClipDistancePerViewNV");
	m_operandNames.emplaceUnique(Hash64(5278u, static_cast<unsigned int>(OperandKind::BuiltIn)),"CullDistancePerViewNV");
	m_operandNames.emplaceUnique(Hash64(5279u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LayerPerViewNV");
	m_operandNames.emplaceUnique(Hash64(5280u, static_cast<unsigned int>(OperandKind::BuiltIn)),"MeshViewCountNV");
	m_operandNames.emplaceUnique(Hash64(5281u, static_cast<unsigned int>(OperandKind::BuiltIn)),"MeshViewIndicesNV");
	m_operandNames.emplaceUnique(Hash64(5286u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordNV");
	m_operandNames.emplaceUnique(Hash64(5287u, static_cast<unsigned int>(OperandKind::BuiltIn)),"BaryCoordNoPerspNV");
	m_operandNames.emplaceUnique(Hash64(5292u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragSizeEXT");
	m_operandNames.emplaceUnique(Hash64(5292u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragmentSizeNV");
	m_operandNames.emplaceUnique(Hash64(5293u, static_cast<unsigned int>(OperandKind::BuiltIn)),"FragInvocationCountEXT");
	m_operandNames.emplaceUnique(Hash64(5293u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InvocationsPerPixelNV");
	m_operandNames.emplaceUnique(Hash64(5319u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LaunchIdNV");
	m_operandNames.emplaceUnique(Hash64(5319u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LaunchIdKHR");
	m_operandNames.emplaceUnique(Hash64(5320u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LaunchSizeNV");
	m_operandNames.emplaceUnique(Hash64(5320u, static_cast<unsigned int>(OperandKind::BuiltIn)),"LaunchSizeKHR");
	m_operandNames.emplaceUnique(Hash64(5321u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldRayOriginNV");
	m_operandNames.emplaceUnique(Hash64(5321u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldRayOriginKHR");
	m_operandNames.emplaceUnique(Hash64(5322u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldRayDirectionNV");
	m_operandNames.emplaceUnique(Hash64(5322u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldRayDirectionKHR");
	m_operandNames.emplaceUnique(Hash64(5323u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectRayOriginNV");
	m_operandNames.emplaceUnique(Hash64(5323u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectRayOriginKHR");
	m_operandNames.emplaceUnique(Hash64(5324u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectRayDirectionNV");
	m_operandNames.emplaceUnique(Hash64(5324u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectRayDirectionKHR");
	m_operandNames.emplaceUnique(Hash64(5325u, static_cast<unsigned int>(OperandKind::BuiltIn)),"RayTminNV");
	m_operandNames.emplaceUnique(Hash64(5325u, static_cast<unsigned int>(OperandKind::BuiltIn)),"RayTminKHR");
	m_operandNames.emplaceUnique(Hash64(5326u, static_cast<unsigned int>(OperandKind::BuiltIn)),"RayTmaxNV");
	m_operandNames.emplaceUnique(Hash64(5326u, static_cast<unsigned int>(OperandKind::BuiltIn)),"RayTmaxKHR");
	m_operandNames.emplaceUnique(Hash64(5327u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InstanceCustomIndexNV");
	m_operandNames.emplaceUnique(Hash64(5327u, static_cast<unsigned int>(OperandKind::BuiltIn)),"InstanceCustomIndexKHR");
	m_operandNames.emplaceUnique(Hash64(5330u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectToWorldNV");
	m_operandNames.emplaceUnique(Hash64(5330u, static_cast<unsigned int>(OperandKind::BuiltIn)),"ObjectToWorldKHR");
	m_operandNames.emplaceUnique(Hash64(5331u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldToObjectNV");
	m_operandNames.emplaceUnique(Hash64(5331u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WorldToObjectKHR");
	m_operandNames.emplaceUnique(Hash64(5332u, static_cast<unsigned int>(OperandKind::BuiltIn)),"HitTNV");
	m_operandNames.emplaceUnique(Hash64(5332u, static_cast<unsigned int>(OperandKind::BuiltIn)),"HitTKHR");
	m_operandNames.emplaceUnique(Hash64(5333u, static_cast<unsigned int>(OperandKind::BuiltIn)),"HitKindNV");
	m_operandNames.emplaceUnique(Hash64(5333u, static_cast<unsigned int>(OperandKind::BuiltIn)),"HitKindKHR");
	m_operandNames.emplaceUnique(Hash64(5351u, static_cast<unsigned int>(OperandKind::BuiltIn)),"IncomingRayFlagsNV");
	m_operandNames.emplaceUnique(Hash64(5351u, static_cast<unsigned int>(OperandKind::BuiltIn)),"IncomingRayFlagsKHR");
	m_operandNames.emplaceUnique(Hash64(5352u, static_cast<unsigned int>(OperandKind::BuiltIn)),"RayGeometryIndexKHR");
	m_operandNames.emplaceUnique(Hash64(5374u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WarpsPerSMNV");
	m_operandNames.emplaceUnique(Hash64(5375u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SMCountNV");
	m_operandNames.emplaceUnique(Hash64(5376u, static_cast<unsigned int>(OperandKind::BuiltIn)),"WarpIDNV");
	m_operandNames.emplaceUnique(Hash64(5377u, static_cast<unsigned int>(OperandKind::BuiltIn)),"SMIDNV");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::Scope)),"CrossDevice");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::Scope)),"Device");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::Scope)),"Workgroup");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::Scope)),"Subgroup");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::Scope)),"Invocation");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::Scope)),"QueueFamily");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::Scope)),"QueueFamilyKHR");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::Scope)),"ShaderCallKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::GroupOperation)),"Reduce");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::GroupOperation)),"InclusiveScan");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::GroupOperation)),"ExclusiveScan");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::GroupOperation)),"ClusteredReduce");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::GroupOperation)),"PartitionedReduceNV");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::GroupOperation)),"PartitionedInclusiveScanNV");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::GroupOperation)),"PartitionedExclusiveScanNV");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::KernelEnqueueFlags)),"NoWait");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::KernelEnqueueFlags)),"WaitKernel");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::KernelEnqueueFlags)),"WaitWorkGroup");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::Capability)),"Matrix");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::Capability)),"Shader");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::Capability)),"Geometry");
	m_operandNames.emplaceUnique(Hash64(3u, static_cast<unsigned int>(OperandKind::Capability)),"Tessellation");
	m_operandNames.emplaceUnique(Hash64(4u, static_cast<unsigned int>(OperandKind::Capability)),"Addresses");
	m_operandNames.emplaceUnique(Hash64(5u, static_cast<unsigned int>(OperandKind::Capability)),"Linkage");
	m_operandNames.emplaceUnique(Hash64(6u, static_cast<unsigned int>(OperandKind::Capability)),"Kernel");
	m_operandNames.emplaceUnique(Hash64(7u, static_cast<unsigned int>(OperandKind::Capability)),"Vector16");
	m_operandNames.emplaceUnique(Hash64(8u, static_cast<unsigned int>(OperandKind::Capability)),"Float16Buffer");
	m_operandNames.emplaceUnique(Hash64(9u, static_cast<unsigned int>(OperandKind::Capability)),"Float16");
	m_operandNames.emplaceUnique(Hash64(10u, static_cast<unsigned int>(OperandKind::Capability)),"Float64");
	m_operandNames.emplaceUnique(Hash64(11u, static_cast<unsigned int>(OperandKind::Capability)),"Int64");
	m_operandNames.emplaceUnique(Hash64(12u, static_cast<unsigned int>(OperandKind::Capability)),"Int64Atomics");
	m_operandNames.emplaceUnique(Hash64(13u, static_cast<unsigned int>(OperandKind::Capability)),"ImageBasic");
	m_operandNames.emplaceUnique(Hash64(14u, static_cast<unsigned int>(OperandKind::Capability)),"ImageReadWrite");
	m_operandNames.emplaceUnique(Hash64(15u, static_cast<unsigned int>(OperandKind::Capability)),"ImageMipmap");
	m_operandNames.emplaceUnique(Hash64(17u, static_cast<unsigned int>(OperandKind::Capability)),"Pipes");
	m_operandNames.emplaceUnique(Hash64(18u, static_cast<unsigned int>(OperandKind::Capability)),"Groups");
	m_operandNames.emplaceUnique(Hash64(19u, static_cast<unsigned int>(OperandKind::Capability)),"DeviceEnqueue");
	m_operandNames.emplaceUnique(Hash64(20u, static_cast<unsigned int>(OperandKind::Capability)),"LiteralSampler");
	m_operandNames.emplaceUnique(Hash64(21u, static_cast<unsigned int>(OperandKind::Capability)),"AtomicStorage");
	m_operandNames.emplaceUnique(Hash64(22u, static_cast<unsigned int>(OperandKind::Capability)),"Int16");
	m_operandNames.emplaceUnique(Hash64(23u, static_cast<unsigned int>(OperandKind::Capability)),"TessellationPointSize");
	m_operandNames.emplaceUnique(Hash64(24u, static_cast<unsigned int>(OperandKind::Capability)),"GeometryPointSize");
	m_operandNames.emplaceUnique(Hash64(25u, static_cast<unsigned int>(OperandKind::Capability)),"ImageGatherExtended");
	m_operandNames.emplaceUnique(Hash64(27u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageMultisample");
	m_operandNames.emplaceUnique(Hash64(28u, static_cast<unsigned int>(OperandKind::Capability)),"UniformBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(29u, static_cast<unsigned int>(OperandKind::Capability)),"SampledImageArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(30u, static_cast<unsigned int>(OperandKind::Capability)),"StorageBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(31u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(32u, static_cast<unsigned int>(OperandKind::Capability)),"ClipDistance");
	m_operandNames.emplaceUnique(Hash64(33u, static_cast<unsigned int>(OperandKind::Capability)),"CullDistance");
	m_operandNames.emplaceUnique(Hash64(34u, static_cast<unsigned int>(OperandKind::Capability)),"ImageCubeArray");
	m_operandNames.emplaceUnique(Hash64(35u, static_cast<unsigned int>(OperandKind::Capability)),"SampleRateShading");
	m_operandNames.emplaceUnique(Hash64(36u, static_cast<unsigned int>(OperandKind::Capability)),"ImageRect");
	m_operandNames.emplaceUnique(Hash64(37u, static_cast<unsigned int>(OperandKind::Capability)),"SampledRect");
	m_operandNames.emplaceUnique(Hash64(38u, static_cast<unsigned int>(OperandKind::Capability)),"GenericPointer");
	m_operandNames.emplaceUnique(Hash64(39u, static_cast<unsigned int>(OperandKind::Capability)),"Int8");
	m_operandNames.emplaceUnique(Hash64(40u, static_cast<unsigned int>(OperandKind::Capability)),"InputAttachment");
	m_operandNames.emplaceUnique(Hash64(41u, static_cast<unsigned int>(OperandKind::Capability)),"SparseResidency");
	m_operandNames.emplaceUnique(Hash64(42u, static_cast<unsigned int>(OperandKind::Capability)),"MinLod");
	m_operandNames.emplaceUnique(Hash64(43u, static_cast<unsigned int>(OperandKind::Capability)),"Sampled1D");
	m_operandNames.emplaceUnique(Hash64(44u, static_cast<unsigned int>(OperandKind::Capability)),"Image1D");
	m_operandNames.emplaceUnique(Hash64(45u, static_cast<unsigned int>(OperandKind::Capability)),"SampledCubeArray");
	m_operandNames.emplaceUnique(Hash64(46u, static_cast<unsigned int>(OperandKind::Capability)),"SampledBuffer");
	m_operandNames.emplaceUnique(Hash64(47u, static_cast<unsigned int>(OperandKind::Capability)),"ImageBuffer");
	m_operandNames.emplaceUnique(Hash64(48u, static_cast<unsigned int>(OperandKind::Capability)),"ImageMSArray");
	m_operandNames.emplaceUnique(Hash64(49u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageExtendedFormats");
	m_operandNames.emplaceUnique(Hash64(50u, static_cast<unsigned int>(OperandKind::Capability)),"ImageQuery");
	m_operandNames.emplaceUnique(Hash64(51u, static_cast<unsigned int>(OperandKind::Capability)),"DerivativeControl");
	m_operandNames.emplaceUnique(Hash64(52u, static_cast<unsigned int>(OperandKind::Capability)),"InterpolationFunction");
	m_operandNames.emplaceUnique(Hash64(53u, static_cast<unsigned int>(OperandKind::Capability)),"TransformFeedback");
	m_operandNames.emplaceUnique(Hash64(54u, static_cast<unsigned int>(OperandKind::Capability)),"GeometryStreams");
	m_operandNames.emplaceUnique(Hash64(55u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageReadWithoutFormat");
	m_operandNames.emplaceUnique(Hash64(56u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageWriteWithoutFormat");
	m_operandNames.emplaceUnique(Hash64(57u, static_cast<unsigned int>(OperandKind::Capability)),"MultiViewport");
	m_operandNames.emplaceUnique(Hash64(58u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupDispatch");
	m_operandNames.emplaceUnique(Hash64(59u, static_cast<unsigned int>(OperandKind::Capability)),"NamedBarrier");
	m_operandNames.emplaceUnique(Hash64(60u, static_cast<unsigned int>(OperandKind::Capability)),"PipeStorage");
	m_operandNames.emplaceUnique(Hash64(61u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniform");
	m_operandNames.emplaceUnique(Hash64(62u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformVote");
	m_operandNames.emplaceUnique(Hash64(63u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformArithmetic");
	m_operandNames.emplaceUnique(Hash64(64u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformBallot");
	m_operandNames.emplaceUnique(Hash64(65u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformShuffle");
	m_operandNames.emplaceUnique(Hash64(66u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformShuffleRelative");
	m_operandNames.emplaceUnique(Hash64(67u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformClustered");
	m_operandNames.emplaceUnique(Hash64(68u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformQuad");
	m_operandNames.emplaceUnique(Hash64(69u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderLayer");
	m_operandNames.emplaceUnique(Hash64(70u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderViewportIndex");
	m_operandNames.emplaceUnique(Hash64(4423u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupBallotKHR");
	m_operandNames.emplaceUnique(Hash64(4427u, static_cast<unsigned int>(OperandKind::Capability)),"DrawParameters");
	m_operandNames.emplaceUnique(Hash64(4431u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupVoteKHR");
	m_operandNames.emplaceUnique(Hash64(4433u, static_cast<unsigned int>(OperandKind::Capability)),"StorageBuffer16BitAccess");
	m_operandNames.emplaceUnique(Hash64(4433u, static_cast<unsigned int>(OperandKind::Capability)),"StorageUniformBufferBlock16");
	m_operandNames.emplaceUnique(Hash64(4434u, static_cast<unsigned int>(OperandKind::Capability)),"UniformAndStorageBuffer16BitAccess");
	m_operandNames.emplaceUnique(Hash64(4434u, static_cast<unsigned int>(OperandKind::Capability)),"StorageUniform16");
	m_operandNames.emplaceUnique(Hash64(4435u, static_cast<unsigned int>(OperandKind::Capability)),"StoragePushConstant16");
	m_operandNames.emplaceUnique(Hash64(4436u, static_cast<unsigned int>(OperandKind::Capability)),"StorageInputOutput16");
	m_operandNames.emplaceUnique(Hash64(4437u, static_cast<unsigned int>(OperandKind::Capability)),"DeviceGroup");
	m_operandNames.emplaceUnique(Hash64(4439u, static_cast<unsigned int>(OperandKind::Capability)),"MultiView");
	m_operandNames.emplaceUnique(Hash64(4441u, static_cast<unsigned int>(OperandKind::Capability)),"VariablePointersStorageBuffer");
	m_operandNames.emplaceUnique(Hash64(4442u, static_cast<unsigned int>(OperandKind::Capability)),"VariablePointers");
	m_operandNames.emplaceUnique(Hash64(4445u, static_cast<unsigned int>(OperandKind::Capability)),"AtomicStorageOps");
	m_operandNames.emplaceUnique(Hash64(4447u, static_cast<unsigned int>(OperandKind::Capability)),"SampleMaskPostDepthCoverage");
	m_operandNames.emplaceUnique(Hash64(4448u, static_cast<unsigned int>(OperandKind::Capability)),"StorageBuffer8BitAccess");
	m_operandNames.emplaceUnique(Hash64(4449u, static_cast<unsigned int>(OperandKind::Capability)),"UniformAndStorageBuffer8BitAccess");
	m_operandNames.emplaceUnique(Hash64(4450u, static_cast<unsigned int>(OperandKind::Capability)),"StoragePushConstant8");
	m_operandNames.emplaceUnique(Hash64(4464u, static_cast<unsigned int>(OperandKind::Capability)),"DenormPreserve");
	m_operandNames.emplaceUnique(Hash64(4465u, static_cast<unsigned int>(OperandKind::Capability)),"DenormFlushToZero");
	m_operandNames.emplaceUnique(Hash64(4466u, static_cast<unsigned int>(OperandKind::Capability)),"SignedZeroInfNanPreserve");
	m_operandNames.emplaceUnique(Hash64(4467u, static_cast<unsigned int>(OperandKind::Capability)),"RoundingModeRTE");
	m_operandNames.emplaceUnique(Hash64(4468u, static_cast<unsigned int>(OperandKind::Capability)),"RoundingModeRTZ");
	m_operandNames.emplaceUnique(Hash64(4471u, static_cast<unsigned int>(OperandKind::Capability)),"RayQueryProvisionalKHR");
	m_operandNames.emplaceUnique(Hash64(4478u, static_cast<unsigned int>(OperandKind::Capability)),"RayTraversalPrimitiveCullingProvisionalKHR");
	m_operandNames.emplaceUnique(Hash64(5008u, static_cast<unsigned int>(OperandKind::Capability)),"Float16ImageAMD");
	m_operandNames.emplaceUnique(Hash64(5009u, static_cast<unsigned int>(OperandKind::Capability)),"ImageGatherBiasLodAMD");
	m_operandNames.emplaceUnique(Hash64(5010u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentMaskAMD");
	m_operandNames.emplaceUnique(Hash64(5013u, static_cast<unsigned int>(OperandKind::Capability)),"StencilExportEXT");
	m_operandNames.emplaceUnique(Hash64(5015u, static_cast<unsigned int>(OperandKind::Capability)),"ImageReadWriteLodAMD");
	m_operandNames.emplaceUnique(Hash64(5055u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderClockKHR");
	m_operandNames.emplaceUnique(Hash64(5249u, static_cast<unsigned int>(OperandKind::Capability)),"SampleMaskOverrideCoverageNV");
	m_operandNames.emplaceUnique(Hash64(5251u, static_cast<unsigned int>(OperandKind::Capability)),"GeometryShaderPassthroughNV");
	m_operandNames.emplaceUnique(Hash64(5254u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderViewportIndexLayerEXT");
	m_operandNames.emplaceUnique(Hash64(5254u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderViewportIndexLayerNV");
	m_operandNames.emplaceUnique(Hash64(5255u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderViewportMaskNV");
	m_operandNames.emplaceUnique(Hash64(5259u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderStereoViewNV");
	m_operandNames.emplaceUnique(Hash64(5260u, static_cast<unsigned int>(OperandKind::Capability)),"PerViewAttributesNV");
	m_operandNames.emplaceUnique(Hash64(5265u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentFullyCoveredEXT");
	m_operandNames.emplaceUnique(Hash64(5266u, static_cast<unsigned int>(OperandKind::Capability)),"MeshShadingNV");
	m_operandNames.emplaceUnique(Hash64(5282u, static_cast<unsigned int>(OperandKind::Capability)),"ImageFootprintNV");
	m_operandNames.emplaceUnique(Hash64(5284u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentBarycentricNV");
	m_operandNames.emplaceUnique(Hash64(5288u, static_cast<unsigned int>(OperandKind::Capability)),"ComputeDerivativeGroupQuadsNV");
	m_operandNames.emplaceUnique(Hash64(5291u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentDensityEXT");
	m_operandNames.emplaceUnique(Hash64(5291u, static_cast<unsigned int>(OperandKind::Capability)),"ShadingRateNV");
	m_operandNames.emplaceUnique(Hash64(5297u, static_cast<unsigned int>(OperandKind::Capability)),"GroupNonUniformPartitionedNV");
	m_operandNames.emplaceUnique(Hash64(5301u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderNonUniform");
	m_operandNames.emplaceUnique(Hash64(5301u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderNonUniformEXT");
	m_operandNames.emplaceUnique(Hash64(5302u, static_cast<unsigned int>(OperandKind::Capability)),"RuntimeDescriptorArray");
	m_operandNames.emplaceUnique(Hash64(5302u, static_cast<unsigned int>(OperandKind::Capability)),"RuntimeDescriptorArrayEXT");
	m_operandNames.emplaceUnique(Hash64(5303u, static_cast<unsigned int>(OperandKind::Capability)),"InputAttachmentArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(5303u, static_cast<unsigned int>(OperandKind::Capability)),"InputAttachmentArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5304u, static_cast<unsigned int>(OperandKind::Capability)),"UniformTexelBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(5304u, static_cast<unsigned int>(OperandKind::Capability)),"UniformTexelBufferArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5305u, static_cast<unsigned int>(OperandKind::Capability)),"StorageTexelBufferArrayDynamicIndexing");
	m_operandNames.emplaceUnique(Hash64(5305u, static_cast<unsigned int>(OperandKind::Capability)),"StorageTexelBufferArrayDynamicIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5306u, static_cast<unsigned int>(OperandKind::Capability)),"UniformBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5306u, static_cast<unsigned int>(OperandKind::Capability)),"UniformBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5307u, static_cast<unsigned int>(OperandKind::Capability)),"SampledImageArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5307u, static_cast<unsigned int>(OperandKind::Capability)),"SampledImageArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5308u, static_cast<unsigned int>(OperandKind::Capability)),"StorageBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5308u, static_cast<unsigned int>(OperandKind::Capability)),"StorageBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5309u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5309u, static_cast<unsigned int>(OperandKind::Capability)),"StorageImageArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5310u, static_cast<unsigned int>(OperandKind::Capability)),"InputAttachmentArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5310u, static_cast<unsigned int>(OperandKind::Capability)),"InputAttachmentArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5311u, static_cast<unsigned int>(OperandKind::Capability)),"UniformTexelBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5311u, static_cast<unsigned int>(OperandKind::Capability)),"UniformTexelBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5312u, static_cast<unsigned int>(OperandKind::Capability)),"StorageTexelBufferArrayNonUniformIndexing");
	m_operandNames.emplaceUnique(Hash64(5312u, static_cast<unsigned int>(OperandKind::Capability)),"StorageTexelBufferArrayNonUniformIndexingEXT");
	m_operandNames.emplaceUnique(Hash64(5340u, static_cast<unsigned int>(OperandKind::Capability)),"RayTracingNV");
	m_operandNames.emplaceUnique(Hash64(5345u, static_cast<unsigned int>(OperandKind::Capability)),"VulkanMemoryModel");
	m_operandNames.emplaceUnique(Hash64(5345u, static_cast<unsigned int>(OperandKind::Capability)),"VulkanMemoryModelKHR");
	m_operandNames.emplaceUnique(Hash64(5346u, static_cast<unsigned int>(OperandKind::Capability)),"VulkanMemoryModelDeviceScope");
	m_operandNames.emplaceUnique(Hash64(5346u, static_cast<unsigned int>(OperandKind::Capability)),"VulkanMemoryModelDeviceScopeKHR");
	m_operandNames.emplaceUnique(Hash64(5347u, static_cast<unsigned int>(OperandKind::Capability)),"PhysicalStorageBufferAddresses");
	m_operandNames.emplaceUnique(Hash64(5347u, static_cast<unsigned int>(OperandKind::Capability)),"PhysicalStorageBufferAddressesEXT");
	m_operandNames.emplaceUnique(Hash64(5350u, static_cast<unsigned int>(OperandKind::Capability)),"ComputeDerivativeGroupLinearNV");
	m_operandNames.emplaceUnique(Hash64(5353u, static_cast<unsigned int>(OperandKind::Capability)),"RayTracingProvisionalKHR");
	m_operandNames.emplaceUnique(Hash64(5357u, static_cast<unsigned int>(OperandKind::Capability)),"CooperativeMatrixNV");
	m_operandNames.emplaceUnique(Hash64(5363u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentShaderSampleInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(5372u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentShaderShadingRateInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(5373u, static_cast<unsigned int>(OperandKind::Capability)),"ShaderSMBuiltinsNV");
	m_operandNames.emplaceUnique(Hash64(5378u, static_cast<unsigned int>(OperandKind::Capability)),"FragmentShaderPixelInterlockEXT");
	m_operandNames.emplaceUnique(Hash64(5379u, static_cast<unsigned int>(OperandKind::Capability)),"DemoteToHelperInvocationEXT");
	m_operandNames.emplaceUnique(Hash64(5568u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupShuffleINTEL");
	m_operandNames.emplaceUnique(Hash64(5569u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupBufferBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(5570u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupImageBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(5579u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupImageMediaBlockIOINTEL");
	m_operandNames.emplaceUnique(Hash64(5584u, static_cast<unsigned int>(OperandKind::Capability)),"IntegerFunctions2INTEL");
	m_operandNames.emplaceUnique(Hash64(5603u, static_cast<unsigned int>(OperandKind::Capability)),"FunctionPointersINTEL");
	m_operandNames.emplaceUnique(Hash64(5604u, static_cast<unsigned int>(OperandKind::Capability)),"IndirectReferencesINTEL");
	m_operandNames.emplaceUnique(Hash64(5696u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupAvcMotionEstimationINTEL");
	m_operandNames.emplaceUnique(Hash64(5697u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupAvcMotionEstimationIntraINTEL");
	m_operandNames.emplaceUnique(Hash64(5698u, static_cast<unsigned int>(OperandKind::Capability)),"SubgroupAvcMotionEstimationChromaINTEL");
	m_operandNames.emplaceUnique(Hash64(5824u, static_cast<unsigned int>(OperandKind::Capability)),"FPGAMemoryAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(5886u, static_cast<unsigned int>(OperandKind::Capability)),"UnstructuredLoopControlsINTEL");
	m_operandNames.emplaceUnique(Hash64(5888u, static_cast<unsigned int>(OperandKind::Capability)),"FPGALoopControlsINTEL");
	m_operandNames.emplaceUnique(Hash64(5892u, static_cast<unsigned int>(OperandKind::Capability)),"KernelAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(5897u, static_cast<unsigned int>(OperandKind::Capability)),"FPGAKernelAttributesINTEL");
	m_operandNames.emplaceUnique(Hash64(5945u, static_cast<unsigned int>(OperandKind::Capability)),"BlockingPipesINTEL");
	m_operandNames.emplaceUnique(Hash64(5948u, static_cast<unsigned int>(OperandKind::Capability)),"FPGARegINTEL");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::RayQueryIntersection)),"RayQueryCandidateIntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::RayQueryIntersection)),"RayQueryCommittedIntersectionKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::RayQueryCommittedIntersectionType)),"RayQueryCommittedIntersectionNoneKHR");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::RayQueryCommittedIntersectionType)),"RayQueryCommittedIntersectionTriangleKHR");
	m_operandNames.emplaceUnique(Hash64(2u, static_cast<unsigned int>(OperandKind::RayQueryCommittedIntersectionType)),"RayQueryCommittedIntersectionGeneratedKHR");
	m_operandNames.emplaceUnique(Hash64(0u, static_cast<unsigned int>(OperandKind::RayQueryCandidateIntersectionType)),"RayQueryCandidateIntersectionTriangleKHR");
	m_operandNames.emplaceUnique(Hash64(1u, static_cast<unsigned int>(OperandKind::RayQueryCandidateIntersectionType)),"RayQueryCandidateIntersectionAABBKHR");
};
const Grammar::Instruction* Grammar::getInfo(unsigned int _opcode, Extension _extension) const
{
	return m_instructions.get(Hash64(_opcode, static_cast<unsigned int>(_extension)));
};
const char* Grammar::getOperandName(OperandKind _kind, unsigned int _literalValue) const
{
	const char** name = m_operandNames.get(Hash64(_literalValue, static_cast<unsigned int>(_kind)));
	return name == nullptr ? nullptr : *name;
};
