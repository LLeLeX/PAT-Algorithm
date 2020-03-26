#include <bits/stdc++.h>
using namespace std;
int N, cnt;
vector<int> pre, in, post; 
stack<int> s;
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
Node* recreate(int preL, int preR, int inL, int inR)
{
	if(preL > preR)
		return NULL;
	Node* root = newNode(pre[preL]);
	int k;
	for(k = inL; k <= inR; ++k)
	{
		if(in[k] == pre[preL])
			break;
	}
	int numLeft = k - inL;
	root->lchild = recreate(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = recreate(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
void postOrder(Node* root)
{
	if(root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < 2 * N; i++)
	{
		char str[10];
		int num;
		scanf("%s", str);
		if(str[1] == 'u')
		{
			scanf("%d", &num);
			pre.push_back(num);
			s.push(num);
		}
		else if(str[1] == 'o')
		{
			int top = s.top();
			s.pop();
			in.push_back(top);
		}
	}
	Node* root = recreate(0, N - 1, 0, N - 1);
	postOrder(root);
	for(int i = 0; i < post.size(); ++i)
	{
		if(i < post.size() - 1)
			printf("%d ", post[i]);
		else
			printf("%d", post[i]);
	}
	/*for(int i = 0; i < pre.size(); ++i)
	{
		printf("%d ", pre[i]);
	}
	cout << endl;
	for(int i = 0; i < in.size(); ++i)
	{
		printf("%d ", in[i]);
	}*/
	return 0;
}
