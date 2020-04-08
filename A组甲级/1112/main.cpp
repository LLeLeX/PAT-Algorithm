#include <bits/stdc++.h>
using namespace std;
int K, len;
char str[1005];
//poscnt:字符串第i个字符连续重复的次数,keycnt:字母i在字符串中最小的重复次数（） 
int poscnt[1005];
//isBroke:按键好坏，isprint:输出错误键时防止重复输出 
bool isBroken[150], isPrint[150];
int main(int argc, char *argv[]) {
	scanf("%d", &K);
	getchar();
	scanf("%s", str);
	len = strlen(str);
	memset(isBroken, true, sizeof(isBroken)); 
	for(int i = 0; i < len; ++i)
	{
		int pos = str[i];
		poscnt[i]++;
		for(int j = i + 1; str[j] == str[i]; ++j)//向后遍历K位 
		{
			if(str[j] != str[i])//K位之内有一位与str[i]不同
				break; 
			else
			{ 	
				poscnt[i]++;
			} 
		}
		if(str[i] == str[i - 1] && i != 0)//保证连续重复的字符存储最大的重复次数 
			poscnt[i] = max(poscnt[i], poscnt[i - 1]);
	}
	//统计同一字符不同位置出现的最小次数，并判断按键好坏 
	for(int i = 0; i < len; ++i)
	{
		int pos = str[i];
		if(poscnt[i] % K == 0)
			continue;
		else
			isBroken[pos] = false;
		
		
		
		/*if(keycnt[pos] == 0)//第一次遇到字母str[i]直接赋值 
			keycnt[pos] = poscnt[i];
		else//取最小值 
		{ 
			if(keycnt[pos] % K != 0)//更新keycnt后，判断为好键 
			{
				isBroken[pos] = false;
				continue;
			}
			if(poscnt[i] % K != 0)//当前为好键 
			{
				keycnt[pos] = poscnt[i];
				isBroken[pos] = false;
				continue;
			}
			keycnt[pos] = min(keycnt[pos], poscnt[i]);//存储同一字符不同位置出现的最小次数，避免故意按k次 
		} 
		if(keycnt[pos] % K != 0)//判断按键好坏，不是k的倍数，说明是好键 
			isBroken[pos] = false;*/
	}
	//输出
	for(int i = 0; i < len; ++i)
	{
		int pos = str[i];
		if(isPrint[pos] == false && isBroken[pos] == true)
		{
			printf("%c", pos);
			isPrint[pos] = true;
		}
	}
	printf("\n");
	for(int i = 0; i < len; ++i)
	{
		int pos = str[i];
		if(isBroken[pos] == false)
			printf("%c", str[i]);
		else
		{
			printf("%c", str[i]);
			i += K - 1;
		}
	}
	return 0;
}
