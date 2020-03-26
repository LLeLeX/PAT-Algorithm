#include <bits/stdc++.h>
using namespace std;
int N;
int num[105];
vector<int> in;
struct Node{
	int data;
	int rchild;
	int lchild;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		lchild = l;
		rchild = r;
	}
}nodes[105];
void middleOrder(int root)
{
	if(root == -1)
	{
		return;
	}
	middleOrder(nodes[root].lchild);
	in.push_back(root);
	middleOrder(nodes[root].rchild);
}
void levelOrder(int root)
{
	int count = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		count++;
		if(count < N)
			printf("%d ", nodes[now].data);
		else
			printf("%d", nodes[now].data);
		if(nodes[now].lchild != -1)
			q.push(nodes[now].lchild);
		if(nodes[now].rchild != -1)
			q.push(nodes[now].rchild);
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d%d", &nodes[i].lchild, &nodes[i].rchild);
	for(int i = 0; i < N; ++i)
		scanf("%d", &num[i]);
	sort(num, num + N);
	middleOrder(0);
	for(int i = 0; i < in.size(); i++)
	{
		int index = in[i];
		nodes[index].data = num[i];
	}
	levelOrder(0);
	return 0;
}
