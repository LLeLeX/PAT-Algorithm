#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int N, K, pos = 1, maxWeight;//pos对人名做编号，maxweight记录最大的权值 
int group;//记录连通图的组数 
int G[maxn][maxn];//图 
int weight[maxn];//各顶点权值和，便于统计最大权值 
bool vis[maxn];
map<string, int> mp;//名字映射编号 
map<int, string> mpMirror;//编号映射名字 
map<string, int> gang;//组织信息 
struct Node{//头目信息 
	int index, member;
	Node(){}
	Node(int id, int m)
	{
		index = id;
		member = m;
	}
}node;


//当前顶点v，当前权值和sum，当前成员数cnt 
void dfs(int v, int &sum, int &cnt)
{
	if(vis[v])
		return;
	vis[v] = true;
	cnt = cnt + 1;//!!!访问到当前节点就进行操作，不能放在循环内 
	node.member = cnt;
	if(weight[v] > maxWeight)//当前访问的顶点权值和大于最大值 
	{
		maxWeight = weight[v];
		node.index = v;
	}
	for(int i = 1; i <= N; ++i)//与当前顶点连通的点 
	{
		if(G[v][i])//边存在 
		{ 
			sum += G[v][i]; 
			G[v][i] = 0;//删除边，防止重复访问 
			if(!vis[i]) //没访问过 
				dfs(i, sum, cnt);
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i)
	{
		string name1, name2;
		int w;
		cin >> name1 >> name2;
		scanf("%d", &w);
		if(!mp[name1])//新名字 
		{
			mp[name1] = pos;//从下标1开始
			mpMirror[pos] = name1;
			pos++;
		}
		if(!mp[name2])
		{
			mp[name2] = pos;
			mpMirror[pos] = name2;
			pos++;
		}
		int v1 = mp[name1], v2 = mp[name2];
		weight[v1] += w;
		weight[v2] += w;
		G[v1][v2] = w;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(!vis[i])
		{
			int total = 0, count = 0;
			maxWeight = -1;
			node = Node(0, 0);
			dfs(i, total, count);
			if(total > K && count > 2)
			{
				int id = node.index;//头目id 
				int member = node.member;//头目成员数 
				gang[mpMirror[id]] = member;
				group++;
			}
		}
	}
	printf("%d\n", group);
	for(map<string, int>::iterator it = gang.begin(); it != gang.end(); it++)
	{
		cout << it->first;
		printf(" %d\n", it->second);
	}
	return 0;
}
