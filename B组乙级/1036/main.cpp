#include <bits/stdc++.h>
using namespace std; 
double N;
char C;
int main(int argc, char** argv) {
	scanf("%lf %c", &N, &C);
	int row = round(N / 2);
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(i == 1 || i == row)
			{
				printf("%c", C);
			}
			else
			{
				if(j == 1 || j == N)
				{
					printf("%c", C);
				}
				else
				{
					printf(" ");
				}
			}	
		}
		printf("\n");
	}
	return 0;
}
