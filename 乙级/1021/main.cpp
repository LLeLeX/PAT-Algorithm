#include <bits/stdc++.h>
using namespace std;
char N[1005];
int nums[15];
int main(int argc, char** argv) {
	scanf("%s", N);
	int len = strlen(N);
	for(int i = 0; i < len; i++)
	{
		int temp = N[i] - '0';
		nums[temp]++;
	}
	bool flag = false;
	for(int i = 0; i <= 9; i++)
	{
		if(nums[i] && flag == false)
		{
			printf("%d:%d", i, nums[i]);
			flag = true;
		}
		else if(nums[i] && flag == true)
		{
			printf("\n%d:%d", i, nums[i]);
		}
	}
	if(flag == false)
	{
		printf("0");
	}
}
