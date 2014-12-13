LEX = flex
YACC = bison
CC = g++

main : lex.yy.o Parser.tab.o
	$(CC) lex.yy.o Parser.tab.o -o main

lex.yy.o : lex.yy.c Parser.tab.h
	$(CC) -c lex.yy.c

Parser.tab.o : Parser.tab.c
	$(CC) -c Parser.tab.c

Parser.tab.c Parser.tab.h : Parser.y
	$(YACC) -d Parser.y

lex.yy.c : Lexer.l
	$(LEX) Lexer.l

clean : 
	rm -f *.o *.c *.h 
	rm main