#include <cstdio>
#include <string>
#include "IndexManager.h"
#include "BTree.h"

using namespace std;

IndexManager::IndexManager()
{
	 // for index_file
	 // 	  loadBTree(...)
	 // 	  trees.push_back
}

IndexManager::~IndexManager()
{
	 for (map<string, BTree*>::iterator it = trees.begin(); it != trees.end(); ++it)
		  delete it->second;
}

int IndexManager::createIndex(const string&)
{

}

int IndexManager::dropIndex(const string&)
{

}

void IndexManager::addBTree(const string& attr, BTree* tree)
{
	 trees.insert(make_pair(string(attr), tree));
}

BTree* IndexManager::loadBTree(const string&)
{

}

int IndexManager::storeBTree(const string& output, BTree* tree)
{
	 FILE *file = fopen(("index_" + output).c_str(), "wb");
	 if (!file) return -1;
	 int tree_data[3];
	 tree_data[0] = 0;
	 tree_data[1] = tree->root;
	 if (tree->type == BTree::STRING)
		  tree_data[2] = 0;
	 else 
		  tree_data[2] = 1;
	 fwrite(tree_data, sizeof(int), 3, file);
	 for (int i = 0; i < (tree->ptrs).size(); ++i)
	 {
		  BNode *node = (tree->ptrs)[i];
//		  if (node->type == NodeType::LEAF)
	 }
	 fclose(file);
}

BTree* IndexManager::getBTree(const string& key)
{
	 if (trees.count(key) <= 0)
		  return NULL;
	 return trees.at(key);
}
