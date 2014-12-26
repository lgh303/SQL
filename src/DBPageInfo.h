#ifndef __DBPAGEINFO_H__
#define __DBPAGEINFO_H__

using namespace std;
class DBPageInfo
{
public:
	bool isNull;
	int firstEmptySlot;
	int pageID;
	int slotNum;
	int nextEmptyPage;
};

#endif