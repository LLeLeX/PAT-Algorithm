#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int N;
int pre[maxn], in[maxn];
struct Node{
	int data;
	int left, right;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		left = l;
		right = r;
	}
}nodes[maxn];
int pos;
int newNode(int x)
{
	nodes[pos] = Node(x, -1, -1);
	return pos++;
}
void recreate(int &root, int preL, int preR, int inL, int inR)
{
	if(preL > preR)
	{
		return;
	}
	root = newNode(pre[preL]);
	int k;
	for(k = inL; k < inR; ++k)
	{
		if(in[k] == pre[preL])
		{
			break;
		}
	}
	int numleft = k - inL;
	recreate(nodes[root].left, preL + 1, preL + numleft, inL, k - 1);
	recreate(nodes[root].right, preL + numleft + 1, preR, k + 1, inR);
	
}
void levelOrder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << nodes[now].data << " ";
		if(nodes[now].left != -1)
			q.push(nodes[now].left);
		if(nodes[now].right != -1)
			q.push(nodes[now].right); 
	}
}
bool isEnd = false;
void postOrder(int root)
{
	if(isEnd == true)
		return;
	if(root == -1)
		return;
	postOrder(nodes[root].left);
	postOrder(nodes[root].right);
	if(isEnd == false)
	{
		printf("%d", nodes[root].data);
		isEnd = true;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &in[i]);
	}
	int root = -1;
	recreate(root, 0, N - 1, 0, N - 1);
	postOrder(root);
	return 0;
}
