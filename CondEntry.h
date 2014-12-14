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
		  str += left.toString();
		  switch (op)
		  {
		  case EQUAL :
			   str += " = ";
			   break;
		  case GREATER :
			   str += " > ";
			   break;
		  case LESS :
			   str += " < ";
			   break;
		  case IS :
			   str += " IS ";
			   break;
		  case LIKE :
			   str += " LIKE ";
			   break;
		  }
		  str += right.toString();
		  str += ")";
		  return str;
	 }
	 CondArithOp op;
	 Expr left, right;
};

#endif // __COND_ENTRY_H__
