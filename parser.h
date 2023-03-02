#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>

class Parser
{
public:
    int lookahead;

    Parser ();
    ~Parser();

	int scan ();
	void match ( int );
	void err ( std::string );
	int Z ();
	void open_file ();

private:
	FILE* file;

	int z ();
	int body();
	int cond ();
	int param();
	int var ();
	

	bool isVariable ( char* str);
	bool isPlus (char* str);
	bool isDigit (char* str);
};

enum
{
	IF,		
	PRINT,
	NUM,
	LESS, // <
	MORE, // > 
	OP_BR, // (
	CL_BR, // )
	SEM,// ;
	ELSE,		//else
	COMPR,		//==
};
//parser
#endif // PARSER_H
