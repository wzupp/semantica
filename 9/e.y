%{
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char *s);

Stack ops; 
Stack current_ops;

int current_bool;
%}

%union {
    int ival;
}

%token <ival> VAL 
%token IF ELSE LPAREN RPAREN LT GT LE GE EQ NE NAME SEMICOLON
%type <ival> comp 

%nonassoc LT GT LE GE EQ NE
%left ELSE

%%

oper:
      IF LPAREN VAL comp VAL {
      int result;
      switch ($4) {
        case LT:
          result = $3 < $5;
          printf("%d < %d = %d\n", $3, $5, result);
          break;
        case GT:
          result = $3 > $5;
          printf("%d > %d = %d\n", $3, $5, result);
          break;
        case LE:
          result = $3 <= $5;
          printf("%d <= %d = %d\n", $3, $5, result);
          break;
        case GE:
          result = $3 >= $5;
          printf("%d >= %d = %d\n", $3, $5, result);
          break;
        case EQ:
          result = $3 == $5;
          printf("%d == %d = %d\n", $3, $5, result);
          break;
        case NE:
          result = $3 != $5;
          printf("%d != %d = %d\n", $3, $5, result);
          break;
        default:
          printf("ERROR! UNKNOWN OP!\n");
          exit(-1);
      }
      push(&ops, result);

  }RPAREN { push(&current_ops, 1); } op { pop(&current_ops); } oper_
    ;

oper_:
      ELSE { push(&current_ops, 0); } op { pop(&current_ops); }
    | %empty
    ;

op:
      NAME LPAREN VAL RPAREN SEMICOLON { 
      print_stack_with_message(&ops, "OPS");
      print_stack_with_message(&current_ops, "CURRENT_OPS");
      if( compare_stacks(&ops, &current_ops) || contain(&ops, &current_ops) ){
          printf("\nname(%d)\n\n", $3); 
      }
      //int val = pop(&ops);
      //if ( val == 1 ){
      //  if( current_bool == 1 ){
      //    printf("%d\n", $3); 
      //  }
      //  push(&ops, val);
      //} else {
      //  if( current_bool == 0 ){
      //    printf("%d\n", $3); 
      //  }
      //}
      // if( current_ops.top == 0 )
      //   pop(&current_ops);
}
    | oper
    ;

comp:
      LT { $$ = LT; }
    | GT { $$ = GT; }
    | LE { $$ = LE; }
    | GE { $$ = GE; }
    | EQ { $$ = EQ; }
    | NE { $$ = NE; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    yyparse();

    return 0;
}

