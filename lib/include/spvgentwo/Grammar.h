// Auto generated - do not modify
#pragma once

#include "Vector.h"
#include "HashMap.h"
#include "Spv.h"

namespace spvgentwo
{
	class Grammar
{
		public:
		enum class Extension : unsigned short
		{
			Core = 0,
			Glsl = 1,
			OpenCl = 2,
		};
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
			FragmentShadingRate,
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
			FPDenormMode,
			FPOperationMode,
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
			ZeroOrOne, // zero or one
			ZeroOrAny, // zero or any
			One, // exactly once
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
			Vector<Operand> operands;
			Vector<spv::Capability> capabilities;
			Vector<spv::Extension> extensions;
			unsigned int version;
		};
		Grammar(IAllocator* _pAllocator);
		const Instruction* getInfo(unsigned int _opcode, Extension _extension = Extension::Core) const;
		const char* getOperandName(OperandKind _kind, unsigned int _literalValue) const;
		const Vector<Operand>* getOperandParameters(OperandKind _kind, unsigned int _literalValue) const;
		const Vector<Operand>* getOperandBases(OperandKind _kind) const;
	private:
		HashMap<Hash64, Instruction> m_instructions;
		HashMap<Hash64, const char*> m_operandNames;
		HashMap<Hash64, Vector<Operand>> m_operandParameters;
		HashMap<OperandKind, Vector<Operand>> m_operandBases;
	};
} // spvgentwo
