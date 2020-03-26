#include <bits/stdc++.h>
using namespace std;
int N;//节点个数 
double P, r, ans = 0.00;;//初始价格，百分比 
struct Node{
	int count, level;//货物数目及层数 
	vector<int> child;
}nodes[100005];
double poww(double a, int b)
{
	if(b == 0)
		return 1.00;
	if(b & 1)
		return a * poww(a, b - 1);
	else
	{
		double temp = poww(a, b / 2);
		return temp * temp;
	}
}
void levelOrder()//0为根节点下标 
{
	queue<int> q;
	q.push(0);
	nodes[0].level = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(nodes[now].child.size() == 0)//为叶子节点 
		{
			ans += nodes[now].count * P * poww(r, nodes[now].level);
		}
		for(int i = 0; i < nodes[now].child.size(); ++i)
		{
			int child = nodes[now].child[i];
			nodes[child].level = nodes[now].level + 1;
			q.push(child);
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%lf%lf", &N, &P, &r);
	r = 1 + r / 100;
	for(int i = 0; i < N; ++i)
	{
		int k;//子节点个数 
		scanf("%d", &k);
		if(!k)//k=0时，为叶子节点 
		{
			int cnt;
			scanf("%d", &cnt);
			nodes[i].count = cnt;//记录货物数目 
		} 
		else
		{
			for(int j = 0; j < k; ++j)
			{
				int temp;
				scanf("%d", &temp);
				nodes[i].child.push_back(temp);//记录当前节点的子节点 
			}
		}
	}	
	levelOrder();
	printf("%.1f", ans);
	return 0;
}
