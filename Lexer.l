%{
	#include <cstdlib>
	#include <iostream>
	#include "SemValue.h"
	#define YYSTYPE SemValue
	#include "Parser.tab.h"
	void yyerror(const char*);
	std::string str;
	using namespace std;
%}

OPERATOR		 (","|"."|"+"|"-"|"*"|"/"|"("|")"|"="|"<"|">"|";")
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
TBS				 ("TABLES"|"tables")
TB				 ("TABLE"|"table")
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
VCHAR			 ("VARCHAR"|"varchar")

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
{TB}    	   { return SemValue::keyword(TB); }
{TBS}    	   { return SemValue::keyword(TBS); }
{INDEX}		   { return SemValue::keyword(INDEX); }
{DESC}		   { return SemValue::keyword(DESC); }

{NOT}		   { return SemValue::keyword(NOT); }
{NUL}		   { return SemValue::keyword(NUL); }
{PRIMARY}	   { return SemValue::keyword(PRIMARY); }
{FOREIGN}	   { return SemValue::keyword(FOREIGN); }
{KEY}		   { return SemValue::keyword(KEY); }
{CHECK}		   { return SemValue::keyword(CHECK); }
{REFER}		   { return SemValue::keyword(REFER); }

{INS_INTO}	   { return SemValue::keyword(INS_INTO); }
{VALUES}	   { return SemValue::keyword(VALUES); }
{DELETE}	   { return SemValue::keyword(DELETE); }
{WHERE}		   { return SemValue::keyword(WHERE); }
{UPDATE}	   { return SemValue::keyword(UPDATE); }
{SET}		   { return SemValue::keyword(SET); }
{SELECT}	   { return SemValue::keyword(SELECT); }
{FROM}		   { return SemValue::keyword(FROM); }
{LIKE}		   { return SemValue::keyword(LIKE); }

{AND}		   { return SemValue::keyword(AND); }
{OR}		   { return SemValue::keyword(OR); }

{SUM}		   { return SemValue::keyword(SUM); }
{AVG}		   { return SemValue::keyword(AVG); }
{MAX}		   { return SemValue::keyword(MAX); }
{MIN}		   { return SemValue::keyword(MIN); }
{GRP_BY}	   { return SemValue::keyword(GRP_BY); }

{INT}		   { return SemValue::keyword(INT); }
{CHAR}		   { return SemValue::keyword(CHAR); }
{VCHAR}		   { return SemValue::keyword(VCHAR); }


{OPERATOR}     { return *yytext; }
{IDENTIFIER}   {
					yylval = SemValue();
					yylval.code = IDENTIFIER;
					yylval.id = std::string(yytext);
					return IDENTIFIER;
			   }
{INTEGER}  	   {
					yylval = SemValue();
					yylval.code = INTEGER;
					yylval.length = atoi(yytext);
					return INTEGER;
			   }	

<INITIAL>\"    {
					str = std::string();
					cout << "begin str" << endl;
					BEGIN(STR);
			   }

<STR>\"	   	   {
					BEGIN(INITIAL);
					yylval = SemValue();
					yylval.code = LITERAL;
					yylval.literal = str;
					return LITERAL;
			   }

<STR>.		   {
					str += char(*yytext);
			   }

. 		   	   {
					return 256;
		   	   }
%%

int yywrap(void)
{
	 return 1;
}
