#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int N, M, C1, C2;
int team[maxn];//��Ȩ�������Ԯ����Ŀ 
int pathCnt[maxn];//���·������ 
int G[maxn][maxn];//������Ȩͼ 
int dist[maxn], t[maxn];
bool vis[maxn];
int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &team[i]);
		dist[i] = inf;
	}
	for(int i = 0; i < M; ++i)
	{
		int c1, c2, l;
		scanf("%d%d%d", &c1, &c2, &l);
		G[c1][c2] = G[c2][c1] = l;
	}
	//Dijkstra
	dist[C1] = 0;//��ʼ�� 
	t[C1] = team[C1];
	pathCnt[C1] = 1;
	for(int i = 0; i < N; ++i)
	{
		int u, udist = inf;
		for(int j = 0; j < N; ++j)//Ѱ�ҵ�ǰ���·�� 
		{
			if(!vis[j])
			{
				if(dist[j] < udist)
				{
					u = j;
					udist = dist[j];
				}
			}
		}
		vis[u] = true;
		for(int v = 0; v < N; ++v)
		{
			if(!vis[v] && G[u][v])
			{
				if(udist + G[u][v] < dist[v])//���� 
				{
					dist[v] = udist + G[u][v];//������̾��� 
					t[v] = t[u] + team[v];//���µ�Ȩ
					pathCnt[v] = pathCnt[u];//����·����Ŀ 
				}
				else if(udist + G[u][v] == dist[v])
				{
					if(t[u] + team[v] > t[v])
						t[v] = t[u] + team[v];
					pathCnt[v] += pathCnt[u];
				}
			}
		}
	}
	printf("%d %d", pathCnt[C2], t[C2]);
	return 0;
}
