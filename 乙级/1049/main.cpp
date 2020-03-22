#include <bits/stdc++.h>
using namespace std;
int N;
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	double ans = 0;
	for(int i = 1; i <= N; ++i)
	{
		double num;
		scanf("%lf", &num);
		ans += num * i * (N + 1 - i); 
	}
	printf("%.2f", ans);
	return 0;
}
