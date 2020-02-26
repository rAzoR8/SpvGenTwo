#include "ExpressionGraph.h"
#include "common/ExprGraph.h"

using namespace spvgentwo;

enum class Op
{
	Nop,
	Var,
	Const,
	Add,
	Sub,
	Mul,
	Div
};

struct MyExpr
{
	const char* name = nullptr;
	BasicBlock& bb;
	Op op = Op::Nop;
	//Instruction* constnt = nullptr;
	Instruction* result = nullptr;

	template<class Node>
	void operator()(Node& parent)
	{
		switch (op)
		{
		case Op::Nop:
			/*result =*/ bb->opNop();
			break;
		case Op::Var:
			break;
		case Op::Const:
			//result = constant;//bb.getModule()->addConstant(constant);
			break;
		case Op::Add:
		{
			Node* lex = parent.inputs().front().pTarget;
			Node* rex = parent.inputs().back().pTarget;

			Instruction* lhs = lex->data().get().result;
			Instruction* rhs = rex->data().get().result;

			result = bb->Add(lhs, rhs);
		}
			break;
		case Op::Sub:
		{
			Node* lex = parent.inputs().front().pTarget;
			Node* rex = parent.inputs().back().pTarget;

			Instruction* lhs = lex->data().get().result;
			Instruction* rhs = rex->data().get().result;

			result = bb->Sub(lhs, rhs);
		}
			break;
		case Op::Mul:
		{
			Node* lex = parent.inputs().front().pTarget;
			Node* rex = parent.inputs().back().pTarget;

			Instruction* lhs = lex->data().get().result;
			Instruction* rhs = rex->data().get().result;

			result = bb->Mul(lhs, rhs);
		}
			break;
		case Op::Div:
		{
			Node* lex = parent.inputs().front().pTarget;
			Node* rex = parent.inputs().back().pTarget;

			Instruction* lhs = lex->data().get().result;
			Instruction* rhs = rex->data().get().result;

			result = bb->Div(lhs, rhs);
		}
			break;
		default:
			break;
		}
	};
};

spvgentwo::Module examples::expressionGraph(spvgentwo::IAllocator* _pAllocator, spvgentwo::ILogger* _pLogger)
{
	//auto expr = make_expr([]() {printf("hallo"); return 1u; });

	//auto val = expr();
	//Graph<spv::Op> g(&alloc);

	//g.emplace(spv::Op::OpIAdd)->connect(g.emplace(spv::Op::OpIMul));

	Module module(_pAllocator, spv::Version, _pLogger);
	module.addCapability(spv::Capability::Shader);
	Function& main = module.addEntryPoint<void>(spv::ExecutionModel::Vertex, "main");
	BasicBlock& bb = *main;

	ExprGraph<MyExpr> exprgraph(_pAllocator);

	auto* c1 = exprgraph.emplace(MyExpr{ "c1", bb, Op::Const, module.constant(1337) });
	auto* c2 = exprgraph.emplace(MyExpr{ "c1",bb, Op::Const, module.constant(42) });

	auto* add = exprgraph.emplace(MyExpr{ "add",bb, Op::Add });
	auto* sub = exprgraph.emplace(MyExpr{ "sub",bb, Op::Sub });
	auto* mul = exprgraph.emplace(MyExpr{ "mul",bb, Op::Mul });
	auto* div = exprgraph.emplace(MyExpr{ "div",bb, Op::Div });

	// c1 + c1 = add
	c1->connect(add);
	c2->connect(add);

	// c2 - add = sub
	c2->connect(sub);
	add->connect(sub);

	// sub * add = mul
	sub->connect(mul);
	add->connect(mul);

	// c1 / mul = div
	c1->connect(div);
	mul->connect(div);

	exprgraph.evaluateRecursive(div);

	bb.returnValue();

	return module;
}
