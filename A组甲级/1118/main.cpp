#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int N;
int father[maxn];//第i只鸟与第father[i]只鸟属于同一棵树 
bool vis[maxn];//标记树的个数 
void init()
{
	for(int i = 1; i < maxn; ++i)
	{
		father[i] = i;
	}
}
int findFather(int x)
{
	if(x == father[x])
		return x;
	else
	{
		int f = findFather(father[x]);
		father[x] = f;
		return f;
	}
}
void unionFather(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if(fx != fy)
		father[fx] = fy;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	init();
	int maxBird = -1;//存储鸟的最大编号 
	for(int i = 0; i < N; ++i)
	{
		int K, firBird;//存储每张照片第一只鸟的编号 
		scanf("%d", &K);
		for(int i = 0; i < K; ++i)
		{
			int bird;
			scanf("%d", &bird);
			maxBird = max(maxBird, bird);
			if(i == 0)//第一只鸟作为根 
			{
				firBird = bird;
				continue;
			}
			unionFather(firBird, bird);
		}
	}
	int treecnt = 0;
	for(int i = 1; i <= maxBird; ++i)
	{
		int pos = findFather(i);//再次更新根节点 
		if(vis[pos] == false)
		{
			treecnt++;
			vis[pos] = true;
		}
			//cout << father[i] << " ";
	}
	//cout << endl;
	printf("%d %d\n", treecnt, maxBird);	
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i)
	{
		int b1, b2;
		scanf("%d%d", &b1, &b2);
		/*int fb1 = findFather(b1);
		int fb2 = findFather(b2);*/
		if(father[b1] == father[b2])
			printf("Yes\n");
		else
			printf("No\n");
	} 
	return 0;
}
