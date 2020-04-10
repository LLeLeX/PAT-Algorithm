#include <bits/stdc++.h>
using namespace std;
int N;
double segment[10005];
bool cmp(int a, int b)
{
	return a < b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%lf", &segment[i]);
	}
	sort(segment, segment + N, cmp);
	double ans = segment[0];
	for(int i = 1; i < N; ++i)
	{
		ans = (ans + segment[i]) * 1.0 / 2;
	}
	printf("%d", (int)floor(ans));
	return 0;
}
