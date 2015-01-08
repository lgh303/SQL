#ifndef __INDEX_MANAGER__
#define __INDEX_MANAGER__

#include <string>
#include <map>
#include "BTree.h"

class IndexManager
{
	 std::map<std::string, BTree*> trees;
public:
	 IndexManager();
	 ~IndexManager();
	 BTree* loadBTree(const std::string&);
	 int storeBTree(const std::string&, BTree*);
	 int createIndex(const std::string&);
	 int dropIndex(const std::string&);
	 void addBTree(const std::string&, BTree*);
	 BTree* getBTree(const std::string& key) { return trees.at(key); }
};

#endif // __INDEX_MANAGER__
