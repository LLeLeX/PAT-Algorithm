#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	while(n--)
	{
		int m;
		scanf("%d", &m);
		ll first, d;
		scanf("%lld", &first);//第一个数 
		for(int i = 0; i < m - 1; ++i)
		{
			ll a;
			scanf("%lld", &a);//第二个数
			/*if(first < a)//可以省略，无需注意大小 
			{
				ll temp = a;
				a = first;
				first = temp;
			}*/
			d = gcd(first, a);
			first = first / d * a;
		}
		printf("%d\n", first);
	}
	return 0;
}
