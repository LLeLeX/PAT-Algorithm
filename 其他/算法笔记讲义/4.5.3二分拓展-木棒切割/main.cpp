#include <bits/stdc++.h>
using namespace std;
int N, K;
int sticks[10];
int solve(int a[], int left, int right, int k)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		int num = 0;
		for(int i = 0; i < N; i++)
		{
			num += a[i] / mid;
		}
		if(num < k)
		{
			right = mid;
		}
		else if(num >= k)
		{
			left = mid + 1;
		}
	}
	return left;
}
int main(int argc, char *argv[]) {
	printf("给出木棒的个数：\n");
	scanf("%d", &N);
	printf("输入长度:\n");
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &sticks[i]);
	}
	sort(sticks, sticks + N);
	printf("至少得到K段长度相等的木棒\n");
	printf("输入K:\n");
	scanf("%d", &K); 
	int ans = solve(sticks, 0, sticks[N - 1], K);
	printf("%d", ans - 1);
	return 0;
}
