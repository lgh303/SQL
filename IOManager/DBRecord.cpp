#include "DBRecord.h"
#include "DBUtility.h"
#include <iostream>
using namespace std;

DBRecordHeader::DBRecordHeader()
{
	isNull = true;
	nextEmptySlot = 0;
}

DBRecord::DBRecord()
{
	record = NULL;
}

DBRecord::DBRecord(int size)
{
	record = new char[size];
	memset(record, 0, size);
}
