#include <bits/stdc++.h>
using namespace std;
int L, K;
string str;
int change(string s)
{
	int result = 0;
	for(int i = 0; i < K; ++i)
	{
		result = result * 10 + (s[i] - '0');
	}
	return result;
}
bool isPrime(int x)
{
	if(x == 1 || x == 0)
		return false;
	int sqr = (int)sqrt(x * 1.0);
	for(int i = 2; i <= sqr; ++i)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &L, &K);
	cin >> str;
	bool cmplt = false;
	string temp = "";
	for(int i = 0; i <= L - K; ++i)
	{
		if(cmplt == true)
			break;
		temp = "";
		for(int j = i; j < i + K; ++j)
		{
			temp += str[j];
		}
		int num = change(temp);
		if(isPrime(num) == true)
			cmplt = true;
	}
	if(cmplt == true)
		cout << temp << endl;
	else
		cout << "404" << endl;
	return 0;
}
