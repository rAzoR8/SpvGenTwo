#include "test/SpvValidator.h"
#include "common/BinaryVectorWriter.h"
#include "common/ModulePrinter.h"

#include "spirv-tools/libspirv.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace spvgentwo;
using namespace ModulePrinter;

namespace
{
    static spvtools::SpirvTools& instance( )
    {
        static spvtools::SpirvTools tools( SPV_ENV_UNIVERSAL_1_6 );
        static bool toolsInitialized = false;

        if( tools.IsValid() && toolsInitialized == false )
        {
			tools.SetMessageConsumer(
				[](spv_message_level_t level, const char*, const spv_position_t& position, const char* message)
				{
					switch (level) {
					case SPV_MSG_FATAL:
						FAIL("line " << position.line << " id " << position.index << ": " << message);
						break;
					case SPV_MSG_INTERNAL_ERROR:
					case SPV_MSG_ERROR:
					case SPV_MSG_WARNING:
						WARN("line " << position.line << " id " << position.index << ": " << message);
						break;
					case SPV_MSG_INFO:
						UNSCOPED_INFO("line " << position.line << " id " << position.index << ": " << message);
						break;
					default:
						break;
					}
				}
			);
            toolsInitialized = true;
        }

        return tools;
    }
}


test::SpvValidator::SpvValidator(const Grammar& _gram) : m_gram(_gram)
{
}

bool test::SpvValidator::validate( const spvgentwo::Module& _module )
{
	std::vector<uint32_t> vec;
	auto writer = BinaryVectorWriter<std::vector<uint32_t>>( vec );

	if (_module.write(writer))
	{
		if (instance().Validate(vec) == false)
		{
			PrintOptions options{ PrintOptionsBits::All };
			String buffer(_module.getAllocator(), 1024);
			auto printer = ModuleStringPrinter(buffer, false);
			printModule(_module, m_gram, printer, options);
			WARN(buffer.c_str());
			return false;
		}
		else return true;
	}
	else return false;
}