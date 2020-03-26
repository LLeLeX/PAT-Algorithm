#include <bits/stdc++.h>
using namespace std;
int tree1[10] = {5, 3, 7, 4, 2, 8, 6};
int tree2[10] = {7, 4, 5, 8, 2, 6, 3};
struct Node{
	int data;
	int level;
	Node* lchild;
	Node* rchild;
};
Node* newNode(int v)
{
	Node* node = new Node;
	node->data = v;
	node->lchild = node->rchild = NULL;
	return node;
}
void insert(Node* &root, int v)
{
	if(root == NULL)//查找结果不存在，即插入位置 
	{
		root = newNode(v);
		return;
	}
	if(v == root->data)//查找成功,该元素已存在 
		return;
	else if(v > root->data)
		insert(root->rchild, v);
	else
		insert(root->lchild, v);
}

//删除节点
Node* findMax(Node* root)
{
	while(root->rchild != NULL)
		root = root->rchild;
	return root;
} 
Node* findMin(Node* root)
{
	while(root->lchild != NULL)
		root = root->lchild;
	return root;
}
/*要删除的节点x*/
void deleteNode(Node* &root, int x)
{
	if(root == NULL)//给定的x不存在 
		return;
	if(root->data == x)//找到x，进入删除操作 
	{
		if(root->lchild == NULL && root->rchild == NULL)//为叶子节点 
			root = NULL;//直接赋值为空即可删除 
		else if(root->lchild != NULL)//有左孩子 
		{
			Node* pre = findMax(root->lchild);
			root->data = pre->data;
			//pre = NULL;
			deleteNode(root->lchild, pre->data);//递归删除pre 
		} 
		else if(root->rchild != NULL)//有右孩子 
		{
			Node* next = findMin(root->rchild);
			root->data = next->data;
			deleteNode(root->rchild, next->data);
		}
	}
	else if(root->data > x)
		deleteNode(root->lchild, x);
	else
		deleteNode(root->rchild, x);
}
void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	root->level = 1;
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("(%d,%d)\n", now->data, now->level);
		if(now->lchild != NULL)
		{
			now->lchild->level = now->level + 1;
			q.push(now->lchild);
		}
		if(now->rchild != NULL)
		{
			now->rchild->level = now->level + 1;
			q.push(now->rchild);
		}
	}
}
int main(int argc, char *argv[]) {
	Node* root = NULL;
	for(int i = 0; i < 7; ++i)
	{
		insert(root, tree1[i]);
	}
	levelOrder(root);
	cout << "*******" << endl;
	deleteNode(root, 5);
	levelOrder(root);
	return 0;
}
