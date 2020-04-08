#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3fffffff;
int N;
int n1, n2;
ll s1, s2;
ll num[maxn];
bool cmp(ll a, ll b)
{
	return a < b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%lld", &num[i]);
	}
	sort(num, num + N, cmp);
	//计算n1，n2，且n1存大数更能保证s1-s2最大 
	n1 = N / 2;
	n2 = N - n1;
	if(n1 < n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
//	cout << n1 << " " << n2 << endl;
	printf("%d ", n1 - n2);
	for(int i = N - 1; i >= (N - n1); --i)
	{
		s1 += num[i];
	} 
	for(int i = 0; i < n2; ++i)
	{
		s2 += num[i];
	}
//	cout << s1 << " " << s2 << endl;
	
	printf("%lld", s1 - s2); 
	return 0;
}
