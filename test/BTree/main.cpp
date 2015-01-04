#include "BTree.h"
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

pair<int, int> data[100];
int main()
{
	 BTree *tree = new BTree();
	 srand(time(NULL));
	 int times = 30;
	 for (int i = 0; i < times; ++i)
		  data[i] = make_pair(i * 2, i * 3);
	 for (int t = 0; t < times / 2; ++t)
	 {
		  int x = rand() % times;
		  int y = rand() % times;
		  pair<int, int> tmp = data[x];
		  data[x] = data[y];
		  data[y] = tmp;
	 }
	 for (int i = 0; i < times; ++i)
		  tree->insert(data[i].first / 2, data[i]);
	 tree->print(tree->root);
	 pair<int, int> ret = tree->search(8);
	 printf("%d %d\n", ret.first, ret.second);
	 delete tree;
}

