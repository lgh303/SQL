#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	 vector<int> v1;
	 for (int i = 0; i < 10; ++i)
		  v1.push_back(i);
	 vector<int> v2;
	 v2.assign(v1.begin() + 4, v1.end());
	 v1.erase(v1.begin() + 4, v1.end());
	 printf("%d\n", v1.size());
	 for (int i = 0; i < v1.size(); ++i)
		  printf("%d ", v1[i]);
	 printf("\n");
	 printf("%d\n", v2.size());
	 for (int i = 0; i < v2.size(); ++i)
		  printf("%d ", v2[i]);
	 printf("\n");
	 printf("%d\n", v1.front());
	 printf("%d\n", v1.back());
}
