#include <bits/stdc++.h>
using namespace std;
string str;
struct letter{
	char s;
	int cnt;
	int flag;//±ê¼ÇPATestµÄË³Ðò
	letter(){}
	letter(char ss, int cc, int ff)
	{
		s = ss;
		cnt = cc;
		flag = ff;
	} 
}let[130];
bool cmp(letter a, letter b)
{
	return a.flag > b.flag;
}
int main(int argc, char *argv[]) {
	cin >> str;
	int len = str.length();
	let['P'] = letter('P', 0, 6);
	let['A'] = letter('A', 0, 5);
	let['T'] = letter('T', 0, 4);
	let['e'] = letter('e', 0, 3);
	let['s'] = letter('s', 0, 2);
	let['t'] = letter('t', 0, 1);
	for(int i = 0; i < len; i++)
	{
		if(str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't')
			let[str[i]].cnt++;	
		
	}
	sort(let, let + 125, cmp);
	int sum = 0;
	for(int i = 0; i < 6; i++)
	{
		sum += let[i].cnt;
	}
	for(int i = 0; i < sum; i++)
	{
		int index = i % 6;
		if(let[index].cnt)
		{
			printf("%c", let[index].s);
			let[index].cnt--;
		}
		else
		{
			sum++;
		}
	}
	return 0;
}
