#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int N;
int prime[maxn], pNum;
bool isSift[maxn];
void findPrime()
{
	for(int i = 2; i < maxn; ++i)
	{
		if(!isSift[i])
		{
			prime[pNum++] = i;
			if(i > N)
				break;
			for(int j = i + i; j < maxn; j += i)
			{
				isSift[j] = true;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	findPrime();
	int ans = 0;
	for(int i = 1; i < pNum; ++i)
	{
		if(prime[i] <= N && prime[i] - prime[i - 1] == 2)
			ans++;
	}
	printf("%d", ans);
	return 0;
}
