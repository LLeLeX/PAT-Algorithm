#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int N, M, S, E;
int G[505][505];//length
int Time[505][505];
bool visD[505], visT[505]; 
vector<int> preD[505], preT[505];//路径前驱 
int d[505], t[505];//最短路径d，最短时间t 
void init()
{
	for(int i = 0; i < 505; ++i)
	{
		d[i] = inf;
		t[i] = inf;
	} 
	d[S] = 0;
	t[S] = 0;
}
void Dijkstra()
{
	for(int i = 0; i < N; ++i)
	{
		//找出当前最短距 
		int u, du = inf;
		for(int j = 0; j < N; ++j)
		{
			if(d[j] < du && visD[j] == false)
			{
				u = j;
				du = d[j];
			}
		}
		//找出当前最短时间
		int w, tw = inf;
		for(int j = 0; j < N; ++j)
		{
			if(t[j] < tw && visT[j] == false)
			{
				w = j;
				tw = t[j];
			}
		}
		visD[u] = true; //标记已访问 
		visT[w] = true;
		for(int v = 0; v < N; ++v)
		{
			if(G[u][v] != 0 && visD[v] == false)//边存在 
			{
				if(d[u] + G[u][v] < d[v])//距离更短 
				{
					d[v] = d[u] + G[u][v];
					preD[v].clear();
					preD[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v]) 
				{
					preD[v].push_back(u);
				}
			}
		}	
		for(int v = 0; v < N; ++v)
		{
			if(Time[w][v] != 0 && visT[v] == false)
			{
				if(t[w] + Time[w][v] < t[v])
				{
					t[v] = t[w] + Time[w][v];
					preT[v].clear();
					preT[v].push_back(w);
				}
				else if(t[w] + Time[w][v] == t[v])
				{
					preT[v].push_back(w);
				}
			}
		}		
	}
}
vector<int> tempPath, optPath;
int tempValue, optValue = inf;
void dfsD(int v)
{
	if(v == S)//回到起点，即递归边界 
	{
		tempPath.push_back(v);//此时得到一条完整的最短路径 
		tempValue = 0;
		//计算边权（最短路长度相同选择最快的） 
		for(int i = tempPath.size() - 1; i > 0; --i)
		{
			int id = tempPath[i], nextid = tempPath[i - 1];
			tempValue += Time[id][nextid];
		}
		if(tempValue < optValue)//保存最佳路径 
		{
			optValue = tempValue;
			optPath = tempPath;
		}
		tempPath.pop_back();
		return; 	
	}
	tempPath.push_back(v);
	for(int i = 0; i < preD[v].size(); ++i)
	{
		dfsD(preD[v][i]);
	}
	tempPath.pop_back();
}

vector<int> tempTimePath, optTimePath;
int tempNum, optNum = inf;
void dfsT(int v)
{
	if(v == S)
	{
		tempTimePath.push_back(v);
		//计算节点个数最少的路径
		tempNum = tempTimePath.size();
		if(tempNum < optNum)
		{
			optNum = tempNum;
			optTimePath = tempTimePath;
		} 
		tempTimePath.pop_back();
		return;
	}
	tempTimePath.push_back(v);
	for(int i = 0; i < preT[v].size(); ++i)
	{
		dfsT(preT[v][i]);
	}
	tempTimePath.pop_back();
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int v1, v2, way, length, time;
		scanf("%d%d%d%d%d", &v1, &v2, &way, &length, &time);
		if(way == 1)//单行 
		{
			G[v1][v2] = length;
			Time[v1][v2] = time; 
		}
		else//双向 
		{
			G[v1][v2] = G[v2][v1] = length;
			Time[v1][v2] = Time[v2][v1] = time;
		}
	}
	scanf("%d%d", &S, &E);
	init();
	Dijkstra();	
	dfsD(E);
	dfsT(E);
	if(optTimePath == optPath)//两条路径相同 
	{
		printf("Distance = %d; Time = %d: ", d[E], t[E]);
		for(int i = optPath.size() - 1; i >= 0; --i)
		{
			printf("%d", optPath[i]);
			if(i > 0)
				printf(" -> ");
		}
	}
	else
	{
		printf("Distance = %d: ", d[E]);
		for(int i = optPath.size() - 1; i >= 0; --i)
		{
			printf("%d", optPath[i]);
			if(i > 0)
				printf(" -> ");
			else
				printf("\n");
		}
		printf("Time = %d: ", t[E]);
		for(int i = optTimePath.size() - 1; i >= 0; --i)
		{
			printf("%d", optTimePath[i]);
			if(i > 0)
				printf(" -> ");
			else
				printf("\n");
		}
	}	
	return 0;
}
