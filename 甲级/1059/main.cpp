#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
struct Factor{
	int num;
	int cnt;
	Factor(){}
	Factor(int n, int c){
		num = n;
		cnt = c;
	}
}fac[50];
ll N;
int prime[100005], pNum;
bool isSift[maxn];
void findPrime()
{
	isSift[0] = isSift[1] = true;
	for(int i = 2; i < maxn; ++i)
	{
		if(isSift[i] == false)
		{
			prime[pNum++] = i;
			for(int j = i + i; j < maxn; j += i)
			{
				isSift[j] = true;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	findPrime();
	scanf("%lld", &N);
	ll sqr = (int)sqrt(1.0 * N), origin = N;
	int pos = 0;
	for(int i = 0; i < pNum; ++i)
	{
		if(prime[i] <= sqr)
		{
			if(N % prime[i] == 0)//包含这个质因子 
			{
				fac[pos] = Factor(prime[i], 0);//初始化 
				while(N % prime[i] == 0)
				{
					fac[pos].cnt++;
					N /= prime[i];
				}
				pos++;
			}
		}
		else
			break;
	}
	if(N != 1)
		fac[pos++] = Factor(N, 1);
	if(origin == 1)
		fac[pos++] = Factor(origin, 1);
	printf("%lld=", origin);
	for(int i = 0; i < pos; ++i)
	{
		if(fac[i].cnt > 1)
		{
			printf("%d^%d", fac[i].num, fac[i].cnt);
		}
		else
		{
			printf("%d", fac[i].num);
		}
		if(i < pos - 1)
			printf("*");
	}
	return 0;
}
