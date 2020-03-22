#include <bits/stdc++.h>
using namespace std;
int N, cnt;
struct account{
	char name[20];
	char pwd[20];
	bool flag;
	account(){}
	account(char *s1, char *s2, bool f)
	{
		strcpy(name, s1);
		strcpy(pwd, s2);
		flag = f;
	}
}acts[1005];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	char str1[20], str2[20];
	for(int i = 0; i < N; i++)
	{
		scanf("%s %s", str1, str2);
		int len2 = strlen(str2);
		bool f = false;//标记是否被修改过 
		for(int i = 0; i < len2; i++)//遍历判断并修改 
		{
			if(str2[i] == '1')
			{
				str2[i] = '@';
				f = true;
			}
			else if(str2[i] == '0')
			{
				str2[i] = '%';
				f = true;
			}
			else if(str2[i] == 'l')
			{
				str2[i] = 'L';
				f = true;
			}
			else if(str2[i] == 'O')
			{
				str2[i] = 'o';
				f = true;
			}
			else
			{
				continue;
			}
		}
		if(f)
		{
			acts[i] = account(str1, str2, f);
			cnt++; 
		}
		else
		{
			acts[i] = account(str1, str2, f);
		}
	}
	if(!cnt)
	{
		if(N != 1)
			printf("There are %d accounts and no account is modified", N);
		else
			printf("There is 1 account and no account is modified");
	}
	else
	{
		printf("%d\n", cnt);
		for(int i = 0; i < N; i++)
		{
			if(acts[i].flag)
			{
				printf("%s %s", acts[i].name, acts[i].pwd);
				if(i < N - 1)
				{
					printf("\n");
				}
			}
		}
	}
	return 0;
}
