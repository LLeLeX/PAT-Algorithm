#include <bits/stdc++.h>
using namespace std;
int LL[10] = {7, 5, 8, 3, 6, 2, 4},
	LR[10] = {7, 3, 8, 2, 5, 4, 6},
	RR[10] = {3, 5, 2, 4, 7, 6, 8},
	RL[10] = {3, 2, 7, 5, 8, 4, 6},
	AVL[10] = {5, 3, 7, 2, 4, 6, 8};
struct Node{
	int data;
	int height;
	int level = 1;
	Node* lchild;
	Node* rchild;
	Node(){}
	Node(int x):data(x),height(1),lchild(NULL),rchild(NULL){}
	//Node(){}
	/*Node(int x)
	{
		data = x;
		height = 1;
		level = 1;
		lchild = NULL;
		lchild = NULL;
	}*/
};
Node* newNode(int v)
{
	Node* node = new Node;
	node->data = v;
	node->height = 1;//默认高度为1
	node->lchild = node->rchild = NULL; 
	return node; 
}
void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("(%d,%d) ", now->data, now->level);
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
	cout << endl;
}
int getHeight(Node* root)//获取当前节点高度 :其中涉及空节点高度为0的情况 
{
	if(root == NULL)//节点为空 
		return 0;
	return root->height;
} 
int getBalanceFactor(Node* root)//获取当前节点的平衡因子 
{
	return getHeight(root->lchild) - getHeight(root->rchild);//root节点左子树的高度-右子树的高度 
}
void updateHeight(Node* root)//更新当前节点的高度 
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void leftRotation(Node* &root)
{
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	//更新节点高度
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
}
void rightRotation(Node* &root)
{
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	//更新节点高度
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
}
void AVLinsert(Node* &root, int v)
{
	if(root == NULL)//到达空节点，查找失败，即是插入位置 
	{
		root = newNode(v);
		//root = new Node(v);
		return;
	}
	if(v < root->data)//比根节点小，往左子树走 
	{
		AVLinsert(root->lchild, v);
		updateHeight(root);//每次插入后要更新树高
		if(getBalanceFactor(root) == 2)//属于L型 
		{
			cout << "出现不平衡" << endl;
			if(getBalanceFactor(root->lchild) == 1)//LL型
			{
				cout << "LL型" << endl;
				rightRotation(root);
			}
			else if(getBalanceFactor(root->lchild) == -1)//LR型
			{
				cout << "LR型" << endl;
				leftRotation(root->lchild);
				rightRotation(root);
			} 
		} 
		else
			cout << "插入正常" << endl;
	}
	else//大于等于根节点，往右子树走 
	{
		AVLinsert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2)//属于R型
		{
			cout << "出现不平衡" << endl;
			if(getBalanceFactor(root->rchild) == -1)//RR型 
			{
				cout << "RR型" << endl;
				leftRotation(root); 
			} 
			else if(getBalanceFactor(root->rchild) == 1)//RL型 
			{
				cout << "RL型" << endl;
				rightRotation(root->rchild);
				leftRotation(root);
			}
		} 
		else
		{ 
			cout << "插入正常" << endl; 
		} 
	}
}
void BSTinsert(Node* &root, int v)
{
	if(root == NULL)
	{
		//root = newNode(v);
		root = new Node(v);
		return;
	}
	if(v < root->data)
		BSTinsert(root->lchild, v);
	else
		BSTinsert(root->rchild, v);
} 
int main(int argc, char *argv[]) {
	Node* BSTroot = NULL;
	Node* AVLroot = NULL;
	for(int i = 0; i < 7; ++i)
	{
		BSTinsert(BSTroot, RR[i]);
	}
	levelOrder(BSTroot);
	for(int i = 0; i < 7; ++i)
	{
		AVLinsert(AVLroot, RR[i]);
	}
	levelOrder(AVLroot);
	return 0;
}
