#include <bits/stdc++.h>
using namespace std;
int m, n;
int fibo[50];
int init(int n)
{
	if(n == 1)
		return fibo[1];
	else if(n == 2)
		return fibo[2];
	else
		fibo[n] = init(n - 1) + init(n - 2);
		return fibo[n];
}
int main(int argc, char *argv[]) {
	fibo[1] = 1;
	fibo[2] = 1;
	fibo[3] = 2;
	init(20);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			for(int k = n - i - 1; k > 0; k--)
				cout << "  ";
			for(int j = 0; j < i * 2 + 1; j++)
			{
				cout << fibo[j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
