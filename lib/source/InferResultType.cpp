#include "InferResultType.h"
#include "Instruction.h"
#include "Module.h"

spvgentwo::Instruction* spvgentwo::inferType(const spv::Op _operation, Instruction* _op1, Instruction* _op2, Instruction* _op3)
{
	Instruction* op1TypeInst = _op1 != nullptr ? _op1->getType() : nullptr;
	Instruction* op2TypeInst = _op2 != nullptr ? _op2->getType() : nullptr;
	Instruction* op3TypeInst = _op3 != nullptr ? _op3->getType() : nullptr;

	if (op1TypeInst == nullptr)
	{
		return nullptr;
	}

	Module& module = *_op1->getModule();

	const Type* op1Type = op1TypeInst != nullptr ? module.getTypeInfo(op1TypeInst) : nullptr;
	const Type* op2Type = op2TypeInst != nullptr ? module.getTypeInfo(op2TypeInst) : nullptr;
	const Type* op3Type = op3TypeInst != nullptr ? module.getTypeInfo(op3TypeInst) : nullptr;

	switch (_operation)
	{
	case spv::Op::OpSizeOf:
		return module.type<unsigned int>();
	case spv::Op::OpSNegate:
	{
		Type t(stdrep::move(module.newType()));

		if(op1Type->isVector())
		{
			t.VectorElement(op1Type->getVectorComponentCount()).Int(op1Type->front().getIntWidth(), true);
		}
		else
		{
			t.Int(op1Type->getIntWidth(), true);
		}

		return module.addType(t);
	}
	// types where operands must match result type, no further validation at this point
	case spv::Op::OpFNegate:
	case spv::Op::OpIAdd:
	case spv::Op::OpISub:
	case spv::Op::OpFAdd:
	case spv::Op::OpFSub:
	case spv::Op::OpFMul:
	case spv::Op::OpUDiv:
	case spv::Op::OpSDiv:
	case spv::Op::OpFDiv:
	case spv::Op::OpUMod:
	case spv::Op::OpSRem:
	case spv::Op::OpSMod:
	case spv::Op::OpFRem:
	case spv::Op::OpFMod:
		return op1TypeInst;
	case spv::Op::OpIAddCarry:
	case spv::Op::OpISubBorrow:
	{
		Type t(stdrep::move(module.newType()));
		t.Struct().IntM().IntM();
		return module.addType(t);
	}
	case spv::Op::OpVectorTimesScalar:
		return checkType(spv::Op::OpTypeVector, op1TypeInst);
	case spv::Op::OpMatrixTimesScalar:
		return checkType(spv::Op::OpTypeMatrix, op1TypeInst);
	case spv::Op::OpVectorTimesMatrix:
	{
		// Matrix must be a matrix with the same Component Type as the Component Type in Result Type.
		// Its number of columns must equal the number of components in Result Type.
		// => return matrix row type:
		if (op1Type->getBaseType() == spv::Op::OpTypeMatrix)
		{
			Type rowType(stdrep::move(module.newType()));
			rowType.Vector(op1Type->getMatrixColumnCount()).Member().setBaseType(op1Type->front().getBaseType());
			return module.addType(rowType);
		}
		break;
	}
	case spv::Op::OpMatrixTimesVector:
	{
		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		if (op1Type->getBaseType() == spv::Op::OpTypeMatrix)
		{
			return (op1TypeInst->begin() + 1)->getInstruction();
		}
		break;
	}
	case spv::Op::OpMatrixTimesMatrix:
	{
		// Linear - algebraic multiply of LeftMatrix X RightMatrix.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// LeftMatrix must be a matrix whose Column Type is the same as the Column Type in Result Type.
		// RightMatrix must be a matrix with the same Component Type as the Component Type in Result Type.Its number of columns must equal the number of columns in Result Type.Its columnsmusthavethesamenumberofcomponentsasthenumberofcolumnsinLeftMatrix.

		Type matType(stdrep::move(module.newType()));
		matType.MatrixColumn(op2Type->getMatrixColumnCount()).VectorElement(op2Type->getMatrixColumnCount()).Float(op1Type->front().front().getFloatWidth());
		return module.addType(matType);
	}
	case spv::Op::OpOuterProduct:
	{
		// Linear - algebraic outer product of Vector 1 and Vector 2.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// Vector 1 must have the same type as the Column Type in Result Type.
		// Vector 2 must be a vector with the same Component Type as the Component Type in Result Type.Its number of components must equal the number of columns in Result Type.
		Type matType(stdrep::move(module.newType()));
		matType.MatrixColumn(op2Type->getVectorComponentCount()).VectorElement(op1Type->getVectorComponentCount()).Float(op1Type->front().getFloatWidth());
		return module.addType(matType);
	}
	case spv::Op::OpDot:
	{
		Type floatType(stdrep::move(module.newType()));
		floatType.Float(op1Type->front().getFloatWidth());
		return module.addType(floatType);
	}
	case spv::Op::OpAny:
	case spv::Op::OpAll:
		return module.type<bool>();
	case spv::Op::OpLogicalEqual:
	case spv::Op::OpLogicalNotEqual:
	case spv::Op::OpLogicalOr:
	case spv::Op::OpLogicalAnd:
	case spv::Op::OpLogicalNot:
		// Result Type must be a scalar or vector of Boolean type.
		// The type of Operand 1 must be the same as Result Type.
		// The type of Operand 2 must be the same as Result Type.
		return op1TypeInst;
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
		Type t(stdrep::move(module.newType()));

		if (op1Type->isVector())
		{
			t.VectorElement(op1Type->getVectorComponentCount()).Bool();
		}
		else
		{
			t.Bool();
		}

		return module.addType(t);
	}
	case spv::Op::OpPhi:
		return op1TypeInst;
	default:
		break;
	}

	return nullptr;
}

const spvgentwo::Type* spvgentwo::selectType(const spv::Op _type, const Type* _left, const Type* _right)
{
	return _left->getBaseType() == _type ? _left : (_right->getBaseType() == _type ? _right : nullptr);
}

spvgentwo::Instruction* spvgentwo::selectType(const spv::Op _type, Instruction* _leftTypeInstr, Instruction* _rightTypeInstr)
{
	return _leftTypeInstr->getOperation() == _type ? _leftTypeInstr : (_rightTypeInstr->getOperation() == _type ? _rightTypeInstr : nullptr);
}

spvgentwo::Instruction* spvgentwo::checkType(const spv::Op _type, Instruction* _typeInstr)
{
	return _typeInstr->getOperation() == _type ? _typeInstr : nullptr;
}