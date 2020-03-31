#include <bits/stdc++.h>
using namespace std;
int N;
double D;
struct Cake{
	double amount;
	double price;
	double single;
}cakes[1005];
bool cmp(Cake c1, Cake c2)
{
	return c1.single > c2.single;
}
int main(int argc, char *argv[]) {
	scanf("%d%lf", &N, &D);
	for(int i = 0; i < N; ++i)
	{
		scanf("%lf", &cakes[i].amount);
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%lf", &cakes[i].price);
		cakes[i].single = cakes[i].price / cakes[i].amount;
	}
	sort(cakes, cakes + N, cmp);
	double ans = 0;
	for(int i = 0; i < N; ++i)
	{
		if(cakes[i].amount > D)
		{
			ans += cakes[i].single * D;
			break;
		}
		else
		{
			ans += cakes[i].price;
			D -= cakes[i].amount;
		}
	}
	printf("%.2f", ans);
	return 0;
}
