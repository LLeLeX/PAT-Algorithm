#include <bits/stdc++.h>
using namespace std;
int K;
int arr[110];
bool vis[500];
void compute(int n)
{
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n /= 2;
			vis[n] = true;
		}
		else
		{
			n = (3 * n + 1) / 2;
			vis[n] = true;
		}
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &K);
	for(int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
		compute(arr[i]);
	}	
	bool flag = false;
	sort(arr, arr + K, cmp);
	for(int i = 0; i < K; i++)
	{
		int index = arr[i];
		if(!vis[index] && !flag)
		{
			printf("%d", arr[i]);
			flag = true;
		}
		else if(!vis[index] && flag)
		{
			printf(" %d", arr[i]);
		}
	}
	return 0;
}
