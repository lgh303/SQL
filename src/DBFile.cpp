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
	//����content����
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
	//���úÿղ�����
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

//oper = 0Ϊ������� oper = 1Ϊ�����
//style = 0Ϊ���ڣ�style = 1Ϊ���ڣ� style = 2ΪС��
int DBFile::SearchRecord(char** keyattr, int* style, int* oper, char** keyword, int paranum, vector< pair<int, int> >& re)
{
	//��һ������ȡ����ƫ����
	DBAttribute* key = new DBAttribute[paranum];
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	for(int j = 0;j<paranum;j++)
	{
		bool hit = false;
		for(int i = 0;i < fileinfo->attrNum;i++)
		{
			if(strcmp(fileinfo->attr[i].name, keyattr[j]) == 0)
			{
				hit = true;
				key[j] = fileinfo->attr[i];
				break;
			}
		}
		if(!hit)
		{
			DBPrintErrorPos("Search Record");
			DBPrintError(NOSUCHATTRIBUTE);
			return NOSUCHATTRIBUTE;
		}
	}
	//�ڶ�����ȫ�ļ�ɨ�裨�˴�����B+�������䣩
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
					bool* judgement = new bool[paranum];
					for(int k = 0;k<paranum;k++)
					{
						char* target = getRecord(i, j) + DBRECORDHEADER + key[k].offset;
						if(style[k] == 0)
                        {
                            if( strcmp(target, keyword[k]) == 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 1)
                        {
                             if( strcmp(target, keyword[k]) > 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 2)
                        {
                             if( strcmp(target, keyword[k]) < 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
					}
					if(paranum == 1)
					{
						if(judgement[0])
							re.push_back(make_pair(i,j));
					}
					else
					{
						bool expression = judgement[0];
						for(int k = 0;k<paranum - 1;k++)
						{
							if(oper[k] == 0)
								expression = expression && judgement[k+1];
							else if(oper[k] == 1)
								expression = expression || judgement[k+1];
						}
						if(expression)
							re.push_back(make_pair(i,j));
					}
				}
			}
		}
	}
	return DBOK;
}

//���棺��AddRecord������δ������¼��ȷ�Լ��ĺ�������ˣ��ڲ���֮ǰϵͳ����ģ������ؼ���¼��ȷ�ԡ�
int DBFile::AddRecord(char* record, int length)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	//��¼�����ж�
	if(length != fileinfo->recordLength)
	{
		DBPrintErrorPos("Add record");
		DBPrintError(RECORDLENGTHERROR);
		return RECORDLENGTHERROR;
	}
	//�����ж�
	int primary = -1;
	for(int i = 0;i<fileinfo->attrNum;i++)
	{
		if(fileinfo->attr[i].isPrimary)
		{
			primary = i;
			break;
		}
	}
	if(primary != -1)
	{
		char* primaryword = new char[fileinfo->attr[primary].length];
		memcpy(primaryword, record + fileinfo->attr[primary].offset, fileinfo->attr[primary].length);
		vector< pair<int, int> > searchResult;
		char** attrname = new char*[1];
		attrname[0] = fileinfo->attr[primary].name;
		char** priword = new char*[1];
		priword[0] = primaryword;
		int res = SearchRecord(attrname, NULL,  priword, 1, searchResult);
		if(res < 0)
			return res;
		if(searchResult.size() > 0)
		{
			DBPrintErrorPos("Add record");
			DBPrintError(PRIMARYKEYERROR);
			return PRIMARYKEYERROR;
		}
	}
	//��¼����
	int pageid = fileinfo->firstNotFullPageId;
	if(pageid == -1)
	{
		int re = CreatePage();
		if(re != DBOK)
			return re;
		fileinfo->firstNotFullPageId = fileinfo->pageNum - 1;
		pageid = fileinfo->pageNum - 1;
	}
	DBPageInfo* pageinfo = (DBPageInfo*)(getPage(pageid));
	int rid = pageinfo->firstEmptySlot;
	char* recordinfo = getRecord(pageid, rid);
	memcpy(recordinfo + DBRECORDHEADER, record, length);
	((DBRecordHeader*)recordinfo)->isNull = false;
	pageinfo = (DBPageInfo*)(getPage(pageid));
	pageinfo->isNull = false;
	pageinfo->firstEmptySlot = ((DBRecordHeader*)recordinfo)->nextEmptySlot;
	fileinfo->isEmpty = false;
	if(pageinfo->firstEmptySlot == -1)
	{
		fileinfo->firstNotFullPageId = pageinfo->nextEmptyPage;
	}
	return DBOK;
}

int DBFile::DeleteRecord(int pageid, int rid)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	DBPageInfo* pageinfo = ((DBPageInfo*)getPage(pageid));
	char* recordinfo = getRecord(pageid, rid);
	DBRecordHeader* recordheader = (DBRecordHeader*)recordinfo;
	//ҳԽ���ж�
	if(pageid >= fileinfo->pageNum || pageid < 0)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(PAGEIDOVERFLOW);
		return PAGEIDOVERFLOW;
	}
	//��¼Խ���ж�
	if(rid >= pageinfo->slotNum || rid < 0)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(RIDOVERFLOW);
		return RIDOVERFLOW;
	}
	//��¼Ϊ���ж�
	if(recordheader->isNull)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(RECORDNOTEXIST);
		return RECORDNOTEXIST;
	}
	//Case 1:��ҳ����ʱɾ��������±�ҳ�ղ������ȫ�ļ�δ��ҳ����
	if(pageinfo->firstEmptySlot == -1)
	{
		pageinfo->nextEmptyPage = fileinfo->firstNotFullPageId;
		fileinfo->firstNotFullPageId = pageid;
	}
	//Case 2:��ҳδ��ʱɾ����ֻ����±�ҳ�Ŀղ�����
	recordheader->isNull = true;
	recordheader->nextEmptySlot = pageinfo->firstEmptySlot;
	pageinfo->firstEmptySlot = rid;

	return DBOK;
}

int DBFile::UpdateRecord(char* keyattr, char* keyword, int pageid, int rid)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	DBPageInfo* pageinfo = ((DBPageInfo*)getPage(pageid));
	char* recordinfo = getRecord(pageid, rid);
	DBRecordHeader* recordheader = (DBRecordHeader*)recordinfo;
	//ҳԽ���ж�
	if(pageid >= fileinfo->pageNum || pageid < 0)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(PAGEIDOVERFLOW);
		return PAGEIDOVERFLOW;
	}
	//��¼Խ���ж�
	if(rid >= pageinfo->slotNum || rid < 0)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(RIDOVERFLOW);
		return RIDOVERFLOW;
	}
	//��¼Ϊ���ж�
	if(recordheader->isNull)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(RECORDNOTEXIST);
		return RECORDNOTEXIST;
	}
	//�����ظ�����
	int primary = -1;
	for(int i = 0;i<fileinfo->attrNum;i++)
	{
		if(fileinfo->attr[i].isPrimary)
		{
			primary = i;
			break;
		}
	}
	if(primary != -1)
	{
		if(strcmp(fileinfo->attr[primary].name, keyattr) == 0)
		{
			vector< pair<int, int> > result;
			char** attrname = new char*[1];
			attrname[0] = keyattr;
			char** priword = new char*[1];
			priword[0] = keyword;
			int re = SearchRecord(attrname, NULL, priword, 1, result);
			if(re < 0)
				return re;
			if(result.size() > 0)
			{
				DBPrintErrorPos("Update record");
				DBPrintError(PRIMARYKEYERROR);
				return PRIMARYKEYERROR;
			}
		}
	}
	//��������������㣬�����
	int target = -1;
	for(int i = 0;i<fileinfo->attrNum;i++)
	{
		if(strcmp(keyattr, fileinfo->attr[i].name) == 0)
		{
			target = i;
			break;
		}
	}
	//δ�ҵ�������
	if(target == -1)
	{
		DBPrintErrorPos("Update record");
		DBPrintError(NOSUCHATTR);
		return NOSUCHATTR;
	}
	memcpy(recordinfo + DBRECORDHEADER + fileinfo->attr[target].offset, keyword, fileinfo->attr[target].length);
	return DBOK;
}

int DBFile::show(vector< pair<int, int> >rlist, vector<int>attrindex)
{
    DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
    int* space = new int[attrindex.size()];
    for(int i = 0;i<attrindex.size();i++)
        space[i] = (fileinfo->attr[attrindex[i]].length > ATTRLENGTHMAX ? fileinfo->attr[attrindex[i]].length : ATTRLENGTHMAX);
    for(int i = 0;i<attrindex.size();i++)
    {
        cout<<fileinfo->attr[attrindex[i]].name;
        for(int j = 0;j<space[i] - strlen(fileinfo->attr[attrindex[i]].name);j++)
            cout<<" ";
        cout<<"|";
    }
    cout<<endl;
    vector< pair<int, int> >::iterator iter = rlist.begin();
    for(;iter != rlist.end();iter++)
    {
        char* pos = getRecord(iter->first, iter->second);
        if(((DBRecordHeader*)pos)->isNull)
            cout<<"-----Invalid Search-----";
        else
        {
            for(int i = 0;i<attrindex.size();i++)
            {
                char* wordpos = pos + DBRECORDHEADER + fileinfo->attr[attrindex[i]].offset;
                if(fileinfo->attr[attrindex[i]].type == 0)
                    cout<<wordpos;
                else
                    cout<<*((int*)wordpos);
                for(int j = 0;j<space[i] - strlen(wordpos);j++)
                    cout<<" ";
                cout<<"|";
            }
        }
        cout<<endl;
    }
    return DBOK;
}


