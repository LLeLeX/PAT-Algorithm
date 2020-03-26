#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll p = 1e7 + 19;
const ll maxn = 1005;
char a[maxn], b[maxn];//正序和逆序 
ll powP[maxn], hashA[maxn], hashB[maxn];
vector<pair<ll, int> > subA, subB;
int length;
void init(int len)
{
	powP[0] = 1;
	b[0] = a[len - 1];
	for(int i = 1; i < len; ++i)
	{
		powP[i] = (powP[i - 1] * p) % mod;
		b[i] = a[len - i - 1];
	}
}
void getHash(int len, ll hash[], char str[])
{
	hash[0] = str[0];
	for(int i = 1; i < len; ++i)
	{
		hash[i] = (hash[i - 1] * p + str[i]) % mod;
	}
}
ll getSubHash(ll hash[], int i, int j)
{
	if(i == 0)
		return hash[j];
	else
		return ((hash[j] - hash[i - 1] * powP[j - i + 1]) % mod + mod) % mod;
} 
int binarySearch(int l, int r, int len, int i, int isEven)//奇数：iseven=0，偶数：iseven = 1 
{
	while(l < r)
	{
		int mid = (l + r) / 2;
		//左半子串H1，右半子串H2 
		int H1L = i - mid + isEven, H1R = i;
		int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + isEven);
		ll hashL = getSubHash(hashA, H1L, H1R);
		ll hashR = getSubHash(hashB, H2L, H2R);
		if(hashL != hashR)//说明回文半径小于等于mid 
			r = mid;
		else//说明回文半径大于mid 
			l = mid + 1;
	}
	return l - 1;//返回最大回文半径 
}
int main(int argc, char *argv[]) {
	fgets(a, maxn, stdin);
	length = strlen(a) - 1;
	init(length);
	getHash(length, hashA, a);
	getHash(length, hashB, b);
	int ans = 0;
	//奇数回文 
	for(int i = 0; i < length; ++i)
	{
		int maxLen = min(i, length - 1 - i) + 1;
		int k = binarySearch(0, maxLen, length, i, 0);
		ans = max(ans, k * 2 + 1);//计算整个回文 
	}
	//偶回文
	for(int i = 0; i < length; ++i)
	{
		int maxLen = min(i + 1, length - 1 - i) + 1;
		int k = binarySearch(0, maxLen, length, i, 1);
		ans = max(ans, k * 2);
	} 
	printf("%d", ans);
	return 0;
}
