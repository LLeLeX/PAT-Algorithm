#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i) & (-i))
int N;
int c[maxn];
//将第x个元素加上v 
void update(int x, int v)
{
	for(int i = x; i <= N; i += lowbit(i))
	{
		c[i] += v;
	}
}
//求1~x之和 
int getSum(int x)
{
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i))
	{
		sum += c[i];
	} 
	return sum;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		update(num, 1);
		printf("%d ", getSum(num - 1));
	}
	return 0;
}
