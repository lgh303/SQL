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

int IndexManager::createIndex(const string&)
{

}

int IndexManager::dropIndex(const string&)
{

}

BTree* IndexManager::loadBTree(const string&)
{

}

int IndexManager::storeBTree(const string& output, BTree* tree)
{
	 FILE *file = fopen(output.c_str(), "wb");
	 if (!file) return -1;
	 int tree_data[2];
	 tree_data[0] = 0;
	 if (tree->type == BTree::STRING)
		  tree_data[0] = 1;
	 tree_data = tree->root;
	 fwrite(data, sizeof(int), 2, file);
	 for (int i = 0; i < (tree->ptrs).size(); ++i)
	 {
		  BNode *node = (tree->ptrs)[i];
		  if (node->type == NodeType::LEAF)
	 }
	 fclose(file);
}
