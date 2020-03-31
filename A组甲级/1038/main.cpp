#include <bits/stdc++.h>
using namespace std;
int N;
string str[10005];
bool cmp(string s1, string s2)
{
	return s1 + s2 < s2 + s1;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	sort(str, str + N, cmp);
	bool flag = false;//标记是否已经输出过非零数 
	for(int i = 0; i < N; i++)
	{
		int len = str[i].length();
		for(int j = 0; j < len; j++)
		{
			if(str[i][j] == '0')
			{
				if(flag == true)
				{
					cout << str[i][j]; 
				}
				else
				{
					continue;
				}
			}
			else
			{
				flag = true;
				cout << str[i][j];
			}
		}
	}
	if(!flag)
	{
		cout << 0;
	} 
	return 0;
}
