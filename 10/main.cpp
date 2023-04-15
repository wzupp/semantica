#include "MyGrammarBaseVisitor.h"
#include "MyGrammarLexer.h"
#include "MyGrammarParser.h"
#include <ANTLRInputStream.h>
#include <antlr4-runtime.h>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class EvaluatorVisitor : public MyGrammarBaseVisitor {
private:
  int value;

public:
  int result() const { return value; }

  virtual antlrcpp::Any visitOper(MyGrammarParser::OperContext *ctx) override {
    int left = std::stoi(ctx->VAL(0)->getText());
    int right = std::stoi(ctx->VAL(1)->getText());
    std::string comp_type = std::any_cast<std::string>(visit(ctx->comp()));

    bool condition = false;

    if (comp_type == "less") {
      condition = left < right;
    } else if (comp_type == "more") {
      condition = left > right;
    } else if (comp_type == "lt") {
      condition = left <= right;
    } else if (comp_type == "gt") {
      condition = left >= right;
    } else if (comp_type == "eq") {
      condition = left == right;
    } else if (comp_type == "neq") {
      condition = left != right;
    }

    if (condition) {
      visit(ctx->op());
    } else {
      visit(ctx->oper_());
    }

    return nullptr;
  }

  virtual antlrcpp::Any
  visitOper_(MyGrammarParser::Oper_Context *ctx) override {
    if (ctx->op()) {
      visit(ctx->op());
    }

    return nullptr;
  }

  virtual antlrcpp::Any visitComp(MyGrammarParser::CompContext *ctx) override {
    std::string result;

    if (ctx->less) {
      result = "less";
    } else if (ctx->more) {
      result = "more";
    } else if (ctx->lt) {
      result = "lt";
    } else if (ctx->gt) {
      result = "gt";
    } else if (ctx->eq) {
      result = "eq";
    } else if (ctx->neq) {
      result = "neq";
    }

    return result;
  }

  virtual antlrcpp::Any visitOp(MyGrammarParser::OpContext *ctx) override {
    if (ctx->VAL()) {
      value = std::stoi(ctx->VAL()->getText());
    } else {
      visit(ctx->oper());
    }

    return nullptr;
  }
};

int main(int argc, const char *argv[]) {
  std::ifstream stream;
  if (argc > 1) {
    stream.open(argv[1]);
    std::cout << argv[1] << std::endl;
  } else {
    stream.open("../test");
  }
  antlr4::ANTLRInputStream input(stream);

  MyGrammarLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  MyGrammarParser parser(&tokens);
  EvaluatorVisitor visitor;

  antlr4::tree::ParseTree *tree = parser.oper();
  visitor.visit(tree);

  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
  std::cout << "Final result: " << visitor.result() << std::endl;

  return 0;
}
