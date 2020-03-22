#include <bits/stdc++.h>
using namespace std;
int n, m;
int coins[100005];
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + n);
	int left = 0, right = n - 1;
	bool cmplt = false;
	while(left < right)
	{
		if(coins[left] + coins[right] == m)
		{
			printf("%d %d", coins[left], coins[right]);
			cmplt = true;
			break;
		}
		else if(coins[left] + coins[right] > m)
		{
			right--;
		}
		else if(coins[left] + coins[right] < m)
		{
			left++;
		}
	}
	if(!cmplt)
	{
		printf("No Solution");
	}
	return 0;
}
