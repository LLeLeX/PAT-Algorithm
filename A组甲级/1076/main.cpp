#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N, L;
int G[maxn][maxn];//有向无权图 
bool inq[maxn];
struct Node{
	int index;
	int level;
	Node(){}
	Node(int id, int l)
	{
		index = id;
		level = l;
	}
};
//起始顶点，层数 
int bfs(int v, int level)
{
	Node node = Node(v, 0);
	int count = 0;
	queue<Node> q;
	q.push(node);
	inq[v] = true;
	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		if(now.level == L)
			continue;
		for(int i = 1; i <= N; ++i)
		{
			if(G[i][now.index] && !inq[i])//有边 
			{
				count++;
				Node temp = Node(i, now.level + 1);
				q.push(temp);
				inq[i] = true;
			}
		}
	} 
	return count;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &L);
	for(int i = 1; i <= N; ++i)//第i个用户 
	{
		int m;
		scanf("%d", &m);
		for(int j = 1; j <= m; ++j)
		{
			int v;
			scanf("%d", &v);
			G[i][v] = 1; 
		}
	}
	int K;
	scanf("%d", &K);
	while(K--)
	{
		int query;
		scanf("%d", &query);
		memset(inq, false, sizeof(inq));
		int ans = bfs(query, 0);
		printf("%d\n", ans);
	}
	/*for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
