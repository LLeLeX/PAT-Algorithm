#include <bits/stdc++.h>
using namespace std;
int remain;
int main(int argc, char** argv) {
	int N;
	char C;
	scanf("%d %c", &N, &C);
	//均考虑中间的一个 
	int temp = 1, row = 1;
	for(int i = 3; i <= 1000; i += 2)
	{
		if(temp + 2 * i <= N)
		{
			temp += 2 * i;
			row += 2;
		}
		else
		{
			break;
		}
	}
	remain = N - temp;
	//上半部分 
	int upr = row / 2; 
	for(int i = upr; i >= 1; i--)
	{
		for(int k = upr - i; k > 0; k--)
		{
			printf(" ");
		}
		for(int j = 2 * i + 1; j >= 1; j--)
		{
			printf("%c", C);
		}
		printf("\n");
	}
	//下半部分
	int downr = row - upr;
	for(int i = 1; i <= downr; i++)
	{
		for(int k = downr - i; k >= 1; k--)
		{
			printf(" ");
		}
		for(int j = 2 * i - 1; j > 0; j--)
		{
			printf("%c", C);
		}
		printf("\n");
	}
	printf("%d", remain);
	return 0;
}
