#include "DBFile.h"
#include "DBBufManager.h"
#include "DBUtility.h"
#include "DBError.h"
#include "DBFileInfo.h"
#include "DBPageInfo.h"
#include "DBRecord.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


DBFileHeader::DBFileHeader()
{
	header = new char[DBFILEHEADER];
	memset(header, 0, DBFILEHEADER);
}

DBFile::DBFile()
{
	content = NULL;
}

int DBFile::CreatePage()
{
	//更新content长度
	DBFileInfo* newfileinfo = (DBFileInfo*)(fileheader.header);
	int orglength = newfileinfo->pageNum * DBPAGE;
	if(orglength > 0)
	{
		char* tmp = new char[orglength];
		memcpy(tmp, content, orglength); 
		content = new char[orglength + DBPAGE];
		memset(content, 0, orglength + DBPAGE);
		memcpy(content, tmp, orglength);
	}
	else
		content = new char[DBPAGE];

	DBPage* newpage = new DBPage();
	DBPageInfo* newpageinfo = (DBPageInfo*)(newpage->header.header);
	newpageinfo->firstEmptySlot = 0;
	newpageinfo->isNull = true;
	newpageinfo->nextEmptyPage = -1;
	newpageinfo->pageID = newfileinfo->pageNum + 1;
	if(newfileinfo->recordLength == 0)
	{
		DBPrintErrorPos("Create Page");
		DBPrintError(NOTSETFILEHEADER);
		return NOTSETFILEHEADER;
	}
	newpageinfo->slotNum = (DBPAGE - DBPAGEHEADER) / (newfileinfo->recordLength + DBRECORDHEADER);
	//设置好空槽链表
	for(int i = 0;i<newpageinfo->slotNum;i++)
	{
		DBRecordHeader* recordheader = (DBRecordHeader*)(newpage->pagecontent + i * (newfileinfo->recordLength + DBRECORDHEADER));
		recordheader->nextEmptySlot = ((i == newpageinfo->slotNum - 1) ? -1 : (i + 1));
		recordheader->isNull = true;
	}
	memcpy(content+orglength, newpage->header.header, DBPAGEHEADER);
	memcpy(content+orglength+DBPAGEHEADER, newpage->pagecontent, DBPAGE - DBPAGEHEADER);

	if(newfileinfo->firstNotFullPageId == -1)
		newfileinfo->firstNotFullPageId = newpageinfo->pageID;
	if(newfileinfo->isEmpty)
		newfileinfo->isEmpty = false;
	newfileinfo->pageNum += 1;
	return DBOK;
}

char* DBFile::getPage(int page)
{
	return content + page * DBPAGE;
}

char* DBFile::getRecord(int page, int rid)
{
	return content + DBPAGEHEADER + page * DBPAGE + rid * (DBRECORDHEADER + ((DBFileInfo*)(fileheader.header))->recordLength);
}

int DBFile::SearchRecord(char* keyattr, char* keyword, vector< pair<int, int> >& result)
{
	//第一步：获取属性偏移量
	DBAttribute key;
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	bool hit = false;
	for(int i = 0;i < fileinfo->attrNum;i++)
	{
		if(strcmp(fileinfo->attr[i].name, keyattr) == 0)
		{
			hit = true;
			key = fileinfo->attr[i];
			break;
		}
	}
	if(!hit)
	{
		DBPrintErrorPos("Search Record");
		DBPrintError(NOSUCHATTRIBUTE);
		return NOSUCHATTRIBUTE;
	}
	//第二步：全文件扫描（此处可用B+树做扩充）
	int pagecnt = ((DBFileInfo*)(fileheader.header))->pageNum;
	int slotcnt = (DBPAGE - DBPAGEHEADER) / (((DBFileInfo*)(fileheader.header))->recordLength + DBRECORDHEADER);
	for(int i = 0;i<pagecnt;i++)
	{
		if( !(((DBPageInfo*)(getPage(i)))->isNull) )
		{
			for(int j = 0;j<slotcnt;j++)
			{
				if( !(((DBRecordHeader*)(getRecord(i, j)))->isNull) )
				{
					char* target = getRecord(i, j) + DBRECORDHEADER + key.offset;
					if( strcmp(target, keyword) == 0)
						result.push_back(make_pair(i, j));
				}
			}
		}
	}
	return DBOK;
}

//警告：此AddRecord函数是未经过记录正确性检查的函数，因此，在插入之前系统管理模块请务必检查记录正确性。
int DBFile::AddRecord(char* record, int length)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	//记录长度判断
	if(length != fileinfo->recordLength)
	{
		DBPrintErrorPos("Add record");
		DBPrintError(RECORDLENGTHERROR);
		return RECORDLENGTHERROR;
	}
	//主键判断
	int primary;
	for(int i = 0;i<fileinfo->attrNum;i++)
	{
		if(fileinfo->attr[i].isPrimary)
		{
			primary = i;
			break;
		}
	}
	char* primaryword = new char[fileinfo->attr[primary].length];
	memcpy(primaryword, record + fileinfo->attr[primary].offset, fileinfo->attr[primary].length);
	vector< pair<int, int> > searchResult;
	int res = SearchRecord(fileinfo->attr[primary].name, primaryword, searchResult);
	if(res < 0)
		return res;
	if(searchResult.size() > 0)
	{
		DBPrintErrorPos("Add record");
		DBPrintError(PRIMARYKEYERROR);
		return PRIMARYKEYERROR;
	}
	//记录插入
	int pageid = fileinfo->firstNotFullPageId;
	if(pageid == -1)
	{
		int re = CreatePage();
		if(re != DBOK)
			return re;
		pageid = 0;
		fileinfo->firstNotFullPageId = 0;
	}
	DBPageInfo* pageinfo = (DBPageInfo*)(getPage(pageid));
	int rid = pageinfo->firstEmptySlot;
	if(rid == -1)
	{
		int re = CreatePage();
		if(re != DBOK)
			return re;
		pageid += 1;
		rid = 0;
		fileinfo->firstNotFullPageId = pageid;
	}
	char* recordinfo = getRecord(pageid, rid);
	memcpy(recordinfo + DBRECORDHEADER, record, length);
	((DBRecordHeader*)recordinfo)->isNull = false;
	pageinfo = (DBPageInfo*)(getPage(pageid));
	pageinfo->isNull = false;
	pageinfo->pageID = pageid;
	pageinfo->firstEmptySlot = ((DBRecordHeader*)recordinfo)->nextEmptySlot;
	fileinfo->isEmpty = false;
	return DBOK;
}

int DBFile::DeleteRecord(int pageid, int rid)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	DBPageInfo* pageinfo = ((DBPageInfo*)getPage(pageid));
	char* recordinfo = getRecord(pageid, rid);
	((DBRecordHeader*)recordinfo)->isNull = true;
	((DBRecordHeader*)recordinfo)->nextEmptySlot = pageinfo->firstEmptySlot;
	return 0;
}


