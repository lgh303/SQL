#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	 int x = 5;
	 int y = -3;
	 string s = "Hello all";
	 FILE *output = fopen("store_test", "wb");
	 if (!output)
	 {
		  printf("Oh no!\n");
		  return -1;
	 }
	 int data[2];
	 data[0] = x;
	 data[1] = y;
	 fwrite(data, sizeof(int), 2, output);
	 fwrite(s.c_str(), sizeof(char), s.size(), output);
	 fclose(output);
	 FILE *input = fopen("store_test", "rb");
	 if (!input)
	 {
		  printf("E..\n");
		  return -1;
	 }
	 int recv_data[2];
	 fread(recv_data, sizeof(int), 2, input);
	 char buf[128];
	 int len = fread(buf, sizeof(char), 128, input);
	 fclose(input);
	 printf("%d %d\n", recv_data[0], recv_data[1]);
	 printf("%d\n", len);
	 buf[len] = '\0';
	 printf("%s\n", buf);
}
