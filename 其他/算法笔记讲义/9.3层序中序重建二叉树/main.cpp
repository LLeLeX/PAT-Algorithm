#include <bits/stdc++.h>
using namespace std;
int lay[10] = {1, 2, 3, 4, 5, 6, 7};
int in[10] = {4, 2, 5, 1, 6, 3, 7};
bool hashtable[10];
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
Node* recreate(int layL, int layR, int inL, int inR)
{
	//边界 
	if(inL > inR)
	{
		return NULL;
	}
	int x, y;
	Node* root = NULL;
	//在中序序列里找到层序的一个根节点，跳出循环进入递归 
	for(x = layL; x <= layR; ++x)//层序的特点，根节点排在前面 （循环含义：把每一个节点都当做根节点） 
	{
		if(hashtable[x])//该节点已访问 
			continue;
		bool flag = false;//标记是否在中序序列里找到根节点，若找到跳出所有 
		for(y = inL; y <= inR; ++y)
		{
			if(lay[x] == in[y])//在中序序列里 找到层序遍历到的根节点lay[x] 
			{
				flag = true; 
				break;
			}
		}
		if(flag)
		{
			hashtable[x] = true;
			root = newNode(lay[x]);
			root->lchild = recreate(x + 1, layR, inL, y - 1);//中序划分的左子树
			root->rchild = recreate(x + 1, layR, y + 1, inR);//中序划分的右子树 
			//由于层序是顺序遍历并做访问标记，直接从x+1即可 
		}
	}
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
