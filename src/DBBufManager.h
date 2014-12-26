#ifndef __DBBUFMANAGER__H__
#define __DBBUFMANAGER__H__
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class DBBufManager
{
public:
	int bufnum;
	map<char*, int> bufmap;
	map<int, char*> bufinvmap;
	vector<time_t> visittime;
	vector<bool> isnull;
public:
	DBBufManager();
	int AddBuf(char* filename);
	int DeleteBuf();
	int DeleteBufById(int fileid);
	int SearchBuf(char* filename);
	int FixOperTime(int id, time_t opertime);
	int AllWriteback();
};

extern DBBufManager* mybufmanager;

#endif