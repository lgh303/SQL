#ifndef __EXPR_H__
#define __EXPR_H__

#include <string>
#include "Attr.h"

class Expr
{
public:
	 enum ExprType {ATTR, INTEGER, LITERAL};
     Expr(ExprType t = Expr::INTEGER)
		  : type(t) {}
	 std::string toString()
	 {
		  std::string str = "";
		  switch (type)
		  {
		  case ATTR :
			   str += attr.toString();
			   break;
		  case INTEGER :
			   str += "Integer";
			   break;
		  case LITERAL :
			   str += literal;
			   break;
		  }
		  return str;
	 }
	 ExprType type;
	 int integer;
	 std::string literal;
	 Attr attr;
};

#endif // __EXPR_H__
