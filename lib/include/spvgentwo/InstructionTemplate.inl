#pragma once

#include "Type.h"
#include "Module.h"
#include "Instruction.h"

namespace spvgentwo
{
	template<class ...Args>
	inline Instruction::Instruction(Module* _pModule, const spv::Op _op, Args&& ..._args) : List(_pModule->getAllocator()),
		m_parentType(ParentType::Module)
	{
		m_parent.pModule = _pModule;
		makeOp(_op, stdrep::forward<Args>(_args)...);
	}

	template<class ...Args>
	inline Instruction::Instruction(Function* _pFunction, const spv::Op _op, Args&& ..._args) : List(_pFunction->getAllocator()),
		m_parentType(ParentType::Function)
	{
		m_parent.pFunction = _pFunction;
		makeOp(_op, stdrep::forward<Args>(_args)...);
	}

	template<class ...Args>
	inline Instruction::Instruction(BasicBlock* _pBasicBlock, const spv::Op _op, Args&& ..._args) : List(_pBasicBlock->getAllocator()),
		m_parentType(ParentType::BasicBlock)
	{
		m_parent.pBasicBlock = _pBasicBlock;
		makeOp(_op, stdrep::forward<Args>(_args)...);
	}

	template<class ...Args>
	inline Instruction* Instruction::makeOp(const spv::Op _op, Args&& ..._args)
	{
		reset();

		m_Operation = _op;

		if constexpr (sizeof...(_args) > 0u)
		{
			makeOpInternal(stdrep::forward<Args>(_args)...);
		}

		inferResultTypeOperand();

		validateOperands();

		return this;
	}
	
	template<class T>
	inline Instruction* Instruction::bitcast(Instruction* _pOperand)
	{
		return opBitcast(getModule()->template type<T>(), _pOperand);
	}

	template<class ...ArgInstr>
	inline Instruction* Instruction::opSpecConstantOp(Instruction* _pResultType, spv::Op _opcode, ArgInstr* ..._instrOperands)
	{
		if constexpr (sizeof...(_instrOperands) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ArgInstr>...>, "ArgInstr must be of type Instruction");
		}

		// TODO: check _opcode for valid operations
		return makeOp(spv::Op::OpSpecConstantOp, _pResultType, InvalidId, _opcode, _instrOperands...);
	}

	template<class T, class ...Args>
	inline void Instruction::makeOpInternal(T&& _first, Args&& ..._args)
	{
		static_assert(traits::is_same_base_type_v<T, sgt_nullptr_t> == false, "Can't deduce pointer type from nullptr");

		if constexpr (traits::is_same_base_type_v<T, Instruction*>)
		{
			addOperand(stdrep::forward<T>(_first)); // same overload as above, just make it easier to debug	
		}
		else if constexpr (traits::is_same_base_type_v<T, BasicBlock*>)
		{
			addOperand(stdrep::forward<T>(_first)); // same overload as above, just make it easier to debug
		}
		else if constexpr (traits::is_same_base_type_v<T, spv::Id>) 
		{
			addOperand(stdrep::forward<T>(_first)); // same overload as above, just make it easier to debug
		}
		else if constexpr (traits::is_same_base_type_v<T, literal_t>)
		{
			addOperand(stdrep::forward<T>(_first)); // same overload as above, just make it easier to debug
		}
		else if constexpr (stdrep::is_same_v<traits::remove_cvref_t<T>, int> || stdrep::is_same_v<traits::remove_cvref_t<T>, unsigned int>) // bitcast to 32 bit literal
		{
			addOperand(literal_t{ stdrep::forward<T>(_first)});
		}
		else
		{
			appendLiterals(stdrep::forward<T>(_first));
		}

		if constexpr (sizeof...(_args) > 0u)
		{
			makeOpInternal(stdrep::forward<Args>(_args)...);
		}
	}

	template<class ...Args>
	inline void Instruction::appendLiterals(Args&& ..._args)
	{
		appendLiteralsToContainer(*this, stdrep::forward<Args>(_args)...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opExtInst(Instruction* _pResultType, Instruction* _pExtensionId, unsigned int _instOpCode, Operands ..._operands)
	{
		return makeOp(spv::Op::OpExtInst, _pResultType, InvalidId, _pExtensionId, literal_t{ _instOpCode }, _operands...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opExtInst(Instruction* _pResultType, const char* _pExtName, unsigned int _instOpCode, Operands ..._operands)
	{
		Instruction* _pExtImport = getModule()->addExtensionInstructionImport(_pExtName);
		return makeOp(spv::Op::OpExtInst, _pResultType, InvalidId, _pExtImport, literal_t{ _instOpCode }, _operands...);
	}

	template<class ...ArgInstr>
	inline Instruction* Instruction::opFunctionCall(Instruction* _pResultType, Instruction* _pFunction, ArgInstr* ..._args)
	{
		if constexpr (sizeof...(_args) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ArgInstr>...>, "ArgInstr must be of type Instruction");
		}

		if (_pResultType == nullptr || _pFunction == nullptr) return error();

		if (_pResultType->isType() && _pFunction->getOperation() == spv::Op::OpFunction)
		{
			return makeOp(spv::Op::OpFunctionCall, _pResultType, InvalidId, _pFunction, _args...);
		}

		getModule()->logError("_pResultType is not a type instruction or _pFunction is not OpFunction");

		return error();
	}

	template<class ...ArgInstr>
	inline Instruction* Instruction::call(Function* _pFunction, ArgInstr* ..._args)
	{
		if (_pFunction == nullptr) return error();
		return opFunctionCall(_pFunction->getReturnTypeInstr(), _pFunction->getFunction(), _args...);
	}

	template<class ...Instr>
	inline void Instruction::opEntryPoint(const spv::ExecutionModel _model, Instruction* _pFunction, const char* _pName, Instr* ..._instr)
	{
		if constexpr (sizeof...(_instr) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, Instr>...>, "Instr must be of type Instruction");
		}

		makeOp(spv::Op::OpEntryPoint, _model, _pFunction, _pName, _instr...);
	}

	template<class ...ExecModeLiteral>
	inline void Instruction::opExecutionMode(Instruction* _pEntryPoint, const spv::ExecutionMode _mode, ExecModeLiteral ..._args)
	{
		makeOp(spv::Op::OpExecutionMode, _pEntryPoint, _mode, _args...);
	}

	template<class ...ExecModeConstInstr>
	inline void Instruction::opExecutionModeId(Instruction* _pEntryPoint, const spv::ExecutionMode _mode, ExecModeConstInstr* ..._args)
	{
		if constexpr (sizeof...(_args) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ExecModeConstInstr>...>, "ExecModeConstInstr must be of type Instruction");

			if ((_args->isSpecOrConstant() && ...) == false)
			{
				getModule()->logError("Operand of OpExecutionModeId is not a constant instruction");
				return;
			}
		}

		makeOp(spv::Op::OpExecutionModeId, _pEntryPoint, _mode, _args...);
	}

	template<class ...Decorations>
	inline void Instruction::opDecorate(Instruction* _pTarget, spv::Decoration _decoration, Decorations ..._decorations)
	{
		makeOp(spv::Op::OpDecorate, _pTarget, _decoration, _decorations...);
	}

	template<class ...Decorations>
	inline void Instruction::opMemberDecorate(Instruction* _pTargetStructType, unsigned int _memberIndex, spv::Decoration _decoration, Decorations ..._decorations)
	{
		makeOp(spv::Op::OpMemberDecorate, _pTargetStructType, _memberIndex, _decoration, _decorations...);
	}

	template<class ...Instr>
	inline void Instruction::opDecorateId(Instruction* _pTarget, spv::Decoration _decoration, Instruction* _pId, Instr* ..._ids)
	{
		if constexpr (sizeof...(_ids) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, Instr>...>, "Instr must be of type Instruction");
		}

		makeOp(spv::Op::OpDecorateId, _pTarget, _decoration, _pId, _ids...);
	}

	template<class ...VarInst>
	inline Instruction* Instruction::opPhi(Instruction* _pVar, VarInst* ..._variables)
	{
		makeOp(spv::Op::OpPhi, _pVar->getResultTypeInstr(), InvalidId);

		auto addVar = [&](Instruction* var)
		{
			addOperand(var);
			addOperand(var->getBasicBlock());
		};

		addVar(_pVar);

		(addVar(_variables), ...);
		return this;
	}

	template<class ...LoopControlParams>
	inline void Instruction::opLoopMerge(BasicBlock* _pMergeBlock, BasicBlock* _pContinueBlock, const Flag<spv::LoopControlMask> _loopControl, LoopControlParams ..._params)
	{
		makeOp(spv::Op::OpLoopMerge, _pMergeBlock, _pContinueBlock, literal_t{ _loopControl }, _params...);
	}

	template<class ...ConstInstr>
	inline Instruction* Instruction::opAccessChain(Instruction* _pResultType, Instruction* _pBase, ConstInstr* ..._pIndices)
	{
		if constexpr (sizeof...(_pIndices) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ConstInstr>...>, "ConstInstr must be of type Instruction");
		}

		if (_pResultType == nullptr || _pBase == nullptr) return error();

		if(_pResultType->isType() == false || _pResultType->getType()->isPointer() == false) 
		{
			getModule()->logError("_pResultType is not a (pointer) type instruction");
			return error();
		}

		return makeOp(spv::Op::OpAccessChain, _pResultType, InvalidId, _pBase, _pIndices...);
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opAccessChain(Instruction* _pBase, IntIndices ..._indices)
	{
		if (_pBase == nullptr) return error();

		if constexpr (sizeof...(_indices) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<unsigned int, IntIndices>...>, "IntIndices must be of type unsigned int");
		}

		// Base must be a pointer, pointing to the base of a composite object.
		const Type* pBaseType = _pBase->getType();
		if (pBaseType == nullptr) return error();

		auto it = pBaseType->getSubType(0u, _indices...); // base is a pointer type, so 0 is used to get the inner type

		if (it != nullptr)
		{
			Module* pModule = _pBase->getModule();

			// Result Type must be an OpTypePointer.
			// Its Type operand must be the type reached by walking the Base’s type hierarchy down to the last provided index in Indexes, and its Storage Class operand must be the same as the Storage Class of Base.
	
			Instruction* pResultType = pModule->addType(it->wrapPointer(pBaseType->getStorageClass()));

			return makeOp(spv::Op::OpAccessChain, pResultType, InvalidId, _pBase, pModule->template constant<unsigned int>(_indices)...);
		}

		getModule()->logError("Failed to deduct composite type of base operand for OpAccessChain");

		return error();
	}

	template<class ...ConstInstr>
	inline Instruction* Instruction::opInBoundsAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstIndex, ConstInstr* ..._pIndices)
	{
		if constexpr (sizeof...(_pIndices) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ConstInstr>...>, "ConstInstr must be of type Instruction");
		}

		if (_pResultType == nullptr || _pBase == nullptr || _pConstIndex == nullptr) return error();

		if (_pResultType->isType() == false)
		{
			getModule()->logError("_pResultType is not a type instruction");
			return error();
		}

		if (_pConstIndex->isSpecOrConstant() == false)
		{
			getModule()->logError("_pConstIndex is not a constant instruction");
			return error();
		}

		return makeOp(spv::Op::OpInBoundsAccessChain, _pResultType, InvalidId, _pBase, _pConstIndex, _pIndices...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opLoad(Instruction* _pPointerToVar, const Flag<spv::MemoryAccessMask> _memOperands, Operands ..._operands)
	{
		if (_pPointerToVar == nullptr) return error();

		const Type* ptrType = _pPointerToVar->getType();
		if (ptrType == nullptr) return error();

		if(ptrType->isPointer() == false)
		{
			getModule()->logError("_pPointerToVar is not of type pointer");
			return error();
		}

		if(_memOperands.empty() && sizeof...(_operands) > 0)
		{
			getModule()->logError("OpLoad: no MemoryAccessMask provided for _operands...");
			return error();
		}

		// Result Type is the type of the loaded object.It must be a type with ﬁxed size; i.e., it cannot be, nor include, any OpTypeRuntimeArray types.
		// Pointer is the pointer to load through.Its type must be an OpTypePointer whose Type operand is the same as Result Type.
		Instruction* pResultType = getModule()->addType(ptrType->front());
		return makeOp(spv::Op::OpLoad, pResultType, InvalidId, _pPointerToVar, literal_t{ _memOperands }, _operands...);
	}

	template<class ...Operands>
	inline void Instruction::opStore(Instruction* _pPointerToVar, Instruction* _valueToStore, const Flag<spv::MemoryAccessMask> _memOperands, Operands ..._operands)
	{
		if (_pPointerToVar == nullptr || _valueToStore == nullptr)
			return;

		const Type* ptrtype = _pPointerToVar->getType();
		const Type* valtype = _valueToStore->getType();

		if (ptrtype == nullptr || valtype == nullptr)
			return;

		if (_memOperands.empty() && sizeof...(_operands) > 0)
		{
			getModule()->logError("OpStore: no MemoryAccessMask provided for _operands...");
			return;
		}

		if (ptrtype->isPointer() && ptrtype->front() == *valtype)
		{
			makeOp(spv::Op::OpStore, _pPointerToVar, _valueToStore, literal_t{ _memOperands }, _operands...);
		}
		else
		{
			getModule()->logError("Type of _pPointerToVar is not a pointer or the type pointed to does not match the type of _valueToStore");
		}
	}

	template<class ...Operands>
	inline void Instruction::opCopyMemorySizedImpl(Instruction* _pTargetPtr, Instruction* _pSourcePtr, Instruction* _pSizeInt, Flag<spv::MemoryAccessMask> _targetMemOperands, Flag<spv::MemoryAccessMask> _sourceMemOperands, Operands ..._operands)
	{
		Module* module = getModule();

		const Type* targetType = _pTargetPtr->getType();
		const Type* sourceType = _pSourcePtr->getType();

		if (targetType == nullptr || sourceType == nullptr)
		{
			return;
		}

		//  If present, any Memory Operands must begin with a memory operand literal.If not present, it is the same as
		//	specifying the memory operand None. Before version 1.4, at most one memory operands mask can be provided.
		//	Starting with version 1.4 two masks can be provided, as described in Memory Operands. If no masks or only one
		//	mask is present, it applies to both Source and Target. If two masks are present, the first applies to Target and must not
		//	include MakePointerVisible, and the second applies to Source and must not include MakePointerAvailable

		if (targetType->isPointer() == false || sourceType->isPointer() == false)
		{
			module->logError("Operand of OpCopyMemory/Sized is not a pointer type");
			return;
		}		

		if(_pSizeInt != nullptr)
		{
			const Type* sizeType = _pSizeInt->getType();
			if (sizeType == nullptr) return;

			//  Size is the number of bytes to copy. It must have a scalar integer type. If it is a
			//	constant instruction, the constant value must not be 0. It is invalid for both the
			//	constant’s type to have Signedness of 1 and to have the sign bit set. Otherwise,
			//	as a run - time value, Size is treated as unsigned, and if its value is 0, no memory
			//	access is made.

			if(sizeType->isInt() == false)
			{
				module->logError("Operand _pSizeInt of OpCopyMemorySized must be of type scalar integer");
				return;
			}

			if (_pSizeInt->isConstant())
			{
				if(sizeType->isSigned())
				{
					module->logError("Operand _pSizeInt of OpCopyMemorySized must be of type scalar unsigned integer if OpConstant");
					return;
				}

				bool constZero = true;
				for(unsigned int val : _pSizeInt->getConstant()->getData()) // could be 64bit for some reason
				{
					if(val != 0u)
					{
						constZero = false;
						break;
					}
				}

				if(constZero)
				{
					module->logError("Operand _pSizeInt of OpCopyMemorySized must be not be 0 valued OpConstant");
					return;
				}
			}
		}

		auto makeOpCopyMemory = [&](auto... args)
		{
			if(_pSizeInt == nullptr)
			{
				if( targetType->front().isVoid() || sourceType->front().isVoid() )
				{
					module->logError( "Operand of OpCopyMemory must not contain any pointer to OpTypeVoid" );
					return;
				}
				else if( targetType->containsType( spv::Op::OpTypeRuntimeArray ) || sourceType->containsType( spv::Op::OpTypeRuntimeArray ) )
				{
					module->logError( "Operand of OpCopyMemory must not contain any OpTypeRuntimeArray" );
					return;
				}
				else if( targetType->front() != sourceType->front() )
				{
					module->logError( "Operand types for _pTargetPtr and _pSourcePtr of OpCopyMemory don't match" );
					return;
				}

				makeOp(spv::Op::OpCopyMemory, _pTargetPtr, _pSourcePtr, args...);
			}
			else
			{
				makeOp(spv::Op::OpCopyMemorySized, _pTargetPtr, _pSourcePtr, _pSizeInt, args...);
			}
		};

		// no memory operands provided
		if (_targetMemOperands.empty() && _sourceMemOperands.empty())
		{
			if constexpr (sizeof...(_operands) > 0) 
			{
				module->logError("OpCopyMemory: no MemoryAccessMask provided for _operands...");
				return;
			}

			makeOpCopyMemory();
			return; // early out
		}

		if (module->getSpvVersion() <= makeVersion(1u, 4u) && _sourceMemOperands)
		{
			module->logError("Operand _sourceMemOperands of OpCopyMemory not supported before SPIR-V 1.5");
			return;
		}

		if (_sourceMemOperands.empty())
		{
			makeOpCopyMemory(literal_t{ _targetMemOperands }, _operands...);
		}
		else // both operands masks set
		{
			if ((_targetMemOperands & spv::MemoryAccessMask::MakePointerVisible) ||
				(_sourceMemOperands & spv::MemoryAccessMask::MakePointerAvailable))
			{
				module->logError("Operand of OpCopyMemory: _targetMemOperands may not include MakePointerVisible and _sourceMemOperands may not include MakePointerAvailable");
				return;
			}

			makeOpCopyMemory(literal_t{ _targetMemOperands }, literal_t{ _sourceMemOperands }, _operands...);
		}
	}

	template<class ...Components>
	inline Instruction* Instruction::opVectorShuffle(Instruction* _pVector1, Instruction* _pVector2, Components ..._components)
	{
		constexpr auto componentCount = sizeof...(_components);

		static_assert(componentCount > 1u && componentCount < 5u, "Invalid number of component indices [2..4]");

		if constexpr (sizeof...(_components) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<unsigned int, Components>...>, "Components must be of type unsigned int");
		}

		if (_pVector1 == nullptr || _pVector2 == nullptr) return error();

		const Type* lType = _pVector1->getType();
		const Type* rType = _pVector2->getType();

		if (lType == nullptr || rType == nullptr) return error();

		if (lType->isVector() && rType->isVector() && lType->getBaseType() == rType->getBaseType())
		{
			Instruction* resultType = getModule()->addType(lType->getBaseType().wrapVector(componentCount));
			return makeOp(spv::Op::OpVectorShuffle, resultType, InvalidId, _pVector1, _pVector2, literal_t{ _components }...);
		}

		getModule()->logError("Argument of opVectorShuffle is not a matching vector type or opUndef");

		return error();
	}

	template<class ...ConstituentInstr>
	inline Instruction* Instruction::opCompositeConstruct(Instruction* _pResultType, Instruction* _pFirstConstituent, ConstituentInstr* ..._constituents)
	{
		if constexpr (sizeof...(_constituents) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<Instruction, ConstituentInstr>...>, "ConstituentInstr must be of type Instruction");
		}

		if (_pResultType == nullptr || _pFirstConstituent == nullptr) return error();

		const Type* type =  _pResultType->getType();
		if (type == nullptr) return error();

		if (type->isComposite() == false)
		{
			getModule()->logError("Result type of opCompositeConstruct is not a composite type");
			return error();
		}

		return makeOp(spv::Op::OpCompositeConstruct, _pResultType, InvalidId, _pFirstConstituent, _constituents...);
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opCompositeExtract(Instruction* _pComposite, IntIndices ..._indices)
	{
		if constexpr (sizeof...(_indices) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<unsigned int, IntIndices>...>, "IntIndices must be of type unsigned int");
		}

		if (_pComposite == nullptr) return error();

		const Type* pBaseType = _pComposite->getType();
		if (pBaseType == nullptr) return error();

		Module* pModule = _pComposite->getModule();

		if (pBaseType->isComposite() == false)
		{
			pModule->logError("Argument of opCompositeExtract is not a composite type");
			return error();
		}

		auto it = pBaseType->getSubType(_indices...);

		if (it != nullptr)
		{
			Instruction* pResultType = pModule->addType(*it);
			return makeOp(spv::Op::OpCompositeExtract, pResultType, InvalidId, _pComposite, literal_t{ _indices }...);
		}

		pModule->logError("Invalid index sequence specified for composite type extraction");

		return error();
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opCompositeInsert(Instruction* _pComposite, Instruction* _pValue, IntIndices ..._indices)
	{
		if constexpr (sizeof...(_indices) > 0u)
		{
			static_assert(stdrep::conjunction_v<stdrep::is_same<unsigned int, IntIndices>...>, "IntIndices must be of type unsigned int");
		}

		if (_pComposite == nullptr || _pValue == nullptr) return error();

		const Type* pBaseType = _pComposite->getType();
		if (pBaseType == nullptr) return error();

		Module* pModule = _pComposite->getModule();

		if (pBaseType->isComposite() == false)
		{
			pModule->logError("Argument of opCompositeInsert is not a composite type");
			return error();
		}

		auto it = pBaseType->getSubType(_indices...);

		if (it != nullptr)
		{
			const Type* pValueType = _pValue->getType();
			if (pValueType == nullptr) return error();

			if (*it == *pValueType)
			{
				return makeOp(spv::Op::OpCompositeInsert, _pComposite->getResultTypeInstr(), InvalidId, _pValue, _pComposite, literal_t{ _indices }...);
			}

			pModule->logError("Value type does not match composite insertion type");
			return error();
		}

		pModule->logError("Invalid index sequence specified for composite insertion");

		return error();
	}

	template<class ...ImageOperands>
	inline Instruction* Instruction::genericImageOp(const spv::Op _imageOp, Instruction* _pTargetImage, Instruction* _pCoordinate, Instruction* _pDrefOrCompnent, const Flag<spv::ImageOperandsMask> _imageOperands, ImageOperands ..._operands)
	{
		Module& module = *getModule();
		const Type* type = _pTargetImage->getType();
		const Type* coordType = _pCoordinate->getType();

		if (type == nullptr || coordType == nullptr)
		{
			return error();		
		}

		if (type->isImage() == false && type->isSampledImage() == false)
		{
			return error();
		}

		const Type* imageType = type->isSampledImage() ? &type->front() : type;

		bool isDref = false;
		bool isComponent = false;
		bool isSampled = false; // type must be OpTypeSampledImage

		Flag<CheckImgCoord> coordCheckArgs;

		auto checkDrefComponent = [&]() -> bool
		{
			if (isDref || isComponent)
			{
				if (_pDrefOrCompnent == nullptr || _pDrefOrCompnent->getType() == nullptr)
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

		// TODO: sparse image ops

		switch (_imageOp)
		{
		case spv::Op::OpImageRead:
		//case spv::Op::OpImageSparseRead:
			if (imageType->getImageSamplerAccess() == SamplerImageAccess::Sampled)
			{
				module.logError("OpImageRead requires _pTargetImage of type OpImage. Its 'Sampled' operand must NOT be 1.");
				return error();
			}
			isSampled = false;
			coordCheckArgs |= CheckImgCoord::MustBeInt;
			break;
		//case spv::Op::OpImageSparseFetch:
		case spv::Op::OpImageFetch:
			if ((imageType->getImageSamplerAccess() != SamplerImageAccess::Sampled) || (imageType->getImageDimension() == spv::Dim::Cube))
			{
				module.logError("OpImageFetch requires _pTargetImage of type OpImage. Its Dim operand cannot be Cube, and its 'Sampled' operand must be 1.");
				return error();
			}
			isSampled = false;
			coordCheckArgs |= CheckImgCoord::CanBeInt;
			break;
		case spv::Op::OpImageDrefGather:
			isDref = true; [[fallthrough]];
		case spv::Op::OpImageGather:
			isSampled = true;
			isComponent = !isDref;
			coordCheckArgs |= CheckImgCoord::CanBeInt;
			if (spv::Dim d = imageType->getImageDimension(); d != spv::Dim::Dim2D && d != spv::Dim::Cube && d != spv::Dim::Rect)
			{
				module.logError("OpImageGather requres Dim of sampled image to be 2D, Cube or Rect");
				return error();
			}
			break;
		case spv::Op::OpImageSampleImplicitLod:			isSampled = true; break;
		case spv::Op::OpImageSampleExplicitLod:			isSampled = true; coordCheckArgs |= CheckImgCoord::CanBeInt; break;
		case spv::Op::OpImageSampleProjImplicitLod:		isSampled = true; coordCheckArgs |= CheckImgCoord::CanBeInt; coordCheckArgs |= CheckImgCoord::IsProjective; break;
		case spv::Op::OpImageSampleProjExplicitLod:		isSampled = true; coordCheckArgs |= CheckImgCoord::IsProjective; break;
		case spv::Op::OpImageSampleDrefImplicitLod:		isSampled = true; isDref = true; break;
		case spv::Op::OpImageSampleDrefExplicitLod:		isSampled = true; isDref = true; break;
		case spv::Op::OpImageSampleProjDrefImplicitLod: isSampled = true; coordCheckArgs |= CheckImgCoord::IsProjective; isDref = true; break;
		case spv::Op::OpImageSampleProjDrefExplicitLod: isSampled = true; coordCheckArgs |= CheckImgCoord::IsProjective; isDref = true; break;
		case spv::Op::OpImageQueryLod:					isSampled = true; coordCheckArgs |= CheckImgCoord::CanBeInt; break;

			break;
		default:
			module.logError("_imageOp is not supported / implemented");
			return error();
		}

		if (isSampled && type->isSampledImage() == false)
		{
			module.logError("_imageOp requires _pTargetImage operand to be of type OpTypeSampledImage");
			return error();
		}
		else if (!isSampled && type->isImage() == false)
		{
			module.logError("_imageOp requires _pTargetImage operand to be of type OpTypeImage");
			return error();
		}

		if (!checkDrefComponent() || !checkImageCoordinateType(imageType, coordType, coordCheckArgs))
		{
			return error();
		}

		if (_pDrefOrCompnent == nullptr)
		{
			if (_imageOperands == spv::ImageOperandsMask::MaskNone)
			{
				makeOp(_imageOp, InvalidInstr, InvalidId, _pTargetImage, _pCoordinate);
			}
			else
			{
				makeOp(_imageOp, InvalidInstr, InvalidId, _pTargetImage, _pCoordinate, literal_t{ _imageOperands }, _operands...);
			}
		}
		else
		{
			if (_imageOperands == spv::ImageOperandsMask::MaskNone)
			{
				makeOp(_imageOp, InvalidInstr, InvalidId, _pTargetImage, _pCoordinate, _pDrefOrCompnent);
			}
			else
			{
				makeOp(_imageOp, InvalidInstr, InvalidId, _pTargetImage, _pCoordinate, _pDrefOrCompnent, literal_t{ _imageOperands }, _operands...);
			}
		}

		return this; // success
	}

	template<class ...ImageOperands>
	inline Instruction* Instruction::opImageWrite(Instruction* _pImage, Instruction* _pCoordinate, Instruction* _pTexel, const Flag<spv::ImageOperandsMask> _imageOperands, ImageOperands ..._operands)
	{
		const Type* imageType = _pImage->getType();
		const Type* coordType = _pCoordinate->getType();
		const Type* texelType = _pTexel->getType();
		Module* module = getModule();

		if (imageType == nullptr || coordType == nullptr || texelType == nullptr)
		{
			return error();		
		}

		if (imageType->isImage() == false || (imageType->getImageSamplerAccess() == SamplerImageAccess::Sampled) || imageType->getImageDimension() == spv::Dim::SubpassData)
		{
			module->logError("OpImageWrite requires _pTargetImage of type opImage. Its 'Sampled' operand must NOT be 1. It's Dim must not be Subpass");
			return error();
		}

		if (checkImageCoordinateType(imageType, coordType, CheckImgCoord::MustBeInt) == false)
		{
			return error();		
		}

		const Type& sampledType = imageType->front();

		if (texelType->isScalarOrVectorOf(sampledType.getType(), getImageDimension(imageType->getImageDimension()) ) == false)
		{
			module->logError("OpImageWrite texel type must be numerical scalar or vector of type %s", sampledType.getString());
			return error();
		}

		if (_imageOperands)
		{
			return makeOp(spv::Op::OpImageWrite, _pImage, _pCoordinate, _pTexel, literal_t{ _imageOperands }, _operands...);
		}
		else
		{
			return makeOp(spv::Op::OpImageWrite, _pImage, _pCoordinate, _pTexel);
		}
	}
} // !spvgentwo