#pragma once

#include "List.h"
#include "SpvDefines.h"

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Type
	{
	public:
		Type(IAllocator* _pAllocator);
		~Type();

		void setBaseType(const spv::Op _type);

		// makes this a void type
		Type& Void();
		
		Type& Int(const uint32_t _bits = 32u, const bool _sign = true);
		Type& UInt(const uint32_t _bits = 32u) { return Int(_bits, false); }

		Type& Float(const uint32_t _bits = 32u);

	private:
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type
		uint32_t m_Dimension = 0u;
		bool m_Sign = false;

		// image
		bool m_Array = false;
		bool m_MultiSampled = false;
		// depth tex type
		// sampler access

		List<Type> m_subTypes;
	};
} // !spvgentwo