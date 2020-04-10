#include <bits/stdc++.h>
using namespace std;
int N, M;
int G[505][505];
int vis[505];
int degree[505];
int oddNum;
void dfs(int v)
{
	if(vis[v] == true)
		return;
	vis[v] = true;
	for(int u = 0; u <= N; ++u)
	{
		if(G[u][v] == 1)
			dfs(u);
	}
}
void bfs(int v)
{
	queue<int> q;
	q.push(v);
	vis[v] = true;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int u = 1; u <= N; ++u)
		{
			if(G[now][u] == 1 && vis[u] == false)
			{
				q.push(u);
				vis[u] = true;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
		degree[u]++;
		degree[v]++;
	}
	for(int i = 1; i <= N; ++i)
	{
		printf("%d", degree[i]);
		if(i < N)
			printf(" ");
		else
			printf("\n");
		if(degree[i] & 1 == 1)
			oddNum++;
	}
	dfs(1);
	bool isConnect = true;
	for(int i = 1; i <= N; ++i)
	{
		if(vis[i] == false)//Í¼²»Á¬Í¨ 
		{
			isConnect = false;
			break;
		}
	}
	if(isConnect == true && oddNum == 0)
		printf("Eulerian");
	else if(isConnect == true && oddNum == 2)
		printf("Semi-Eulerian");
	else
		printf("Non-Eulerian");
	return 0;
}
