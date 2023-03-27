#include "sem.h"
#include <stdio.h>

extern int lookahead;
extern int intvalue;

bool boolValue;

std::string op();
void operOper();
bool compComp();
int comp();
std::string oper();
std::string oper__();

int valuePrint;

int comp() {
  if (lookahead == less || lookahead == COMP || lookahead == over ||
      lookahead == unq || lookahead == ool || lookahead == loo) {
    return lookahead;
  }
  throw std::runtime_error("Ожидалась лексема нетерминала <comp>\n");
}

std::string oper__() {
  // <oper’>::= else <op>| e
  if (lookahead == EOF)
    return "";

  if (lookahead != ELSE)
    throw std::runtime_error("Ожидалось else");

  lookahead = scan();
  return op();
};

std::string op() {
  // <op>::= name(val); | <oper>
  if (lookahead != name)
    return oper();

  lookahead = scan();
  if (lookahead != lbrace)
    throw std::runtime_error("Expected (\n");

  lookahead = scan();
  if (lookahead != val)
    throw std::runtime_error("Expected val\n");
  auto val = intvalue;

  lookahead = scan();
  if (lookahead != rbrace)
    throw std::runtime_error("Expected )\n");

  lookahead = scan();
  if (lookahead != col)
    throw std::runtime_error("Expected ;\n");

  return std::to_string(val) + "\n";
}

std::string oper() {
  // <oper>:: if (val<comp> val) <op> <oper’>
  std::string result = "";
  if (lookahead != IF)
    throw std::runtime_error("Expected IF\n");

  lookahead = scan();
  if (lookahead != lbrace)
    throw std::runtime_error("Expected (\n");

  lookahead = scan();
  if (lookahead != val)
    throw std::runtime_error("Expected val\n");
  auto lval_if = intvalue;

  lookahead = scan();
  auto comp_op = comp();

  lookahead = scan();
  if (lookahead != val)
    throw std::runtime_error("Expected val\n");
  auto rval_if = intvalue;

  bool if_value;
  switch (comp_op) {
  case less:
    if_value = lval_if < rval_if;
    break;
  case COMP:
    if_value = lval_if == rval_if;
    break;
  case over:
    if_value = lval_if > rval_if;
    break;
  case unq:
    if_value = lval_if != rval_if;
    break;
  case ool:
    if_value = lval_if >= rval_if;
    break;
  case loo:
    if_value = lval_if <= rval_if;
    break;
  default:
    throw std::runtime_error("Impossible state\n");
  }

  lookahead = scan();
  if (lookahead != rbrace)
    throw std::runtime_error("Expected )\n");

  lookahead = scan();
  if (if_value)
    result = op();
  else
    op();

  lookahead = scan();
  if (!if_value)
    result = oper__();
  else
    oper__();

  return result;
}

int main() {
  lookahead = scan();
  auto result = oper();

  std::cout << "\n"
            << "\nResult\n"
            << result;

  std::cin.get();
  return 0;
}
