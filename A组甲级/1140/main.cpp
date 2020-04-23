#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
	string str, temp;
	int N; 
	cin >> str >> N;
	if(N == 1)
	{
		cout << str << endl;
		return 0;
	}
	else
		N = N - 1;
	while(N--)
	{
		temp = "";
		int len = str.length();
		int i, j; 
		for(i = 0; i < len; ++i)
		{
			char c = str[i];
			int count = 0;
			for(j = i; j < len; ++j)
			{
				if(str[j] == c)
				{
					i = j;
					count++;
				}
				else
				{
					i = j - 1;
					break;
				}
			}
			temp += c;
			temp += count + '0';	
		}
		str = temp;
	}
	cout << str << endl;
	return 0;
}
