#include <bits/stdc++.h>
using namespace std;
int N;  
int f[10][10], dp[10][10];
int path[10][10];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			scanf("%d", &f[i][j]);
		}
	}
	for(int i = 1; i <= N; ++i)//±ß½ç 
	{
		dp[N][i] = f[N][i];
	}
	int maxw = -1;
	for(int i = N - 1; i >= 1; --i)
	{
		for(int j = 1; j <= i; ++j)
		{
			//dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
			if(dp[i + 1][j] > dp[i + 1][j + 1])
			{
				dp[i][j] = dp[i + 1][j] + f[i][j];
				path[i][j] = j;
			}
			else
			{
				dp[i][j] = dp[i + 1][j + 1] + f[i][j];
				path[i][j] = j + 1;
			}
		}
	}
	printf("%d\n", dp[1][1]);
	/*printf("%d ", f[1][1]);
	int index = path[1][1];*/
	int index = 1;
	for(int i = 1; i <= N; ++i)
	{
		cout << f[i][index] << " ";
		index = path[i][index];
	}
	return 0;
}
