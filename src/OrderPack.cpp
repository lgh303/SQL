#include "OrderPack.h"
#include "DBFileManager.h"
#include "DBBufManager.h"
#include "DBFileInfo.h"
#include "SchemaEntry.h"
#include "DBError.h"
#include "DBUtility.h"
#include "Global.h"

inline char* strtochar(string s)
{
	char* c = new char[s.length() + 1];
	for(int i = 0;i<s.length();i++)
		c[i] = s[i];
	c[s.length()] = '\0';
	return c;
}

void OrderPack::process()
{
	 switch (type)
	 {
	 case CREATE_DB:
		 break;
	 case DROP_DB:
		 break;
	 case USE:
		 break;
	 case CREATE_TB:
		 //创建文件
		 myfilemanager->CreateFile(strtochar(tbname));
		 //更改文件头
		 DBFileInfo* fileinfo = new DBFileInfo();
		 fileinfo->attrNum = schema.size();
		 int recordlength = 0;
		 for(int i = 0;i<schema.size();i++)
		 {
			 fileinfo->attr[i].isForeign = (schema.entries[i].entrykind == SchemaEntry::EntryKind::FOREIGN ? true : false);
			 fileinfo->attr[i].isNull = ~schema.entries[i].notNull;
			 fileinfo->attr[i].isPrimary = (schema.entries[i].entrykind == SchemaEntry::EntryKind::PRIMARY ? true : false);
			 fileinfo->attr[i].length = ((schema.entries[i].type == "int") ? 5 : schema.entries[i].length + 1);
			 recordlength += fileinfo->attr[i].length;
			 if(schema.entries[i].field.length() >= 32)
			 {
				 DBPrintErrorPos("Create Table Resolution");
				 DBPrintError(ATTRNAMETOOLONG);
				 return;
			 }
			 strcpy(fileinfo->attr[i].name, strtochar(schema.entries[i].field));
			 fileinfo->attr[i].offset = recordlength;
			 if(schema.entries[i].type == "int")
				 fileinfo->attr[i].type = 1;//int
			 else
				 fileinfo->attr[i].type = 0;//char or varchar
			 if(fileinfo->attr[i].isForeign)
			 {
				 if(schema.entries[i].foreignAttr.attrname.length() >= 32)
				 {
					 DBPrintErrorPos("Create Table Resolution");
					 DBPrintError(FOREIGNATTRNAMETOOLONG);
					 return;
				 }
				 strcpy(fileinfo->attr[i].foreignKeyAttr, strtochar(schema.entries[i].foreignAttr.attrname));
				 if(schema.entries[i].foreignAttr.tbname.length() >= 32)
				 {
					 DBPrintErrorPos("Create Table Resolution");
					 DBPrintError(FOREIGNFILENAMETOOLONG);
					 return;
				 }
				 strcpy(fileinfo->attr[i].foreignKeyFileName, strtochar(schema.entries[i].foreignAttr.tbname));
			 }
		 }
		 fileinfo->recordLength = recordlength;
		 myfilemanager->setFileHeader(fileinfo, strtochar(tbname));
		 int fileid = mybufmanager->SearchBuf(strtochar(tbname));
		 mybufmanager->FixOperTime(fileid, ::GetCurrentTime());
		 break;
	 case DROP_TB:
		 int fileid = mybufmanager->SearchBuf(strtochar(tbname));
		 if(fileid < 0)
		 {

		 }
		 break;
	 case SHOW:
		 break;
	 case DESC:
		 break;
	 case INSERT:
		 break;
	 case DELETE:
		 break;
	 case UPDATE:
		 break;
	 case SELECT:
		 break;
	 case CREATE_INDEX:
		 break;
	 case DROP_INDEX:
		 break;
	 }
}
