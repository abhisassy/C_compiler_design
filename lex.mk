a.out : lex.yy.c
	gcc lex.yy.c -lfl
lex.yy.c : lexical_analyser.l
	lex lexical_analyser.l
