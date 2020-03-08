#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int N, M, C1, C2;
int team[maxn];//点权，各点救援队数目 
int pathCnt[maxn];//最短路径个数 
int G[maxn][maxn];//无向有权图 
int dist[maxn], t[maxn];//最短距离dist，最大队员数目t 
bool vis[maxn];
struct Node{
	int index;//顶点 
	int dist;//最短距离 
	Node(){}
	Node(int id, int dd)
	{
		index = id;
		dist = dd;
	}
	friend bool operator < (Node n1, Node n2)//重载运算符，在优先队列中排序 
	{
		if(n1.dist != n2.dist)
			return n1.dist > n2.dist;
		else
			return n1.index > n2.index;
	}
}node;
priority_queue<Node> q;//优先队列便于查找最短距离 
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
	//初始化 
	dist[C1] = 0;
	t[C1] = team[C1];
	pathCnt[C1] = 1;
	node = Node(C1, dist[C1]);
	q.push(node);
	//Dijkstra 
	while(!q.empty())
	{
		Node now = q.top();
		q.pop();//删除队首元素 
		int u = now.index;
		int udist = now.dist;
		if(vis[u])//若在 udist + G[u][v] == dist[v]条件中q.push(node)，队列中元素会重复 
			continue;
		vis[u] = true;
		for(int v = 0; v < N; ++v)
		{
			if(!vis[v] && G[u][v])
			{
				if(udist + G[u][v] < dist[v])
				{
					t[v] = t[u] + team[v];
					pathCnt[v] = pathCnt[u];
					dist[v] = udist + G[u][v];
					node = Node(v, dist[v]);
					q.push(node);//更新后的节点入队 
				}
				else if(udist + G[u][v] == dist[v])
				{
					t[v] = max(t[v], t[u] + team[v]);
					pathCnt[v] += pathCnt[u];
					/*node = Node(v, dist[v]);//加上后需要在循环外判断是否被访问 
					q.push(node);*/
				}
			}
		}
	}
	printf("%d %d", pathCnt[C2], t[C2]);
	return 0;
}
