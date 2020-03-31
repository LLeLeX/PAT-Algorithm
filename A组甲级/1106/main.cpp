#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N, minLevel = maxn;
int levelCount[maxn];
double P, r;
struct Node{
	int level;
	vector<int> child;
}nodes[maxn];
void dfs(int index, int level)
{
	nodes[index].level = level;
	if(nodes[index].child.size() == 0)//±ß½ç 
	{
		levelCount[level]++;
		minLevel = min(nodes[index].level, minLevel); 
		return;
	}
	for(int i = 0; i < nodes[index].child.size(); ++i)
	{
		dfs(nodes[index].child[i], level+ 1);
	}
}
double poww(double a, int b)
{
	if(b == 0)
		return 1.0000;
	if(b & 1)
		return a * poww(a, b - 1);
	else
	{
		double temp = poww(a, b / 2);
		return temp * temp;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%lf%lf", &N, &P, &r);
	r = 1 + r / 100;
	for(int i = 0; i < N; ++i)
	{
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j)
		{
			int childID;
			scanf("%d", &childID);
			nodes[i].child.push_back(childID);
		}
	}
	dfs(0, 0);
	printf("%.4f %d", P * poww(r, minLevel), levelCount[minLevel]);
	return 0;
}
