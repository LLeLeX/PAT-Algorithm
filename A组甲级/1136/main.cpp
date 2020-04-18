#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
char a[maxn], b[maxn];//a存原串和答案，b存反向串 
bool judge(char str[], int length)
{
	for(int i = 0; i <= length / 2; ++i)
	{
		if(str[i] != str[length - i - 1])
			return false;
	}
	return true;
}
void add(int length)
{
	int temp[maxn];
	int pos = 0;
	int r = 0;//进位 
	for(int i = 0; i < length; ++i)
	{
		int x = a[i] - '0';
		int y = b[i] - '0';
		temp[pos++] = (x + y + r) % 10;
		if(x + y + r < 10)
			r = 0;
		else
			r = 1;
	}
	if(r != 0)
		temp[pos++] = r;
	for(int i = pos - 1; i >= 0; --i)
	{
		a[pos - i - 1] = temp[i] + '0';
	}
}

int main(int argc, char *argv[]) {
	scanf("%s", a);
	int cnt = 0;
	while(1)
	{
		int len = strlen(a);
		if(judge(a, len) == true)
		{
			printf("%s is a palindromic number.\n", a);	
			break;
		}
		if(cnt == 10)
		{
			printf("Not found in 10 iterations.\n");
			break;
		}
		strcpy(b, a);
		reverse(b, b + len);
		printf("%s + %s = ", a, b);
		add(len);
		printf("%s\n", a);
		cnt++;
	}
	return 0;
}
