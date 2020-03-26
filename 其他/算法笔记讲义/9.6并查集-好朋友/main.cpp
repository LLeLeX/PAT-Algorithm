#include <bits/stdc++.h>
using namespace std;
bool vis[105];
int root[105];
int n, m;
int findRoot(int x)
{
	/*if(x == root[x])//递归边界，找到根节点 
		return x;
	else//递归寻找根节点 
	{
		int r = findRoot(root[x]);//r存储根节点 
		root[x] = r;//回溯将路径上的所有根节点赋值为r 
		return r; //返回根节点 
	}*/
	int a = x;
	while(x != root[x])
		x = root[x];
	while(a != root[a])
	{
		int z = a;
		a = root[a];
		root[z] = x;
	}
	return x;
}
void unionRoot(int x, int y)
{
	int rx = findRoot(x);
	int ry = findRoot(y);
	if(rx != ry)
		root[rx] = ry;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)//从下标1开始 
		root[i] = i;
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		unionRoot(a, b);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		//int r = findRoot(i);
		if(!vis[root[i]])//新的根节点即新集合 
		{ 
			ans++;
			vis[root[i]] = true; 
		} 
		else//属于已存在的集合 
			continue;
	}
	printf("%d", ans);
	return 0;
}
