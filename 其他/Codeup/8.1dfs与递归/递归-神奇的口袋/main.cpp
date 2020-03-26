#include <bits/stdc++.h>
using namespace std;
int n, arr[25], ans;
//index:物品下标，v：当前体积 
void dfs(int index, int v)
{
	//递归边界
	if(index > n)
		return; 
	if(v == 40)
	{
		ans++;
		return;
	}
	if(v + arr[index] <= 40)//注意！！ 
		dfs(index + 1, v + arr[index]);//放入 
	dfs(index + 1, v);//不放入 
}
int main(int argc, char *argv[]) {
	while(1)
	{
		scanf("%d", &n); 
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		dfs(0, 0);
		printf("%d\n", ans); 
	}
	return 0;
}
