#ifndef __SCHEMA_ENTRY_H__
#define __SCHEMA_ENTRY_H__

#include <string>

using std::string;

class SchemaEntry
{
public:
	 SchemaEntry() {}
	 SchemaEntry(string& f, string& t, int len, int notN)
		  : field(f), type(t), length(len)
	 {
		  notNull = notN;
		  keykind = 0;
	 }
	 string field;
	 string type;
	 int length;
	 bool notNull;
	 int keykind;
};

#endif // __SCHEMA_ENTRY_H__
