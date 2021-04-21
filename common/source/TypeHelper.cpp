#include "common/TypeHelper.h"

#include "spvgentwo/Type.h"
#include "spvgentwo/String.h"
#include "spvgentwo/Instruction.h"

namespace
{
	bool getTypeName(spvgentwo::sgt_size_t _offset, const spvgentwo::Type& _type, spvgentwo::String& _outName, const spvgentwo::Instruction* _pOpTypeInstr)
	{
		return false;
	}
} // anon

bool spvgentwo::TypeHelper::getTypeName(const Type& _type, String& _outName, const Instruction* _pOpTypeInstr)
{
	return ::getTypeName(0u, _type, _outName, _pOpTypeInstr);
}