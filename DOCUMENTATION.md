# Documentation

SpvGenTwo is build around building-blocks that are somewhat similar to SPIR-V's structure. From afar the resemble a layer-model: `Operand >> Instruction >> BasicBlock >> Function >> Module`, meaning that each Instruction is a list of operands, each BasicBlock is a list of Instructions and so on.

**Overview:**
* [Operands](#Operands)
* [Instructions](#Instructions)
* [BasicBlocks](#BasicBlocks)
* [Functions](#Functions)
    * [EntryPoints](#EntryPoints)
* [Modules](#Modules)
* [Types](#Types)
* [Constants](#Constants)

## Operands
There are four kinds of [operands](lib/include/spvgentwo/Operand.h) in SpvGenTwo:

* **ResultId** - [id](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#Terms) which was the result of an instruction
* **Literal** - 32bit integral immediate value
* **Instruction** - is resolved to an _id_ using `instruction->getResultId()`, this allows the the Instruction to be changed until it is finally resolved by serialization (when the module is written)
* **BranchTarget** - BasicBlock resolved by its first instruction `branchTarget->front().getResultId()` - this is just a helpful indirection

Note: SPIR-V only differentiates between `<id>` and `literal` operands.

```cpp
struct literal_t{ unsigned int value = 0u;};
```

`literal_t` is a type indirection / tag to be able differentiate between `spv::Id` and `unsigned int` literal values.

```cpp
union {
    BasicBlock* branchTarget; // corresponds to the block's OpLabel instruction
    Instruction* instruction; // intermediate or type
    literal_t value; // 32bit unsigned int
    spv::Id resultId; // 32bit unsigned int
};
```
## Instructions

[Instructions](lib/include/spvgentwo/Instruction.h) are a list of _operands_ and the associated `spv::Op` operation. SPIR-V mandates a [physical layout](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#_a_id_physicallayout_a_physical_layout_of_a_spir_v_module_and_instruction) (order) for instructions:

| Instruction Word Number   | Contents  |
|---|---|
| 0  | Opcode: The 16 high-order bits are the WordCount of the instruction. The 16 low-order bits are the opcode enumerant. |
| 1  | Optional instruction type <id> (presence determined by opcode). |
| . | Optional instruction Result <id> (presence determined by opcode). |
| . | Operand 1 (if needed) |
| . | Operand 2 (if needed) |
| ... | ... |
| WordCount - 1 | Operand N (N is determined by WordCount minus the 1 to 3 words used for the opcode, instruction type <id>, and instruction Result <id>). |

In SpvGenTwo the Instruction class roughly looks like this:

```cpp
class Instruction : public List<Operand>
{
private:
    spv::Op m_Operation = spv::Op::OpNop;
public:
    spv::Id getResultId() const;
    const Type* getType() const; // ResultType

    // make operation from up to 3 intermediate results, resulting instruction has result and result type
    Instruction* makeOp(const spv::Op _instOp, Instruction* _pOp1, Instruction* _pOp2 = nullptr, Instruction* _pOp3 = nullptr, Instruction* _pResultType = nullptr);

    // direclty translate arguments to spirv operands
    template <class ...Args>
    Instruction* makeOpEx(const spv::Op _op, Args ... _args);

    // assign <id>s to unresolved operands and serialize to physical layout
    spv::Id write(IWriter* _pWriter, spv::Id& _resultId);

    /// OPERATIONS:
    Instruction* opDot(Instruction* _pLeft, Instruction* _pRight);
    ...
}
```

Instruction derives from `List<Operand>` just as BasicBlock derives from `List<Instruction>` and Function derives from `List<BasicBlock>`. I chose a double-linked [list](lib/include/spvgentwo/List.h) as my primary container in SpvGenTwo as it allows us to rearrange its elements without invalidating the pointers to the data they carry.

By default, the operation of an Instruction is set to `spv::Op::Nop` (No Operation). Calling makeOp() or makeOpEx() sets the operation and adds the operands in the order they were passed.

Internally all Instructions are initialized using makeOpEx():
```cpp
template <class ...Args>
Instruction* makeOpEx(const spv::Op _op, Args ... _args);
```

`makeOpEx()` checks the C++ types of arguments passed to either add them as an Operand (`Instruction*, BasicBlock*, spv::Id, literal_t`) or decompose the argument into 32bit literals (if it is bigger than a `literal_t`).
`

```cpp
Instruction* makeOp(const spv::Op _instOp, Instruction* _pOp1, Instruction* _pOp2 = nullptr, Instruction* _pOp3 = nullptr, Instruction* _pResultType = nullptr);
```
`makeOp()` tries to infer the result type of the operation based on the passed operands either by calling the free function `inferType()` or the IInferResultType interface (assigned to the module).

~~`makeOp()` checks if the [types](#Types) of the operands (passed as Instruction*) match the requirements of the `spv::Op` using the type inference interface IInferType.~~ See [Issue 2](https://github.com/rAzoR8/SpvGenTwo/issues/2)

Any implementation of an `spv::Op` that has a resultId should also return a pointer to it self. Just as `Instruction* opDot()` returns the `this`-pointer. Operations that have no result (such as opNop, opBranch etc) should not return anything (`void`).

## BasicBlocks

[BasicBlocks](lib/include/spvgentwo/BasicBlock.h) always start with an `opLabel` instruction and my only contain one branch instruction (terminator) which must be the last instruction within the block (see [CFG](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#_universal_validation_rules)).

```cpp
class BasicBlock : public List<Instruction>
{
public:
    Instruction* operator->() { return &emplace_back(this); } // add new instruction

    // serialize instructions of this block
    void write(IWriter* _pWriter, spv::Id& _resultId);

    // Control flow helpers
    BasicBlock& If(Instruction* _pCondition, BasicBlock& _trueBlock, BasicBlock* _pMergeBlock, Flag<spv::SelectionControlMask> _mask);
    ... // arithmetic helpers
    BasicBlock& Add(Instruction* _pLeft, Instruction* _pRight);
    BasicBlock& Add(Instruction* _pRight) { return Add(&back(), _pRight); }
    BasicBlock& Sub(Instruction* _pLeft, Instruction* _pRight);
    BasicBlock& Mul(Instruction* _pLeft, Instruction* _pRight);
    BasicBlock& Div(Instruction* _pLeft, Instruction* _pRight);
};
```

The BasicBlock class can be used as a stack of operations where the left-hand operand of a new operation is the last Instruction stored in the BasicBlock and the right-hand operand is the result of another operation (possibly from a different BasicBlock). The result of this new Operation is pushed onto the stack (there is no pop). This concept is used in the global [operators](lib/source/Operators.cpp) implementation.

Programming control-flow in SPIR-V can be tedious. The BasicBlock class implements some helpers making easier to write _structured_ **if** statements and **loops**. Please see the Control-Flow [example](example/source/ControlFlow.cpp) for more detail.

## Functions

[Functions](lib/include/spvgentwo/Function.h) are collections of BasicBlocks encapsulated by `opFunction` and `opFunctionEnd` instructions. Use the module to add a new function using `addFunction<Args...>(...)`

```cpp
class Function : public List<BasicBlock>
{
private:
    Instruction m_Function; // OpFunction
	Instruction m_FunctionEnd; // OpFunctionEnd
    List<Instruction> m_Parameters; // OpFunctionParameters
public:
    void write(IWriter* _pWriter, spv::Id& _resultId); // serialize opFunction, BasicBLocks, opFunctionEnd

    // creates m_pFunctionType with OpTypeFunction and _pReturnType (opperands are added by addParameters), returns m_pFunctionType
    Instruction* setReturnType(Instruction* _pReturnType);

    // adds opFunctionParameter(_pParamType) to m_parameters and _pParamType to m_pFunctionType, returns last opFunctionParameter generated
    template <class ... TypeInstr>
    Instruction* addParameters(Instruction* _pParamType, TypeInstr* ... _paramTypeInstructions);

    // creates opFunction, m_pFunctionType must have been completed (all parameters added via addParameters), returns opFunction
    Instruction* finalize(const Flag<spv::FunctionControlMask> _control, const char* _pName = nullptr);
};
```

There are two ways to specify a function declaration:
1. [Template constructor](example/source/FunctionCall.cpp) -
Calling `finalize` is not necessary:
```cpp
template <class ... TypeInstr>
Function(Module* _pModule, const char* _pName, const Flag<spv::FunctionControlMask> _control, Instruction* _pReturnType, TypeInstr* ... _paramTypeInstructions);

// float add(float x, float y)
Function& funcAdd = module.addFunction<float, float, float>("add", spv::FunctionControlMask::Const);
```

2. Functional interface:
    * call `setReturnType(Instruction*)` with some Instruction* type generated by `module.type<T>()`
    * (optional) call `addParameters<Args...>()` with argument type Instruction*
    * call `finalize` with the ControlMask (for constness etc.)

### EntryPoints

[EntryPoints](lib/include/spvgentwo/EntryPoint.h) derive from Functions and add an `opEntryPoint` instruction required by the Shader [capability](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#Capability) set. 
```cpp
class EntryPoint : public Function
{
private:
    Instruction m_EntryPoint; // OpEntryPoint
    List<Instruction> m_ExecutionModes; // OpExecutionMode
public:
    template <class ... Args>
    Instruction* addExecutionMode(const spv::ExecutionMode _mode, Args ... _args);

    // overrides Functions finalize (used internally), _pEntryPointName is mandatory parameter, returns opFunction
    Instruction* finalize(const spv::ExecutionModel _model, const Flag<spv::FunctionControlMask> _control, const char* _pEntryPointName);
};
```

An [entry point](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#OpEntryPoint) must list all global variables it consumes. This is done by the module before serialization in `Module::write()`. `getGlobalVariableInterface()` traverses the CFG and for any usage of variables originating from outside the function.

## Modules

[Modules](lib/include/spvgentwo/Modules.h) contain all Functions (and EntryPoints), the complete set [preamble](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#_a_id_logicallayout_a_logical_layout_of_a_module) instructions and type/constant lookup hash-maps.

The Module class does not actually derive from a List of Functions because it hosts EntryPoints as well.

```cpp
class Module
{
private:
    List<Function> m_Functions;
    List<EntryPoint> m_EntryPoints;
    List<Instruction> m_Capabilities; // Preamble start
    ...
    List<Instruction> m_TypesAndConstants;
    HashMap<Type, Instruction*> m_TypeToInstr; // type hierarchy 
    HashMap<Instruction*, Type*> m_InstrToType; // reverse type lookup
    HashMap<Constant, Instruction*> m_ConstantBuilder;
	List<Instruction> m_GlobalVariables; //opVariable with StorageClass != Function
public:
	// automatically assigns IDs and serializes module to IWriter
	void write(IWriter* _pWriter);
   
    Type newType(); // creates new empty type using this modules allocator
    Constant newConstant();  // creates new empty constant using this modules allocator

    Instruction* addType(const Type& _type); // construct a type from Type info
    template <class T, class ... Props>
	Instruction* type(const Props& ... _props); // construct a type from C++ type T

    Instruction* addConstant(const Constant& _const); // construct a constant from Constant Info
	template <class T>
	Instruction* constant(const T& _value, const bool _spec = false); // construct a constant from C++ value T
  
    Function& addFunction(); // add empty function   
    EntryPoint& addEntryPoint(); // add empty entry point
};
```

Use `addFunction` or `addEntryPoint` to retrieve a reference to a newly added Function.

```cpp
// float add(float x, float y)
Function& funcAdd = module.addFunction<float, float, float>("add", spv::FunctionControlMask::Const);
```

## Types

SpvGenTwo offers a simple [type](lib/include/spvgentwo/Type.h) composition system. The `Type` class is a super set of all OpTypeXXX instructions and its parameters.
To construct a new empty type, use `Type Module::newType()`. Once done with creating the type, use `Instruction* Module::addType(const Type& _type)` to create an Instruction* holding the `OpTypeXXX`. Types in SpvGenTwo are unique meaning that calling `module.addType(myType)` with the same Type results in the same Instruction*.
Type Instruction* can also be directly obtained form a C++ type using `module.type<T>()`. This however only works for simple / fundamental types. Custom structs and functions are not supported.

Here's a short example how to create a struct type:

```cpp
Type myStruct = module.newType();

//struct myStruct
//{
// float x;
// int y;
// vec3 v;
//};

myStruct.Struct();
myStruct.FloatM(); // add 32 bit float as member
myStruct.IntM(); // add signed int as member
myStruct.Member().VectorElement(3).Float(); // add empty member to struct, make it a vector of 3 elements of type float

// add via addType, make a pointer for storage class 'function
Instruction* type = module.addType(myStruct.wrapPointer(spv::StorageClass::Function));
```

The resulting SPIR-V looks something like this:

```
               OpCapability Shader
               OpMemoryModel Logical Simple
               OpEntryPoint Vertex %main "main"
               OpName %main "main"
               OpName %FunctionEntry "FunctionEntry"
       %void = OpTypeVoid
          %2 = OpTypeFunction %void
      %float = OpTypeFloat 32
        %int = OpTypeInt 32 1
    %v3float = OpTypeVector %float 3
  %_struct_8 = OpTypeStruct %float %int %v3float
%_ptr_Function__struct_8 = OpTypePointer Function %_struct_8
       %main = OpFunction %void None %2
%FunctionEntry = OpLabel
               OpReturn
               OpFunctionEnd
```

For more examples, checkout the Types [example](example/source/Types.cpp).

## Constants