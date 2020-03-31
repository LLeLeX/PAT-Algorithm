#include <bits/stdc++.h>
using namespace std;
int a, b;
int sum;
char str[100];
int main(int argc, char *argv[]) {
	scanf("%d%d", &a, &b);
	sum = a + b;
	sprintf(str, "%d", sum);
	int len = strlen(str);
	if(len < 4)
	{
		printf("%s", str);
	}
	else
	{
		int cnt = 0;
		for(int i = 0; i < len; i++)
		{
			if(str[i] >= '0' && str[i] <= '9' && i != len - 1)
			{
				printf("%c", str[i]);
				if((len - 1 - i) % 3 == 0)
				{
					printf(",");
				}
			}
			else
			{
				printf("%c", str[i]);
			}
		}
	}
	return 0;
}
