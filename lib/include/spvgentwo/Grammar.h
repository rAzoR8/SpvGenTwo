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
			ImageOperands=0u,
			FPFastMathMode=1u,
			SelectionControl=2u,
			LoopControl=3u,
			FunctionControl=4u,
			MemorySemantics=5u,
			MemoryAccess=6u,
			KernelProfilingInfo=7u,
			RayFlags=8u,
			FragmentShadingRate=9u,
			SourceLanguage=10u,
			ExecutionModel=11u,
			AddressingModel=12u,
			MemoryModel=13u,
			ExecutionMode=14u,
			StorageClass=15u,
			Dim=16u,
			SamplerAddressingMode=17u,
			SamplerFilterMode=18u,
			ImageFormat=19u,
			ImageChannelOrder=20u,
			ImageChannelDataType=21u,
			FPRoundingMode=22u,
			FPDenormMode=23u,
			FPOperationMode=24u,
			LinkageType=25u,
			AccessQualifier=26u,
			FunctionParameterAttribute=27u,
			Decoration=28u,
			BuiltIn=29u,
			Scope=30u,
			GroupOperation=31u,
			KernelEnqueueFlags=32u,
			Capability=33u,
			RayQueryIntersection=34u,
			RayQueryCommittedIntersectionType=35u,
			RayQueryCandidateIntersectionType=36u,
			IdResultType=37u,
			IdResult=38u,
			IdMemorySemantics=39u,
			IdScope=40u,
			IdRef=41u,
			LiteralInteger=42u,
			LiteralString=43u,
			LiteralContextDependentNumber=44u,
			LiteralExtInstInteger=45u,
			LiteralSpecConstantOpInteger=46u,
			PairLiteralIntegerIdRef=47u,
			PairIdRefLiteralInteger=48u,
			PairIdRefIdRef=49u,
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
		static bool hasOperandParameters(OperandKind _kind);
	private:
		HashMap<Hash64, Instruction> m_instructions;
		HashMap<Hash64, const char*> m_operandNames;
		HashMap<Hash64, Vector<Operand>> m_operandParameters;
		HashMap<OperandKind, Vector<Operand>> m_operandBases;
	};
} // spvgentwo
