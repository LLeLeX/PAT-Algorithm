#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int N;
int hashtable[maxn];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int maxdist = -1;
	for(int i = 0; i < N; ++i)
	{
		int dd;
		scanf("%d", &dd);
		hashtable[dd]++;
		maxdist = max(maxdist, dd);
	}
	for(int i = maxdist - 1; i >= 0; --i)
	{
		if(i > hashtable[i + 1])
		{
			hashtable[i] += hashtable[i + 1];
		}
		else
		{
			printf("%d", i);
			//break;
			return 0;
		}
	}
	printf("0");
	return 0;
}
