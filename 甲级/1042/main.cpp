#include <bits/stdc++.h>
using namespace std;
int K;
int arr[60];
char colors[10] = {'0', 'S', 'H', 'C', 'D', 'J'};
int ans1[60][3];
int ans2[60][3];
int main(int argc, char *argv[]) {
	scanf("%d", &K);
	for(int i = 1; i <= 54; i++)
	{
		scanf("%d", &arr[i]);
	}
	int total = K;
	//初始化 
	int init = 1;
	for(int i = 1; i <= 4; i++)//控制花色 
	{
		int start = 1;
		for(int j = start; j <= 13; j++)//控制纸牌数字 
		{
			ans2[init][1] = i;
			ans2[init][2] = j;
			init++;
		}
	}
	ans2[53][1] = ans2[54][1] = 5;
	ans2[53][2] = 1;
	ans2[54][2] = 2;


/*	cout << "***********" << endl;
	for(int i = 1; i <= 54; i++)
		{
			for(int j = 1; j<= 2; j++)
			{
				if(j == 1)
				{
					printf("%c", colors[ans2[i][j]]);
				}
				else
				{
					printf("%d", ans2[i][j]);
				}
			}
			printf("\n");
		}
	cout << "***********" << endl;*/
	
	bool flag = false;
	while(K--)
	{
		if(!flag)
		{
			int index = 1;
			for(int i = 1; i <= 54; i++)
			{
				int temp = arr[index];
				ans1[temp][1] = ans2[i][1];
				ans1[temp][2] = ans2[i][2];
				index++;
			}
			flag = true;
		}
		else
		{
			int index = 1;
			for(int i = 1; i <= 54; i++)
			{
				int temp = arr[index];
				ans2[temp][1] = ans1[i][1];
				ans2[temp][2] = ans1[i][2];
				index++;
			}
			flag = false;
		}
	}
	
	
	if(total % 2 == 1)
	{
		for(int i = 1; i <= 54; i++)
		{
			for(int j = 1; j<= 2; j++)
			{
				if(j == 1)
				{
					printf("%c", colors[ans1[i][j]]);
				}
				else
				{
					printf("%d", ans1[i][j]);
				}
			}
			if(i < 54)
			{
				printf(" ");
			}
		}
	}
	else
	{
		for(int i = 1; i <= 54; i++)
		{
			for(int j = 1; j<= 2; j++)
			{
				if(j == 1)
				{
					printf("%c", colors[ans2[i][j]]);
				}
				else
				{
					printf("%d", ans2[i][j]);
				}
			}
			if(i < 54)
			{
				printf(" ");
			}
		}
	}
	return 0;
}
