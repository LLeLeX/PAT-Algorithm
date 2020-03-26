#include <bits/stdc++.h>
using namespace std;
int N;
int A[10], dp[10];
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
		for(int j = 0; j < i; ++j)
		{
			if(A[j] <= A[i] && (dp[j] + 1 > dp[i]))
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
