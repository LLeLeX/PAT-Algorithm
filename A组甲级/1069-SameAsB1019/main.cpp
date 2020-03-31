#include <bits/stdc++.h>
using namespace std;
char str[10];
bool increase(char s1, char s2)
{
	return s1 < s2;
}
bool decrease(char s1, char s2)
{
	return s1 > s2;
}
int strToint()
{
	int result = 0;
	for(int i = 0; i < 4; ++i)
	{
		result = result * 10 + (str[i] - '0');
	}
	return result;
}
void intTostr(int n)
{
	for(int i = 0; i < 4; ++i)
	{
		int ret = n % 10;
		str[i] = '0' + ret;
		n /= 10;
	}
}
int main(int argc, char *argv[]) {
	int num1 = 0, num2 = 0, ans = 0;
	scanf("%d", &num1);
	intTostr(num1);
	while(1)
	{
		sort(str, str + 4, decrease);
		num1 = strToint();
		sort(str, str + 4, increase);
		num2 = strToint();
		ans = num1 - num2;
		printf("%04d - %04d = %04d\n", num1, num2, ans);
		if(ans == 0 || ans == 6174)
			break;
		intTostr(ans);
	}
	
	return 0;
}
