#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int ans;
char str[100005];
int cntP[100005], cntT[100005];
int main(int argc, char *argv[]) {
	scanf("%s", str);
	int len = strlen(str);
	int indexP = 1;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == 'P')
		{
			cntP[indexP]++;
		}
		else if(str[i] == 'A')
		{
			cntP[indexP] += cntP[indexP - 1];
			indexP++;
		}
	}
	int indexT = indexP - 1; 
	for(int i = len - 1; i >= 0; i--)
	{
		if(str[i] == 'T')
		{
			cntT[indexT]++;
		}
		else if(str[i] == 'A')
		{
			cntT[indexT - 1] += cntT[indexT];
			indexT--;
		}
	} 
	for(int i = 1; i <= indexP; i++)
	{
		ans += cntP[i] * cntT[i] % mod;
		ans %= mod;
	}
	printf("%lld", ans);
	return 0;
}
