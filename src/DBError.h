#ifndef __DBERROR_H__
#define __DBERROR_H__
#include <string>
using namespace std;

static const char* DB_ERROR[] = {
		"DB_OK",
		"Cannot create file",
		"File has already existed. Cannot create file.",
		"Oops! There is no such file",
		"File is not open",
		"Don't you forget setting file header? Record length is 0.",
		"There is no such attribute in this file.",
		"Create record failed. The record length is not equal to the current document's record length.",
		"Create record failed. The record's primary key is equal to some else in this document.",
		"Delete record failed. The record to be deleted is null.",
		"Delete record failed. Page id overflow.",
		"Delete record failed. Record id overflow.",
		"There is no such attribute in this document."
	};

extern void DBPrintError(int error);
extern void DBPrintErrorPos(string error);


#endif // !__DBERROR_H__
