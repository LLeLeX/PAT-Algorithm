#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
struct Fraction{
	ll up, down;
	Fraction(){}
	Fraction(ll u, ll d)
	{
		up = u;
		down = d;
	}
}num[105];
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
Fraction reduction(Fraction f)
{
	if(f.up == 0)
		f.down = 1;
	if(f.down < 0)
	{
		f.up = -1 * f.up;
		f.down = -1 * f.down;
	}
	ll d = gcd(abs(f.up), abs(f.down));
	if(d > 1)
	{
		f.up /= d;
		f.down /= d;
	}
	return f;
}
Fraction add(Fraction f1, Fraction f2)
{
	Fraction ans;
	ans.up = f1.up * f2.down + f2.up * f1.down;
	ans.down = f1.down * f2.down;
	ans = reduction(ans);
	return ans;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	Fraction ans;
	for(int i = 0; i < N; ++i)
	{
		ll u, d;
		scanf("%lld/%lld", &u, &d);
		num[i] = Fraction(u, d);
		num[i] = reduction(num[i]);
		if(i == 0)
			ans = num[i];
		if(i > 0)
		{
			ans = add(ans, num[i]);
		}
	}
	if(ans.down == 1)
	{
		printf("%lld\n", ans.up);
	}
	else if(ans.up < ans.down)
	{
		printf("%lld/%lld\n", ans.up, ans.down);
	}
	else if(ans.up > ans.down)
	{
		ll cof = ans.up / ans.down;
		ans.up = ans.up % ans.down;//！！！ans.up要加绝对值 
		printf("%lld %lld/%lld\n", cof, ans.up, ans.down);
	}
	return 0;
}
