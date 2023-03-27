#include "sem.h"
#include <exception>
#include <string>

int lookahead;
int intvalue;
FILE *current_stream = stdin;
std::string str;

std::string semanticDecode(int Lexem) {

  std::string lexemName;

  switch (Lexem) {
  case 1:
    lexemName = "if";
    break;
    return lexemName;
  case 2:
    lexemName = "lbrace";
    break;
    return lexemName;

  case 3:
    lexemName = "rbrace";
    break;
    return lexemName;
  case 4:
    lexemName = "else";
    break;
    return lexemName;
  case 5:
    lexemName = "print";
    break;
    return lexemName;
  case 6:
    lexemName = "val";
    break;
    return lexemName;
  case 7:
    lexemName = "col";
    break;
    return lexemName;
  case 8:
    lexemName = "less";
    break;
    return lexemName;
  case 9:
    lexemName = "comp";
    break;
    return lexemName;
  case 10:
    lexemName = "empty";
    break;
    return lexemName;
  case 11:
    lexemName = "skip";
    break;
    return lexemName;
  case 12:
    lexemName = "over";
    break;
    return lexemName;
  case 13:
    lexemName = "unq";
    break;
    return lexemName;
  case 14:
    lexemName = "ool";
    break;
    return lexemName;
  case 15:
    lexemName = "loo";
    break;
    return lexemName;
  default:
    lexemName = "Error ";
    return lexemName;
  }
}

int scan() {
  str.clear();
  char t;
  while (1) {
    t = getc(current_stream);
    if (t == ' ' || t == '\t' || t == '\n' || t == '\r' || t == EOF) {
      if (t == EOF)
        return EOF;
    } else if (t == '(' || t == ')' || t == ';' || t == '<' || t == '>') {
      switch (t) {
      case '(':
        return lbrace;
      case ')':
        return rbrace;
      case ';':
        return col;
      case '<':
        return less;
      case '>':
        return over;
      };
    } else if (t >= '0' && t <= '9') {
      intvalue = t - '0';
      t = getc(current_stream);
      while (t >= '0' && t <= '9') {
        intvalue = intvalue * 10 + t - '0';
        t = getc(current_stream);
      }
      if (t == '(' || t == ')' || t == ';' || t == '<' || t == '>')
        ungetc(t, current_stream);
      return val;
    } else {
      str.push_back(t);
      while (1) {
        if (str.compare("if") == 0) {
          return IF;
        }
        if (str.compare("else") == 0) {
          return ELSE;
        }
        if (str.compare("name") == 0) {
          return name;
        }
        if (str.compare("==") == 0) {
          return COMP;
        }
        if (str.compare("!=") == 0) {
          return unq;
        }
        if (str.compare(">=") == 0) {
          return ool;
        }
        if (str.compare("<=") == 0) {
          return loo;
        }
        t = getc(current_stream);
        if ((t == ';' || t == '(' || t == ')' || t == '<' || t == '>') ||
            (t == ' ' || t == '\t' || t == '\n' || t == '\r' || t == EOF)) {
          if (t == ';' || t == '(' || t == ')' || t == '<' || t == '>') {
            ungetc(t, current_stream);
          }
          break;
        }
        str.push_back(t);
      }
      throw std::runtime_error("Доселе неизвестный в дикой природе токен\n");
    }
  }
}

int error(std::string errorMessage) {
  std::cout << errorMessage << "\n";
  exit(EXIT_FAILURE);
}
