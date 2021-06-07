#include "spvgentwo/GLSL450Instruction.h"
#include "spvgentwo/Module.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec1(const glslstd450::Op _op, Instruction* _pFloat, const bool _no64Bit)
{
	Instruction* pTypeInstr = _pFloat->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	const Type* pType = pTypeInstr->getType();

	if ((pType->isFloat() || pType->isVectorOfFloat()) && (_no64Bit ? pType->getBaseType().getFloatWidth() <= 32u : true))
	{
		return opExtInst(pTypeInstr, ExtName, static_cast<unsigned int>(_op), _pFloat);
	}

	getModule()->logError("Operands of scalarOrFloatVec1 opeartion are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec2(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2)
{
	Instruction* returnType = _pOp1->getResultTypeInstr();
	if (returnType == nullptr) return error();

	const Type* leftType = returnType->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType == nullptr || rightType == nullptr) return error();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *leftType == *rightType)
	{
		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrFloatVec2 opeartion are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec3(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3)
{
	Instruction* returnType = _pOp1->getResultTypeInstr();
	if (returnType == nullptr) return error();

	const Type* type1 = returnType->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1 == nullptr || type2 == nullptr || type3 == nullptr) return error();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *type1 == *type2 && *type2 == *type3)
	{
		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrFloatVec3 opeartion are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec1(const glslstd450::Op _op, Instruction* _pInt, const bool _signed)
{
	Instruction* pTypeInstr = _pInt->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	const Type* pType = pTypeInstr->getType();
	if (pType == nullptr) return error();

	if (pType->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == pType->getBaseType().getIntSign())
	{
		return opExtInst(pTypeInstr, ExtName, static_cast<unsigned int>(_op), _pInt);
	}

	getModule()->logError("Operands of scalarOrInt1 opeartion are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec2(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, const bool _signed)
{
	Instruction* returnType = _pOp1->getResultTypeInstr();
	if (returnType == nullptr) return error();

	const Type* leftType = returnType->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType == nullptr || rightType == nullptr) return error();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == leftType->getBaseType().getIntSign()  && *leftType == *rightType)
	{
		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrIntVec2 opeartion are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec3(const glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, const bool _signed)
{
	Instruction* returnType = _pOp1->getResultTypeInstr();
	if (returnType == nullptr) return error();

	const Type* type1 = returnType->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1 == nullptr || type2 == nullptr || type3 == nullptr) return error();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeInt) && _signed == type1->getBaseType().getIntSign() && *type1 == *type2 && *type2 == *type3)
	{
		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrIntVec3 opeartion are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opLength(Instruction* _pX)
{
	const Type* type = _pX->getType();
	if (type == nullptr) return error();

	if (type->isVectorOfFloat())
	{
		if (auto it = _pX->getResultTypeInstr()->getFirstActualOperand(); it != nullptr && it->isInstruction()) // extract base type
		{
			return opExtInst(it->instruction, ExtName, static_cast<unsigned int>(glslstd450::Op::Length), _pX);
		}
	}

	getModule()->logError("Operand of opLength is not of type float vector");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opDistance(Instruction* _pP1, Instruction* _pP2)
{
	const Type* type1 = _pP1->getType();
	const Type* type2 = _pP2->getType();

	if (type1 == nullptr || type2 == nullptr) return error();

	if (type1->isScalarOrVectorOfSameLength(spv::Op::OpTypeFloat, *type2))
	{
		if (auto it = _pP1->getResultTypeInstr()->getFirstActualOperand(); it != nullptr && it->isInstruction()) // extract base type
		{
			return opExtInst(it->instruction, ExtName, static_cast<unsigned int>(glslstd450::Op::Distance), _pP1, _pP2);
		}
	}

	getModule()->logError("Operand type of opDistance is not a float scalar or vector");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opCross(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* pLeftTypeInstr = _pLeft->getResultTypeInstr();
	Instruction* pRightTypeInstr = _pRight->getResultTypeInstr();

	if (pLeftTypeInstr == nullptr || pRightTypeInstr == nullptr) return error();

	const Type* pType = pLeftTypeInstr->getType();
	if (pLeftTypeInstr == pRightTypeInstr && pType->isVectorOfFloat(3u))
	{
		return opExtInst(pLeftTypeInstr, ExtName, static_cast<unsigned int>(glslstd450::Op::Cross), _pLeft, _pRight);
	}
	
	getModule()->logError("Operands of opCross are not vector of length 3");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opRefract(Instruction* _pIvec, Instruction* _pNvec, Instruction* _pEtaFloat)
{
	const Type* typeI = _pIvec->getType();
	const Type* typeN = _pNvec->getType();
	const Type* typeEta = _pEtaFloat->getType();

	if (typeI == nullptr || typeN == nullptr || typeEta == nullptr) return error();

	if (typeI->isScalarOrVectorOfSameLength(spv::Op::OpTypeFloat, *typeN) && typeN->getBaseType() == *typeEta)
	{
		return opExtInst(_pIvec->getResultTypeInstr(), ExtName, static_cast<unsigned int>(glslstd450::Op::Refract), _pIvec, _pNvec, _pEtaFloat);
	}

	getModule()->logError("Operands of opRefract are not vector of float or _pEtaFloat is not a float scalar");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opDeterminant(Instruction* _pMatrix)
{
	const Type* pType = _pMatrix->getType();
	if (pType == nullptr) return error();

	if (pType->isSqareMatrix())
	{
		Instruction* pResultType = getModule()->addType(pType->getBaseType());
		return opExtInst(pResultType, ExtName, static_cast<unsigned int>(glslstd450::Op::Determinant), _pMatrix);
	}

	getModule()->logError("Operand of opDeterminant is not a square matirx");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opMatrixInverse(Instruction* _pMatrix)
{
	Instruction* _pTypeInstr = _pMatrix->getResultTypeInstr();
	if (_pTypeInstr == nullptr) return error();

	const Type* pType = _pTypeInstr->getType();
	if (pType == nullptr) return error();

	if (pType->isSqareMatrix())
	{
		return opExtInst(_pTypeInstr, ExtName, static_cast<unsigned int>(glslstd450::Op::MatrixInverse), _pMatrix);
	}

	getModule()->logError("Operand of opMatrixInverse is not a square matirx");

	return error();
}