#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int G[210][210];
bool vis[210];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		G[u][v] = G[v][u] = d;
	}
	scanf("%d", &K);
	int ans = 0x3fffffff, ansindex = 0;
	for(int k = 1; k <= K; ++k)
	{
		int n, fir;
		scanf("%d", &n);
		vector<int> sub;
		memset(vis, false, sizeof(vis));
		int flag = 0;//-1:not a ts cycle; 
		for(int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			sub.push_back(x);
		}
		//���ܻص���ʼ�㣬���ܱ������е㲢�ص���ʼ�� 
		if(sub[0] != sub[sub.size() - 1] || sub.size() < N + 1)
		{
			flag = -1;
		}
		//��ʱ˵���ǻ�·�ҿ��ܱ������г��� 
		//dist:-1��ʾ�޽�,cnt��¼�����Ķ����� 
		int dist = 0, cnt = 0;
		for(int i = 0; i < n - 1; ++i)
		{
			if(dist == -1)
				continue;
			int u = sub[i];
			int v = sub[i + 1];
			if(vis[u] == false)
			{
				vis[u] = true;
				cnt++;
			}
			if(vis[v] == false)
			{
				vis[v] = true;
				cnt++;
			}
			if(G[u][v] == 0)//��������֮�䲻���ڱ� 
			{
				dist = -1;
				flag = -1;
			}
			else
			{
				dist += G[u][v]; 
			} 
		}
		if(dist == -1)
		{
			printf("Path %d: NA (Not a TS cycle)\n", k);
		} 
		else if(cnt < N || flag == -1)//û�б��������г��� 
		{
			printf("Path %d: %d (Not a TS cycle)\n", k, dist);
		}
		else if(cnt == N && n != N + 1)//���������г��У��еĳ��в�ֹһ�η���
		{
			printf("Path %d: %d (TS cycle)\n", k, dist);
			if(dist < ans)
			{
				ans = dist;
				ansindex = k;
			}
		}
		else
		{
			printf("Path %d: %d (TS simple cycle)\n", k, dist);
			if(dist < ans)
			{
				ans = dist;
				ansindex = k;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", ansindex, ans);
	return 0;
}
