#include <bits/stdc++.h>
using namespace std;
double battle[5][5];
char ans[5];
char n[5] = {'0', 'W', 'T', 'L'};
double sum;
int main(int argc, char *argv[]) {
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			scanf("%lf", &battle[i][j]);
			if(battle[i][4] < battle[i][j])
			{
				battle[i][4] = battle[i][j];
				ans[i] = n[j];
			}
		}
	}
	for(int i = 1; i <= 3; i++)
	{
		printf("%c ", ans[i]);
	}
	sum = (battle[1][4] * battle[2][4] * battle[3][4] * 0.65 - 1) * 2;
	printf("%.2f", sum);
	return 0;
}
