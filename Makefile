a.out : lex.yy.c y.tab.c
	gcc lex.yy.c y.tab.c -lfl -w
lex.yy.c : lexical_analyser.l y.tab.c
	lex lexical_analyser.l
y.tab.c : parser.y
	yacc -d parser.y

clean : rm -f lex.yy.c y.tab.h y.tab.c