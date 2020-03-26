#include <bits/stdc++.h>
using namespace std;
char str[100];
int length, dp[105][105];
int main(int argc, char *argv[]) {
	scanf("%s", str);
	length = strlen(str);
	for(int i = 0; i < length; ++i)//初始化 
	{
		dp[i][i] = 1;
		if(str[i] == str[i + 1])
			dp[i][i + 1] = 1;
	}
	int ans = 0;
	for(int len = 3; len <= length; ++len)//子串的长度,长度是能取等号的 
	{
		for(int i = 0; i < length; ++i)//子串首 
		{
			int j = i + len - 1;//子串尾
			if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = dp[i + 1][j - 1];
				ans = len;
			}
			/*else
			{
				dp[i][j] = 0;//不需要写出 
			}*/
		}
	}
	printf("%d", ans);
	return 0;
}
