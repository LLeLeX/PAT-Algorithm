#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int h = 10000;
int N, M;
vector<int> G[10005];
unordered_map<int, int> edges;//存储原图所有边 
unordered_map<int, int> vis;//记录点集覆盖的边 
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		edges[u * h + v] = 1;//1:为有效边 
		edges[v * h + u] = 1;	
	}
	int K;
	scanf("%d", &K);
	while(K--)
	{
		vis = edges;//vis初始化 
		int num;
		scanf("%d", &num);
		for(int i = 0; i < num; ++i)
		{
			int u;
			scanf("%d", &u);
			for(int v = 0; v < G[u].size(); ++v)
			{
				int next = G[u][v];
				vis[u * h + next] = vis[next * h + u] = 2;
			}
		}
		bool flag = true;//标记是否覆盖 
		for(auto it = edges.begin(); it != edges.end(); ++it)//自动指针替代迭代器 
		{
			int key = it->first;
			int value = it->second;
			if(edges[key] == 1 && vis[key] == 1)
			{
				flag = false;
				break;
			}
		}
		if(flag == true)
			printf("Yes\n");
		else
			printf("No\n");
	} 
	return 0;
}
