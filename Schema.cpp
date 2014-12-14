#include "SchemaEntry.h"
#include "Schema.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Schema::setPrimary(string& key)
{
	 for (int i = 0; i < size(); ++i)
		  if (entries[i].field == key)
		  {
			   entries[i].keykind = 1;
			   break;
		  }
}

void Schema::print()
{
	 for (int i = 0; i < size(); ++i)
	 {
		  cout << entries[i].field << ": " << entries[i].type << "(" << entries[i].length << ") ";
		  if (entries[i].notNull)
			   cout << "NoNull ";
		  else
			   cout << "YesNull ";
		  if (entries[i].keykind == 1)
			   cout << "PRI";
		  cout << endl;
	 }
}

void Schema::add(SchemaEntry& entry)
{
	 entries.push_back(entry);
}
