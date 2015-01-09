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
#include "IndexManager.h"
#include "BTree.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

static int enterDatabaseFlag = 0;

extern IndexManager* indexManager;

inline char* strtochar(string s)
{
	char* c = new char[s.length() + 1];
	for(int i = 0;i<s.length();i++)
		c[i] = s[i];
	c[s.length()] = '\0';
	return c;
}

int infoready(Condition condition, char** &keyattr, int* &style, int* &oper, char** &keyword)
{
     keyattr = new char* [condition.operands.size()];
     style = new int[condition.operands.size() ];
     if(condition.opcodes.size() != 0)
        oper = new int[condition.opcodes.size()];
    else
        oper = NULL;
     keyword = new char* [condition.operands.size()];
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
    return DBOK;
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
             int err = myfilemanager->CreateFile(strtochar(tbname));
             if(err < 0)
                return;
             //更改文件头
             DBFileInfo* fileinfo = new DBFileInfo();
             fileinfo->attrNum = schema.size();
             int recordlength = 0;
             for(int i = 0;i<schema.size();i++)
             {
                 fileinfo->attr[i].isForeign = schema.entries[i].isForeign;
                 fileinfo->attr[i].isNull = !schema.entries[i].notNull;
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
             err = myfilemanager->setFileHeader(fileinfo, strtochar(tbname));
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
             DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
			/* for (int i = 0; i < fileinfo->attrNum; ++i)
			 {
				  string type = "int";
				  if (fileinfo->attr[i].type == 0)
					   type = "char";
				  cout << fileinfo->attr[i].name << ": " << type << "(" << fileinfo->attr[i].length - 1 << ") ";
				  if (!fileinfo->attr[i].isNull)
					   cout << "Not Null ";
				  if (fileinfo->attr[i].isPrimary)
					   cout << "PRIMARY  ";
				  cout << endl;
			 }*/
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
             DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
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
                    if(fileinfo->attr[i].type == 1)
                        memcpy(record + fileinfo->attr[i].offset, (char*)(&values[i].integer), 4);
                    else
                    {
                        DBPrintErrorPos("Insert Resolution");
                        DBPrintError(TYPEERROR);
                        return;
                    }
                 else if(values[i].type == 1)
                    if(fileinfo->attr[i].type == 0)
                        memcpy(record + fileinfo->attr[i].offset, strtochar(values[i].literal), values[i].literal.length() + 1);
                    else
                    {
                        DBPrintErrorPos("Insert Resolution");
                        DBPrintError(TYPEERROR);
                        return;
                    }
                //空值判断
                 else
                 {
                     if(!fileinfo->attr[i].isNull)
                     {
                         DBPrintErrorPos("Insert Record");
                         DBPrintError(KEYNULL);
                         return;
                     }
                     char* zero = new char[fileinfo->attr[i].length];
                     for(int j = 0;j<fileinfo->attr[i].length;j++)
                        zero[j] = '\0';
                     memcpy(record + fileinfo->attr[i].offset, zero, fileinfo->attr[i].length);
                 }
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
             DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
             char** keyattr;
             int* style;
             int* oper;
             char** keyword;
             int paranum = condition.operands.size();
             vector< pair<int, int> > result;
             infoready(condition, keyattr, style, oper, keyword);
             bufFile[fileid]->SearchRecord(keyattr, style, oper, keyword, paranum, result);
             if(result.size() == 0)
             {
                 DBPrintErrorPos("Delete Record");
                 DBPrintError(NOSUCHRECORD);
                 return;
             }
             vector< pair<int, int> >::iterator iter = result.begin();
             for(;iter != result.end();iter++)
                 bufFile[fileid]->DeleteRecord(iter->first, iter->second);
             break;
	     }
	 case UPDATE:
	     {
             int err = myfilemanager->OpenFile(strtochar(tbname));
             if(err < 0)
                return;
             int fileid = mybufmanager->SearchBuf(strtochar(tbname));
             DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
             char** keyattr;
             int* style;
             int* oper;
             char** keyword;
             int paranum = condition.operands.size();
             vector< pair<int, int> > result;
             infoready(condition, keyattr, style, oper, keyword);
             if(condition.operands.size() != 0)
                bufFile[fileid]->SearchRecord(keyattr, style, oper, keyword, paranum, result);
            else
            {
                for(int i = 0;i<fileinfo->pageNum;i++)
                 for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
                     if(!((DBRecordHeader*)(bufFile[fileid]->getRecord(i, j)))->isNull)
                         result.push_back(make_pair(i, j));
            }
             char* upattr = new char[updateAttr.length() + 1];
             memcpy(upattr, strtochar(updateAttr), updateAttr.length() + 1);
             char* upword;
             if(updateValue.type == 0)
             {
                 upword = new char[5];
                 memcpy(upword, (int*)(&(updateValue.integer)), 4);
                 memcpy(upword + 4, "\0", 1);
             }
             else if(updateValue.type == 1)
             {
                 upword = new char[updateValue.literal.length() + 1];
                 memcpy(upword, strtochar(updateValue.literal), updateValue.literal.length() + 1);
             }
             else
             {
                 for(int i = 0;i<fileinfo->attrNum;i++)
                    if(!fileinfo->attr[i].isNull && strcmp(fileinfo->attr[i].name, upattr) == 0)
                    {
                        DBPrintErrorPos("Update Record");
                        DBPrintError(KEYNULL);
                        return;
                    }
                 upword = new char[5];
                 memcpy(upword, "\0\0\0\0\0", 5);
             }
             vector< pair<int, int> >::iterator iter = result.begin();
             for(;iter != result.end();iter++)
                 bufFile[fileid]->UpdateRecord(upattr, upword, iter->first, iter->second);
             break;
	     }
	 case SELECT:
	     {
	         //单表非聚集处理
	         bool isGather = false;
	         for(int i = 0;i<attrs.size();i++)
                if(attrs[i].aggr != Attr::NONE)
                 {
                     isGather = true;
                     break;
                 }
             if(tables.size() == 1 && !isGather && groupbyAttr.aggr == Attr::NONE)
             {
                 int err = myfilemanager->OpenFile(strtochar(tables[0]));
                 if(err < 0)
                    return;
                 int fileid = mybufmanager->SearchBuf(strtochar(tables[0]));
                 DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tables[0]));
                 char** keyattr = NULL;
                 int* style = NULL;
                 int* oper = NULL;
                 char** keyword = NULL;
                 int paranum = condition.operands.size();
                 vector< pair<int, int> > result;
                 infoready(condition, keyattr, style, oper, keyword);
                 if(condition.operands.size() != 0)
                    bufFile[fileid]->SearchRecord(keyattr, style, oper, keyword, paranum, result);
                else
                {
                     for(int i = 0;i<fileinfo->pageNum;i++)
                        for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
                            if(!((DBRecordHeader*)(bufFile[fileid]->getRecord(i, j)))->isNull)
                                result.push_back(make_pair(i, j));
                }
                 vector<int> targetattrlist;
                 if(allAttrs)
                    for(int i = 0;i<fileinfo->attrNum;i++)
                        targetattrlist.push_back(i);
                 else
                 {
                     vector<Attr>::iterator iter = attrs.begin();
                     for(;iter != attrs.end();iter++)
                     {
                         int flag = 0;
                         for(int i = 0;i<fileinfo->attrNum;i++)
                         {
                            if(strcmp(strtochar(iter->attrname), fileinfo->attr[i].name) == 0)
                             {
                                 flag = 1;
                                 targetattrlist.push_back(i);
                                 break;
                             }
                         }
                         if(flag == 0)
                         {
                             DBPrintErrorPos("Search Record Resolution");
                             DBPrintError(NOSUCHATTR);
                             return;
                         }
                     }
                 }
                 bufFile[fileid]->show(result, targetattrlist);
             }
             //单表聚集查询
             if(tables.size() == 1 && attrs.size() == 1 && isGather)
             {
                 int err = myfilemanager->OpenFile(strtochar(tables[0]));
                 if(err < 0)
                    return;
                 int fileid = mybufmanager->SearchBuf(strtochar(tables[0]));
                 DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tables[0]));
                 vector< pair<int, int> > searchid;
                 for(int i = 0;i<fileinfo->pageNum;i++)
                     for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
                        if(!((DBRecordHeader*)(bufFile[fileid]->getRecord(i, j)))->isNull)
                            searchid.push_back(make_pair(i, j));
                int mode;
                if(attrs[0].aggr == Attr::SUM)
                    mode = 0;
                else if(attrs[0].aggr == Attr::AVG)
                    mode = 1;
                else if(attrs[0].aggr == Attr::MAX)
                    mode = 2;
                else if(attrs[0].aggr == Attr::MIN)
                    mode = 3;
                int resultflag;
                int resultInteger;
                char* resultLiteral;
                err = bufFile[fileid]->calculate(searchid, strtochar(attrs[0].attrname), mode, resultflag, resultInteger, resultLiteral);
                if(err < 0)
                    return;
                cout<<endl;
                if(resultflag == 0)
                    cout<<" "<<resultLiteral<<endl;
                else
                    cout<<" "<<resultInteger<<endl;
                cout<<endl;
             }
            //单表分组聚集查询
            if(tables.size() == 1 && attrs.size() == 2 && isGather)
            {
                int err = myfilemanager->OpenFile(strtochar(tables[0]));
                if(err < 0)
                    return;
                int fileid = mybufmanager->SearchBuf(strtochar(tables[0]));
                DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tables[0]));
                if(fileinfo->pageNum == 0)
                {
                    DBPrintErrorPos("Search Record");
                    DBPrintError(NOSUCHRECORD);
                    return;
                }
                int slotTotal = fileinfo->pageNum * ((DBPageInfo*)(bufFile[fileid]->getPage(0)))->slotNum;
                int slotPerPage = ((DBPageInfo*)(bufFile[fileid]->getPage(0)))->slotNum;
                bool* flag = new bool[slotTotal];
                memset(flag, 0, slotTotal);
                int attrpos = -1;
                for(int i = 0;i<fileinfo->attrNum;i++)
                    if(strcmp(fileinfo->attr[i].name, strtochar(groupbyAttr.attrname)) == 0)
                    {
                        attrpos = i;
                        break;
                    }
                if(attrpos == -1)
                {
                    DBPrintErrorPos("Search Record");
                    DBPrintError(NOSUCHATTR);
                    return;
                }
                cout<<endl;
                for(int i = 0;i<fileinfo->pageNum;i++)
                     for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
                        if(!((DBRecordHeader*)(bufFile[fileid]->getRecord(i, j)))->isNull &&  !flag[i*slotPerPage+j])
                        {
                            char** keyattr = new char*[1];
                            keyattr[0] = new char[groupbyAttr.attrname.length() + 1];
                            int* style = new int[1];
                            style[0] = 0;
                            char** keyword = new char*[1];
                            keyword[0] = new char[fileinfo->attr[attrpos].length];
                            memcpy(keyword[0], bufFile[fileid]->getRecord(i, j) + DBRECORDHEADER + fileinfo->attr[attrpos].offset, fileinfo->attr[attrpos].length);
                            memcpy(keyattr[0], strtochar(groupbyAttr.attrname), groupbyAttr.attrname.length() + 1);
                            vector< pair<int, int> > result;
                            bufFile[fileid]->SearchRecord(keyattr, style, NULL, keyword, 1, result);
                            vector< pair<int, int> >::iterator iter = result.begin();
                            for(;iter != result.end();iter++)
                                flag[iter->first * slotPerPage + iter->second] = true;

                            int mode;
                            if(attrs[1].aggr == Attr::SUM)
                                mode = 0;
                            else if(attrs[1].aggr == Attr::AVG)
                                mode = 1;
                            else if(attrs[1].aggr == Attr::MAX)
                                mode = 2;
                            else if(attrs[1].aggr == Attr::MIN)
                                mode = 3;
                            int resultflag;
                            int resultInteger;
                            char* resultLiteral;
                            int err = bufFile[fileid]->calculate(result, strtochar(attrs[1].attrname), mode, resultflag, resultInteger, resultLiteral);
                            if(err < 0)
                                return;
                            if(resultflag == 0)
                                if(fileinfo->attr[attrpos].type == 0)
                                    cout<<" "<<keyword[0]<<"  :  "<<resultLiteral<<endl;
                                else
                                    cout<<" "<<*((int*)keyword[0])<<"  :  "<<resultLiteral<<endl;
                            else
                                if(fileinfo->attr[attrpos].type == 0)
                                    cout<<" "<<keyword[0]<<"  :  "<<resultInteger<<endl;
                                else
                                    cout<<" "<<*((int*)keyword[0])<<"  :  "<<resultInteger<<endl;
                        }
                        cout<<endl;
            }
            break;
	     }
	 case CREATE_INDEX:
	 {
		  int err = myfilemanager->OpenFile(strtochar(tbname));
		  if(err < 0)
			   return;
		  int fileid = mybufmanager->SearchBuf(strtochar(tbname));
		  if (fileid < 0)
		  {
			   DBPrintErrorPos("Table not Exist. Create Index Failed.\n");
			   break;
		  }
		  DBFileInfo* fileinfo = myfilemanager->getFileHeader(strtochar(tbname));
		  int type = -1;
		  int offset = -1;
		  int pos = -1;
		  for (int i = 0; i < fileinfo->attrNum; ++i)
			   if (fileinfo->attr[i].name == indexAttr)
			   {
					pos = i;
					type = fileinfo->attr[i].type;
					offset = fileinfo->attr[i].offset;
					break;
			   }
		  if (type == -1)
		  {
			   DBPrintErrorPos("Attribute not Exist. Create Index Failed.\n");
			   break;
		  }
		  if (!fileinfo->attr[pos].isPrimary)
		  {
			   DBPrintErrorPos("Only Primary Key can create Index.\n");
			   break;
		  }
		  BTree *tree = NULL;
		  if (type == 0)
			   tree = new BTree(BTree::STRING);
		  else
			   tree = new BTree(BTree::DIGIT);
		  for(int i = 0;i<fileinfo->pageNum;i++)
			   for(int j = 0;j<((DBPageInfo*)(bufFile[fileid]->getPage(i)))->slotNum;j++)
			   {
					char* header = bufFile[fileid]->getRecord(i, j);
					if (!((DBRecordHeader*)header)->isNull)
					{
						 char* pos = header + 8 + offset;
						 if (type == 0)
						 {
							  string value(pos);
							  tree->insert(value, make_pair(i, j));
						 }
						 else
						 {
							  int value = *(int*)pos;
							  tree->insert(value, make_pair(i, j));
						 }
					}
			   }
		  string tree_name = tbname + "_" + indexAttr;
		  indexManager->addBTree(indexAttr, tree);
		  indexManager->storeBTree(tree_name, tree);
		  break;
	 }
	 case DROP_INDEX:
	 {
		  int ret = unlink(("index_" + tbname + "_" + indexAttr).c_str());
		  if (ret < 0)
			   DBPrintErrorPos("Index Not Exist. Drop Index Failed.\n");
		  break;
	 }
	 }
}
