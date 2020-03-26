#include <bits/stdc++.h>
using namespace std;
int N;
int f[10][10], dp[10][10];
int DP(int x, int y)
{
	if(dp[x][y] != -1)
		return dp[x][y];
	else
	{
		dp[x][y] = max(DP(x + 1, y), DP(x + 1, y + 1)) + f[x][y];
		return dp[x][y];
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			scanf("%d", &f[i][j]);
			dp[i][j] = -1;
		}
	}
	for(int i = 1; i <= N; ++i)
	{
		dp[N][i] = f[N][i];
	}
	cout << DP(1, 1);
	return 0;
}
