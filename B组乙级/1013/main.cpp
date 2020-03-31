#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000005;
int m, n;
int prime[maxn], pNum;
bool isSift[maxn];//是否被筛掉，未被筛掉的为素数 
void findPrime()
{
	for(int i = 2; i < maxn; ++i)
	{
		if(!isSift[i])
		{
			prime[pNum++] = i;
			if(pNum > n)
				break;
			for(int j = i + i; j < maxn; j += i)
			{
				isSift[j] = true;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &m, &n);
	findPrime();
	int row = 0;
	for(int i = m; i <= n; ++i)
	{
		printf("%d", prime[i - 1]);
		row++;
		if(row % 10 != 0 && i < n)
			printf(" ");
		else
		{
			printf("\n");
		}
	}
	return 0;
}
