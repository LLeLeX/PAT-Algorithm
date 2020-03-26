#include <bits/stdc++.h>
using namespace std;
int N, index;
bool hashtable[15];
vector<int> level, in;
struct Node{
	int data;
	int lchild;
	int rchild;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		lchild = l;
		rchild = r;
	}
}nodes[15];
void display()
{
	for(int i = 0; i < N; ++i)
	{
		cout << nodes[i].data << " " << nodes[i].lchild << " " << nodes[i].rchild << endl;
	}
}
int newNode(int v)
{
	nodes[index] = Node(v, -1, -1);
	return index++;
}
void inOrder(int root)//root只代表下标不代表节点 
{
	if(root == -1)//子树为空 
		return;
	inOrder(nodes[root].lchild);
	in.push_back(nodes[root].data);
	inOrder(nodes[root].rchild);
}
void levelOrder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		level.push_back(now);
		if(nodes[now].lchild != -1)
			q.push(nodes[now].lchild);
		if(nodes[now].rchild != -1)
			q.push(nodes[now].rchild);
	}
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)//初始化 
	{
		int curIndex = newNode(i);
		char l, r;//左右孩子 
		scanf(" %c %c", &l, &r);
		if(l != '-')
		{
			int num = l - '0';
			nodes[curIndex].lchild = num;
			hashtable[num] = true;//标记该节点不是二叉树的根节点 
		}
		if(r != '-')
		{
			int num = r - '0'; 
			nodes[curIndex].rchild = num;
			hashtable[num] = true;
		}
	}
	//寻找二叉树的根节点 
	int root;
	for(int i = 0; i < N; ++i)
	{
		if(!hashtable[i])
		{
			root = i;
			break;
		}
	}
	//display();
	//cout << root << endl;
	//反转
	for(int i = 0; i < N; ++i)
	{
		int temp = nodes[i].lchild;
		nodes[i].lchild = nodes[i].rchild;
		nodes[i].rchild = temp;
	} 
	levelOrder(root);
	for(int i = 0; i < N; i++)
	{
		if(i < N - 1)
			printf("%d ", level[i]);
		else
			printf("%d\n", level[i]);
	}
	inOrder(root);
	for(int i = 0; i < N; i++)
	{
		if(i < N - 1)
			printf("%d ", in[i]);
		else
			printf("%d", in[i]);
	}
	return 0;
}
