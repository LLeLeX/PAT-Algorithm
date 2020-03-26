#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, ans;
int mp[10][10];
bool vis[10][10];
//x,y×ø±ê 
void dfs(int x, int y)
{
	//µÝ¹éÌå 
	vis[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//µÝ¹é±ß½ç 
		if(tx >= 0 && tx < n && ty >= 0 && ty < n && !vis[tx][ty] && mp[tx][ty] != 0)
		{
			dfs(tx, ty);
		}
	} 
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &mp[i][j]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mp[i][j] == 1 && !vis[i][j])
			{
				cout << i << " " << j << endl;
				ans++;
				dfs(i, j);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
