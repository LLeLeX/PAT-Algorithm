#include <bits/stdc++.h>
using namespace std;
string str;
char s[3000][3000];
int main(int argc, char *argv[]) {
	cin >> str;
	int len = str.length();
	int ansn1 = 0;
	for(int n2 = 1; n2 <= len; n2++)
	{
		for(int n1 = 0; n1 <= n2; n1++)
		{
			if(n1 * 2 + n2 == len + 2)
			{
				ansn1 = max(ansn1, n1);
			}
		}
	}
	int ansn2 = len + 2 - 2 * ansn1;
	int space = ansn2 - 2;//×óÓÒÖ®¼äµÄ¿Õ¸ñ
	//cout << ansn1 << " " << ansn2; 
	for(int i = 1; i <= ansn1; i++)
	{
		for(int j = 1; j <= ansn2; j++)
		{
			s[i][j] = ' ';
		}
	}
	//»æÍ¼
	int index = 0;
	for(int i = 1; i <= ansn1; i++)//×ó±ß 
	{
		s[i][1] = str[index++];
	} 
	for(int j = 2; j <= ansn2; j++)//µ×±ß 
	{
		s[ansn1][j] = str[index++];
	}
	for(int i = ansn1 - 1; i >= 1; i--)//ÓÒ±ß 
	{
		s[i][ansn2] = str[index++]; 
	} 
	//display
	for(int i = 1; i <= 2 * ansn1 - 1; i++)
	{
		for(int j = 1; j <= ansn2; j++)
		{
			printf("%c", s[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
