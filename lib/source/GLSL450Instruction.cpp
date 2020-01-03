#include "spvgentwo/GLSL450Instruction.h"
#include "spvgentwo/Module.h"

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec1(const extinstr::GLSLstd450 _op, Instruction* _pFloat, const bool _no64Bit)
{
	Instruction* _pTypeInstr = _pFloat->getTypeInst();
	const Type* pType = _pTypeInstr->getType();

	if ((pType->isFloat() || pType->isVectorOfFloat()) && (_no64Bit ? pType->getBaseType().getFloatWidth() <= 32u : true))
	{
		return opExtInst(_pTypeInstr, ExtName, _op, _pFloat);
	}

	getModule()->logError("Operands of scalarOrFloatVec1 opeartion are not vector or scalar of float");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec2(const extinstr::GLSLstd450 _op, Instruction* _pOp1, Instruction* _pOp2)
{
	Instruction* returnType = _pOp1->getTypeInst();

	const Type* leftType = returnType->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *rightType == *rightType)
	{
		return opExtInst(returnType, ExtName, _op, _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrFloatVec2 opeartion are not vector or scalar of float");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec3(const extinstr::GLSLstd450 _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3)
{
	Instruction* returnType = _pOp1->getTypeInst();

	const Type* type1 = returnType->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *type1 == *type2 && *type2 == *type3)
	{
		return opExtInst(returnType, ExtName, _op, _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrFloatVec3 opeartion are not vector or scalar of float");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec1(const extinstr::GLSLstd450 _op, Instruction* _pInt, const bool _signed)
{
	Instruction* _pTypeInstr = _pInt->getTypeInst();
	const Type* pType = _pTypeInstr->getType();

	if (pType->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == pType->getBaseType().getIntSign())
	{
		return opExtInst(_pTypeInstr, ExtName, _op, _pInt);
	}

	getModule()->logError("Operands of scalarOrInt1 opeartion are not vector or scalar of int");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec2(const extinstr::GLSLstd450 _op, Instruction* _pOp1, Instruction* _pOp2, const bool _signed)
{
	Instruction* returnType = _pOp1->getTypeInst();

	const Type* leftType = returnType->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == leftType->getBaseType().getIntSign()  && *rightType == *rightType)
	{
		return opExtInst(returnType, ExtName, _op, _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrIntVec2 opeartion are not vector or scalar of int");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec3(const extinstr::GLSLstd450 _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, const bool _signed)
{
	Instruction* returnType = _pOp1->getTypeInst();

	const Type* type1 = returnType->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == type1->getBaseType().getIntSign() && *type1 == *type2 && *type2 == *type3)
	{
		return opExtInst(returnType, ExtName, _op, _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrIntVec3 opeartion are not vector or scalar of int");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opCross(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pType = _pLeftTypeInstr->getType();
	if (_pLeftTypeInstr == _pRightTypeInstr && pType->isVectorOfScalar(3u))
	{
		return opExtInst(_pLeftTypeInstr, ExtName, extinstr::GLSLstd450::GLSLstd450Cross, _pLeft, _pRight);	
	}
	
	getModule()->logError("Operands of opCross are not scalar vector of length 3");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opDeterminant(Instruction* _pMatrix)
{
	const Type* pType = _pMatrix->getType();

	if (pType->isSqareMatrix())
	{
		Instruction* pResultType = getModule()->addType(pType->getBaseType());
		return opExtInst(pResultType, ExtName, extinstr::GLSLstd450::GLSLstd450Determinant, _pMatrix);
	}

	getModule()->logError("Operand of opDeterminant is not a square matirx");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opMatrixInverse(Instruction* _pMatrix)
{
	Instruction* _pTypeInstr = _pMatrix->getTypeInst();
	const Type* pType = _pTypeInstr->getType();

	if (pType->isSqareMatrix())
	{
		return opExtInst(_pTypeInstr, ExtName, extinstr::GLSLstd450::GLSLstd450MatrixInverse, _pMatrix);
	}

	getModule()->logError("Operand of opMatrixInverse is not a square matirx");

	return nullptr;
}