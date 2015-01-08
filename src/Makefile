LEX = flex
YACC = bison
CC = g++
FLAGS = -D__LINUX__

HEADER = DBPage.h DBPageInfo.h DBRecord.h \
DBBufManager.h DBUtility.h DBError.h \
Global.h DBFile.h DBFileInfo.h DBFileManager.h \
Attr.h CondEntry.h Condition.h \
Expr.h SchemaEntry.h Schema.h \
SemValue.h Value.h Parser.tab.h \
OrderPack.h \
BNode.h BTree.h IndexManager.h

IO_SRC = DBPage.cpp DBRecord.cpp DBBufManager.cpp \
DBError.cpp Global.cpp DBFile.cpp \
DBFileManager.cpp \
BNode.cpp BTree.cpp IndexManager.cpp

IO_OBJ = DBPage.o DBRecord.o DBBufManager.o \
DBError.o Global.o DBFile.o \
DBFileManager.o \
BNode.o BTree.o IndexManager.o

PARSER_SRC = Condition.cpp SemValue.cpp Schema.cpp \
Parser.tab.c lex.yy.c \
OrderPack.cpp

PARSER_OBJ = Condition.o SemValue.o Schema.o \
Parser.tab.o lex.yy.o \
OrderPack.o


TARGET = ./main

main : $(IO_OBJ) $(PARSER_OBJ)
	$(CC) $(IO_OBJ) $(PARSER_OBJ) -o $(TARGET)

$(IO_OBJ) : $(IO_SRC) $(HEADER)
	$(CC) -c $(FLAGS) $(IO_SRC)

$(PARSER_OBJ) : $(PARSER_SRC) $(HEADER)
	$(CC) -c $(PARSER_SRC)

Parser.tab.h Parser.tab.c : Parser.y
	$(YACC) -W -d Parser.y

lex.yy.c : Lexer.l
	$(LEX) Lexer.l

clean : 
	rm $(TARGET)
	rm *.o