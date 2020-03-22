#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int N, M, S, D;
int G[maxn][maxn];//无向有权图 
int cost[maxn][maxn];
int dist[maxn], c[maxn];
bool vis[maxn];
int pre[maxn];//前驱结点集 
vector<int> path;
void dfs(int v)
{
	if(v == S)
	{
		printf("%d ", v);
		return;
	}
	dfs(pre[v]);
	printf("%d ", v);
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for(int i = 0; i < M; ++i)
	{
		int c1, c2, d, c;
		scanf("%d%d%d%d", &c1, &c2, &d, &c);
		G[c1][c2] = G[c2][c1] = d;
		cost[c1][c2] = cost[c2][c1] = c;
	}
	for(int i = 0; i < N; ++i)
	{
		dist[i] = inf;
		c[i] = inf;
	}
	dist[S] = 0;
	c[S] = 0;
	//Dijkstra
	for(int i = 0; i < N; ++i)
	{
		int u, udist, min = inf;
		for(int j = 0; j < N; ++j)//寻找最短距离 
		{
			if(!vis[j])
			{
				if(dist[j] < min)
				{
					u = j;
					udist = min = dist[j];
				}
			}
		}
		vis[u] = true;
		for(int v = 0; v < N; ++v)
		{
			if(!vis[v] && G[u][v])
			{
				if(udist + G[u][v] < dist[v])
				{
					dist[v] = udist + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if(udist + G[u][v] == dist[v])
				{
					if(c[u] + cost[u][v] < c[v])
					{
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				} 
			}
		} 
	}
	dfs(D);
	/*for(int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d ", path[i]);
	}*/
	printf("%d %d", dist[D], c[D]);
	return 0;
}
