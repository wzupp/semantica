/* C Declarations */

%{
	#include <stdio.h>
	
	int nothingToPrint = 0;
%}


%token VAL IF ELSE NAME EQUAL NUM
%nonassoc IFX
%nonassoc ELSE
%nonassoc PRINT
%left '<'  EQUAL


%%

p : /* empty */
  | p s
  ;

s : oper '\n' {if(nothingToPrint==0) printf("Result: %d\n\n", $1); if (nothingToPrint==1) printf("Result: -\n\n");};
  | error '\n'
  ;


oper  :
                  
	                      
	IF '(' comp ')' op %prec IFX { 
								if($3)
								{
									$$ = $5;
									
								}
								else
								{
									nothingToPrint = 1;
							     	
								}
								
							}

	| IF '(' comp ')' op ELSE op  {
								 	if($3)
									{
										$$ = $5;
										
									}
									else
									{
										$$ = $7;
										
									};
									
								}
	;
	
op: NAME '(' comp ')' ';' {$$=$3;}
	    |oper
	;		



comp:  NUM				{ $$ = $1; }
	| comp '<' comp		{ $$ = $1 < $3; }
	| comp '>' comp		{ $$ = $1 > $3; }
	| comp "<=" comp	{ $$ = $1 <= $3; }
	| comp ">=" comp	{ $$ = $1 >= $3; }
	| comp "!=" comp	{ $$ = $1 != $3; }
	| comp EQUAL comp	{ $$ = $1 == $3; }
	| '(' comp ')'		{ $$ = $2; }
	
	;
%%

int yywrap(){ return 1;}
int main() { yyparse(); }
void yyerror( char *mes ) {  printf( "error: '%s'", mes ); }