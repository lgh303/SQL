%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include <unistd.h>
	#include "DBFileManager.h"
	#include "DBBufManager.h"
	#include "IndexManager.h"
	#include "DBFile.h"
	#include "SemValue.h"
	#include "OrderPack.h"
	#define YYSTYPE SemValue
	void yyerror(const char*);
	void prompt();
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
	using namespace std;

	DBFileManager* myfilemanager = NULL;
	DBBufManager *mybufmanager = NULL;
	IndexManager *indexManager = NULL;
%}

%token INTEGER IDENTIFIER LITERAL
%token ENDLINE QUIT
%token CREATE DB DBS DROP USE SHOW TB TBS INDEX DESC
%token NOT IS NUL IN PRIMARY FOREIGN KEY CHECK REFER
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
                mybufmanager->AllWriteback();
				delete mybufmanager;
				delete myfilemanager;
				delete indexManager;
				exit(0);
           }
	   	 | CREATE DB IDENTIFIER ';' ENDLINE
		   {
				OrderPack pack(OrderPack::CREATE_DB);
				pack.dbname = $3.id;
				pack.process();
				/* std::cout << "create db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
		 | DROP DB IDENTIFIER ';' ENDLINE
		   {
				OrderPack pack(OrderPack::DROP_DB);
				pack.dbname = $3.id;
				pack.process();
				/* std::cout << "drop db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
		 | USE IDENTIFIER ';' ENDLINE
		   {
				OrderPack pack(OrderPack::USE);
				pack.dbname = $2.id;
				pack.process();
				/* std::cout << "use db "; */
				/* std::cout << $2.id << std::endl; */
				prompt();
		   }
        | SHOW DBS ';' ENDLINE
        {
                OrderPack pack(OrderPack::SHOWDBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
        }
		 | SHOW TBS ';' ENDLINE
		   {
				OrderPack pack(OrderPack::SHOWTBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
		   }
		 | CREATE TB IDENTIFIER '(' AttrDefList ')' ';' ENDLINE
		   {
				OrderPack pack(OrderPack::CREATE_TB);
				pack.tbname = $3.id;
				pack.schema = $5.schema;
				pack.process();
				/* std::cout << "create tb "; */
				/* std::cout << $3.id << std::endl; */
				/* std::cout << "Schema :" << std::endl; */
				/* $5.schema.print(); */
				prompt();
		   }
		 | DROP TB IDENTIFIER ';' ENDLINE
  		   {
				OrderPack pack(OrderPack::DROP_TB);
				pack.tbname = $3.id;
				pack.process();
				/* std::cout << "drop tb "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
		 | DESC IDENTIFIER ';' ENDLINE
		   {
				OrderPack pack(OrderPack::DESC);
				pack.tbname = $2.id;
				pack.process();
				/* cout << "describe table "; */
				/* cout << $2.id << endl; */
				prompt();
		   }
		 | INS_INTO IDENTIFIER VALUES '(' ValueList ')' ';' ENDLINE
		   {
				OrderPack pack(OrderPack::INSERT);
				pack.tbname = $2.id;
				pack.values = $5.values;
				pack.process();
		   		/* cout << "insert into table "; */
				/* cout << $2.id << endl; */
				/* cout << "values : " << endl; */
				/* $5.printValues(); */
				prompt();
		   }
		 | DELETE FROM IDENTIFIER WhereClause ';' ENDLINE
		   {
				OrderPack pack(OrderPack::DELETE);
				pack.tbname = $3.id;
				pack.condition = $4.condition;
				pack.process();
				/* cout << "delete from table "; */
				/* cout << $3.id << endl; */
				/* $4.condition.print(); */
				prompt();
		   }
		 | SELECT AttrList FROM TableList WhereClause GroupClause ';' ENDLINE
		   {
				OrderPack pack(OrderPack::SELECT);
				pack.allAttrs = $2.allAttrs;
				pack.attrs = $2.attrList;
				pack.tables = $4.tableList;
				pack.condition = $5.condition;
				pack.groupbyAttr = $6.attr;
				pack.process();
				/* cout << "select from table " << endl; */
				/* cout << "ATTR : "; */
				/* $2.printAttrs(); */
				/* cout << "TB : "; */
				/* $4.printTables(); */
				/* cout << "Cond : "; */
				/* $5.condition.print(); */
				/* cout << "GRP_BY : " << $6.attr.toString() << endl; */
				prompt();
		   }
		 | UPDATE IDENTIFIER SET IDENTIFIER '=' ValueItem WhereClause ';' ENDLINE
		   {
				OrderPack pack(OrderPack::UPDATE);
				pack.tbname = $2.id;
				pack.updateAttr = $4.id;
				pack.updateValue = $6.value;
				pack.condition = $7.condition;
				pack.process();
				/* cout << "update table " <<  endl; */
				/* cout << "TB : " << $2.id << endl; */
				/* cout << "ATTR : " << $4.id << endl; */
				/* cout << "VAL : "; */
				/* if ($6.value.type == 0) */
				/*    cout << $6.value.integer << endl; */
				/* else */
				/*    cout << $6.value.literal << endl; */
				/* $7.condition.print(); */
				prompt();
		   }
		 | CREATE INDEX IDENTIFIER '(' IDENTIFIER ')' ';' ENDLINE
		   {
				OrderPack pack(OrderPack::CREATE_INDEX);
				pack.tbname = $3.id;
				pack.indexAttr = $5.id;
				pack.process();
				/* cout << "create index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
		 | DROP INDEX IDENTIFIER '(' IDENTIFIER ')' ';' ENDLINE
		   {
				OrderPack pack(OrderPack::DROP_INDEX);
				pack.tbname = $3.id;
				pack.indexAttr = $5.id;
				pack.process();
				/* cout << "drop index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
	   	 | error ENDLINE
	   	   {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
	   	   ;

WhereClause :
		   /* empty */
		   {
				$$.condition.clear();
		   }
		 | WHERE CondList
		   {
		   		 $$.condition = $2.condition;
		   }
		 ;

GroupClause :
		   /* empty */
		   {
				$$.attr.clear();
		   }
		 | GRP_BY Attr
		   {
				$$.attr = $2.attr;
		   }
		 ;

AttrDefList :
		   AttrDefList ',' AttrDefItem
		   {
				$$.schema.process($3.schemaEntry);
		   }
		 | AttrDefItem
		   {
				$$.schema = Schema();
				$$.schema.process($1.schemaEntry);
		   }
		   ;

AttrDefItem :
		   IDENTIFIER Type '(' INTEGER ')'
		   {
				$$.schemaEntry = SchemaEntry($1.id, $2.datatype, $4.length, 0);
				$$.schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
		 | IDENTIFIER Type '(' INTEGER ')' NOT NUL
		   {
				$$.schemaEntry = SchemaEntry($1.id, $2.datatype, $4.length, 1);
				$$.schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
		 | PRIMARY KEY '(' IDENTIFIER ')'
		   {
				$$.schemaEntry.primaryKey = $4.id;
				$$.schemaEntry.entrykind = SchemaEntry::PRIMARY;
		   }
		 | CHECK '(' CondList ')'
		   {
				$$.schemaEntry.constrain = $3.condition;
				$$.schemaEntry.entrykind = SchemaEntry::CHECK;
		   }
		 | FOREIGN KEY '(' IDENTIFIER ')' REFER IDENTIFIER '(' IDENTIFIER ')'
		   {
				$$.schemaEntry.foreignKey = $4.id;
				$$.schemaEntry.foreignAttr = Attr($7.id, $9.id);
				$$.schemaEntry.entrykind = SchemaEntry::FOREIGN;
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
				$$.values.clear();
				$$.values.push_back($1.value);
		   }
		   ;

ValueItem :
		   INTEGER  { $$.value = Value(0, $1.length, ""); }
		 | LITERAL  { $$.value = Value(1, 0, $1.literal); }
		 | NUL {$$.value = Value(2, 0, "");}
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
		 | Attr IS NUL
		   {
				$$.condEntry = CondEntry();
				$$.condEntry.op = CondEntry::IS;
				$$.condEntry.left = Expr(Expr::ATTR);
				$$.condEntry.left.attr = $1.attr;
		   }
		 | Attr LIKE LITERAL
		   {
				$$.condEntry = CondEntry();
				$$.condEntry.op = CondEntry::LIKE;
				$$.condEntry.left = Expr(Expr::ATTR);
				$$.condEntry.left.attr = $1.attr;
				$$.condEntry.mode = $3.literal;
		   }
		 | Attr IN '(' ValueList ')'
		   {
				$$.condEntry = CondEntry();
				$$.condEntry.op = CondEntry::IN;
				$$.condEntry.left = Expr(Expr::ATTR);
				$$.condEntry.left.attr = $1.attr;
				$$.condEntry.values = $4.values;
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

AttrList :
		   '*'
		   {
				$$.allAttrs = true;
		   }
		 | AttrList ',' AttrAggr
		   {
				$$.allAttrs = false;
				$$.attrList.push_back($3.attr);
		   }
		 | AttrAggr
		   {
				$$.allAttrs = false;
				$$.attrList.clear();
				$$.attrList.push_back($1.attr);
		   }
		 ;
AttrAggr :
		   Attr
		   {
				$$.attr = $1.attr;
				$$.attr.aggr = Attr::NONE;
		   }
		 | SUM '(' Attr ')'
		   {
				$$.attr = $3.attr;
				$$.attr.aggr = Attr::SUM;
		   }
		 | AVG '(' Attr ')'
		   {
				$$.attr = $3.attr;
				$$.attr.aggr = Attr::AVG;
		   }
		 | MAX '(' Attr ')'
		   {
				$$.attr = $3.attr;
				$$.attr.aggr = Attr::MAX;
		   }
		 | MIN '(' Attr ')'
		   {
				$$.attr = $3.attr;
				$$.attr.aggr = Attr::MIN;
		   }
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

TableList :
		   TableList ',' IDENTIFIER
		   {
				$$.tableList.push_back($3.id);
		   }
		 | IDENTIFIER
		   {
				$$.tableList.clear();
				$$.tableList.push_back($1.id);
		   }

%%

void prompt()
{
	if (isInterp)
	{
		 std::cout << std::endl;
		std::cout << " sql> ";
	}
	else
	{
//		cout << "--------------" << endl;
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

	FILE *pFile = NULL;
	if (argc == 2)
	{
		pFile = fopen(argv[1], "r");
		if (!pFile)
		{
			std::cout << "Input File not Exist!" << std::endl;
			return -1;
		}
	}

	chdir("../db");

	myfilemanager = new DBFileManager();
	mybufmanager = new DBBufManager();
	indexManager = new IndexManager();
	tmpbuf = new DBFile();

	if (argc == 2)
	{
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
