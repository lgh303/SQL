#include "DBFile.h"
#include "DBBufManager.h"
#include "DBUtility.h"
#include "DBError.h"
#include "DBFileManager.h"
#include "DBFileInfo.h"
#include "DBPageInfo.h"
#include "DBRecord.h"
#include "Global.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#ifndef __LINUX__
#include <io.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;

class DBFileInfo;
DBFile* bufFile[BUFFILEMAX];
DBFile* tmpbuf;

int DBFileManager::CreateFile(char* filename)
{
	//查找数据库中有无该文件
	int result = -1;

#ifndef __LINUX__
	_finddata_t* newfile = new _finddata_t();
	result = _findfirst(filename, newfile);
#else
    char* curpath = new char[100];
    getcwd(curpath, 100);
	DIR *dir = opendir(curpath);
	// need to make sure dir != NULL
	string tbname = filename;
	for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
		 if (pDir->d_name[0] != '.' && tbname == pDir->d_name)
		 {
			  result = 0;
			  break;
		 }
	closedir(dir);
#endif

	if(result != -1)
	{
		DBPrintErrorPos("Create File Error");
		DBPrintError(FILEEXIST);
		return FILEEXIST;
	}
	//创建一个新文件
	ofstream fout;
	fout.open(filename);
	fout.close();
	int fileid = mybufmanager->AddBuf(filename);
	if(fileid == -1)
	{
		DBPrintErrorPos("Create File Error");
		DBPrintError(CREATEFILEFAILURE);
		return CREATEFILEFAILURE;
	}
	//为该文件新建buf
	bufFile[fileid] = new DBFile();
	DBFileInfo* fileinfo = new DBFileInfo();
	memcpy(bufFile[fileid]->fileheader.header, (char*)fileinfo, sizeof(*fileinfo));
	mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
	return DBOK;
}

int DBFileManager::OpenFile(char* filename)
{
	//查找数据库中有无该文件

	 int result = -1;
	 int filesize = -1;

#ifndef __LINUX__
	 _finddata_t* newfile = new _finddata_t();
	 result = _findfirst(filename, newfile);
	 filesize = newfile->size;
#else
	char* curpath = new char[100];
    getcwd(curpath, 100);
	DIR *dir = opendir(curpath);
	// need to make sure dir != NULL
	string tbname = filename;
	for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
		 if (pDir->d_name[0] != '.' && tbname == pDir->d_name)
		 {
			  result = 0;
			  string tbpath = tbname;
			  struct stat filestat;
			  stat(tbpath.c_str(), &filestat);
			  filesize = filestat.st_size;
			  break;
		 }
	closedir(dir);
#endif

	if(result == -1)
	{
		DBPrintErrorPos("Open File Error");
		DBPrintError(FILENOTEXIST);
		return FILENOTEXIST;
	}
	//查找Buf中有无该文件
	int id = mybufmanager->SearchBuf(filename);
	if(id != -1)
	{
		return DBOK;
	}
	//输入流，向新开的BufPage中写入字节流
	ifstream fin(filename);
	int fileid = mybufmanager->AddBuf(filename);
	bufFile[fileid] = new DBFile();
	fin.read(bufFile[fileid]->fileheader.header, DBFILEHEADER);
	if(filesize - DBFILEHEADER > 0)
	{
		bufFile[fileid]->content = new char[filesize - DBFILEHEADER];
		fin.read(bufFile[fileid]->content, filesize - DBFILEHEADER);
	}
	fin.close();
	mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
	return DBOK;
}

int DBFileManager::CloseFile(char* filename)
{
	//查找Buf中有无该文件
	int fileid = mybufmanager->SearchBuf(filename);
	if(fileid == -1)
	{
		DBPrintErrorPos("Close File Error");
		DBPrintError(FILENOTOPEN);
		return FILENOTOPEN;
	}
	//查找文件系统中有无该文件

	int result = -1;

#ifndef __LINUX__
	_finddata_t* newfile = new _finddata_t();
	result = _findfirst(filename, newfile);
#else
	char* curpath = new char[100];
    getcwd(curpath, 100);
	DIR *dir = opendir(curpath);
	// need to make sure dir != NULL
	string tbname = filename;
	for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
		 if (pDir->d_name[0] != '.' && tbname == pDir->d_name)
		 {
			  result = 0;
			  break;
		 }
	closedir(dir);
#endif

	if(result == -1)
	{
		DBPrintErrorPos("Close File Error");
		DBPrintError(FILENOTEXIST);
		return FILENOTEXIST;
	}
	//计算大小并写回
	ofstream fout(filename);
	fout.write(bufFile[fileid]->fileheader.header, DBFILEHEADER);
	int filesize = DBFILEHEADER + ((DBFileInfo*)(bufFile[fileid]->fileheader.header))->pageNum * DBPAGE;
	if(filesize - DBFILEHEADER > 0)
	{
		fout.write(bufFile[fileid]->content, filesize - DBFILEHEADER);
	}
	fout.close();
	mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
	return DBOK;
}

int DBFileManager::DestroyFile(char* filename)
{
	//查找文件系统中有无该文件

	int result = -1;

#ifndef __LINUX__
	_finddata_t* newfile = new _finddata_t();
	result = _findfirst(filename, newfile);
#else
	char* curpath = new char[100];
    getcwd(curpath, 100);
	DIR *dir = opendir(curpath);
	// need to make sure dir != NULL
	string tbname = filename;
	for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
		 if (pDir->d_name[0] != '.' && tbname == pDir->d_name)
		 {
			  result = 0;
			  break;
		 }
	closedir(dir);
#endif

	if(result == -1)
	{
		DBPrintErrorPos("Destroy File Error");
		DBPrintError(FILENOTEXIST);
		return FILENOTEXIST;
	}
	//查找Buf中有无该文件
	int fileid = mybufmanager->SearchBuf(filename);
	if(fileid != -1)
		mybufmanager->DeleteBufById(fileid);
	remove(filename);
	return DBOK;
}

DBFileInfo* DBFileManager::getFileHeader(char* filename)
{
	int fileid = mybufmanager->SearchBuf(filename);
	if(fileid == -1)
	{
		DBPrintErrorPos("Get File Header Error");
		DBPrintError(FILENOTOPEN);
		return NULL;
	}
	mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
	return (DBFileInfo*)(bufFile[fileid]->fileheader.header);
}
int DBFileManager::setFileHeader(DBFileInfo* fi, char* filename)
{
	int fileid = mybufmanager->SearchBuf(filename);
	if(fileid == -1)
	{
		DBPrintErrorPos("Set File Header Error");
		DBPrintError(FILENOTOPEN);
		return FILENOTOPEN;
	}
	memcpy(bufFile[fileid]->fileheader.header, (char*)fi, sizeof(*fi));
	mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
	return DBOK;
}

int DBFileManager::TwoBufConnected(char* filename1, char* filename2)
{
    int err = OpenFile(filename1);
    if(err < 0)
        return err;
    int fileid1 = mybufmanager->SearchBuf(filename1);
    DBFileInfo* fileinfo1 = myfilemanager->getFileHeader(filename1);
    err = OpenFile(filename2);
    if(err < 0)
        return err;
    int fileid2 = mybufmanager->SearchBuf(filename2);
    DBFileInfo* fileinfo2 = myfilemanager->getFileHeader(filename2);
    tmpbuf = new DBFile();
    DBFileInfo* fileinfo = new DBFileInfo();
    fileinfo->attrNum = fileinfo1->attrNum + fileinfo2->attrNum;
    fileinfo->recordLength = fileinfo1->recordLength + fileinfo2->recordLength;
    for(int i = 0;i<fileinfo1->attrNum;i++)
    {
        memcpy(fileinfo->attr[i].foreignKeyAttr, fileinfo1->attr[i].foreignKeyAttr, ATTRLENGTHMAX);
        memcpy(fileinfo->attr[i].foreignKeyFileName, fileinfo1->attr[i].foreignKeyFileName, ATTRLENGTHMAX);
        fileinfo->attr[i].isForeign = fileinfo1->attr[i].isForeign;
        fileinfo->attr[i].isNull = fileinfo1->attr[i].isNull;
        fileinfo->attr[i].isPrimary = false;
        fileinfo->attr[i].length = fileinfo1->attr[i].length;
        memcpy(fileinfo->attr[i].name, fileinfo1->fname, strlen(fileinfo1->fname));
        memcpy(fileinfo->attr[i].name + strlen(fileinfo1->fname), ".", 1);
        memcpy(fileinfo->attr[i].name + strlen(fileinfo1->fname) + 1, fileinfo1->attr[i].name, strlen(fileinfo1->attr[i].name));
        memcpy(fileinfo->attr[i].name + strlen(fileinfo1->fname) + 1 + strlen(fileinfo1->attr[i].name), "\0", 1);
        fileinfo->attr[i].offset = fileinfo1->attr[i].offset;
        fileinfo->attr[i].type = fileinfo1->attr[i].type;
    }
    int A = fileinfo1->attrNum;
     for(int i = 0;i<fileinfo2->attrNum;i++)
    {
        memcpy(fileinfo->attr[i + A].foreignKeyAttr, fileinfo2->attr[i].foreignKeyAttr, ATTRLENGTHMAX);
        memcpy(fileinfo->attr[i + A].foreignKeyFileName, fileinfo2->attr[i].foreignKeyFileName, ATTRLENGTHMAX);
        fileinfo->attr[i + A].isForeign = fileinfo2->attr[i].isForeign;
        fileinfo->attr[i + A].isNull = fileinfo2->attr[i].isNull;
        fileinfo->attr[i + A].isPrimary = false;
        fileinfo->attr[i + A].length = fileinfo2->attr[i].length;
        memcpy(fileinfo->attr[i + A].name, fileinfo2->fname, strlen(fileinfo2->fname));
        memcpy(fileinfo->attr[i + A].name + strlen(fileinfo2->fname), ".", 1);
        memcpy(fileinfo->attr[i + A].name + strlen(fileinfo2->fname) + 1, fileinfo2->attr[i].name, strlen(fileinfo2->attr[i].name));
        memcpy(fileinfo->attr[i + A].name + strlen(fileinfo2->fname) + 1 + strlen(fileinfo2->attr[i].name), "\0", 1);
        fileinfo->attr[i + A].offset = fileinfo2->attr[i].offset + fileinfo1->recordLength;
        fileinfo->attr[i + A].type = fileinfo2->attr[i].type;
    }
    memcpy(tmpbuf->fileheader.header, (char*)fileinfo, sizeof(*fileinfo));
    for(int i = 0;i<fileinfo1->pageNum;i++)
        for(int j = 0;j<((DBPageInfo*)(bufFile[fileid1]->getPage(i)))->slotNum;j++)
             if(!((DBRecordHeader*)(bufFile[fileid1]->getRecord(i, j)))->isNull)
              {
                  for(int x = 0;x<fileinfo2->pageNum;x++)
                    for(int y= 0;y<((DBPageInfo*)(bufFile[fileid2]->getPage(x)))->slotNum;y++)
                        if(!((DBRecordHeader*)(bufFile[fileid2]->getRecord(x, y)))->isNull)
                        {
                            char* newrecord = new char[fileinfo->recordLength];
                            memcpy(newrecord, bufFile[fileid1]->getRecord(i,j) + DBRECORDHEADER, fileinfo1->recordLength);
                            memcpy(newrecord + fileinfo1->recordLength, bufFile[fileid2]->getRecord(x,y) + DBRECORDHEADER, fileinfo2->recordLength);
                            tmpbuf->AddRecord(newrecord, fileinfo->recordLength);
                        }
              }
    return DBOK;
}
