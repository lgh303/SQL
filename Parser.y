%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include "SemValue.h"
	#define YYSTYPE SemValue
	void yyerror(const char*);
	void prompt();
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
	using namespace std;
%}

%token INTEGER IDENTIFIER LITERAL
%token ENDLINE QUIT
%token CREATE DB DROP USE SHOW TB TBS INDEX DESC
%token NOT NUL PRIMARY FOREIGN KEY CHECK REFER
%token INS_INTO VALUES DELETE
%token WHERE UPDATE SET SELECT FROM LIKE
%token AND OR SUM AVG MAX MIN GRP_BY
%token INT CHAR VCHAR

%left '+' '-'
%left '*' '/'

%%

Program :
		  Program Stmt
		| /* empty */
		;
Stmt : 
		   ENDLINE
		   {
				prompt();
		   }
	     | QUIT ENDLINE
	   	   {
				exit(0);
           }
	   	 | CREATE DB IDENTIFIER ';' ENDLINE
		   {
				std::string dbname = $3.id;
				std::cout << "create db ";
				std::cout << dbname << std::endl;
				prompt();
		   }
		 | DROP DB IDENTIFIER ';' ENDLINE
		   {
				std::string dbname = $3.id;
				std::cout << "drop db ";
				std::cout << dbname << std::endl;
				prompt();
		   }
		 | USE IDENTIFIER ';' ENDLINE
		   {
				std::string dbname = $2.id;
				std::cout << "use db ";
				std::cout << dbname << std::endl;
				prompt();
		   }
		 | SHOW TBS ';' ENDLINE
		   {
				std::cout << "show tables" << std::endl;
				prompt();
		   }
		 | CREATE TB IDENTIFIER '(' AttrDefList ')' ';' ENDLINE
		   {
				std::cout << "create tb ";
				std::cout << $3.id << std::endl;
				std::cout << "Schema :" << std::endl;
				$5.schema.print();
				prompt();
		   }
		 | DESC IDENTIFIER ';' ENDLINE
		   {
				cout << "describe table ";
				cout << $2.id << endl;
				prompt();
		   }
		 | INS_INTO IDENTIFIER VALUES '(' ValueList ')' ';' ENDLINE
		   {		
		   		cout << "insert into table ";
				cout << $2.id << endl;
				cout << "values : " << endl;
				$5.printValues();
				prompt();
		   }
		 | DELETE FROM IDENTIFIER WHERE CondList ';' ENDLINE
		   {
				cout << "delete from table ";
				cout << $3.id << endl;
				$5.condition.print();
				prompt();
		   }
	   	 | error ENDLINE
	   	   {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
	   	   ;

AttrDefList :
		   AttrDefList ',' AttrDefItem
		   {
				if ($3.primaryKey.empty())
					$$.schema.add($3.schemaEntry);
				else
					$$.schema.setPrimary($3.primaryKey);
		   }
		 | AttrDefItem
		   {
				$$.schema = Schema();
				if ($1.primaryKey.empty())
					$$.schema.add($1.schemaEntry);
				else
					$$.schema.setPrimary($1.primaryKey);
		   }
		   ;

AttrDefItem :
		   IDENTIFIER Type '(' INTEGER ')' 
		   {
				$$.schemaEntry = SchemaEntry($1.id, $2.datatype, $4.length, 0);
				$$.primaryKey = "";
		   }
		 | IDENTIFIER Type '(' INTEGER ')' NOT NUL
		   {
				$$.schemaEntry = SchemaEntry($1.id, $2.datatype, $4.length, 1);
				$$.primaryKey = "";
		   }
		 | PRIMARY KEY '(' IDENTIFIER ')'
		   {
				$$.primaryKey = $4.id;
		   }
		   ;

Type :	   INT		{ $$.datatype = "int"; }
		 | CHAR		{ $$.datatype = "char"; }
		 | VCHAR 	{ $$.datatype = "varchar"; }
		 ;

ValueList :
		   ValueList ',' ValueItem
		   {
				$$.values.push_back($3.value);
		   }
		 | ValueItem
		   {
				cout << "ValueItem" << endl;
				$$.values.push_back($1.value);
		   }
		   ;

ValueItem :
		   INTEGER  { $$.value = Value(0, $1.length, ""); }
		 | LITERAL  { $$.value = Value(1, 0, $1.literal); }
		 ;

CondList :
		   CondList AND Cond
		   {
				$$.condition.add(Condition::AND, $3.condEntry);
		   }
		 | CondList OR Cond
		   {
				$$.condition.add(Condition::OR, $3.condEntry);
		   }
		 | Cond
		   {
				$$.condition = Condition($1.condEntry);
		   }
		 ;

Cond :
		   Expr '=' Expr
		   {
				$$.condEntry = CondEntry(CondEntry::EQUAL, $1.expr, $3.expr);
		   }
		 | Expr '>' Expr
		   {
				$$.condEntry = CondEntry(CondEntry::GREATER, $1.expr, $3.expr);
		   }
		 | Expr '<' Expr
		   {
				$$.condEntry = CondEntry(CondEntry::LESS, $1.expr, $3.expr);
		   }
		 ;

Expr :
	       Attr
		   {
				$$.expr = Expr(Expr::ATTR);
				$$.expr.attr = $1.attr;
		   }
		 | INTEGER
		   {
				$$.expr = Expr(Expr::INTEGER);
				$$.expr.integer = $1.length;
		   }
		 | LITERAL
		   {
				$$.expr = Expr(Expr::LITERAL);
				$$.expr.literal = $1.literal;
		   }
		 ;

Attr :
		   IDENTIFIER
		   {	
		   		$$.attr = Attr("", $1.id);
		   }
		 | IDENTIFIER '.' IDENTIFIER
		   {
				$$.attr = Attr($1.id, $3.id);
		   }
		 ;

%%

void prompt()
{
	if (isInterp)
	{
		std::cout << " sql> ";
	}
}

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
		prompt();
		yyparse();
	}
	return 0;
}
