#include <bits/stdc++.h>
using namespace std;
int N;
int pre[105], post[105];
struct Node{
	int data;
	int left, right;
}nodes[105];
int pos;
int newNode(int x)
{
	nodes[pos].data = x;
	nodes[pos].left = nodes[pos].right = -1;
	return pos++;
}
//判断二叉树是否唯一，并返回左右子树划分位置的下标 
int checkUnique(int preL, int preR, int postL, int postR)
{
	//注意序列下标从0开始 
	int firRoot = pre[preL];//树的根节点，pre[0] = post[N - 1] 
	int secRoot = post[postR - 1];//获取后序序列根节点的前一个节点 
	if(pre[preL + 1] == secRoot)
		return -1;
	for(int i = preL + 1; i <= preR; ++i)
	{
		if(pre[i] == secRoot)
			return i;
	}
	return -1;
}
bool isUnique = true;//标记树是否唯一 
int recreate( int preL, int preR, int postL, int postR)
{
	//递归边界
	if(preL > preR || postL > postR)
		return -1;
	if(preL == preR)
	{
		int root = newNode(post[postR]);
		return root;
	} 
	
	int root = newNode(post[postR]);//根据后序获得根节点
	int secroot = checkUnique(preL, preR, postL, postR);
	/*int secroot = preL + 1;
	for(; secroot <= preR; ++secroot)
	{
		if(pre[secroot] == post[postR - 1])
			break;
	}*/
	
	
	if(secroot == -1)
	{
		isUnique = false;
		nodes[root].right = recreate(preL + 1, preR, postL, postR - 1);
	}
	else
	{
		int numleft = secroot - preL - 1;//在pre[]中，secroot位置划分左右子树 
		nodes[root].left = recreate(preL + 1, preL + numleft, postL, postL + numleft - 1);
		nodes[root].right = recreate(secroot, preR, postL + secroot - preL - 1, postR - 1);
	}
	return root;	
}
vector<int> in;
void inOrder(int root)
{
	//递归边界 
	if(root == -1)
		return;
	inOrder(nodes[root].left);
	in.push_back(nodes[root].data);
	inOrder(nodes[root].right);
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &post[i]);
	}
	int root = recreate(0, N - 1, 0, N - 1);
	if(isUnique == false)
		printf("No\n");
	else
		printf("Yes\n");
	inOrder(root);
	for(int i = 0; i < in.size(); ++i)
	{
		printf("%d", in[i]);
		if(i < in.size() - 1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
