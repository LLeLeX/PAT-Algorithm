#include <bits/stdc++.h>
using namespace std;
char str[20005];
char ans[20005];
char Ex[100]; 
char signNum, signEx;
int main(int argc, char** argv) {
	scanf("%s", str);
	ans[0] = str[0];
	int len = strlen(str);
	int e = 0, indexEx = 0, cntNum = 0, cntEx = 0;//cntNum�ǵ�����λ����cntEx��ָ����ֵ 
	bool startEx = false;//��ǿ�ʼд��ָ�� 
	for(int i = 1; i < len; i++)
	{
		if(str[i] == 'E')
		{
			e = i;
			cntNum = i - 1;//����С����
			startEx = true;
		}
		else if(i >= e + 2 && startEx == true)//ָ���ַ�д���������� 
		{
			Ex[indexEx++] = str[i];
		}
	}
	sscanf(Ex, "%d", &cntEx);
	bool enough = true;//�ж�ָ���͵���λ����С
	if(cntEx < cntNum - 2)
	{
		enough = false;
	} 
	signNum = str[0], signEx = str[e + 1];//ָ���ķ��� 
	int index = 1;
	if(signEx == '+')
	{
		if(enough)//ָ�����պõȣ���д��������0 
		{
			for(int i = 1; i <= cntNum; i++)//д�� 
			{
				if(str[i] != '.')//ȥ��С���� 
				{
					ans[index++] = str[i];
				}
			}
			for(int i = 1; i <= cntEx - cntNum + 2; i++)//��0 ��2��cntNumС�������� 
			{
				ans[index++] = '0'; 
			} 
		}	
		else//ָ��С����д��������Ȼ�󲹵㣬������д��
		{
			for(int i = 1; i <= 2 + cntEx; i++)
			{
				if(str[i] != '.')//��ʱȥ��С����
				{
					ans[index++] = str[i];
				}
			}

			ans[index] = '.';//���� 
			index++;
			for(int i = 3 + cntEx; i <= cntNum; i++)//����д�� 
			{
				ans[index++] = str[i];
			}
		}	
	}
	else if(signEx == '-')//д0�����㣬����д0ֱ����ָ����ͬ��д����д�� 
	{
		if(cntEx != 0)
		{
			ans[index++] = '0';//��д0 
			cntEx--;
			ans[index++] = '.';//���� 
			if(cntEx)//����ָ�� 
			{
				for(int i = 1; i <= cntEx; i++)//д0
				{
					ans[index++] = '0';
				}
			}
			for(int i = 1; i <= cntNum; i++)
			{
				if(str[i] != '.')
				{
					ans[index++] = str[i];
				}
			}
		}
		else
		{
			for(int i = 1; i <= cntNum; i++)
			{
				ans[index++] = str[i];
			}
		}
	}
	for(int i = 0; i <= index; i++)
	{
		if(ans[i] == '+')
		{
			continue;
		}
		printf("%c", ans[i]);
	}
	return 0;
}
