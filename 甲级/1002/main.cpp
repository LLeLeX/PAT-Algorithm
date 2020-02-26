#include <bits/stdc++.h>
using namespace std;
int K1, K2, cnt, start = -1;
double poly[10005];
int main(int argc, char *argv[]) {
	scanf("%d", &K1);
	for(int i = 1; i <= K1; i++)
	{
		int a;
		double b;
		scanf("%d%lf", &a, &b);
		start = max(start, a);
		poly[a] += b;
		if(poly[a])
		{
			cnt++;
		}
	} 
	scanf("%d", &K2);
	for(int i = 1; i <= K2; i++)
	{
		int a;
		double b;
		scanf("%d%lf", &a, &b);
		start = max(start, a);
		if(!poly[a])
		{
			cnt++;
		}
		poly[a] += b;
		if(!poly[a])
		{
			cnt--;
		}
	}
	bool flag = false;
	printf("%d", cnt);
	if(cnt != 0)
	{
		for(int i = start + 1; i >= 0; i--)
		{
			if(poly[i])
			{
				printf(" %d %.1f", i, poly[i]);
			}
			
		}
	}
	return 0;
}
