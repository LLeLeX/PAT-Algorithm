#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;
int num[25];
bool isPrime(int x)
{
	int sqr = (int)sqrt(1.0 * x);
	for(int i = 2; i <= sqr; i++)
	{
		if(x % i == 0)
			return false;//������ 
	}
	return true;//���� 
}
//index:��ǰnum���±꣬nowK����ǰ������sum����ǰ�� 
void dfs(int index, int nowK, int sum)
{
	//�����ĸ�������ݹ�߽� 
	if(index > n)//!!˳�� 
		return;
	//����Ӻ͵ĸ�������ݹ�߽� 
	if(nowK == k)
	{
		if(isPrime(sum))
		{
			cnt++;
		}
		return;
	} 
	
	//�ݹ���
	dfs(index + 1, nowK + 1, sum + num[index]);//����
	dfs(index + 1, nowK, sum);//������ 
}
int main() {
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		dfs(0, 0, 0);
		printf("%d\n", cnt);
	} 
	return 0;
}
