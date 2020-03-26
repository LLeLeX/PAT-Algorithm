#include <bits/stdc++.h>
using namespace std;
int n, m;
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main(int argc, char *argv[]) {
	while(~scanf("%d%d", &n, &m))
	{
		if(n < m)//把n调整为大数 
		{
			int temp = m;
			m = n;
			n = temp;
		}
		printf("%d\n", gcd(n, m));
	}
	return 0;
}
