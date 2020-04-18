#include <bits/stdc++.h>
using namespace std;
int N;
struct Node{
	string str;
	int left, right;
}nodes[25];
bool isNode[25];
void inOrder(int root, int depth)
{
	if(root == -1)
		return;
	bool isLeaf = true;
	if(nodes[root].left == -1 && nodes[root].right == -1)
	{
		isLeaf = false;
	}
	if(isLeaf && depth != 1)//非叶子结点且不是第一层
		printf("(");
	inOrder(nodes[root].left, depth + 1);
	cout << nodes[root].str;
	inOrder(nodes[root].right, depth + 1);
	if(isLeaf && depth != 1)
		printf(")");
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		cin >> nodes[i].str >> nodes[i].left >> nodes[i].right;
		if(nodes[i].left != -1)
			isNode[nodes[i].left] = true; 
		if(nodes[i].right != -1)
			isNode[nodes[i].right] = true;
	}
	int root;
	for(int i = 1; i <= N; ++i)
	{
		if(isNode[i] == false)
		{
			root = i;
			break; 
		} 
	}
	inOrder(root, 1);
	return 0;
}
