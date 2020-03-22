#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int Cmax, N, Sp, M;
int weight[maxn];//当前顶点自行车个数 
bool vis[maxn];
int G[maxn][maxn];
int d[maxn];
vector<int> pre[maxn];
void Dijkstra()
{
	for(int i = 0; i <= N; ++i)
	{
		int u, udist, mindist = inf;
		for(int j = 0; j <= N; ++j)//寻找最短距离 
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				udist = mindist = d[j];
			}
		}
		vis[u] = true;
		for(int v = 0; v <= N; ++v)
		{
			if(!vis[v] && G[u][v])
			{
				if(d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int> optPath, tempPath;
int optNeed = inf, optRemain = inf;//最佳带出去，最佳带回来 
void dfs(int v)//当前顶点v 
{
	if(v == 0)//边界 
	{
		tempPath.push_back(v);
		
		//计算过程 
		int tempNeed = 0, tempRemain = 0;//当前需要带出去的，当前手上剩余的 
		for(int i = tempPath.size() - 1; i >= 0; i--)
		{
			int id = tempPath[i];
			if(weight[id] > 0)//说明是有多余的 
			{
				tempRemain += weight[id];
			}
			else//说明是不够的 
			{
				int absW = weight[id] * -1;
				if(tempRemain > absW)//手上的足以补足 
				{
					tempRemain += weight[id];
				}
				else//不足以补足，需要从起点带 
				{
					tempNeed += absW - tempRemain;
					tempRemain = 0;
				}
			}
		}
		 
			
		if(tempNeed < optNeed)//首先选择往外带最少的 
		{
			optPath = tempPath;
			optNeed = tempNeed;
			optRemain = tempRemain;
		} 
		else if(tempNeed == optNeed)
		{
			
			if(tempRemain < optRemain)//比较往回拿最少的
			{
				optPath = tempPath;
				optRemain = tempRemain;
			} 
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i)
	{
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &weight[i]);
	for(int i = 0; i < M; ++i)
	{
		int s1, s2, t;
		scanf("%d%d%d", &s1, &s2, &t);
		G[s1][s2] = G[s2][s1] = t;
	}
	//初始化 
	for(int i = 0; i <= N; ++i)//下标从0到N 
	{
		d[i] = inf;
		if(i > 0)
			weight[i] -= Cmax / 2;//把每个站点的点权都减去Cmax/2 
	}
	d[0] = 0;
	Dijkstra();
	dfs(Sp);
	printf("%d ", optNeed);
	for(int i = optPath.size() - 1; i >= 0; i--)
	{
		printf("%d", optPath[i]);
		if(i > 0)
			printf("->");
		else
			printf(" ");
	}
	printf("%d", optRemain);
	return 0;
}
