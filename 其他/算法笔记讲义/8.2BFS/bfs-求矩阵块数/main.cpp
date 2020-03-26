#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x, y;
	Node(){}
	Node(int xx, int yy){
		x = xx;
		y = yy;
	}
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, ans;
int mp[10][10]; 
bool vis[10][10];
void bfs(int x, int y)
{
	queue<Node> q;
	Node node = Node(x, y);
	q.push(node);
	vis[node.x][node.y] = true;
	while(!q.empty())
	{
		Node top = q.front();//取队首元素 
		/*if(mp[top.x][top.y] == 0)//边界 
		{
			q.pop();
			continue;
		}*/
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int tx = top.x + dir[i][0];
			int ty = top.y + dir[i][1];
			if(!vis[tx][ty] && tx >= 0 && tx < n && ty >= 0 && ty < m && mp[top.x][top.y] == 1)
			{
				Node temp = Node(tx, ty);
				q.push(temp);
				vis[tx][ty] = true;
			}
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
				bfs(i, j);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
