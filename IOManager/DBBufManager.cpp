#include <iostream>
#include <fstream>
#include "DBBufManager.h"
#include "DBUtility.h"
#include "DBFileManager.h"
using namespace std;


DBBufManager::DBBufManager()
{
	bufnum = 0;
	for(int i = 0;i<BUFFILEMAX;i++)
	{
		isnull.push_back(true);
		visittime.push_back(0);
	}
}

//���һ��Buf File, allocnumΪ����ţ����ظ�filename������Ļ������
int DBBufManager::AddBuf(char* filename)
{
	int tmp = SearchBuf(filename);
	if(tmp != -1)
		return tmp;
	else
	{
		if(bufnum < BUFFILEMAX)
		{
			int allocnum = -1;
			for(int i = 0;i<BUFFILEMAX;i++)
			{
				if(isnull[i])
				{
					allocnum = i;
					break;
				}
			}
			bufmap[filename] = allocnum;
			bufinvmap[allocnum] = filename;
			isnull[allocnum] = false;
			bufnum += 1;
			return allocnum;
		}
		else
		{
			int allocnum = DeleteBuf();
			bufmap[filename] = allocnum;
			bufinvmap[allocnum] = filename;
			isnull[allocnum] = false;
			bufnum += 1;
			return allocnum;
		}
	}
}

//ɾ��Buf�����ر�ɾ����Buf�ţ�ɾ��������ɾ����һ�β�����������ʱ������Ǹ�BufFile
int DBBufManager::DeleteBuf()
{
	time_t min_visit_time = INT_MAX;
	int todelete = -1;
	for(int i = 0;i<BUFFILEMAX;i++)
	{
		if(visittime[i] < min_visit_time && !isnull[i])
		{
			min_visit_time = visittime[i];
			todelete = i;
		}
	}
	if(todelete != -1)
	{
		bufnum -= 1;
		myfilemanager->CloseFile(bufinvmap[todelete]);
		isnull[todelete] = true;
	}
	return todelete;
}

int DBBufManager::DeleteBufById(int id)
{
	if(!isnull[id])
	{
		bufnum -= 1;
		myfilemanager->CloseFile(bufinvmap[id]);
		isnull[id] = true;
	}
	return id;
}

//����һ���ļ���Ӧ��Buf�š�
int DBBufManager::SearchBuf(char* filename)
{
	map<char*, int>::iterator iter = bufmap.find(filename);
	if(iter == bufmap.end())
		return -1;
	else
	{
		int num = iter->second;
		if(isnull[num])
			return -1;
		else
			return num;
	} 
}

int DBBufManager::FixOperTime(int id, time_t opertime)
{
	if(isnull[id])
		return -1;
	else
		visittime[id] = opertime;
	return 0;
}

int DBBufManager::AllWriteback()
{
	int tmp = bufnum;
	for(int i = 0;i<tmp;i++)
	{
		int re = DeleteBuf();
	}
	return 0;
}