#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int M, N;
int tree[maxn];
vector<int> post;
void postOrder(int root)
{
	if(root > N)
		return;
	postOrder(2 * root);
	postOrder(2 * root + 1);
	post.push_back(tree[root]);
}


int main(int argc, char *argv[]) {
	scanf("%d%d", &M, &N);
	while(M--)
	{
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= N; ++i)
		{
			//完全二叉树的层序 
			scanf("%d", &tree[i]);
		}
		int flag;//0:最大堆，1：最小堆 
		if(tree[1] >= tree[2])
			flag = 0;
		else
			flag = 1;
		for(int i = 1; i <= N; ++i)
		{
			int root = i;
			int left = 2 * i;
			int right = 2 * i + 1;
			if(left > N)//超出范围，已经遍历完所有节点 
				break;
			
			if(flag == 0)//最大堆 
			{
				if(tree[root] < tree[left] && left <= N)
				{
					flag = -1;
					break;
				}
				if(tree[root] < tree[right] && right <= N)
				{
					flag = -1;
					break;
				}
			}
			if(flag == 1)
			{
				if(tree[root] >= tree[left] && left <= N)
				{
					flag = -1;
					break;
				}
				if(tree[root] >= tree[right] && right <= N)
				{
					flag = -1;
					break;
				}
			}
		} 
		if(flag == -1)
			printf("Not Heap\n");
		else if(flag == 0)
			printf("Max Heap\n");
		else
			printf("Min Heap\n");
		
		postOrder(1);
		for(int i = 0; i < post.size(); ++i)
		{
			printf("%d", post[i]);
			if(i < post.size() - 1)
				printf(" ");
			else
				printf("\n");
		}
		post.clear();
	}
	return 0;
}
