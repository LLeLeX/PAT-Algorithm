//亚历山大精灵例题 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 0x3fffffff;
int N, M, start;//N个顶点，M条边, start起点 
int G[maxn][maxn];//有向有权边 
bool vis[maxn];
int dis[maxn];//存储最短距离 
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &M, &start);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;//边uv，点u与点v之间的边，权值为w
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = w;
	}
	//从下标0开始，初始化dis[0] = 0 
	for(int i = 1; i < N; ++i)
	{
		dis[i] = inf;//初始化最短距离 
	}
	//输出邻接矩阵
	 
	/*for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}*/
	//Dijkstra
	for(int i = 1; i <= N; ++i)//对n个顶点做循环 
	{
		int now, nowdis = inf;//记录最小点的下标，和最小的距离 
		for(int j = 0; j < N; ++j)//寻找dis[]最小的点 
		{
			if(!vis[j])//未被访问过 
			{
				if(dis[j] < nowdis)//比较距离找出最小的点 
				{
					now = j;
					nowdis = dis[j];
				}
			}
		}
		vis[now] = true;//标记为已访问
		for(int k = 0; k < N; ++k)//遍历与now相邻的点 
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
