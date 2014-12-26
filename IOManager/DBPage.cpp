#include "DBPage.h"
#include "DBUtility.h"
#include <iostream>
using namespace std;

DBPageHeader::DBPageHeader()
{
	header = new char[DBPAGEHEADER];
	memset(header, 0, DBPAGEHEADER);
}

DBPage::DBPage()
{
	pagecontent = new char[DBPAGE - DBPAGEHEADER];
	memset(pagecontent, 0, DBPAGE - DBPAGEHEADER);
}

