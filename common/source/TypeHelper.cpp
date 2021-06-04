#include "common/TypeHelper.h"

#include "spvgentwo/Type.h"
#include "spvgentwo/String.h"
#include "spvgentwo/Instruction.h"

namespace
{
	void getTypeName(spvgentwo::sgt_size_t _offset, unsigned int _indent, const spvgentwo::Type& _type, spvgentwo::String& _outName, const spvgentwo::Instruction* _pOpTypeInstr, unsigned int _memberIndex = spvgentwo::sgt_uint32_max)
	{
		using namespace spvgentwo;

		Instruction::Iterator op = nullptr;

		if (_pOpTypeInstr != nullptr) // get subtype if possible
		{
			if (_pOpTypeInstr->isType())
			{
				op = _pOpTypeInstr->getFirstActualOperand();
			}
			else if (_pOpTypeInstr->hasResultType())
			{
				op = _pOpTypeInstr->getResultTypeInstr()->getFirstActualOperand();
			}
		}

		auto instrName = [](const spvgentwo::Instruction* _instr, unsigned int _memberIdx = sgt_uint32_max) -> const char*
		{
			const char* name = nullptr;

			if (_instr != nullptr)
			{
				if (name = _instr->getName(_memberIdx); name == nullptr && _instr->hasResultType())
				{
					if (const Instruction* t = _instr->getResultTypeInstr(); t != nullptr)
					{
						name = t->getName(_memberIdx);
					}
				}
			}

			return name;
		};

		// string
		auto insert = [&](const char* str)
		{
			auto prev = _outName.size();
			_outName.insert(_offset, str);
			auto len = _outName.size() - prev;
			_offset += len;
		};

		// type
		auto insertSubType = [&_outName, &_offset](const Type& _t, unsigned int _indent, const spvgentwo::Instruction* _pInstr, unsigned int _memberIdx = sgt_uint32_max)
		{
			auto prev = _outName.size();
			getTypeName(_offset, _indent, _t, _outName, _pInstr, _memberIdx);
			auto len = _outName.size() - prev;
			_offset += len;
		};

		auto indent = [&insert](unsigned int indent)
		{
			for(auto i = 0u; i < indent; ++i)
			{
				insert("\t");
			}
		};

		if (_type.isStruct())
		{
			insert("struct ");

			if (const char* name = instrName(_pOpTypeInstr); name != nullptr)
			{
				insert(name);
			}

			insert(" {\n");

			for (const Type& t : _type) 
			{
				indent(_indent+1u);
				insertSubType(t, _indent + 1u, op != nullptr ? op->getInstruction() : nullptr, _memberIndex++);
				if (t.isStruct() == false)
				{
					insert(";\n");
				}

				++op;
			}
			
			indent(_indent);
			insert("};\n");
		}
		else if (_type.isFunction())
		{
			auto it = _type.begin();

			// return type
			insertSubType(*it, 0u, op != nullptr ? op->getInstruction() : nullptr);

			if (const char* name = instrName(_pOpTypeInstr); name != nullptr)
			{
				insert(" "); // func name
				insert(name);
			}

			// parameters
			insert("(");

			while (++it != _type.end())
			{
				++op;

				// param name
				if (const char* name = instrName(op != nullptr ? op->getInstruction() : nullptr); name != nullptr)
				{
					insert(name);
				}
				else // parameter type
				{
					insertSubType(*it, 0u, op != nullptr ? op->getInstruction() : nullptr);
				}

				if (it.next() != nullptr)
				{
					insert(", ");
				}
			}

			insert(")");
		}
		else if (_type.isPointer())
		{
			insertSubType(_type.front(), 0u, op != nullptr ? op->getInstruction() : nullptr);
			insert("*");

			if (const char* name = instrName(_pOpTypeInstr); name != nullptr)
			{
				insert(" ");
				insert(name);
			}
		}
		else if (_type.isArray())
		{
			insertSubType(_type.front(), 0u, _pOpTypeInstr); // or pass subtype instr?

			if (const char* name = instrName(_pOpTypeInstr); name != nullptr)
			{
				insert(name);
			}

			insert("[");

			char num[11]{ '\0' };
			uintToString(_type.getArrayLength(), num, 10u, 10u);			
			insert(num);

			insert("]");
		}
		else if (const char* name = instrName(_pOpTypeInstr, _memberIndex); name != nullptr)
		{
			insert(name);
		}
		else if(const char* fundamentalName = _type.getString(); fundamentalName != nullptr)
		{
			insert(fundamentalName);
		}
	}
} // anon

void spvgentwo::TypeHelper::getTypeName(const Type& _type, String& _outName, const Instruction* _pOpTypeInstr)
{
	::getTypeName(0u, 0u, _type, _outName, _pOpTypeInstr);
}