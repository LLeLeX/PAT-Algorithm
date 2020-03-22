#include <bits/stdc++.h>
using namespace std;
int weight[105];
int N, M, S, cnt;//Count:方案数 
vector<int> path;
struct Node{
	int wei;
	vector<int> child;
}nodes[105];
bool cmp(int x, int y)//先排序 
{
	return nodes[x].wei > nodes[y].wei;
}
//当前节点下标index，当前权值和sum 
void dfs(int index, int sum)
{
	path.push_back(nodes[index].wei);
	sum += nodes[index].wei; 
	//边界 
	if(sum > S)
		return;
	if(!nodes[index].child.size())//到达叶子节点 
	{
		if(sum == S)
		{
			for(int i = 0; i < path.size(); ++i)
			{
				if(i < path.size() - 1)
					printf("%d ", path[i]);
				else
					printf("%d\n", path[i]);
			}
		}
		sum = 0;
		return;
	}
	for(int i = 0; i < nodes[index].child.size(); ++i)
	{
		int child = nodes[index].child[i];
		dfs(child, sum);
		path.pop_back();
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &N, &M, &S);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &nodes[i].wei);//权值初始化 
	}
	for(int i = 0; i < M; ++i)//节点初始化 
	{
		int id, num;
		scanf("%d%d", &id, &num);
		for(int j = 0; j < num; ++j)
		{
			int childID;
			scanf("%d", &childID);
			nodes[id].child.push_back(childID);
		}
		sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
	}
	dfs(0, 0);
	return 0;
}
