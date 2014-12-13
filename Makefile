LEX = flex
YACC = bison
CC = g++

main : lex.yy.o Parser.tab.o SemValue.o
	$(CC) lex.yy.o Parser.tab.o SemValue.o -o main

SemValue.o : SemValue.cpp SemValue.h
	$(CC) -c SemValue.cpp

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