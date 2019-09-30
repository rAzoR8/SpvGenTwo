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
	case spv::Op::OpIAdd:
	case spv::Op::OpISub:
	case spv::Op::OpFAdd:
	case spv::Op::OpFSub:
		return _rightOperand;
	case spv::Op::OpIAddCarry:
	case spv::Op::OpISubBorrow:
	{
		Type t(_module.newType());
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
			Type rowType(_module.newType());
			rowType.Vector(lType->getMatrixColumnCount()).Member().setBaseType(lType->front().getBaseType());
			return _module.addType(rowType);
		}
	}
	case spv::Op::OpMatrixTimesVector:
	{
		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		if (lType->getBaseType() == spv::Op::OpTypeMatrix)
		{
			return (lTypeInst->begin() + 1)->getInstruction();
		}
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