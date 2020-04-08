#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
bool hashtable[maxn];
int N, K;
struct Student{
	int id;
	int reward;
	bool check = false;//标记是否check 
}stu[maxn];
bool isPrime(int n)//暴力判断素数 
{
	if(n == 0 || n == 1)
		return true;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
int Primeinfo[maxn];
int pos;
bool isSift[maxn];//表示是否被筛掉，没筛掉是素数 
void getPrimeinfo()//素数筛
{
	isSift[0] = isSift[1] = true;
	for(int i = 2; i < maxn; ++i)
	{
		if(isSift[i] == false)
		{
			Primeinfo[pos++] = i;
			for(int j = i + i; j < maxn; j += i)
			{
				isSift[j] = true;
			}
		}
	}
} 


int main(int argc, char *argv[]) {
	scanf("%d", &N);
	getPrimeinfo();
	for(int i = 1; i <= N; ++i)
	{
		int id;
		scanf("%d", &id);
		hashtable[id] = true;
		stu[id].id = id;
		if(i == 1)
		{
			stu[id].reward = 0;
		}
		else if(isSift[i] == false)
		{
			stu[id].reward = 1;
		}
		else
		{
			stu[id].reward = 2;
		}
	}
	scanf("%d", &K);
	for(int i = 0; i < K; ++i)
	{
		int query;
		scanf("%d", &query);
		if(hashtable[query] == false)
			printf("%04d: Are you kidding?\n", query);
		else if(stu[query].check == true)
			printf("%04d: Checked\n", query);
		else
		{
			if(stu[query].reward == 0)
				printf("%04d: Mystery Award\n", query);
			else if(stu[query].reward == 1)
				printf("%04d: Minion\n", query);
			else
				printf("%04d: Chocolate\n", query);
			stu[query].check = true;
		}
	}
	return 0;
}
