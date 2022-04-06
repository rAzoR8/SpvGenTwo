#include "test/SpvValidator.h"
#include "common/BinaryVectorWriter.h"
#include "spirv-tools/libspirv.hpp"

#include <catch2/catch_test_macros.hpp>

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


test::SpvValidator::SpvValidator()
{
}

bool test::SpvValidator::validate( const spvgentwo::Module& _module )
{
	std::vector<uint32_t> vec;
	auto writer = spvgentwo::BinaryVectorWriter( vec );

	return _module.write( writer ) && instance().Validate( vec );
}