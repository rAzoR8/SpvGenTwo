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
		Instruction* opSAbs(Instruction* _pSInt) { return scalarOrIntVec1(glslstd450::Op::SAbs, _pSInt, Sign::Signed); }

		Instruction* opFSign(Instruction* _pFloat) { return scalarOrFloatVec1(glslstd450::Op::FSign, _pFloat); }
		Instruction* opSSign(Instruction* _pSInt) { return scalarOrIntVec1(glslstd450::Op::SSign, _pSInt, Sign::Signed); }

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

		// opModf DEPRECATED
		Instruction* opModfStruct(Instruction* _pFloat);

		Instruction* opFMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::FMin, _pX, _pY); }
		Instruction* opUMin(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::UMin, _pX, _pY, Sign::Unsigned); }
		Instruction* opSMin(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::SMin, _pX, _pY, Sign::Signed); }

		Instruction* opFMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::FMax, _pX, _pY); }
		Instruction* opUMax(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::UMax, _pX, _pY, Sign::Unsigned); }
		Instruction* opSMax(Instruction* _pX, Instruction* _pY) { return scalarOrIntVec2(glslstd450::Op::SMax, _pX, _pY, Sign::Signed); }

		Instruction* opFClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrFloatVec3(glslstd450::Op::FClamp, _pX, _pMin, _pMax); }
		Instruction* opUClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrIntVec3(glslstd450::Op::UClamp, _pX, _pMin, _pMax, Sign::Unsigned); }
		Instruction* opSClamp(Instruction* _pX, Instruction* _pMin, Instruction* _pMax) { return scalarOrIntVec3(glslstd450::Op::SClamp, _pX, _pMin, _pMax, Sign::Signed); }

		Instruction* opFMix(Instruction* _pX, Instruction* _pY, Instruction* _pA) { return scalarOrFloatVec3(glslstd450::Op::FMix, _pX, _pY, _pA); }
		
		// IMix removed in v0.99, Revision 3
		
		Instruction* opStep(Instruction* _pEdge, Instruction* _pX) { return scalarOrFloatVec2(glslstd450::Op::Step, _pEdge, _pX); }
		Instruction* opSmoothStep(Instruction* _pEdge0, Instruction* _pEdge1, Instruction* _pX) { return scalarOrFloatVec3(glslstd450::Op::SmoothStep, _pEdge0, _pEdge1, _pX); }
		Instruction* opFma(Instruction* _pA, Instruction* _pB, Instruction* _pC) { return scalarOrFloatVec3(glslstd450::Op::Fma, _pA, _pB, _pC); }

		// Frexp DEPRECATED
		Instruction* opFrexpStruct(Instruction* _pFloat);		
		Instruction* opLdexp(Instruction* _pFloatX, Instruction* _pIntExp);

		Instruction* opPackSnorm4x8(Instruction* _pFloatVec4) { return packNorm(glslstd450::Op::PackSnorm4x8, _pFloatVec4, 4u); }
		Instruction* opPackUnorm4x8(Instruction* _pFloatVec4) { return packNorm(glslstd450::Op::PackUnorm4x8, _pFloatVec4, 4u); }
		Instruction* opPackSnorm2x16(Instruction* _pFloatVec2) { return packNorm(glslstd450::Op::PackSnorm2x16, _pFloatVec2, 2u); }
		Instruction* opPackUnorm2x16(Instruction* _pFloatVec2) { return packNorm(glslstd450::Op::PackUnorm2x16, _pFloatVec2, 2u); }
		Instruction* opPackHalf2x16(Instruction* _pFloatVec2) { return packNorm(glslstd450::Op::PackHalf2x16, _pFloatVec2, 2u); }
		Instruction* opPackDouble2x32(Instruction* _pIntVec2);

		Instruction* opUnpackSnorm4x8(Instruction* _pInt32) { return unpackNorm(glslstd450::Op::UnpackSnorm4x8, _pInt32, 4u); }
		Instruction* opUnpackUnorm4x8(Instruction* _pInt32) { return unpackNorm(glslstd450::Op::UnpackUnorm4x8, _pInt32, 4u); }
		Instruction* opUnpackSnorm2x16(Instruction* _pInt32) { return unpackNorm(glslstd450::Op::UnpackSnorm2x16, _pInt32, 2u); }
		Instruction* opUnpackUnorm2x16(Instruction* _pInt32) { return unpackNorm(glslstd450::Op::UnpackUnorm2x16, _pInt32, 2u); }
		Instruction* opUnpackHalf2x16(Instruction* _pInt32) { return unpackNorm(glslstd450::Op::UnpackHalf2x16, _pInt32, 2u); }
		Instruction* opUnpackDouble2x32(Instruction* _pDouble);

		Instruction* opLength(Instruction* _pX);
		Instruction* opDistance(Instruction* _pP1, Instruction* _pP2);
		Instruction* opCross(Instruction* _pX, Instruction* _pY);
		Instruction* opNormalize(Instruction* _pX) { return scalarOrFloatVec1(glslstd450::Op::Normalize, _pX); }
		Instruction* opFaceForward(Instruction* _pN, Instruction* _pI, Instruction* _pNref) { return scalarOrFloatVec3(glslstd450::Op::FaceForward, _pN, _pI, _pNref); }
		Instruction* opReflect(Instruction* _pI, Instruction* _pN) { return scalarOrFloatVec2(glslstd450::Op::Reflect, _pI, _pN); }
		Instruction* opRefract(Instruction* _pIvec, Instruction* _pNvec, Instruction* _pEtaFloat);
		
		Instruction* opFindILsb(Instruction* _pIntVec) { return scalarOrIntVec1(glslstd450::Op::FindILsb, _pIntVec, Sign::Any); }
		Instruction* opFindSMsb(Instruction* _pIntVec) { return scalarOrIntVec1(glslstd450::Op::FindSMsb, _pIntVec, Sign::Any); }
		Instruction* opFindUMsb(Instruction* _pIntVec) { return scalarOrIntVec1(glslstd450::Op::FindUMsb, _pIntVec, Sign::Any); }

		Instruction* opInterpolateAtCentroid(Instruction* _pInterpolant) { return interpolate(glslstd450::Op::InterpolateAtCentroid, _pInterpolant, nullptr); }
		Instruction* opInterpolateAtSample(Instruction* _pInterpolant, Instruction* _pSampleInt) { return interpolate(glslstd450::Op::InterpolateAtSample, _pInterpolant, _pSampleInt); }
		Instruction* opInterpolateAtOffset(Instruction* _pInterpolant, Instruction* _pOffsetVec2) { return interpolate(glslstd450::Op::InterpolateAtOffset, _pInterpolant, _pOffsetVec2); }

		Instruction* opNMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::NMin, _pX, _pY); }
		Instruction* opNMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(glslstd450::Op::NMax, _pX, _pY); }
		Instruction* opNClamp(Instruction* _pX, Instruction* _pMinVal, Instruction* _pMaxVal) { return scalarOrFloatVec3(glslstd450::Op::NClamp, _pX, _pMinVal, _pMaxVal); }

	private:
		Instruction* scalarOrFloatVec1(glslstd450::Op _op, Instruction* _pFloat, const bool _no64Bit = false, Instruction* _pResultType = nullptr);
		Instruction* scalarOrFloatVec2(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pResultType = nullptr);
		Instruction* scalarOrFloatVec3(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Instruction* _pResultType = nullptr);

		Instruction* scalarOrIntVec1(glslstd450::Op _op, Instruction* _pInt, Sign _sign, Instruction* _pResultType = nullptr);
		Instruction* scalarOrIntVec2(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Sign _sign, Instruction* _pResultType = nullptr);
		Instruction* scalarOrIntVec3(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Sign _sign, Instruction* _pResultType = nullptr);

		Instruction* packNorm(glslstd450::Op _op, Instruction* _pFloatVec, unsigned int _vecComponents);
		Instruction* unpackNorm(glslstd450::Op _op, Instruction* _pIntScalar, unsigned int _vecComponents);

		Instruction* interpolate(glslstd450::Op _op, Instruction* _pInterpolant, Instruction* _pSampleOffset);
	};

	// namespace for shortening extension names
	namespace ext
	{
		using GLSL = GLSL450Intruction;
	} // !ext
} // !spvgentwo