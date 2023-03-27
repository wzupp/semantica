#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

// Односимвольники:
// (  ) ; < >
//
// Многосимвольники:
// if else name == != >= <=
//
// <oper>:: if (val<comp> val) <op> <oper’>
// <oper’>::= else <op>| e
// <op>::= name(val); | <oper>
// <comp>::= <|>|<=|>=| == | !=

enum {
  IF = 1,     // 'if'
  lbrace = 2, // (
  rbrace = 3, // )
  ELSE = 4,   // 'else'
  name = 5,   // 'name'
  val = 6,    //
  col = 7,    // ;
  less = 8,   // <
  COMP = 9,   // ==
  empty = 10, //
  skip = 11,  //
  over = 12,  // >
  unq = 13,   // !=
  ool = 14,   // >=
  loo = 15    // <=
};

int scan();
int error(std::string errorMessage);

#endif
