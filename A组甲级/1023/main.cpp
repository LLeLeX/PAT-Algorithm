#include <bits/stdc++.h>
using namespace std;
int hashtable[15], hashtemp[15];
struct Bign{
	int d[25];
	int len;
	Bign(){
		memset(d, 0, sizeof(0));
		len = 0;
	}
}; 
char str[25];
Bign mul(Bign a, int n)
{
	Bign ans;
	int carry = 0;
	for(int i = 0; i < a.len; ++i)
	{
		int temp = carry + a.d[i] * n;
		ans.d[i] = temp % 10;//积
		carry = temp / 10;//进位 
		ans.len++;
		hashtemp[ans.d[i]]++;//统计积中数字的个数 
	}
	//处理最后一个进位,乘法进位可能不唯一 
	while(carry != 0)
	{
		ans.d[ans.len] = carry % 10;
		carry /= 10;
		hashtemp[ans.d[ans.len]]++;
		ans.len++;
	} 
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%s", str);
	Bign num;
	num.len = strlen(str);
	for(int i = 0; i < num.len; ++i)
	{
		num.d[i] = str[num.len - i - 1] - '0';
		hashtable[num.d[i]]++;
	}
	Bign ans = mul(num, 2);
	bool flag = true;//对比两个hash是否相匹配 
	if(ans.len != num.len)
		flag = false;
	for(int i = 0; i < 10; i++)
	{
		if(flag == false)
			break;
		if(hashtable[i] != hashtemp[i])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = ans.len - 1; i >= 0; --i)
	{
		printf("%d", ans.d[i]);
	}
	return 0;
}
