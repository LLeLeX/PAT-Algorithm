#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Map[256];
LL INF = (1LL << 63) - 1;
void init()
{
	for(char c = '0'; c <= '9'; c++)
	{
		Map[c] = c - '0';//将‘0’~‘9’映射到 0~9 
	}
	for(char c = 'a'; c <= 'z'; c++)
	{
		Map[c] = c - 'a' + 10;//将'a'~'z'映射到10~35 
	}
}
LL convertNum10(char a[], LL radix, LL t)//将a转换为十进制，t为上界 
{
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if(ans < 0 || ans > t)//溢出，或超过N1的十进制 
		{
			return -1;
		}
	}
	return ans;
} 
int cmp(char N2[], LL radix, LL t)
{
	int len = strlen(N2);
	LL num = convertNum10(N2, radix, t);
	if(num < 0)//溢出，肯定N2>t 
	{
		return 1;
	}
	if(t > num)//t较大，返回-1 
	{
		return -1;
	} 
	else if(t == num)
	{
		return 0;
	}
	else//num较大返回1 
	{
		return 1;
	}
} 
LL binarySearch(char N2[], LL left, LL right, LL t)
{
	LL mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if(flag == 0)//找到解 
		{
			return mid;
		}
		else if(flag == -1)//往右子区间查找 
		{
			left = mid + 1;
		}
		else//往左子区间查找 
		{
			right = mid - 1;
		}
	}
	return -1;
}
int findLargestDigit(char N2[])//求最大的数位 
{
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++)
	{
		if(Map[N2[i]] > ans)
		{
			ans = Map[N2[i]];
		}
	}
	return ans + 1;
} 
char N1[20], N2[20], temp[20];
int tag, radix;
int main(int argc, char *argv[]) {
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if(tag == 2)
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	LL t = convertNum10(N1, radix, INF);
	LL low = findLargestDigit(N2);
	LL high = max(low, t) + 1;
	LL ans = binarySearch(N2, low, high, t);
	if(ans == -1)
	{
		printf("Impossible");
	}
	else
	{
		printf("%lld", ans);
	}
	return 0;
}
