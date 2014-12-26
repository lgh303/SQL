#include "DBFile.h"
#include "DBBufManager.h"
#include "DBUtility.h"
#include "DBError.h"
#include "DBFileManager.h"
#include "DBFileInfo.h"
#include "Global.h"
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
using namespace std;

class DBFileInfo;
DBFile* bufFile[BUFFILEMAX];

int DBFileManager::CreateFile(char* filename)
{
	//查找数据库中有无该文件
	_finddata_t* newfile = new _finddata_t();
	int result = _findfirst(filename, newfile);
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
	_finddata_t* newfile = new _finddata_t();
	int result = _findfirst(filename, newfile);
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
	if(newfile->size - DBFILEHEADER > 0)
	{
		bufFile[fileid]->content = new char[newfile->size - DBFILEHEADER];
		fin.read(bufFile[fileid]->content, newfile->size - DBFILEHEADER);
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
	_finddata_t* newfile = new _finddata_t();
	int result = _findfirst(filename, newfile);
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
	_finddata_t* newfile = new _finddata_t();
	int result = _findfirst(filename, newfile);
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