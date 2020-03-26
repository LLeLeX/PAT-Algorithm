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
	//拆分 
	bool flag = false;//false表示底数
	int lenNums = 0, lenExps = 0; 
	for(int i = start; i < len; i++)
	{
		if(str[i] == 'E')
		{
			flag = true;
		}
		else if(flag == false)//底数阶段 
		{
			if(str[i] != '+')
				nums[lenNums++] = str[i];//含小数点 
		}
		else if(flag == true)//指数阶段，带正负号 
		{
			exps[lenExps++] = str[i];
		}
	}
	int index = 0;//记录ans数组
	int ex = 0;//指数的值
	int actCnt = lenNums - 2;//实际小数点后的位数 
	sscanf(exps, "%d", &ex); 
	if(ex == 0)//指数是0次幂 
	{
		for(int i = 0; i < lenNums; i++)
		{
			ans[index++] = nums[i];//若为底数为正数，nums[0]是'+'
		}
	}
	else if(exps[0] == '+')//指数为正 
	{
		//对底数操作 
		ans[index++] = nums[0];//处理小数点前的一位 
		if(ex >= actCnt)//指数大于等于小数点后的位数 
		{
			for(int i = 2; i < actCnt + 2; i++)//i从小数点后的一位开始 
			{
				ans[index++] = nums[i]; 
			}
			for(int i = 0; i < ex - actCnt; i++)//多出来的补零 
			{
				ans[index++] = '0';
			}
		}
		else//指数小于后面的位数，要点小数点 
		{
			for(int i = 2; i < ex + 2; i++)//先写数 
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
	
	else if(exps[0] == '-')//指数为负 
	{
		ex = -ex;//取相反数 
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
	//输出
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
