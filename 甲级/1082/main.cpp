#include <bits/stdc++.h>
using namespace std;
char num[15][15] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char unit[10][10] = {"ge", "Shi", "Bai", "Qian", "Wan", "Yi"};
int main(int argc, char *argv[]) {
	char N[15];
	scanf("%s", N);
	int len = strlen(N);
	int left = 0, right = len - 1;
	if(len == 1 && N[0] == '0')//��һλ�һ���0 
	{
		printf("ling");
	}
	else
	{
		if(N[0] == '-')
		{
			printf("Fu"); 
			left++;
		}
		while(left + 4 <= right)//����߽ڿ�ʼ 
		{
			right -= 4;//��֤��left��right��ͬһ�ڣ���left�ڸ�λ��right�ڸýڵ����λ 
		}
		while(left < len)
		{
			bool flag = false;//����Ƿ��л��۵�0 
			bool isPrint = false;//�Ƿ��Ѿ���������е�λ 
			while(left <= right)//�Ӹýڵĸ�λleftһֱ�ߵ���λright 
			{
				if(N[left] == '0')//����ǰλΪ0 
				{
					flag = true;//�л��۵�0 
				} 
				else//��ǰλ�ò�Ϊ0��˵��ǰ���һ��0���Ѿ��������� 
				{
					if(flag == true)//ǰ���Ѿ��л��۵�0��
					{
						printf(" ling");//����һ��0���� 
						flag = false;//flag���� 
					} 
					if(left > 0)//��ʾ������λ �������ǵ�һ�������Ԫ�أ�����ǰ��������ո�
					{
						printf(" ");
					}	
					int indexNum = N[left] - '0';
					printf("%s", num[indexNum]);
					isPrint = true;//�ý��й����
					//����ÿһ���е�ʮ���٣� ǧ��С��λ����
					if(left != right)//��λ���Ǹ�λ
					{
						int indexUint = right - left;
						printf(" %s", unit[indexUint]);//�����úÿո� 
					} 	 
				}
				left++; 
			}
			//�����ڣ����λ����
			//�˽��й����������100000000����������Ҳ��Ǹ�λ�� 
			if(isPrint == true && right != len - 1)
			{
				int indexUint = (len - 1 - right) / 4 + 3;
				printf(" %s", unit[indexUint]);
			}
			right += 4;
		} 
	}
	return 0;
}
