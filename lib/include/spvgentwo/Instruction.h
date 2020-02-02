#pragma once

#include "List.h"
#include "Operand.h"
#include "Flag.h"

namespace spvgentwo
{
	// forward delcs
	class Type;
	class Function;
	class Module;

	class Instruction : public List<Operand>
	{
		friend class Module;
		friend class BasicBlock;

	public:
		enum class ParentType
		{
			BasicBlock,
			Function,
			Module
		};

	private:
		spv::Op m_Operation = spv::Op::OpNop;

		ParentType m_parentType = ParentType::BasicBlock;

		union
		{
			BasicBlock* pBasicBlock; // parent
			Function* pFunction;
			Module* pModule;
		} m_parent = {};

	public:
		using Iterator = EntryIterator<Operand>;

		template <class ...Args>
		Instruction(Module* _pModule, const spv::Op _op = spv::Op::OpNop, Args&& ... _args);
		template <class ...Args>
		Instruction(Function* _pFunction, const spv::Op _op = spv::Op::OpNop, Args&& ... _args);
		template <class ...Args>
		Instruction(BasicBlock* _pBasicBlock, const spv::Op _op = spv::Op::OpNop, Args&& ... _args);

		Instruction(Module* _pModule, Instruction&& _other) noexcept;
		Instruction(Function* _pFunction, Instruction&& _other) noexcept;
		Instruction(BasicBlock* _pBasicBlock, Instruction&& _other) noexcept;

		Instruction(const Instruction&) = delete;

		virtual ~Instruction();

		Instruction& operator=(Instruction&& _other) noexcept;
		Instruction& operator=(const Instruction& _other) = delete;

		Module* getModule() const;
		Function* getFunction() const;
		BasicBlock* getBasicBlock() const;

		// get name that was assigned via opName
		const char* getName() const;

		// not so sure this is a good idea
		operator BasicBlock& () { return *getBasicBlock(); }
		operator const BasicBlock& () const { return *getBasicBlock(); }

		// manual instruction construction:
		void setOperation(const spv::Op _op) { m_Operation = _op; };
		spv::Op getOperation() const { return m_Operation; }
		template<class ...Args>
		Operand& addOperand(Args&& ... _operand) { return emplace_back(stdrep::forward<Args>(_operand)...); }

		// operand helper
		spv::Id getResultId() const;
		Instruction* getTypeInst() const;
		const Type* getType() const;

		// operand iterator helpers return null iterator of not compatible with operation 
		Iterator getResultTypeOperand() const; // <id> ResultType operand
		Iterator getResultIdOperand() const; // Result <id> operand
		Iterator getFirstActualOperand() const; // operand after Result <id>

		// get StorageClass of OpVariable instructions
		spv::StorageClass getStorageClass() const;
	
		bool isType() const;
		bool isTerminator() const;
		bool isConstant() const;
		bool isSpecConstant() const;
		bool isSpecOrConstant() const;

		bool hasResult() const { return hasResultId(m_Operation); }
		bool hasResultType() const { return hasResultTypeId(m_Operation); }
		bool hasResultAndType() const { return hasResultAndTypeId(m_Operation); }

		// returns a list of BasicBlock branch targets if this instuction is a Terminator
		bool getBranchTargets(List<BasicBlock*>& _outTargetBlocks) const;

		// reset Operation and clear Operands
		void reset();

		// get number of 32 bit words used by this instruction
		unsigned int getWordCount() const;

		// get opcode encoded with instruction word count [16 bit op code, 16 bit number of operand words] 
		unsigned int getOpCode() const;

		// returns the ID assigned to this instrucions
		spv::Id resolveId(spv::Id& _previousId);

		// serialize instructions of this basic block to the IWriter, returns ID that was assigned to this instruction
		spv::Id write(IWriter* _pWriter, spv::Id& _resultId);

		// transforms _args to operands, calls inferResultTypeOperand and validateOperands()
		template <class ...Args>
		Instruction* makeOp(const spv::Op _op, Args ... _args);

		// convert and add the raw data passed via _args as literal_t operands
		template <class ...Args>
		void appendLiterals(Args ... _args);

		// infer result type from operands, RestulType operand must be set to InvalidInstr
		// this function assigns the infered OpType instruction to the first operand of this instruction
		// uses ITypeInferenceAndValiation instance if present
		Instruction* inferResultTypeOperand();

		// validate m_Operations and operands with ITypeInferenceAndValiation instance if present, return true if okay
		bool validateOperands();

		//
		// OPERATIONS
		//

		void opNop();

		Instruction* opUndef(Instruction* _pResultType);

		Instruction* opSizeOf(Instruction* _pPointerToVar);

		// instruction generators:
		// all instructions generating a result id return a pointer to this instruction for reference (passing to other instruction operand)
		void opCapability(const spv::Capability _capability);

		void opMemoryModel(const spv::AddressingModel _addressModel, const spv::MemoryModel _memoryModel);

		void opExtension(const char* _pExtName);

		// generates extension id
		Instruction* opExtInstImport(const char* _pExtName);

		template <class ...Operands>
		Instruction* opExtInst(Instruction* _pResultType, Instruction* _pExtensionId, unsigned int _instOpCode, Operands ... _operands);

		template <class ...Operands>
		Instruction* opExtInst(Instruction* _pResultType, const char* _pExtName, unsigned int _instOpCode, Operands ... _operands);

		Instruction* opLabel();

		Instruction* opFunction(const Flag<spv::FunctionControlMask> _functionControl, Instruction* _pResultType, Instruction* _pFuncType);

		Instruction* opFunctionParameter(Instruction* _pType);

		void opReturn();

		void opReturnValue(Instruction* _pValue);

		void opFunctionEnd();

		template <class ... ArgInstr>
		Instruction* opFunctionCall(Instruction* _pResultType, Instruction* _pFunction, ArgInstr ... _args);

		template <class ... ArgInstr>
		Instruction* call(Function* _pFunction, ArgInstr ... _args);

		//  _pFunction is result of opFunction
		template <class ... Instr>
		void opEntryPoint(const spv::ExecutionModel _model, Instruction* _pFunction, const char* _pName, Instr ... _instr);

		// _pResultType must be of OpTypePointer
		Instruction* opVariable(Instruction* _pResultType, const spv::StorageClass _storageClass, Instruction* _pInitializer = nullptr);

		void opName(Instruction* _pTarget, const char* _pName);

		void opMemberName(Instruction* _pTargetStructType, unsigned int _memberIndex, const char* _pName);

		template <class ... Decorations>
		void opDecorate(Instruction* _pTarget, spv::Decoration _decoration, Decorations ... _decorations);

		template <class ... Decorations>
		void opMemberDecorate(Instruction* _pTargetStructType, unsigned int _memberIndex, spv::Decoration _decoration, Decorations ... _decorations);

		template <class ... Instr>
		void opMemberId(Instruction* _pTarget, spv::Decoration _decoration, Instruction* _pId, Instr*..._ids);

		// deduce parent form input variables
		template <class ... VarInst>
		Instruction* opPhi(Instruction* _pVar, VarInst* ... _variables);

		Instruction* opSelect(Instruction* _pCondBool, Instruction* _pTrueObj, Instruction* _pFalseObj);

		template <class ...LoopControlParams>
		void opLoopMerge(BasicBlock* _pMergeBlock, BasicBlock* _pContinueBlock, const Flag<spv::LoopControlMask> _loopControl, LoopControlParams ... _params);

		void opSelectionMerge(BasicBlock* _pMergeBlock, const spv::SelectionControlMask _control);

		// label is infered from the basic block on serialization
		void opBranch(BasicBlock* _pTargetBlock);

		// label is infered from the basic block on serialization
		void opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock);
		void opBranchConditional(Instruction* _pCondition, BasicBlock* _pTrueBlock, BasicBlock* _pFalseBlock, const unsigned int _trueWeight, const unsigned int _falseWeight);

		template <class ... Instr>
		Instruction* opAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstIndex, Instr* ... _pIndices);

		template <class ... IntIndices>
		Instruction* opAccessChain(Instruction* _pBase, const unsigned int _firstIndex, IntIndices... _indices);

		template <class ... Instr>
		Instruction* opInBoundsAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstIndex, Instr* ... _pIndices);

		template <class ... Operands>
		Instruction* opLoad(Instruction* _pPointerToVar, const Flag<MemoryOperands> _memOperands = MemoryOperands::None, Operands ... _operands);

		template <class ... Operands>
		void opStore(Instruction* _pPointerToVar, Instruction* _valueToStore, const Flag<MemoryOperands> _memOperands = MemoryOperands::None, Operands ... _operands);

		Instruction* opOuterProduct(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opDot(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opAny(Instruction* _pBoolVec);

		Instruction* opAll(Instruction* _pBoolVec);

		Instruction* opVectorExtractDynamic(Instruction* _pVector, Instruction* _pIndexInt);

		Instruction* opVectorInsertDynamic(Instruction* _pVector, Instruction* _pComponent, Instruction* _pIndexInt);

		template <class ... ConstituentInstr>
		Instruction* opCompositeConstruct(Instruction* _pResultType, Instruction* _pFirstConstituents, ConstituentInstr* ... _constituents);

		template <class ... IntIndices>
		Instruction* opCompositeExtract(Instruction* _pComposite, const unsigned int _firstIndex, IntIndices ... _indices);

		template <class ... IntIndices>
		Instruction* opCompositeInsert(Instruction* _pComposite,  Instruction* _pValue, const unsigned int _firstIndex, IntIndices ... _indices);

		Instruction* opCopyObject(Instruction* _pObject);

		Instruction* opTranspose(Instruction* _pMatrix);

		Instruction* opSNegate(Instruction* _pSignedInt);

		Instruction* opFNegate(Instruction* _pFloat);

		Instruction* opIAdd(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opFAdd(Instruction* _pLeft, Instruction* _pRight);

		Instruction* opSampledImage(Instruction* _pImage, Instruction* _pSampler);

		// generic base case with image operands
		template <class ...ImageOperands>
		Instruction* opImageSample(const spv::Op _imageSampleOp, Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDrefOrCompnent = nullptr, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands);

#pragma region SampleMethods
		// Implicit
		template <class ...ImageOperands>
		Instruction* opImageSampleImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleImplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		// Explicit
		template <class ...ImageOperands>
		Instruction* opImageSampleExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleExplicitLod, _pSampledImage, _pCoordinate, nullptr, _additionalOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleExplicitLod, _pSampledImage, _pCoordinate, nullptr, _additionalOperands | spv::ImageOperandsMask::Grad, _pLodLevel, _operands...);
		}

		// Proj
		template <class ...ImageOperands>
		Instruction* opImageSampleProjImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjImplicitLod, _pSampledImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjExplicitLod, _pSampledImage, _pCoordinate, nullptr, _additionalOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjExplicitLod, _pSampledImage, _pCoordinate, nullptr, _additionalOperands | spv::ImageOperandsMask::Grad, _pLodLevel, _operands...);
		}

		//
		// Dref
		//

		// Implicit
		template <class ...ImageOperands>
		Instruction* opImageSampleDrefImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleDrefImplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

		// Explicit
		template <class ...ImageOperands>
		Instruction* opImageSampleDrefExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _additionalOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleDrefExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _additionalOperands | spv::ImageOperandsMask::Grad, _pLodLevel, _operands...);
		}

		// Proj
		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefImplictLod(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjDrefImplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefExplicitLodLevel(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pLodLevel, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _additionalOperands | spv::ImageOperandsMask::Lod, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageSampleProjDrefExplicitLodGrad(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, Instruction* _pGrad, const Flag<spv::ImageOperandsMask> _additionalOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageSampleProjDrefExplicitLod, _pSampledImage, _pCoordinate, _pDepthReference, _additionalOperands | spv::ImageOperandsMask::Grad, _pLodLevel, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageFetch(Instruction* _pImage, Instruction* _pCoordinate, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageFetch, _pImage, _pCoordinate, nullptr, _imageOperands, _operands...);
		}

		// Gather
		template <class ...ImageOperands>
		Instruction* opImageGather(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pComponent, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageGather, _pSampledImage, _pCoordinate, _pComponent, _imageOperands, _operands...);
		}

		template <class ...ImageOperands>
		Instruction* opImageDrefGather(Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDepthReference, const Flag<spv::ImageOperandsMask> _imageOperands = spv::ImageOperandsMask::MaskNone, ImageOperands... _operands)
		{
			return opImageSample(spv::Op::OpImageDrefGather, _pSampledImage, _pCoordinate, _pDepthReference, _imageOperands, _operands...);
		}

#pragma endregion

	private:

		// creates literals
		template <class T, class ...Args>
		void makeOpInternal(T first, Args ... _args);

	};

	template<class ...Args>
	inline Instruction::Instruction(Module* _pModule, const spv::Op _op, Args&& ..._args) :List(_pModule->getAllocator()),
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
	inline Instruction* Instruction::makeOp(const spv::Op _op, Args ..._args)
	{
		reset();

		m_Operation = _op;

		if constexpr (sizeof...(_args) > 0u)
		{
			makeOpInternal(_args...);
		}

		inferResultTypeOperand();
		validateOperands();

		return this;
	}
	
	template<class T, class ...Args>
	inline void Instruction::makeOpInternal(T _first, Args ..._args)
	{
		if constexpr (traits::is_same_base_type_v<T, Instruction*> || traits::is_same_base_type_v<T, BasicBlock*> || traits::is_same_base_type_v<T, spv::Id> || traits::is_same_base_type_v<T, literal_t>)
		{
			addOperand(_first);
		}
		else if constexpr (stdrep::is_same_v<traits::remove_cvref_t<T>, int> || stdrep::is_same_v<traits::remove_cvref_t<T>, unsigned int>) // bitcast to 32 bit literal
		{
			addOperand(literal_t{_first});
		}
		else
		{
			appendLiterals(_first);
		}

		if constexpr (sizeof...(_args) > 0u)
		{
			makeOpInternal(_args...);
		}
	}

	template<class ...Args>
	inline void Instruction::appendLiterals(Args ..._args)
	{
		appendLiteralsToContainer(*this, _args...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opExtInst(Instruction* _pResultType, Instruction* _pExtensionId, unsigned int _instOpCode, Operands ..._operands)
	{
		return makeOp(spv::Op::OpExtInst, _pResultType, InvalidId, _pExtensionId, literal_t{ _instOpCode }, _operands...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opExtInst(Instruction* _pResultType, const char* _pExtName, unsigned int _instOpCode, Operands ..._operands)
	{
		Instruction* _pExtImport = getModule()->getExtensionInstructionImport(_pExtName);
		return makeOp(spv::Op::OpExtInst, _pResultType, InvalidId, _pExtImport, literal_t{ _instOpCode }, _operands...);
	}

	template<class ...ArgInstr>
	inline Instruction* Instruction::opFunctionCall(Instruction* _pResultType, Instruction* _pFunction, ArgInstr ..._args)
	{
		return makeOp(spv::Op::OpFunctionCall, _pResultType, InvalidId, _pFunction, _args...);
	}

	template<class ...ArgInstr>
	inline Instruction* Instruction::call(Function* _pFunction, ArgInstr ..._args)
	{
		return opFunctionCall(_pFunction->getReturnType(), _pFunction->getFunction(), _args...);
	}

	template<class ...Instr>
	inline void Instruction::opEntryPoint(const spv::ExecutionModel _model, Instruction* _pFunction, const char* _pName, Instr ..._instr)
	{
		makeOp(spv::Op::OpEntryPoint, _model, _pFunction, _pName, _instr...);
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
	inline void Instruction::opMemberId(Instruction* _pTarget, spv::Decoration _decoration, Instruction* _pId, Instr* ..._ids)
	{
		makeOp(spv::Op::OpDecorateId, _pTarget, _decoration, _ids...);
	}

	template<class ...VarInst>
	inline Instruction* Instruction::opPhi(Instruction* _pVar, VarInst* ..._variables)
	{
		makeOp(spv::Op::OpPhi, _pVar->getTypeInst(), InvalidId);

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

	template<class ...Instr>
	inline Instruction* Instruction::opAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstIndex, Instr* ..._pIndices)
	{
		return makeOp(spv::Op::OpAccessChain, _pResultType, InvalidId, _pBase, _pConstIndex, _pIndices...);
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opAccessChain(Instruction* _pBase, const unsigned int _firstIndex, IntIndices ..._indices)
	{
		// Base must be a pointer, pointing to the base of a composite object.

		const Type* pBaseType = _pBase->getType();
		auto it = pBaseType->getSubType(0u, _firstIndex, _indices...); // base is a pointer type, so 0 is used to get the inner type
		Module* pModule = _pBase->getModule();
		Instruction* pResultType = nullptr;

		if (it != nullptr)
		{
			// Result Type must be an OpTypePointer.
			// Its Type operand must be the type reached by walking the Base’s type hierarchy down to the last provided index in Indexes, and its Storage Class operand must be the same as the Storage Class of Base.
	
			Type&& ptrType(it->wrap(spv::Op::OpTypePointer));
			ptrType.setStorageClass(pBaseType->getStorageClass());
			pResultType = pModule->addType(ptrType);
		}

		return makeOp(spv::Op::OpAccessChain, pResultType, InvalidId, _pBase, pModule->constant(_firstIndex), pModule->constant<unsigned int>(_indices)...);
	}

	template<class ...Instr>
	inline Instruction* Instruction::opInBoundsAccessChain(Instruction* _pResultType, Instruction* _pBase, Instruction* _pConstIndex, Instr* ..._pIndices)
	{
		return makeOp(spv::Op::OpInBoundsAccessChain, _pResultType, InvalidId, _pBase, _pConstIndex, _pIndices...);
	}

	template<class ...Operands>
	inline Instruction* Instruction::opLoad(Instruction* _pPointerToVar, const Flag<MemoryOperands> _memOperands, Operands ..._operands)
	{
		// Result Type is the type of the loaded object.It must be a type with ﬁxed size; i.e., it cannot be, nor include, any OpTypeRuntimeArray types.
		// Pointer is the pointer to load through.Its type must be an OpTypePointer whose Type operand is the same as Result Type.
		Instruction* pResultType = getModule()->addType(_pPointerToVar->getType()->front());
		return makeOp(spv::Op::OpLoad, pResultType, InvalidId, _pPointerToVar, _memOperands.mask, _operands...);
	}

	template<class ...Operands>
	inline void Instruction::opStore(Instruction* _pPointerToVar, Instruction* _valueToStore, const Flag<MemoryOperands> _memOperands, Operands ..._operands)
	{
		makeOp(spv::Op::OpStore, _pPointerToVar, _valueToStore, _memOperands.mask, _operands...);
	}

	template<class ...ConstituentInstr>
	inline Instruction* Instruction::opCompositeConstruct(Instruction* _pResultType, Instruction* _pFirstConstituent, ConstituentInstr* ..._constituents)
	{
		if (_pResultType->getType()->isComposite() == false)
		{
			getModule()->logError("Result type of opCompositeConstruct is not a composite type");
			return this;
		}

		return makeOp(spv::Op::OpCompositeConstruct, _pResultType, InvalidId, _pFirstConstituent, _constituents...);
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opCompositeExtract(Instruction* _pComposite, const unsigned int _firstIndex, IntIndices ..._indices)
	{
		const Type* pBaseType = _pComposite->getType();
		Module* pModule = _pComposite->getModule();

		if (pBaseType->isComposite() == false)
		{
			pModule->logError("Argument of opCompositeExtract is not a composite type");
			return this;
		}

		auto it = pBaseType->getSubType(0u, _firstIndex, _indices...);

		if (it != nullptr)
		{
			Instruction* pResultType = pModule->addType(*it);
			return makeOp(spv::Op::OpCompositeExtract, pResultType, InvalidId, _pComposite, literal_t{ _firstIndex }, literal_t{ _indices }...);
		}

		pModule->logError("Invalid index sequence specified for composite type extraction");

		return this;
	}

	template<class ...IntIndices>
	inline Instruction* Instruction::opCompositeInsert(Instruction* _pComposite, Instruction* _pValue, const unsigned int _firstIndex, IntIndices ..._indices)
	{
		const Type* pBaseType = _pComposite->getType();
		Module* pModule = _pComposite->getModule();

		if (pBaseType->isComposite() == false)
		{
			pModule->logError("Argument of opCompositeInsert is not a composite type");
			return this;
		}

		auto it = pBaseType->getSubType(0u, _firstIndex, _indices...);

		if (it != nullptr)
		{
			const Type* pValueType = _pValue->getType();

			if (*it == *pValueType)
			{
				return makeOp(spv::Op::OpCompositeInsert, _pComposite->getTypeInst(), InvalidId, _pValue, _pComposite, literal_t{ _firstIndex }, literal_t{ _indices }...);
			}

			pModule->logError("Value type does not match composite insertion type");
			return this;
		}

		pModule->logError("Invalid index sequence specified for composite insertion");

		return this;
	}

	template<class ...ImageOperands>
	inline Instruction* Instruction::opImageSample(const spv::Op _imageSampleOp, Instruction* _pSampledImage, Instruction* _pCoordinate, Instruction* _pDrefOrCompnent, const Flag<spv::ImageOperandsMask> _imageOperands, ImageOperands ..._operands)
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
				return this;
			}
			checkCoords = true; coordCanBeInt = true;
			break;
		case spv::Op::OpImageDrefGather:
		case spv::Op::OpImageGather:
			isComponent = _imageSampleOp == spv::Op::OpImageGather;
			isDref = _imageSampleOp == spv::Op::OpImageDrefGather;
			checkCoords = true;  coordCanBeInt = true;
			if (imageType->getImageDimension() != spv::Dim::Dim2D && imageType->getImageDimension() != spv::Dim::Cube && imageType->getImageDimension() != spv::Dim::Rect)
			{
				module.logError("OpImageGather requres Dim of sampled image to be 2D, Cube or Rect");
				return this;
			}
			break;
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
			return this;
		}

		if (!checkDrefComponent() || !checkCoordinateType())
		{
			return this;
		}

		if (_pDrefOrCompnent == nullptr)
		{
			if (_imageOperands == spv::ImageOperandsMask::MaskNone)
			{
				makeOp(_imageSampleOp, InvalidInstr, InvalidId, _pSampledImage, _pCoordinate);			
			}
			else
			{
				makeOp(_imageSampleOp, InvalidInstr, InvalidId, _pSampledImage, _pCoordinate, literal_t{ _imageOperands.mask }, _operands...);
			}
		}
		else
		{
			if (_imageOperands == spv::ImageOperandsMask::MaskNone)
			{
				makeOp(_imageSampleOp, InvalidInstr, InvalidId, _pSampledImage, _pCoordinate, _pDrefOrCompnent);
			}
			else
			{
				makeOp(_imageSampleOp, InvalidInstr, InvalidId, _pSampledImage, _pCoordinate, _pDrefOrCompnent, literal_t{ _imageOperands.mask }, _operands...);
			}
		}

		return this;
	}
} // !spvgentwo