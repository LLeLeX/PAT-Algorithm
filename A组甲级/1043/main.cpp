#include <bits/stdc++.h>
using namespace std;
int N, pos;
vector<int> origin, pre, post;
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
}nodes[1005];
int newNode(int v)
{
	nodes[pos] = Node(v, -1, -1);
	return pos++;
}
void insert(int &root, int v)//������������� 
{
	if(root == -1)//˵������vʧ�ܣ����ǲ���λ�� 
	{
		root = newNode(v);
		return;
	}
	if(v >= nodes[root].data)//���ڵ�����������
		insert(nodes[root].rchild, v);
	else
		insert(nodes[root].lchild, v); 
}
void preOrder(int root)//����ǰ�� 
{
	if(root == -1)
		return;
	pre.push_back(nodes[root].data);
	preOrder(nodes[root].lchild);
	preOrder(nodes[root].rchild);
} 
void mirrorPre(int root)//����ǰ�� 
{
	if(root == -1)
		return;
	pre.push_back(nodes[root].data);
	mirrorPre(nodes[root].rchild);
	mirrorPre(nodes[root].lchild);
}
void postOrder(int root)//�������� 
{
	if(root == -1)
		return;
	postOrder(nodes[root].lchild);
	postOrder(nodes[root].rchild);
	post.push_back(nodes[root].data);
}
void mirrorPost(int root)//������� 
{
	if(root == -1)
		return;
	mirrorPost(nodes[root].rchild);
	mirrorPost(nodes[root].lchild);
	post.push_back(nodes[root].data);
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int root = -1;//��Ÿ��ڵ��ַ ��ע��������Ϊ-1 
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		origin.push_back(num);
		insert(root, num);
	}
	if(origin[0] > origin[1])//���� 
	{
		preOrder(root);
		if(pre == origin)
		{
			printf("YES\n");
			postOrder(root);
			for(int i = 0; i < post.size(); ++i)
			{
				if(i < post.size() - 1)
					printf("%d ", post[i]);
				else
					printf("%d", post[i]);
			}
		}
		else
			printf("NO");
	}
	else//���� 
	{
		mirrorPre(root);
		if(pre == origin)
		{
			printf("YES\n");
			mirrorPost(root);
			for(int i = 0; i < post.size(); ++i)
			{
				if(i < post.size() - 1)
					printf("%d ", post[i]);
				else
					printf("%d", post[i]);
			}
		}
		else
			printf("NO");
	} 	
	return 0;
}
