# SpvGenTwo Documentation

SpvGenTwo is build around building-blocks that are somewhat similar to SPIR-V's structure. From afar the resemble a layer-model: `Operand >> Instruction >> BasicBlock >> Function >> Module`, meaning that each Instruction is a list of operands, each BasicBlock is a list of Instructions and so on.

## Operands
There are four kinds of [operands](lib/include/spvgentwo/Operand.h) in SpvGenTwo:

* **ResultId** - [id](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#Terms) which was the result of an instruction
* **Literal** - 32bit integral immediate value
* **Instruction** - is resolved to an _id_ using `instruction->getResultId()`, this allows the the Instruction to be changed until it is finally resolved by serialization (when the module is written)
* **BranchTarget** - BasicBlock resolved by its first instruction `branchTarget->front().getResultId()` - this is just a helpful indirection

Note: SPIR-V only differentiates between `<id>` and `literal` operands.

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

`makeOpEx()` checks the types of arguments passed to either add them as an Operand (`Instruction*, BasicBlock*, spv::Id, literal_t`) or decompose the argument into 32bit literals (if it is bigger than a `literal_t`).

