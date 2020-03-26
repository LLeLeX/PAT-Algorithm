#include <bits/stdc++.h>
using namespace std;
//上下左右前后 
int dir[6][3] = {{0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};
struct Node{
	int x, y, z;
	Node(){}
	Node(int xx, int yy, int zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
};
int M, N, L, T, ans;//M行 N列 L层 至少为T个 
int mp[1300][135][65];
bool inq[1300][135][65];
int bfs(int x, int y, int z)
{
	int cnt = 1;//记录块数 
	queue<Node> q;
	Node node = Node(x, y, z);
	q.push(node);
	inq[x][y][z] = true;
	while(!q.empty())
	{
		Node top = q.front();
		q.pop();
		for(int i = 0; i < 6; i++)
		{
			int tx = top.x + dir[i][0];
			int ty = top.y + dir[i][1];
			int tz = top.z + dir[i][2];
			if(tx >= 0 && tx < M && ty >= 0 && ty < N && tz >= 0 && tz < L && mp[tx][ty][tz] == 1 && !inq[tx][ty][tz])
			{
				Node temp = Node(tx, ty, tz);
				q.push(temp);
				cnt++;//找到一个相邻的1 
				inq[tx][ty][tz] = true;
			}
		}
	}
	if(cnt < T)
		return 0;
	else
		return cnt;
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for(int k = 0; k < L; k++)
	{
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &mp[i][j][k]);
			}
		}
	}
	for(int k = 0; k < L; k++)
	{
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(mp[i][j][k] == 1 && !inq[i][j][k])
				{
					ans += bfs(i, j, k);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
