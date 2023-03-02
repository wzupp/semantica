#include "parser.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cctype>


#define MAX_LEXEM 10 //длина одного слова.

Parser::Parser ()
{
}

Parser::~Parser ()
{
}

void Parser::open_file ()
{
  if (!fopen("input.txt","r")) {
      printf("Error. Cannot open file");
      return;
    }
  file = fopen ("input.txt", "r");
  lookahead = -1;

}


char lexem [MAX_LEXEM];

int Parser::scan ()
{
  char ch;
 // char lexem [MAX_LEXEM];
  int j=0;
  for (int i=0; i < MAX_LEXEM; i++)
    lexem[i]='\0' ;

  while(true)
    {
      ch=fgetc(file);
	if ( ch == ' ')
		continue;
    	 else if (isalnum(ch))
        {

          lexem[j] = ch;
          j++;
		do 
		{
			ch = fgetc(file);
			if ( isalnum(ch))
			{
				lexem[j] = ch;
				j++;
			}else
			{
				ungetc(ch,file);
				break;
			}
		}while(isalnum(ch));
		break;
        }
	else if (ch == '('|| ch == ')' || ch == '<' || ch == '>' || ch == ';')
	{
		lexem[j] = ch;
		break;
	}
	else if ( ch == '=')
	{
		lexem[j] = ch;
		j++;
		ch= fgetc(file);
		if( ch == '=')
		{
			lexem[j] = ch;
			break;
		}
	}
      else  
        break;
    }

 // printf ("Scan : \t%s\t interpreted as ", lexem);

  if ((lexem[0]=='i') && 
      (lexem[1]=='f'))
    {
     // printf ("IF\n");
      lookahead = IF;
    }
  else if ((lexem[0]=='p') &&
           (lexem[1]=='r') &&
           (lexem[2]=='i') &&
           (lexem[3]=='n') &&
           (lexem[4]=='t'))
    {
     // printf ("PRINT\n");
      lookahead = PRINT;
    }
      else if ((lexem[0]=='e') &&
           (lexem[1]=='l') &&
           (lexem[2]=='s') &&
           (lexem[3]=='e'))
    {
     // printf ("ELSE\n");
      lookahead = ELSE;
    }
  else if (isDigit (lexem))
    {
     // printf ("NUM\n");
      lookahead = NUM;
    }
  else if (lexem[0] == '<')
    {
     // printf ("LESS\n");
      lookahead = LESS;
    }
  else if (lexem[0] == '>')
    {
     // printf ("MORE\n");
      lookahead = MORE;
    }
  else if (lexem[0] == '(')
    {
     // printf ("OP_BR\n");
      lookahead = OP_BR;
    }
  else if (  (lexem[0] == ';') )
    {
     // printf ("SEM\n");
      lookahead = SEM;
    }
  else if (lexem[0] == ')')
    {
     // printf ("CL_BR\n");
      lookahead = CL_BR;
    }
  else if ((lexem[0]=='=') &&
          (lexem[1]=='='))
  {
   // printf ("COMPR\n");
    lookahead = COMPR;
  }
  return lookahead;
}

void Parser::match ( int t )
{
  if (lookahead == t)
    {
      lookahead = scan();
    }
  else if (lookahead == SEM)
    return;
  else
    {
      err ("Invalid input, match error");
    }
}

void Parser::err ( std::string str )
{
  std::cout << std::endl;
  std::cout << str << std::endl;
  exit (1);
}

int Parser::Z ()
{
  z();
  printf ("\nSuccess!\n");
  return lookahead;
}

int Parser::z ()
{
  if (lookahead == IF)
    {
      match (IF);
      match (OP_BR);
      cond();
      match (CL_BR);
      z();
    }
  else if (lookahead == PRINT)
    {
      match (PRINT);
      match (OP_BR);
      printf("\n body: ");
      param();
      match(CL_BR);
      match (SEM);
      body();
    }
    else if (lookahead == ELSE){
      match(ELSE);
      body();
    }
  else
    err ("error in z");
  return lookahead;
}

int Parser::body(){
  if (lookahead == PRINT)
    {
      match (PRINT);
      match (OP_BR);
     // printf("\n body: ");
      param(); 
      match(CL_BR);
      match (SEM);
    }
    else if (lookahead == ELSE){
      match(ELSE);
      body();
    }
  else
    err ("error in body");
  return lookahead;
}

int Parser::cond () 
{
  printf("conditional: ");
  param();
 // printf("%S ",lexem);
  if (lookahead == LESS)
    {
      printf("%S ",lexem);
      match (LESS);
     // printf("%S ",lexem);
      param();
    }
  else if (lookahead == MORE)
    {
      printf("%S ",lexem);
      match (MORE);
     // printf("%S ",lexem);
      param();
    }
  else if (lookahead == COMPR)
    {
      printf("%C%C ",lexem[0],lexem[1]);
      match (COMPR);
    //  printf("%S ",lexem);
      param();
    }
else {
      err("error in cond");
}
  return lookahead;
}

int Parser::param()
{
 if (lookahead == NUM)
    {
      printf("%S ",lexem);
      match (NUM);
     // printf("%S ",lexem);
    }
    else err("error in param");
  return lookahead;
}




bool Parser::isDigit (char* t)
{
  if((t[0]<='9') && (t[0]>='0'))
    return true;
  else
    return false;
}
