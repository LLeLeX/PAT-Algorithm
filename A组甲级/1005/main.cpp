#include <bits/stdc++.h>
using namespace std;
char N[105];
char str[15][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char ans[105];
int main(int argc, char *argv[]) {
	scanf("%s", N);
	int len = strlen(N);
	int pos = 0;
	int sum = 0;
	for(int i = len - 1; i >= 0; i--)
	{
		sum += N[i] - '0';
	}
	sprintf(ans, "%d", sum);
	int lenAns = strlen(ans);
	bool flag = false;
	for(int i = 0; i < lenAns; i++)
	{
		int temp = ans[i] - '0';
		if(!flag)
		{
			printf("%s", str[temp]);
			flag = true;
		}
		else
		{
			printf(" %s", str[temp]);
		}
	}
	
	
	return 0;
}
