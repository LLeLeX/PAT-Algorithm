#include <bits/stdc++.h>
using namespace std;
int N, ans;
int A[10], dp[10];
int DP(int x)
{
	if(x == 0)//±ß½ç 
	{
		return A[0];
	}
	dp[x] = max(A[x], DP(x - 1) + A[x]);
	return dp[x];
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	int ans = -1;
	for(int i = 0; i < N; ++i)
	{
		int temp = DP(i);
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
