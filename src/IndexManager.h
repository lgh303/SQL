#ifndef __INDEX_MANAGER__
#define __INDEX_MANAGER__

#include <string>
#include <map>
#include "BTree.h"
#include "DBFileInfo.h"

class IndexManager
{
	 std::map<std::string, BTree*> trees;
public:
	 ~IndexManager();
	 int storeIndex(const std::string&, BTree*);
	 void addBTree(const std::string&, BTree*);
	 int removeBTree(const std::string&);
	 BTree* getBTree(const std::string&);
	 int insertRecord(DBFileInfo*, char*, int, int);
	 int deleteRecord(DBFileInfo*, char*);
	 int updateRecord(DBFileInfo*, char*, char*, char*);
};

#endif // __INDEX_MANAGER__
