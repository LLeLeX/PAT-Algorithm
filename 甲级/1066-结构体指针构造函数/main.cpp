#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v;
	int height;
	node*lchild, *rchild;
	node(){}
	node(int x):v(x),height(1),lchild(NULL),rchild(NULL){}
};
int getHeight(node*root)
{
	if (!root)return 0;
	return root->height;
}//获得高度
int getBalanceFactor(node*root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}//获得平衡因子
void updateHeight(node*&root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void L(node*&root)
{
	node*temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node*&root)
{
	node*temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node*&root, int x)
{
	if (!root)
	{
		root = new node(x);
		return;
	}
	if (x < root->v)
	{
		insert(root->lchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == 2)//确定树形
		{
			if (getBalanceFactor(root->lchild) == 1)
			{
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2)//确定树形
		{
			if (getBalanceFactor(root->rchild) == -1)
			{
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	int x;
	node*root = NULL;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		insert(root, x);
	}
	printf("%d\n", root->v);
	return 0;
}
