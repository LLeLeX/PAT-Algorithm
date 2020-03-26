#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Node{
	int x, y;
	int step = 0;
	Node(){}
	Node(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};
int n, m; 
char mp[10][10];
bool vis[10][10];
int bfs(int x, int y)
{
	queue<Node> q;
	Node node = Node(x, y);
	q.push(node);
	vis[x][y] = true;//标记位已入队 
	while(!q.empty())
	{
		Node top = q.front();
		q.pop();
		if(mp[top.x][top.y] == 'T')
		{
			return top.step;
		}
		for(int i = 0; i < 4; i++)
		{
			int tx = top.x + dir[i][0];
			int ty = top.y + dir[i][1];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] != '*' && !vis[tx][ty])
			{
				Node temp = Node(tx, ty);
				temp.step = top.step + 1;
				q.push(temp);
				vis[tx][ty] = true;
			}
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", mp[i]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mp[i][j] == 'S')
			{
				printf("%d", bfs(i, j));
				break;
			}
		}
	}
	return 0;
}
