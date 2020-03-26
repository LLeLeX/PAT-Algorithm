#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
bool flag, viscol[35], vis1[35], vis2[35];//列，斜对角线1，斜对角线2 
bool check(int r, int c)
{
	if(!viscol[c] && !vis1[r + c] && !vis2[r - c + n])
	{
		return true;//无冲突 
	}
	else
	{
		return false;//有冲突 
	}
} 
//row：行 ,根据行进行遍历 
void dfs(int row)
{
	if(row == n)//边界2 与if(ans.size() == n)等效 
	{
		for(int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i] + 1);
		}
		flag = true;
		printf("\n");
		return;
	}
	//递归体,对列进行遍历 
	for(int i = 0; i < n; i++)
	{
		if(check(row, i))//行列，俩斜线均无冲突 
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
