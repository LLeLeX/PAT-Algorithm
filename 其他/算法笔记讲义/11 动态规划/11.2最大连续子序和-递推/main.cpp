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
	dp[0] = A[0];//±ß½ç
	int ans = dp[0];
	for(int i = 1; i < N; ++i)
	{
		dp[i] = max(A[i], dp[i - 1] + A[i]);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	return 0;
}
