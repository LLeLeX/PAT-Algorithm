#include <bits/stdc++.h>
using namespace std;
int weight[105];
int N, M, S, cnt;//Count:������ 
vector<int> path;
struct Node{
	int wei;
	vector<int> child;
}nodes[105];
bool cmp(int x, int y)//������ 
{
	return nodes[x].wei > nodes[y].wei;
}
//��ǰ�ڵ��±�index����ǰȨֵ��sum 
void dfs(int index, int sum)
{
	path.push_back(nodes[index].wei);
	sum += nodes[index].wei; 
	//�߽� 
	if(sum > S)
		return;
	if(!nodes[index].child.size())//����Ҷ�ӽڵ� 
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
		scanf("%d", &nodes[i].wei);//Ȩֵ��ʼ�� 
	}
	for(int i = 0; i < M; ++i)//�ڵ��ʼ�� 
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
