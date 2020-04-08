#include <bits/stdc++.h>
using namespace std;
int N;
bool judgeNum(char str[], double &ans)
{
	ans = 0.0;
	bool isneg = false;//标记是否为负数 
	int start = 0;//起始数字下标 
	int len = strlen(str);
	if(str[0] == '-')//判断负数 
	{
		isneg = true;
		start = 1;
	} 
	int posdot = -1;//记录小数点的位置
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
	int cntdigit = 0;//统计小数位数 
	bool isdot = false;//记录是否出现了小数点 
	double digitpart = 0.0;//计算小数结果
	if(posdot != -1)
	{	
		for(int i = posdot + 1; i < len; ++i)
		{
			double temp = str[i] - '0';
			if(cntdigit >= 2)//小数位数超过2 
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
		if(cntdot > 1)//多个小数点 
			return false;
		if(cntneg > 1)
			return false;
		//不是数字且不是小数点 
		if((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
			return false;
		if(str[i] == '.')//是小数点 
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
		if(judge(str) == true)//输入有效 
		{
			double num;
			if(judgeNum(str, num) == true)//有效数字 
			{
				ans += num;
				count++;
			}
			else//无效 
			{
				printf("ERROR: %s is not a legal number\n", str);
			}
		}
		else//无效 
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
