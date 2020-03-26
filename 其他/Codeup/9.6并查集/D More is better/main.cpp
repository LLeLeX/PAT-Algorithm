#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000001;
int n, maxcnt;
int father[maxn], num[maxn];//father:���鼯,num:��¼i�ڵ��°���num[i]����� 
void init(int x)//����Ч�ĳ�ʼ�� 
{
	father[x] = x;//��ʼ�����鼯 
	num[x] = 1;//��ʼ����ǰ���ڵ��������Ľڵ��� 
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
		num[fy] += num[fx];//������ڵ㸳ֵ���Ӧ����fx�����Ľڵ����ۼӵ�fy�� 
		if(num[fy] > maxcnt)
			maxcnt = num[fy];//�������ֵ 
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d", &n))
	{	
		vector<pair<int,int> > vec;//������Ŀ�����Ĺ�ϵ���� 
		if(n == 0)//��nΪ0��˵��ֻ��һ������ 
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
		
		for(int i = 0; i < vec.size(); ++i)//ѭ����Ч 
		{
			unionFather(vec[i].first, vec[i].second); 
		}
		printf("%d\n", maxcnt);
	}
	return 0;
}
