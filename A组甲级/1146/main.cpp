#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int N, M, K;
int in[maxn], temp[maxn];
int G[maxn][maxn];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = 1;
		in[v]++;//入度自增 
	}
	scanf("%d", &K);
	vector<int> ans;
	for(int i = 0; i < K; ++i)
	{
		bool cmplt = true;
		for(int j = 1; j <= N; ++j)
		{
			temp[j] = in[j];
		}
		for(int j = 0; j < N; ++j)
		{
			int u;
			scanf("%d", &u);
			if(temp[u] != 0 || cmplt == false)
			{
				cmplt = false;
				continue;
			}
			for(int v = 1; v <= N; ++v)
			{
				if(G[u][v] == 1)
					temp[v]--;
			}
		}
		if(cmplt == false)
			ans.push_back(i);
	}
	for(int i = 0; i < ans.size(); ++i)
	{
		printf("%d", ans[i]);
		if(i < ans.size() - 1)
			printf(" ");
	}
	return 0;
}
