#include <iostream>
#include "Global.h"
using namespace std;

time_t GetCurrentTime()
{
	time_t curtime;
	time(&curtime);
	return curtime;
}