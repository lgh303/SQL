#ifndef __SCHEMA_H__
#define __SCHEMA_H__

#include <vector>
#include <string>
#include "SchemaEntry.h"

class Schema
{
public:
	 void setPrimary(std::string&);
	 void print();
	 void add(SchemaEntry&);
	 int size() { return entries.size(); }
private:
	 std::vector<SchemaEntry> entries;
};

#endif //__SCHEMA_H__
