#include "test/SpvValidator.h"
#include "common/BinaryVectorWriter.h"
#include "spirv-tools/libspirv.hpp"

namespace
{
    class MessageConsumer
    {
    public:
        MessageConsumer( spvgentwo::ILogger* _pLogger ) : m_pLogger( _pLogger ) {};
        void operator()( spv_message_level_t level, const char*, const spv_position_t& position, const char* message )
        {
            switch( level ) {
            case SPV_MSG_FATAL:
                m_pLogger->log( spvgentwo::LogLevel::Fatal, "line %ull idx %ull : %s", position.line, position.index, message );
                break;
            case SPV_MSG_INTERNAL_ERROR:
            case SPV_MSG_ERROR:
                m_pLogger->log( spvgentwo::LogLevel::Error, "line %ull idx %ull : %s", position.line, position.index, message );
                break;
            case SPV_MSG_WARNING:
                m_pLogger->log( spvgentwo::LogLevel::Warning, "line %ull idx %ull : %s", position.line, position.index, message );
                break;
            case SPV_MSG_INFO:
                m_pLogger->log( spvgentwo::LogLevel::Info, "line %ull idx %ull : %s", position.line, position.index, message );
                break;
            default:
                break;
            }
        }
    private:
        spvgentwo::ILogger* m_pLogger;
    };

    static spvtools::SpirvTools& instance( spvgentwo::ILogger* _pLogger )
    {
        static spvtools::SpirvTools tools( SPV_ENV_UNIVERSAL_1_6 );
        static bool toolsInitialized = false;

        if( tools.IsValid() && toolsInitialized == false )
        {
            tools.SetMessageConsumer( MessageConsumer( _pLogger ) );
            toolsInitialized = true;
        }

        return tools;
    }
}


test::SpvValidator::SpvValidator( spvgentwo::ILogger* _pLogger ) : m_pLogger(_pLogger)
{

}

bool test::SpvValidator::validate( const spvgentwo::Module& _module )
{
	std::vector<uint32_t> vec;
	auto writer = spvgentwo::BinaryVectorWriter( vec );

	return _module.write( writer ) && instance( m_pLogger ).Validate( vec );
}