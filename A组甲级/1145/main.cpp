#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int Msize, N, M;
bool isPrime(int x)
{
	if(x == 0 || x == 1)
		return false;
	int sqr = (int)sqrt(1.0 * x);
	for(int i = 2; i <= sqr; ++i)
	{
		if(x % i == 0)
			return false;
	}
	return true;
} 
int hashtable[maxn]; //散列表 
int hashcnt[maxn];//比较次数 
int getHash(int x)
{
	int i = 0;
	for(i = 0; i <= Msize; ++i)
	{
		int temp = i * i;//二次探测 
		int pos = (x + temp) % Msize;
		if(hashtable[pos] == 0)
		{
			hashtable[pos] = x;
			return pos;
		}
	}
	if(i == Msize + 1)//十次探测失败
		return -1;
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &Msize, &N, &M);
	while(isPrime(Msize) == false)
	{
		Msize++;
	}
	for(int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		int pos = getHash(x);
		if(pos == -1)
			printf("%d cannot be inserted.\n", x);
	}
	int ans = 0;
	for(int i = 0; i < M; ++i)
	{
		int x;
		scanf("%d", &x);
		for(int j = 0; j <= Msize; ++j)
		{
			ans++;
			int pos = (x + j * j) % Msize;
			if(hashtable[pos] == 0 || hashtable[pos] == x)
			{
				break;
			}
		}
	}
	printf("%.1f\n", ans * 1.0 / M);
	return 0;
}
