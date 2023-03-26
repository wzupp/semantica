all:  my

my: e.l e.y 
	bison -t -d e.y
	flex --debug e.l
	cc lex.yy.c e.tab.c -g 
	./a.exe < testfile.test
