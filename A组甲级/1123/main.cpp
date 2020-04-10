#include <bits/stdc++.h>
using namespace std;
int N;
struct Node{
	int data;
	int height;//��ǰ�����ĸ߶�
	Node* left;
	Node* right; 
};
Node* newNode(int x)
{
	Node* node = new Node;
	node->data = x;
	node->height = 1;//��ʼ�߶�Ϊ1
	node->left = node->right = NULL;
	return node; 
}
int getHeight(Node* root)
{
	if(root == NULL)
		return 0;
	else
		return root->height;
}
int getBalanceFactor(Node* root)
{
	return (getHeight(root->left) - getHeight(root->right));
}
void updateHeight(Node* root)
{
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
void LRotation(Node* &root)
{
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void RRotation(Node* &root)
{
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
//���ڵ㣬Ҫ�����ֵΪx 
void insert(Node* &root, int x)
{
	if(root == NULL)
	{
		root = newNode(x);
		return;
	}
	if(x < root->data)
	{
		insert(root->left, x);
		updateHeight(root);
		if(getBalanceFactor(root) == 2)
		{
			if(getBalanceFactor(root->left) == 1)
			{
				RRotation(root);
			}
			else if(getBalanceFactor(root->left) == -1)
			{
				LRotation(root->left);
				RRotation(root);
			}	
		}
	}
	else
	{
		insert(root->right, x);
		updateHeight(root);
		if(getBalanceFactor(root) == -2)
		{
			if(getBalanceFactor(root->right) == -1)
			{
				LRotation(root);
			}
			else if(getBalanceFactor(root->right) == 1)
			{
				RRotation(root->right);
				LRotation(root);
			}
		}
	}
}
bool isCmplt = true;//����Ƿ�Ϊ��ȫ������ 
bool isLeaf = false;//����Ƿ������Ҷ�ӽڵ� 
void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("%d", now->data);
		cnt++;
		if(cnt < N)
			printf(" ");
		else
			printf("\n");
		//�����ж���ȫ������	
		if(now->left == NULL && now->right != NULL)
			isCmplt = false;
		if(isLeaf == true)
		{
			if(now->left != NULL || now->right != NULL)//��Ҷ�ӽڵ� 
				isCmplt = false;
		}
		if(now->right == NULL)//����Ӧ�þ�ΪҶ�ӽڵ� 
			isLeaf = true;	
		//���� 
		if(now->left != NULL)
			q.push(now->left);
		if(now->right != NULL)
			q.push(now->right);
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	Node* root = NULL;
	for(int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		insert(root, x); 
	}
	levelOrder(root);
	if(isCmplt == true)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
