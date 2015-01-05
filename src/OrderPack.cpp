#include <cstring>
#include <iostream>
#include "OrderPack.h"
#include "DBFileManager.h"
#include "DBBufManager.h"
#include "DBFileInfo.h"
#include "SchemaEntry.h"
#include "DBError.h"
#include "DBUtility.h"
#include "Global.h"
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
                 recordlength += fileinfo->attr[i].length;
                 if(schema.entries[i].field.length() >= 32)
                 {
                     DBPrintErrorPos("Create Table Resolution");
                     DBPrintError(ATTRNAMETOOLONG);
                     return;
                 }
                 strcpy(fileinfo->attr[i].name, strtochar(schema.entries[i].field));
                 fileinfo->attr[i].offset = recordlength;
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
	 case SHOW:
		 break;
	 case DESC:
		 break;
	 case INSERT:
		 break;
	 case DELETE:
		 break;
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
