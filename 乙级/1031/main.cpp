#include <bits/stdc++.h>
using namespace std;
int N;
char id[20];
int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int Z[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char M[20] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
bool judge(char id[])
{
	for(int i = 0; i <= 1; i++)
	{
		if(id[i] > '9')
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	scanf("%d", &N);
	bool flag = false;
	while(N--)
	{
		scanf("%s", id);
		if(!judge(id))
		{
			printf("%s\n", id);
			flag = true;
			continue;
		}
		//求前17位的和 
		int sum = 0;
		for(int i = 0; i < 17; i++)
		{
			sum += (id[i] - '0') * w[i];
		}
		int z = sum % 11;
		if(id[17] != M[z])
		{
			printf("%s\n", id);
			flag = true;
		}
	}
	if(!flag)
	{
		printf("All passed");	
	}
	return 0;
}
