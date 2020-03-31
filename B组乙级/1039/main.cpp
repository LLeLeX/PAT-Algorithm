#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int cntAsc[130];
int main(int argc, char *argv[]) {
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	//标记第一串所有珠子及个数 
	for(int i = 0; i < len1; i++)
	{
		cntAsc[s1[i]]++;
	}
	//核对第二串
	int cntUse = 0;//记录可以用到的个数
	int cntLost = 0;//记录缺珠子的个数 
	for(int i = 0; i < len2; i++)
	{
		if(cntAsc[s2[i]] > 0)//有这个珠子 
		{
			cntAsc[s2[i]]--;
			cntUse++; 
		}
		else//此时缺珠子 
		{
			cntLost++;
		}
	}
	if(cntLost == 0)
	{
		printf("Yes %d", len1 - cntUse);
	}
	else
	{
		printf("No %d", cntLost);
	}
	return 0;
}
