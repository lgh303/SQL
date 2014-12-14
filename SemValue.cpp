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

