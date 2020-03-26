#include <bits/stdc++.h>
using namespace std;
int N;
struct Node{
	int data, height;
	Node* lchild;
	Node* rchild;
};
Node* newNode(int v)
{
	Node* node = new Node;
	node->data = v;
	node->height = 1;
	node->lchild = node->rchild = NULL;
	return node;
}
int getHeight(Node* root)
{
	if(root == NULL)
		return 0;
	return root->height;
}
int getBF(Node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void update(Node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void R_rotation(Node* &root)
{
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	update(root);
	update(temp);
	root = temp;
}
void L_rotation(Node* &root)
{
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	update(root);
	update(temp);
	root = temp;
}
void insert(Node* &root, int v)
{
	if(root == NULL)
	{
		root = newNode(v);
		return; 
	}
	if(v < root->data)
	{
		insert(root->lchild, v);
		update(root);
		if(getBF(root) == 2)
		{
			if(getBF(root->lchild) == 1)
			{
				R_rotation(root);
			}
			else if(getBF(root->lchild) == -1)
			{
				L_rotation(root->lchild);
				R_rotation(root);
			}
		}
	}
	else
	{
		insert(root->rchild, v);
		update(root);
		if(getBF(root) == -2)
		{
			if(getBF(root->rchild) == -1)
			{
				L_rotation(root);
			}
			else if(getBF(root->rchild) == 1)
			{
				R_rotation(root->rchild);
				L_rotation(root);
			}
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	Node* root = NULL;
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		insert(root, num);
	}
	printf("%d", root->data);
	return 0;
}
