// Auto generated - do not modify
#pragma once

#include "Vector.h"
#include "HashMap.h"
#include "Spv.h"

namespace spvgentwo
{
class Grammar
{
	enum class OperandCategory : unsigned short
	{
		BitEnum,
		ValueEnum,
		Id,
		Literal,
		Composite,
	};
	enum class OperandKind : unsigned short
	{
		ImageOperands,
		FPFastMathMode,
		SelectionControl,
		LoopControl,
		FunctionControl,
		MemorySemantics,
		MemoryAccess,
		KernelProfilingInfo,
		RayFlags,
		SourceLanguage,
		ExecutionModel,
		AddressingModel,
		MemoryModel,
		ExecutionMode,
		StorageClass,
		Dim,
		SamplerAddressingMode,
		SamplerFilterMode,
		ImageFormat,
		ImageChannelOrder,
		ImageChannelDataType,
		FPRoundingMode,
		LinkageType,
		AccessQualifier,
		FunctionParameterAttribute,
		Decoration,
		BuiltIn,
		Scope,
		GroupOperation,
		KernelEnqueueFlags,
		Capability,
		RayQueryIntersection,
		RayQueryCommittedIntersectionType,
		RayQueryCandidateIntersectionType,
		IdResultType,
		IdResult,
		IdMemorySemantics,
		IdScope,
		IdRef,
		LiteralInteger,
		LiteralString,
		LiteralContextDependentNumber,
		LiteralExtInstInteger,
		LiteralSpecConstantOpInteger,
		PairLiteralIntegerIdRef,
		PairIdRefLiteralInteger,
		PairIdRefIdRef,
	};
	enum class Quantifier
	{
		Optional,
		AnyCount
	};
	struct Operand
	{
		OperandKind kind;
		OperandCategory category;
		const char* name;
		Quantifier quantifier;
	};
	struct Instruction
	{
		const char* name;
		spv::Op opcode;
		Vector<Operand> operands;
		Vector<spv::Capability> capabilities;
		Vector<const char*> extensions;
		unsigned int version;
	};
	public:
		Grammar(IAllocator* _pAllocator);
	private:
		HashMap<spv::Op, Instruction> m_instructions;
};
} // spvgentwo
