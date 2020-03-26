#include<bits/stdc++.h>
using namespace std;
int wdir[4][2] = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
int gdir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;
char maze[105][105];
bool vis[105][105], flag[105][105];
bool cmplt;
void gdfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || maze[x][y] == '#')
    {
        return;
    }
    if(vis[x][y])
	{
		return;
	} 
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + gdir[i][0];
        int ty = y + gdir[i][1];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && maze[tx][ty] != '#')
        {
            gdfs(tx, ty);
        }
    }
}
void wdfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || maze[x][y] == '#')
    {
        return;
    }
    if(vis[x][y])
    {
        cmplt = true;
        return;
    }
    if(flag[x][y])
    	return;
    flag[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + wdir[i][0];
        int ty = y + wdir[i][1];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && maze[tx][ty] != '#')
        {
            wdfs(tx, ty);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf(" %c", &maze[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maze[i][j] == 'g')//先走公主
            {
                gdfs(i, j);
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maze[i][j] == 'w')//再走王子
            {
                wdfs(i, j);
                break;
            }
        }
    }
    if(cmplt)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
