#include <bits/stdc++.h>
using namespace std;
string unitNum[15] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenNum[15] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string E2M[170];//数字->火星文 
map<string, int> M2E;//火星文->数字 
int N;
void init()
{
	for(int i = 0; i < 13; i++)
	{
		E2M[i] = unitNum[i];
		M2E[unitNum[i]] = i;
		E2M[i * 13] = tenNum[i];
		M2E[tenNum[i]] = i * 13;
	}
	for(int i = 1; i < 13; i++)
	{
		for(int j = 1 ; j < 13; j++)
		{
			string mar = tenNum[i] + " " + unitNum[j];
			E2M[i * 13 + j] = mar;
			M2E[mar] = i * 13 + j;
		}
	}
}
int main(int argc, char *argv[]) {
	init();
	scanf("%d", &N);
	getchar();
	while(N--)
	{
		string str;
		int num = 0;
		getline(cin, str);
		if(str[0] >= '0' && str[0] <= '9')
		{
			for(int i = 0; i < str.length(); i++)
			{
				num = 10 * num + (str[i] - '0');
			}
			cout << E2M[num] << endl;
		}
		else
		{
			cout << M2E[str] << endl;
		}
	}
	return 0;
}
