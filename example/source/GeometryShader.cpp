#include "example/GeometryShader.h"
#include "spvgentwo/TypeAlias.h"

using namespace spvgentwo;

Module examples::geometryShader(IAllocator* _pAllocator, ILogger* _pLogger)
{
    using namespace glsl;

    // create a new spir-v module
    Module module(_pAllocator, spv::Version, spv::AddressingModel::Logical, spv::MemoryModel::GLSL450, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Geometry);
    //module.addExtension("GLSL.std.450"); // needed?
    module.addSourceStringInstr()->opSource(spv::SourceLanguage::GLSL, 330u);

    EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Geometry, "main");
    entry.addExecutionMode(spv::ExecutionMode::InputPoints);
    entry.addExecutionMode(spv::ExecutionMode::Invocations, 1u);
    entry.addExecutionMode(spv::ExecutionMode::OutputLineStrip);
    entry.addExecutionMode(spv::ExecutionMode::OutputVertices, 2u);

    Type type = module.newType();

    // wouldnt it be nice to have proper relfection in c++?
    struct gl_PerVertex
    {
      vec4 gl_Position;
      float gl_PointSize;
      float gl_ClipDistance[];
    };

    type.Struct();
    type.Member().VectorElement(4).Float(); // vec4 gl_Position
    type.FloatM(); // float gl_PointSize
    type.Member().ArrayElement(1u).Float(); // float gl_ClipDistance[];
    
    module.addType(type, "gl_PerVertex"); // just to assign the name

    Instruction* outPerVertex = module.output(type, "gl_out");
    Instruction* inPerVertex = module.input(type.wrapArray(1u), "gl_in");

    // void main();
    {
        BasicBlock& bb = *entry; // get entry block to this function       

        Instruction* glin_PositionPtr = bb->opAccessChain(inPerVertex, 0u, 0u); // gl_in[0].gl_Position
        Instruction* glin_Position = bb->opLoad(glin_PositionPtr);

        Instruction* constNeg = module.constant(make_vector(-0.1f, 0.f, 0.f, 0.f));
        Instruction* newPos = bb->Add(glin_Position, constNeg);

        Instruction* glout_PositionPtr = bb->opAccessChain(outPerVertex, 0u); // gl_out.glPosition
        bb->opStore(glout_PositionPtr, newPos);
        bb->opEmitVertex();

        Instruction* constPos = module.constant(make_vector(0.1f, 0.f, 0.f, 0.f));
        newPos = bb->Add(glin_Position, constPos);
        bb->opStore(glout_PositionPtr, newPos);
        bb->opEmitVertex();

        bb->opEndPrimitive();
        entry->opReturn();
    }

    return module;
}

// SHADER:
//#version 330 core
//layout(points) in;
//layout(line_strip, max_vertices = 2) out;
//
//void main() {
//    gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.0, 0.0, 0.0);
//    EmitVertex();
//
//    gl_Position = gl_in[0].gl_Position + vec4(0.1, 0.0, 0.0, 0.0);
//    EmitVertex();
//
//    EndPrimitive();
//}