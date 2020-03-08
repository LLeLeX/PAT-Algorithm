#include <bits/stdc++.h>
using namespace std;
double poly[10005];
double ans[10005];
int K1, K2, cnt;
int main(int argc, char *argv[]) {
	int start = -1;//记录最高次项 
	scanf("%d", &K1);
	for(int i = 1; i <= K1; i++)
	{
		int a;
		double b;
		scanf("%d%lf", &a, &b);
		start = max(start, a);
		poly[a] = b;
	}
	scanf("%d", &K2);
	for(int i = 1; i <= K2; i++)
	{
		int a;
		double b;
		scanf("%d%lf", &a, &b);
		for(int j = 0; j <= start; j++)//对一式逐个相乘再相加 
		{
			if(poly[j])
			{
				int index = j + a;//相乘后的指数 
				ans[index] += poly[j] * b;//相乘后的系数 
			} 
		}
	}
	for(int i = 0; i < 10005; i++)
	{
		if(ans[i])
		{
			cnt++;
		}
	}
	printf("%d", cnt);
	for(int i = 10004; i >= 0; i--)
	{
		if(ans[i])
		{
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}
