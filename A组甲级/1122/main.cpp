#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int G[205][205];
bool vis[205]; 
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i <M; ++i)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	scanf("%d", &K);
	while(K--)
	{
		bool isHami = true;//����Ƿ��ǹ��ܶٻ�· 
		int num;
		scanf("%d", &num);
		vector<int> cycle;
		for(int i = 0; i < num; ++i)
		{
			int v;
			scanf("%d", &v);
			cycle.push_back(v);
		}
		if(cycle[0] != cycle[num - 1])//���ǻ�· 
			isHami = false;
		else if(num != N + 1)
			isHami = false;
		else
		{
			memset(vis, false, sizeof(vis));//��ʼ�� 
			for(int i = 1; i < num; ++i)
			{
				int u = cycle[i];
				int v = cycle[i - 1]; 
				//û��ͨ·���Ѿ����ʹ��� 
				if(G[u][v] == 0 || vis[u] == true)
				{
					isHami = false;
					break; 
				}
				vis[u] = true;
			}
		}
		if(isHami == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
