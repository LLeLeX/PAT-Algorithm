#include <bits/stdc++.h>
using namespace std;
int N;
double D;
struct cake{
	double store;
	double price;
	double single;
	cake(){}
}ck[1005];
double ans;
bool cmp(cake c1, cake c2)
{
	return c1.single > c2.single;
}
int main(int argc, char *argv[]) {
	scanf("%lf%lf", &N, &D);
	for(int i = 0; i < N; i++)
	{
		scanf("%lf", &ck[i].store);
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%lf", &ck[i].price);
		ck[i].single = ck[i].price / ck[i].store;
	}
	sort(ck, ck + N, cmp);
	for(int i = 0; i < N; i++)
	{
		if(ck[i].store <= D)//库存小于需求量 
		{
			ans += ck[i].price;
			D -= ck[i].store;
		}
		else
		{
			ans += D * ck[i].single;
			break;
		}
	}
	printf("%.2f", ans); 
	return 0;
}
