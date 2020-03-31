#include <bits/stdc++.h>
using namespace std;
char s1[100005], s2[100005];
//string s1, s2;
bool asc[130];
int main(int argc, char *argv[]) {
	/*getline(cin, s1);
	getline(cin, s2);*/
	/*fgets(s1, 100005, stdin);
	fgets(s2, 100005, stdin);*/
	gets(s1);
	gets(s2); 
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	/*int len1 = s1.length();
	int len2 = s2.length();*/
	for(int i = 0; i < len1; i++)
	{
		//true为坏掉 
		if(s1[i] >= 'A' && s1[i] <= 'Z')
		{
			asc[s1[i]] = true;
			asc[s1[i] + 32] = true;
		}
		else
		{
			asc[s1[i]] = true;
		}
	}
	
	for(int i = 0; i < len2; i++)
	{
		//获取当前字母和标点 
		if(asc[s2[i]])//坏掉了 
		{
			continue;
		}
		else if(s2[i] >= 'A' && s2[i] <= 'Z')
		{
			if( asc[s2[i]] ||asc['+'])
			{
				continue;
			}
			else
			{
				printf("%c", s2[i]);
			}
		}
		else//完好的 
		{
			printf("%c", s2[i]); 
		}
	}
	return 0;
}
