# SpvGenTwo Documentation

SpvGenTwo is build around building-blocks that are somewhat similar to SPIR-V's structure. From afar the resemble a layer-model: `Operand >> Instruction >> BasicBlock >> Function >> Module`, meaning that each Instruction is a list of operands, each BasicBlock is a list of Instructions and so on.

## Operands
There are four kinds of [operands](lib/include/spvgentwo/Operand.h):

* **ResultId** - [id](https://www.khronos.org/registry/spir-v/specs/unified1/SPIRV.html#Terms) which was the result of an instruction
* **Literal** - 32bit integral immediate value
* **Instruction** - is resolved to an _id_ using `instruction->getResultId()`, this allows the the Instruction to be changed until it is finally resolved by serialization (when the module is written)
* **BranchTarget** - BasicBlock resolved by its first instruction `branchTarget->front().getResultId()` - this is just a helpful indirection

```cpp
union {
    BasicBlock* branchTarget; // corresponds to the block's OpLabel instruction
    Instruction* instruction; // intermediate or type
    literal_t value; // 32bit unsigned int
    spv::Id resultId; // 32bit unsigned int
};
```