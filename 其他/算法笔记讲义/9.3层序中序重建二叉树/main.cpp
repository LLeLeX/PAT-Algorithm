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
	//�߽� 
	if(inL > inR)
	{
		return NULL;
	}
	int x, y;
	Node* root = NULL;
	//�������������ҵ������һ�����ڵ㣬����ѭ������ݹ� 
	for(x = layL; x <= layR; ++x)//������ص㣬���ڵ�����ǰ�� ��ѭ�����壺��ÿһ���ڵ㶼�������ڵ㣩 
	{
		if(hashtable[x])//�ýڵ��ѷ��� 
			continue;
		bool flag = false;//����Ƿ��������������ҵ����ڵ㣬���ҵ��������� 
		for(y = inL; y <= inR; ++y)
		{
			if(lay[x] == in[y])//������������ �ҵ�����������ĸ��ڵ�lay[x] 
			{
				flag = true; 
				break;
			}
		}
		if(flag)
		{
			hashtable[x] = true;
			root = newNode(lay[x]);
			root->lchild = recreate(x + 1, layR, inL, y - 1);//���򻮷ֵ�������
			root->rchild = recreate(x + 1, layR, y + 1, inR);//���򻮷ֵ������� 
			//���ڲ�����˳������������ʱ�ǣ�ֱ�Ӵ�x+1���� 
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
