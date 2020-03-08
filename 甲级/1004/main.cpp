#include <bits/stdc++.h>
using namespace std;
int N, M, maxLevel = -1;
int leafs[105]; 
struct Node{
	int level;
	vector<int> child;
}nodes[105];
void bfs()
{
	queue<int> q;
	q.push(1);
	nodes[1].level = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		maxLevel = max(nodes[now].level, maxLevel);
		if(!nodes[now].child.size())//р╤вс╫з╣Ц
		{
			leafs[nodes[now].level]++;
		} 
		for(int i = 0; i < nodes[now].child.size(); ++i)
		{
			int child = nodes[now].child[i];
			nodes[child].level = nodes[now].level + 1;
			q.push(child);
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	if(N == 1)
	{
		printf("1");
	}
	else
	{
		for(int i = 0; i < M; ++i)
		{
			int id, num;
			scanf("%d%d", &id, &num);
			for(int j = 0; j < num; j++)
			{
				int childID;
				scanf("%d", &childID);
				nodes[id].child.push_back(childID);
			}
		}
		bfs();
		for(int i = 0; i <= maxLevel; i++)
		{
			if(i <= maxLevel - 1)
				printf("%d ", leafs[i]);
			else
				printf("%d", leafs[i]);
		}
	}
	return 0;
}
