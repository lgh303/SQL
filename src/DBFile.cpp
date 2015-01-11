#include "DBFile.h"
#include "DBBufManager.h"
#include "DBUtility.h"
#include "DBError.h"
#include "DBFileInfo.h"
#include "DBPageInfo.h"
#include "DBRecord.h"
#include "IndexManager.h"
#include "BTree.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

extern IndexManager* indexManager;

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
	//¸üÐÂcontent³¤¶È
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
	//ÉèÖÃºÃ¿Õ²ÛÁ´±í
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

//oper = 0ÎªÓë²Ù×÷£¬ oper = 1Îª»ò²Ù×÷
//style = 0ÎªµÈÓÚ£¬style = 1Îª´óÓÚ£¬ style = 2ÎªÐ¡ÓÚ
int DBFile::SearchRecord(char** keyattr, int* style, int* oper, char** keyword, int paranum, vector< pair<int, int> >& re)
{
	//µÚÒ»²½£º»ñÈ¡ÊôÐÔÆ«ÒÆÁ¿
	DBAttribute* key = new DBAttribute[paranum];
	DBAttribute* keyright = new DBAttribute[paranum];
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
		if(style[j] == 3 || style[j] == 4 || style[j] == 5)
        {
            bool hit = false;
            for(int i = 0;i < fileinfo->attrNum;i++)
            {
                if(strcmp(fileinfo->attr[i].name, keyword[j]) == 0)
                {
                    hit = true;
                    keyright[j] = fileinfo->attr[i];
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
	}

	if (paranum == 1 &&(style[0] == 0 || style[0] == 1 || style[0] == 2))
	{
		 int attrpos = -1;
		 for(int w = 0;w < fileinfo->attrNum;w++)
			  if(strcmp(fileinfo->attr[w].name, keyattr[0]) == 0)
			  {
				   attrpos = w;
				   break;
			  }
		 if(attrpos == -1)
		 {
			  DBPrintErrorPos("Search");
			  DBPrintError(NOSUCHATTR);
			  return NOSUCHATTR;
		 }
		 if (fileinfo->attr[attrpos].isPrimary)
		 {
			  string attr_name(fileinfo->attr[attrpos].name);
			  string tbname = fileinfo->fname;
			  BTree *tree = indexManager->getBTree(tbname + "." + attr_name);
			  if (tree)
			  {
				   cout << "BTree Searching " << tbname << '.' << attr_name << endl;
				   if (fileinfo->attr[attrpos].type == 0) // String
						re = tree->search_zone(string(keyword[0]), style[0]);
				   else // Digit
						re = tree->search_zone(*(int*)keyword[0], style[0]);
				   return DBOK;
			  }
		 }
	}

	//µÚ¶þ²½£ºÈ«ÎÄ¼þÉ¨Ãè£¨´Ë´¦¿ÉÓÃB+Ê÷×öÀ©³ä£©
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
						char* targetright = NULL;
						if(style[k]  > 2)
                            targetright = getRecord(i,j) + DBRECORDHEADER + keyright[k].offset;
						if(style[k] == 0)
                        {
                            if( (strcmp(target, keyword[k]) == 0 && key[k].type == 0) || (*(int*)target == *(int*)keyword[k] && key[k].type == 1))
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 1)
                        {
                             if( (strcmp(target, keyword[k]) > 0 && key[k].type == 0) || (*(int*)target > *(int*)keyword[k] && key[k].type == 1))
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 2)
                        {
                             if( (strcmp(target, keyword[k]) < 0 && key[k].type == 0) || (*(int*)target < *(int*)keyword[k] && key[k].type == 1))
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 3)
                        {
                            if(strcmp(target, targetright) == 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 4)
                        {
                            if(strcmp(target, targetright) > 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
                        else if(style[k] == 5)
                        {
                            if(strcmp(target, targetright) < 0)
                                judgement[k] = true;
                            else
                                judgement[k] = false;
                        }
					}
					if(paranum == 1)
					{
						 //属性名称：fileinfo->attr[pos].name
						 //文件在缓存管理系统的文件号: mybufmanager->SearchBuf(char* filename)
						 //获取文件：bufFile[fileid],这是一个指针
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

//¾¯¸æ£º´ËAddRecordº¯ÊýÊÇÎ´¾­¹ý¼ÇÂ¼ÕýÈ·ÐÔ¼ì²éµÄº¯Êý£¬Òò´Ë£¬ÔÚ²åÈëÖ®Ç°ÏµÍ³¹ÜÀíÄ£¿éÇëÎñ±Ø¼ì²é¼ÇÂ¼ÕýÈ·ÐÔ¡£
int DBFile::AddRecord(char* record, int length)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	//¼ÇÂ¼³¤¶ÈÅÐ¶Ï
	if(length != fileinfo->recordLength)
	{
		DBPrintErrorPos("Add record");
		DBPrintError(RECORDLENGTHERROR);
		return RECORDLENGTHERROR;
	}
	//Ö÷¼üÅÐ¶Ï
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
		priword[0] = new char[fileinfo->attr[primary].length];
		memcpy(priword[0], primaryword, fileinfo->attr[primary].length);
		int* style = new int[1];
		style[0] = 0;
		int res = SearchRecord(attrname, style, NULL,  priword, 1, searchResult);
		if(res < 0)
			return res;
		if(searchResult.size() > 0)
		{
			DBPrintErrorPos("Add record");
			DBPrintError(PRIMARYKEYERROR);
			return PRIMARYKEYERROR;
		}
	}
	//¼ÇÂ¼²åÈë
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

	indexManager->insertRecord(fileinfo, record, pageid, rid);

	return DBOK;
}

int DBFile::DeleteRecord(int pageid, int rid)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	DBPageInfo* pageinfo = ((DBPageInfo*)getPage(pageid));
	char* recordinfo = getRecord(pageid, rid);
	DBRecordHeader* recordheader = (DBRecordHeader*)recordinfo;
	//Ò³Ô½½çÅÐ¶Ï
	if(pageid >= fileinfo->pageNum || pageid < 0)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(PAGEIDOVERFLOW);
		return PAGEIDOVERFLOW;
	}
	//¼ÇÂ¼Ô½½çÅÐ¶Ï
	if(rid >= pageinfo->slotNum || rid < 0)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(RIDOVERFLOW);
		return RIDOVERFLOW;
	}
	//¼ÇÂ¼Îª¿ÕÅÐ¶Ï
	if(recordheader->isNull)
	{
		DBPrintErrorPos("Delete Record");
		DBPrintError(RECORDNOTEXIST);
		return RECORDNOTEXIST;
	}
	//Case 1:±¾Ò³ÒÑÂúÊ±É¾³ý£¬Ðè¸üÐÂ±¾Ò³¿Õ²ÛÁ´±íºÍÈ«ÎÄ¼þÎ´ÂúÒ³Á´±í
	if(pageinfo->firstEmptySlot == -1)
	{
		pageinfo->nextEmptyPage = fileinfo->firstNotFullPageId;
		fileinfo->firstNotFullPageId = pageid;
	}
	//Case 2:±¾Ò³Î´ÂúÊ±É¾³ý£¬Ö»Ðè¸üÐÂ±¾Ò³µÄ¿Õ²ÛÁ´±í
	recordheader->isNull = true;
	recordheader->nextEmptySlot = pageinfo->firstEmptySlot;
	pageinfo->firstEmptySlot = rid;

	indexManager->deleteRecord(fileinfo, getRecord(pageid, rid) + DBRECORDHEADER);

	return DBOK;
}

int DBFile::UpdateRecord(char* keyattr, char* keyword, int pageid, int rid)
{
	DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
	DBPageInfo* pageinfo = ((DBPageInfo*)getPage(pageid));
	char* recordinfo = getRecord(pageid, rid);
	DBRecordHeader* recordheader = (DBRecordHeader*)recordinfo;
	//Ò³Ô½½çÅÐ¶Ï
	if(pageid >= fileinfo->pageNum || pageid < 0)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(PAGEIDOVERFLOW);
		return PAGEIDOVERFLOW;
	}
	//¼ÇÂ¼Ô½½çÅÐ¶Ï
	if(rid >= pageinfo->slotNum || rid < 0)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(RIDOVERFLOW);
		return RIDOVERFLOW;
	}
	//¼ÇÂ¼Îª¿ÕÅÐ¶Ï
	if(recordheader->isNull)
	{
		DBPrintErrorPos("Update Record");
		DBPrintError(RECORDNOTEXIST);
		return RECORDNOTEXIST;
	}
	//Ö÷¼üÖØ¸´²éÕÒ
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
			int* style = new int[1];
            style[0] = 0;
			int re = SearchRecord(attrname, style, NULL, priword, 1, result);
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
	//ÉÏÊöÇé¿ö¾ù²»Âú×ã£¬Ôò¸üÐÂ
	int target = -1;
	for(int i = 0;i<fileinfo->attrNum;i++)
	{
		if(strcmp(keyattr, fileinfo->attr[i].name) == 0)
		{
			target = i;
			break;
		}
	}
	//Î´ÕÒµ½¸ÃÊôÐÔ
	if(target == -1)
	{
		DBPrintErrorPos("Update record");
		DBPrintError(NOSUCHATTR);
		return NOSUCHATTR;
	}

	char *old_val = recordinfo + DBRECORDHEADER + fileinfo->attr[target].offset;
	indexManager->updateRecord(fileinfo, keyattr, old_val, keyword);
	
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
//        for(int j = 0;j<space[i] - strlen(fileinfo->attr[attrindex[i]].name);j++)
            cout<<"\t";
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
//                for(int j = 0;j<space[i] - strlen(wordpos);j++)
                    cout<<"\t";
                cout<<"|";
            }
        }
        cout<<endl;
    }
    return DBOK;
}

//mode: 0 for sum, 1 for avg, 2 for max, 3 for min
//resultflag: 0 for literal, 1 for integer
int DBFile::calculate(vector< pair<int, int> > rlist, char* attrname, int mode, int& resultflag, int& resultInteger, char* &resultLiteral)
{
    DBFileInfo* fileinfo = (DBFileInfo*)(fileheader.header);
    int attrpos = -1;
    for(int i = 0;i<fileinfo->attrNum;i++)
    {
        if(strcmp(attrname, fileinfo->attr[i].name) == 0)
        {
            attrpos = i;
            break;
        }
    }
    if(attrpos == -1)
    {
        DBPrintErrorPos("Calculate");
        DBPrintError(NOSUCHATTR);
        return NOSUCHATTR;
    }
    if(fileinfo->attr[attrpos].type == 0 && (mode == 0 || mode == 1))
    {
        DBPrintErrorPos("Calculate");
        DBPrintError(CALCULATETYPEERROR);
        return CALCULATETYPEERROR;
    }
    if(rlist.size() == 0)
    {
        DBPrintErrorPos("Calculate");
        DBPrintError(NORECORDMATCH);
        return NORECORDMATCH;
    }
    vector< pair<int, int> >::iterator iter = rlist.begin();
    resultInteger = 0;
    resultLiteral = new char[fileinfo->attr[attrpos].length];
    resultflag = fileinfo->attr[attrpos].type;
    if(fileinfo->attr[attrpos].type == 0)
        memcpy(resultLiteral, getRecord(iter->first, iter->second) + fileinfo->attr[attrpos].offset + DBRECORDHEADER, fileinfo->attr[attrpos].length);
    else
        resultInteger = *((int*)(getRecord(iter->first, iter->second) + fileinfo->attr[attrpos].offset + DBRECORDHEADER));
    for(;iter != rlist.end();iter++)
    {
        if(iter == rlist.begin())
            continue;
        char* wordpos = getRecord(iter->first, iter->second) + fileinfo->attr[attrpos].offset + DBRECORDHEADER;
        if(mode == 0 || mode == 1)
            resultInteger += (*((int*)wordpos));
        else if(mode == 2)
        {
            resultInteger = max(resultInteger,  (*((int*)wordpos)));
            if(strcmp(resultLiteral, wordpos) < 0)
                memcpy(resultLiteral, wordpos, strlen(wordpos) + 1);
        }
        else if(mode == 3)
        {
            resultInteger = min(resultInteger,  (*((int*)wordpos)));
            if(strcmp(resultLiteral, wordpos) > 0)
                memcpy(resultLiteral, wordpos, strlen(wordpos) + 1);
        }
    }
    if(mode == 1)
        resultInteger /= rlist.size();
    return DBOK;
}


