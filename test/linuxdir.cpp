#include <cstdio>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <string>

using std::string;
int main()
{
	 string dbname = "db/";
	 string dbpath = "../" + dbname;
	 DIR *dir = opendir(dbpath.c_str());
	 string tbname = "User";
	 for (dirent *pDir = readdir(dir); pDir != NULL; pDir = readdir(dir))
	 {
		  if (pDir->d_name[0] != '.' && tbname == pDir->d_name)
		  {
			   string tbpath = dbpath + tbname;
			   struct stat filestat;
			   stat(tbpath.c_str(), &filestat);
			   int size = filestat.st_size;
			   printf("%d\n", size);
		  }
	 }
}
