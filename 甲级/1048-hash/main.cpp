#include <bits/stdc++.h>
using namespace std;
int N, M;
int coins[505];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		coins[num]++;
	}
	bool flag = false;
	for(int i = 1; i < M; i++)
	{
		if(coins[i] >= 1)
		{
			coins[i]--;
			if(coins[M - i] >= 1)
			{
				flag = true;
				printf("%d %d", i, M - i);
				break;
			}
			coins[i]++;
		}
	}
	if(!flag)
	{
		printf("No Solution");
	}
	return 0;
}
