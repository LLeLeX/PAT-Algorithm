#include <bits/stdc++.h>
using namespace std;
char str[100];
int length, ans, dp[105][105];
void DP(int len, int i)//���ȣ������ 
{
	if(i >= length)
		return;
	int j = i + len - 1;
	if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
	{
		dp[i][j] = dp[i + 1][j - 1];
		ans = len;	
	}
	i++;
	DP(len, i);
} 
int main(int argc, char *argv[]) {
	scanf("%s", str);
	length = strlen(str);
	for(int i = 0; i < length; ++i)//��ʼ�� 
	{
		dp[i][i] = 1;
		if(str[i] == str[i + 1])
			dp[i][i + 1] = 1;
	}
	for(int len = 3; len <= length; ++len)//�Ӵ��ĳ��� 
	{
		DP(len, 0);
	}
	printf("%d", ans);
	return 0;
}
