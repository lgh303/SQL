#include <iostream>
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

void SemValue::printValues()
{
	 for (int i = 0; i < values.size(); ++i)
	 {
		  if (values[i].type == 0)
			   cout << values[i].integer;
		  else
			   cout << values[i].literal;
		  cout << " | ";
	 }
	 cout << endl;
}
