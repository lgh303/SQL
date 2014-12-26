#ifndef __DBPAGE_H__
#define __DBPAGE_H__

class DBPageHeader
{
public:
	char* header;
public:
	DBPageHeader();
};

class DBPage
{
public:
	DBPageHeader header;
	char* pagecontent;
public:
	DBPage();
};

#endif