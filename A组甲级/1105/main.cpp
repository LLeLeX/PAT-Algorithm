#include <bits/stdc++.h>
using namespace std;
int N;
int num[100005];
int matrix[10010][10010];
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	if(N == 1)
	{
		printf("%d", num[0]);
		return 0;
	}
	sort(num, num + N, cmp);
	int m = (int)ceil(sqrt(1.0 * N));
	while(N % m != 0)
	{
		m++;
	}
	int n = N / m;
	int pos = 0;
	int i = 1, j = 1;
	int U = 1, D = m, L = 1, R = n;
	while(pos < N)
	{
		while(pos < N && j < R)
		{
			matrix[i][j] = num[pos++];
			j++;
		}
		while(pos < N && i < D)
		{
			matrix[i][j] = num[pos++];
			i++;
		}
		while(pos < N && j > L)
		{
			matrix[i][j] = num[pos++];
			j--;
		}
		while(pos < N && i > U)
		{
			matrix[i][j] = num[pos++];
			i--;
		}
		U++, D--, L++, R--;
		i++, j++;
		if(pos == N - 1)
		{
			matrix[i][j] = num[pos++];
		}
	}
	for(int i =1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			printf("%d", matrix[i][j]);
			if(j < n)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
