#include <bits/stdc++.h>
using namespace std;
int N, M;
int coins[100005];
int binarySearch(int left, int right, int x)
{
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(coins[mid] == x)
		{
			return mid;
		}
		else if(coins[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + N);
	bool flag = false;
	for(int i = 0; i < N; i++)
	{
		int temp = binarySearch(i + 1, N - 1, M - coins[i]);
		if(temp == i)
		{
			continue;
		}
		else if(temp == -1)
		{
			continue;
		}
		else
		{
			printf("%d %d", coins[i], coins[temp]);
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		printf("No Solution");
	}
	return 0;
}
