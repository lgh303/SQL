#ifndef __B_TREE__
#define __B_TREE__

#include <vector>
#include <utility>
#include "BNode.h"

using std::pair;

class BTree
{
public:
	 int root;
	 pair<int, int> search(int);
	 int insert(int, pair<int, int>);
	 void print(int);
	 ~BTree();
private:
	 std::vector<BNode*> ptrs;
	 int searchleaf(int, int);
	 BNode* splitLeaf(BNode*);
	 BNode* splitStem(BNode*);
	 void insertStem(BNode*, BNode*, int);
	 void tracedown(BNode*);
};

#endif // __B_TREE__
