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
void inOrder(int root)//rootֻ�����±겻����ڵ� 
{
	if(root == -1)//����Ϊ�� 
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
	for(int i = 0; i < N; ++i)//��ʼ�� 
	{
		int curIndex = newNode(i);
		char l, r;//���Һ��� 
		scanf(" %c %c", &l, &r);
		if(l != '-')
		{
			int num = l - '0';
			nodes[curIndex].lchild = num;
			hashtable[num] = true;//��Ǹýڵ㲻�Ƕ������ĸ��ڵ� 
		}
		if(r != '-')
		{
			int num = r - '0'; 
			nodes[curIndex].rchild = num;
			hashtable[num] = true;
		}
	}
	//Ѱ�Ҷ������ĸ��ڵ� 
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
	//��ת
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
