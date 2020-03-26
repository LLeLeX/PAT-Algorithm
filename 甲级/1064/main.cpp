#include <bits/stdc++.h>
using namespace std;
int N, num[1005];
vector<int> in;
struct Node{
	int data;
	int lchild, rchild;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		lchild = l;
		rchild = r;
	}
}nodes[1005];
void middleOrder(int root)
{
	if(root > N)
	{
		return;
	}
	middleOrder(nodes[root].lchild);
	in.push_back(root);
	middleOrder(nodes[root].rchild);
}
void levelOrder(int root)
{
	int cnt = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		cnt++;
		if(cnt < N)
			printf("%d ", nodes[now].data);
		else
			printf("%d", nodes[now].data);
		if(nodes[now].lchild <= N)
			q.push(nodes[now].lchild);
		if(nodes[now].rchild <= N)
			q.push(nodes[now].rchild);
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	for(int i = 1; i <= N; ++i)//根节点为1 
	{
		nodes[i].lchild = 2 * i;
		nodes[i].rchild = 2 * i + 1;
		//cout << i << " " << nodes[i].lchild << " " << nodes[i].rchild << endl;
	}
	middleOrder(1);
	for(int i = 0; i < N; ++i)
	{
		int index = in[i];
		nodes[index].data = num[i];
	}
	levelOrder(1);
	return 0;
}
