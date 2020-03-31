#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int N, D;
bool isPrime[maxn] = {true};
void findPrime()
{
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < maxn; ++i)
	{
		if(isPrime[i])
		{
			for(int j = i + i; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
int num[50], pos = 0;//存储进制转换的每一位，pos是下标 
int getNum(int n, int r)//十进制转换为N进制 
{
	while(n)
	{
		int ret = n % r;
		num[pos++] = ret;//倒序 
		n = n / r;
	}
}
int main(int argc, char *argv[]) {
	memset(isPrime, true, sizeof(isPrime));
	findPrime();
	while(1)
	{
		scanf("%d", &N);
		if(N < 0)
			break;
		scanf("%d", &D);
		memset(num, 0, sizeof(num));//初始化 
		pos = 0;
		if(isPrime[N] == false)
			printf("No\n");
		else
		{
			getNum(N, D);//十进制N转换为D进制
			//此时num数组里面是D进制数
			//正序遍历num就是倒序的N（D进制下）
			//reverse存储反转后的十进制数，product当前进制次方 
			int reverse = 0, product = 1;
			for(int i = pos - 1; i >= 0; --i)
			{
				reverse += num[i] * product;
				product *= D;
			} 
			if(isPrime[reverse] == false)
				printf("No\n");
			else
				printf("Yes\n"); 
		}
	}
	return 0;
}
