%{
	#include <cstdlib>
	#include <iostream>
	#include "Parser.tab.h"
	void yyerror(const char*);
	bool err = false;
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
			   }

{INTEGER}  {
				yylval = atoi(yytext);
				return INTEGER;
		   }

. 		   {
				if (!err)
				{
					std::cout << "ERROR" << std::endl;
					err = true;
				}
				BEGIN(ERR);
		   }

<ERR>.	   {  /* ignore */ }

<ERR>{NEWLINE}	{
					err = false;
					BEGIN(INITIAL);
				}

%%

int yywrap(void)
{
	 return 1;
}
