#ifndef __DBRECORD_H__
#define __DBRECORD_H__

class DBRecordHeader
{
public:
	int nextEmptySlot;
	bool isNull;
public:
	DBRecordHeader();
};

class DBRecord
{
public:
	DBRecordHeader header;
	char* record;
public:
	DBRecord();
	DBRecord(int size);
};

#endif