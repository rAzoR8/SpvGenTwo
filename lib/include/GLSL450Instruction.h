#pragma once

#include "Instruction.h"

namespace spvgentwo
{
	namespace extinstr
	{
		#include  <vulkan/GLSL.std.450.h>
	} // !extinstr

	class GLSL450Intruction : protected Instruction
	{
	public:
		using Instruction::Instruction;

		static constexpr const char* ExtName = "GLSL.std.450";

		Instruction* opRound(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Round, _pFloat); }
		Instruction* opRoundEven(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450RoundEven, _pFloat); }
		Instruction* opTrund(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Trunc, _pFloat); }
		Instruction* opFAbs(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450FAbs, _pFloat); }

		Instruction* opSAbs(Instruction* _pSInt) { return scalarOrSIntVec1(extinstr::GLSLstd450::GLSLstd450SAbs, _pSInt); }
		Instruction* opFSign(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450FSign, _pFloat); }
		Instruction* opSSign(Instruction* _pSInt) { return scalarOrSIntVec1(extinstr::GLSLstd450::GLSLstd450SSign, _pSInt); }

		Instruction* opFloor(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Floor, _pFloat); }
		Instruction* opCeil(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Ceil, _pFloat); }
		Instruction* opFract(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Fract, _pFloat); }

		// todo: only 16 and 32 bit floats
		Instruction* opRadians(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Radians, _pFloat, true); } 
		Instruction* opDegrees(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Degrees, _pFloat, true); }
		Instruction* opSin(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Sin, _pFloat, true); }
		Instruction* opCos(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Cos, _pFloat, true); }
		Instruction* opTan(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Cos, _pFloat, true); }
		Instruction* opASin(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Asin, _pFloat, true); }
		Instruction* opACos(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Acos, _pFloat, true); }
		Instruction* opATan(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Atan, _pFloat, true); }
		Instruction* opSinh(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Sinh, _pFloat, true); }
		Instruction* opCosh(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Cosh, _pFloat, true); }
		Instruction* opTanh(Instruction* _pYOverX) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Tanh, _pYOverX, true); }
		Instruction* opAsinh(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Asinh, _pFloat, true); }
		Instruction* opAcosh(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Acosh, _pFloat, true); }
		Instruction* opAtanh(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Atanh, _pFloat, true); }

		Instruction* opAtan2(Instruction* _pY, Instruction* _pX) { return scalarOrFloatVec2(extinstr::GLSLstd450::GLSLstd450Atan2, _pY, _pX); }
		Instruction* opPow(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(extinstr::GLSLstd450::GLSLstd450Pow, _pX, _pY); }

		Instruction* opExp(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Exp, _pFloat, true); }
		Instruction* opLog(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Log, _pFloat, true); }
		Instruction* opExp2(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Exp2, _pFloat, true); }
		Instruction* opLog2(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Log2, _pFloat, true); }

		Instruction* opSqrt(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450Sqrt, _pFloat); }
		Instruction* opInverseSqrt(Instruction* _pFloat) { return scalarOrFloatVec1(extinstr::GLSLstd450::GLSLstd450InverseSqrt, _pFloat); }

		Instruction* opDeterminant(Instruction* _pMatrix);
		Instruction* opMatrixInverse(Instruction* _pMatrix);

		// Modf
		// ModfStruct

		Instruction* opFMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(extinstr::GLSLstd450::GLSLstd450FMin, _pX, _pY); }
		//Instruction* opUMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatUInt2(extinstr::GLSLstd450::GLSLstd450FMin, _pX, _pY); }
		//Instruction* opSMin(Instruction* _pX, Instruction* _pY) { return scalarOrFloatSInt2(extinstr::GLSLstd450::GLSLstd450FMin, _pX, _pY); }

		Instruction* opFMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatVec2(extinstr::GLSLstd450::GLSLstd450FMax, _pX, _pY); }
		//Instruction* opUMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatUInt2(extinstr::GLSLstd450::GLSLstd450FMin, _pX, _pY); }
		//Instruction* opSMax(Instruction* _pX, Instruction* _pY) { return scalarOrFloatSInt2(extinstr::GLSLstd450::GLSLstd450FMin, _pX, _pY); }

		Instruction* opCross(Instruction* _pLeft, Instruction* _pRight);

	private:
		Instruction* scalarOrFloatVec1(const extinstr::GLSLstd450 _op, Instruction* _pFloat, const bool _no64Bit = false);
		Instruction* scalarOrFloatVec2(const extinstr::GLSLstd450 _op, Instruction* _pOp1, Instruction* _pOp2);

		Instruction* scalarOrSIntVec1(const extinstr::GLSLstd450 _op, Instruction* _pSInt);

	};

	// namespace for shortening extension names
	namespace ext
	{
		using GLSL = GLSL450Intruction;
	} // !ext
} // !spvgentwo