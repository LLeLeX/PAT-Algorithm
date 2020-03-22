#include <bits/stdc++.h>
using namespace std;
int N, M;
int num[105];
void display()
{
	for(int i = 0; i < N; ++i)
	{
		printf("%d", num[i]);
		if(i < N - 1)
			printf(" ");
		else
			printf("\n");
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	for(int i = 0; i < M; ++i)
	{
		int pos = num[N - 1];
		for(int j = N - 1; j >= 0; --j)
		{
			num[j + 1] = num[j];
		}
		num[0] = pos;
	}
	display();
	return 0;
}
