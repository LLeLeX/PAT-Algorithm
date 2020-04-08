#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N;
struct Node{
	int data;
	int left, right;
	int level;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		left = l;
		right = r;
	}
}nodes[maxn];
//关于静态二叉树 
int pos, root = -1;
int newNode(int x)//新建节点 
{
	nodes[pos] = Node(x, -1, -1);
	return pos++;
}
//root:根节点引用，x：要插入的数据 
void insert(int &root, int x)//插入 
{
	//递归边界
	if(root == -1)
	{
		root = newNode(x);
		return;
	} 
	//小于等于根节点 
	if(x <= nodes[root].data)
	{
		insert(nodes[root].left, x);
	}
	else
	{
		insert(nodes[root].right, x);
	}
}
//层序遍历 
int levelcnt[maxn];//记录每层节点个数 
int maxlevel;//记录最大层数 
void levelOrder()
{
	queue<int> q;
	q.push(root);
	nodes[root].level = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		levelcnt[nodes[now].level]++;
		maxlevel = max(maxlevel, nodes[now].level);
		//cout << nodes[now].data << " " << nodes[now].level << endl;
		if(nodes[now].left != -1)
		{
			q.push(nodes[now].left);
			nodes[nodes[now].left].level = nodes[now].level + 1;
		}
		if(nodes[now].right != -1)
		{
			q.push(nodes[now].right);
			nodes[nodes[now].right].level = nodes[now].level + 1;
		}
	}		
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int data;
		scanf("%d", &data);
		insert(root, data);
	}
	levelOrder();
	int a = levelcnt[maxlevel];
	int b = levelcnt[maxlevel - 1];
	printf("%d + %d = %d", a, b, a + b);
	
	return 0;
}
