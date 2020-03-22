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
	int e = 0, indexEx = 0, cntNum = 0, cntEx = 0;//cntNum是底数的位数，cntEx是指数的值 
	bool startEx = false;//标记开始写入指数 
	for(int i = 1; i < len; i++)
	{
		if(str[i] == 'E')
		{
			e = i;
			cntNum = i - 1;//多算小数点
			startEx = true;
		}
		else if(i >= e + 2 && startEx == true)//指数字符写入新数组中 
		{
			Ex[indexEx++] = str[i];
		}
	}
	sscanf(Ex, "%d", &cntEx);
	bool enough = true;//判断指数和底数位数大小
	if(cntEx < cntNum - 2)
	{
		enough = false;
	} 
	signNum = str[0], signEx = str[e + 1];//指数的符号 
	int index = 1;
	if(signEx == '+')
	{
		if(enough)//指数大或刚好等，先写数，后添0 
		{
			for(int i = 1; i <= cntNum; i++)//写数 
			{
				if(str[i] != '.')//去掉小数点 
				{
					ans[index++] = str[i];
				}
			}
			for(int i = 1; i <= cntEx - cntNum + 2; i++)//添0 ，2把cntNum小数点算上 
			{
				ans[index++] = '0'; 
			} 
		}	
		else//指数小，先写部分数，然后补点，最后继续写数
		{
			for(int i = 1; i <= 2 + cntEx; i++)
			{
				if(str[i] != '.')//暂时去掉小数点
				{
					ans[index++] = str[i];
				}
			}

			ans[index] = '.';//补点 
			index++;
			for(int i = 3 + cntEx; i <= cntNum; i++)//继续写数 
			{
				ans[index++] = str[i];
			}
		}	
	}
	else if(signEx == '-')//写0，补点，继续写0直到和指数相同，写数不写点 
	{
		if(cntEx != 0)
		{
			ans[index++] = '0';//先写0 
			cntEx--;
			ans[index++] = '.';//补点 
			if(cntEx)//还有指数 
			{
				for(int i = 1; i <= cntEx; i++)//写0
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
