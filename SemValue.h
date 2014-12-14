#ifndef __SEM_VALUE_H__
#define __SEM_VALUE_H__

#include <string>
#include <vector>
#include "Schema.h"
#include "SchemaEntry.h"
#include "Value.h"

using std::string;

class SemValue
{
public:
	 int code;
	 string id;
	 string literal;
	 string datatype;
	 int length;
	 Schema schema;
	 SchemaEntry schemaEntry;
	 std::vector<Value> values;
	 Value value;
	 string primaryKey;

	 void printValues();
	 static int keyword(int);
};

#endif // __SEM_VALUE_H__
