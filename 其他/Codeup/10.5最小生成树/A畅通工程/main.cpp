#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3fffffff;
int N;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
int prim()
{
	int ans = 0;
	for(int i = 1; i <= N; ++i)
	{
		int u, mindist = inf;
		for(int j = 1; j <= N; ++j)
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				mindist = d[j];
			}
		}
		vis[u] = true;
		ans += d[u];
		for(int v = 1; v <= N; ++v)
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
	while(~scanf("%d", &N))
	{
		if(N == 0)
			break;
		memset(vis, false, sizeof(vis));
		int len = N * (N - 1) / 2;
		for(int i = 0; i < len; ++i)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u][v] = G[v][u] = w;
		}
		for(int i = 1; i <= N; ++i)
		{
			d[i] = inf;
		}
		d[1] = 0;
		printf("%d\n", prim());
	}
	return 0;
}
