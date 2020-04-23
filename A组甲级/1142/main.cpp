#include <bits/stdc++.h>
using namespace std;
int Nv, Ne, M;
int G[210][210];
int vis[210];
int main(int argc, char *argv[]) {
	scanf("%d%d", &Nv, &Ne);
	for(int i = 1; i <= Nv; ++i)
	{
		G[i][i] = 1;//初始化图 
	}
	for(int i = 0; i < Ne; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
/*	for(int i = 1; i <= 8; ++i)
	{
		for(int j = 1; j <= 8; ++j)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	} */
	scanf("%d", &M);
	while(M--)
	{
		int K;
		scanf("%d", &K);
		vector<int> vec;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < K; ++i)
		{
			int u;
			scanf("%d", &u);
			vec.push_back(u);
			for(int v = 1; v <= Nv; ++v)
			{
				if(G[u][v] == 1)
					vis[v]++;
			}
		}
		int flag = -1;//初始化 
		for(int i = 0; i < K; ++i)
		{
			int u = vec[i];
			if(vis[u] != K)//不是clique 
				flag = 0;
		}
		if(flag == 0)
		{
			printf("Not a Clique\n");
			continue;
		}
		int count = 0;
		for(int i = 1; i <= Nv; ++i)
		{
			if(vis[i] == K)
				count++;
		}
		if(count == K)
			printf("Yes\n");
		else
			printf("Not Maximal\n");
		
		/*for(int i = 1; i <= 8; ++i)
		{
			cout << vis[i] << " ";
		}
		cout << endl;*/
	}
	 
	return 0;
}
