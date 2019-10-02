#include "InferResultType.h"
#include "Instruction.h"
#include "Module.h"

spvgentwo::Instruction* spvgentwo::inferType(const spv::Op _operation, Instruction* _leftOperand, Instruction* _rightOperand, Module& _module)
{
	Instruction* lTypeInst = _leftOperand->getType();
	Instruction* rTypeInst = _rightOperand->getType();

	const Type* lType = _module.getTypeInfo(lTypeInst);
	if (lType == nullptr) return nullptr;

	const Type* rType = _module.getTypeInfo(rTypeInst);
	if (rType == nullptr) return nullptr;

	switch (_operation)
	{
	case spv::Op::OpSNegate:
	{
		Type t(stdrep::move(_module.newType()));

		if(lType->isVector())
		{
			t.VectorElement(lType->getVectorComponentCount()).Int(lType->front().getIntWidth(), true);
		}
		else
		{
			t.Int(lType->getIntWidth(), true);
		}

		return _module.addType(t);
	}
	case spv::Op::OpFNegate:
		return _leftOperand;
	case spv::Op::OpIAdd:
	case spv::Op::OpISub:
	case spv::Op::OpFAdd:
	case spv::Op::OpFSub:
		return _rightOperand;
	case spv::Op::OpIAddCarry:
	case spv::Op::OpISubBorrow:
	{
		Type t(stdrep::move(_module.newType()));
		t.Struct().IntM().IntM();
		return _module.addType(t);
	}
	case spv::Op::OpVectorTimesScalar:
		return checkType(spv::Op::OpTypeVector, lTypeInst);
	case spv::Op::OpMatrixTimesScalar:
		return checkType(spv::Op::OpTypeMatrix, lTypeInst);
	case spv::Op::OpVectorTimesMatrix:
	{
		// Matrix must be a matrix with the same Component Type as the Component Type in Result Type.
		// Its number of columns must equal the number of components in Result Type.
		// => return matrix row type:
		if (lType->getBaseType() == spv::Op::OpTypeMatrix)
		{
			Type rowType(stdrep::move(_module.newType()));
			rowType.Vector(lType->getMatrixColumnCount()).Member().setBaseType(lType->front().getBaseType());
			return _module.addType(rowType);
		}
		break;
	}
	case spv::Op::OpMatrixTimesVector:
	{
		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		if (lType->getBaseType() == spv::Op::OpTypeMatrix)
		{
			return (lTypeInst->begin() + 1)->getInstruction();
		}
		break;
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
		return _leftOperand;
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
		// TODO: OpFOrdLessThanEqual ... 
	{
		Type t(stdrep::move(_module.newType()));

		if (lType->isVector())
		{
			t.VectorElement(lType->getVectorComponentCount()).Bool();
		}
		else
		{
			t.Bool();
		}

		return _module.addType(t);
	}


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