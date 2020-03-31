#include <bits/stdc++.h>
using namespace std;
int N;
int hobby[1005];//hobby[i]Ϊ��i��hobby�ĸ��ڵ� 
int father[1005];//���鼯 
int vis[1005];//��¼�����е����� 
int findFather(int x)
{
	if(x == father[x])//�߽磬�ҵ����ڵ� 
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
	/*for(int i = 1; i <= N; ++i)//��ʼ�� 
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
			if(!hobby[id])//���hobby��û�и��ڵ㣨���hobby��û����ϲ���� 
				hobby[id] = i;//��i����Ϊ���hobby�ĸ��ڵ�	 
			//����ǰ�û���hobby�еĸ��ڵ�ϲ���һ������ 
			unionFather(hobby[id], i); 
		}
	}
	int ans = 0;//ͳ������ 
	for(int i = 1; i <= N; ++i)
	{
		int F = findFather(i);//�Ҹ��ڵ� 
		if(!vis[F])//�µļ��� 
		{
			ans++;	
		}
		vis[F]++;
	}
	printf("%d\n", ans);
	sort(vis + 1, vis + N + 1, cmp);//����sort�Ǵ�0����ģ�������ʹ�õĵ�һ���±���1 
	for(int i = 1; i <= ans; i++)
	{
		//�����Ϊ0������ 
		printf("%d", vis[i]);
		if(i < ans)
			printf(" ");
	}
	return 0;
}
