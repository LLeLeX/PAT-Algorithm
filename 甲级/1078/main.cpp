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
	if(hashtable[pos])//��ǰλ���Ѿ���ֵ 
	{
		return false;//������ͻ 
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
	if(isPrime[Msize])//������������ 
	{
		for(int i = 0; i < N; ++i)
		{
			int num;
			scanf("%d", &num);
			int hash = getHash(num, Msize);
			bool flag = false;//����Ƿ�̽��ɹ� 
			//̽�� 
			if(check(hash))
			{
				printf("%d", hash);
			}
			else
			{
				for(int step = 1; step <= Msize; step++)//����̽�� 
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
	else//�������� 
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
			bool flag = false;//����Ƿ�̽��ɹ� 
			//̽�� 
			if(check(hash))
			{
				printf("%d", hash);
			}
			else
			{
				for(int step = 1; step <= Msize; step++)//����̽�� 
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
