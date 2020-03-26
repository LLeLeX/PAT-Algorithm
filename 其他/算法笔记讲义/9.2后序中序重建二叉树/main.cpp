#include <bits/stdc++.h>
using namespace std;
int post[10] = {4, 5, 2, 6, 7, 3, 1};
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

Node* recreate(int postL, int postR, int inL, int inR)
{
	if(postL > postR)
		return NULL;
	Node* root = newNode(post[postR]);
	int k;
	for(k = inL; k <= inR; ++k)
	{
		if(in[k] == post[postR])
			break;
	}
	int numLeft = k - inL;
	root->lchild = recreate(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = recreate(postL + numLeft, postR - 1, k + 1, inR);
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
