#include <bits/stdc++.h>
using namespace std;
int N, ans;
int dfs(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return dfs(n - 1) + dfs(n- 2);
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &N))
	{
		ans = dfs(N);
		printf("%d\n", ans);
	}
	return 0;
}
