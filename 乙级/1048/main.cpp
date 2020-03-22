#include <bits/stdc++.h>
using namespace std;
char sign[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
char a[105], b[105];
char ans[105];
int main(int argc, char** argv) {
	scanf("%s%s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int conlena = lena, conlenb = lenb;
	//此时len的长度已经比下标多一位了 
	reverse(a, a + lena);
	reverse(b, b + lenb);
	int minLen = min(lena, lenb);
	int maxLen = max(lena, lenb);
	int index = 0;
	if(conlena > conlenb)
	{
		for(int i = lenb; i < lena; i++)
		{
			b[i] = '0';
		}
		for(int i = 1; i <= maxLen; i++)
		{
			if(i % 2 == 0)//偶数位
			{
				int temp = b[i - 1] - a[i - 1]; 
				if(temp < 0)
				{
					temp += 10;
				}
				ans[index++] = sign[temp];
				lena--;
				lenb--;
			}
			else if(i % 2 == 1)//奇数位 
			{
				int temp = (a[i - 1] - '0' + b[i - 1] - '0') % 13;
				ans[index++] = sign[temp];
				lena--;
				lenb--;
			}
		}
	}
	if(conlenb >= conlena)
	{
		for(int i = 1; i <= minLen; i++)
		{
			if(i % 2 == 0)//偶数位
			{
				int temp = b[i - 1] - a[i - 1]; 
				if(temp < 0)
				{
					temp += 10;
				}
				ans[index++] = sign[temp];
				lena--;
				lenb--;
			}
			else if(i % 2 == 1)//奇数位 
			{
				int temp = (a[i - 1] - '0' + b[i - 1] - '0') % 13;
				ans[index++] = sign[temp];
				lena--;
				lenb--;
			}
		}
	}
	if(lenb)//b较长 
	{
		for(int i = conlena; i < conlenb; i++)
		{
			ans[index++] = b[i]; 
		}
	}
	for(int i = maxLen - 1; i >= 0; i--)
	{
		printf("%c", ans[i]);
	}
	return 0;
}
