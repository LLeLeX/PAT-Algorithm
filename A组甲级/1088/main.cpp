#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fraction{
	ll up;
	ll down;
	Fraction(){}
	Fraction(ll uu, ll dd)
	{
		up = uu;
		down = dd;
	}
}num1, num2;
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	else
		gcd(b, a % b);
}
Fraction reduce(Fraction a)//三步化简 
{
	if(a.up == 0) 
	{
		a.down = 1;
	}
	if(a.down < 0)
	{
		a.up *= -1;
		a.down *= -1;
	}
	Fraction ans = a;
	ll temp = gcd(a.up, a.down);
	if(abs(temp) > 1)
	{
		ans.up /= temp;
		ans.down /= temp;
	}
	return ans;
}
Fraction add(Fraction a, Fraction b)
{
	Fraction ans;
	ans.up = a.up * b.down + a.down * b.up;
	ans.down = a.down * b.down;
	ans = reduce(ans);
	return ans;
}
Fraction sub(Fraction a, Fraction b)
{
	Fraction ans;
	ans.up = a.up * b.down - a.down * b.up;
	ans.down = a.down * b.down;
	ans = reduce(ans);
	return ans;
}
Fraction mul(Fraction a, Fraction b)
{
	Fraction ans;
	ans.up = a.up * b.up;
	ans.down = a.down * b.down;
	ans = reduce(ans);
	return ans; 
}
Fraction div(Fraction a, Fraction b)
{
	Fraction ans;
	ans.up = a.up * b.down;
	ans.down = a.down * b.up;
	ans = reduce(ans);
	return ans; 
}
void display(Fraction a)
{
	ll cof = 0;
	if(a.up < 0)
		printf("(");
	if(a.down == 1)//整数 
	{
		printf("%lld", a.up);
	}
	else if(abs(a.up) > abs(a.down))//假分数 
	{
		cof = a.up / a.down;
		a.up = abs(a.up) % a.down;
		printf("%lld %lld/%lld", cof, a.up, a.down);
	}
	else//真分数 
	{
		printf("%lld/%lld", a.up, a.down);
	}
	if(a.up < 0 || cof < 0)
		printf(")");
}
int main(int argc, char *argv[]) {
	ll up1, down1, up2, down2;
	scanf("%lld/%lld %lld/%lld", &up1, &down1, &up2, &down2);
	num1 = Fraction(up1, down1);
	num1 = reduce(num1);
	num2 = Fraction(up2, down2);
	num2 = reduce(num2);
	Fraction ans;
	
	//加法 
	display(num1);	
	printf(" + ");
	display(num2);
	printf(" = ");
	ans = add(num1, num2);
	ans = reduce(ans);
	display(ans);
	printf("\n");
	
	//减法 
	display(num1);	
	printf(" - ");
	display(num2);
	printf(" = ");
	ans = sub(num1, num2);
	ans = reduce(ans);
	display(ans);
	printf("\n");
	
	//乘法 
	display(num1);	
	printf(" * ");
	display(num2);
	printf(" = ");
	ans = mul(num1, num2);
	ans = reduce(ans);
	display(ans);
	printf("\n");
	
	//除法 
	display(num1);	
	printf(" / ");
	display(num2);
	printf(" = ");
	if(num2.up == 0)
	{
		printf("Inf\n");
		return 0;
	}
	ans = div(num1, num2);
	ans = reduce(ans);
	display(ans);
	printf("\n");
	return 0;
}
