#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int N;
int father[maxn];//��iֻ�����father[i]ֻ������ͬһ���� 
bool vis[maxn];//������ĸ��� 
void init()
{
	for(int i = 1; i < maxn; ++i)
	{
		father[i] = i;
	}
}
int findFather(int x)
{
	if(x == father[x])
		return x;
	else
	{
		int f = findFather(father[x]);
		father[x] = f;
		return f;
	}
}
void unionFather(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if(fx != fy)
		father[fx] = fy;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	init();
	int maxBird = -1;//�洢�������� 
	for(int i = 0; i < N; ++i)
	{
		int K, firBird;//�洢ÿ����Ƭ��һֻ��ı�� 
		scanf("%d", &K);
		for(int i = 0; i < K; ++i)
		{
			int bird;
			scanf("%d", &bird);
			maxBird = max(maxBird, bird);
			if(i == 0)//��һֻ����Ϊ�� 
			{
				firBird = bird;
				continue;
			}
			unionFather(firBird, bird);
		}
	}
	int treecnt = 0;
	for(int i = 1; i <= maxBird; ++i)
	{
		int pos = findFather(i);//�ٴθ��¸��ڵ� 
		if(vis[pos] == false)
		{
			treecnt++;
			vis[pos] = true;
		}
			//cout << father[i] << " ";
	}
	//cout << endl;
	printf("%d %d\n", treecnt, maxBird);	
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i)
	{
		int b1, b2;
		scanf("%d%d", &b1, &b2);
		/*int fb1 = findFather(b1);
		int fb2 = findFather(b2);*/
		if(father[b1] == father[b2])
			printf("Yes\n");
		else
			printf("No\n");
	} 
	return 0;
}
