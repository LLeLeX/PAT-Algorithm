#include <bits/stdc++.h>
using namespace std;
int N;
int teams[1005];
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		int t, p, s;
		scanf("%d-%d %d", &t, &p, &s);
		teams[t] += s;
	}
	int ans = 0;
	int len = sizeof(teams) / sizeof(teams[0]);
	cout << len << endl;
	for(int i = 1; i <= 1000; i++)
	{
		if(teams[i] > teams[ans])
		{
			ans = i;
		}
	}
	printf("%d %d", ans, teams[ans]);
	return 0;
}
