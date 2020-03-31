#include <bits/stdc++.h>
using namespace std;
int N;
int minLen = 1000;
char s[105][305];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	getchar();
	for(int i = 0; i < N; i++)
	{
		/*fgets(s[i], 305, stdin);
		getchar();*/
		//getline(cin, s[i]);
		cin.getline(s[i], 305);
		int len = strlen(s[i]);
		reverse(s[i], s[i] + len);
		minLen = min(len, minLen);
	}
	//cout << minLen;
	int cnt = 0;
	for(int j = 0; j < minLen; j++)//列 
	{
		bool flag = true;
		for(int i = 1; i < N; i++)//行 
		{
			//查看所有行的这一列是否相同 
			if(s[i][j] != s[i - 1][j])
			{
				flag = false;
				break;
			}
		}	
		if(flag)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(!cnt)
	{
		printf("nai");
	}
	else
	{
		for(int i = cnt - 1; i >= 0; i--)
		{
			printf("%c", s[0][i]);
		} 
	}
	return 0;
}
