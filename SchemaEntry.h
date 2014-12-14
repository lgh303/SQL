#ifndef __SCHEMA_ENTRY_H__
#define __SCHEMA_ENTRY_H__

#include "Condition.h"
#include <string>

using std::string;

class SchemaEntry
{
public:
	 enum EntryKind {NORMAL, PRIMARY, CHECK, FOREIGN};
	 SchemaEntry() {}
	 SchemaEntry(string& f, string& t, int len, int notN)
		  : field(f), type(t), length(len)
	 {
		  notNull = notN;
	 }
	 string field;
	 string type;
	 int length;
	 bool notNull;
	 bool isPrimary;
	 bool isForeign;
	 bool hasConstrain;
	 EntryKind entrykind;
	 string primaryKey;
	 Condition constrain;
};

#endif // __SCHEMA_ENTRY_H__
