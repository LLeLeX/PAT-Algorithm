#include <bits/stdc++.h>
using namespace std;
int K, len;
char str[1005];
//poscnt:�ַ�����i���ַ������ظ��Ĵ���,keycnt:��ĸi���ַ�������С���ظ��������� 
int poscnt[1005];
//isBroke:�����û���isprint:��������ʱ��ֹ�ظ���� 
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
		for(int j = i + 1; str[j] == str[i]; ++j)//������Kλ 
		{
			if(str[j] != str[i])//Kλ֮����һλ��str[i]��ͬ
				break; 
			else
			{ 	
				poscnt[i]++;
			} 
		}
		if(str[i] == str[i - 1] && i != 0)//��֤�����ظ����ַ��洢�����ظ����� 
			poscnt[i] = max(poscnt[i], poscnt[i - 1]);
	}
	//ͳ��ͬһ�ַ���ͬλ�ó��ֵ���С���������жϰ����û� 
	for(int i = 0; i < len; ++i)
	{
		int pos = str[i];
		if(poscnt[i] % K == 0)
			continue;
		else
			isBroken[pos] = false;
		
		
		
		/*if(keycnt[pos] == 0)//��һ��������ĸstr[i]ֱ�Ӹ�ֵ 
			keycnt[pos] = poscnt[i];
		else//ȡ��Сֵ 
		{ 
			if(keycnt[pos] % K != 0)//����keycnt���ж�Ϊ�ü� 
			{
				isBroken[pos] = false;
				continue;
			}
			if(poscnt[i] % K != 0)//��ǰΪ�ü� 
			{
				keycnt[pos] = poscnt[i];
				isBroken[pos] = false;
				continue;
			}
			keycnt[pos] = min(keycnt[pos], poscnt[i]);//�洢ͬһ�ַ���ͬλ�ó��ֵ���С������������ⰴk�� 
		} 
		if(keycnt[pos] % K != 0)//�жϰ����û�������k�ı�����˵���Ǻü� 
			isBroken[pos] = false;*/
	}
	//���
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
