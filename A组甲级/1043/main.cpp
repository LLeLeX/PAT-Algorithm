#include <bits/stdc++.h>
using namespace std;
int N, pos;
vector<int> origin, pre, post;
struct Node{
	int data;
	int lchild;
	int rchild;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		lchild = l;
		rchild = r;
	}
}nodes[1005];
int newNode(int v)
{
	nodes[pos] = Node(v, -1, -1);
	return pos++;
}
void insert(int &root, int v)//构建二叉查找树 
{
	if(root == -1)//说明查找v失败，即是插入位置 
	{
		root = newNode(v);
		return;
	}
	if(v >= nodes[root].data)//大于等于在右子树
		insert(nodes[root].rchild, v);
	else
		insert(nodes[root].lchild, v); 
}
void preOrder(int root)//正常前序 
{
	if(root == -1)
		return;
	pre.push_back(nodes[root].data);
	preOrder(nodes[root].lchild);
	preOrder(nodes[root].rchild);
} 
void mirrorPre(int root)//镜像前序 
{
	if(root == -1)
		return;
	pre.push_back(nodes[root].data);
	mirrorPre(nodes[root].rchild);
	mirrorPre(nodes[root].lchild);
}
void postOrder(int root)//正常后序 
{
	if(root == -1)
		return;
	postOrder(nodes[root].lchild);
	postOrder(nodes[root].rchild);
	post.push_back(nodes[root].data);
}
void mirrorPost(int root)//镜像后序 
{
	if(root == -1)
		return;
	mirrorPost(nodes[root].rchild);
	mirrorPost(nodes[root].lchild);
	post.push_back(nodes[root].data);
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int root = -1;//存放根节点地址 ，注意先声明为-1 
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		origin.push_back(num);
		insert(root, num);
	}
	if(origin[0] > origin[1])//正常 
	{
		preOrder(root);
		if(pre == origin)
		{
			printf("YES\n");
			postOrder(root);
			for(int i = 0; i < post.size(); ++i)
			{
				if(i < post.size() - 1)
					printf("%d ", post[i]);
				else
					printf("%d", post[i]);
			}
		}
		else
			printf("NO");
	}
	else//镜像 
	{
		mirrorPre(root);
		if(pre == origin)
		{
			printf("YES\n");
			mirrorPost(root);
			for(int i = 0; i < post.size(); ++i)
			{
				if(i < post.size() - 1)
					printf("%d ", post[i]);
				else
					printf("%d", post[i]);
			}
		}
		else
			printf("NO");
	} 	
	return 0;
}
