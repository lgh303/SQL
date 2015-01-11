#ifndef __DBFILEMANAGER_H__
#define __DBFILEMANAGER_H__

#include<iostream>
using namespace std;

class DBAttribute;
class DBFileInfo;

class DBFileManager
{
public:
	int CreateFile(char* filename);
	int DestroyFile(char* filename);
	int OpenFile(char* filename);
	int CloseFile(char* filename);
	DBFileInfo* getFileHeader(char* filename);
	int setFileHeader(DBFileInfo* fi, char* filename);
	int TwoBufConnected(char* filename1, char* attr1, char* filename2, char* attr2);
};

extern DBFileManager* myfilemanager;

#endif
