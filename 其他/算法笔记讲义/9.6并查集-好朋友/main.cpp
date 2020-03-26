#include <bits/stdc++.h>
using namespace std;
bool vis[105];
int root[105];
int n, m;
int findRoot(int x)
{
	/*if(x == root[x])//�ݹ�߽磬�ҵ����ڵ� 
		return x;
	else//�ݹ�Ѱ�Ҹ��ڵ� 
	{
		int r = findRoot(root[x]);//r�洢���ڵ� 
		root[x] = r;//���ݽ�·���ϵ����и��ڵ㸳ֵΪr 
		return r; //���ظ��ڵ� 
	}*/
	int a = x;
	while(x != root[x])
		x = root[x];
	while(a != root[a])
	{
		int z = a;
		a = root[a];
		root[z] = x;
	}
	return x;
}
void unionRoot(int x, int y)
{
	int rx = findRoot(x);
	int ry = findRoot(y);
	if(rx != ry)
		root[rx] = ry;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)//���±�1��ʼ 
		root[i] = i;
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		unionRoot(a, b);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		//int r = findRoot(i);
		if(!vis[root[i]])//�µĸ��ڵ㼴�¼��� 
		{ 
			ans++;
			vis[root[i]] = true; 
		} 
		else//�����Ѵ��ڵļ��� 
			continue;
	}
	printf("%d", ans);
	return 0;
}
