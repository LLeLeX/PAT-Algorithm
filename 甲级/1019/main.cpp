#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, b;
ll ans[100005];
int index;
void compute(ll n, ll r)
{
	do
	{
		ll ret = n % r;
		ans[index++] = ret;
		n /= r;
	}while(n);
}
int main(int argc, char *argv[]) {
	scanf("%lld%lld", &N, &b);
	compute(N, b);
	bool flag = true;
	for(int i = index - 1; i >= index / 2; i--)
	{
		if(ans[i] != ans[index - i - 1])
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for(int i = index - 1; i >= 0; i--)
	{
		printf("%lld", ans[i]);
		if(i > 0)
		{
			printf(" ");
		}
	}
	return 0;
}
