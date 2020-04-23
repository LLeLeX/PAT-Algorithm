#include <bits/stdc++.h>
using namespace std;
int M, N; 
unordered_map<int, bool> mp;//标记节点是否存在 

int main(int argc, char *argv[]) {
	scanf("%d%d", &M, &N);
	vector<int> pre;//存储二叉排序树的先序遍历结果
	for(int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		mp[x] = true;
		pre.push_back(x);
	}
	while(M--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(mp[u] == false && mp[v] == true)
		{
			printf("ERROR: %d is not found.\n", u);
		} 
		else if(mp[u] == true && mp[v] == false)
		{
			printf("ERROR: %d is not found.\n", v);
		}
		else if(mp[u] == false && mp[v] == false)
		{
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else
		{
			for(int i = 0; i < pre.size(); ++i)//顺序遍历二叉排序树的先序序列
			{
				if((pre[i] < u && pre[i] > v) || (pre[i] > u && pre[i] < v))
				{
					printf("LCA of %d and %d is %d.\n", u, v, pre[i]);
					break;
				}
				if(pre[i] == u)
				{
					printf("%d is an ancestor of %d.\n", u, v);
					break;
				}
				if(pre[i] == v)
				{
					printf("%d is an ancestor of %d.\n", v, u);
					break;
				}
			}
		}
	}
	return 0;
}
