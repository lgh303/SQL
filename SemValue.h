#ifndef __SEM_VALUE_H__
#define __SEM_VALUE_H__

#include <string>

class SemValue
{
public:
	 int code;
	 std::string id;
	 std::string dbname;
	 static int keyword(int);
	 static int identifier(std::string);
private:
};

#endif // __SEM_VALUE_H__
