#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	 vector< pair<int, int> > v;
	 v.push_back(make_pair(5, 3));
	 v.push_back(make_pair(6, 4));
	 v.push_back(make_pair(9, 9));
	 v.push_back(make_pair(1, 1));
	 v.push_back(make_pair(4, 8));
	 sort(v.begin(), v.end());
	 for (int i = 0; i < v.size(); ++i)
		  printf("%d %d\n", v[i].first, v[i].second);
}
