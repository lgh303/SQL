#ifndef __B_NODE__
#define __B_NODE__

#include <string>
#include <vector>
#include <utility>

using std::pair;

class BNode
{
public:
	 enum NodeType{LEAF, STEM};
	 BNode(NodeType, int);
	 NodeType type;
	 int number;
	 // pair.second == -1 means it has been removed.
	 std::vector< pair<std::string, int> > values;
	 int pNextLeaf;
	 int pPreLeaf;
	 int pFirstNode;
	 int parent;
	 void sortValues();
	 static pair<int, int> toPRPair(int);
	 static int toBTreeValue(pair<int, int>);
	 static int MaxSize;
};

#endif // __B_NODE__
