all:  my

my: e.l e.y 
	bison -t -d e.y
	flex  e.l
	cc lex.yy.c e.tab.c -g 
	./a.out < testfile.test

clean: 
	rm e.tab.* a.exe a.out lex.yy.c
