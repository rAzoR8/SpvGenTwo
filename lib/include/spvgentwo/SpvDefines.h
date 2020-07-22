#pragma once

#include "Spv.h"

namespace spvgentwo
{
	constexpr unsigned int makeGeneratorId(unsigned short _gen, unsigned short _ver) { return _gen << 16 | _ver; }
	constexpr unsigned int makeVersion(unsigned char _major, unsigned char _minor) { return _major << 16 | (_minor << 8); }
	constexpr unsigned char getMajorVersion(unsigned int _version) { return (_version & 0x00FF0000) >> 16; }
	constexpr unsigned char getMinorVersion(unsigned int _version) { return (_version & 0x0000FF00) >> 8; }

	// Sampled indicates whether or not this image will be accessed in combination with a sampler, and must be one of the following values:
	enum class SamplerImageAccess : unsigned int
	{
		Unknown = 0, // indicates this is only known at run time, not at compile time
		Sampled = 1, // indicates will be used with sampler
		Storage = 2  // indicates will be used without a sampler (a storage image)
	};

	enum class ConstantSamplerCoordMode : unsigned int
	{
		UnNormalized = 0,
		Normalized = 1
	};

	constexpr size_t wordCount(const decltype(sizeof(spv::Id)) _byteCount)
	{
		return (_byteCount / sizeof(spv::Id)) + (_byteCount % sizeof(spv::Id) != 0u ? 1u : 0u);
	}

	constexpr spv::Op getOperation(unsigned int _instrWord)
	{
		return static_cast<spv::Op>(_instrWord & spv::OpCodeMask);
	}

	constexpr unsigned int getOperandCount(unsigned int _instrWord)
	{
		return _instrWord >> spv::WordCountShift;
	}

	constexpr unsigned int makeOpCode(spv::Op _op, unsigned int _operandCount)
	{
		return (static_cast<unsigned int>(_op) & spv::OpCodeMask) | (_operandCount << spv::WordCountShift);
	}

	inline bool hasResultAndTypeId(const spv::Op _operation)
	{
		bool res = false, type = false;
		spv::HasResultAndType(_operation, &res, &type);
		return res && type;
	}

	// returns either spv::OpExecutionMode or spv::OpExecutionModeId based on input mode
	constexpr spv::Op getExecutionModeOp(const spv::ExecutionMode _mode)
	{
		switch (_mode)
		{
		case spv::ExecutionMode::SubgroupsPerWorkgroupId:
		case spv::ExecutionMode::LocalSizeId:
		case spv::ExecutionMode::LocalSizeHintId:
			return spv::Op::OpExecutionModeId;
		default:
			return spv::Op::OpExecutionMode;
		}
	}

	constexpr bool isTerminatorOp(const spv::Op _instr)
	{
		switch (_instr)
		{
		case spv::Op::OpBranch:
		case spv::Op::OpBranchConditional:
		case spv::Op::OpSwitch:
		case spv::Op::OpReturn:
		case spv::Op::OpReturnValue:
		case spv::Op::OpKill:
		case spv::Op::OpUnreachable:
			return true;
		default:
			return false;
		}
	}

	// Instructions that start "OpConstant" or "OpSpec"
	constexpr bool isSpecOrConstantOp(const spv::Op _instr)
	{
		return IsConstantOp(_instr) || IsSpecConstantOp(_instr);
	}

	enum class Sign
	{
		Signed = 1 << 0,
		Unsigned = 1 << 1,
		Any = Signed | Unsigned,
	};

	// get spv::Op::OpTypeFloat from spv::Op::OpFAdd etc (argument type), returns spv::Op::OpNop
	constexpr spv::Op getTypeFromOp(const spv::Op _op, Sign& _sign)
	{
		// this is not a complete match for all instructions, but for most that have variants for several types
		switch (_op)
		{
		case spv::Op::OpTypeFloat:
		case spv::Op::OpFAdd:
		case spv::Op::OpFConvert:
		case spv::Op::OpFDiv:
		case spv::Op::OpFMod:
		case spv::Op::OpFMul:
		case spv::Op::OpFNegate:
		case spv::Op::OpFOrdEqual:
		case spv::Op::OpFOrdGreaterThan:
		case spv::Op::OpFOrdGreaterThanEqual:
		case spv::Op::OpFOrdLessThan:
		case spv::Op::OpFOrdLessThanEqual:
		case spv::Op::OpFOrdNotEqual:
		case spv::Op::OpFRem:
		case spv::Op::OpFSub:
		case spv::Op::OpFUnordEqual:
		case spv::Op::OpFUnordGreaterThan:
		case spv::Op::OpFUnordGreaterThanEqual:
		case spv::Op::OpFUnordLessThan:
		case spv::Op::OpFUnordLessThanEqual:
		case spv::Op::OpFUnordNotEqual:
		case spv::Op::OpFwidth:
		case spv::Op::OpFwidthCoarse:
		case spv::Op::OpFwidthFine:
		case spv::Op::OpDPdx:
		case spv::Op::OpDPdy:
		case spv::Op::OpDPdxFine:
		case spv::Op::OpDPdyFine:
		case spv::Op::OpDPdxCoarse:
		case spv::Op::OpDPdyCoarse:

		case spv::Op::OpIsNan:
		case spv::Op::OpIsInf:
		case spv::Op::OpIsFinite:
		case spv::Op::OpIsNormal:
		case spv::Op::OpSignBitSet:
		case spv::Op::OpLessOrGreater:
		case spv::Op::OpOrdered:
		case spv::Op::OpUnordered:
		case spv::Op::OpConvertFToS:
		case spv::Op::OpConvertFToU:

			_sign = Sign::Any;
			return spv::Op::OpTypeFloat;

		case spv::Op::OpSConvert:
		case spv::Op::OpSDiv:
		case spv::Op::OpSGreaterThan:
		case spv::Op::OpSGreaterThanEqual:
		case spv::Op::OpSLessThan:
		case spv::Op::OpSLessThanEqual:
		case spv::Op::OpSMod:
		case spv::Op::OpSMulExtended:
		case spv::Op::OpSNegate:
		case spv::Op::OpSRem:
		case spv::Op::OpConvertSToF:
			_sign = Sign::Signed;
			return spv::Op::OpTypeInt;

		case spv::Op::OpTypeInt:
		case spv::Op::OpIAdd:
		case spv::Op::OpIAddCarry:
		case spv::Op::OpIAddSatINTEL:
		case spv::Op::OpIAverageINTEL:
		case spv::Op::OpIAverageRoundedINTEL:
		case spv::Op::OpIEqual:
		case spv::Op::OpINotEqual:
		case spv::Op::OpIMul:
		case spv::Op::OpIMul32x16INTEL:
		case spv::Op::OpISub:
		case spv::Op::OpISubBorrow:
		case spv::Op::OpISubSatINTEL:
		case spv::Op::OpNot:
		case spv::Op::OpShiftRightLogical:
		case spv::Op::OpShiftRightArithmetic:
		case spv::Op::OpShiftLeftLogical:
		case spv::Op::OpBitwiseOr:
		case spv::Op::OpBitwiseXor:
		case spv::Op::OpBitwiseAnd:
			_sign = Sign::Any;
			return spv::Op::OpTypeInt;

		case spv::Op::OpUAddSatINTEL:
		case spv::Op::OpUAverageINTEL:
		case spv::Op::OpUAverageRoundedINTEL:
		case spv::Op::OpUConvert:
		case spv::Op::OpUCountLeadingZerosINTEL:
		case spv::Op::OpUCountTrailingZerosINTEL:
		case spv::Op::OpUDiv:
		case spv::Op::OpUGreaterThan:
		case spv::Op::OpUGreaterThanEqual:
		case spv::Op::OpULessThan:
		case spv::Op::OpULessThanEqual:
		case spv::Op::OpUMod:
		case spv::Op::OpUMul32x16INTEL:
		case spv::Op::OpUMulExtended:
		case spv::Op::OpUSubSatINTEL:
		case spv::Op::OpConvertUToF:
			_sign = Sign::Unsigned;
			return spv::Op::OpTypeInt;

		case spv::Op::OpTypeBool:
		case spv::Op::OpLogicalEqual:
		case spv::Op::OpLogicalNotEqual:
		case spv::Op::OpLogicalOr:
		case spv::Op::OpLogicalAnd:
		case spv::Op::OpLogicalNot:
		case spv::Op::OpAny:
		case spv::Op::OpAll:

			_sign = Sign::Any;
			return spv::Op::OpTypeBool;

		default:
			_sign = Sign::Any;
			return spv::Op::OpNop;
		}
	}

	constexpr spv::Op getTypeFromOp(const spv::Op _op) { Sign sign = Sign::Any; return getTypeFromOp(_op, sign); }

	constexpr bool hasStringTerminator(unsigned int _word)
	{
		return (_word & 0x000000FFu) == 0u || (_word & 0x0000FF00) == 0u || (_word & 0x00FF0000) == 0u || (_word & 0xFF000000) == 0u;
	}
} //!spvgentwo