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
			_offset += sLen;

			for (const Type& t : _type) 
			{
				auto prev = _outName.size();
				getTypeName(_offset, t, _outName, _pOpTypeInstr); // todo, advance _pOpTypeInstr
				auto len = _outName.size() - prev;
				_offset += len;

				_outName.insert(_offset, ";\n");
				_offset += sizeof(";\n");
			}
			
			_outName.insert(_offset, "};");
			return true;
		}
		else if(const char* name = _type.getString(); name != nullptr)
		{
			_outName.insert(_offset, name);
		}
		// TODO: other types

		return false;
	}
} // anon

bool spvgentwo::TypeHelper::getTypeName(const Type& _type, String& _outName, const Instruction* _pOpTypeInstr)
{
	return ::getTypeName(0u, _type, _outName, _pOpTypeInstr);
}