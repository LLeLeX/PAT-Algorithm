#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[105];
int main(int argc, char** argv) {
	scanf("%d%d", &N, &M);
	M = M % N;
	for(int i = 1; i <= N; i++)
	{
		if(i <= N - M)
		{
			scanf("%d", &arr[i + M]);
		}
		else
		{
			scanf("%d", &arr[i - N + M]);
		}
	}
	for(int i = 1; i <= N; i++)
	{
		if(i < N)
		{
			printf("%d ", arr[i]);
		}
		else
		{
			printf("%d", arr[i]);
		}
	}
	return 0;
}
