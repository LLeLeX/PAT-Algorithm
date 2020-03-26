#include <bits/stdc++.h>
using namespace std;
int N, M, L;
int a[205], b[10005];
int dp[205][10005];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; ++i)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &L);
	for(int i = 1; i <= L; ++i)
	{
		scanf("%d", &b[i]);
	}
	/*for(int i = 0; i <= M; ++i)
	{
		dp[i][0] = 0;
	} 
	for(int i = 0; i <= L; ++i)
	{
		dp[0][i] = 0;
	}*/
	for(int i = 1; i <= M; ++i)
	{
		for(int j = 1; j <= L; ++j)
		{
			if(a[i] == b[j])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[M][L]);
	return 0;
}
