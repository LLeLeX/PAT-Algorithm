#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int inf = 0x3fffffff;
int N, K;
string start;
int weight[maxn];
map<string, int> city;
map<int, string> cityid;
int G[maxn][maxn];
vector<int> pre[maxn];
bool vis[maxn];
int d[maxn], num[maxn], w[maxn];
void dijkstra()
{
	for(int i = 0; i < N; ++i)
	{
		int u, udist, mindist = inf;
		for(int j = 0; j < N; ++j)
		{
			if(!vis[j] && d[j] < mindist)
			{
				u = j;
				udist = mindist = d[j];
			}
		}
		vis[u] = true;
		for(int v = 0; v < N; ++v)
		{
			if(!vis[v] && G[u][v])
			{
				if(udist + G[u][v] < d[v])
				{
					d[v] = udist + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(udist + G[u][v] == d[v])
				{
					num[v] += num[u];
					w[v] = max(w[v], w[u] + weight[v]);
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int> tempPath, optPath;
int optAvg = -1, tempAvg = 0, optSum = -1, tempSum = 0;
void dfs(int v)
{
	if(v == city[start])
	{
		tempPath.push_back(v);
		tempSum = 0;
		int len = tempPath.size() - 1;//把起点减去，起点happiness为0 
		for(int i = tempPath.size() - 1; i >= 0; i--)
		{
			int id = tempPath[i];
			tempSum += weight[id];
		}
		tempAvg = tempSum / len;
		if(tempSum > optSum)//首先选择最大happiness和 
		{
			optAvg = tempAvg;
			optPath = tempPath;
			optSum = tempSum;
		}
		else if(tempSum == optSum)
		{
			if(tempAvg > optAvg)//其次选择最大平均值 
			{
				optAvg = tempAvg;
				optPath = tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); ++i)
		dfs(pre[v][i]);
	tempPath.pop_back();
} 
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	cin >> start;
	city[start] = 0;
	cityid[0] = start;
	for(int i = 1; i < N; ++i)
	{
		string c;
		int w;
		cin >> c >> w;
		city[c] = i;
		cityid[i] = c;
		weight[i] = w;
	}
	for(int i = 0; i < K; ++i)
	{
		string c1, c2;
		int c;
		cin >> c1 >> c2 >> c;
		int u = city[c1];
		int v = city[c2];
		G[u][v] = G[v][u] = c;
	}
	for(int i = 0; i < N; ++i)
	{
		d[i] = inf;
	}
	d[0] = 0;
	num[0] = 1;
	dijkstra(); 
	int rom = city["ROM"];
	dfs(rom);
	printf("%d %d %d %d\n", num[rom], d[rom], optSum, optAvg);
	for(int i = optPath.size() - 1; i >= 0; i--)
	{
		int id = optPath[i];
		cout << cityid[id];
		if(i > 0)
			printf("->");
	}
	return 0;
}
