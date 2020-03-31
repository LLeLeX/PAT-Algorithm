#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int Msize, N;
bool hashtable[maxn];
int prime[maxn], pNum;
bool isPrime[maxn];
void findPrime()
{
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < maxn; ++i)
	{
		if(isPrime[i])
		{
			prime[pNum++] = i;
			for(int j = i + i; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
int getHash(int n, int size)
{
	return n % size;
} 
bool check(int pos)
{
	if(hashtable[pos])//当前位置已经有值 
	{
		return false;//产生冲突 
	}
	else
	{
		hashtable[pos] = true;
		return true;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &Msize, &N);
	memset(isPrime, true, sizeof(isPrime));
	findPrime();
	if(isPrime[Msize])//给出的是素数 
	{
		for(int i = 0; i < N; ++i)
		{
			int num;
			scanf("%d", &num);
			int hash = getHash(num, Msize);
			bool flag = false;//标记是否探测成功 
			//探测 
			if(check(hash))
			{
				printf("%d", hash);
			}
			else
			{
				for(int step = 1; step <= Msize; step++)//二次探测 
				{
					int key = num + step * step;
					hash = getHash(key, Msize);
					if(check(hash))
					{
						flag = true;
						printf("%d", hash);
						break;
					}
				}
				if(!flag)
					printf("-");
			}
			
			if(i < N - 1)
				printf(" ");
		}
	}
	else//不是素数 
	{
		for(int i = 0; i < pNum; ++i)
		{
			if(prime[i] > Msize)
			{
				Msize = prime[i];
				break;
			}
		}
		for(int i = 0; i < N; ++i)
		{
			int num;
			scanf("%d", &num);
			int hash = getHash(num, Msize);
			bool flag = false;//标记是否探测成功 
			//探测 
			if(check(hash))
			{
				printf("%d", hash);
			}
			else
			{
				for(int step = 1; step <= Msize; step++)//二次探测 
				{
					int key = num + step * step;
					hash = getHash(key, Msize);
					if(check(hash))
					{
						flag = true;
						printf("%d", hash);
						break;
					}
				}
				if(!flag)
					printf("-");
			}
			
			if(i < N - 1)
				printf(" ");
		}
	}
	return 0;
}
