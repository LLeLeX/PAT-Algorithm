#include <bits/stdc++.h>
using namespace std;
int n, r;
vector<int> ans;
int p[25];
bool vis[25];
void dfs(int num)
{
	//�߽� 
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
	//�ݹ���
	for(int i = num; i <= n; i++)//???��num��ʼ 
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
void dfs2(int index, int cnt)//ȫ���в���˳��֮�ֵ� 
{
	//�߽� 
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
	//�ݹ���
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

void DFS(int index,int nowK)//index��ʾ���ڴ���Ľڵ㣬nowK��ʾ���нڵ����
{
	if (nowK==r)//�ݹ�߽�Ϊ�������нڵ�����ﵽr�����ӡp���鲢������һ��
	{
		for (int i = 0; i < r; i++)//��� 
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[i]);
		return;
	}
	if (index > n)//�ݹ�߽磺�Ѿ��������һ���ڵ��򷵻���һ��
		return;		
	ans.push_back(index); 
	DFS(index + 1,nowK+1);//����˽ڵ�
	ans.pop_back();
	DFS(index + 1, nowK);//������˽ڵ�
}
int main(int argc, char** argv) {
	while(~scanf("%d%d", &n, &r))
	{
		DFS(1, 0);
	}
	return 0;
}
