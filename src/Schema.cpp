#include "SchemaEntry.h"
#include "Schema.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Schema::print()
{
	 for (int i = 0; i < size(); ++i)
	 {
		  cout << entries[i].field << ": " << entries[i].type << "(" << entries[i].length << ") ";
		  if (entries[i].notNull)
			   cout << "NoNull ";
		  else
			   cout << "YesNull ";
		  if (entries[i].isPrimary)
			   cout << "PRIMARY  ";
		  if (entries[i].isForeign)
			   cout << "FOREIGN (" << entries[i].foreignAttr.toString() << ")";
		  cout << endl;
	 }
	 if (!constrain.empty())
		  constrain.print();
}

void Schema::process(SchemaEntry& entry)
{
	 switch (entry.entrykind)
	 {
	 case SchemaEntry::NORMAL :
		  entry.isPrimary = false;
		  entry.isForeign = false;
		  entry.hasConstrain = false;
		  entries.push_back(entry);
		  break;
	 case SchemaEntry::PRIMARY :
		  for (int i = 0; i < size(); ++i)
			   if (entries[i].field == entry.primaryKey)
			   {
					entries[i].isPrimary = true;
					break;
			   }
		  break;
	 case SchemaEntry::CHECK :
		  constrain = entry.constrain;
		  break;
	 case SchemaEntry::FOREIGN :
		  for (int i = 0; i < size(); ++i)
			   if (entries[i].field == entry.foreignKey)
			   {
					entries[i].isForeign = true;
					entries[i].foreignAttr = entry.foreignAttr;
					break;
			   }
		  break;
	 }
}
