#include <bits/stdc++.h>
using namespace std;
char str[1005];
int length, ans, dp[1005][1005];
void DP(int len, int i)
{
	if(i >= length)
		return;
	int j = i + len - 1;
	if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
	{
		dp[i][j] = 1;
		ans = len;
	}
	i++;
	DP(len, i);
}
int main(int argc, char *argv[]) {
	fgets(str, 1005, stdin);
	length = strlen(str) - 1;
	if(length >= 1)
		ans = 1;
	for(int i = 0; i < length; ++i)//初始化dp 
	{
		dp[i][i] = 1;
		if(str[i] == str[i + 1])
		{
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for(int len = 3; len <= length; ++len)//长度要取等号 
	{
		DP(len, 0);
		/*for(int i = 0; i < length; ++i)
		{
			int j = i + len - 1;
			if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ans = len;
			}
		}*/
	}
	printf("%d", ans);
	return 0;
}
