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
		return selectType(spv::Op::OpTypeVector, lTypeInst, rTypeInst);
	case spv::Op::OpMatrixTimesScalar:
		return selectType(spv::Op::OpTypeMatrix, lTypeInst, rTypeInst);
	case spv::Op::OpVectorTimesMatrix:
	{
		// Linear - algebraic Vector X Matrix.
		// Result Type must be a vector of ﬂoating - point type.
		// Vector must be a vector with the same Component Type as the Component Type in Result Type.Its number of components must equal the number of components in each column in Matrix.
		// Matrix must be a matrix with the same Component Type as the Component Type in Result Type.Its number of columns must equal the number of components in Result Type.

	}
	case spv::Op::OpMatrixTimesVector:
	{
		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		Instruction* mat = selectType(spv::Op::OpTypeMatrix, lTypeInst, rTypeInst);
		if (mat != nullptr)
		{
			return (mat->begin() + 1)->getInstruction();
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