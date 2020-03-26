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
			return false;//非素数 
	}
	return true;//素数 
}
//index:当前num的下标，nowK：当前个数，sum：当前和 
void dfs(int index, int nowK, int sum)
{
	//遍历的个数满足递归边界 
	if(index > n)//!!顺序 
		return;
	//参与加和的个数满足递归边界 
	if(nowK == k)
	{
		if(isPrime(sum))
		{
			cnt++;
		}
		return;
	} 
	
	//递归体
	dfs(index + 1, nowK + 1, sum + num[index]);//放入
	dfs(index + 1, nowK, sum);//不放入 
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
