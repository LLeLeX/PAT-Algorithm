#include <bits/stdc++.h>
using namespace std;
char str1[100], str2[100], str3[100], str4[100];
char week[10][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; 
int main(int argc, char *argv[]) {
	scanf("%s\n%s\n%s\n%s", str1, str2, str3, str4);
	int minLen = min(strlen(str1), strlen(str2));
	bool flag = false;//��ǵ�һ����ȵ���ĸ 
	bool fircmplt = false;//���ǰ�����ַ����Ƚ��Ƿ���� 
	bool seccmplt = false;
	for(int i = 0; i < minLen; i++)
	{
		if(!flag)//�ǵ�һ����ȵ� 
		{
			if(str1[i] >= 'A' && str1[i] <= 'G')
			{
				if(str1[i] == str2[i])
				{
					int index = str1[i] - 'A';  
					printf("%s ", week[index]);
					flag = true;
				}
			}
		}
		else//�ڶ�����ȵ���ĸ������ 
		{
			//0~9||A~O
			if(str1[i] >= '0' && str1[i] <= '9')
			{
				if(str1[i] == str2[i])
				{
					int temp = str1[i] - '0';
					printf("%02d:", temp);
					fircmplt = true;
				}
			}
			else if(str1[i] >= 'A' && str1[i] <= 'O')
			{
				if(str1[i] == str2[i])
				{
					int temp = str1[i] - 'A' + 10;
					printf("%02d:", temp);
					fircmplt = true;
				}
			} 
		}
		if(fircmplt)
		{
			break;
		}
	}
	minLen = max(strlen(str3), strlen(str4));
	for(int i = 0; i < minLen; i++)
	{
		if(str3[i] >= 'a' && str3[i] <= 'z')
		{
			if(str3[i] == str4[i])
			{
				printf("%02d", i);
				seccmplt = true;
			}
		}
		else if(str3[i] >= 'A' && str3[i] <= 'Z')
		{
			if(str3[i] == str4[i])
			{
				printf("%02d", i);
				seccmplt = true;
			}
		}
		if(seccmplt)
		{
			break;
		}
	}
	
	//printf("%s\n%s\n%s\n%s", str1, str2, str3, str4);
	return 0;
}
