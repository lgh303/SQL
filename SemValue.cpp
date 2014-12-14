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

void SemValue::printAttrs()
{
	 cout << "ATTR : ";
	 if (allAttrs)
	 {
		  cout << "All Attrs Selected" << endl;
		  return;
	 }
	 for (int i = 0; i < attrList.size(); ++i)
		  cout << attrList[i].toString() << " | ";
	 cout << endl;
}

void SemValue::printTables()
{
	 cout << "TB : ";
	 for (int i = 0; i < tableList.size(); ++i)
		  cout << tableList[i] << " | ";
	 cout << endl;
}

