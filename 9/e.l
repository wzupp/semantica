%{
#include "e.tab.h"
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
%}

%%

"if"               { return IF; }
"else"             { return ELSE; }
"("                { return LPAREN; }
")"                { return RPAREN; }
"<"                { return LT; }
">"                { return GT; }
"<="               { return LE; }
">="               { return GE; }
"=="               { return EQ; }
"!="               { return NE; }
"name"             { return NAME; }
[0-9]+             { yylval.ival = atoi(yytext); return VAL; }
";"                { return SEMICOLON; }

[ \t\n]            {  }
.                  {  }

%%

int yywrap() {
    return 1;
}

