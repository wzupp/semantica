#include <iostream>
#include "parser.h"

int main ()
{
	Parser parser;
	parser.open_file ();
	parser.lookahead = parser.scan ();
	parser.Z ();
	return 0;
}
//scaner
