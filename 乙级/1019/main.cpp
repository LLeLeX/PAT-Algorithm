#include <bits/stdc++.h>
using namespace std;
int N;
int num[5];
void initNum(int n)
{
	int pos = 3;
	while(n)
	{
		int r = n % 10;
		num[pos] = r;
		n = n / 10;
		pos--;
	}
}
int poww(int a, int b)
{
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
	{
		return a * poww(a, b - 1);
	}
	else if(b % 2 == 0)
	{
		int temp = poww(a, b / 2);
		return temp * temp;
	}
}
int getNum()
{
	int ans = 0;
	for(int i = 0; i < 4; ++i)
	{
		//ans += poww(10 , (3 - i)) * num[i]; 
		ans = ans * 10 + num[i];
	}
	return ans;
}
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	initNum(N);
	int upNum, downNum, result;
	while(1)
	{
		sort(num, num + 4);
		upNum = getNum();
		sort(num, num + 4, cmp);
		downNum = getNum();
		result = downNum - upNum;
		printf("%04d - %04d = %04d\n", downNum, upNum, result);
		memset(num, 0, sizeof(num));
		initNum(result);
		if(result == 6174 || result == 0)
			break;
	}
	return 0;
}
