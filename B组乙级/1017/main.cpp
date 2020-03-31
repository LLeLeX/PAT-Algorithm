#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct Bign{
	int d[maxn];
	int len;
	Bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
char str[maxn];
int n;
Bign div(Bign a, int b, int &r)
{
	Bign ans;
	ans.len = a.len;
	for(int i = a.len - 1; i >= 0; --i)
	{
		int temp = r * 10 + a.d[i];
		if(b > temp)
		{
			ans.d[i] = 0;
			r = a.d[i];
		}
		else
		{
			ans.d[i] = temp / b;
			r = temp % b;
		}
	}
	while(ans.len >= 1 && ans.d[ans.len - 1] == 0)
	{
		ans.len--;
	}
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%s %d", str, &n);
	Bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; ++i)
	{
		a.d[a.len - i - 1] = str[i] - '0';
	}
	int ret = 0;
	Bign ans = div(a, n, ret);
	for(int i = ans.len - 1; i >= 0; i--)
	{
		printf("%d", ans.d[i]);
		if(i == 0)
			printf(" %d", ret);
	}
	if(ans.len == 0)
	{
		printf("0 %d", ret);
	}
	return 0;
}
