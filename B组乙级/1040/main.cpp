#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int len;
char str[maxn];
struct Count {
	int cntP = 0, cntT = 0;
	Count(){}
	Count(int p, int t)
	{
		cntP = p;
		cntT = t;
	}
}countA[maxn];
int main(int argc, char *argv[]) {
	scanf("%s", str);
	len = strlen(str);
	int cntA = 0, cntP = 0, cntT = 0;
	for(int i = 0; i < len; ++i)
	{
		if(str[i] == 'P')
		{
			cntP++;	
		}
		else if(str[i] == 'A')
		{
			countA[i].cntP = cntP;
		}
	}
	for(int i = len - 1; i >= 0; --i)
	{
		if(str[i] == 'T')
		{
			cntT++;	
		}
		else if(str[i] == 'A')
		{
			countA[i].cntT = cntT;
		}
	}
	int ans = 0;
	for(int i = 0; i < len; ++i)
	{
		int temp = (countA[i].cntP * countA[i].cntT) % mod;
		ans = (ans + temp) % mod; 
	}
	printf("%d", ans);
	return 0;
}
