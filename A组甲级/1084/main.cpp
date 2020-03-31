#include <bits/stdc++.h>
using namespace std;
int hashtable[200];
char origin[105], str[105];
int endpoint;
int main(int argc, char *argv[]) {
//只用hashtable输出顺序无法保证 
	scanf("%s", origin);
	scanf("%s", str);
	int len1 = strlen(origin);
	int len2 = strlen(str);
	int i = 0, j = 0;
	while(1)
	{
		if(i == len1)
			break; 
		if(origin[i] == str[j])
		{
			i++;
			j++;
		}
		else
		{
			int index = origin[i];
			if(hashtable[index] == 1)
			{
				i++;
				continue;
			}
			hashtable[index] = 1;
			if(origin[i] >= 'a' && origin[i] <= 'z')
			{
				hashtable[index - 32] = 1;
				printf("%c", origin[i] - 32);
			}
			else if(origin[i] >= 'A' && origin[i] <= 'Z')
			{
				hashtable[index + 32] = 1;
				printf("%c", origin[i]);
			}
			else
			{
				printf("%c", origin[i]);
			}
			i++;
		}
	}
	return 0;
}
