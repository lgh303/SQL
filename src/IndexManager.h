#ifndef __INDEX_MANAGER__
#define __INDEX_MANAGER__

#include <string>
#include <map>
#include "BTree.h"

class IndexManager
{
	 std::map<std::string, BTree*> trees;
public:
	 ~IndexManager();
	 int storeIndex(const std::string&, BTree*);
	 void addBTree(const std::string&, BTree*);
	 int removeBTree(const std::string&);
	 BTree* getBTree(const std::string&);
};

#endif // __INDEX_MANAGER__
