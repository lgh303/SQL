#ifndef __B_TREE__
#define __B_TREE__

#include <string>
#include <vector>
#include <utility>
#include "BNode.h"

using std::pair;
using std::string;

class IndexManager;

class BTree
{
	 friend class IndexManager;
public:
	 enum KeyType { DIGIT, STRING };
	 int root;
	 KeyType type;
	 
	 BTree(KeyType _type);
	 ~BTree();

	 /*
	  * return -1 if not found, else 0.
	  */
	 pair<int, int> search(int);
	 pair<int, int> search(const string&);
	 std::vector< pair<int, int> > search_zone(int, int);
	 std::vector< pair<int, int> > search_zone(const string&, int);
	 

	 /*
	  * return -1 if key is duplicate, else 0
	  */
	 int insert(int, pair<int, int>);
	 int insert(const string&, pair<int, int>);

	 /*
	  * return -1 if not found, else 0
	  */
	 int remove(int);
	 int remove(const string&);

	 void print(int);

private:
	 std::vector<BNode*> ptrs;
	 
	 pair<int, int> _search(const string&);
	 std::vector< pair<int, int> > _search_zone(const string&, int);
	 int _insert(const string&, pair<int, int>);
	 int _remove(const string&);

	 std::vector< pair<int, int> > _search_greater(const string&);
	 std::vector< pair<int, int> > _search_less(const string&);
	 int searchleaf(const string&, int);
	 BNode* splitLeaf(BNode*);
	 BNode* splitStem(BNode*);
	 void insertStem(BNode*, BNode*, const string&);
	 void tracedown(BNode*);
};

#endif // __B_TREE__
