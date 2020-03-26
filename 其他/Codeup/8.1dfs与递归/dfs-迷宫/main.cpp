#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int n, m, startx, starty, endx, endy, ansCnt;
int maze[50][20];
int ans[250][2];
bool vis[50][20];
bool cmplt;
//x:横坐标，y:纵坐标，step：步数，便于路径输出 
void dfs(int x, int y, int step)
{
	//边界 
	if(x < 1 || x > n || y < 1 || y > m || maze[x][y] == 0)
	{
		return;
	}
	if(x == endx && y == endy)//终点 
	{
		cmplt = true;
		ansCnt++;
		printf("(1,1)->");
		for(int i = 0; i < step; i++)
		{
			if(i < step - 1)
				printf("(%d,%d)->", ans[i][0], ans[i][1]);
			else
				printf("(%d,%d)\n", ans[i][0], ans[i][1]);
		}
		return;
	}
	//递归体 
	vis[x][y] = true; 
	for(int i = 0; i < 4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && maze[tx][ty] != 0 && !vis[tx][ty])
		{
			//vis[tx][ty] = true;//存在问题 
			ans[step][0] = tx;
			ans[step][1] = ty;
			dfs(tx, ty, step + 1);
			//vis[tx][ty] = false;;
		}
	}
	vis[x][y] = false;
}
int main(int argc, char *argv[]) {
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		scanf("%d%d", &startx, &starty);
		scanf("%d%d", &endx, &endy);
		dfs(startx, starty, 0);
		if(!cmplt)
			printf("-1");
	}
	return 0;
}
