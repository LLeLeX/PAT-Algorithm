#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int N, M, S, D;
int G[maxn][maxn];//������Ȩͼ 
int cost[maxn][maxn];
int dist[maxn];
bool vis[maxn];
vector<int> pre[maxn];//ǰ����㼯 

vector<int> tempPath, optPath;
int optValue = inf;
void dfs(int v)
{
	//�ݹ�߽� 
	if(v == S)//�Ӻ� 
	{
		tempPath.push_back(v);
		int curValue = 0;
		for(int i = tempPath.size() - 1; i > 0; i--)
		{
			//��ǰ�ڵ��±�id����һ�ڵ��±�nextid
			//id-nextid֮��Ϊ��Ȩ 
			int id = tempPath[i], nextid = tempPath[i - 1];
			curValue += cost[id][nextid];
		} 
		if(curValue < optValue)
		{
			optValue = curValue;
			optPath = tempPath;
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
	}
	dist[S] = 0;
	//Dijkstra
	for(int i = 0; i < N; ++i)
	{
		int u, udist, min = inf;
		for(int j = 0; j < N; ++j)//Ѱ����̾��� 
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
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(udist + G[u][v] == dist[v])
				{
					pre[v].push_back(u);
				} 
			}
		} 
	}
	dfs(D);
	for(int i = optPath.size() - 1; i >= 0; i--)
	{
		printf("%d ", optPath[i]);
	}
	printf("%d %d", dist[D], optValue);
	return 0;
}
