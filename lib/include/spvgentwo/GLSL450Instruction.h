#pragma once

#include "Instruction.h"
#include "Glsl.h"

namespace spvgentwo
{
	class GLSL450Intruction : protected Instruction
	{
	public:
		using Instruction::Instruction;

		static constexpr const char* ExtName = "GLSL.std.450";

		Instruction* opRound(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Round, _pFloat); }
		Instruction* opRoundEven(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::RoundEven, _pFloat); }
		Instruction* opTrunc(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Trunc, _pFloat); }

		Instruction* opFAbs(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::FAbs, _pFloat); }
		Instruction* opSAbs(Instruction* _pSInt) { return scalarOrIntVec1(glslstd450::Op::SAbs, _pSInt, true); }

		Instruction* opFSign(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::FSign, _pFloat); }
		Instruction* opSSign(Instruction* _pSInt) { return scalarOrIntVec1(glslstd450::Op::SSign, _pSInt, true); }

		Instruction* opFloor(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Floor, _pFloat); }
		Instruction* opCeil(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Ceil, _pFloat); }
		Instruction* opFract(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Fract, _pFloat); }

		// todo: only 16 and 32 bit floats
		Instruction* opRadians(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Radians, _pFloat, true); } 
		Instruction* opDegrees(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Degrees, _pFloat, true); }
		Instruction* opSin(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Sin, _pFloat, true); }
		Instruction* opCos(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Cos, _pFloat, true); }
		Instruction* opTan(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Tan, _pFloat, true); }
		Instruction* opASin(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Asin, _pFloat, true); }
		Instruction* opACos(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Acos, _pFloat, true); }
		Instruction* opATan(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Atan, _pFloat, true); }
		Instruction* opSinh(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Sinh, _pFloat, true); }
		Instruction* opCosh(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Cosh, _pFloat, true); }
		Instruction* opTanh(Instruction* _pYOverX) { return scalarOrFloatVec1(glslstd450::Op::Tanh, _pYOverX, true); }
		Instruction* opAsinh(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Asinh, _pFloat, true); }
		Instruction* opAcosh(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Acosh, _pFloat, true); }
		Instruction* opAtanh(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Atanh, _pFloat, true); }

		Instruction* opAtan2(Instruction* _pY, Instruction* _pX) { return scalarOrFloatVec2(glslstd450::Op::Atan2, _pY, _pX); }
		Instruction* opPow(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::Pow, _pX, _pY); }

		Instruction* opExp(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Exp, _pFloat, true); }
		Instruction* opLog(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Log, _pFloat, true); }
		Instruction* opExp2(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Exp2, _pFloat, true); }
		Instruction* opLog2(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Log2, _pFloat, true); }

		Instruction* opSqrt(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::Sqrt, _pFloat); }
		Instruction* opInverseSqrt(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::InverseSqrt, _pFloat); }

		Instruction* opDeterminant(Instruction* _pMatrix);
		Instruction* opMatrixInverse(Instruction* _pMatrix);

		// Modf TODO
		// ModfStruct TODO

		Instruction* opFMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::FMin, _pX, _pY); }
		Instruction* opUMin(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::UMin, _pX, _pY, false); }
		Instruction* opSMin(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::SMin, _pX, _pY, true); }

		Instruction* opFMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::FMax, _pX, _pY); }
		Instruction* opUMax(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::UMax, _pX, _pY, false); }
		Instruction* opSMax(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::SMax, _pX, _pY, true); }

		Instruction* opFClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrFloatVec3(glslstd450::Op::FClamp, _pX, _pMin, _pMax); }
		Instruction* opUClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrIntVec3(glslstd450::Op::UClamp, _pX, _pMin, _pMax, false); }
		Instruction* opSClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrIntVec3(glslstd450::Op::SClamp, _pX, _pMin, _pMax, true); }

		Instruction* opFMix(Instruction* _pX, Instruction* _pY, Instruction* _pA) { return scalarOrFloatVec3(glslstd450::Op::FMix, _pX, _pY, _pA); }
		
		// IMix TODO
		
		Instruction* opStep(Instruction* _pEdge, Instruction* _pX) { return scalarOrFloatVec2(glslstd450::Op::Step, _pEdge, _pX); }
		Instruction* opSmoothStep(Instruction* _pEdge0, Instruction* _pEdge1, Instruction* _pX) { return scalarOrFloatVec3(glslstd450::Op::SmoothStep, _pEdge0, _pEdge1, _pX); }
		Instruction* opFma(Instruction* _pA, Instruction* _pB, Instruction* _pC) { return scalarOrFloatVec3(glslstd450::Op::Fma, _pA, _pB, _pC); }

		// Frexp TODO
		// FrexpStruct TODO
		// PackSnorm4x8 TODO
		// PackUnorm4x8 TODO
		// PackSnorm2x16 TODO
		// PackUnorm2x16 TODO
		// PackHalf2x16 TODO
		// PackDouble2x32 TODO
		// UnpackSnorm2x16 TODO
		// UnpackUnorm2x16 TODO
		// UnpackHalf2x16 TODO
		// UnpackSnorm4x8 TODO
		// UnpackUnorm4x8 TODO
		// UnpackDouble2x32 TODO

		Instruction* opLength(Instruction* _pX);
		Instruction* opDistance(Instruction* _pP1, Instruction* _pP2);
		Instruction* opCross(Instruction* _pX, Instruction* _pY);
		Instruction* opNormalize(Instruction* _pX) { return scalarOrFloatVec1(glslstd450::Op::Normalize, _pX); }
		Instruction* opFaceForward(Instruction* _pN, Instruction* _pI, Instruction* _pNref) { return scalarOrFloatVec3(glslstd450::Op::FaceForward, _pN, _pI, _pNref); }
		Instruction* opReflect(Instruction* _pI, Instruction* _pN) { return scalarOrFloatVec2(glslstd450::Op::Reflect, _pI, _pN); }
		Instruction* opRefract(Instruction* _pIvec, Instruction* _pNvec, Instruction* _pEtaFloat);
		
		// FindILsb TODO
		// FindSMsb TODO
		// FindUMsb TODO
		// InterpolateAtCentroid TODO
		// InterpolateAtSample TODO
		// InterpolateAtOffset TODO
		// NMin TODO
		// NMax TODO
		// NClamp TODO

	private:
		Instruction* scalarOrFloatVec1(const glslstd450::Op _op, Instruction* _pFloat, const bool _no64Bit = false);
		Instruction* scalarOrFloatVec2(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2);
		Instruction* scalarOrFloatVec3(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3);

		Instruction* scalarOrIntVec1(const glslstd450::Op _op, Instruction* _pSInt, const bool _signed);
		Instruction* scalarOrIntVec2(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, const bool _signed);
		Instruction* scalarOrIntVec3(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, const bool _signed);
	};

	// namespace for shortening extension names
	namespace ext
	{
		using GLSL = GLSL450Intruction;
	} // !ext
} // !spvgentwo