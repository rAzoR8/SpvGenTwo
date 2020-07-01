#include "spvgentwo/TypeInferenceAndValiation.h"
#include "spvgentwo/Instruction.h"
#include "spvgentwo/Module.h"

using namespace spvgentwo;

spvgentwo::Instruction* spvgentwo::defaultimpl::inferResultType(const spvgentwo::Instruction& _instr)
{
	Module* module = _instr.getModule();
	auto op1 = _instr.getFirstActualOperand();
	auto op2 = op1 + 1;

	Instruction* typeInstr1 = op1 != nullptr && op1->isInstruction() && op1->instruction != nullptr ? op1->instruction->getTypeInstr() : nullptr;
	Instruction* typeInstr2 = op2 != nullptr && op2->isInstruction() && op2->instruction != nullptr ? op2->instruction->getTypeInstr() : nullptr;

	const Type* type1 = typeInstr1 != nullptr ? typeInstr1->getType() : nullptr;
	const Type* type2 = typeInstr2 != nullptr ? typeInstr2->getType() : nullptr;

	switch (_instr.getOperation())
	{
	case spv::Op::OpSizeOf:
		return module->type<unsigned int>();
	case spv::Op::OpSNegate:
	case spv::Op::OpSDiv:
	case spv::Op::OpSRem:
	case spv::Op::OpSMod:
	case spv::Op::OpSConvert:
	{
		if (type1 == nullptr) return module->getErrorInstr();
		Type t(*type1);
		t.setSign(true);
		return module->addType(t);
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
	case spv::Op::OpFDiv:
	case spv::Op::OpUMod:
	case spv::Op::OpFRem:
	case spv::Op::OpFMod:
	case spv::Op::OpNot:
	case spv::Op::OpShiftRightLogical:
	case spv::Op::OpShiftRightArithmetic:
	case spv::Op::OpShiftLeftLogical:
	case spv::Op::OpBitwiseOr:
	case spv::Op::OpBitwiseXor:
	case spv::Op::OpBitwiseAnd:
	case spv::Op::OpFwidth:
	case spv::Op::OpFwidthCoarse:
	case spv::Op::OpFwidthFine:
	case spv::Op::OpDPdx:
	case spv::Op::OpDPdy:
	case spv::Op::OpDPdxFine:
	case spv::Op::OpDPdyFine:
	case spv::Op::OpDPdxCoarse:
	case spv::Op::OpDPdyCoarse:
		return typeInstr1;
	case spv::Op::OpIAddCarry:
	case spv::Op::OpISubBorrow:
		return module->compositeType(spv::Op::OpTypeStruct, typeInstr1, typeInstr2);
	case spv::Op::OpVectorTimesScalar:
		return checkType(spv::Op::OpTypeVector, typeInstr1);
	case spv::Op::OpMatrixTimesScalar:
		return checkType(spv::Op::OpTypeMatrix, typeInstr1);
	case spv::Op::OpVectorTimesMatrix:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		// Matrix must be a matrix with the same Component Type as the Component Type in Result Type.
		// Its number of columns must equal the number of components in Result Type.
		// => return matrix row type:
		if (type1->isMatrix())
		{
			return module->addType(type1->front().wrapVector(type1->getMatrixColumnCount()));
		}
		break;
	}
	case spv::Op::OpMatrixTimesVector:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		// Matrix must be an OpTypeMatrix whose Column Type is Result Type.
		if (type1->isMatrix())
		{
			return (typeInstr1->begin() + 1)->getInstruction();
		}
		break;
	}
	case spv::Op::OpMatrixTimesMatrix:
	{
		if (type1 == nullptr || type2 == nullptr) return module->getErrorInstr();

		// Linear - algebraic multiply of LeftMatrix X RightMatrix.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// LeftMatrix must be a matrix whose Column Type is the same as the Column Type in Result Type.
		// RightMatrix must be a matrix with the same Component Type as the Component Type in Result Type.
		// Its number of columns must equal the number of columns in Result Type.
		// Its columns must have the same number of components as the number of columns in LeftMatrix.

		return module->addType(type1->front().wrapMatrix(type2->getMatrixColumnCount()));
	}
	case spv::Op::OpOuterProduct:
	{
		if (type1 == nullptr || type2 == nullptr) return module->getErrorInstr();

		// Linear - algebraic outer product of Vector 1 and Vector 2.
		// Result Type must be an OpTypeMatrix whose Column Type is a vector of ﬂoating - point type.
		// Vector 1 must have the same type as the Column Type in Result Type.
		// Vector 2 must be a vector with the same Component Type as the Component Type in Result Type.
		// Its number of components must equal the number of columns in Result Type.

		return module->addType(type1->wrapMatrix(type2->getVectorComponentCount()));
	}
	case spv::Op::OpDot:
	{
		if (type1 == nullptr) return module->getErrorInstr();
		Type floatType(module->getAllocator());
		floatType.Float(type1->front().getFloatWidth());
		return module->addType(floatType);
	}
	case spv::Op::OpTranspose: 
	{
		if (type1 == nullptr) return module->getErrorInstr();
		// Matrix must be an object of type OpTypeMatrix.
		// The number of columns and the column size of Matrix must be the reverse of those in Result Type.
		// The types of the scalar components in Matrix and Result Type must be the same.
		Type matType(module->getAllocator());
		matType.MatrixColumn(type1->front().getVectorComponentCount()).VectorElement(type1->getMatrixColumnCount()) = type1->getBaseType();
		return module->addType(matType);
	}
	case spv::Op::OpVectorExtractDynamic:
		if (type1 == nullptr) return module->getErrorInstr();
		return module->addType(type1->front()); 
	case spv::Op::OpAny:
	case spv::Op::OpAll:
		return module->type<bool>();
	case spv::Op::OpLogicalEqual:
	case spv::Op::OpLogicalNotEqual:
	case spv::Op::OpLogicalOr:
	case spv::Op::OpLogicalAnd:
	case spv::Op::OpLogicalNot:
		// Result Type must be a scalar or vector of Boolean type.
		// The type of Operand 1 must be the same as Result Type.
		// The type of Operand 2 must be the same as Result Type.
		return typeInstr1;
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
	case spv::Op::OpIsNan:
	case spv::Op::OpIsInf:
	case spv::Op::OpIsFinite:
	case spv::Op::OpIsNormal:
	case spv::Op::OpSignBitSet:
	case spv::Op::OpLessOrGreater:
	case spv::Op::OpOrdered:
	case spv::Op::OpUnordered:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		Type t(module->getAllocator());

		if (type1->isVector())
		{
			t.VectorElement(type1->getVectorComponentCount()).Bool();
		}
		else
		{
			t.Bool();
		}

		return module->addType(t);
	}
	case spv::Op::OpPhi:
	case spv::Op::OpCopyObject:
	case spv::Op::OpVectorInsertDynamic:
		return typeInstr1;
	case spv::Op::OpSelect:
		return typeInstr2;
	case spv::Op::OpSampledImage:
		if (type1 == nullptr) return module->getErrorInstr();
		return module->addType(type1->wrap(spv::Op::OpTypeSampledImage));

	case spv::Op::OpImageSampleImplicitLod:
	case spv::Op::OpImageSampleExplicitLod:
	case spv::Op::OpImageSampleDrefImplicitLod:
	case spv::Op::OpImageSampleDrefExplicitLod:
	case spv::Op::OpImageSampleProjImplicitLod:
	case spv::Op::OpImageSampleProjExplicitLod:
	case spv::Op::OpImageSampleProjDrefImplicitLod:
	case spv::Op::OpImageSampleProjDrefExplicitLod:
	case spv::Op::OpImageFetch:
	case spv::Op::OpImageGather:
	case spv::Op::OpImageDrefGather:
	case spv::Op::OpImageRead:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		const Type* image = type1->isSampledImage() ? &type1->front() : (type1->isImage() ? type1 : nullptr); // _pType1 is SampleImage or Image
		if (image == nullptr) break;
		
		const Type& sampledType = image->front();

		//Result Type must be a vector of four components of ﬂoating-point type or integer type.
		//Its components must be the same as Sampled Type of the underlying OpTypeImage (unless that underlying Sampled Type isOpTypeVoid).
		
		if (sampledType.isVoid())
		{
			// not sure what todo, return void? or return float4?
			return module->type<vector_t<float, 4>>();
		}
		else
		{
			return module->addType(sampledType.wrapVector(4));
		}
	}		
		break;

	case spv::Op::OpConvertFToU:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		Type t(*type1);
		Type& base = t.getBaseType();
		base.setType(spv::Op::OpTypeInt);
		base.setIntSign(false); // int/float with stays the same

		return module->addType(t);
	}
	case spv::Op::OpConvertFToS:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		Type t(*type1);
		Type& base = t.getBaseType();
		base.setType(spv::Op::OpTypeInt);
		base.setIntSign(true);

		return module->addType(t);
	}
	case spv::Op::OpConvertSToF:
	case spv::Op::OpConvertUToF:
	{
		if (type1 == nullptr) return module->getErrorInstr();

		Type t(*type1);
		Type& base = t.getBaseType();
		base.setType(spv::Op::OpTypeFloat);
		base.setIntSign(false); // reset sign

		return module->addType(t);
	}
	default:
		break;
	}

	module->logError("Could not infer result type for operation");

	return module->getErrorInstr();
}

bool spvgentwo::defaultimpl::validateOperands(const spvgentwo::Instruction& _instr)
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(_instr.getOperation(), &resultId, &resultType);

	Module* module = _instr.getModule();

	if (resultType)
	{
		auto it = _instr.getResultTypeOperand();
		if (it == nullptr)
		{
			module->logError("ResultType operand missing");
			return false;
		}

		if (it->isInstruction() == false || it->instruction == nullptr)
		{
			module->logError("ResultType operand is not a valid instruction");
			return false;
		}

		if (it->instruction->isType() == false)
		{
			module->logError("ResultType operand is not a OpType instruction");
			return false;
		}
	}

	if (resultId)
	{
		auto it = _instr.getResultIdOperand();
		if (it == nullptr)
		{
			module->logError("ResultId operand missing");
			return false;
		}

		if (it->isId() == false)
		{
			module->logError("ResultId operand is not a spv::id");
			return false;
		}
	}

	for (auto it = _instr.getFirstActualOperand(), end = _instr.end(); it != end; ++it)
	{
		const Operand& op = *it;
		switch (op.type)
		{
		case Operand::Type::Instruction:
			if (op.instruction == nullptr)
			{
				module->logError("Unassigned instruction operand (nullptr)");
				return false;
			}
			else if (op.instruction == &_instr)
			{
				module->logError("Recursive instruction operand");
				return false;
			}
			else if (op.instruction->isErrorInstr())
			{
				module->logError("Error instructions (result of invalid constrution)");
				return false;
			}
			break;
		case Operand::Type::BranchTarget:
			if (op.branchTarget == nullptr)
			{
				module->logError("Unassigned branchtarget operand (nullptr)");
				return false;
			}
			else if (&op.branchTarget->front() == &_instr)
			{
				module->logError("Recursive branch target instruction operand");
				return false;
			}
			break;
		default:
			break;
		}
	}

	// TODO: validate remaining operands (at least check number and type of operands matches instruction opcode)

	// explicit checks:

	switch (_instr.getOperation())
	{
	case spv::Op::OpImageFetch:
	case spv::Op::OpImageDrefGather:
	case spv::Op::OpImageGather:
	case spv::Op::OpImageSampleImplicitLod:
	case spv::Op::OpImageSampleExplicitLod:
	case spv::Op::OpImageSampleProjImplicitLod:
	case spv::Op::OpImageSampleProjExplicitLod:
	case spv::Op::OpImageSampleDrefImplicitLod:
	case spv::Op::OpImageSampleDrefExplicitLod:
	case spv::Op::OpImageSampleProjDrefImplicitLod:
	case spv::Op::OpImageSampleProjDrefExplicitLod:
		return validateImageOperandType(_instr);
	default:
		break;
	}

	return true;
}

bool spvgentwo::defaultimpl::validateImageOperandType(const Instruction& _instr)
{
	Module* module = _instr.getModule();
	const spv::Op op = _instr.getOperation();
	auto imgIt = _instr.getFirstActualOperand();
	auto coordIt = imgIt.next();
	auto drefCompoOrMask = coordIt.next();

	if (imgIt == nullptr || coordIt == nullptr)
	{
		module->logError("Insufficient number of arguments");
		return false;
	}

	const Type* imageType = imgIt->getInstruction()->getType();
	const Type* coordType = coordIt->getInstruction()->getType();

	Flag<spv::ImageOperandsMask> opMask = spv::ImageOperandsMask::MaskNone;
	Instruction::Iterator imageOp1 = nullptr;

	if (drefCompoOrMask && drefCompoOrMask->isLiteral())
	{
		imageOp1 = drefCompoOrMask.next();
		opMask = drefCompoOrMask->getLiteral().value;
	}
	else if(drefCompoOrMask && drefCompoOrMask->isInstruction())
	{
		imageOp1 = drefCompoOrMask + 2;
		if (drefCompoOrMask.next()) opMask = drefCompoOrMask.next()->getLiteral().value;
	}

	Instruction* op1 = imageOp1 != nullptr ? imageOp1->getInstruction() : nullptr;
	Instruction* op2 = imageOp1.next() != nullptr ? imageOp1.next()->getInstruction() : nullptr;
	const Type* type1 = op1 != nullptr ? op1->getType() : nullptr;
	const Type* type2 = op2 != nullptr ? op2->getType() : nullptr;;

	auto checkCoordAndOperandDim = [&]() ->bool
	{
		unsigned int coordLength = coordType->getScalarOrVectorLength() - (imageType->getImageArray() ? 1u : 0u);
		if (coordLength != type1->getScalarOrVectorLength() || coordLength != type2->getScalarOrVectorLength())
		{
			module->logError("Invalid derivative dimensions");
			return false;
		}
		return true;
	};

	for (unsigned int i = 0u; opMask != spv::ImageOperandsMask::MaskNone && i < (unsigned int)spv::ImageOperandsShift::ZeroExtend; ++i)
	{
		// TODO: get operands  within the loop and dont return in the switch
		spv::ImageOperandsMask mask = static_cast<spv::ImageOperandsMask>(1u << i);
		if ((opMask & mask) == mask)
		{
			switch (mask)
			{
			case spv::ImageOperandsMask::Bias:
				return module->logError(type1->isFloat(), "Bias operand must be of type float");
			case spv::ImageOperandsMask::Lod:
				return module->logError(op == spv::Op::OpImageFetch ? type1->isInt() : type1->isFloat(), "Lod operand must be of type float (or int for OpImageFetch)");
			case spv::ImageOperandsMask::Grad:
				if (checkCoordAndOperandDim() == false)
				{
					return false;
				}
				if (type1->isBaseTypeOf(spv::Op::OpTypeFloat) == false || type2->isBaseTypeOf(spv::Op::OpTypeFloat))
				{
					module->logError("Explicit lod grad operands must be scalar or vector of float");
					return false;
				}
				return true;
			case spv::ImageOperandsMask::ConstOffset:
				if (op1->isSpecOrConstant() == false)
				{
					module->logError("Image operand is not a constant op");
					return false;
				}
				[[fallthrough]];
			case spv::ImageOperandsMask::Offset:
				if (checkCoordAndOperandDim() == false)
				{
					return false;
				}
				if (type1->isBaseTypeOf(spv::Op::OpTypeInt) == false || type2->isBaseTypeOf(spv::Op::OpTypeInt))
				{
					module->logError("Explicit lod grad operands must be scalar or vector of integer");
					return false;
				}
				return true;
			case spv::ImageOperandsMask::ConstOffsets:
				break; // not implemented yet
			case spv::ImageOperandsMask::Sample:
				return module->logError(type1->isInt(), "Sample operand must be of type int");
			case spv::ImageOperandsMask::MinLod:
				return module->logError(type1->isFloat(), "MinLod operand must be of type float");
			case spv::ImageOperandsMask::MakeTexelAvailableKHR:
			case spv::ImageOperandsMask::MakeTexelVisibleKHR:
			case spv::ImageOperandsMask::NonPrivateTexelKHR:
			case spv::ImageOperandsMask::VolatileTexelKHR:
				return true; // reserved, no type check
			case spv::ImageOperandsMask::SignExtend:
				break; // not implemented yet
			case spv::ImageOperandsMask::ZeroExtend:
				break; // not implemented yet
			default:
				module->logError("Unknown operand mask");
				continue;
			}
		}
	}	

	return true;
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