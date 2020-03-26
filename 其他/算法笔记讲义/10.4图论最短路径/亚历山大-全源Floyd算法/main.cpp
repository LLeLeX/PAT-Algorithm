#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3fffffff;
int N, M;//N个顶点，M条边
DWORD startTime, endTime;
struct Node{
	int v;
	int dist;
	Node(){}
	Node(int vv, int dd)
	{
		v = vv;
		dist = dd;
	}
};
vector<Node> G[maxn];//有向有权边 
int d[maxn][maxn];//存储最短距离 
//源点s 
void Floyd()
{
	for(int k = 0; k < N; ++k)
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				if(d[i][k] != inf && d[k][j] != inf && d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j  < N; ++j)
		{
			d[i][j] = inf;
		}
	}
	for(int i = 0; i < N; i++)
	{
		d[i][i] = 0;//顶点i到顶点i的距离是0 
	}
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		d[u][v] = w;
	}
	
	startTime = GetTickCount();
	Floyd();
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	endTime = GetTickCount();
	cout << endTime - startTime << "ms" << endl;
	return 0;
}

