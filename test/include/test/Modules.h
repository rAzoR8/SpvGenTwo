#pragma once

#include "spvgentwo/Module.h"

namespace test
{
	spvgentwo::Module constants( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module types( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );

	spvgentwo::Module oldInstrTest( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module imageRead( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );

	spvgentwo::Module computeShader(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger);
	spvgentwo::Module controlFlow( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module expressionGraph( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module extensions( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module fragmentShader( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module functionCall( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module geometryShader( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module physicalStorageTest(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );

	spvgentwo::Module linkageLibA( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module linkageLibB( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	spvgentwo::Module linkageConsumer( spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger );
	bool linkageLinked( const spvgentwo::Module& _libA, const spvgentwo::Module& _libB, spvgentwo::Module& _consumer, spvgentwo::IAllocator* _pAllocator, const spvgentwo::Grammar* _pGrammar );
} // !test
