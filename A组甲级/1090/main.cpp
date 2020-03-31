#include <bits/stdc++.h>
using namespace std;
int N, maxLevel = -1;//节点个数
double P, r;//初始价格和 r%
struct Node{
	int level;
	vector<int> child;
}nodes[100005];
double poww(double a, int b)
{
	if(b == 0)
		return 1;
	if(b % 2 == 1)
		return a * poww(a, b - 1);
	else
	{
		double temp = pow(a, b / 2);
		return temp * temp;
	}
}
void levelOrder(int root)
{
	queue<int> q;
	q.push(root);
	nodes[root].level = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		maxLevel = max(nodes[now].level, maxLevel);
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
	int rootIndex;
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);//输入的是父节点 
		if(num == -1)//根节点 
		{
			rootIndex = i;
			continue;
		}
		nodes[num].child.push_back(i);//i为当前节点，也是子节点 
	}
	levelOrder(rootIndex);
	double price = P * poww(r, maxLevel) * 1.0;
	int cnt = 0;
	for(int i = 0; i < N; ++i)
	{
		if(nodes[i].level == maxLevel)
			cnt++;
	}
	printf("%.2f %d", price, cnt); 
	/*for(int i = 0; i < nodes[4].child.size(); i++)
		cout << nodes[4].child[i] << " " ;*/ 
	return 0;
}
