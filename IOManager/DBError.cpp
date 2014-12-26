#include "DBError.h"
#include <iostream>
#include <string>
using namespace std;

void DBPrintError(int error)
{
	cout<<"Error: "<<DB_ERROR[-error]<<"."<<endl;
}

void DBPrintErrorPos(string error)
{
	cout<<error<<": ";
}
