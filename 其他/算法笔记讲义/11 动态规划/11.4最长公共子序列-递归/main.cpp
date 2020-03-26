#include <bits/stdc++.h>
using namespace std;
char a[50], b[50];
int dp[50][50]; 
int lena, lenb, len;
void DP(int x, int y)//x:字符串a的下标；y：字符串b的下标 
{
	if(y > lenb)
	{
		return;
	}
	if(a[x] == b[y])
	{
		dp[x][y] = dp[x - 1][y - 1] + 1;
		y++;
		DP(x, y);
	}
	else
	{
		dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
		y++;
		DP(x, y);
	}
} 
int main(int argc, char *argv[]) {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	lena = strlen(a + 1);
	lenb = strlen(b + 1);
	len = max(lena, lenb);
	for(int i = 1; i <= lena; ++i)
	{
		DP(i, 0);
	} 
	printf("%d", dp[lena][lenb]);
	return 0;
}
