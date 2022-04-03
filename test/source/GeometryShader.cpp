#include "example/GeometryShader.h"
#include "spvgentwo/TypeAlias.h"
#include "spvgentwo/Templates.h"

using namespace spvgentwo;

Module examples::geometryShader(IAllocator* _pAllocator, ILogger* _pLogger)
{
    using namespace glsl;

    // create a new spir-v module
    Module module(_pAllocator, spv::AddressingModel::Logical, spv::MemoryModel::GLSL450, _pLogger);

    // configure capabilities and extensions
    module.addCapability(spv::Capability::Geometry);
    //module.addExtension("GLSL.std.450"); // needed?
    module.addSourceStringInstr()->opSource(spv::SourceLanguage::GLSL, 330u);

    EntryPoint& entry = module.addEntryPoint(spv::ExecutionModel::Geometry, u8"main");
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
      float gl_ClipDistance[1];
    };

    type.Struct();
    type.Member().VectorElement(4).Float(); // vec4 gl_Position
    type.FloatM(); // float gl_PointSize
    type.Member().ArrayElement(1u).Float(); // float gl_ClipDistance[];
    
    Instruction* glPerVertexType = module.addType(type, u8"gl_PerVertex"); // just to assign the name
    module.addDecorationInstr()->opDecorate(glPerVertexType, spv::Decoration::Block);
    module.addDecorationInstr()->opMemberDecorate(glPerVertexType, 0, spv::Decoration::BuiltIn, spv::BuiltIn::Position);
    module.addDecorationInstr()->opMemberDecorate(glPerVertexType, 1, spv::Decoration::BuiltIn, spv::BuiltIn::PointSize);
    module.addDecorationInstr()->opMemberDecorate(glPerVertexType, 2, spv::Decoration::BuiltIn, spv::BuiltIn::ClipDistance);
    module.addMemberName(glPerVertexType, u8"gl_Position", 0u);
    module.addMemberName(glPerVertexType, u8"gl_PointSize", 1u);
    module.addMemberName(glPerVertexType, u8"gl_ClipDistance", 2u);

    const char* memberName = glPerVertexType->getName(1u);

    Instruction* outPerVertex = module.output(type, u8"gl_out");
    Instruction* inPerVertex = module.input(type.wrapArray(1u), u8"gl_in");

    // void main();
    {
        BasicBlock& bb = *entry; // get entry block to this function       

        // test comp
        {
            Instruction* glin_PerVertexPtr = bb->opAccessChain(inPerVertex); // gl_in[0].gl_Position
            Instruction* glin_PerVertex = bb->opLoad(glin_PerVertexPtr); // array

            Instruction* struct_ = bb->opCompositeExtract(glin_PerVertex, 0u); // get the struct
            Instruction* vec_y = bb->opCompositeExtract(struct_, 0u, 1u); // get vec -> get y element

            vec_y = bb->Mul(vec_y, vec_y); // square

            bb->opCompositeInsert(glin_PerVertex, vec_y, 0u, 0u, 1u);
        }

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