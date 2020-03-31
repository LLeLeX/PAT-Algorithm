#include <bits/stdc++.h>
using namespace std;
char str1[10005], str2[10005];
int hashTable[130];
int main(int argc, char *argv[]) {
	fgets(str1, 10005, stdin);
	fgets(str2, 10005, stdin);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; i++)
	{
		hashTable[str2[i]] = 1;
	}
	for(int i = 0; i < len1; i++)
	{
		if(hashTable[str1[i]] == 1)
		{
			continue;
		}
		else
		{
			printf("%c", str1[i]);
		}
	}
	return 0;
}
