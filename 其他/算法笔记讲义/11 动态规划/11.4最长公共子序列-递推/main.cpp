#include <bits/stdc++.h>
using namespace std;
char a[50], b[50];
int dp[50][50]; 
int main(int argc, char *argv[]) {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	int lena = strlen(a + 1);
	int lenb = strlen(b + 1);
	int len = max(lena, lenb);
	/*for(int i = 1; i <= len; ++i)//全局变量无需再初始化边界为0 
	{
		dp[i][0] = dp[0][i] = 0;
	}*/
	for(int i = 1; i <= lena; ++i)
	{
		for(int j = 1; j <= lenb; ++j)
		{
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	} 
	printf("%d", dp[lena][lenb]);
	return 0;
}
