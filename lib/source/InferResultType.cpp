#include "InferResultType.h"
#include "Instruction.h"
#include "Module.h"

spvgentwo::Instruction* spvgentwo::inferType(const spv::Op _operation, Instruction* _op1, Instruction* _op2, Instruction* _op3)
{
	Instruction* op1TypeInst = _op1 != nullptr ? _op1->getTypeInst() : nullptr;
	Instruction* op2TypeInst = _op2 != nullptr ? _op2->getTypeInst() : nullptr;
	Instruction* op3TypeInst = _op3 != nullptr ? _op3->getTypeInst() : nullptr;

	if (op1TypeInst == nullptr)
	{
		return nullptr;
	}

	Module& module = *_op1->getModule();

	const Type* op1Type = op1TypeInst != nullptr ? module.getTypeInfo(op1TypeInst) : nullptr;
	const Type* op2Type = op2TypeInst != nullptr ? module.getTypeInfo(op2TypeInst) : nullptr;
	const Type* op3Type = op3TypeInst != nullptr ? module.getTypeInfo(op3TypeInst) : nullptr;

	return inferType(_operation, module, op1TypeInst, op2TypeInst, op3TypeInst, op1Type, op2Type, op3Type);
}

spvgentwo::Instruction* spvgentwo::inferType(const spv::Op _operation, Module& _module, Instruction* _pType1Inst, Instruction* _pType2Inst, Instruction* _pType3Inst, const Type* _pType1, const Type* _pType2, const Type* _pType3)
{
	switch (_operation)
	{
	case spv::Op::OpSizeOf:
		return _module.type<unsigned int>();
	case spv::Op::OpSNegate:
	{
		Type t(stdrep::move(_module.newType()));

		if (_pType1->isVector())
		{
			t.VectorElement(_pType1->getVectorComponentCount()).Int(_pType1->front().getIntWidth(), true);
		}
		else
		{
			t.Int(_pType1->getIntWidth(), true);
		}

		return _module.addType(t);
	}
	// types where operands must match result type, no further validation at this point
	case spv::Op::OpFNegate:
	case spv::Op::OpIAdd:
	case spv::Op::OpISub:
	case spv::Op::OpFAdd:
	case spv::Op::OpFSub:
	case spv::Op::OpIMul:
	case spv::Op::OpFMul:
	case spv::Op::OpUDiv:
	case spv::Op::OpSDiv:
	case spv::Op::OpFDiv:
	case spv::Op::OpUMod:
	case spv::Op::OpSRem:
	case spv::Op::OpSMod:
	case spv::Op::OpFRem:
	case spv::Op::OpFMod:
		return _pType1Inst;
	case spv::Op::OpIAddCarry:
	case spv::Op::OpISubBorrow:
		return _module.compositeType(spv::Op::OpTypeStruct, _pType1Inst, _pType2Inst);
	case spv::Op::OpVectorTimesScalar:
		return checkType(spv::Op::OpTypeVector, _pType1Inst);
	case spv::Op::OpMatrixTimesScalar:
		return checkType(spv::Op::OpTypeMatrix, _pType1Inst);
	case spv::Op::OpVectorTimesMatrix:
	{
		// Matrix must be a matrix with the same Component Type as the Component Type in Result Type.
		// Its number of columns must equal the number of components in Result Type.
		// => return matrix row type:
		if (_pType1->getType() == spv::Op::OpTypeMatrix)
		{
			Type rowType(stdrep::move(_module.newType()));
			rowType.Vector(_pType1->getMatrixColumnCount()).Member().setType(_pType1->front().getType());
			return _module.addType(rowType);
		}
		break;
	}
	case spv::Op::OpMatrixTimesVector:
	{
		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		if (_pType1->getType() == spv::Op::OpTypeMatrix)
		{
			return (_pType1Inst->begin() + 1)->getInstruction();
		}
		break;
	}
	case spv::Op::OpMatrixTimesMatrix:
	{
		// Linear - algebraic multiply of LeftMatrix X RightMatrix.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// LeftMatrix must be a matrix whose Column Type is the same as the Column Type in Result Type.
		// RightMatrix must be a matrix with the same Component Type as the Component Type in Result Type.Its number of columns must equal the number of columns in Result Type.Its columnsmusthavethesamenumberofcomponentsasthenumberofcolumnsinLeftMatrix.

		Type matType(stdrep::move(_module.newType()));
		matType.MatrixColumn(_pType2->getMatrixColumnCount()).VectorElement(_pType2->getMatrixColumnCount()).Float(_pType1->front().front().getFloatWidth());
		return _module.addType(matType);
	}
	case spv::Op::OpOuterProduct:
	{
		// Linear - algebraic outer product of Vector 1 and Vector 2.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// Vector 1 must have the same type as the Column Type in Result Type.
		// Vector 2 must be a vector with the same Component Type as the Component Type in Result Type.Its number of components must equal the number of columns in Result Type.
		Type matType(stdrep::move(_module.newType()));
		matType.MatrixColumn(_pType2->getVectorComponentCount()).VectorElement(_pType1->getVectorComponentCount()).Float(_pType1->front().getFloatWidth());
		return _module.addType(matType);
	}
	case spv::Op::OpDot:
	{
		Type floatType(stdrep::move(_module.newType()));
		floatType.Float(_pType1->front().getFloatWidth());
		return _module.addType(floatType);
	}
	case spv::Op::OpAny:
	case spv::Op::OpAll:
		return _module.type<bool>();
	case spv::Op::OpLogicalEqual:
	case spv::Op::OpLogicalNotEqual:
	case spv::Op::OpLogicalOr:
	case spv::Op::OpLogicalAnd:
	case spv::Op::OpLogicalNot:
		// Result Type must be a scalar or vector of Boolean type.
		// The type of Operand 1 must be the same as Result Type.
		// The type of Operand 2 must be the same as Result Type.
		return _pType1Inst;
	case spv::Op::OpIEqual:
	case spv::Op::OpINotEqual:
	case spv::Op::OpUGreaterThan:
	case spv::Op::OpSGreaterThan:
	case spv::Op::OpUGreaterThanEqual:
	case spv::Op::OpSGreaterThanEqual:
	case spv::Op::OpULessThan:
	case spv::Op::OpSLessThan:
	case spv::Op::OpULessThanEqual:
	case spv::Op::OpSLessThanEqual:
	case spv::Op::OpFOrdEqual:
	case spv::Op::OpFUnordEqual:
	case spv::Op::OpFOrdNotEqual:
	case spv::Op::OpFUnordNotEqual:
	case spv::Op::OpFOrdLessThan:
	case spv::Op::OpFUnordLessThan:
	case spv::Op::OpFOrdGreaterThan:
	case spv::Op::OpFUnordGreaterThan:
	case spv::Op::OpFOrdLessThanEqual:
	case spv::Op::OpFUnordLessThanEqual:
	case spv::Op::OpFOrdGreaterThanEqual:
	case spv::Op::OpFUnordGreaterThanEqual:
	{
		Type t(stdrep::move(_module.newType()));

		if (_pType1->isVector())
		{
			t.VectorElement(_pType1->getVectorComponentCount()).Bool();
		}
		else
		{
			t.Bool();
		}

		return _module.addType(t);
	}
	case spv::Op::OpPhi:
		return _pType1Inst;
	default:
		break;
	}

	_module.logError("Could not infer result type for operation");

	return nullptr;
}

const spvgentwo::Type* spvgentwo::selectType(const spv::Op _type, const Type* _left, const Type* _right)
{
	return _left->getType() == _type ? _left : (_right->getType() == _type ? _right : nullptr);
}

spvgentwo::Instruction* spvgentwo::selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr)
{
	return _leftTypeInstr->getOperation() == _type ? _leftTypeInstr : (_rightTypeInstr->getOperation() == _type ? _rightTypeInstr : nullptr);
}

spvgentwo::Instruction* spvgentwo::checkType(const spv::Op _type, Instruction* _typeInstr)
{
	return _typeInstr->getOperation() == _type ? _typeInstr : nullptr;
}