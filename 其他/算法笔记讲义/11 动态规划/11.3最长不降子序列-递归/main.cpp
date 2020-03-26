#include <bits/stdc++.h>
using namespace std;
int N;
int A[10], dp[10];
int DP(int x, int y)
{
	if(y >= x)//±ß½ç 
		return 1;
	//µÝ¹éÌå 
	if(A[x] >= A[y] && dp[x] < dp[y] + 1)
	{
		dp[x] = dp[y] + 1;
		y++;
		DP(x, y);	
	}
	else
	{
		y++;
		DP(x, y);
	}
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
		dp[i] = 1;
		int temp = DP(i, 0);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	return 0;
}
