#include <bits/stdc++.h>
using namespace std;
int r, g, b;
char ans[10];
int pos;
void compute(int n)
{
	pos = 0;
	ans[0] = ans[1] = '0';
	do
	{
		int ret = n % 13;
		if(ret < 10)
		{
			ans[pos++] = '0' + ret;
		}
		else
		{
			switch(ret)
			{
				case 10:
					ans[pos++] = 'A';
					break;
				case 11:
					ans[pos++] = 'B';
					break;
				case 12:
					ans[pos++] = 'C';
					break;
			}

		}
		n /= 13;
	}while(n);
}
void display()
{
	for(int i = 1; i >= 0; i--)
	{
		printf("%c", ans[i]);
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &r, &g, &b);
	printf("#");
	compute(r);
	display();
	compute(g);
	display();
	compute(b);
	display();
	return 0;
}
