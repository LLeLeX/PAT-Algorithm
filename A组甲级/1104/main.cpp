#include <bits/stdc++.h>
using namespace std;
double N;
double num[100005];
int main(int argc, char *argv[]) {
	scanf("%lf", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%lf", &num[i]);
	}
	double ans = 0;
	for(int i = 1; i <= N; ++i)
	{
		ans += (N - i + 1) * i * num[i];
	}
	printf("%.2f", ans);
	return 0;
}
