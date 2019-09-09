#pragma once

#include "List.h"
#include <vulkan/spirv.hpp11>

namespace spvgentwo
{
	// forward decls
	class IAllocator;

	class Type
	{
	public:
		Type(IAllocator* _pAllocator);
		~Type();

		Type Void();

	private:
		spv::Op m_Type = spv::Op::OpTypeVoid; // base type
		spv::Id m_Dimension = 0;
		bool m_Sign = false;

		// image
		bool m_Array = false;
		bool m_MultiSampled = false;
		// depth tex type
		// sampler access

		List<Type> m_subTypes;
	};
} // !spvgentwo