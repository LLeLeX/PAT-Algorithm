#include <bits/stdc++.h>
using namespace std;
char str[10005];
char nums[10005], ans[10005]; 
char exps[10];
int main(int argc, char *argv[]) {
	cin >> str;
	int len = strlen(str);
	int start = 0;
	if(str[0] == '-')
	{
		printf("%c", str[0]);
		start++;
	}
	//��� 
	bool flag = false;//false��ʾ����
	int lenNums = 0, lenExps = 0; 
	for(int i = start; i < len; i++)
	{
		if(str[i] == 'E')
		{
			flag = true;
		}
		else if(flag == false)//�����׶� 
		{
			if(str[i] != '+')
				nums[lenNums++] = str[i];//��С���� 
		}
		else if(flag == true)//ָ���׶Σ��������� 
		{
			exps[lenExps++] = str[i];
		}
	}
	int index = 0;//��¼ans����
	int ex = 0;//ָ����ֵ
	int actCnt = lenNums - 2;//ʵ��С������λ�� 
	sscanf(exps, "%d", &ex); 
	if(ex == 0)//ָ����0���� 
	{
		for(int i = 0; i < lenNums; i++)
		{
			ans[index++] = nums[i];//��Ϊ����Ϊ������nums[0]��'+'
		}
	}
	else if(exps[0] == '+')//ָ��Ϊ�� 
	{
		//�Ե������� 
		ans[index++] = nums[0];//����С����ǰ��һλ 
		if(ex >= actCnt)//ָ�����ڵ���С������λ�� 
		{
			for(int i = 2; i < actCnt + 2; i++)//i��С������һλ��ʼ 
			{
				ans[index++] = nums[i]; 
			}
			for(int i = 0; i < ex - actCnt; i++)//������Ĳ��� 
			{
				ans[index++] = '0';
			}
		}
		else//ָ��С�ں����λ����Ҫ��С���� 
		{
			for(int i = 2; i < ex + 2; i++)//��д�� 
			{
				ans[index++] = nums[i];
			} 
			ans[index++] = '.';
			for(int i = ex + 2; i < lenNums; i++)
			{
				ans[index++] = nums[i];
			}
		}
	} 
	
	else if(exps[0] == '-')//ָ��Ϊ�� 
	{
		ex = -ex;//ȡ�෴�� 
		ans[index++] = '0';
		ans[index++] = '.';
		if(ex > 1)
		{
			for(int j = 0; j < ex - 1; j++)
			{
				ans[index++] = '0';
			}
		}
		for(int i = 0; i < lenNums; i++)
		{
			if(nums[i] != '+' && nums[i] != '.')
			{
				ans[index++] = nums[i];
			}	
		}
	}
	//���
	if(str[0] == '0' || str[1] == '0')
	{
		printf("0");
	} 
	else
	{
		for(int i = 0; i < index; i++)
		{
			printf("%c", ans[i]);
		}
	}	
	return 0;
}
