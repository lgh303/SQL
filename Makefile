LEX = flex
YACC = bison
CC = g++
SRC = *.cpp *.c


main : $(SRC)
	$(CC) $(SRC) -o main

Parser.tab.c Parser.tab.h : Parser.y
	$(YACC) -W -d Parser.y

lex.yy.c : Lexer.l
	$(LEX) Lexer.l

clean : 
	rm -f *.o
	rm main