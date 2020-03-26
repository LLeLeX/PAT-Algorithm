#include <bits/stdc++.h>
using namespace std;
int N, M;
struct Edge{
	int u, v;//边的两个端点
	int w;
	Edge(){}
	Edge(int uu, int vv, int ww)
	{
		u = uu;
		v = vv;
		w = ww;
	} 
}edges[105];
int father[105];
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
bool cmp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}
int kruskal()
{
	int ans = 0, edgeCnt = 0;
	for(int i = 0; i < M; ++i)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		int fu = findFather(u);
		int fv = findFather(v);
		if(fu != fv)
		{
			father[fu] = fv;//手动合并两个集合
			ans += w;
			edgeCnt++;	
		}
		if(edgeCnt == N - 1)
				break; 
	}
	if(edgeCnt != N - 1)
		return -1;
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[i] = Edge(u, v, w);
	}
	//并查集初始化 
	for(int i = 0; i < N; ++i)
	{
		father[i] = i;
	}
	//对边排序
	sort(edges, edges + M, cmp);
	cout << kruskal(); 
	return 0;
}
