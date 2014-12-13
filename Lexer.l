%{
	#include <cstdlib>
	#include <iostream>
	#include "SemValue.h"
	#define YYSTYPE SemValue
	#include "Parser.tab.h"
	void yyerror(const char*);
%}

OPERATOR		 ("."|"+"|"-"|"*"|"/"|"("|")"|"="|"<"|">"|";")
WHITESPACE 		 ([ \t]+)
NEWLINE  		 (\r|\n|\r\n)
INTEGER 		 ([0-9]+)
IDENTIFIER  	 ([A-Za-z][_0-9A-Za-z]*)
QUIT 			 ("quit")

CREATE			 ("CREATE"|"create")
DB				 ("DATABASE"|"database")
DROP			 ("DROP"|"drop")
USE				 ("USE"|"use")
SHOW			 ("SHOW"|"show")
TB				 ("TABLES"|"tables")
INDEX			 ("INDEX"|"index")
DESC			 ("DESC"|"desc")
NOT				 ("NOT"|"not")
NUL 			 ("NULL"|"null")
PRIMARY			 ("PRIMARY"|"primary")
FOREIGN			 ("FOREIGN"|"foreign")
KEY				 ("KEY"|"key")
CHECK			 ("CHECK"|"check")
REFER			 ("REFER"|"refer")

INS_INTO		 ("INSERT INTO"|"insert into")
VALUES			 ("VALUES"|"values")
DELETE  		 ("DELETE"|"delete")
WHERE			 ("WHERE"|"where")
UPDATE			 ("UPDATE"|"update")
SET				 ("SET"|"set")
SELECT			 ("SELECT"|"select")
FROM			 ("FROM"|"from")
LIKE			 ("LIKE"|"like")

AND				 ("AND"|"and")
OR				 ("OR"|"or")

SUM				 ("SUM"|"sum")
AVG				 ("AVG"|"avg")
MAX				 ("MAX"|"max")
MIN				 ("MIN"|"min")
GRP_BY			 ("GRPOUP BY"|"group by")

INT				 ("INT"|"int")
CHAR			 ("CHAR"|"char")
VCHAR			 ("VCHAR"|"vchar")

%x STR

%%

{WHITESPACE}   { /* ignore */ }
{NEWLINE}  	   { return ENDLINE; }
{QUIT}		   { return QUIT; }

{CREATE} 	   { return SemValue::keyword(CREATE); }
{DB}		   { return SemValue::keyword(DB); }
{DROP}		   { return SemValue::keyword(DROP); }
{USE} 		   { return SemValue::keyword(USE); }
{SHOW}	   	   { return SemValue::keyword(SHOW); }
{TB}    	   { return TB; }
{INDEX}		   { return INDEX; }
{DESC}		   { return DESC; }

{NOT}		   { return NOT; }
{NUL}		   { return NUL; }
{PRIMARY}	   { return PRIMARY; }
{FOREIGN}	   { return FOREIGN; }
{KEY}		   { return KEY; }
{CHECK}		   { return CHECK; }
{REFER}		   { return REFER; }

{INS_INTO}	   { return INS_INTO; }
{VALUES}	   { return VALUES; }
{DELETE}	   { return DELETE; }
{WHERE}		   { return WHERE; }
{UPDATE}	   { return UPDATE; }
{SET}		   { return SET; }
{SELECT}	   { return SELECT; }
{FROM}		   { return FROM; }
{LIKE}		   { return LIKE; }

{AND}		   { return AND; }
{OR}		   { return OR; }

{SUM}		   { return SUM; }
{AVG}		   { return AVG; }
{MAX}		   { return MAX; }
{MIN}		   { return MIN; }
{GRP_BY}	   { return GRP_BY; }

{INT}		   { return INT; }
{CHAR}		   { return CHAR; }
{VCHAR}		   { return VCHAR; }


{OPERATOR}     { return *yytext; }
{IDENTIFIER}   { return SemValue::identifier(std::string(yytext)); }
{INTEGER}  	   {
					return INTEGER;
			   }

<INITIAL>\"	   {
					BEGIN(STR);
			   }
<STR>.		   {
			   }
<STR>\"		   {
			   }

. 		   	   {
					return 256;
		   	   }
%%

int yywrap(void)
{
	 return 1;
}
