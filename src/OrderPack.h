#ifndef __ORDER_PACK__
#define __ORDER_PACK__

#include <string>
#include <vector>
#include "Schema.h"
#include "Value.h"
#include "Condition.h"
#include "Attr.h"

using std::string;

class OrderPack
{
public:
	 enum OrderType {CREATE_DB, DROP_DB, USE, CREATE_TB, DROP_TB, SHOWDBS, SHOWTBS, DESC, INSERT, DELETE, UPDATE, SELECT, CREATE_INDEX, DROP_INDEX};

	 OrderType type;
	 string dbname;
	 string tbname;
	 Schema schema;

	 std::vector<Value> values;
	 bool allAttrs;
	 std::vector<Attr> attrs;
	 std::vector<string> tables;
	 Condition condition;
	 Attr groupbyAttr;

	 string updateAttr;
	 Value updateValue;
	 string indexAttr;

	 OrderPack(OrderType _type)
		  : type(_type) {}
	 void process();
};

#endif // __ORDER_PACK__
