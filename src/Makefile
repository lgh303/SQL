LEX = flex
YACC = bison
CC = g++
FLAGS = -D__LINUX__
SRC = *.cpp *.c
HEADER = *.h


main : $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o main

Parser.tab.h Parser.tab.c : Parser.y
	$(YACC) -W -d Parser.y

lex.yy.c : Lexer.l
	$(LEX) Lexer.l

clean : 
	rm -f main
