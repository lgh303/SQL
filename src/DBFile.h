#ifndef __DBFILE_H__
#define __DBFILE_H__
#include "DBUtility.h"
#include "DBPage.h"
#include <vector>
#include <map>
using namespace std;

class DBRecord;

class DBFileHeader
{
public:
	char* header;

public:
	DBFileHeader();

};
class DBFile
{
public:
	DBFileHeader fileheader;
	char* content;
public:
	DBFile();
	int CreatePage();
	char* getPage(int page);
	char* getRecord(int page, int rid);
	int SearchRecord(char** keyattr, int* oper, char** keyword, int paranum, vector< pair<int, int>>& re);
	int AddRecord(char* record, int length);
	int DeleteRecord(int pageid, int rid);
	int UpdateRecord(char* keyattr, char* keyword, int pageid, int rid);
};

extern DBFile* bufFile[BUFFILEMAX];

#endif