#include <bits/stdc++.h>
using namespace std;
int K;
int pre[35];
bool istree;//判断是否为红黑树 
struct Node{
	int data;
	int left, right;
	bool isred;
	Node(){}
	Node(int dd, int ll, int rr)
	{
		data = dd;
		left = ll;
		right = rr;
	}
}nodes[35]; 
int pos;
int newNode(int x)
{
	nodes[pos] = Node(abs(x), -1, -1);
	if(x < 0)
		nodes[pos].isred = true;
	else
		nodes[pos].isred = false;
	return pos++;
} 
void insert(int &root, int x)
{
	int temp = abs(x);
	if(root == -1)
	{
		root = newNode(x);
		return;
	}
	if(nodes[root].data > temp)
	{
		insert(nodes[root].left, x);
	}
	else
	{
		insert(nodes[root].right, x);
	}
}

bool levelOrder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		//cout << nodes[now].data << " ";
		int ll = nodes[now].left;
		int rr = nodes[now].right;
		bool rootisred = nodes[now].isred;
		if(ll != -1)
		{
			q.push(ll);
			if(rootisred == true && nodes[ll].isred == true)
				return false;//判断红节点的子节点是否为黑节点 
		}
		if(rr != -1)
		{
			q.push(rr);
			if(rootisred == true && nodes[rr].isred == true)
				return false;
		}
	}
	return true;
}

int optStep = -1;
bool isfirst = true;
void dfs(int root, int step)
{
	if(root == -1)
	{
		if(istree == true)
		{
			if(optStep == -1)
				optStep = step;
			else if(optStep != step)
				istree = false;
		} 
		return;
	}
	if(nodes[root].isred == false)//统计路径上黑节点个数 
		step++;
	dfs(nodes[root].left, step);
	dfs(nodes[root].right, step);
} 


int main(int argc, char *argv[]) {
	scanf("%d", &K);
	while(K--)
	{
		int N;
		istree = true;//是否是红黑树 
		scanf("%d", &N);
		int root = -1;//初始化根节点
		memset(pre, 0, sizeof(pre));
		pos = 0;
		for(int i = 0; i < 35; ++i)
		{
			nodes[i] = Node(0, 0, 0);
		}
		 
		for(int i = 0; i < N; ++i)
		{ 
			scanf("%d", &pre[i]);
			insert(root, pre[i]);
		}
		if(pre[0] < 0)//根节点不为黑色 
		{
			printf("No\n");
			continue;
		}
		istree = levelOrder(root);
		if(istree == false)
		{
			printf("No\n");
			continue;
		}
		
		for(int i = 0; i < N; ++i)
		{
			optStep = -1;
			dfs(i, 0);
			if(istree == false)
				break;
		}
		
		
		if(istree == false)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}
