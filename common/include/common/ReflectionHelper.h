#pragma once

namespace spvgentwo
{
	// forward decls

	class Module;

	class ReflectionHelper
	{
	public:
		ReflectionHelper(const Module& _module);
		~ReflectionHelper();

		// parse OpExecutionMode/Id operands, returns false if LocalSize or LocalSizeHint is present
		bool getLocalSize(unsigned int& _x, unsigned int& _y, unsigned int& _z) const;

	private:
		const Module& m_module;
	};
} // !spvgentwo