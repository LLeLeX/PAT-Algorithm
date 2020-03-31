#include <bits/stdc++.h>
using namespace std;
int N, M, L;
int hashtable[205];
int a[10005], dp[10005];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
	{
		hashtable[i] = -1;//初始化 
	}
	for(int i = 1; i <= M; ++i)
	{
		int color;
		scanf("%d", &color);
		hashtable[color] = i;
	}
	scanf("%d", &L);
	int num = 0;//剔除不喜欢的颜色 
	for(int i = 0; i < L; ++i)
	{
		int color;
		scanf("%d", &color);
		if(hashtable[color] > -1)//转化 为最长不降子序列问题 
			a[num++] = hashtable[color];
	}
	int ans = 0;
	for(int i = 0; i < num; ++i)
	{
		dp[i] = 1;
		for(int j = 0; j < i; ++j)
		{
			if(a[j] <= a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
