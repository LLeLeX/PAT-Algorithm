#include <bits/stdc++.h>
using namespace std;
char str[100];
int length, dp[105][105];
int main(int argc, char *argv[]) {
	scanf("%s", str);
	length = strlen(str);
	for(int i = 0; i < length; ++i)//��ʼ�� 
	{
		dp[i][i] = 1;
		if(str[i] == str[i + 1])
			dp[i][i + 1] = 1;
	}
	int ans = 0;
	for(int len = 3; len <= length; ++len)//�Ӵ��ĳ���,��������ȡ�Ⱥŵ� 
	{
		for(int i = 0; i < length; ++i)//�Ӵ��� 
		{
			int j = i + len - 1;//�Ӵ�β
			if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = dp[i + 1][j - 1];
				ans = len;
			}
			/*else
			{
				dp[i][j] = 0;//����Ҫд�� 
			}*/
		}
	}
	printf("%d", ans);
	return 0;
}
