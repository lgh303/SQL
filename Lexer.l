%{
	#include <cstdlib>
	#include <iostream>
	#include "Parser.tab.h"
	void yyerror(const char*);
%}

OPERATOR  ("+"|"-"|"*"|"/"|"("|")"|"="|";")
WHITESPACE  ([ \t]+)
NEWLINE  (\r|\n|\r\n)
INTEGER ([0-9]+)

QUIT ("quit")

%x ERR

%%

{WHITESPACE}   { /* ignore */ }
{OPERATOR}     { return *yytext; }
{QUIT}		   { return QUIT; }

{NEWLINE}  	   {
					return ENDLINE;
			   }

{INTEGER}  {
				yylval = atoi(yytext);
				return INTEGER;
		   }

. 		   {
				return 256;
		   }

%%

int yywrap(void)
{
	 return 1;
}
