#include <cstring>
#include <iostream>
#include <vector>
#include "OrderPack.h"
#include "DBFile.h"
#include "DBFileManager.h"
#include "DBBufManager.h"
#include "DBPage.h"
#include "DBPageInfo.h"
#include "DBFileInfo.h"
#include "DBRecord.h"
#include "SchemaEntry.h"
#include "DBError.h"
#include "DBUtility.h"
#include "Global.h"
#include "Condition.h"
#include "CondEntry.h"
#include "Attr.h"
#include "Expr.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

static int enterDatabaseFlag = 0;

inline char* strtochar(string s)
{
	char* c = new char[s.length() + 1];
	for(int i = 0;i<s.length();i++)
		c[i] = s[i];
	c[s.length()] = '\0';
	return c;
}

void OrderPack::process()
{
	 switch (type)
	 {
    case CREATE_DB:
        {
             if(enterDatabaseFlag != 0)
             {
                 mybufmanager->AllWriteback();
                 chdir("..");
                 enterDatabaseFlag = 0;
             }
             int result = -1;
             char* curpath = new char[100];
             getcwd(curpath, 100);
             DIR *dir = opendir(curpath);
             // need to make sure dir != NULL
             for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
                 if (pDir->d_type != 8 && dbname == pDir->d_name)
                 {
                     result = 0;
                     break;
                 }
             closedir(dir);
             if(result == 0)
             {
                 DBPrintErrorPos("Create Database Resolution");
                 DBPrintError(DBEXISTS);
                 return;
             }
             mkdir(strtochar(dbname), 0777);
             break;
        }
	 case DROP_DB:
	     {
	         if(enterDatabaseFlag == 1)
             {
                 mybufmanager->AllWriteback();
                 chdir("..");
                 enterDatabaseFlag = 0;
             }
             //进入顶层文件夹
             int result = -1;
             char* curpath = new char[100];
             getcwd(curpath, 100);
             DIR *dir = opendir(curpath);
             // need to make sure dir != NULL
             for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
                 if (pDir->d_type != 8 && dbname == pDir->d_name)
                 {
                     result = 0;
                     break;
                 }
              closedir(dir);
              if(result == -1)
              {
                  DBPrintErrorPos("Use Database Resolution");
                  DBPrintError(DBNOTEXISTS);
                  return;
              }
              //进入待删除文件夹
              chdir(dbname.c_str());
              getcwd(curpath, 100);
              dir = opendir(curpath);
              // need to make sure dir != NULL
              for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
              {
                  if(pDir->d_type == 8)
                    myfilemanager->DestroyFile(pDir->d_name);
              }
              closedir(dir);
              //继续返回主文件夹
              chdir("..");
              //删除已空的db文件夹
              rmdir(dbname.c_str());
	     }
		 break;
	 case USE:
	     {
              if(enterDatabaseFlag != 0)
              {
                  mybufmanager->AllWriteback();
                  chdir("..");
                  enterDatabaseFlag = 0;
              }
              int result = -1;
              char* curpath = new char[100];
              getcwd(curpath, 100);
              DIR *dir = opendir(curpath);
              // need to make sure dir != NULL
              for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
                  if (pDir->d_type != 8 && dbname == pDir->d_name)
                  {
                      result = 0;
                      break;
                  }
              closedir(dir);
              if(result == -1)
              {
                  DBPrintErrorPos("Use Database Resolution");
                  DBPrintError(DBNOTEXISTS);
                  return;
              }
             chdir(strtochar(dbname));
             enterDatabaseFlag = 1;
             break;
	     }
	 case CREATE_TB:
	     {
	         if(enterDatabaseFlag == 0)
             {
                 DBPrintErrorPos("Create Table Resolution");
                 DBPrintError(CREATEFILEPATHERROR);
                 return;
             }
             //创建文件
             myfilemanager->CreateFile(strtochar(tbname));
             //更改文件头
             DBFileInfo* fileinfo = new DBFileInfo();
             fileinfo->attrNum = schema.size();
             int recordlength = 0;
             for(int i = 0;i<schema.size();i++)
             {
                 fileinfo->attr[i].isForeign = schema.entries[i].isForeign;
                 fileinfo->attr[i].isNull = ~schema.entries[i].notNull;
                 fileinfo->attr[i].isPrimary = schema.entries[i].isPrimary;
                 fileinfo->attr[i].length = ((schema.entries[i].type == "int") ? 5 : schema.entries[i].length + 1);
                 if(schema.entries[i].field.length() >= 32)
                 {
                     DBPrintErrorPos("Create Table Resolution");
                     DBPrintError(ATTRNAMETOOLONG);
                     return;
                 }
                 strcpy(fileinfo->attr[i].name, strtochar(schema.entries[i].field));
                 fileinfo->attr[i].offset = recordlength;
                 recordlength += fileinfo->attr[i].length;
                 if(schema.entries[i].type == "int")
                     fileinfo->attr[i].type = 1;//int
                 else
                     fileinfo->attr[i].type = 0;//char or varchar
                 if(fileinfo->attr[i].isForeign)
                 {
                     if(schema.entries[i].foreignAttr.attrname.length() >= 32)
                     {
                         DBPrintErrorPos("Create Table Resolution");
                         DBPrintError(FOREIGNATTRNAMETOOLONG);
                         return;
                     }
                     strcpy(fileinfo->attr[i].foreignKeyAttr, strtochar(schema.entries[i].foreignAttr.attrname));
                     if(schema.entries[i].foreignAttr.tbname.length() >= 32)
                     {
                         DBPrintErrorPos("Create Table Resolution");
                         DBPrintError(FOREIGNFILENAMETOOLONG);
                         return;
                     }
                     strcpy(fileinfo->attr[i].foreignKeyFileName, strtochar(schema.entries[i].foreignAttr.tbname));
                 }
             }
             fileinfo->recordLength = recordlength;
             int err = myfilemanager->setFileHeader(fileinfo, strtochar(tbname));
             if(err < 0)
                return;
             int fileid = mybufmanager->SearchBuf(strtochar(tbname));
             mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
             break;
	     }
	 case DROP_TB:
	     {
	         myfilemanager->DestroyFile(strtochar(tbname));
             break;
	     }
     case SHOWDBS:
        {
             if(enterDatabaseFlag == 1)
             {
                 mybufmanager->AllWriteback();
                 chdir("..");
                 enterDatabaseFlag = 0;
             }
              char* curpath = new char[100];
             getcwd(curpath, 100);
             DIR *dir = opendir(curpath);
             // need to make sure dir != NULL
             cout<<endl;
             for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
                 if (pDir->d_type != 8 && pDir->d_name[0] != '.')
                  {
                      cout<<" "<<pDir->d_name<<endl;
                  }
             cout<<endl;
             closedir(dir);
             break;
        }
	 case SHOWTBS:
	     {
	         if(enterDatabaseFlag == 0)
             {
                 DBPrintErrorPos("Show Tables Resolution");
                 DBPrintError(DBNOTCHOOSE);
                 return;
             }
             char* curpath = new char[100];
             getcwd(curpath, 100);
             DIR *dir = opendir(curpath);
             // need to make sure dir != NULL
             cout<<endl;
             for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
                 if (pDir->d_type == 8)
                  {
                      cout<<" "<<pDir->d_name<<endl;
                  }
             cout<<endl;
             closedir(dir);
	         break;
	     }
	 case DESC:
	     {
	         int err = myfilemanager->OpenFile(strtochar(tbname));
	         if(err < 0)
                return;
             int fileid = mybufmanager->SearchBuf(strtochar(tbname));
             DBFileInfo* fileinfo = new DBFileInfo();
             fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
             vector< pair<int, int> > searchid;
             vector<int> searchattr;
             for(int i = 0;i<fileinfo->attrNum;i++)
                searchattr.push_back(i);
             for(int i = 0;i<fileinfo->pageNum;i++)
                for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
                    if(!((DBRecordHeader*)(bufFile[fileid]->getRecord(i, j)))->isNull)
                        searchid.push_back(make_pair(i, j));
             cout<<endl;
             bufFile[fileid]->show(searchid, searchattr);
             cout<<endl;
            break;
	     }
	 case INSERT:
	     {
             int err = myfilemanager->OpenFile(strtochar(tbname));
             if(err < 0)
                return;
             int fileid = mybufmanager->SearchBuf(strtochar(tbname));
             DBFileInfo* fileinfo = new DBFileInfo();
             fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
             char* record = new char[fileinfo->recordLength];
             if(values.size() != fileinfo->attrNum)
             {
                 DBPrintErrorPos("Insert Record Resolution");
                 DBPrintError(ATTRNUMNOTEQUAL);
                 return;
             }
             for(int i = 0;i<fileinfo->attrNum;i++)
             {
                 if(values[i].type == 0)
                    memcpy(record + fileinfo->attr[i].offset, (char*)(&values[i].integer), 4);
                 else
                    memcpy(record + fileinfo->attr[i].offset, strtochar(values[i].literal), values[i].literal.length() + 1);
             }
             bufFile[fileid]->AddRecord(record, fileinfo->recordLength);
             break;
	     }
	 case DELETE:
	     {
	         int err = myfilemanager->OpenFile(strtochar(tbname));
             if(err < 0)
                return;
             int fileid = mybufmanager->SearchBuf(strtochar(tbname));
             DBFileInfo* fileinfo = new DBFileInfo();
             fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
             char** keyattr = new char* [condition.operands.size()];
             int* style = new int[condition.operands.size() ];
             int* oper;
             if(condition.opcodes.size() != 0)
                oper = new int[condition.opcodes.size()];
            else
                oper = NULL;
             char** keyword = new char* [condition.operands.size()];
             int paranum = condition.operands.size();
             vector< pair<int, int> > result;
             for(int i = 0;i<condition.opcodes.size();i++)
             {
                 if(condition.opcodes[i] == Condition::AND)
                    oper[i] = 0;
                 else if(condition.opcodes[i] == Condition::OR)
                    oper[i] = 1;
             }
            for(int i = 0;i<condition.operands.size();i++)
            {
                if(condition.operands[i].left.type == Expr::ATTR)
                {
                     if(condition.operands[i].op == CondEntry::EQUAL)
                        style[i] = 0;
                    else if(condition.operands[i].op == CondEntry::GREATER)
                        style[i] = 1;
                    else if(condition.operands[i].op == CondEntry::LESS)
                        style[i] = 2;
                    keyattr[i] = new char[ATTRLENGTHMAX];
                    memcpy(keyattr[i], strtochar(condition.operands[i].left.attr.attrname),  condition.operands[i].left.attr.attrname.length() + 1);
                    if(condition.operands[i].right.type == Expr::INTEGER)
                    {
                        keyword[i] = new char[5];
                        memcpy(keyword[i], (char*)(&(condition.operands[i].right.integer)), 4);
                        memcpy(keyword[i] + 4, "\0", 1);
                    }
                    else if(condition.operands[i].right.type == Expr::LITERAL)
                    {
                        keyword[i] = new char[condition.operands[i].right.literal.length() + 1];
                        memcpy(keyword[i], strtochar(condition.operands[i].right.literal), condition.operands[i].right.literal.length() + 1);
                    }
                }
                else
                {
                    if(condition.operands[i].op == CondEntry::EQUAL)
                        style[i] = 0;
                    else if(condition.operands[i].op == CondEntry::GREATER)
                        style[i] = 2;
                    else if(condition.operands[i].op == CondEntry::LESS)
                        style[i] = 1;
                    keyattr[i] = new char[ATTRLENGTHMAX];
                    memcpy(keyattr[i], strtochar(condition.operands[i].right.attr.attrname),  condition.operands[i].right.attr.attrname.length() + 1);
                    if(condition.operands[i].left.type == Expr::INTEGER)
                    {
                        keyword[i] = new char[5];
                        memcpy(keyword[i], (char*)(&(condition.operands[i].left.integer)), 4);
                        memcpy(keyword[i] + 4, "\0", 1);
                    }
                    else if(condition.operands[i].left.type == Expr::LITERAL)
                    {
                        keyword[i] = new char[condition.operands[i].left.literal.length() + 1];
                        memcpy(keyword[i], strtochar(condition.operands[i].left.literal), condition.operands[i].left.literal.length() + 1);
                    }
                }
            }
            bufFile[fileid]->SearchRecord(keyattr, style, oper, keyword, paranum, result);
            vector< pair<int, int> >::iterator iter = result.begin();
            for(;iter != result.end();iter++)
                bufFile[fileid]->DeleteRecord(iter->first, iter->second);
            break;
	     }
	 case UPDATE:
		 break;
	 case SELECT:
		 break;
	 case CREATE_INDEX:
		 break;
	 case DROP_INDEX:
		 break;
	 }
}
