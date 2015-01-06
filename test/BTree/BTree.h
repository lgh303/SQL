#ifndef __B_TREE__
#define __B_TREE__

#include <string>
#include <vector>
#include <utility>
#include "BNode.h"

using std::pair;
using std::string;

class BTree
{
public:
	 enum KeyType { DIGIT, STRING };
	 int root;
	 KeyType type;
	 
	 BTree(KeyType _type);
	 ~BTree();

	 /*
	  * return -1 if not found else 0.
	  */
	 pair<int, int> search(int);
	 pair<int, int> search(const string&);

	 /*
	  * return -1 if key is duplicate else 0
	  */
	 int insert(int, pair<int, int>);
	 int insert(const string&, pair<int, int>);

	 /*
	  * return -1 if not found else 0
	  */
	 int remove(int);
	 int remove(const string&);

	 void print(int);

private:
	 std::vector<BNode*> ptrs;
	 
	 pair<int, int> _search(const string&);
	 int _insert(const string&, pair<int, int>);
	 int _remove(const string&);
	 
	 int searchleaf(const string&, int);
	 BNode* splitLeaf(BNode*);
	 BNode* splitStem(BNode*);
	 void insertStem(BNode*, BNode*, const string&);
	 void tracedown(BNode*);
};

#endif // __B_TREE__
