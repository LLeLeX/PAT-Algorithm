#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int n, m, diff = INF;
int sum[100005];
//查找第一个大于key的值 
int upperbound(int left, int right, int key)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	/*for(int i = 1; i <= n; i++)
	{
		cout << sum[i] << " ";
	}*/
	for(int i = 1; i <= n; i++)
	{
		int pos = upperbound(i, n + 1, sum[i - 1] + m);//pos为第一个大于sum[i] + m的下标
		if(sum[pos - 1] - sum[i - 1] == m)//sum[pos]大于sum[i] + m 
		{//此时验证sum[pos - 1] 是否等于 sum[i] + m 
			diff = m;
			break;
		} 
		else if(pos <= n && sum[pos] - sum[i - 1] < diff)//若无刚好相等的，则取最小值 
		{
			diff = sum[pos] - sum[i - 1];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int pos = upperbound(i, n + 1, sum[i - 1] + diff);
		if(sum[pos - 1] - sum[i - 1] == diff)
		{
			printf("%d-%d\n", i, pos - 1);
		}
	}
	return 0;
}
