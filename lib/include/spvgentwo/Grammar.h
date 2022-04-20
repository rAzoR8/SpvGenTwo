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
			QuantizationModes=24u,
			FPOperationMode=25u,
			OverflowModes=26u,
			LinkageType=27u,
			AccessQualifier=28u,
			FunctionParameterAttribute=29u,
			Decoration=30u,
			BuiltIn=31u,
			Scope=32u,
			GroupOperation=33u,
			KernelEnqueueFlags=34u,
			Capability=35u,
			RayQueryIntersection=36u,
			RayQueryCommittedIntersectionType=37u,
			RayQueryCandidateIntersectionType=38u,
			PackedVectorFormat=39u,
			IdResultType=40u,
			IdResult=41u,
			IdMemorySemantics=42u,
			IdScope=43u,
			IdRef=44u,
			LiteralInteger=45u,
			LiteralString=46u,
			LiteralContextDependentNumber=47u,
			LiteralExtInstInteger=48u,
			LiteralSpecConstantOpInteger=49u,
			PairLiteralIntegerIdRef=50u,
			PairIdRefLiteralInteger=51u,
			PairIdRefIdRef=52u,
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
