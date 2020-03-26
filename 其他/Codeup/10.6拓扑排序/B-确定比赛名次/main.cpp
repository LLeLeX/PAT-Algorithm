#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int N, M;
int G[maxn][maxn];
int inDegree[maxn];
vector<int> ans; 
void topological()
{
	priority_queue<int, vector<int>, greater<int> > q;
	int cnt = 0;
	for(int i = 1; i <= N; ++i)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.top();
		q.pop();
		if(cnt < N - 1)
			printf("%d ", u);
		else
			printf("%d\n", u);
		ans.push_back(u);
		for(int v = 1; v <= N; ++v)
		{
			if(G[u][v] == 1)
			{
				inDegree[v]--;
				if(inDegree[v] == 0)
				{
					q.push(v);
				}
			}
		}
		cnt++;
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d%d", &N, &M))
	{
		if(M == 0 || N == 0)
			break;
		memset(inDegree, 0, sizeof(inDegree));
		memset(G, 0, sizeof(G));//差一个初始化图G 
		for(int i = 0; i < M; ++i)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			G[p1][p2] = 1;
			inDegree[p2]++;
		}
		//ans.clear();
		topological();
		/*for(int i = 0; i < ans.size(); ++i)
		{
			printf("%d", ans[i]);
			if(i < ans.size() - 1)
				printf(" ");
			else
				printf("\n");
		}*/
	}
	return 0;
}
