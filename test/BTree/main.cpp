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

	 for (int i = 5; i < 25; ++i)
		  tree->remove(i);
	 for (int i = 15; i < 20; ++i)
		  tree->insert(i, make_pair(i + 1, i + 3));

	 for (int i = 0; i < times; ++i)
	 {
		  pair<int, int> ret = tree->search(i);
		  printf("%d : %d %d\n", i, ret.first, ret.second);
	 }
	 tree->print(tree->root);
	 delete tree;
}

