#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int n, m, diff = INF;
int sum[100005];
//���ҵ�һ������key��ֵ 
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
		int pos = upperbound(i, n + 1, sum[i - 1] + m);//posΪ��һ������sum[i] + m���±�
		if(sum[pos - 1] - sum[i - 1] == m)//sum[pos]����sum[i] + m 
		{//��ʱ��֤sum[pos - 1] �Ƿ���� sum[i] + m 
			diff = m;
			break;
		} 
		else if(pos <= n && sum[pos] - sum[i - 1] < diff)//���޸պ���ȵģ���ȡ��Сֵ 
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
