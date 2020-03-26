#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
char mp[1005][1005];
bool visx[1005], visy[1005];
//x,y坐标
void dfs(int x, int y)
{
	mp[x][y] = '0';//引爆炸弹，修改防止重复访问 
	//递归边界	
	//递归体
	//访问同一行
	if(!visx[x])
	{
		visx[x] = true;//标记行被访问 
		for(int j = 0; j < m; j++)
		{
			if(mp[x][j] == '1')//同一行存在炸弹 
			{
				dfs(x, j);
			}
		}
	}
	//访问同一列
	if(!visy[y])
	{
		visy[y] = true;
		for(int i = 0; i < n; i++)
		{
			if(mp[i][y] == '1')//同一列存在炸弹 
			{
				dfs(i, y);
			}
		} 	
	}
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
    	scanf("%s", mp[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mp[i][j] == '1')
            {
            	cnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
