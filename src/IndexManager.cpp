#include <cstdio>
#include <string>
#include <cstring>
#include "IndexManager.h"
#include "DBFileInfo.h"
#include "BTree.h"

using namespace std;

IndexManager::~IndexManager()
{
	 for (map<string, BTree*>::iterator it = trees.begin(); it != trees.end(); ++it)
		  delete it->second;
}

void IndexManager::addBTree(const string& tree_name, BTree* tree)
{
	 trees.insert(make_pair(string(tree_name), tree));
}

int IndexManager::removeBTree(const string& tree_name)
{
	 BTree *tree = getBTree(tree_name);
	 if (tree)
	 {
		  delete tree;
		  trees.erase(tree_name);
		  return 0;
	 }
	 return -1;
}

int IndexManager::storeIndex(const string& output, BTree* tree)
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
	 fclose(file);
}

BTree* IndexManager::getBTree(const string& key)
{
	 if (trees.count(key) <= 0)
		  return NULL;
	 return trees.at(key);
}

int IndexManager::insertRecord(DBFileInfo* fileinfo, char* record, int pid, int rid)
{
	 int pos = -1;
	 for (int i = 0; i < fileinfo->attrNum; ++i)
		  if (fileinfo->attr[i].isPrimary)
		  {
			   pos = i;
			   break;
		  }
	 if (pos == -1) return 0;
	 string tbname = fileinfo->fname;
	 string priAttr = fileinfo->attr[pos].name;
	 BTree *tree = getBTree(tbname + "." + priAttr);
	 if (!tree) return 0;
	 int offset = fileinfo->attr[pos].offset;
	 char* vPos = record + offset;
	 int type = fileinfo->attr[pos].type;
	 int ret = -1;
	 if (type == 0) // String
		  ret = tree->insert(string(vPos), make_pair(pid, rid));
	 else // DIGIT
		  ret = tree->insert(*(int*)vPos, make_pair(pid, rid));
	 return ret;
}

int IndexManager::deleteRecord(DBFileInfo* fileinfo, char* record)
{
	 int pos = -1;
	 for (int i = 0; i < fileinfo->attrNum; ++i)
		  if (fileinfo->attr[i].isPrimary)
		  {
			   pos = i;
			   break;
		  }
	 if (pos == -1) return 0;
	 string tbname = fileinfo->fname;
	 string priAttr = fileinfo->attr[pos].name;
	 BTree *tree = getBTree(tbname + "." + priAttr);
	 if (!tree) return 0;
	 int offset = fileinfo->attr[pos].offset;
	 char* vPos = record + offset;
	 int type = fileinfo->attr[pos].type;
	 int ret = -1;
	 if (type == 0) // String
		  ret = tree->remove(string(vPos));
	 else // DIGIT
		  ret = tree->remove(*(int*)vPos);
	 return ret;
}

int IndexManager::updateRecord(DBFileInfo* fileinfo, char* attr, char* old_key, char* new_key)
{
	 int pos = -1;
	 for (int i = 0; i < fileinfo->attrNum; ++i)
		  if (fileinfo->attr[i].isPrimary && strcmp(attr, fileinfo->attr[i].name) == 0)
		  {
			   pos = i;
			   break;
		  }
	 if (pos == -1) return 0;
	 string tbname = fileinfo->fname;
	 string priAttr = fileinfo->attr[pos].name;
	 BTree *tree = getBTree(tbname + "." + priAttr);
	 if (!tree) return 0;
	 int type = fileinfo->attr[pos].type;
	 if (type == 0) // String
	 {
		  pair<int, int> value = tree->search(string(old_key));
		  tree->remove(string(old_key));
		  tree->insert(string(new_key), value);
	 }
	 else // DIGIT
	 {
		  pair<int, int> value = tree->search(*(int*)old_key);
		  tree->remove(*(int*)old_key);
		  tree->insert(*(int*)new_key, value);
	 }
	 return 0;
}
