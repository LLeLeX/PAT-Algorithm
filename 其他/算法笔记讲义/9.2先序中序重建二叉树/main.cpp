#include <bits/stdc++.h>
using namespace std;
int pre[10] = {1, 2, 4, 5, 3, 6, 7};
int in[10] = {4, 2, 5, 1, 6, 3, 7};
struct Node{
	int data;
	int layer = 0;
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
Node* recreate(int preL, int preR, int inL, int inR)
{
	if(preL > preR)//�߽� 
		return NULL;
	Node* root = newNode(pre[preL]);//����ĸ��ڵ� 
	int k;//��¼������ڵ���±� 
	for(k = inL; k <= inR; k++)//���������ҵ����ڵ� 
	{
		if(in[k] == pre[preL])
			break;
	}
	int numLeft = k - inL;//�����������Ľڵ��� 
	root->lchild = recreate(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = recreate(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
void layerOrder(Node* root)
{
	queue<Node*> q;
	root->layer = 1;
	q.push(root);
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("(%d,%d)\n", now->data, now->layer);
		if(now->lchild != NULL)
		{
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild);
		}
		if(now->rchild != NULL)
		{
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild);
		}
	}
}
int main(int argc, char *argv[]) {
	Node* root = recreate(0, 6, 0, 6);
	layerOrder(root);
	return 0;
}
