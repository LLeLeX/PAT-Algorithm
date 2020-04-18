#include <bits/stdc++.h>
using namespace std;
int N;
struct Node{
	string str;
	int left, right;
}nodes[25];
bool isNode[25];
int root;
string dfs(int index)
{
	if(index == -1)
		return "";
	if(nodes[index].right != -1)
	{
		nodes[index].str = dfs(nodes[index].left) + nodes[index].str + dfs(nodes[index].right);
		if(index != root)
			nodes[index].str = "(" + nodes[index].str + ")";
	}
	return nodes[index].str;
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
	for(int i = 1; i <= N; ++i)
	{
		if(isNode[i] == false)
		{
			root = i;
			break; 
		} 
	}
	cout << dfs(root);
	return 0;
}
