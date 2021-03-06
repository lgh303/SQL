#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "CondEntry.h"
#include <vector>

class Condition
{
public:
	 enum CondLogicOp {AND, OR};
	 Condition() {}
	 Condition(CondEntry&);
	 void add(CondLogicOp, CondEntry&);
	 void print();
	 void clear();
	 bool empty();
public:
	 std::vector<CondEntry> operands;
	 std::vector<CondLogicOp> opcodes;
};

#endif // __CONDITION_H__
