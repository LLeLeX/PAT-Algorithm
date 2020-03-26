#include <bits/stdc++.h>
using namespace std;
int n, V, w[10], c[10];//n件物品，背包容量V，每件物品重量w[i]，每件物品价值c[i]
int maxValue;//记录过程中的最大价值 
void dfs(int index, int sumW, int sumC)
{
	if(index == n)//已经把n件物品处理完毕 
	{
		return;
	}
	dfs(index + 1, sumW, sumC);//不放这件物品
	if(sumW + w[index] <= V)
	{
		if(sumC + c[index] > maxValue)
			maxValue = sumC + c[index];
		dfs(index + 1, sumW + w[index], sumC + c[index]);//放这件物品 
	}	
}
int main(int argc, char** argv) {
	scanf("%d%d", &n, &V);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &w[i]); 
	} 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	dfs(0, 0, 0);
	printf("C:%d\n", maxValue);
	return 0;
}
