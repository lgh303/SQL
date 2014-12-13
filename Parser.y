%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include "SemValue.h"
	#define YYSTYPE SemValue
	void yyerror(const char*);
	void prompt();
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
%}

%token INTEGER IDENTIFIER LITERAL
%token ENDLINE QUIT
%token CREATE DB DROP USE SHOW TB INDEX DESC
%token NOT NUL PRIMARY FOREIGN KEY CHECK REFER
%token INS_INTO VALUES DELETE
%token WHERE UPDATE SET SELECT FROM LIKE
%token AND OR SUM AVG MAX MIN GRP_BY
%token INT CHAR VCHAR

%left '+' '-'
%left '*' '/'

%%

program :
		program stmt
		| /* empty */
		;
stmt : 
		 ENDLINE
		 {
			prompt();
		 }
	     | QUIT ENDLINE
	   	   {
				exit(0);
           }
	   	 | CREATE DB IDENTIFIER ';' ENDLINE
		   {
				std::cout << "create db" << std::endl;
				std::cout << $3.id << std::endl;
				prompt();
		   }
		 | DROP DB IDENTIFIER ';' ENDLINE
		   {
				std::cout << "drop db" << std::endl;
				std::cout << $3.id << std::endl;
				prompt();
		   }
		 | USE IDENTIFIER ';' ENDLINE
		   {
				std::cout << "use db" << std::endl;
				std::cout << $2.id << std::endl;
				prompt();
		   }
		 | SHOW TB ';' ENDLINE
		   {
				std::cout << "show tables" << std::endl;
				prompt();
		   }
	   	 | error ENDLINE
	   	   {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
	   	   ;

%%

void prompt()
{
	if (isInterp)
	{
		std::cout << " sql> ";
	}
}

void yyerror(const char *s)
{
	/* Do Nothing */
}

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return -1;
	}
	if (argc == 2)
	{
		FILE* pFile = fopen(argv[1], "r");
		if (!pFile)
		{
			std::cout << "Input File not Exist!" << std::endl;
			return -1;
		}
		isInterp = false;
		yyin = pFile;
		yyparse();
	}
	if (argc == 1)
	{
		isInterp = true;
		prompt();
		yyparse();
	}
	return 0;
}
