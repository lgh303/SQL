#include <iostream>
#include "Condition.h"
#include "CondEntry.h"

using namespace std;

Condition::Condition(CondEntry& entry)
{
	 operands.push_back(entry);
}

void Condition::add(CondLogicOp op, CondEntry& entry)
{
	 operands.push_back(entry);
	 opcodes.push_back(op);
}

void Condition::clear()
{
	 operands.clear();
	 opcodes.clear();
}

void Condition::print()
{
	 if (operands.empty())
	 {
		  cout << "Empty Condition" << endl;
		  return;
	 }
	 cout << operands[0].toString();
	 for (int i = 0; i < opcodes.size(); ++i)
	 {
		  cout << " ";
		  switch (opcodes[i])
		  {
		  case AND :
			   cout << "AND";
			   break;
		  case OR :
			   cout << "OR";
			   break;
		  }
		  cout << " ";
		  cout << operands[i + 1].toString();
	 }
	 cout << endl;
}
