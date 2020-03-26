#include <bits/stdc++.h>
using namespace std;
int n, cnt;
vector<int> ans[100], temp;//����x�ĵ�y��
bool viscol[35], vis1[35], vis2[35];
bool check(int x, int y)
{
	if(!viscol[y] && !vis1[x + y] && !vis2[x - y + 8])
		return true;
	else
		return false;
}
//x:��, cnt:��ǰ������
void dfs(int row)
{
	if(row == 8)
	{
		ans[cnt] = temp;
		cnt++;
		return; 
	}
	for(int i = 0; i < 8; i++)//�� 
	{
		if(check(row, i))//���У���б�߾��޳�ͻ 
		{
			viscol[i] = vis1[row + i] = vis2[row - i + 8] = true;
			temp.push_back(i);
			dfs(row + 1);
			temp.pop_back();
			viscol[i] = vis1[row + i] = vis2[row - i + 8] = false;
		}
	}
}
int main(int argc, char *argv[]) {
	dfs(0);
	scanf("%d", &n);
	while(n--)
	{
		int m;
		scanf("%d", &m);
		for(int i = 0; i < ans[m].size(); i++)
		{
			printf("%d", ans[m - 1][i] + 1);
		}
		printf("\n");
	}
	return 0;
}
