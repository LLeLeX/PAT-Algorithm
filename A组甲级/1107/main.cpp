#include <bits/stdc++.h>
using namespace std;
int N;
int hobby[1005];//hobby[i]为第i个hobby的根节点 
int father[1005];//并查集 
int vis[1005];//记录组数中的人数 
int findFather(int x)
{
	if(x == father[x])//边界，找到根节点 
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
		father[fx] = fy; 
}
bool cmp(int a, int b)
{
	return a > b;
}
void init(int x)
{
	father[x] = x;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	/*for(int i = 1; i <= N; ++i)//初始化 
		father[i] = i;*/
	for(int i = 1; i <= N; ++i)
	{
		init(i);
		int k;
		scanf("%d: ", &k);
		while(k--)
		{
			int id;
			scanf("%d", &id);
			if(!hobby[id])//这个hobby还没有根节点（这个hobby还没有人喜欢） 
				hobby[id] = i;//第i个人为这个hobby的根节点	 
			//将当前用户与hobby中的根节点合并成一个集合 
			unionFather(hobby[id], i); 
		}
	}
	int ans = 0;//统计组数 
	for(int i = 1; i <= N; ++i)
	{
		int F = findFather(i);//找根节点 
		if(!vis[F])//新的集合 
		{
			ans++;	
		}
		vis[F]++;
	}
	printf("%d\n", ans);
	sort(vis + 1, vis + N + 1, cmp);//由于sort是从0排序的，过程中使用的第一个下标是1 
	for(int i = 1; i <= ans; i++)
	{
		//输出不为0的人数 
		printf("%d", vis[i]);
		if(i < ans)
			printf(" ");
	}
	return 0;
}
