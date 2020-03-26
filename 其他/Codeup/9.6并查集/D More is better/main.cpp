#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000001;
int n, maxcnt;
int father[maxn], num[maxn];//father:并查集,num:记录i节点下包含num[i]个结点 
void init(int x)//更高效的初始化 
{
	father[x] = x;//初始化并查集 
	num[x] = 1;//初始化当前根节点所包含的节点数 
}
int findFather(int x)
{
	if(x == father[x])
		return x;
	else
	{
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
}
void unionFather(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if(fx != fy)
	{
		father[fx] = fy; 
		num[fy] += num[fx];//与上面节点赋值相对应，把fx包含的节点数累加到fy中 
		if(num[fy] > maxcnt)
			maxcnt = num[fy];//更新最大值 
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &n))
	{	
		vector<pair<int,int> > vec;//保存题目给出的关系数据 
		if(n == 0)//当n为0，说明只有一个男生 
		{
			printf("1\n");
			continue;
		} 
		maxcnt = -1;
		for(int i = 0; i < n; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			init(a);
			init(b);
			vec.push_back(make_pair(a, b));
			//unionFather(a, b); 
		}
		
		for(int i = 0; i < vec.size(); ++i)//循环高效 
		{
			unionFather(vec[i].first, vec[i].second); 
		}
		printf("%d\n", maxcnt);
	}
	return 0;
}
