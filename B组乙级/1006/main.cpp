#include <bits/stdc++.h>
using namespace std;
char s[10];
char ans[50];
int main(int argc, char** argv) {
	scanf("%s", s);
	int len = strlen(s) - 1;
	//个位 
	int cnt = s[len] - '0';
	int index = 0;
	for(int i = cnt; i >= 1; i--)
	{
		ans[index] = i + '0';
		index++;
	}
	len--;
	if(len >= 0)
	{
		//十位
		cnt = s[len] - '0';
		for(int i = 1; i <= cnt; i++)
		{
			ans[index] = 'S';
			index++;
		} 
		len--;
	}
	if(len >= 0)
	{
		//百位
		cnt = s[len] - '0';
		for(int i = 1; i <= cnt; i++)
		{
			ans[index] = 'B';
			index++;
		}
	}
	if(index == 0)
	{
		printf("0");
	}
	for(int i = index - 1; i >= 0; i--)
	{
		printf("%c", ans[i]);
	}
	return 0;
}
