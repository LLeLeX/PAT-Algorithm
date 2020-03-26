#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int T;
int main(int argc, char *argv[]) {
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		ll A, B, C;
		scanf("%lld%lld%lld", &A, &B, &C);
		ll sum = (A % mod + B % mod) % mod;
		ll cc = C % mod;
		if(sum > cc)
		{
			printf("Case #%d: true\n", i);
		}
		else
		{
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}
