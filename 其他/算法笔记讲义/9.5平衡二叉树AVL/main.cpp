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
	node->height = 1;//Ĭ�ϸ߶�Ϊ1
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
int getHeight(Node* root)//��ȡ��ǰ�ڵ�߶� :�����漰�սڵ�߶�Ϊ0����� 
{
	if(root == NULL)//�ڵ�Ϊ�� 
		return 0;
	return root->height;
} 
int getBalanceFactor(Node* root)//��ȡ��ǰ�ڵ��ƽ������ 
{
	return getHeight(root->lchild) - getHeight(root->rchild);//root�ڵ��������ĸ߶�-�������ĸ߶� 
}
void updateHeight(Node* root)//���µ�ǰ�ڵ�ĸ߶� 
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void leftRotation(Node* &root)
{
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	//���½ڵ�߶�
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
}
void rightRotation(Node* &root)
{
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	//���½ڵ�߶�
	updateHeight(root);
	updateHeight(temp);
	root = temp; 
}
void AVLinsert(Node* &root, int v)
{
	if(root == NULL)//����սڵ㣬����ʧ�ܣ����ǲ���λ�� 
	{
		root = newNode(v);
		//root = new Node(v);
		return;
	}
	if(v < root->data)//�ȸ��ڵ�С������������ 
	{
		AVLinsert(root->lchild, v);
		updateHeight(root);//ÿ�β����Ҫ��������
		if(getBalanceFactor(root) == 2)//����L�� 
		{
			cout << "���ֲ�ƽ��" << endl;
			if(getBalanceFactor(root->lchild) == 1)//LL��
			{
				cout << "LL��" << endl;
				rightRotation(root);
			}
			else if(getBalanceFactor(root->lchild) == -1)//LR��
			{
				cout << "LR��" << endl;
				leftRotation(root->lchild);
				rightRotation(root);
			} 
		} 
		else
			cout << "��������" << endl;
	}
	else//���ڵ��ڸ��ڵ㣬���������� 
	{
		AVLinsert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2)//����R��
		{
			cout << "���ֲ�ƽ��" << endl;
			if(getBalanceFactor(root->rchild) == -1)//RR�� 
			{
				cout << "RR��" << endl;
				leftRotation(root); 
			} 
			else if(getBalanceFactor(root->rchild) == 1)//RL�� 
			{
				cout << "RL��" << endl;
				rightRotation(root->rchild);
				leftRotation(root);
			}
		} 
		else
		{ 
			cout << "��������" << endl; 
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
