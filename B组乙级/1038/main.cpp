#include <bits/stdc++.h>
using namespace std;
int N, K;
int cntScore[105];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		int sc;
		scanf("%d", &sc);
		cntScore[sc]++;
	}
	scanf("%d", &K);
	for(int i = 1; i <= K; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d", cntScore[temp]);
		if(i < K)
		{
			printf(" ");
		}
	}
	return 0;
}
