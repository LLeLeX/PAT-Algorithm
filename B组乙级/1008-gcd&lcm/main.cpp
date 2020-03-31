#include <bits/stdc++.h>
using namespace std;
int N, M;
int num[105];
int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	//temp:临时变量，pos:存放当前处理位置,next:下一个要处理的位置 
	int temp, pos, next;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	M = M % N;
	if(M != 0)
	{
		int d = gcd(M, N);
		for(int i = N - M; i < N - M + d; ++i)
		{
			temp = num[i];
			pos = i;
			do{
				next = (pos - M + N) % N;
				if(next != i)
					num[pos] = num[next];
				else
					num[pos] = temp;
				pos = next;
			}while(pos != i);
		}
	}
	for(int i = 0; i < N; ++i)
	{
		printf("%d", num[i]);
		if(i < N - 1)
			printf(" ");
		else
			printf("\n"); 
	}
	return 0;
}
