#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int M, N;
int in[maxn], pre[maxn];
unordered_map<int, int> inpos;//中序中数据的位置 
int main(int argc, char *argv[]) {
	scanf("%d%d", &M, &N);
	for(int i = 1; i <= N; ++i)//下标从1开始 
	{
		scanf("%d", &in[i]);
		inpos[in[i]] = i; 
	}
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &pre[i]);
	}
	while(M--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		int inu = inpos[u], inv = inpos[v];
		if(inu == 0 && inv != 0)//等于0说明该数据不在树中 
			printf("ERROR: %d is not found.\n", u);
		else if(inu != 0 && inv == 0)
			printf("ERROR: %d is not found.\n", v);
		else if(inu == 0 && inv == 0)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else
		{
			for(int i = 1; i <= N; ++i)//遍历先序序列 
			{
				int now = pre[i];//当前节点的数值 
				int innow = inpos[now];//当前节点在中序中的下标 
				if((innow > inu && innow < inv) || (innow > inv && innow < inu))//下标在u，v之间 
				{
					printf("LCA of %d and %d is %d.\n", u, v, now);
					break;
				}
				else if(innow == inu)//与u相等即可，没有innow != inv的条件 
				{
					printf("%d is an ancestor of %d.\n", u, v);
					break;
				}
				else if(innow == inv)
				{
					printf("%d is an ancestor of %d.\n", v, u);
					break;
				}
				else
					continue;
			}
		}
	}
	return 0;
}
