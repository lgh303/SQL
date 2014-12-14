#ifndef __SEM_VALUE_H__
#define __SEM_VALUE_H__

#include <string>
#include "Schema.h"

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
	 string primaryKey;

	 static int keyword(int);
};

#endif // __SEM_VALUE_H__
