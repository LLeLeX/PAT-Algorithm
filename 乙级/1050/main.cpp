#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int matrix[maxn][maxn],A[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	if(N == 1)
	{
		printf("%d\n", A[0]);
		return 0;
	}
	sort(A, A + N, cmp);
	//计算m,n
	int m = (int)ceil(sqrt(1.0 * N));
	while(N % m != 0)
	{
		m++;
	} 
	int n = N / m;
	int i = 1, j = 1, pos = 0;
	int U = 1, D = m, L = 1, R = n;
	while(pos < N)
	{
		while(pos < N && j < R)//向右填 
		{
			matrix[i][j] = A[pos++];
			j++;
		}
		while(pos < N && i < D)
		{
			matrix[i][j] = A[pos++];
			i++;
		}
		while(pos < N && j > L)
		{
			matrix[i][j] = A[pos++];
			j--;
		}
		while(pos < N && i > U)
		{
			matrix[i][j] = A[pos++];
			i--;
		}
		U++, D--, L++, R--;//更新边界 
		i++, j++;//位置移至内层左上角
		if(pos == N - 1)
		{
			matrix[i][j] = A[pos++];
		} 
	}
	for(int i = 1; i <= m; ++i)
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
