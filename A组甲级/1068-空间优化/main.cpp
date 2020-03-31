#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int N, M;
int value[maxn], dp[maxn];
bool choice[maxn][maxn], path[maxn];
bool cmp(int a, int b)
{
	return b < a;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &value[i]);
	}
	sort(value + 1, value + N + 1, cmp);
	bool flag = false;//标记是否有解 
	for(int i = 1; i <= N; ++i)
	{
		for(int j = M; j >= value[i]; --j)
		{
			if(dp[j] <= dp[j - value[i]] + value[i])
			{
				dp[j] = dp[j - value[i]] + value[i];
				choice[i][j] = true;
			}
			else
			{
				choice[i][j] = false;
			}
			if(dp[j] == M)
			{
				flag = true;
			}
		}
	}
	if(flag == true)
	{
		int k = N, num = 0, v = M;
		while(k >= 0)
		{
			if(choice[k][v] == 1)
			{
				path[k] = true;
				v -= value[k];
				num++;
			}
			else
				path[k] = false;
			k--;
		}
		for(int i = N; i >= 1; --i)
		{
			if(path[i] == true)
			{
				printf("%d", value[i]);
				num--;
				if(num > 0)
					printf(" ");
			}	
		}
	}
	else
	{
		printf("No Solution");
	}
	return 0;
}
