#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
bool flag, viscol[35], vis1[35], vis2[35];//�У�б�Խ���1��б�Խ���2 
bool check(int r, int c)
{
	if(!viscol[c] && !vis1[r + c] && !vis2[r - c + n])
	{
		return true;//�޳�ͻ 
	}
	else
	{
		return false;//�г�ͻ 
	}
} 
//row���� ,�����н��б��� 
void dfs(int row)
{
	if(row == n)//�߽�2 ��if(ans.size() == n)��Ч 
	{
		for(int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i] + 1);
		}
		flag = true;
		printf("\n");
		return;
	}
	//�ݹ���,���н��б��� 
	for(int i = 0; i < n; i++)
	{
		if(check(row, i))//���У���б�߾��޳�ͻ 
		{
			viscol[i] = vis1[row + i] = vis2[row - i + n] = true;
			ans.push_back(i);
			dfs(row + 1);
			viscol[i] = vis1[row + i] = vis2[row - i + n] = false;
			ans.pop_back();
		}
	}
}
int main(int argc, char** argv) {
	while(scanf("%d", &n) != EOF)
	{
		dfs(0);
		if(!flag)
		{
			printf("no solute!");
		} 
	}
	return 0;
}
