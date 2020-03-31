#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int K;
int A[maxn], dp[maxn], start[maxn];//start[i]，表示A[]中从start[i]下标开始，到A[i]的序列 
int main(int argc, char *argv[]) {
	scanf("%d", &K);
	bool flag = true;//标记是否全为负数 
	for(int i = 0; i < K; ++i)
	{
		scanf("%d", &A[i]);
		if(A[i] >= 0)
			flag = false;
	}
	if(flag == true)
	{
		printf("0 %d %d", A[0], A[K - 1]);
		return 0;
	}
	dp[0] = A[0];
	for(int i = 1; i < K; ++i)
	{
		if(A[i] > (dp[i - 1] + A[i]))
		{
			start[i] = i;
			dp[i] = A[i];
		}
		else
		{
			start[i] = start[i - 1];
			dp[i] = dp[i - 1] + A[i];
		}
	}
	int ans = dp[0], index = 0;//index要从0开始，不能从-1开始，否则当dp[0]最大时，index仍为-1报错 
	for(int i = 1; i < K; ++i)
	{
		if(dp[i] > dp[index])
		{
			ans = dp[i];
			index = i;
		}
	}
	printf("%d %d %d", ans, A[start[index]], A[index]);
	return 0;
}
