#include "BNode.h"
#include <utility>
#include <algorithm>

using namespace std;

int BNode::MaxSize = 4;

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

void BNode::sortValues()
{
	 sort(values.begin(), values.end());
}
		  
