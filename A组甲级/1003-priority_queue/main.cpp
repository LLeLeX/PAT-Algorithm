#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3fffffff;
int N, M, C1, C2;
int team[maxn];//��Ȩ�������Ԯ����Ŀ 
int pathCnt[maxn];//���·������ 
int G[maxn][maxn];//������Ȩͼ 
int dist[maxn], t[maxn];//��̾���dist������Ա��Ŀt 
bool vis[maxn];
struct Node{
	int index;//���� 
	int dist;//��̾��� 
	Node(){}
	Node(int id, int dd)
	{
		index = id;
		dist = dd;
	}
	friend bool operator < (Node n1, Node n2)//����������������ȶ��������� 
	{
		if(n1.dist != n2.dist)
			return n1.dist > n2.dist;
		else
			return n1.index > n2.index;
	}
}node;
priority_queue<Node> q;//���ȶ��б��ڲ�����̾��� 
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
	//��ʼ�� 
	dist[C1] = 0;
	t[C1] = team[C1];
	pathCnt[C1] = 1;
	node = Node(C1, dist[C1]);
	q.push(node);
	//Dijkstra 
	while(!q.empty())
	{
		Node now = q.top();
		q.pop();//ɾ������Ԫ�� 
		int u = now.index;
		int udist = now.dist;
		if(vis[u])//���� udist + G[u][v] == dist[v]������q.push(node)��������Ԫ�ػ��ظ� 
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
					q.push(node);//���º�Ľڵ���� 
				}
				else if(udist + G[u][v] == dist[v])
				{
					t[v] = max(t[v], t[u] + team[v]);
					pathCnt[v] += pathCnt[u];
					/*node = Node(v, dist[v]);//���Ϻ���Ҫ��ѭ�����ж��Ƿ񱻷��� 
					q.push(node);*/
				}
			}
		}
	}
	printf("%d %d", pathCnt[C2], t[C2]);
	return 0;
}
