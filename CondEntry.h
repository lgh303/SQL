#ifndef __COND_ENTRY_H__
#define __COND_ENTRY_H__

#include <string>
#include "Expr.h"

class CondEntry
{
public:
	 enum CondArithOp {EQUAL, GREATER, LESS, IS, LIKE};
	 CondEntry() {}
	 CondEntry(CondArithOp o, Expr l, Expr r)
		  : op(o), left(l), right(r) {}
	 std::string toString()
	 {
		  std::string str("(");
		  switch (op)
		  {
		  case EQUAL :
			   str += left.toString();
			   str += " = ";
			   str += right.toString();
			   break;
		  case GREATER :
			   str += left.toString();
			   str += " > ";
			   str += right.toString();
			   break;
		  case LESS :
			   str += left.toString();
			   str += " < ";
			   str += right.toString();
			   break;
		  case IS :
			   str += left.toString();
			   str += " IS ";
			   str += "NULL";
			   break;
		  case LIKE :
			   str += left.toString();
			   str += " LIKE ";
			   str += mode;
			   break;
		  }
		  str += ")";
		  return str;
	 }
	 CondArithOp op;
	 Expr left, right;
	 std::string mode;
};

#endif // __COND_ENTRY_H__
