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
//���ھ�̬������ 
int pos, root = -1;
int newNode(int x)//�½��ڵ� 
{
	nodes[pos] = Node(x, -1, -1);
	return pos++;
}
//root:���ڵ����ã�x��Ҫ��������� 
void insert(int &root, int x)//���� 
{
	//�ݹ�߽�
	if(root == -1)
	{
		root = newNode(x);
		return;
	} 
	//С�ڵ��ڸ��ڵ� 
	if(x <= nodes[root].data)
	{
		insert(nodes[root].left, x);
	}
	else
	{
		insert(nodes[root].right, x);
	}
}
//������� 
int levelcnt[maxn];//��¼ÿ��ڵ���� 
int maxlevel;//��¼������ 
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
