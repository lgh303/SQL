#ifndef __VALUE_H__
#define __VALUE_H__

#include <string>

class Value
{
public:
	 Value() {}
	 Value(int t, int i, std::string s)
		  : type(t), integer(i), literal(s) {}
	 int type;//integer for 0, string for 1
	 int integer;
	 std::string literal;
};

#endif // __VALUE_H__
