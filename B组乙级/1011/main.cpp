#include <bits/stdc++.h>
using namespace std;
int T;
int main(int argc, char** argv) {
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a + b > c)
		{
			printf("Case #%d: true\n", i);
		}
		else
		{
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}
