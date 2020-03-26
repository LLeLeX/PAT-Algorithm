#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int N, M;
int G[105][105];
int d[105];//顶点与集合s的最短距离 
bool vis[105];
int prim()
{
	int ans = 0;
	for(int i = 0; i < N; ++i)
	{
		int u, mindist = inf;
		for(int j = 0; j < N; ++j)
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				mindist = d[j];
			}
		}
		vis[u] = true;
		ans += d[u];
		for(int v = 0; v < N; ++v)
		{
			if(!vis[v] && G[u][v] && G[u][v] < d[v])
			{
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	for(int i = 1; i <= N; ++i)
	{
		d[i] = inf;
	}
	d[0] = 0;
	cout << prim();
	return 0;
}
