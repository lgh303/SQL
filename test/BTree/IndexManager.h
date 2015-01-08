#ifndef __INDEX_MANAGER__
#define __INDEX_MANAGER__

#include <string>
#include <map>
#include "BTree.h"

class IndexManager
{
	 std::map<std::string, BTree*> trees;
	 BTree* loadBTree(const std::string&);
	 int storeBTree(const std::string&, BTree*);
public:
	 IndexManager();
	 int createIndex(const std::string&);
	 int dropIndex(const std::string&);
};

#endif // __INDEX_MANAGER__
