#include <bits/stdc++.h>
using namespace std;
int N, post[35], in[35], cnt = 0;
struct Node{
	int data;
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
	Node* root = newNode(post[postR]);//后序根节点
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
	return root;
}
void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		cnt++;
		if(cnt < N)
			printf("%d ", now->data);
		else
			printf("%d", now->data);
		if(now->lchild != NULL)
			q.push(now->lchild);
		if(now->rchild != NULL)
			q.push(now->rchild);
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &in[i]);
	}
	Node* root = recreate(0, N - 1, 0, N- 1);
	levelOrder(root);
	return 0;
}
