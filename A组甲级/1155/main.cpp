#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int N;
int heap[maxn];
vector<int> path;
int flag = -1;
void dfs(int root)
{
	if(root > N)
		return;
	if(2 * root + 1 > N && 2 * root > N)
	{
		path.push_back(heap[root]);
		for(int i = 0; i < path.size(); ++i)
		{
			if(i < path.size() - 1 && flag != -1)
			{
				int pare = path[i];
				int child = path[i + 1];
				if(flag == 1)//´ó¶¥¶Ñ 
				{
					if(child > pare)
						flag = -1;
				}
				else
				{
					if(child < pare)
						flag = -1;
				}
			}
			printf("%d", path[i]);
			if(i < path.size() - 1)
				printf(" ");
			else
				printf("\n");
		}
		path.pop_back();
		return;
	}
	path.push_back(heap[root]);
	dfs(2 * root + 1);
	path.pop_back();
	path.push_back(heap[root]);
	dfs(2 * root);
	path.pop_back();
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &heap[i]);
	}
	int k = 2;
	while(flag == -1)
	{
		if(heap[1] > heap[k])
			flag = 1;
		else if(heap[1] == heap[2])
			k++;
		else
			flag = 2;
	}
	dfs(1);
	if(flag == -1)
		printf("Not Heap\n");
	else if(flag == 1)
		printf("Max Heap\n");
	else
		printf("Min Heap\n");
	return 0;
}
