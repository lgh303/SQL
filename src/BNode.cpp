#include "BNode.h"
#include <utility>
#include <algorithm>

using namespace std;

int BNode::MaxSize = 50;

BNode::BNode(NodeType _type, int _number)
	 : type(_type), number(_number)
{
}

pair<int, int> BNode::toPRPair(int value)
{
	 int pageNumber = value >> 10;
	 int recordNumber = value & ((1 << 10) - 1);
	 return make_pair(pageNumber, recordNumber);
}

int BNode::toBTreeValue(pair<int, int> valuepair)
{
	 return (valuepair.first << 10) + valuepair.second;
}

bool digit_cmp(const pair<string, int>& px, const pair<string, int>& py)
{
	 int dx = atoi(px.first.c_str());
	 int dy = atoi(py.first.c_str());
	 return (dx < dy);
}

void BNode::sortValues(bool is_string)
{
	 if (is_string)
		  sort(values.begin(), values.end());
	 else
		  sort(values.begin(), values.end(), digit_cmp);
}

