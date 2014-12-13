%{
	#include <iostream>
	#include <cstdlib>
	void yyerror(const char*);
	int yylex(void);
%}

%token INTEGER
%token QUIT
%left '+' '-'
%left '*' '/'

%%

program :
		program stmt
		| /* empty */
		;
stmt : 
	     QUIT
	   	 {
			exit(0);
         }
	   | INTEGER ';'
	     {
			std::cout << "Number : " << $1 << std::endl;
		 }
	   ;


%%

void yyerror(const char *s)
{
	 std::cout << "Syntax Error" << std::endl;
}

int main(int argc, char** argv)
{
	yyparse();
	return 0;
}
