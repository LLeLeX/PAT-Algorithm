#include <bits/stdc++.h>
using namespace std;
int N;
int G[55][55];
int inDegree[55];
vector<int> topo;
bool topologicalSort()
{
	topo.clear();
	stack<int> q;//此题是用栈维护的！！！！ 
	int cnt = 0;//计结点个数 
	for(int i = 0; i < N; ++i)
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
		topo.push_back(u);
		for(int v = 0; v < N; ++v)
		{
			if(G[u][v])//边存在 
			{
				inDegree[v]--;
				if(inDegree[v] == 0)
					q.push(v);
			}
		}
		cnt++;
	}
	if(cnt == N)
		return true;//是有向无环图 
	else
		return false;
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &N))
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				scanf("%d", &G[i][j]);
				if(G[i][j] == 1)
					inDegree[j]++;
			}
		}
		if(topologicalSort())
		{
			for(int i = 0; i < topo.size(); ++i)
			{
				printf("%d", topo[i]);
				if(i < topo.size() - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
		else
		{
			printf("ERROR\n");
		}
	}
	return 0;
}
