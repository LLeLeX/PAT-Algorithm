#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int N, M, K;
vector<int> G[maxn];
int color[maxn];
set<int> cnt;
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d", &K);
	while(K--)
	{
		bool flag = true;
		cnt.clear();
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &color[i]);
			cnt.insert(color[i]);
		}
		for(int u = 0; u < N; ++u)
		{
			if(flag == false)
				break;
			for(int j = 0; j < G[u].size(); ++j)
			{
				if(flag == false)
					break;
				int v = G[u][j];
				if(color[u] == color[v])
					flag = false;
			}
		}
		
		if(flag == false)
			printf("No\n");
		else
			printf("%d-coloring\n", cnt.size());
	}
	return 0;
}
