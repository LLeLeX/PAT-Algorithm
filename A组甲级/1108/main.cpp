#include <bits/stdc++.h>
using namespace std;
int N;
bool judgeNum(char str[], double &ans)
{
	ans = 0.0;
	bool isneg = false;//����Ƿ�Ϊ���� 
	int start = 0;//��ʼ�����±� 
	int len = strlen(str);
	if(str[0] == '-')//�жϸ��� 
	{
		isneg = true;
		start = 1;
	} 
	int posdot = -1;//��¼С�����λ��
	for(int i = start; i < len; ++i)
	{
		if(str[i] == '.')
		{
			posdot = i;
			break;
		}
		ans = ans * 10 + (str[i] - '0');
	} 
//	cout << "ans:" << ans << endl;
	int cntdigit = 0;//ͳ��С��λ�� 
	bool isdot = false;//��¼�Ƿ������С���� 
	double digitpart = 0.0;//����С�����
	if(posdot != -1)
	{	
		for(int i = posdot + 1; i < len; ++i)
		{
			double temp = str[i] - '0';
			if(cntdigit >= 2)//С��λ������2 
				return false;
			cntdigit++;
			digitpart += temp * pow(0.1, cntdigit);
		} 
	}
//	cout << "digit:" << digitpart << endl;
	ans += digitpart;
//	cout << "sum:" << ans << endl;
	if(isneg == true)
		ans *= -1;
	if(ans < -1000 || ans > 1000)
		return false;
	else
		return true;
}

bool judge(char str[])
{
	int len = strlen(str);
	int cntdot = 0, cntneg = 0;
	for(int i = 0; i < len; ++i)
	{
		if(cntdot > 1)//���С���� 
			return false;
		if(cntneg > 1)
			return false;
		//���������Ҳ���С���� 
		if((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
			return false;
		if(str[i] == '.')//��С���� 
		{
			cntdot++;
		}
		else if(str[i] == '-')
		{
			cntneg++;
		}
	}
	return true; 
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	int count = 0;
	double ans = 0.0; 
	for(int i = 0; i < N; ++i)
	{
		char str[1000];
		scanf("%s", str);
//		cout << judge(str) << " ";
		if(judge(str) == true)//������Ч 
		{
			double num;
			if(judgeNum(str, num) == true)//��Ч���� 
			{
				ans += num;
				count++;
			}
			else//��Ч 
			{
				printf("ERROR: %s is not a legal number\n", str);
			}
		}
		else//��Ч 
		{
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if(count == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(count == 1)
	{
		printf("The average of 1 number is %.2f\n", ans);
	}
	else
	{
		ans /= count;
		printf("The average of %d numbers is %.2f\n", count, ans);
	}
	return 0;
}
