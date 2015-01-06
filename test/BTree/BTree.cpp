#include "BTree.h"
#include "BNode.h"
#include <vector>
#include <utility>

#include <iostream>

using namespace std;

BTree::~BTree()
{
	 for (int i = 0; i < ptrs.size(); ++i)
		  delete ptrs[i];
}

pair<int, int> BTree::search(int keyword)
{
	 if (ptrs.empty())
		  return make_pair(-1, -1);
	 int leafnumber = searchleaf(keyword, root);
	 BNode *pLeaf = ptrs[leafnumber];
	 for (int i = 0; i < pLeaf->values.size(); ++i)
		  if (keyword == pLeaf->values[i].first && pLeaf->values[i].second != -1)
			   return BNode::toPRPair(pLeaf->values[i].second);
	 return make_pair(-1, -1);
}

int BTree::insert(int keyword, pair<int, int> valuepair)
{
	 int value = BNode::toBTreeValue(valuepair);
	 if (ptrs.empty())
	 {
		  root = 0;
		  BNode *pNode = new BNode(BNode::LEAF, 0);
		  pNode->parent = -1;
		  pNode->values.push_back(make_pair(keyword, value));
		  pNode->pNextLeaf = -1;
		  ptrs.push_back(pNode);
		  return 0;
	 }
	 int leafnumber = searchleaf(keyword, root);
	 BNode *pLeaf = ptrs[leafnumber];
	 for (int i = 0; i < pLeaf->values.size(); ++i)
		  if (keyword == pLeaf->values[i].first && pLeaf->values[i].second != -1)
			   return -1;

	 bool found_removed_key = false;
	 for (int i = 0; i < pLeaf->values.size(); ++i)
		  if (pLeaf->values[i].second == -1)
		  {
			   found_removed_key = true;
			   pLeaf->values[i].first = keyword;
			   pLeaf->values[i].second = value;
			   break;
		  }
	 if (!found_removed_key)
		  pLeaf->values.push_back(make_pair(keyword, value));
	 pLeaf->sortValues();
	 if (pLeaf->values.size() > BNode::MaxSize)
	 {
		  BNode* newleaf = splitLeaf(pLeaf);
		  int upwards = newleaf->values.front().first;
		  insertStem(pLeaf, newleaf, upwards);
	 }
	 return 0;
}

int BTree::searchleaf(int keyword, int number)
{
	 BNode* pNode = ptrs[number];
	 if (pNode->type == BNode::LEAF)
		  return pNode->number;
	 if (keyword < pNode->values.front().first)
		  return searchleaf(keyword, pNode->pFirstNode);
	 for (int i = 0; i < pNode->values.size() - 1; ++i)
		  if (keyword >= pNode->values[i].first && keyword < pNode->values[i + 1].first)
			   return searchleaf(keyword, pNode->values[i].second);
	 return searchleaf(keyword, pNode->values.back().second);
}

BNode* BTree::splitLeaf(BNode *oldleaf)
{
	 int newnumber = ptrs.size();
	 BNode *newleaf = new BNode(BNode::LEAF, newnumber);
	 newleaf->parent = oldleaf->parent;
	 newleaf->pNextLeaf = oldleaf->pNextLeaf;
	 oldleaf->pNextLeaf = newnumber;
	 int lsize = (BNode::MaxSize + 1) >> 1;
	 newleaf->values.assign(oldleaf->values.begin() + lsize, oldleaf->values.end());
	 oldleaf->values.erase(oldleaf->values.begin() + lsize, oldleaf->values.end());
	 ptrs.push_back(newleaf);
	 return newleaf;
}

BNode* BTree::splitStem(BNode *oldstem)
{
	 int newnumber = ptrs.size();
	 BNode *newstem = new BNode(BNode::STEM, newnumber);
	 newstem->parent = oldstem->parent;
	 int rsize = (BNode::MaxSize + 1) >> 1;
	 int lsize = (BNode::MaxSize + 1) - rsize;
	 newstem->values.assign(oldstem->values.begin() + lsize, oldstem->values.end());
	 oldstem->values.erase(oldstem->values.begin() + lsize, oldstem->values.end());
	 newstem->pFirstNode = oldstem->values.back().second;
	 ptrs.push_back(newstem);
	 return newstem;
}

void BTree::insertStem(BNode *oldleaf, BNode* newleaf, int upwards)
{
	 int parentIndex = oldleaf->parent;
	 if (parentIndex == -1)
	 {
		  BNode *newstem = new BNode(BNode::STEM, ptrs.size());
		  newstem->parent = -1;
		  newstem->pFirstNode = oldleaf->number;
		  newstem->values.push_back(make_pair(upwards, newleaf->number));
		  root = ptrs.size();
		  ptrs.push_back(newstem);
		  tracedown(newstem);
		  return;
	 }
	 BNode *pParent = ptrs[parentIndex];
	 pParent->values.push_back(make_pair(upwards, newleaf->number));
	 pParent->sortValues();
	 if (pParent->values.size() > BNode::MaxSize)
	 {
		  BNode *newstem = splitStem(pParent);
		  insertStem(pParent, newstem, pParent->values.back().first);
		  pParent->values.pop_back();
	 }
	 else
		  tracedown(pParent);
}

void BTree::tracedown(BNode *pParent)
{
	 if (pParent->type == BNode::LEAF)
		  return;
	 BNode *node = ptrs[pParent->pFirstNode];
	 node->parent = pParent->number;
	 for (int i = 0; i < pParent->values.size(); ++i)
	 {
		  node = ptrs[pParent->values[i].second];
		  node->parent = pParent->number;
		  tracedown(node);
	 }
}

void BTree::print(int index)
{
	 BNode *pNode = ptrs[index];
	 if (pNode->type == BNode::LEAF)
	 {
		  cout << pNode->number << " | ";
		  for (int i = 0; i < pNode->values.size(); ++i)
			   cout << "(" << pNode->values[i].first << "," << pNode->values[i].second << ") ";
		  cout << " | " << pNode->pNextLeaf;
		  cout << endl;
	 }
	 else
	 {
		  cout << pNode->number << " >> ";
		  cout << pNode->pFirstNode << ' ';
		  for (int i = 0; i < pNode->values.size(); ++i)
		  {
			   cout << '(' << pNode->values[i].first << ',' << pNode->values[i].second << ')' << ' ';
		  }
		  cout << endl;
		  print(pNode->pFirstNode);
		  for (int i = 0; i < pNode->values.size(); ++i)
			   print(pNode->values[i].second);
	 }
}

int BTree::remove(int keyword)
{
	 if (ptrs.empty())
		  return -1;
	 int leafnumber = searchleaf(keyword, root);
	 BNode *pLeaf = ptrs[leafnumber];
	 for (int i = 0; i < pLeaf->values.size(); ++i)
		  if (keyword == pLeaf->values[i].first && pLeaf->values[i].second != -1)
		  {
			   pLeaf->values[i].second = -1;
			   return 0;
		  }
	 return -1;
}
