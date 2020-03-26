#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3fffffff;
int N, M;//N个顶点，M条边
DWORD startTime, endTime;
struct Node{
	int v;
	int dist;
	Node(){}
	Node(int vv, int dd)
	{
		v = vv;
		dist = dd;
	}
};
vector<Node> G[maxn];//有向有权边 
bool vis[maxn];
int d[maxn];//存储最短距离 
void init()
{
	for(int i = 0; i < N; ++i)
	{
		vis[i] = false;
		d[i] = inf;
	}
}
//源点s 
void Dijkstra(int s)
{
	init();
	d[s] = 0;
	for(int i = 0; i < N; ++i)
	{
		int u, udist, mindist = inf;
		for(int j = 0; j < N; ++j)//寻找d[]最小值 
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				udist = mindist = d[j];
			}
		}
		vis[u] = true;
		for(int k = 0; k < G[u].size(); k++)
		{
			int v = G[u][k].v;
			int vdist = G[u][k].dist;
			if(!vis[v] && udist + vdist < d[v])
			{
				d[v] = udist + vdist;
			}
		}
	} 
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;//边uv，点u与点v之间的边，权值为w
		scanf("%d%d%d", &u, &v, &w);
		Node node = Node(v, w);
		G[u].push_back(node);
	}
	startTime = GetTickCount();
	for(int i = 0; i < N; ++i)
	{
		Dijkstra(i);
		for(int i = 0; i < N; ++i)
			printf("%d ", d[i]);
		printf("\n");
	}
	endTime = GetTickCount();
	cout << endTime - startTime << "ms" << endl;
	return 0;
}
