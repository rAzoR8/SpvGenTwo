#include "common/TypeHelper.h"

#include "spvgentwo/Type.h"
#include "spvgentwo/String.h"
#include "spvgentwo/Instruction.h"

namespace
{
	bool getTypeName(spvgentwo::sgt_size_t _offset, const spvgentwo::Type& _type, spvgentwo::String& _outName, const spvgentwo::Instruction* _pOpTypeInstr)
	{
		using namespace spvgentwo;

		if (_type.isStruct())
		{
			auto sLen = sizeof("struct {\n");
			_outName.insert(_offset, "struct {\n", sLen); // TODO: implant _pOpTypeInstr
			_offset += sLen-1;

			for (const Type& t : _type) 
			{
				_outName.insert(_offset++, "\t", 1u);

				auto prev = _outName.size();
				getTypeName(_offset, t, _outName, _pOpTypeInstr); // todo, advance _pOpTypeInstr
				auto len = _outName.size() - prev - 1;
				_offset += len;

				_outName.insert(_offset, ";\n");
				_offset += sizeof(";\n")-1;
			}
			
			_outName.insert(_offset, "};");
			return true;
		}
		else if(const char* name = _type.getString(); name != nullptr)
		{
			_outName.insert(_offset, name);
			return true;
		}
		// TODO: other types

		return false;
	}
} // anon

bool spvgentwo::TypeHelper::getTypeName(const Type& _type, String& _outName, const Instruction* _pOpTypeInstr)
{
	return ::getTypeName(0u, _type, _outName, _pOpTypeInstr);
}