#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
char mp[1005][1005];
bool visx[1005], visy[1005];
//x,y����
void dfs(int x, int y)
{
	mp[x][y] = '0';//����ը�����޸ķ�ֹ�ظ����� 
	//�ݹ�߽�	
	//�ݹ���
	//����ͬһ��
	if(!visx[x])
	{
		visx[x] = true;//����б����� 
		for(int j = 0; j < m; j++)
		{
			if(mp[x][j] == '1')//ͬһ�д���ը�� 
			{
				dfs(x, j);
			}
		}
	}
	//����ͬһ��
	if(!visy[y])
	{
		visy[y] = true;
		for(int i = 0; i < n; i++)
		{
			if(mp[i][y] == '1')//ͬһ�д���ը�� 
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
