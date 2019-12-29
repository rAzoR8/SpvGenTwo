#include "Instruction.h"
#include "BasicBlock.h"
#include "Type.h"
#include "Writer.h"
#include "InferResultType.h"
#include "Module.h"

spvgentwo::Instruction::~Instruction()
{
}

spvgentwo::BasicBlock* spvgentwo::Instruction::getBasicBlock()
{
	return m_parentType == ParentType::BasicBlock ? m_parent.pBasicBlock : nullptr;
}

const spvgentwo::BasicBlock* spvgentwo::Instruction::getBasicBlock() const
{
	return m_parentType == ParentType::BasicBlock ? m_parent.pBasicBlock : nullptr;
}

spvgentwo::Function* spvgentwo::Instruction::getFunction()
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getFunction();
	case ParentType::Function:
		return m_parent.pFunction;
	default:
		return nullptr;
	}
}

const spvgentwo::Function* spvgentwo::Instruction::getFunction() const
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getFunction();
	case ParentType::Function:
		return m_parent.pFunction;
	default:
		return nullptr;
	}
}

spvgentwo::Module* spvgentwo::Instruction::getModule()
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getModule();
	case ParentType::Function:
		return m_parent.pFunction->getModule();
	case ParentType::Module:
		return m_parent.pModule;
	default:
		return nullptr;
	}
}

const spvgentwo::Module* spvgentwo::Instruction::getModule() const
{
	switch (m_parentType)
	{
	case ParentType::BasicBlock:
		return m_parent.pBasicBlock->getModule();
	case ParentType::Function:
		return m_parent.pFunction->getModule();
	case ParentType::Module:
		return m_parent.pModule;
	default:
		return nullptr;
	}
}

void spvgentwo::Instruction::reset()
{
	m_Operation = spv::Op::OpNop;
	clear(); // clear operands
}

unsigned int spvgentwo::Instruction::getWordCount() const
{
	return 1u + static_cast<unsigned int>(m_Elements); // (m_elements is number of operands)
}

unsigned int spvgentwo::Instruction::getOpCode() const
{
	return ((unsigned int )m_Operation & spv::OpCodeMask) | (getWordCount() << spv::WordCountShift);
}

spv::Id spvgentwo::Instruction::getResultId() const
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false/* || empty()*/)
		return InvalidId;

	auto it = begin();
	if (resultType /*&& size() > 1u*/) // skip resultType operand 
	{
		++it;
	}
	return it->getResultId();
}

spv::Id spvgentwo::Instruction::resolveId(spv::Id& _resultId)
{
	for (Operand& op : *this)
	{
		switch (op.type)
		{
		case Operand::Type::Instruction:
			op.instruction->resolveId(_resultId);
			break;
		case Operand::Type::BranchTarget:
			op.branchTarget->front().resolveId(_resultId);
			break;
		default:
			break;
		}
	}

	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false)
		return InvalidId;

	auto it = begin();
	if (resultType) // skip resultType operand 
	{
		++it;
	}

	if (it->resultId == InvalidId)
	{
		it->resultId = ++_resultId;
	}

	return it->resultId;
}

spvgentwo::Instruction* spvgentwo::Instruction::getTypeInst() const
{
	if (hasResultType())
	{
		return front().getInstruction();
	}
	return nullptr;
}

const spvgentwo::Type* spvgentwo::Instruction::getType() const
{
	const Module* pModule = getModule();
	if (isType()) 
	{
		return pModule->getTypeInfo(this);
	}

	return pModule->getTypeInfo(getTypeInst());
}

spv::StorageClass spvgentwo::Instruction::getStorageClass() const
{
	switch (m_Operation)
	{
	case spv::Op::OpTypePointer:
		return static_cast<spv::StorageClass>((begin() + 1)->getLiteral().value);
	case spv::Op::OpVariable:
		return static_cast<spv::StorageClass>((begin() + 2)->getLiteral().value);
	default:
		return spv::StorageClass::Max;
	}
}

bool spvgentwo::Instruction::isType() const
{
	return isTypeOp(m_Operation);
}

bool spvgentwo::Instruction::isTerminator() const
{
	return isTerminatorOp(m_Operation);
}

bool spvgentwo::Instruction::isConstant() const
{
	return isConstantOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecConstant() const
{
	return isSpecOp(m_Operation);
}

bool spvgentwo::Instruction::isSpecOrConstant() const
{
	return isSpecOrConstantOp(m_Operation);
}

spv::Id spvgentwo::Instruction::write(IWriter* _pWriter, spv::Id& _resultId)
{
	const spv::Id ID = resolveId(_resultId);

	_pWriter->put(getOpCode());
	
	for (const Operand& operand : *this)
	{
		operand.write(_pWriter);
	}
	
	return ID;
}

void spvgentwo::writeInstructions(IWriter* _pWriter, const List<Instruction>& _instructions, spv::Id& _resultId)
{
	for (Instruction& instr : _instructions)
	{
		instr.write(_pWriter, _resultId);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::makeOp(const spv::Op _instOp, Instruction* _pOp1, Instruction* _pOp2, Instruction* _pOp3, Instruction* _pResultType)
{
	Instruction* pResultType = _pResultType;
	
	if (pResultType == nullptr)
	{
		if (getModule()->getInferResultType() != nullptr)
		{
			pResultType = getModule()->getInferResultType()->inferType(_instOp, _pOp1, _pOp2, _pOp3);
		}
		else
		{
			pResultType = inferType(_instOp, _pOp1, _pOp2, _pOp3);
		}
	}

	Instruction* pInst = makeOpEx(_instOp, pResultType, InvalidId, _pOp1);

	if (_pOp2 != nullptr)
	{
		pInst->addOperand(_pOp2);
	}
	if (_pOp3 != nullptr)
	{
		pInst->addOperand(_pOp3);
	}

	return pInst;
}

void spvgentwo::Instruction::opNop()
{
	makeOpEx(spv::Op::OpNop);
}

spvgentwo::Instruction* spvgentwo::Instruction::opUndef(Instruction* _pResultType)
{
	return makeOpEx(spv::Op::OpUndef, _pResultType, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opSizeOf(Instruction* _pPointerToVar)
{
	return makeOp(spv::Op::OpSizeOf, _pPointerToVar);
}

void spvgentwo::Instruction::opCapability(const spv::Capability _capability)
{
	makeOpEx(spv::Op::OpCapability, _capability);
}

void spvgentwo::Instruction::opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel)
{
	makeOpEx(spv::Op::OpMemoryModel, _addressModel, _memoryModel);
}

void spvgentwo::Instruction::opExtension(const char* _pExtName)
{
	makeOpEx(spv::Op::OpExtension, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opExtInstImport(const char* _pExtName)
{
	return makeOpEx(spv::Op::OpExtInstImport, InvalidId, _pExtName);
}

spvgentwo::Instruction* spvgentwo::Instruction::opLabel()
{
	return makeOpEx(spv::Op::OpLabel, InvalidId);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType)
{
	return makeOpEx(spv::Op::OpFunction, _pResultType, InvalidId, literal_t{ _functionControl.mask }, _pFuncType);
}

spvgentwo::Instruction* spvgentwo::Instruction::opFunctionParameter(Instruction* _pType)
{
	return makeOpEx(spv::Op::OpFunctionParameter, _pType, InvalidId);
}

void spvgentwo::Instruction::opReturn()
{
	makeOpEx(spv::Op::OpReturn);
}

void spvgentwo::Instruction::opReturnValue(Instruction* _pValue)
{
	makeOpEx(spv::Op::OpReturnValue, _pValue);
}

void spvgentwo::Instruction::opFunctionEnd()
{
	makeOpEx(spv::Op::OpFunctionEnd);
}

void spvgentwo::Instruction::opName(Instruction* _pTarget, const char* _pName)
{
	makeOpEx(spv::Op::OpName, _pTarget, _pName);
}

void spvgentwo::Instruction::opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName)
{
	makeOpEx(spv::Op::OpMemberName, _pTargetStructType, _memberIndex, _pName);
}

void spvgentwo::Instruction::opSelectionMerge(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control)
{
	makeOpEx(spv::Op::OpSelectionMerge, _pMergeBlock, _control);
}

void spvgentwo::Instruction::opBranch(BasicBlock* _pTargetBlock)
{
	makeOpEx(spv::Op::OpBranch, _pTargetBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock)
{
	makeOpEx(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock);
}

void spvgentwo::Instruction::opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight)
{
	makeOpEx(spv::Op::OpBranchConditional, _pCondition, _pTrueBlock, _pFalseBlock, _trueWeight, _falseWeight);
}

spvgentwo::Instruction* spvgentwo::Instruction::opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer)
{
	if (_pInitializer == nullptr)
	{
		return makeOpEx(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass);
	}
	else
	{
		return makeOpEx(spv::Op::OpVariable, _pResultType, InvalidId, _storageClass, _pInitializer);
	}
}

spvgentwo::Instruction* spvgentwo::Instruction::opOuterProduct(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pLeftType = _pLeftTypeInstr->getType();
	const Type* pRightType = _pRightTypeInstr->getType();

	if (pLeftType->isVectorOfFloat() && pRightType->isVectorOfFloat() && pLeftType->hasSameBase(*pRightType))
	{
		return makeOp(spv::Op::OpOuterProduct, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opOuterProduct are not scalar vector of length 3");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opDot(Instruction* _pLeft, Instruction* _pRight)
{
	Instruction* _pLeftTypeInstr = _pLeft->getTypeInst();
	Instruction* _pRightTypeInstr = _pRight->getTypeInst();

	const Type* pType = _pLeftTypeInstr->getType();
	if (_pLeftTypeInstr == _pRightTypeInstr && pType->isVectorOfFloat())
	{
		return makeOp(spv::Op::OpDot, _pLeft, _pRight);
	}

	getModule()->logError("Operands of opDot are not scalar vector of length 3");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAny(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAny, _pBoolVec);
	}

	getModule()->logError("Operands of opAny is not a vector of bool");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opAll(Instruction* _pBoolVec)
{
	if (_pBoolVec->getType()->isVectorOfBool())
	{
		return makeOp(spv::Op::OpAll, _pBoolVec);
	}

	getModule()->logError("Operands of opAll is not a vector of bool");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opCopyObject(Instruction* _pObject)
{
	return makeOpEx(spv::Op::OpCopyObject, _pObject->getTypeInst(), InvalidId, _pObject);
}

spvgentwo::Instruction* spvgentwo::Instruction::opTranspose(Instruction* _pMatrix)
{
	return makeOp(spv::Op::OpTranspose, _pMatrix);
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt)
{
	return makeOp(spv::Op::OpVectorExtractDynamic, _pVector, _pIndexInt);
}

spvgentwo::Instruction* spvgentwo::Instruction::opVectorInsertDynamic(Instruction* _pVector, Instruction* _pComponent, Instruction* _pIndexInt)
{
	const Type* pVecType = _pVector->getType();

	if (pVecType->isVector() && pVecType->front() == *_pComponent->getType())
	{
		return makeOp(spv::Op::OpVectorInsertDynamic, _pVector, _pComponent, _pIndexInt);
	}

	getModule()->logError("opVectorInsertDyanmic: _pVector component type does not match type of _pComponent");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSelect(Instruction* _pCondBool, Instruction* _pTrueObj, Instruction* _pFalseObj)
{
	const Type* trueType = _pTrueObj->getType();
	const Type* falseType = _pFalseObj->getType();
	const Type* condType = _pCondBool->getType();

	if (*trueType == *falseType && condType->isScalarOrVectorOf(spv::Op::OpTypeBool) && 
		condType->getVectorComponentCount() == trueType->getVectorComponentCount())
	{
		// Before version1.4, results are only computed per component.
		// Before version1.4, Result Type must be a pointer, scalar, or vector.Starting withv ersion1.4, Result Type can additionally be a composite type other than a vector.

		if (trueType->isScalar() || trueType->isVector() || trueType->isPointer() ||
			(getModule()->getSpvVersion() >= makeVersion(1u, 4u) && trueType->isComposite()))
		{
			return makeOpEx(spv::Op::OpSelect, _pTrueObj->getTypeInst(), InvalidId, _pCondBool, _pTrueObj, _pFalseObj);
		}

		getModule()->logError("Object arguments of opSelect are not of type Scalar|Vector|Pointer|Composite");

		return nullptr;
	}

	getModule()->logError("Condition type does not match extent of object arguments");

	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opSampledImage(Instruction* _pImage, Instruction* _pSampler)
{
	const Type* imageType = _pImage->getType();
	const Type* samplerType = _pSampler->getType();

	if (imageType->isImage() && samplerType->isSampler() && imageType->getImageSamplerAccess() != SamplerImageAccess::Storage && imageType->getImageDimension() != spv::Dim::SubpassData)
	{
		return makeOp(spv::Op::OpSampledImage, _pImage, _pSampler);
	}

	getModule()->logError("Image or sampler type does not match (storage / subpass image not allowed");
	
	return nullptr;
}

spvgentwo::Instruction* spvgentwo::Instruction::opImageSample(const spv::Op _imageSampleOp, Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDrefOrCompnent)
{
	Module& module = *getModule();
	const Type* type = _pSampledImage->getType();
	const Type* imageType = type->isSampledImage() ? &type->front() : type;
	const Type* coordType = _pCoordinate->getType();

	bool isDref = false;
	bool isProj = false;
	bool isComponent = false;
	bool coordCanBeInt = false;
	bool checkCoords = false;

	auto checkCoordinateType = [&]() -> bool
	{
		if (checkCoords == false)
			return true;

		unsigned int dim = 0u;

		switch (imageType->getImageDimension())
		{
		case spv::Dim::Dim1D:
		case spv::Dim::Buffer:
			dim = 1u;
			break;
		case spv::Dim::Dim2D:
		case spv::Dim::Rect:
		case spv::Dim::SubpassData:
			dim = 2u;
			break;
		case spv::Dim::Dim3D:
		case spv::Dim::Cube:
			dim = 3u;
			break;
		default:
			module.logError("Image dimension not supported/implemented");
			return false;
		}

		if (imageType->getImageArray())
		{
			dim += 1u;
		}

		if (isProj)
		{
			dim += 1u;
		}

		if (dim > 1u && coordType->getVectorComponentCount() < dim)
		{
			module.logError("Dimension of coordinates does not match image type");
			return false;
		}

		if (coordType->isScalarOrVectorOf(spv::Op::OpTypeInt))
		{
			if (coordCanBeInt == false)
			{
				module.logError("Image operation does not support integer coordinates");
				return false;
			}
		}
		else if (coordType->isScalarOrVectorOf(spv::Op::OpTypeFloat) == false)
		{
			module.logError("Coordinate type must be scalar or vector of float");
			return false;
		}

		return true;
	};

	auto checkDrefComponent = [&]() -> bool
	{
		if (isDref || isComponent)
		{
			if (_pDrefOrCompnent == nullptr)
			{
				module.logError("Depth reference parameter is null");
				return false;
			}
			if (isDref && _pDrefOrCompnent->getType()->isF32() == false)
			{
				module.logError("Depth reference value must be of type float (32bit)");
				return false;
			}
			if (isComponent && _pDrefOrCompnent->getType()->isI32() == false)
			{
				module.logError("Component index must be of type integer (32bit)");
				return false;
			}
		}
		else if (_pDrefOrCompnent != nullptr)
		{
			module.logError("Image operation does not consume Component or Depth reference value, but operand was supplied");
			return false;
		}
		return true;
	};

	switch (_imageSampleOp)
	{
	case spv::Op::OpImageFetch:
		if (type->isImage() == false || (imageType->getImageSamplerAccess() != SamplerImageAccess::Sampled) || (imageType->getImageDimension() == spv::Dim::Cube))
		{
			module.logError("OpImageFetch requires _pSampledImage of type opImage. Its Dim operand cannot be Cube, and its Sampled operand must be 1.");
			return nullptr;
		}	
		checkCoords = true; coordCanBeInt = true;
		break;
	case spv::Op::OpImageGather: checkCoords = true; isComponent = true; break;
	case spv::Op::OpImageDrefGather: isDref = true;  checkCoords = true; isComponent = true; break;
	case spv::Op::OpImageSampleImplicitLod: checkCoords = true; break;
	case spv::Op::OpImageSampleExplicitLod: checkCoords = true; coordCanBeInt = true; break;
	case spv::Op::OpImageSampleProjImplicitLod: isProj = true; checkCoords = true; coordCanBeInt = true; break;
	case spv::Op::OpImageSampleProjExplicitLod: isProj = true; checkCoords = true; break;
	case spv::Op::OpImageSampleDrefImplicitLod: checkCoords = true; isDref = true; break;
	case spv::Op::OpImageSampleDrefExplicitLod: checkCoords = true;  isDref = true; break;
	case spv::Op::OpImageSampleProjDrefImplicitLod: isProj = true; checkCoords = true; isDref = true; break;
	case spv::Op::OpImageSampleProjDrefExplicitLod: isProj = true; checkCoords = true; isDref = true; break;

		break;
	default:
		module.logError("_imageSampleOp is not supported / implemented");
		return nullptr;
	}

	if (!checkDrefComponent() || !checkCoordinateType())
	{
		return nullptr;
	}

	Instruction* pInstruction = makeOp(_imageSampleOp, _pSampledImage, _pCoordinate, _pDrefOrCompnent);

	return pInstruction;
}

bool spvgentwo::Instruction::validateImageOperandType(spv::Op _op, Instruction* _pImage, Instruction* _pCoordinate, spv::ImageOperandsMask _mask, List<Instruction*>& _inOutOperands)
{
	Module* module = _pImage->getModule();
	const Type* imageType = _pImage->getType();

	Instruction* __operand1 = nullptr;
	Instruction* __operand2 = nullptr;
	const Type* __type1 = nullptr;
	const Type* __type2 = nullptr;

	auto operand1 = [&]() -> Instruction* { return __operand1 != nullptr ? __operand1 : (__operand1 = _inOutOperands.pop_front()); };
	auto operand2 = [&]() -> Instruction* { operand1(); return __operand2 != nullptr ? __operand2 : (__operand2 = _inOutOperands.pop_front()); };
	auto type1 = [&]() -> const Type* { return __type1 != nullptr ? __type1 : (__type1 = operand1()->getType()); };
	auto type2 = [&]() -> const Type* { return __type2 != nullptr ? __type2 : (__type2 = operand2()->getType()); };

	auto checkCoordAndOperandDim = [&]() ->bool
	{
		const Type* coordType = _pCoordinate->getType();
		unsigned int coordLength = coordType->getScalarOrVectorLength() - (imageType->getImageArray() ? 1u : 0u);
		if (coordLength != type1()->getScalarOrVectorLength() || coordLength != type2()->getScalarOrVectorLength())
		{
			module->logError("Invalid derivative dimensions");
			return false;
		}
		return true;
	};

	switch (_mask)
	{
	case spv::ImageOperandsMask::Bias:
		return type1()->isFloat();
	case spv::ImageOperandsMask::Lod:
		return _op == spv::Op::OpImageFetch ? type1()->isInt() : type1()->isFloat();
	case spv::ImageOperandsMask::Grad:
		if (checkCoordAndOperandDim() == false) 
		{
			return false;		
		}
		if (type1()->isBaseTypeOf(spv::Op::OpTypeFloat) == false || type2()->isBaseTypeOf(spv::Op::OpTypeFloat))
		{
			module->logError("Explicit lod grad operands must be scalar or vector of float");
			return false;
		}
		return true;
	case spv::ImageOperandsMask::ConstOffset:
		if (operand1()->isSpecOrConstant() == false)
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
		if (type1()->isBaseTypeOf(spv::Op::OpTypeInt) == false || type2()->isBaseTypeOf(spv::Op::OpTypeInt))
		{
			module->logError("Explicit lod grad operands must be scalar or vector of integer");
			return false;
		}
		return true;
	case spv::ImageOperandsMask::ConstOffsets:
		break; // not implemented yet
	case spv::ImageOperandsMask::Sample:
		return type1()->isInt();
	case spv::ImageOperandsMask::MinLod:
		return type1()->isFloat();
	case spv::ImageOperandsMask::MakeTexelAvailableKHR:
	case spv::ImageOperandsMask::MakeTexelVisibleKHR:
	case spv::ImageOperandsMask::NonPrivateTexelKHR:
	case spv::ImageOperandsMask::VolatileTexelKHR:
		return true; // reserved, no type check
	case spv::ImageOperandsMask::SignExtend:
		break; // not implemented yet
	case spv::ImageOperandsMask::ZeroExtend:
		break; // not implemented yet
	case spv::ImageOperandsMask::MaskNone:
		module->logError("Invalid image operand mask");
		return false;
	}

	module->logWarning("Image operand mask type check not implemented");
	return true;
}

spv::Id spvgentwo::Instruction::getAssignedID() const
{
	bool resultId = false, resultType = false;
	spv::HasResultAndType(m_Operation, &resultId, &resultType);

	if (resultId == false)
		return InvalidId;

	auto it = begin();
	if (resultType) // skip resultType operand 
	{
		++it;
	}

	return it->resultId;
}