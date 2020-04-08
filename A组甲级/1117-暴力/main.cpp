#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int N;
int dist[100005];
int maxcnt[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int maxdist = -1;
	for(int i = 0; i < N; ++i)
	{
		int dd;
		scanf("%d", &dd);
		dist[i] = dd;
		maxcnt[dd]++;
		maxdist = max(maxdist, dd);
	}
	sort(dist, dist + N, cmp);
	int ans = 0; 
	for(int i = 0; i <= N; ++i)//E的取值 
	{
		int cnt = 0;
		for(int j = 0; j < N; ++j)//遍历dist数组 
		{
			if(dist[j] <= i)
				break;
			cnt++;
		}
		if(i <= cnt)
		{
			ans = i;	
		}
	}
	printf("%d", ans);
	return 0;
}
