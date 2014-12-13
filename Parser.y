%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	void yyerror(const char*);
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
%}

%token INTEGER
%token ENDLINE QUIT
%left '+' '-'
%left '*' '/'

%%

program :
		program stmt
		| /* empty */
		;
stmt : 
	     QUIT ENDLINE
	   	 {
			exit(0);
         }
	   | INTEGER ';' ENDLINE
	     {
			std::cout << "Number : " << $1 << std::endl;
			if (isInterp)
			{
				std::cout << " sql> ";
			}
		 }
	   | error ENDLINE
	   	 {
			std::cout << "Syntax Error" << std::endl;
			if (isInterp)
			{
				std::cout << " sql> ";
			}
		 }
	   ;

%%

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
		std::cout << " sql> ";
		yyparse();
	}
	return 0;
}
