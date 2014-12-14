#ifndef __ATTR_H__
#define __ATTR_H__

#include <string>

using std::string;

class Attr
{
public:
	 Attr() {}
	 Attr(string tb, string at)
		  : tbname(tb), attrname(at) {}
	 string toString()
	 {
		  return tbname + "." + attrname;
	 }
	 string tbname;
	 string attrname;
};

#endif // __ATTR_H__
