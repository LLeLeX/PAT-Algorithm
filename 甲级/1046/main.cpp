#include <bits/stdc++.h>
using namespace std;
int N, M;
int dis[100005];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int sum = 0;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &dis[i]);
		sum += dis[i]; 
		dis[i] += dis[i - 1];
	}
	scanf("%d", &M);
	while(M--)
	{
		int a, b;
		int dist1 = 0, dist2 = 0;
		scanf("%d%d", &a, &b);
		int temp = 0;
		if(a > b)//a是较小的顶点 
		{
			temp = a;
			a = b;
			b = temp;
		}
		//正向 
		dist1 = dis[b - 1] - dis[a - 1];
		//反向 
		dist2 =sum - dist1;
		int ans = min(dist1, dist2);
		printf("%d\n", ans);
	}
	return 0;
}
