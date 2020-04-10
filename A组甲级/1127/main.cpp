#include <bits/stdc++.h>
using namespace std;
int N;
int in[35], post[35];
struct Node{
	int data;
	int left, right;
	int layer;
}nodes[35];
int pos;
int newNode(int x)
{
	nodes[pos].data = x;
	nodes[pos].left = nodes[pos].right = -1;
	return pos++;
}
int recreate(int inL, int inR, int postL, int postR)
{
	if(postL > postR)//递归边界 
		return -1;
	int root = newNode(post[postR]);//新建根节点 
	int k;//在in[]中找到根节点，下标放在k中 
	for(k = inL; k <= inR; ++k)
	{
		if(in[k] == post[postR])
			break;
	}
	int numleft = k - inL;//左子树节点个数 
	nodes[root].left = recreate(inL, k - 1, postL, postL + numleft - 1);
	nodes[root].right = recreate(k + 1, inR, postL + numleft, postR - 1);
	return root;
}
deque<int> level[35];
int maxlevel = -1;
void levelOrder(int root)
{
	queue<int> q;
	q.push(root);
	nodes[root].layer = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int layer = nodes[now].layer;
		maxlevel = max(maxlevel, layer);
		if(layer & 1 == 1)
			level[layer].push_front(nodes[now].data);
		else
			level[layer].push_back(nodes[now].data);
		if(nodes[now].left != -1)
		{
			q.push(nodes[now].left);
			nodes[nodes[now].left].layer = nodes[now].layer + 1;
		}
		if(nodes[now].right != -1)
		{
			q.push(nodes[now].right);
			nodes[nodes[now].right].layer = nodes[now].layer + 1;
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &post[i]);
	}
	int root = recreate(0, N - 1, 0, N - 1);
	levelOrder(root);
	
	for(int i = 1; i <= maxlevel; ++i)
	{
		for(int j = 0; j < level[i].size(); ++j)
		{
			printf("%d", level[i][j]);
			if(i == maxlevel && j == level[i].size() - 1)
				continue;
			else
				printf(" ");
		}
	}
	return 0;
}
