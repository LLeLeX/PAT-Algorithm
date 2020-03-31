#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fraction{
	ll up, down;
	Fraction(){}
	Fraction(ll u, ll d)
	{
		up = u;
		down = d;
	}
}num1, num2;
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
		f.down = -1 * f.down;
		f.up = -1 * f.up;
	}
	ll d = gcd(abs(f.up), abs(f.down));
	if(d > 1)
	{
		f.down /= d;
		f.up /= d;
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
Fraction sub(Fraction f1, Fraction f2)
{
	Fraction ans;
	ans.up = f1.up * f2.down - f2.up * f1.down;
	ans.down = f1.down * f2.down;
	ans = reduction(ans);
	return ans;
}
Fraction mul(Fraction f1, Fraction f2)
{
	Fraction ans;
	ans.up = f1.up * f2.up;
	ans.down = f1.down * f2.down;
	ans = reduction(ans);
	return ans;
}
Fraction div(Fraction f1, Fraction f2)
{
	Fraction ans;
	ans.up = f1.up * f2.down;
	ans.down = f1.down * f2.up;
	ans = reduction(ans);
	return ans;
}
void display(Fraction f)
{
	ll cof = 0;
	if(f.up < 0)
		printf("(");
	if(f.down == 1)
	{
		printf("%lld", f.up);
	}
	else if(abs(f.up) > f.down)
	{
		cof = f.up / f.down;
		f.up = abs(f.up) % f.down;
		printf("%lld %lld/%lld", cof, f.up, f.down);
	}
	else
	{
		printf("%lld/%lld", f.up, f.down);
	}
	if(f.up < 0 || cof < 0) 
	{
		printf(")");
	}
}
int main(int argc, char *argv[]) {
	ll a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	num1 = Fraction(a1, b1);
	num2 = Fraction(a2, b2);
	num1 = reduction(num1);
	num2 = reduction(num2);
	Fraction ans;
	//加法 
	display(num1);
	printf(" + ");
	display(num2);
	printf(" = ");
	ans = add(num1, num2);
	display(ans);
	printf("\n");
	//减法
	display(num1);
	printf(" - ");
	display(num2);
	printf(" = ");
	ans = sub(num1, num2);
	display(ans);
	printf("\n"); 
	//乘法
	display(num1);
	printf(" * ");
	display(num2);
	printf(" = ");
	ans = mul(num1, num2);
	display(ans);
	printf("\n"); 
	//除法
	display(num1);
	printf(" / ");
	display(num2);
	printf(" = ");
	if(num2.up != 0)
	{
		ans = div(num1, num2);
		display(ans);
	}
	else
	{
		printf("Inf");
	}
	printf("\n"); 
	return 0;
}
