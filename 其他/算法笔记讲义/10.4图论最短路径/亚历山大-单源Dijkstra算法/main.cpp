//����ɽ�������� 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 0x3fffffff;
int N, M, start;//N�����㣬M����, start��� 
int G[maxn][maxn];//������Ȩ�� 
bool vis[maxn];
int dis[maxn];//�洢��̾��� 
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &M, &start);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;//��uv����u���v֮��ıߣ�ȨֵΪw
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = w;
	}
	//���±�0��ʼ����ʼ��dis[0] = 0 
	for(int i = 1; i < N; ++i)
	{
		dis[i] = inf;//��ʼ����̾��� 
	}
	//����ڽӾ���
	 
	/*for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}*/
	//Dijkstra
	for(int i = 1; i <= N; ++i)//��n��������ѭ�� 
	{
		int now, nowdis = inf;//��¼��С����±꣬����С�ľ��� 
		for(int j = 0; j < N; ++j)//Ѱ��dis[]��С�ĵ� 
		{
			if(!vis[j])//δ�����ʹ� 
			{
				if(dis[j] < nowdis)//�ȽϾ����ҳ���С�ĵ� 
				{
					now = j;
					nowdis = dis[j];
				}
			}
		}
		vis[now] = true;//���Ϊ�ѷ���
		for(int k = 0; k < N; ++k)//������now���ڵĵ� 
		{
			if(!vis[k] && G[now][k] && nowdis + G[now][k] < dis[k])
			{
				dis[k] = nowdis + G[now][k];
			}
		} 
	} 
	
	for(int i = 0; i < N; ++i)
	{
		cout << dis[i] << " ";
	}
	return 0;
}
