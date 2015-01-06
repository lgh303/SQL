#include "BTree.h"
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

pair<int, int> data[100];
int main()
{
	 BTree *tree = new BTree(BTree::STRING);
	 srand(time(NULL));
	 int times = 23;
	 for (int i = 0; i < times; ++i)
		  data[i] = make_pair(i, i * 2);
	 for (int t = 0; t < times / 2; ++t)
	 {
		  int x = rand() % times;
		  int y = rand() % times;
		  pair<int, int> tmp = data[x];
		  data[x] = data[y];
		  data[y] = tmp;
	 }
	 for (int i = 0; i < times; ++i)
	 {
		  char buf[32];
		  sprintf(buf, "%c%c~", 'a' + data[i].first, 'a' + data[i].first + 1);
		  tree->insert(buf, data[i]);
	 }

	 for (int i = 5; i < 20; ++i)
	 {
	 	  char buf[32];
	 	  sprintf(buf, "%c%c~", 'a' + i, 'a' + i + 1);
	 	  tree->remove(buf);
	 }
	 for (int i = 10; i < 15; ++i)
	 {
	 	  char buf[32];
	 	  sprintf(buf, "%c%c~", 'a' + i, 'a' + i + 1);
	 	  tree->insert(buf, make_pair(i + 1, i + 3));
	 }

	 for (int i = 0; i < times; ++i)
	 {
	 	  char buf[32];
	 	  sprintf(buf, "%c%c~", 'a' + i, 'a' + i + 1);
	 	  pair<int, int> ret = tree->search(buf);
	 	  printf("%c : %d %d\n", i + 'a', ret.first, ret.second);
	 }

	 char buf[32];
	 sprintf(buf, "%c%c~", 'a' + 12, 'a' + 12 + 1);
	 printf("Start from : %s\n", buf);
	 vector< pair<int, int> > ret = tree->search_zone(buf, 2);
	 for (int i = 0; i < ret.size(); ++i)
	 {
		  printf("%d %d\n", ret[i].first, ret[i].second);
	 }

	 tree->print(tree->root);
	 delete tree;
}
