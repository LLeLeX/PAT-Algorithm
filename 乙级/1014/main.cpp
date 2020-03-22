#include <bits/stdc++.h>
using namespace std;
char week[10][10] = {"0", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; 
char s[10][70];
int lens[6];
int main(int argc, char** argv) {
	for(int i = 1; i <= 4; i++)
	{
		scanf("%s", s[i]);
		getchar();
		lens[i] = strlen(s[i]);	
	}
	int cnt = min(lens[1], lens[2]);
	bool firflag = false;
	for(int i = 0; i < cnt; i++)
	{
		//星期 
		if(s[1][i] == s[2][i] && firflag == false)
		{
			//只有大写字母 
			if(s[1][i] >= 'A' && s[1][i] <= 'G')
			{
				firflag = true;
				if(s[1][i] <= 'Z')
				{
					int temp = s[1][i] - 'A' + 1;
					printf("%s ", week[temp]);
				}
				else
				{
					int temp = s[1][i] - 'a' + 1;
					printf("%s ", week[temp]);
				}
			}	
		}
		//小时 0~9   A~N
		else if(s[1][i] == s[2][i] && firflag == true)
		{
			//0~9   A~N
			if((s[1][i] >= 'A' && s[1][i] <= 'N') || (s[1][i] >= '0' && s[1][i] <= '9'))
			{
				if(s[1][i] <= '9')
				{
					printf("0%c:", s[1][i]);
				}
				else
				{
					int temp1 = (s[1][i] - 'A') + 10;
					printf("%d:", temp1);	
				}
				break;
			}
		}
	}
	cnt = min(lens[3], lens[4]);
	for(int i = 0; i < cnt; i++)
	{
		if((s[3][i] >= 'a' && s[3][i] <= 'z') || (s[3][i] >= 'A' && s[3][i] <= 'Z'))
		{
			if(s[3][i] == s[4][i])
			{
				printf("%02d", i);
				break;
			}
		}
	}
	return 0;
}
