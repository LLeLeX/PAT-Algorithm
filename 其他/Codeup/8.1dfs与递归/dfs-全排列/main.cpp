#include <bits/stdc++.h>
using namespace std;
int n;
int arr[15], p[15];
vector<int> ans;
bool vis[15];
//所遍历到的当前位置 
void dfs(int index)
{
	if(index == n + 1)
	{
		for(int i = 0; i < n; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			ans.push_back(i);
			vis[i] = true;
			dfs(index + 1);
			ans.pop_back();
			vis[i] = false;
		}
	}
}
int main(int argc, char** argv) {
	while(scanf("%d", &n) != EOF)
	{
		dfs(1);
	}
	return 0;
}
