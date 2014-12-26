#ifndef __DBFILEINFO_H__
#define __DBFILEINFO_H__

#include "DBUtility.h"

class DBAttribute
{
public:
	char name[ATTRLENGTHMAX];
	char foreignKeyFileName[ATTRLENGTHMAX];
	char foreignKeyAttr[ATTRLENGTHMAX];
	int length;
	int offset;
	int type;
	bool isNull;
	bool isPrimary;
	bool isForeign;
	DBAttribute()
	{
		for(int i = 0;i<ATTRLENGTHMAX;i++)
		{
			name[i] = 0;
			foreignKeyFileName[i] = 0;
			foreignKeyAttr[i] = 0;
		}
		length = 0;
		offset = 0;
		type = 0;
		isNull = false;
		isPrimary = false;
		isForeign = false;
	}
};

class DBFileInfo
{
public:
	int recordLength;
	int attrNum;
	DBAttribute attr[ATTRMAX];
	int firstNotFullPageId;
	int pageNum;
	bool isEmpty;
public:
	DBFileInfo():recordLength(0),attrNum(0),firstNotFullPageId(-1),pageNum(0),isEmpty(true)
	{
		for(int i = 0;i<ATTRMAX;i++)
			attr[i] = DBAttribute();
	}
};

#endif