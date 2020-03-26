#include <bits/stdc++.h>
using namespace std;
int n, k;
int num[505];
bool flag;
struct Node{
	int data;
	int height;
	Node* lchild;
	Node* rchild;
}root;
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
void L_rotation(Node* &root)
{
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	update(root);
	update(temp);
	root = temp; 
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
void insert(Node* &root, int v)
{
	if(root == NULL)
	{
		root = newNode(v);
		return;
	}
	if(v < root->data)//Íù×ó×ß 
	{
		insert(root->lchild, v);
		update(root);
		if(getBF(root) == 2)
		{
			if(getBF(root->lchild) == 1)
				R_rotation(root);
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
void search(Node* root, int v)
{
	if(root == NULL)
	{
		flag = false;
		return;
	}
	if(v < root->data)
		search(root->lchild, v);
	else if(v > root->data)
		search(root->rchild, v);
	else
	{
		flag = true;
		return;
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d%d", &n, &k))
	{
		Node* root = NULL;
		for(int i = 0; i < n; ++i)
		{
			int num;
			scanf("%d", &num);
			insert(root, num);
		}
		for(int i = 0; i < k; ++i)
		{
			flag = true;
			int query;
			scanf("%d", &query);
			search(root, query);
			if(!flag)
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
			if(i < k - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
