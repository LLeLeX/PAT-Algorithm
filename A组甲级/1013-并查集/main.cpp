#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N, M, K;
int father[maxn];
bool vis[maxn];
vector<int> G[maxn];
void init()
{
	for(int i = 1; i <= N; ++i)
	{
		father[i] = i;
		vis[i] = false;
	}
}
int findFather(int x)
{
	if(x == father[x])
		return x;
	else
	{
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
}
void unionFather(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if(fx != fy)
		father[fx] = fy;
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < M; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[a].push_back(b);
	}
	
	while(K--)
	{
		int query;
		init();
		scanf("%d", &query);
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 0; j < G[i].size(); ++j)
			{
				int u = i, v = G[i][j];
				if(i == query || G[i][j] == query)
					continue;//略过该点，即删去
				unionFather(i, G[i][j]); 
			}
		}
		int cnt = 0;
		for(int i = 1; i <= N; ++i)
		{
			if(i == query)
				continue;
			int fi = findFather(i);
			if(!vis[fi])
			{
				vis[fi] = true;
				cnt++;
			}
			else
				continue;
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
