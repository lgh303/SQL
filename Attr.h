#ifndef __ATTR_H__
#define __ATTR_H__

#include <string>

using std::string;

class Attr
{
public:
	 enum Aggr {NONE, SUM, AVG, MAX, MIN};
	 Attr() {}
	 Attr(string tb, string at)
		  : tbname(tb), attrname(at) {}
	 string toString()
	 {
		  string str = tbname + "." + attrname;
		  switch (aggr)
		  {
		  case NONE :
			   break;
		  case SUM :
			   str += "(SUM) ";
			   break;
		  case AVG :
			   str += "(AVG) ";
			   break;
		  case MAX :
			   str += "(MAX) ";
			   break;
		  case MIN :
			   str += "(MIN) ";
			   break;
		  }
		  return str;
	 }
	 string tbname;
	 string attrname;
	 Aggr aggr;
};

#endif // __ATTR_H__
