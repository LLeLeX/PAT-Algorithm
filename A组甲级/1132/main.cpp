#include <bits/stdc++.h>
using namespace std;
int N;
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	getchar();
	while(N--)
	{
		int z = 0;
		char str[50];
		scanf("%s", str);
		int len = strlen(str);
		int a = 0, b = 0;
		for(int i = 0; i < len / 2; ++i)
		{
			a = a * 10 + (str[i] - '0');
		}
		z = a;
		for(int i = len / 2; i < len; ++i)
		{
			b = b * 10 + (str[i] - '0');
			z = z * 10 + (str[i] - '0');
		}
	//	cout << z << " " << a << " " << b << endl;
		if(a != 0 && b != 0 && z % (a * b) == 0)//注意0的问题 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
