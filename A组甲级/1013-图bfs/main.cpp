#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N, M, K;
int G[maxn][maxn];//无向无权图 
int Gtemp[maxn][maxn];
bool inq[maxn];
//当前节点v 
void bfs(int v)
{
	queue<int> q;
	q.push(v);
	inq[v] = true;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i = 1; i <= N; ++i)
		{
			if(Gtemp[now][i] && !inq[i])
			{
				q.push(i);
				inq[i] = true;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a][b] = G[b][a] = 1;
		Gtemp[a][b] = Gtemp[b][a] = 1;
	} 
	/*for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}*/
	while(K--)//统计连通图的个数 
	{
		int query;
		scanf("%d", &query);
		memset(inq, false, sizeof(inq));
		for(int i = 1; i <= N; ++i)
		{
			Gtemp[query][i] = Gtemp[i][query] = 0;//路线切断 
		}
		int ans = 0;
		for(int i = 1; i <= N; ++i)
		{
			if(i == query)
				continue;
			if(!inq[i])
			{
				ans++;
				bfs(i);
			}	
		}
		for(int i = 1; i <= N; ++i)
		{
			Gtemp[query][i] = G[query][i];
			Gtemp[i][query] = G[i][query];
		}
		if(ans)
			printf("%d\n", ans - 1);
		else
			printf("%d\n", ans);
	}
	return 0;
}
