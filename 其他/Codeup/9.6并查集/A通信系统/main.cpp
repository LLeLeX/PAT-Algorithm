#include <bits/stdc++.h>
using namespace std;
int N, M;
int father[1005];
bool vis[1005];
void init()//≥ı ºªØ 
{
	for(int i = 1; i <= N; ++i)
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
		int F = findFather(father[x]);
		father[x] = F;
		return F;
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
	while(1)
	{
		memset(father, 0, sizeof(father));
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &N, &M);
		if(!M && !N)
			break;
		init();
		for(int i = 0; i < M; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unionFather(a, b);
		}
		int ans = 0;
		for(int i = 1; i <= N; ++i)
		{
			int F = findFather(i);
			if(!vis[F])
			{
				ans++;
				vis[F] = true;
			}
			if(ans > 1)
			{
				break;
			}
		}
		if(ans == 1 && M == N - 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
