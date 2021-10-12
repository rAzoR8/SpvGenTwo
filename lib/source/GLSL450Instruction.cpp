#include "spvgentwo/GLSL450Instruction.h"
#include "spvgentwo/Module.h"

#include "spvgentwo/InstructionTemplate.inl"
#include "spvgentwo/ModuleTemplate.inl"

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec1(glslstd450::Op _op, Instruction* _pFloat, const bool _no64Bit, Instruction* _pResultType)
{
	Instruction* pTypeInstr = _pFloat->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	const Type* pType = pTypeInstr->getType();

	if ((pType->isFloat() || pType->isVectorOfFloat()) && (_no64Bit ? pType->getBaseType().getFloatWidth() <= 32u : true))
	{
		return opExtInst(_pResultType != nullptr ? _pResultType : pTypeInstr, ExtName, static_cast<unsigned int>(_op), _pFloat);
	}

	getModule()->logError("Operands of scalarOrFloatVec1 are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec2(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pResultType)
{
	const Type* leftType = _pOp1->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType == nullptr || rightType == nullptr) return error();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *leftType == *rightType)
	{
		Instruction* returnType = _pResultType != nullptr ? _pResultType : _pOp1->getResultTypeInstr();
		if (returnType == nullptr) return error();

		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrFloatVec2 are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrFloatVec3(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Instruction* _pResultType)
{
	const Type* type1 = _pOp1->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1 == nullptr || type2 == nullptr || type3 == nullptr) return error();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeFloat) && *type1 == *type2 && *type2 == *type3)
	{
		Instruction* returnType = _pResultType != nullptr ? _pResultType : _pOp1->getResultTypeInstr();
		if (returnType == nullptr) return error();

		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrFloatVec3 are not vector or scalar of float");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec1(glslstd450::Op _op, Instruction* _pInt, Sign _sign, Instruction* _pResultType)
{
	Instruction* pTypeInstr = _pInt->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	const Type* pType = pTypeInstr->getType();
	if (pType == nullptr) return error();

	if (pType->isScalarOrVectorOf(spv::Op::OpTypeInt) && pType->getBaseType().hasSign(_sign))
	{
		return opExtInst(_pResultType != nullptr ? _pResultType : pTypeInstr, ExtName, static_cast<unsigned int>(_op), _pInt);
	}

	getModule()->logError("Operands of scalarOrInt1 are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec2(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Sign _sign, Instruction* _pResultType)
{
	const Type* leftType = _pOp1->getType();
	const Type* rightType = _pOp2->getType();

	if (leftType == nullptr || rightType == nullptr) return error();

	if (leftType->isScalarOrVectorOf(spv::Op::OpTypeInt) &&leftType->getBaseType().hasSign(_sign) && *leftType == *rightType)
	{
		Instruction* returnType = _pResultType != nullptr ? _pResultType : _pOp1->getResultTypeInstr();
		if (returnType == nullptr) return error();

		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2);
	}

	getModule()->logError("Operands of scalarOrIntVec2 are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::scalarOrIntVec3(glslstd450::Op _op, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Sign _sign, Instruction* _pResultType)
{
	const Type* type1 = _pOp1->getType();
	const Type* type2 = _pOp2->getType();
	const Type* type3 = _pOp3->getType();

	if (type1 == nullptr || type2 == nullptr || type3 == nullptr) return error();

	if (type1->isScalarOrVectorOf(spv::Op::OpTypeInt) && type1->getBaseType().hasSign(_sign) && *type1 == *type2 && *type2 == *type3)
	{
		Instruction* returnType = _pResultType != nullptr ? _pResultType : _pOp1->getResultTypeInstr();
		if (returnType == nullptr) return error();

		return opExtInst(returnType, ExtName, static_cast<unsigned int>(_op), _pOp1, _pOp2, _pOp3);
	}

	getModule()->logError("Operands of scalarOrIntVec3 are not vector or scalar of int");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::packNorm(glslstd450::Op _op, Instruction* _pFloatVec, unsigned int _vecComponents)
{
	const Type* type = _pFloatVec->getType();

	if (type == nullptr) return error();

	if (type->isVectorOfFloat(_vecComponents, 32u))
	{
		return opExtInst(getModule()->type<sgt_int32_t>(), ExtName, static_cast<unsigned int>(_op), _pFloatVec);
	}

	getModule()->logError("Operand of packNorm is not a float vector with %u components of 32bit-width", _vecComponents);

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::unpackNorm(glslstd450::Op _op, Instruction* _pIntScalar, unsigned int _vecComponents)
{
	const Type* type = _pIntScalar->getType();

	if (type == nullptr) return error();

	if (type->isInt(32u))
	{
		Type t(getAllocator());
		t.VectorElement(_vecComponents).Float(32u);

		return opExtInst(getModule()->addType(t), ExtName, static_cast<unsigned int>(_op), _pIntScalar);
	}

	getModule()->logError("Operand of packNorm is not a float vector with %u components of 32bit-width", _vecComponents);

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::interpolate(glslstd450::Op _op, Instruction* _pInterpolant, Instruction* _pSampleOffset)
{
	const Type* type = _pInterpolant->getType();
	if (type == nullptr) return error();

	if(type->isPointer(spv::StorageClass::Input) == false)
	{
		getModule()->logError("Operand 'interpolant' is not a pointer of storage class 'input'");
		return error();
	}

	// get inner type
	if (type->front().isScalarOrVectorOf(spv::Op::OpTypeFloat, 0u, 32u) == false)
	{
		getModule()->logError("Operand 'interpolant' is not a float vector with 32bit component width");
		return error();
	}

	Instruction* resultType = getModule()->addType(type->front());

	if (_op == glslstd450::Op::InterpolateAtCentroid)
	{
		return opExtInst(resultType, ExtName, static_cast<unsigned int>(_op), _pInterpolant);
	}
	else if (const Type* sampleoffset = _pSampleOffset->getType(); sampleoffset != nullptr && _op == glslstd450::Op::InterpolateAtSample)
	{
		if (sampleoffset->isInt(32u))
		{
			return opExtInst(resultType, ExtName, static_cast<unsigned int>(_op), _pInterpolant, _pSampleOffset);
		}
		getModule()->logError("Operand 'sample' is not a scalar 32bit integer");
	}
	else if (sampleoffset != nullptr && _op == glslstd450::Op::InterpolateAtOffset) 
	{
		if (sampleoffset->isVectorOfFloat(2u, 32u))
		{
			return opExtInst(resultType, ExtName, static_cast<unsigned int>(_op), _pInterpolant, _pSampleOffset);
		}
		getModule()->logError("Operand 'offset' is not a 2-component float vector with 32bit width");
	}

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opFrexpStruct(Instruction* _pFloat)
{
	Instruction* significantType = _pFloat->getResultTypeInstr();
	if (significantType == nullptr) return error();


	// Result Type must be an OpTypeStruct with two members. Member 0 must have the same type as the type of x.
	// Member 0 holds the significand. Member 1 must be a scalar or vector with integer component type, with 32 - bit
	// component width. Member 1 holds the exponent. These two members and x must have the same number of
	// components.

	Type exponent(*significantType->getType());
	exponent.front().Int(32);

	Module* module = getModule();
	Instruction* exponentType = module->addType(exponent);

	return scalarOrFloatVec1(glslstd450::Op::FrexpStruct, _pFloat, false, module->compositeType(spv::Op::OpTypeStruct, significantType, exponentType));
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opLdexp(Instruction* _pFloatX, Instruction* _pIntExp)
{
	Instruction* resultType = _pFloatX->getResultTypeInstr();
	if (resultType == nullptr) return error();

	const Type* xType = resultType->getType();
	const Type* expType = _pIntExp->getType();

	if (xType == nullptr || expType == nullptr) return error();

	if (xType->isScalarOrVectorOfSameLength(*expType) && xType->getBaseType().isFloat() && expType->getBaseType().isInt())
	{
		return opExtInst(resultType, ExtName, static_cast<unsigned int>(glslstd450::Op::Ldexp), _pFloatX, _pIntExp);
	}

	getModule()->logError("Operands of opLdexp opeartion are not vector or scalar of float (x) or int (expt)");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opPackDouble2x32(Instruction* _pIntVec2)
{
	const Type* type = _pIntVec2->getType();

	if (type == nullptr) return error();

	if (type->isVectorOfInt(2, 32u))
	{
		return opExtInst(getModule()->type<double>(), ExtName, static_cast<unsigned int>(glslstd450::Op::PackDouble2x32), _pIntVec2);
	}

	getModule()->logError("Operand of PackDouble2x32 is not a int vector with 2 components of 32bit-width");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opUnpackDouble2x32(Instruction* _pDouble)
{
	const Type* type = _pDouble->getType();

	if (type == nullptr) return error();

	if (type->isF64())
	{
		return opExtInst(getModule()->type<vector_t<int, 2>>(), ExtName, static_cast<unsigned int>(glslstd450::Op::UnpackDouble2x32), _pDouble);
	}

	getModule()->logError("Operand of UnpackDouble2x32 is not a int vector with 2 components of 32bit-width");

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
	Instruction* pTypeInstr = _pMatrix->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	const Type* pType = pTypeInstr->getType();
	if (pType == nullptr) return error();

	if (pType->isSqareMatrix())
	{
		return opExtInst(pTypeInstr, ExtName, static_cast<unsigned int>(glslstd450::Op::MatrixInverse), _pMatrix);
	}

	getModule()->logError("Operand of opMatrixInverse is not a square matirx");

	return error();
}

spvgentwo::Instruction* spvgentwo::GLSL450Intruction::opModfStruct(Instruction* _pFloat)
{
	Instruction* pTypeInstr = _pFloat->getResultTypeInstr();
	if (pTypeInstr == nullptr) return error();

	return scalarOrFloatVec1(glslstd450::Op::ModfStruct, _pFloat, false, getModule()->compositeType(spv::Op::OpTypeStruct, pTypeInstr, pTypeInstr));
}
