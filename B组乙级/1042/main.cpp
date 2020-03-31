#include <bits/stdc++.h>
using namespace std;
string str;
struct letters{
	char s;
	int cnt;
	letters(){}
	letters(char ss, int cc)
	{
		s = ss;
		cnt = cc;
	}	
}let[30];
bool cmp(letters a, letters b)
{
	if(a.cnt != b.cnt)
	{
		return a.cnt > b.cnt;
	}
	else
	{
		return a.s < b.s;
	}
}
int main(int argc, char *argv[]) {
	for(int i = 0; i < 26; i++)
	{
		char ss = 'a' + i;
		let[i] = letters(ss, 0);
	}
	getline(cin, str);
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')//Ğ¡Ğ´×ÖÄ¸ 
		{
			int index = str[i] - 'a';
			let[index].cnt++;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			int index = str[i] - 'A';
			let[index].cnt++;
		}
	}
	sort(let, let + 26, cmp);
	printf("%c %d", let[0].s, let[0].cnt);
	return 0;
}
