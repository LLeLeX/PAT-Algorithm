#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char *argv[]) {
	cin >> n;
	int cnt = 0;
	while(n != 1)
	{
		if(n & 1)//ÆæÊı 
		{
			n = (3 * n + 1) / 2;
		}
		else
		{
			n = n / 2;	
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
