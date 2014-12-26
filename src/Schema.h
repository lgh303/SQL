#ifndef __SCHEMA_H__
#define __SCHEMA_H__

#include <vector>
#include <string>
#include "SchemaEntry.h"
#include "Condition.h"

class Schema
{
public:
	 void print();
	 void process(SchemaEntry&);
	 int size() { return entries.size(); }
	 std::vector<SchemaEntry> entries;
	 Condition constrain;
};

#endif //__SCHEMA_H__
