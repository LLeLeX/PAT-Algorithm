#include <bits/stdc++.h>
using namespace std;
int K;
bool check(int a[], int len)
{
	if(len == 1)
		return true;
	for(int i = 0; i <= len / 2; ++i)
	{
		if(a[i] != a[len - 1 - i])
			return false;
	}
	return true;
}
struct Bign{
	int d[15];
	int len;
	Bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
char str[15];
Bign add(Bign a, Bign b)
{
	Bign ans;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; ++i)
	{
		int temp = a.d[i] + b.d[i] + carry;
		ans.d[ans.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0)
	{
		ans.d[ans.len++] = carry;
	}
	return ans;
}
Bign change(Bign a)
{
	Bign b;
	b.len = a.len;
	for(int i = 0; i < a.len; ++i)
	{
		b.d[b.len - i - 1] = a.d[i];
	}
	return b;
}
int main(int argc, char *argv[]) {
	scanf("%s %d", str, &K);
	Bign N, M, ans;
	N.len = M.len = strlen(str);
	for(int i = 0; i < N.len; ++i)
	{
		N.d[i] = str[N.len - i - 1] - '0';
		M.d[i] = str[i] - '0';
	}
	int cnt = 0;
	bool flag = true;//标记是否能在有限步数内完成 
	while(check(N.d, N.len) == false)
	{
		cnt++;
		N = add(N, M);
		M = change(N);
		if(cnt == K)//有限步数内未完成 
		{
			flag = false;
			ans = N;
			break;
		}
	}
	if(flag == false)
	{
		N = ans;
		cnt = K; 
	}
	for(int i = N.len - 1; i >= 0; --i)
	{
		printf("%d", N.d[i]);
		if(i == 0)
			printf("\n");
	}
	printf("%d", cnt);
	return 0;
}
