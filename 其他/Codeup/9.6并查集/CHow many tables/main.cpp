#include <bits/stdc++.h>
using namespace std;
int father[1005];
bool vis[1005];
int T;
int N, M;
void init()
{
	for(int i = 1; i <= N; ++i)
		father[i] = i;
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
void unionFather(int a, int b)
{
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb)
		father[fa] = fb;
}
int main(int argc, char *argv[]) {
	scanf("%d", &T);
	while(T--)
	{
		memset(father, 0, sizeof(father));
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &N, &M);
		init();
		for(int i = 0; i < M; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unionFather(a, b);
		}
		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			int F = findFather(i);
			if(!vis[F])
			{
				ans++;
				vis[F] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
