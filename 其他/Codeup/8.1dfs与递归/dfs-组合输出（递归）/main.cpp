#include <bits/stdc++.h>
using namespace std;
int n, r;
vector<int> ans;
int p[25];
bool vis[25];
void dfs(int num)
{
	//边界 
	if(num == n + 1)
	{
		return;
	}
	if(ans.size() == r)
	{
		for(int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	//递归体
	for(int i = num; i <= n; i++)//???从num开始 
	{
		if(!vis[i - 1])//?????
		{
			vis[i - 1] = true;
			ans.push_back(i);
			dfs(i);//??????
			ans.pop_back();
			vis[i - 1] = false;
		}
	}
}
void dfs2(int index, int cnt)//全排列并有顺序之分的 
{
	//边界 
	if(index == n + 1)
	{
		return;
	}
	if(cnt == r)
	{
		for(int i = 1; i <= cnt; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	//递归体
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])//?????
		{
			vis[i] = true;
			p[index] = i;
			dfs2(index + 1, cnt + 1);
			vis[i] = false;
		}
	}
}

void DFS(int index,int nowK)//index表示正在处理的节点，nowK表示已有节点个数
{
	if (nowK==r)//递归边界为：当现有节点个数达到r，则打印p数组并返回上一层
	{
		for (int i = 0; i < r; i++)//输出 
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[i]);
		return;
	}
	if (index > n)//递归边界：已经处理到最后一个节点则返回上一层
		return;		
	ans.push_back(index); 
	DFS(index + 1,nowK+1);//加入此节点
	ans.pop_back();
	DFS(index + 1, nowK);//不加入此节点
}
int main(int argc, char** argv) {
	while(~scanf("%d%d", &n, &r))
	{
		DFS(1, 0);
	}
	return 0;
}
