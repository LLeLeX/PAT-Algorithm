#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, origin;
int main(int argc, char *argv[]) {
	scanf("%lld", &N);
	origin = N;
	ll sqr = (ll)sqrt(1.0 * N);
	ll ansL = 0, anspos, tempL, temppos;//数字长度和起始数字 
	for(int i = 2; i <= sqr; ++i)//起始数字 
	{
		N = origin;
		tempL = 0;
		temppos = i;
		for(int j = i; j <= sqr + 1; ++j)
		{
			if(N % j == 0)
			{
				tempL++;
				N /= j;
			}
			else
			{
				if(tempL > ansL)
				{
					ansL = tempL;
					anspos = temppos;
				}
				break;
			}
		}
	}
	if(ansL == 0)
	{
		ansL = 1;
		anspos = origin;
	}
	printf("%lld\n", ansL);
	for(int i = anspos; i < anspos + ansL; ++i)
	{
		printf("%lld", i);
		if(i < anspos + ansL - 1)
			printf("*");
	}
	return 0;
}
