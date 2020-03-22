#include <bits/stdc++.h>
using namespace std;
double a[10];
bool f[10];
int N , cnt;
int main(int argc, char** argv) {
	int cnta4 = 0;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &N);
		if(N % 5 == 0 && N % 2 == 0)
		{
			f[1] = true;
			a[1] += N;
		}
		if(N % 5 == 1)
		{
			f[2] = true;
			a[2] += N * pow(-1, cnt);
			cnt++;
		}
		if(N % 5 == 2)
		{
			f[3] = true;
			a[3]++;
		}
		if(N % 5 == 3)
		{
			f[4] = true;
			cnta4++;
			a[4] += N;
		}
		if(N % 5 == 4)
		{
			f[5] = true;
			a[5] = max(N, (int)a[5]);
		}
	}
	a[4] = a[4] / cnta4;
	for(int i = 1; i <= 5; i++)
	{
		if(!f[i] && i < 4)
		{
			printf("N ");
		}
		if(f[i] && i < 4)
		{
			printf("%d ", (int)a[i]);
		}
		if(!f[i] && i == 4)
		{
			printf("N ");
		}
		if(f[i] && i == 4)
		{
			printf("%.1f ", a[4]);
		}
		if(!f[i] && i == 5)
		{
			printf("N");
		}
		if(f[i] && i == 5)
		{
			printf("%d", (int)a[5]);
		}
	}
	return 0;
}
