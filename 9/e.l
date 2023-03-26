%{
#define YYSTYPE int
#include "e.tab.h"
#include <stdlib.h>
%}
/*
%{
	#include<stdio.h>
	#include "e.tab.h"
	#include<stdlib.h>
	extern int yylval;
%}
*/

%option noyywrap yylineno
DIGIT    [0-9]
ID       [a-z][a-z0-9]*
NUMBER   [0-9]+

%%

[0-9]+	{ 
		yylval = atoi(yytext);
		return NUM;
	}



"if"	  return IF;
"else"  return ELSE;
"name"   return PRINT;
"=="	return EQUAL;

[<,();\n] 	{
		   
			yylval = yytext[0];
			return *yytext;
		}


%%


