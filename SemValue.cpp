#include "SemValue.h"
#define YYSTYPE SemValue
#include "Parser.tab.h"

extern YYSTYPE yylval;

using namespace std;

int SemValue::keyword(int code)
{
	 yylval = SemValue();
	 yylval.code = code;
	 return code;
}

int SemValue::identifier(string name)
{
	 yylval = SemValue();
	 yylval.code = IDENTIFIER;
	 yylval.id = name;
	 return IDENTIFIER;
}
