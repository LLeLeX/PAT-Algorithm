#include <bits/stdc++.h>
using namespace std;
int arr[10];
struct Node{
	int data;
	int layer = 0; 
	Node* lchild;
	Node* rchild;
	Node(){}
	Node(int d, Node* l, Node* r){
		data = d;
		lchild = l;
		rchild = r;
	}
};
Node* root = NULL;
Node* newNode(int v)
{
	Node* node = new Node;
	node->data = v;
	node->lchild = node->rchild = NULL;
	//cout << node->data << " " << node->lchild << node->rchild << endl;
	return node;
}


//root引用根节点，v新节点的data，dir表示方向，left为0，right为1 
void insertNode(Node* &root, int v, int dir)
{
	if(root == NULL)
	{
		root = newNode(v);
		return;
	}
	if(!dir)
		insertNode(root->lchild, v, 0);
	else
		insertNode(root->rchild, v, 1);
}
//dir方向，0向左，1向右 
void insertNode2(Node* &root, int v, int dir)
{
	if(root == NULL)
	{
		root = newNode(v);
		return;
	}
	if(root->lchild != NULL && root->rchild != NULL)
	{
		if(!dir)
			insertNode2(root->lchild, v, dir);
		else
			insertNode2(root->rchild, v, dir);
	}
		
	else
	{
		if(root->lchild == NULL)
			insertNode2(root->lchild, v, dir);
		else
			insertNode2(root->rchild, v, dir);
	}
}



//遍历 
void preorder(Node* root)
{
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
} 
void layerOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* top = q.front();
		q.pop();
		printf("(%d, %d)\n", top->data, top->layer);
		if(top->lchild != NULL)
		{
			top->lchild->layer = top->layer + 1; 
			q.push(top->lchild);
		}
		if(top->rchild != NULL)
		{
			top->rchild->layer = top->layer + 1;
			q.push(top->rchild);
		}
	}
}
int main(int argc, char *argv[]) {
	/*Node* node = new Node;
	node->data = 10;
	node->lchild = node->rchild = NULL;
	cout << node->data << " " << node->lchild << " " << node->rchild << endl;*/
	
	//构造函数初始化 
	/*Node node = Node(10, NULL, NULL);
	cout << node.data << " " << node.lchild << " " << node.rchild << endl;*/
	
	
	
	for(int i = 1; i <= 7; i++)
	{
		scanf("%d", &arr[i]);
		if(i % 2 == 0)
			insertNode2(root, arr[i], 0);
		else
			insertNode2(root, arr[i], 1);
	}
	preorder(root);
	cout << endl;
	layerOrder(root);
	return 0;
}
