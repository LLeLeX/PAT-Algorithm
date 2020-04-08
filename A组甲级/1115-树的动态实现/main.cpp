#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N;
struct Node{
	int data;
	Node* left;
	Node* right;
	int level;
}*root;

Node* newNode(int x)
{
	Node* node = new Node();
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void insert(Node* &root, int x)
{
	//µÝ¹é±ß½ç
	if(root == NULL)
	{
		root = newNode(x);
		return;
	} 
	if(x <= root->data)
		insert(root->left, x);
	else
		insert(root->right, x);
}
int levelcnt[maxn];
int maxlevel;
void levelOrder()
{
	queue<Node*> q;
	root->level = 1;
	q.push(root);
	while(!q.empty())
	{
		Node* now = q.front();
		q.pop();
		levelcnt[now->level]++;
		maxlevel = max(now->level, maxlevel);
		if(now->left != NULL)
		{
			now->left->level = now->level + 1;
			q.push(now->left);
		}
		if(now->right != NULL)
		{
			now->right->level = now->level + 1;
			q.push(now->right);
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int data;
		scanf("%d", &data);
		insert(root, data);
	}
	levelOrder();
	int a = levelcnt[maxlevel];
	int b = levelcnt[maxlevel - 1];
	int c = a + b;
	printf("%d + %d = %d", a, b, c);
	return 0;
}
